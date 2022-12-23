/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas 
  Departamento de Ciencias Exactas 
  Porgramacion Científica 
  Nancy Yissel Cuellar Valdivia
  Luis Fernando Gutiérrez Marfileño 
  Algoritmo que encuentra una de las raíces de la función f(x) = e^-x - x por el método de iteracion del punto fijo*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define e 2.718281828

void calcular(float, float);
float funcion(float);

int main (){//  
	int i=0, opc;  
	float x = 0, epsilon = 0.0001;
	printf("\n Encontrar una de las raices de la funcion f(x) = e^-x - x");
  	printf("\n 1.- Cambiar valor inicial de x");
  	printf("\n 2.- Cambiar margen de error permitido ");
  	printf("\n 3.- Calcular");
  	printf("\n 4.- Salir\n ");
  	do{
  		printf("\n Opcion: ");
  		scanf("%d", &opc);
  		switch(opc){
	  		case 1:
	  			printf(" x = ");
	  			scanf("%f",&x);
				break;
			case 4:
				printf(" Bye");
				break;
			case 2:
				printf(" M. error: ");
				scanf("%f",&epsilon);
				break;
			case 3:
				calcular(x, epsilon);
				break;
			default:
				printf(" Opcion invalida");
				break;
		}	
	}
	while(opc != 4);
	getch();  
	return 0; 
}

void calcular(float x0, float epsilon){
	float x1 = x0, x2, aux = 1, x;
	int i = 0;
	while(aux == 1){
		x2 = funcion(x1);
		if(fabs(x2 - x1) <= epsilon){
			x = x2;
			aux = 0;
		}
		i++;
		x1 = x2;
	}
	printf("\n La raiz de la funcion es: %.9f", x); 
	printf("\n %d iteraciones requeridas", i); 
}
float funcion(float x){
	float r = pow(e,-x);
	printf("\n f(%.9f) = ", x); 
	printf(" %.9f", r);
	/*r -= x;
	printf(" - %.9f = %.9f", x, r);*/
	return r;
}
