/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas 
  Departamento de Ciencias Exactas 
  Porgramacion Científica 
  Nancy Yissel Cuellar Valdivia
  Valeria Macías Soto
  Luis Fernando Gutiérrez Marfileño 
  Algoritmo que encuentra el valor del área bajo la curva de la función e^-x^2 por medio de
  la regla 1/3 de Simpson*/
  
#include<stdio.h>
#include<math.h>
#define e 2.71828

void calculo(int, float, float);
float funcion(float, int);

int main(){
	int opc, exp;
	float limInf = -1, limSup = 1;
	do{
  		printf("\n\n Calculo del area bajo la curva por medio de la regla de 1/3 Simpson de la funcion e^x^2");
  		printf("\n 1. Calcular area con los datos predeterminados");
  		printf("\n 2. Cambiar valor exponencial");
  		printf("\n 3. Cambiar limites de integracion (-1, 1)");
  		printf("\n 4. Salir\n ");
  		scanf("%d", &opc);
  		switch(opc){
  			case 1:
  				calculo(2, -1, 1);
  				break;
  			case 2:
  				printf("\n Valor del exponente de x: ");
  				scanf("%d", &exp);
  				calculo(exp, limInf, limSup);
  				break;
  			case 3:
  				printf("\n Limite inferior: ");
  				scanf("%f", &limInf);
  				printf(" Limite superior: ");
  				scanf("%f", &limSup);
  				calculo(exp, limInf, limSup);
  				break;
  			case 4:
  				printf("\n Fin del programa\n ");
  				system("pause");
  				break;
  			default:
  				printf("\n Error");
  				break;
  		}
  	}
  	while(opc != 4);
}
void calculo(int exp, float limInf, float limSup){
	float h = (limSup - limInf) / 2;
	float c = (limSup + limInf) / 2;
	float t = funcion(limSup, exp) + funcion(limInf, exp) + (4*funcion(c, exp));
	t *= h;
	t /= 3;
	printf("\n El area bajo la curva es %.9f", t);
}
float funcion(float x, int exp){
	x = pow(x, exp);
	x *= -1;
	float r = pow(e,x);
	return r;
}
