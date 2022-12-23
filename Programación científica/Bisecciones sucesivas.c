/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas 
  Departamento de Ciencias Exactas 
  Porgramacion Científica 
  Nancy Yissel Cuellar Valdivia
  Luis Fernando Gutiérrez Marfileño 
  Algoritmo que encuentra una de las raíces de la función f(x) =  xsen(x) – 1 por el método de bisecciones sucesivas*/
  
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define pi 3.14159265359
  
float funcion(float);
void calculo(float, float, float);

int main(){
  	float epsilon = 0.005, x1 = 0, x2 =2;
  	int opc;
  	do{
  		printf("\n METODO DE  BISECCIONES SUCESIVAS");
	  	printf("\n Encontrar una de las raices de la funcion f(x) =  xsen(x) - 1");
	  	printf("\n 1.- Cambiar valor inicial de x");
	  	printf("\n 2.- Cambiar margen de error permitido ");
	  	printf("\n 3.- Calcular");
	  	printf("\n 4.- Salir\n ");
  		printf("\n Opcion: ");
  		scanf("%d", &opc);
  		switch(opc){
	  		case 1:
	  			printf(" x1 = ");
	  			scanf("%f",&x1);
				break;
			case 4:
				printf(" Bye");
				break;
			case 2:
				printf(" M. error: ");
				scanf("%f",&epsilon);
				break;
			case 3:
				calculo(x1, x2, epsilon);
				break;
			default:
				printf(" Opcion invalida");
				break;
		}
  	}
  	while(opc != 4);
	printf("\n\n Fin \n");
	system("pause");
  	return 0;
  }
  
void calculo(float x1, float x2, float epsilon){
	float xm, fx1, fx2, fxm = funcion(xm), error;
	xm = (x1 + x2 )/2;
	int i = 0;
	error = fabs(fxm);
	while(epsilon < fabs(fxm)){
		fxm = funcion(xm);
		fx1 = funcion(x1);
		fx2 = funcion(x2);
		if((fx1*fxm) < 0){
			x2 = xm;
			xm = (x1 + x2)/2;
		}
		else if((fx1*fxm) > 0){
			x1 = xm;
			xm = (x1 + x2)/2;
		}
		if(fxm == 0)
			break;
		i++;
	}
	printf("\n\n La raiz es %.9f\n Fueron necesarias %d iteraciones\n\n",xm, i);
}
float funcion(float x){
  	float result;
  	result = x*(sin(x)) -1;
  	return result;
}
