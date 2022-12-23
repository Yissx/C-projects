/*  Universidad Autónoma de Aguascalientes
    Ingeniería en Computación Inteligente
	Centro de Ciencias Básicas
	Departamento de Ciencias de la Computación
	Programación Científica
	Nancy Yissel Cuellar Valdivia
	Andrea de Santiago Legaspi
	Montserrat Alejandra Ulloa Rivera
	Profesor de la materia: Dr en C. Luis Fernando Gutiérrez Marfileño
	Este programa implementa los métodos de Regla de Cramer y Gauss para calcular las corrientes de cada resistor en un circuito especifico
	
	Para la resolución se utilizó el método de mallas: el circuito dado se divide en cuatro mallas, creando un sistema de cuatro ecuaciones,
	teniendo como incógnitas las intensidades de la corriente de cada malla.
		10 = R1*I1 + R2*I1 - R2*I2 + R4*I1 + R5*I1 - R5*I3 + R7*I1 + R8*I1 -R8*I4 +R10*I1 (Malla 1)
		0 = R2*I2 - R2*I1 + R3*I2 (Malla 2)
		0 = R5*I3 - R5*I1 + R6*I3 (Malla 3)
		0 = R8*I4 - R8*I1 + R9*I4 (Malla 4)
	Se resuelve cada incógnita y posteriormente estos resultados se sustituyen para encontrar la intensidad de corriente para cada resistencia.
	Esto se saca evaluando en donde choca cada malla, si chocan se restan sus intensidades.
	R1, R4, R7, R10 = I1
	R2 = I1 - I2
	R3 = I2
	R5 = I1 - I3
	R6 = I3
	R8 = I1 - I4
	R7  I4
	
*/
#include <stdlib.h>
#include <stdio.h>

float determinante(float c[][4]){
	int det, det1, det2, det3, det4;
	det1= ((c[1][1]*c[2][2]*c[3][3])+(c[1][2]*c[2][3]*c[3][1])+(c[1][3]*c[2][1]*c[3][2])) - ((c[1][2]*c[2][1]*c[3][3])+(c[1][1]*c[2][3]*c[3][2])+(c[1][3]*c[2][2]*c[3][1]));
	det1= c[0][0]*det1;
	det2= ((c[1][0]*c[2][2]*c[3][3])+(c[1][2]*c[2][3]*c[3][0])+(c[1][3]*c[2][0]*c[3][2])) - ((c[1][2]*c[2][0]*c[3][3])+(c[1][0]*c[2][3]*c[3][2])+(c[1][3]*c[2][2]*c[3][0]));
	det2= -c[0][1]*det2;
	det3= ((c[1][0]*c[2][1]*c[3][3])+(c[1][1]*c[2][3]*c[3][0])+(c[1][3]*c[2][0]*c[3][1])) - ((c[1][1]*c[2][0]*c[3][3])+(c[1][0]*c[2][3]*c[3][1])+(c[1][3]*c[2][1]*c[3][0]));
	det3= c[0][2]*det3;
	det4= ((c[1][0]*c[2][1]*c[3][2])+(c[1][1]*c[2][2]*c[3][0])+(c[1][2]*c[2][0]*c[3][1])) - ((c[1][1]*c[2][0]*c[3][2])+(c[1][0]*c[2][2]*c[3][1])+(c[1][2]*c[2][1]*c[3][0]));
	det4= -c[0][3]*det4;
	det= det1+det2+det3+det4;
	return det;
}

int main(){
	
	float coef[4][4], coef1[4][4], coef2[4][4], coef3[4][4], coef4[4][4], r[9], ind[3], I[9];
	int n=0;
	float x, d, d1, d2, d3, d4, i1, i2, i3, i4, V;
	int i,j,k,h;
	float A[4][5],c,m[10];

	printf("Este programa implementa los métodos de Regla de Cramer y Gauss para calcular las corrientes de cada resistor en un circuito  \n");
	
		while(n!=3){
		printf("\t\nMenu\n");
		printf("1. Calcular con Regla de Cramer\n");
		printf("2. Calcular con Gauss-Jordan\n");
		printf("3. Salir\n");
		scanf("%d", &n);

		switch(n){
			case 1:	
				printf("\nIngresa el valor del voltaje de la fuente: ");
				scanf("%f", &V);
				
				for(i=0; i<10; i++){
					printf("Ingresa el valor de la resistencia %d: ", i+1);
					scanf("%f", &r[i]);
				}
				
				x= r[0]+r[1]+r[3]+r[4]+r[6]+r[7]+r[9];
				
				coef[0][0]= x; coef[0][1]= -r[1]; coef[0][2]= -r[4]; coef[0][3]= -r[7];
				coef[1][0]= -r[1]; coef[1][1]= r[1]+r[2]; coef[1][2]= 0; coef[1][3]= 0;
				coef[2][0]= -r[4]; coef[2][1]= 0; coef[2][2]= r[4]+r[5]; coef[2][3]= 0;
				coef[3][0]= -r[7]; coef[3][1]=0; coef[3][2]=0; coef[3][3]= r[7]+r[8];
				ind[0]= V; ind[1]=0; ind[2]=0; ind[3]=0;
				
				//Función para calcular la determinante
				d= determinante(coef);
				printf("\nValor de la determinante: %.0f", d);
				
				//Matriz auxiliar para reemplazar términos
				for(i=0; i<4; i++){
					for(j=0; j<4; j++){
						coef1[i][j]= coef[i][j];
					}
				}
				
				//Reemplazando términos independientes en la primera columna
				for(i=0; i<4; i++){
					coef1[i][0]=ind[i];
				}
				
				d1=determinante(coef1);
				printf("\nValor de la determinante 1: %.0f", d1);
				
				//Matriz auxiliar para reemplazar términos
				for(i=0; i<4; i++){
					for(j=0; j<4; j++){
						coef2[i][j]= coef[i][j];
					}
				}
				
				//Reemplazando términos independientes en la segunda columna
				for(i=0; i<4; i++){
					coef2[i][1]=ind[i];
				}
				
				d2=determinante(coef2);
				printf("\nValor de la determinante 2: %.0f", d2);
				
				//Matriz auxiliar para reemplazar términos
				for(i=0; i<4; i++){
					for(j=0; j<4; j++){
						coef3[i][j]= coef[i][j];
					}
				}
				
				//Reemplazando términos independientes en la tercera columna
				for(i=0; i<4; i++){
					coef3[i][2]=ind[i];
				}
				
				d3=determinante(coef3);
				printf("\nValor de la determinante 3: %.0f", d3);
				
				//Matriz auxiliar para reemplazar términos
				for(i=0; i<4; i++){
					for(j=0; j<4; j++){
						coef4[i][j]= coef[i][j];
					}
				}
				
				//Reemplazando términos independientes en la cuarta columna
				for(i=0; i<4; i++){
					coef4[i][3]=ind[i];
				}
				
				d4=determinante(coef4);
				printf("\nValor de la determinante 4: %.0f", d4);
				
				i1= d1/d; i2= d2/d; i3= d3/d; i4= d4/d;
				
				printf("\n\nSolucionn del sistema: ");
				printf("\nI1: %.9f", i1);
				printf("\nI2: %.9f", i2);
				printf("\nI3: %.9f", i3);
				printf("\nI4: %.9f \n\n", i4);
				
				//Resistores
				I[0]= i1; I[1]=i1-i2; I[2]=i2; I[3]=i1; I[4]=i1-i3;
				I[5]= i3; I[6]=i1; I[7]=i1-i4; I[8]=i4; I[9]=i1;
				
				for(i=0; i<10; i++){
					printf("Intensidad de R%d: %f\n", i+1, I[i]);
				}
				
				printf("\n\n");
				system("pause");
            break;

			case 2:
				//Gauss-Jordan
				printf("\nIngresa el valor del voltaje de la fuente: ");
				scanf("%f", &A[0][4]);
				
				for(i=0; i<10; i++){
					printf("Ingresa el valor de la resistencia %d: ", i+1);
					scanf("%f", &r[i]);
				}
				
				x= r[0]+r[1]+r[3]+r[4]+r[6]+r[7]+r[9];
				
				//Matriz aumentada
				A[0][0]= x; A[0][1]= -r[1]; A[0][2]= -r[4]; A[0][3]= -r[7];
				A[1][0]= -r[1]; A[1][1]= r[1]+r[2]; A[1][2]= 0; A[1][3]= 0;
				A[2][0]= -r[4]; A[2][1]= 0; A[2][2]= r[4]+r[5]; A[2][3]= 0;
				A[3][0]= -r[7]; A[3][1]=0; A[3][2]=0; A[3][3]= r[7]+r[8];
				
			    for(j=0; j<=3; j++)
			    {
			        for(i=0; i<=3; i++)
			        {
			            if(i!=j)
			            {
			                c=A[i][j]/A[j][j];
			                for(k=0; k<=4; k++)
			                {
			                    A[i][k]=A[i][k]-c*A[j][k];
			                }
			            }
			        }
			    }
			    
			    for(i=0; i<=3; i++)
			    {
			        m[i]=A[i][4]/A[i][i];
			    }
			    
			    printf("\n\nSolucion del sistema: ");
				printf("\nI1: %.9f", m[0]);
				printf("\nI2: %.9f", m[1]);
				printf("\nI3: %.9f", m[2]);
				printf("\nI4: %.9f \n\n", m[3]);
				
				//Resistores
				I[0]= m[0]; I[1]=m[0]-m[1]; I[2]=m[1]; I[3]=m[0]; I[4]=m[0]-m[2];
				I[5]= m[2]; I[6]=m[0]; I[7]=m[0]-m[3]; I[8]=m[3]; I[9]=m[0];
				
				for(i=0; i<10; i++){
					printf("Intensidad de R%d: %f\n", i+1, I[i]);
				}
			break;
			
			case 3:
				printf("\nHasta la próxima\n");
			break;

			default:
				printf("\nOpcion no valida :( \n");
            break;
		}

	}
	system("pause");
}

