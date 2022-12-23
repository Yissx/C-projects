#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 29

int main(){
	FILE *archivo = NULL; 
	char buffer[19] = "";
	int i, j, matriz[N][N];
	archivo = fopen("bays29.txt",  "r");
	if(archivo == NULL){
		printf("\n Error al abrir el archivo");
		return -1;
	}
	while(strcmp(buffer, "EDGE_WEIGHT_SECTION") != 0){ //EDGE_WEIGHT_SECTION es la última línea de texto
		fgets(buffer, 20, archivo);
	}
	printf("\n Contenido de la matriz:\n\n     ");
	for(i = 0; i < N; i ++){
		if(i > 9)
			printf("__%d", i + 1);
		else
			printf("___%d", i + 1);
	}
	for(i = 0; i < N; i ++){
		if(i < 10)
			printf("\n  %d | ", i + 1);
		else if(i > 9)
			printf("\n %d | ", i + 1);
		for(j = 0; j < N; j ++){
			fscanf(archivo, "%d", &matriz[i][j]);
			if(matriz[i][j] > 99)
				printf(" %d", matriz[i][j]);
			else if(matriz[i][j] < 100 && matriz[i][j] > 9)
				printf("  %d", matriz[i][j]);
			else
				printf("   %d", matriz[i][j]);
		}
	}
	fclose(archivo);
	return 0;
}
