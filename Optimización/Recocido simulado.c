#include<stdlib.h>
#include<stdio.h>
#define N 7
#define e 2.71828
#include<math.h>
#include<stdbool.h>

int matriz[N][N] = { {0, 12, 10, 0, 0, 0, 12}, {12, 0, 8, 12, 0, 0, 0}, {10, 8, 0, 11, 3, 0, 9}, {0, 12, 11, 0, 11, 10, 0},
	               {0, 0, 3, 11, 0, 6, 7}, {0, 0, 0, 10, 6, 0, 9}, {12, 0, 9, 0, 7, 9, 0} };
float T0, a = 0, p = 0, Tfin;
int K, recorrido [2][N + 1] = { {1, 2, 3, 4, 5, 6, 7, 1}, {0, 0, 0, 0, 0, 0, 0} }, energia(int);
void recocido(), perturbacion();
bool factibilidad();
float probBoltzmann(float);

int main(){
	int i, j;
	printf("\n Algoritmo del recocido simulado");
	printf("\n Matriz de distancias del grafo a trabajar\n\n    ");
	for(i = 0; i < N; i ++){
		printf("__%d_", i+1);
	}
	for(i = 0; i < N; i ++){
		printf("\n %d |", i+1);
		for(j = 0; j < N; j ++){
			if(matriz[i][j] > 9)
				printf(" %d ", matriz[i][j]);
			else
				printf("  %d ", matriz[i][j]);
		}
	}
	printf("\n\n Se trabajara con la solucion incial {1, 2, 3, 4, 5, 6, 7, 1}");
	printf("\n\n Ingrese los siguientes datos: ");
	printf("\n Temperatura inicial: ");
	scanf("%f", &T0);
	printf(" Temperatura final: ");
	scanf("%f", &Tfin);
	while(a <= 0 || a >= 1){
		printf(" Factor de enfriamiento (0, 1): ");
		scanf("%f", &a);
	}
	while(p <= 0 || p >= 1){
		printf(" Factor de reduccion de iteraciones (0, 1): ");
		scanf("%f", &p);
	}
	printf(" Numero de iteraciones: ");
	scanf("%d", &K);
	recocido();
	printf("\n\n Solucion final con costo de %d \n", energia(0));
	for(i = 0; i < N + 1; i ++){
		printf(" %d", recorrido[0][i]);
	}
	printf("\n\n ");
	system("PAUSE");
	return 0;
}
void recocido(){
	int k = 0, l;
	float T = T0, r;
	while(T > Tfin){
		while(k < K){
			do{
				perturbacion(); 	
			}
			while(factibilidad() == false); //Mientras el subviaje inverso no sea factible, generar más subviajes
			//printf("\n E(i) = %d, E(j) = %d", energia(0), energia(1));
			if(energia(0) > energia(1)){ //Si la solución nueva es mejor a la original, entonces sustituir
				for(l = 0; l < N + 1; l ++){
					recorrido[0][l] = recorrido[1][l];
					recorrido[1][l] = 0;
				}
			}
			else{ //Si no es mejor solución, entonces
				r = 1 + rand() % 99;
				r /= 100;
				//printf("\n Probabilidad de Boltzmann vale %f y r = %f", probBoltzmann(T), r);
				if(r < probBoltzmann(T)){ //Se acpeta j como i
					for(l = 0; l < N + 1; l ++){
						recorrido[0][l] = recorrido[1][l];
						recorrido[1][l] = 0;
					}	
				}
			}
			k ++;
		}
		T *= a;
		K *= p;
		k = 0;
	}
}
int energia(int viaje){
	int s = 0, i;
	for(i = 0; i < N; i ++){
		s += matriz[recorrido[viaje][i] - 1][recorrido[viaje][i + 1] - 1];
	}
	return s;
}
void perturbacion(){
	int r1, r2, aux[8], i, k = 0;
	r1 = 1 + rand () % (N - 1);
	r2 = r1 + rand () % (N - r1);
	/*printf("\n\n r1 = %d r2 = %d", r1, r2);
	printf("\n Viaje original: \n");*/
	for(i = 0; i< N + 1; i ++){
		aux[i] = recorrido[0][i];
		//printf(" %d", aux[i]);
		recorrido[1][i] = recorrido[0][i];
	}
	for(i = r1; i <= r2; i ++){
		recorrido[1][i] = aux[r2 - k];
		k ++;
	}
}
float probBoltzmann(float T){
	return (pow(e, (energia(0) - energia(1))/ T));
}
bool factibilidad(){
	int i;
	bool b = true;
	for(i = 0; i < N; i ++){
		//Se verifica que no haya ceros (que haya camino) de un vértice a otro
		if(matriz[recorrido[1][i] - 1][recorrido[1][i + 1] - 1] == 0)
			b = false;
	}
	return b;
}
