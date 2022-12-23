//Optimización Inteligente 5°A
//Optimización por medio de colonia de hormigas
#include <stdio.h>
#include<stdlib.h>
#include <time.h> 
#include <math.h>
#include<string.h>
#include<stdbool.h>

struct auxiliar {
	int nodo;
	bool camino = false;
	float probabilidad;
};

struct auxiliar2 {
	int orden;
	int sig;
};


int **dist;
float **fermT;

int **lecturaGr24();
int **lecturaKroc();
int construirSolucion(float b, float a, auxiliar2 *camino, int n);
void actualizarFermona(auxiliar2 **camino, int *Lk, float r, float Q, int n, int NumH);
void imprimirCamino(auxiliar2 *camino, int n);

int main(){
	srand(time(0));
	int i, j, x, op, NumH, tam, it, bestR, bestL; 
	float T, Q, ro, a, b;
	
	puts("\tANT COLONY OPTIMIZATION");
	puts("\tEste programa optimiza el recorrido de un grafo predeterminado desde el nodo 1 hasta el nodo 4.");
	
	printf("\nSeleccione el archivo con el que se deaea trabajar: \n1.gr24.tsp \n2.kroc100.tsp\n");
	while(op < 1 || op > 3){
		scanf("%d", &op);
		if (op < 1 || op > 3){
			printf("\nFavor de ingresar una opcion valida: \n1.gr24.tsp \n2.kroc100.tsp\n");
		}
	}
	
	if(op == 1){
		tam = 24;
		printf("\nSe selecciono el archivo gr24.tsp");
		dist = lecturaGr24();
	}
	if(op == 2){
		tam = 100;
		printf("\nSe selecciono el archivo kroc100.tsp");
		dist = lecturaKroc();
	}
	
	/*PARÁMETROS*/
	printf("\nInserte el numero de hormigas: ");
	scanf("%d", &NumH);
	
	printf("Inserte el numero de iteraciones: ");
	scanf("%d", &it);
	
	printf("Inserte el valor inicial de la fermona [T]: ");
	scanf("%f", &T);
	
	printf("Inserte el valor del factor de apredizaje [Q]: ");
	scanf("%f", &Q);
	
	printf("Inserte el valor de factor de evaporacion [p]: ");
	scanf("%f", &ro);
	
	printf("Inserte el valor de factor alpha: ");
	scanf("%f", &a);
	
	printf("Inserte el valor de factor de beta: ");
	scanf("%f", &b);
	
	/*INICIALIZAR LA MATRIZ DE FEROMONAS*/
	fermT = (float **) malloc (tam * sizeof(float *));
	if (fermT == NULL) {
  		printf("No se pudo reservar memoria\n");
  	}
  	
  	for (int i=0 ; i < tam ; i = i + 1) {
    	fermT[i] = (float *) malloc (tam * sizeof(float));
    	if (fermT[i] == NULL) {
  			printf("No se pudo reservar memoria\n");
  		}
  	}
  	
	for(i=0; i<tam; i++){
		for(j=i+1; j<tam; j++){
			if(dist[j][i] != 0){
				fermT[i][j] = T;
				fermT[j][i] = T;
			}
			else { 
				fermT[i][j]=0;
				fermT[j][1]=0;
			}
		}
		fermT[i][i] = 0;
	}
	
	/*DECLARAR LA LISTA TABÚ*/
	auxiliar2 **tabu = NULL;
	tabu = (auxiliar2 **) malloc (NumH * sizeof(auxiliar2 *));
	if (tabu == NULL) {
  		printf("No se pudo reservar memoria\n");
  	}
  	
  	for (int i=0 ; i < NumH ; i = i + 1) {
    	tabu[i] = (auxiliar2 *) malloc ((tam) * sizeof(auxiliar2));
    	if (tabu[i] == NULL) {
  			printf("No se pudo reservar memoria\n");
  		}
  	}
  	
  	/*DECLARAR EL VECTOR DEL PESO DEL RECORRIDO*/
  	int longitud[NumH];

	
	/*puts("\nMATRIZ DE DISTANCIAS\t\t\tMATRIZ DE FERMONAS");
	for(i=0; i<tam; i++){
		for(j=0; j<tam; j++){
			printf("[%.0f] ", dist[i][j]);
		}
		printf("\t\t");
		for(j=0; j<tam; j++){
			printf("[%.1f] ", fermT[i][j]);
		}
		puts("");
	}*/

	/*ITERACIONES DEL ALGORITMO*/
	for(x=0; x<it; x++){
		//printf("\n\n\n\n\nITERACION %d", x);
		
		/*REINICIAR LISTA TABU Y VECTOR DE LONGITUDES*/
		for(i=0; i<NumH; i++){
			for(j=0; j<tam; j++){
				tabu[i][j].orden=0;
				tabu[i][j].sig=0;
			}
			longitud[i]=0;
		}
		
		/*GENERAR RECORRIDOS*/
		for(i=0; i<NumH; i++){
			longitud[i] = construirSolucion(a, b, tabu[i], tam);
			//printf("Hormiga %d lista\n", i);
		}
		
		/*IMPRIMIR LOS RECORRIDOS DE LAS K HORMIGAS*/
		/*for(i=0; i<NumH; i++){
			printf("\nCamino %d: ", i);
			imprimirCamino(tabu[i], tam, nI);
			printf("\nPeso del camino: %d", longitud[i]);
		}*/
		
		/*ACTUALIZAR MATRIZ FEROMONAS*/
		actualizarFermona(tabu, longitud, ro, Q, tam, NumH);
		
		/*puts("\nMATRIZ DE FERMONAS ACTUALIZADA");
		for(i=0; i<tam; i++){
			for(j=0; j<tam; j++){
				printf("[%.3f] ", fermT[i][j]);
			}
			puts("");
		}*/
	}
	
	/*MEJOR RECORRIDO*/
	bestL = longitud[0]+1;
	for(i=0; i<NumH; i++){
		if(bestL > longitud[i]){
			bestL = longitud[i];
			bestR = i;
		}
	}
	
	/*IMPRIMIMOS MEJOR RECORRIDO*/
	printf("\nMejor recorrido encontrado\n");
	imprimirCamino(tabu[bestR], tam);
	printf("\nPeso del camino: %d\n", longitud[bestR]);
	/*LIBERAMOS MEMORIA DE LA LISTA TABU, FERMONAS Y DISTANCIA*/
	for(i = 0; i < tam; i++){
    	free(dist[i]);
    }
    for(i = 0; i < tam; i++) {
    	free(fermT[i]);
    }
	for(i = 0; i < NumH; i++){
    	free(tabu[i]);
    }
  	free(tabu);
	free(fermT);
	free(dist);
	
	system("pause");
	return 0;
	
}

int construirSolucion(float a, float b, auxiliar2 *camino, int n){
	auxiliar caminosPosibles[n];
	int i, j, cont=2, cond=0, pesoCamino=0, nI;
	float TN[n], TNS = 0, p = 0;
	nI = (rand() % n); //Nodo Inicial
	int h = nI, sum = 0; 
	camino[nI].orden = 1; 
	
	while (cond<n){
		//REINICIAR AUXILIARES
		sum = 0;
		TNS = 0;
		j = 0;
		for(i=0; i<n; i++){
			caminosPosibles[i].camino = false;
			caminosPosibles[i].nodo = 0;
			caminosPosibles[i].probabilidad = 0;
		}
		
		/*PROBABILIDADES PIJ*/
		for(i=0; i<n; i++){
			if(dist[h][i]>0 && camino[i].orden == 0){
				caminosPosibles[j].camino = true;
				caminosPosibles[j].nodo = i;
				caminosPosibles[j].probabilidad =  pow(fermT[h][i],a) * pow((1/(float)dist[h][i]), b);
				TNS += caminosPosibles[j].probabilidad;
				j++;
			}
		}
		
		//printf("\nPROBABILIDADES DEL NODO %d", h);
		for(i=0; i<n; i++){
			if(caminosPosibles[i].camino==true){
				caminosPosibles[i].probabilidad/=TNS;
				if(i!=0) caminosPosibles[i].probabilidad+=caminosPosibles[i-1].probabilidad; 
			}
			//printf("\n%d - %d: %f", h, caminosPosibles[i].nodo, caminosPosibles[i].probabilidad);
		}
		
		/*ELEGIR NODO SIGUIENTE*/
		p = (rand() % 100);
		p /= 100;
		//printf("\nProbabilidad = %f", p);
		
		for(i=0; i<n; i++){
			if(caminosPosibles[i].probabilidad>p){
				pesoCamino += (dist[h][caminosPosibles[i].nodo]); 
				camino[h].sig = caminosPosibles[i].nodo;
				h=caminosPosibles[i].nodo; i=n+1;
			}
		}
		//printf("\nNodo siguiente = %d", h);
		camino[h].orden = cont;
		cont++;
		cond++;
		
	}
	
	//printf("\nNodo siguiente = %d", nI);
	camino[h].sig = nI;
	pesoCamino += (dist[h][nI]); 
	
	return (int)(pesoCamino);
	
}

void actualizarFermona(auxiliar2 **camino, int *Lk, float r, float Q, int n, int NumH){
	int i, j,h;
	float Tij, DeltaTij;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(fermT[i][j] != 0){
				fermT[i][j] = ((1 - r) * fermT[i][j]); //(1-ro)*Tij
				fermT[j][i] = fermT[i][j];
			}
		}
	}
	
	//CADA HORMIGA (+ DELTA Tij)
	for(i=0; i<NumH; i++){
		Tij = Q/Lk[i];
		for(h=0; h<n; h++){
			for(j=h+1; j<n; j++){
				if(fermT[h][j] != 0){
					if(camino[i][h].sig == j){
						fermT[h][j] += Tij;
						fermT[j][h] = fermT[h][j];
						//printf("\n %d - %d", h, j);
					}
				}
			}
		}
	}
}


void imprimirCamino(auxiliar2 *camino, int n){
	int i, cont=1, aux=0, nI;
	//printf("\nCamino: ");
	while(cont<n){
		for(i=0; i<n; i++){
			if(camino[i].orden == cont){
				if(cont==1) nI = i+1;
				printf("[%d]", i+1);
				cont++;
			}
		}
	}
	printf("[%d]", nI);
}

int **lecturaKroc(){
	int x[100], y[100], kroc[100][3], xd, yd, i, j, N = 100;
	
	//Matriz dinámica
	int **matriz = (int **) malloc (N * sizeof(int *));
  	if (matriz == NULL) {
  		printf("No se pudo reservar memoria\n");
  		return matriz;
  	}
	for (i=0 ; i<N ; i=i+1) {
    	matriz[i] = (int *) malloc (N * sizeof(int));
    	if (matriz[i] == NULL) {
  			printf("No se pudo reservar memoria\n");
  			return matriz;
  		}
  	}
	
	FILE *manejador_archivo = NULL;
	char buffer[19] = "";
	manejador_archivo= fopen("kroc100.txt",  "r");
	
	if(manejador_archivo == NULL) {
		printf("No fue posible abrir el archivo kroc100.tsp\n");
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

int **lecturaGr24(){
	int i, j, N = 24;
	
	//Matriz dinámica
	int **matriz = (int **) malloc (N * sizeof(int *));
  	if (matriz == NULL) {
  		printf("No se pudo reservar memoria\n");
  		return matriz;
  	}
	for (i=0 ; i<N ; i=i+1) {
    	matriz[i] = (int *) malloc (N * sizeof(int));
    	if (matriz[i] == NULL) {
  			printf("No se pudo reservar memoria\n");
  			return matriz;
  		}
  	}
	
	FILE * archivo = NULL; 
	char buffer[19] = "";
	archivo = fopen("gr24.txt",  "r");
	if(archivo == NULL){
		printf("\nNo fue posible abrir el archivo gr24.tsp");
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
	printf("\n %d", matriz[5][1]);
	fclose(archivo);
	return matriz;
}
