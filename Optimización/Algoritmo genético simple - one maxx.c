#include<stdlib.h>
#include<stdio.h>
#define n 30 //individuos
#define m 10 //bits de cada individuo

int poblacion[n][m], fitnes[n], nuevaP[n][m], padresS[2][m], individuos = 0, probabilidadM, probabilidadC, g = 0;
void mutacion(), cruzamiento(), elitismo(), seleccion(), update(), info();

int main(){
	int i, j, generacion, sum = 0;
	printf("\n Algoritmo genetico simple aplicado al problema One Max \n");
	printf("\n Poblacion inicial: \n");
	//Generar poblacion aleatoria
	for(i = 0; i < n; i ++){
		printf("\n");
		fitnes[i] = 0;
		for(j = 0; j < m; j ++){
			poblacion[i][j] = rand() % 2;
			printf(" %d", poblacion[i][j]);
			//Evaluar poblacion
			if(poblacion[i][j] == 1){
				sum ++;
				fitnes[i] ++;
			}
		}
		printf(" - %d", fitnes[i]);
	}
	printf("\n\n Numero maximo de generaciones: ");
	scanf("%d", &generacion);
	printf(" Probabilidad de cruzamiento (0-100): ");
	while(probabilidadC < 1 || probabilidadC > 99){
		scanf("%d", &probabilidadC);
	}
	printf(" Probabilidad de mutacion (0-100): ");
	while(probabilidadM < 1 || probabilidadM > 99){
		scanf("%d", &probabilidadM);
	}
	while(generacion > 0){
		individuos = 0;
		info();
		elitismo();
		individuos += 2;
		while(individuos < 29){
			seleccion();
			individuos += 2;
		}
		update();
		generacion --;
		g ++;
	}
	printf("\n\n Poblacion resultante\n");
	for(i = 0; i < n; i ++){
		fitnes[i] = 0;
		for(j = 0; j < m; j ++){
			printf(" %d", poblacion[i][j]);
			if(poblacion[i][j] == 1)
				fitnes[i] += 1;
		}
		printf(" - %d\n ", fitnes[i]);
	}
	
	system("pause");
	return 0;
}
void cruzamiento(){
	int ruptura = rand() % 10, nuevo[2][10], k, p = rand() % 100;
	//printf("\n La probabilidad de cruzamiento al azar fue %d, y el punto de ruptura es %d", p, ruptura);
	if(p < probabilidadC){
		//printf("\n Cruzamiento");
		for(k = 0; k < ruptura; k ++){
			nuevo[0][k] = padresS[0][k];
			nuevo[1][k] = padresS[1][k];
		}
		for(k = ruptura; k < m; k ++){
			nuevo[0][k] = padresS[1][k];
			nuevo[1][k] = padresS[0][k];
		}
		for(k = 0; k < m; k ++){
			nuevaP[individuos][k] = nuevo[0][k];
			nuevaP[individuos + 1][k] = nuevo[1][k];
		}	
	}
	else{
		//printf("\n No cruzamiento");
		for(k = 0; k < m; k ++){
			nuevaP[individuos][k] = padresS[0][k];
			nuevaP[individuos + 1][k] = padresS[1][k];
		}	
	}
	/*printf("\n");
	for(k = 0; k < m; k ++){
		printf(" %d", nuevaP[individuos][k]);
	}
	printf("\n");
	for(k = 0; k < m; k ++){
		printf(" %d", nuevaP[individuos + 1][k]);
	}*/
	mutacion();	
}
void seleccion(){
	int sumaTotal = 0, l, r, acumulacion = 0, complete = 0, o;
	//sumaTotal es la suma del fitnes,acumulacion las sumas que llevo recorriendo, complete: selección de 2 hijos, r suma a superar
	//Algoritmo de la ruleta
	while(complete < 2){ //Completar los 2 individuos padres
		sumaTotal = 0;
		acumulacion = 0;
		for(l = 0; l < n; l ++){
			sumaTotal += fitnes[l];
		}
		r = rand() % sumaTotal + 1;
		l = 0;
		while(acumulacion < r){
			acumulacion += fitnes[l];
			l ++; //l es la columna del individuo seleccionado
		}
		l -= 1;
		//printf("\n Padre %d\n", complete +1);
		for(o = 0; o < m; o ++){
			padresS[complete][o] = poblacion[l][o];
			//printf(" %d", padresS[complete][o]);
		}
		complete ++;
	}
	cruzamiento();
}
void mutacion(){
	int p = rand() % 100, gen, k;
	if(p < probabilidadM){
		gen = rand() % 10;
		//printf("\n Primer hijo: el gen mutado sera %d, y la probabilidad fue %d\n", gen, p);
		if(nuevaP[individuos][gen] == 0)
			nuevaP[individuos][gen] = 1;
		else
			nuevaP[individuos][gen] = 0;
		/*for(k = 0; k < m; k ++){
			printf(" %d", nuevaP[individuos][k]);
		}*/
	}
	p = rand() % 100;
	if(p < probabilidadM){
		gen = rand() % 10;
		//printf("\n Segundo hijo: el gen mutado sera %d, y la probabilidad fue %d\n", gen, p);
		if(nuevaP[individuos + 1][gen] == 0)
			nuevaP[individuos + 1][gen] = 1;
		else
			nuevaP[individuos + 1][gen] = 0;
		/*for(k = 0; k < m; k ++){
			printf(" %d", nuevaP[individuos + 1][k]);
		}*/
	}
}
void elitismo(){
	int k, e[2] = {0, 0}; //e guarda el número de individuo con más 1´s
	for(k = 1; k < n; k ++){
		if(fitnes[k] > fitnes[e[0]]) //Individuo 1
			e[0]= k;
	}
	for(k = 1; k < n; k ++){
		if(fitnes[k] > fitnes[e[1]] && k != e[0]) //Individuo 2
			e[1] = k;
	}
	//printf("\n El segundo mejor individuo fue %d\n", e[1]);
	for(k = 0; k < m; k ++){
		padresS[0][k] = poblacion[e[0]][k]; //Ambos individuos pasan a la siguiente generación
		padresS[1][k] = poblacion[e[1]][k];
		//printf(" %d", padresS[1][k]);
	}
	//printf("\n El mejor individuo fue %d\n", e[0]);
	/*for(k=0; k<m; k++){
		printf(" %d", padresS[0][k]);	
	}*/
	cruzamiento();
}
void update(){
	int i, j;
	for(i = 0; i < n; i ++){
		fitnes[i] = 0;
		for(j = 0; j < m; j ++){
			poblacion[i][j] = nuevaP[i][j];
			nuevaP[i][j] = 0;
			if(poblacion[i][j] == 1)
				fitnes[i] += 1;
		}
	}
}
void info(){
	int j, mayor = 0, s = 0;
	for(j = 0; j < n; j ++){
		if(fitnes[j] > fitnes[mayor])
			mayor = j;
		s += fitnes[j];
	}
	float f = s / 30;
	printf("\n Mejor individuo de la generacion %d, promedio fitnes %.2f. Fitnes total: %d\n", g + 1, f, s);
	for(j = 0; j < m; j ++){
		printf(" %d", poblacion[mayor][j]);
	}
}
