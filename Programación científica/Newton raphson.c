/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas 
  Departamento de Ciencias Exactas 
  Porgramacion Científica 
  Nancy Yissel Cuellar Valdivia
  Valeria Macías Soto
  Luis Fernando Gutiérrez Marfileño 
  Algoritmo que encuentra una de las raíces de la función f(x) = cos(x) -x por el método de Newton Raphson*/
  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265359

void calcular(float, float, int);
float funcion(float);
float derivada(float);

int main (){
	int iterar = 100, opc;  
	float x = 57.3, epsilon = 0.1;
	do{	
		printf("\n Evaluar la funcion f(x) = cos(x) - x");
	  	printf("\n 1.- Cambiar valor inicial de x");
	  	printf("\n 2.- Cambiar margen de error permitido ");
	  	printf("\n 3.- Establecer el numero maximo de iteraciones");
	  	printf("\n 4.- Calcular");
	  	printf("\n 5.- Salir\n ");
  		printf("\n Opcion: ");
  		scanf("%d", &opc);
  		switch(opc){
	  		case 1:
	  			printf(" En grados x = ");
	  			scanf("%f",&x);
				break;
			case 5:
				printf(" Bye");
				break;
			case 2:
				printf(" M. error: ");
				scanf("%f",&epsilon);
				break;
			case 4:
	  			x *= pi;
	  			x /= 180;
				calcular(x, epsilon, iterar);
				break;
			case 3:
				printf(" N. maximo: ");
				scanf("%d", &iterar);
				break;
			default:
				printf(" Opcion invalida");
				break;
		}	
	}
	while(opc != 5);
	system("pause");  
	return 0; 
}

void calcular(float x, float epsilon, int iterar){
	float siguiente, r, error = fabs(funcion(x));
	int i = 0;
	while(epsilon < error && i<iterar){
		r = funcion(x);
		/*printf("\n f(%.9lf) = %.9lf", x, r);
		if(i>=iterar && epsilon < error)
			printf("\n\n Proceso fallido :c, ");*/
		siguiente = x - (r/derivada(x));
		error = fabs(r);
		x = siguiente;
		i++;
	}
	if(i >= iterar)
		printf("\n Exceso en las iteraciones", i);
	else{
		printf("\n La raiz es %.9f",x);
		printf("\n %d iteraciones requeridas\n",i);
	}
}

float funcion(float x){
	float result = cos(x) - x;
	return result;
}
float derivada(float x){
	float result = -1*sin(x) - 1;
	return result;
}
