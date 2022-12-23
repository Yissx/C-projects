/*Benemérita Universidad de Aguascalientes
  Centro de Ciencias Básicas
  Departamento de Ciencias Exactas
  Programación científica
  Nancy Yissel Cuellar Valdivia
  Luis Fernando Gutiérrez Marfileño
  Calculo del valor de la tangente de una fucnion a partir de una serie de Taylor*/
  
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#define N 100

float convert(float);
int factorial(int);

int main(){
	float grados, radianes, x;
	int opc, grado;
	do{
		system("cls");
		printf(" 1.- Calcular la tangente de una funcion: de grado 2\n");
		printf(" 2.- Calcular la tangente de una funcion: de grado 4\n");
		printf(" 3.- Calcular la tangente de una funcion: de grado 6\n");
		printf(" 4.- Salir\n ");
		scanf("%d", &opc);
		if(opc!=4){
			printf("\n Grados del angulo: ");
			scanf("%f",&grados);
			radianes = convert(grados);
			printf(" Radianes = %f\n", radianes);
			printf(" El valor de tan(%f) arrojado por el programa es: %f", radianes, tan(radianes));
		}
		switch(opc){
			case 1:	
				x =  radianes/factorial(1);
				printf("\n El valor obtenido a partir del polinomio es: %f", x);
				break;
			case 2:	
				x =  (radianes/factorial(1)) + (2*pow(radianes,3)/factorial(3));
				printf("\n El valor obtenido a partir del polinomio es: %f", x);
				break;
			case 3:
				x =  (radianes/factorial(1)) + (2*pow(radianes,3)/factorial(3)) + (16*pow(radianes,5)/factorial(5));
				printf("\n El valor obtenido a partir del polinomio es: %f", x);
				break;
			case 4: 
				printf("\n Bye\n ");
				break;
			default:
				printf("\n Opcion invalida\n ");
				break;
		}
		
		printf("\n El error fue de %f\n ", x - tan(radianes));
		system("pause");
	}
	while(opc!=4);
	return 0;
}
float convert(float grados){
	float radianes, pi = 3.1416;
	radianes= (grados * pi)/180;
	return radianes;
}
int factorial(int limite){
	int fact;
	if(limite==0)
		return 1;
	else
		return limite*factorial(limite-1);
	return fact;
}

