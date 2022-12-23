/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas
  Departamento de Ciencias Exactas
  Programación Cienctífica
  Nancy Yissel Cuellar Valdivia
  Profesor Luis Fernando Gutiérrez Marfileño
  Programa que encuentra la solución de un sistema de ecuaciones
  a partir de la regla de Cramer*/
  
#include<stdio.h>
 
int determinante(int[3][3]);
   
int main(){
		int sistema[3][3], ele, det, vec[3];
		sistema[0][0] = 2; sistema[0][1] = -1; sistema[0][2] = 6;
		sistema[1][0] = -3; sistema[1][1] = 4; sistema[1][2] = -5;
		sistema[2][0] = 8; sistema[2][1] = -7; sistema[2][2] = -9;
		vec[0] = 77; vec[1] = -30; vec[2] = -133;
		printf(" Regla de Cramer\n");
		printf("\n 2x1 -  x2 + 6x3 =  77");
		printf("\n-3x1 + 4x2 - 5x3 = -30");
		printf("\n 8x1 - 7x2 - 9x3 = -133\n");
		do{
			printf("\n 1. Resolver sistema");
			printf("\n 2. Modificar sistema");
			printf("\n 3. Salir\n ");
			scanf("%d", &ele);
			switch(ele){
				case 1:
					det = determinante(sistema);
					if(det == 0)
						printf("\n Determinante (A) = 0 \n No hay solución única \n ");
					else{
						printf("\n El determinante de A es %d\n\n", det);
						int nueva[3][3], i, j, k, det2;
						for(i=0; i<3; i++){
							for(j=0; j<3; j++){
								printf(" [");
								for(k=0; k<3; k++){
									nueva[j][k] = sistema[j][k];
									if(i == k)
										nueva[j][k] = vec[j];
									printf(" %d", nueva[j][k]);
								}
								printf("]\n");
							}
							det2 = determinante(nueva);
							printf("\n El valor de x%d es %d",i+1,(det2/det));
							printf("\n");
						}
					}
					break;
				case 3:
					printf("\n Salir");
					break;
				case 2:
					printf("\n El sistema tendra que ser de 3x3");
					printf("\n Introducir la matriz de coeficientes:\n");
					int i, j;
					for(i=0; i<3; i++){
						for(j=0; j<3; j++){
							printf(" x%d de la ecuacion %d: ", j+1, i+1);
							scanf("%d", &sistema[i][j]);
						}
						printf("\n");
					}
					printf("\n Introducir el vector de terminos independientes\n");
					for(i=0; i<3; i++){
						printf(" termino %d: ",i+1);
						scanf("%d", &vec[i]);
					}
					break;
				default:
					printf("\n Error");
					break;
			}
		}
		while(ele != 3);
		system("pause");
		return 0;
}
int determinante(int mat[3][3]){
	int det = 0, i;
	det += (mat[0][0] * mat[1][1] * mat[2][2]);
	det += (mat[0][1] * mat[1][2] * mat[2][0]);
	det += (mat[0][2] * mat[1][0] * mat[2][1]);
	
	det -= (mat[2][0] * mat[1][1] * mat[0][2]);
	det -= (mat[2][1] * mat[1][2] * mat[0][0]);
	det -= (mat[2][2] * mat[1][0] * mat[0][1]);
	return det;
}
