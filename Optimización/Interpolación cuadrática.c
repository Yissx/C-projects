/*Nancy Yissel Cuellar Valdivia
5to A Ingeniería en computación inteligente
Universidad Autónoma de Aguascalientes*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon .01

void interpolacionCuadratica(float, float, float);
float funcion(float);
float X3(float, float, float);

int main(){
	printf("\n Busqueda del optimo de la funcion f(x) = 2sen(x)-x^2/2 en el intervalo [0, 4]\n mediante el algoritmo de interpolacion cuadratica con una tolerancia de error del 0.01% y 50 iteraciones maximas\n");
	float x0, x1, x2;
	printf("\n Para realizar el algoritmo es necesario conocer los tres puntos por los que pasa la ecuacion cuadratica");
	printf("\n Ingresar el valor de x0: ");
	scanf("%f", &x0);
	printf(" x1: ");
	scanf("%f", &x1);
	printf(" x2: ");
	scanf("%f", &x2);
	interpolacionCuadratica(x0, x1, x2);
}
void interpolacionCuadratica(float x0, float x1, float x2){
	int i;
	float es, x3, t;
	x3 = X3(x0, x1, x2);
	do{ 
	    t = x3;
		if(x3 < x1){
			x2 = x1;
			x1 = x3;
			x3 = X3(x0, x1, x2);
		}
		else{
			x0 = x1;
			x1 = x3;
			x3 = X3(x0, x1, x2);
		}
		i++;
		es = fabs(x3 - t)/ x3 * 100;
	}
	while(es > epsilon && i < 50);
	printf("\n\n El optimo de la funcion es: %.9f", x3);
	printf("\n f(x) = %.9f", funcion(x3));
	printf("\n %d iteraciones requeridas", i);
	printf("\n El margen de error fue %.9f", es);
}
float funcion(float x){
	return ((2*sin(x))-(pow(x,2)/2));
}
float X3(float x0, float x1, float x2){
	float x3;
	x3 = (funcion(x0) * (pow(x1, 2) - pow(x2, 2))) + (funcion(x1) * (pow(x2, 2) - pow(x0, 2))) + (funcion(x2) * (pow(x0, 2) - pow(x1, 2)));
	x3 /= (2 * funcion(x0) * (x1 - x2)) + (2 * funcion(x1) * (x2 - x0) + (2 * funcion(x2) * (x0 - x1)));
	return x3;
}
