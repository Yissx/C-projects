#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define N 7 //vértices del grafo

int grafo[N][N] = { {0, 5, 3, 0, 0, 6, 0}, {5, 0, 4, 0, 0, 0, 5}, {3, 4, 0, 0, 6, 3, 3}, {0, 0, 0, 0, 5, 0, 4},
					{0, 0, 6, 5, 0, 5, 0}, {6, 2, 3, 0, 5, 0, 0}, {0, 5, 3, 4, 0, 0, 0}},
	camino[N] = {0, 0, 0, 0, 0, 0, 0}, def = 0, nod = 0;
//def representa el número de nodos que se han recorrido, nod es el nodo con el que se está traajando
//feromonas es la tabla grandota, feromonaTemporal guarda la tabla pequeña 
//para la matriz feromonas: [(N * (N - 1)) / 2] son todos los caminos posibles, [segundo índice]: 0 vertice 1, 1 vertice 2, 2 feromona, 3 distancia, 4 inverso de la distancia
float feromona, evaporacion, aprendizaje, feromonas[(N * (N - 1)) / 2][5];
void init(), elegirCamino(), actualizar();

int main(){
	int i, j;
	printf("\n Colonia de hormigas\n");
	init();
	while(camino[def] != 3){
		elegirCamino();
	}
	actualizar();
	printf("\n\n\n ");
	system("pause");
	return 0;
}
void init(){
	int i, j, k = 0;
	float feromonaTotal = 0;
	//Solicitud de parámetros
	printf("\n Introducir el parametro de aprendizaje: ");
	scanf("%f", &aprendizaje);
	printf(" Feromona: ");
	scanf("%f", &feromona);
	printf(" Factor de evaporacion de la feromona: ");
	scanf("%f", &evaporacion);
	//Llenado de la matriz de feromonas
	printf("\n\n Caminos |   T  | Distancia |   N (1/D)");
	for(i = 0; i < N; i ++){
		for(j = i + 1; j < N; j ++){
			feromonas[k][0] = i;
			feromonas[k][1] = j;
			feromonas[k][3] = grafo[i][j];
			if(grafo[i][j] != 0){ //Si no hay arista, entonces no hay feromona ni distancia, ni inverso
				feromonas[k][2] = feromona;
				feromonas[k][4] = 1 / feromonas[k][3];
			}
			else{
				feromonas[k][2] = 0;
				feromonas[k][4] = 0;
			}
			feromonaTotal += feromonas[k][2];
			k ++;
		}
	}
	for(i = 0; i < (N * (N - 1)) / 2; i ++){
			printf("\n  %.0f - %.0f  | %.2f |     %.0f     | %.9f", feromonas[i][0] + 1, feromonas[i][1] + 1, feromonas[i][2], feromonas[i][3], feromonas[i][4]);
	}
	printf("\n           %.2f", feromonaTotal);
}
void elegirCamino(){
	bool p;
	int i, t = 0;
	for(i = 0; i < (N * (N - 1)) / 2; i ++){
		if((feromonas[i][0] == nod || feromonas[i][1] == nod) && feromonas[i][3] != 0)
			t ++;
	}
	float Pij, probAcum = 0, sumN = 0, decision[t][4], r;
	t = 0;
	//Creación de la tablita de elección
	for(i = 0; i < (N * (N - 1)) / 2; i ++){
		if(feromonas[i][0] == nod && feromonas[i][3] != 0){
			decision[t][0] = feromonas[i][0]; //Grafo de salida
			decision[t][1] = feromonas[i][1];//Llegada
			decision[t][2] = feromonas[i][2] * feromonas[i][4]; //Pij: solo multiplicacion de T*N
			sumN += decision[t][2]; //Sumatoria de todas las T*N obtenidas//printf("\n sumN += %f * %f = %f --- %f", feromonas[i][2], feromonas[i][4], decision[t][2], sumN);
			t ++;
		}
		else if(feromonas[i][1] == nod && feromonas[i][3] != 0){
			decision[t][0] = feromonas[i][1];
			decision[t][1] = feromonas[i][0];
			decision[t][2] = feromonas[i][2] * feromonas[i][4]; //Pij: solo multiplicacion de T*N
			sumN += decision[t][2]; //Sumatoria de todas las T*N obtenidas
			t ++;
		}
	}
	for(i = 0; i < t; i ++){
		decision[i][2] /= sumN; //Terminar el valor de Pij
		probAcum += decision[i][2];
		decision[i][3] = probAcum; 
	}
	printf("\n\n Caminos |   Pij   | Prob acumulada");
	for(i = 0; i < t; i ++){
		printf("\n  %.0f - %.0f  | %.5f |   %.5f", decision[i][0] + 1, decision[i][1] + 1, decision[i][2], decision[i][3]);
	}
	do{
		r = rand () % 99 + 1;
		r /= 100;
		p = true;
		camino[def + 1] = decision[0][1]; //Siguiente parada temporal
		for(i = 0; i < t - 1; i ++){
			if(r > decision[i][3])
				camino[def + 1] = decision[i + 1][1]; //Siguiente parada definitiva
		}
		for(i = 0; i <= def; i ++){
			if(camino[i] == camino[def + 1])
				p = false;
		}
	}
	while(p == false);
	def ++;
	nod = camino[def];
}
void actualizar(){
	float Tij, sumDeltaTij = 0;
	int k, Lk = 0, l;
	printf("\n\n El viaje de la hormiga fue: ");
	for(k = 0; k <= def; k ++){
		Lk += grafo[camino[k]][camino[k + 1]];
		printf(" %d -", camino[k] + 1);
	}
	printf("\n Con un costo de %d", Lk);
	for(k = 0; k < (N * (N - 1)) / 2; k ++){
		feromonas[k][2] *= (1 - evaporacion); //Primer paso para Tij
		for(l = 0; l <= def; l ++){
			//Si la hormiga pasó por esa arista
			if((feromonas[k][0] == camino[l] && feromonas[k][1] == camino[l + 1] && feromonas[k][3] != 0) || (feromonas[k][0] == camino[l + 1] && feromonas[k][1] == camino[l] && feromonas[k][3] != 0)){
				feromonas[k][2] += (aprendizaje / Lk);
			}
		}
	}
	printf("\n\n Caminos |    T   | Distancia |   N (1/D)");
	for(l = 0; l < (N * (N - 1)) / 2; l ++){
			printf("\n  %.0f - %.0f  | %.4f |     %.0f     | %.9f", feromonas[l][0] + 1, feromonas[l][1] + 1, feromonas[l][2], feromonas[l][3], feromonas[l][4]);
	}
}
