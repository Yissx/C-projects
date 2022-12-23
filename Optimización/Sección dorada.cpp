/*Nancy Yissel Cuellar Valdivia
5to A Ingeniería en computación inteligente
Universidad Autónoma de Aguascalientes*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define epsilon .01

void seccionDorada();
float funcion(float);

int main(){
	printf("\n Busqueda del optimo de la funcion f(x) = 2sen(x)-x^2/2 en el intervalo [0, 4]\n mediante el algoritmo de la seccion dorada con una tolerancia de error = 0.01 y 10 iteraciones maximas\n");
	seccionDorada();
}
void seccionDorada(){
	float ea, d, xopt, fx, fx1, fx2, R = (pow(5, .5)-1)/2, x1, x2, xu = 4, xl = 0;
	int i = 1;
	d = R * (xu - xl);
	x1 = xl + d;
	x2 = xu - d;
	fx1 = funcion(x1);
	fx2 = funcion(x2);
	if(fx1 > fx2){
		xopt = x1;
		fx = fx1;
	}
	else{
		xopt = x2;
		fx = fx2;
	}
	do{
		d *= R;
		if(fx1 > fx2){
			xl = x2;
			x2 = x1;
			x1 = xl + d;
			fx2 = fx1;
			fx1 = funcion(x1);
		}
		else{
			xu = x1;
			x1 = x2;
			x2 = xu - d;
			fx1 = fx2;
			fx2 = funcion(x2);
		}
		if(fx1 > fx2){
			xopt = x1;
			fx = fx1;
		}
		else{
			xopt = x2;
			fx = fx2;
		}
		if(xopt != 0)
			ea = (1 - R) * fabs((xu - xl)/xopt) * 100;
		i++;
	}
	while(epsilon < ea && i < 10);
	printf("\n X optimo = %.9f \n f(Xoptimo) = %.9f", xopt, funcion(xopt));
	printf("\n %d iteraciones requeridas", i);
	printf("\n El valor del error es %.9f", ea);
}
float funcion(float x){
	return ((2*sin(x))-(pow(x,2)/2));
}
