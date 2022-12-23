#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define e 2.71828
#include<math.h>
#include<stdbool.h>


float T0 = 1, a = 0, p = 0, Tfin = 1000000;
int K = -1, energia(int, int), **matriz, **recorrido; 
void recocido(int), perturbacion(int);
float probBoltzmann(float, int);
int **lecturaGr24(bool *funciona);
int **lecturaKroc(bool *funciona);


int main(){
	int i, j, op = 0, N;
	bool funciona = true; //Si no se puede abrir el archivo o la memoria no se reserva el algoritmo no se ejecuta
	printf("\t\tProyecto Recocido simulado\n");
	//printf("\n Matriz de distancias del grafo a trabajar\n\n    ");
	printf("\nSeleccione el archivo con el que se deaea trabajar: \n1.gr24.tsp \n2.kroc100.tsp\n");
	while(op < 1 || op > 3){
		scanf("%d", &op);
		if (op < 1 || op > 3){
			printf("\nFavor de ingresar una opcion valida: \n1.gr24.tsp \n2.kroc100.tsp\n");
		}
	}
	
	if(op == 1){
		N = 24;
		printf("\nSe selecciono el archivo gr24.tsp");
		matriz = lecturaGr24(&funciona);
	}
	if(op == 2){
		N = 100;
		printf("\nSe selecciono el archivo kroc100.tsp");
		matriz = lecturaKroc(&funciona);
	}
	
	recorrido = (int **) malloc (3 * sizeof(int *)); //Reservar memoria para las filas
	if (recorrido == NULL) {
  		printf("No se pudo reservar memoria\n");
  		funciona = false;
  	}
	for (i=0 ; i<3 ; i++) {
    	recorrido[i] = (int *) malloc ((N + 1) * sizeof(int)); //Reservar memoria para cada casilla
    	if (recorrido[i] == NULL) { 
  			printf("No se pudo reservar memoria\n");
  			funciona = false;
  		}
  	}
  	puts("");
  	for(i=0; i<(N+1); i++){
		recorrido[0][i] = i + 1;	
	}
	for(i=0; i<(N + 1); i++){
		recorrido[1][i] = 0;	
	}
	recorrido[0][N] = 1; 
	
	if (funciona == true){
		printf("\n Se trabajara con la solucion incial: ");
		for(i=0;i<N+1;i++){
			printf("%d- ", recorrido[0][i]);
		}
		printf("\n\n\t Ingrese los siguientes datos ");
		printf("\n Temperatura inicial: ");
		scanf("%f", &T0);
		printf(" Temperatura final: ");
		while(T0<Tfin){
			scanf("%f", &Tfin);
			if(T0<Tfin) printf(" La temperatura final debe ser menor a la incial: ");
		}
		while(a <= 0 || a >= 1){
			printf(" Factor de enfriamiento (0, 1): ");
			scanf("%f", &a);
		}
		while(p <= 0 || p >= 1){
			printf(" Factor de reduccion de iteraciones (0, 1): ");
			scanf("%f", &p);
		}
		printf(" Numero de iteraciones: ");
		while (K<1){
			scanf("%d", &K);
			if(K<1) printf(" El numero de iteraciones debe ser un valor positivo: ");
		}
		
		recocido(N);
		printf("\n\n Solucion final con costo de %d \n", energia(0, N));
		for(i = 0; i < N + 1; i ++){
			printf(" %d", recorrido[0][i]);
		}
		printf("\n\n ");	
	}
				
	for (int i = 0; i < N; i = i + 1) {
    	free(matriz[i]);
    }
    for (int i = 0; i < 3; i = i + 1) {
    	free(recorrido[i]);
    }
	free(matriz);
	free(recorrido);
	system("PAUSE");
	return 0;
}

void recocido(int N){
	int k = 0, l;
	float T = T0, r;
	while(T > Tfin){
		while(k < K){
			perturbacion(N);
			//printf("\n Energia(0) = %d vs energia(1) = %d", energia(0), energia(1));
			if(energia(0, N) > energia(1, N)){ //Si la solución nueva es mejor a la original, entonces sustituir
				for(l = 0; l < N + 1; l ++){
					recorrido[0][l] = recorrido[1][l];
					recorrido[1][l] = 0;
				}
			}
			else{ //Si no es mejor solución, entonces
				r = 1 + rand() % 99;
				r /= 100;
				//printf("\n Probabilidad de Boltzmann vale %f y r = %f", probBoltzmann(T), r);
				if(r < probBoltzmann(T, N)){ //Se acpeta j como i
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
int energia(int viaje, int N){
	int s = 0, i;
	for(i = 0; i < N; i ++){
		s += matriz[recorrido[viaje][i] - 1][recorrido[viaje][i + 1] - 1];
	}
	return s;
}
void perturbacion(int N){
	int r1, r2, aux[N + 1], i, k = 0;
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
	/*printf("\n Viaje modificado: \n");
	for(i = 0; i< N + 1; i ++){
		printf(" %d", recorrido[1][i]);
	}*/
}
float probBoltzmann(float T, int N){
	return (pow(e, (energia(0, N) - energia(1, N))/ T));
}

int **lecturaKroc(bool *funciona){
	int x[100], y[100], kroc[100][3], xd, yd, i, j, N = 100;
	
	//Matriz dinámica
	int **matriz = (int **) malloc (N * sizeof(int *));
  	if (matriz == NULL) {
  		printf("No se pudo reservar memoria\n");
  		*funciona = false;
  		return matriz;
  	}
	for (i=0 ; i<N ; i=i+1) {
    	matriz[i] = (int *) malloc (N * sizeof(int));
    	if (matriz[i] == NULL) {
  			printf("No se pudo reservar memoria\n");
  			*funciona = false;
  			return matriz;
  		}
  	}
	
	FILE *manejador_archivo = NULL;
	char buffer[19] = "";
	manejador_archivo= fopen("kroc100.txt",  "r");
	
	if(manejador_archivo == NULL) {
		printf("No fue posible abrir el archivo kroc100.tsp\n");
		*funciona = false;
		return matriz;
   }
   
	//Leer lo anterior a la matriz
   while(strcmp(buffer, "NODE_COORD_SECTION") != 0){
   		fgets(buffer, 19, manejador_archivo);
   }
    
    puts("\n\n\tCOORDENADAS DE LAS CIUDADES\n");
	//Leer la matriz del archivo y almacenarla   
   for(i=0;i<100;i++){                                
   		for(j=0;j<3;j++){        
        	fscanf(manejador_archivo, "%d", &kroc[i][j]);            
        }
	}
	
	for(i=0;i<100;i++){                                
   		for(j=0;j<3;j++){        
        	printf("[%d]",kroc[i][j]);            
    	}
    	puts("");
	}
	for(i=0;i<100;i++){
		x[i]=kroc[i][1];
		y[i]=kroc[i][2];
	}
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			xd= x[i] - x[j];
			yd= y[i] - y[j];
			matriz[i][j]=	round(sqrt(xd*xd + yd*yd));
		}
	}
	fclose(manejador_archivo);
	
	return matriz;
}

int **lecturaGr24(bool *funciona){
	int i, j, N = 24;
	
	//Matriz dinámica
	int **matriz = (int **) malloc (N * sizeof(int *));
  	if (matriz == NULL) {
  		printf("No se pudo reservar memoria\n");
  		*funciona = false;
  		return matriz;
  	}
	for (i=0 ; i<N ; i=i+1) {
    	matriz[i] = (int *) malloc (N * sizeof(int));
    	if (matriz[i] == NULL) {
  			printf("No se pudo reservar memoria\n");
  			*funciona = false;
  			return matriz;
  		}
  	}
	
	FILE * archivo = NULL; 
	char buffer[19] = "";
	archivo = fopen("gr24.txt",  "r");
	if(archivo == NULL){
		printf("\nNo fue posible abrir el archivo gr24.tsp");
		*funciona = false;
		return matriz;
	}
	while(strcmp(buffer, "EDGE_WEIGHT_SECTION") != 0){ //EDGE_WEIGHT_SECTION es la última línea de texto
		fgets(buffer, 20, archivo);
	}
	printf("\n Contenido de la matriz de distancias:\n\n     ");
	for(i = 0; i < N; i ++){
		if(i > 9)
			printf("__%d", i + 1);
		else
			printf("___%d", i + 1);
	}
	for(i = 0; i < N; i ++){
		for(j = 0; j <= i; j ++){
			fscanf(archivo, "%d", &matriz[i][j]);
		}
	}
	for(i = 0; i < N - 2; i ++){
		for(j = N - 1; j > 0; j --){
			matriz[i][j] = matriz[j][i];
		}
	}
	matriz[N - 2][N - 1] = matriz[N - 1][N - 2];
	for(i = 0; i < N; i ++){
		if(i < 10)
			printf("\n  %d | ", i + 1);
		else if(i > 9)
			printf("\n %d | ", i + 1);
		for(j = 0; j < N; j ++){
			if(matriz[i][j] > 99)
				printf(" %d", matriz[i][j]);
			else if(matriz[i][j] < 100 && matriz[i][j] > 9)
				printf("  %d", matriz[i][j]);
			else
				printf("   %d", matriz[i][j]);
		}
	}
	fclose(archivo);
	return matriz;
}
