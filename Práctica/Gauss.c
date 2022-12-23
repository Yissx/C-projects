/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas 
  Departamento de Ciencias Exactas 
  Porgramacion Científica 
  Nancy Yissel Cuellar Valdivia
  Luis Fernando Gutiérrez Marfileño 
  Algoritmo que encuentra los valores de las incógnitas presentadas en las ecuaciones
  a partir del método de Gauss - Jordan de las ecuaciones dadas*/
  
#include<stdio.h>
#include<stdlib.h>
#define N 12

void pedirDatos(int *, float [][N], int);
void Gauss(int, float [][N]);

int main(){
	int i, size, opc;
    float matx[11][N];
	do{
  		printf("\n\n Solucion a un sistema de ecuaciones por el metodo de Gauss");
  		printf("\n 1. Resolver sistema dado ");
  		printf("\n 2x1 +  x2 + 3x3 = 1 \n 2x1 + 6x2 + 8x3 = 3  \n 6x1 + 8x2 + 18x3 = 5");
  		printf("\n 2. Resolver otro sistema");
  		printf("\n 3. Salir\n ");
  		scanf("%d", &opc);
  		switch(opc){
  			case 1:
  				size = 3;
  				matx[1][1] = 2; matx[1][2] = 1; matx[1][3] = 3; matx[1][4] = 1;
				matx[2][1] = 2; matx[2][2] = 6; matx[2][3] = 8; matx[2][4] = 3;
				matx[3][1] = 6; matx[3][2] = 8; matx[3][3] = 18; matx[3][4] = 5;
				Gauss(size, matx);
				for(i=1; i<=size; i++){
			    	printf("\n x%d = %.2f", i, matx[i][4]);
				}
			  	break;
			case 2:
			    pedirDatos(&size, matx, size);
			    Gauss(size, matx);
			    printf("\n\n Las soluciones son:");
			    for(i=1; i<=size; i++){
			    	printf("\n x%d = %.2f", i, matx[i][size+1]);
				}
				break;
			case 3:
				printf("\n Fin ");
				break;
			default:
				printf("\n Error");
				break;
		}
	}
	while(opc != 3);
	system("pause");
    return 0;
}

void pedirDatos(int *size, float matx[][N], int s){
    int i, j;
    printf("\n Introduce el numero de incognitas (10): ");
    scanf("%d", &*size);
    printf(" Introducir cada componente del sistema:");
    printf("\n\n Matriz de coeficientes: ");
    for(i=1; i<=*size; i++){
    	printf("\n Ecuacion %d\n", i);
		for(j=1; j<=*size; j++){
	        printf(" x%d: ", j); 
			scanf("%f", &matx[i][j]);
		}	
	}
    printf("\n Vector independiente:\n");
    for(i=1; i<=*size; i++){
        printf(" termino %d: ", i);
		scanf("%f", &matx[i][*size+1]);
    }
    for(i=1; i<=*size; i++){
		printf("\n");
    	for(j=1; j<=*size+1; j++){
    		if(j == *size+1)
    			printf(" = ", matx[i][*size+1]);
    		if(matx[i][j] > 0)
				printf(" + %.fx%d", matx[i][j], j);
			else if(matx[i][j] < 0)
				printf("  %.fx%d", matx[i][j], j);
			else
				printf("      ");
		}
	}
}
void Gauss(int size, float matx[][N]){
    int noCero, col, c1, c2, i;
    float pivote, V1;
    for(col=1; col<=size; col++){
        noCero = 0;
		i = col;
        while(noCero == 0){
            if(matx[i][col] != 0)
                noCero = 1;
            else 
				i++;
		}
        pivote = matx[i][col];
        for(c1=1; c1<=(size+1); c1++){
            V1 = matx[i][c1];
            matx[i][c1] = matx[col][c1];
            matx[col][c1] = V1 / pivote;
		}
        for(c2=col+1; c2<=size; c2++){
            V1 = matx[c2][col];
            for(c1=col; c1<=(size+1); c1++){
                matx[c2][c1] = matx[c2][c1] - V1 * matx[col][c1];
			}
    	}
	}
    for(col=size; col>=1; col--) {
		for(c1=(col-1); c1>=1; c1--){
	        matx[c1][size+1] = matx[c1][size+1] - matx[c1][col] * matx[col][size+1];
	        matx[c1][col] = 0;
    	}
    }
}
