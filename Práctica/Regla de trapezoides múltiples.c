/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas 
  Departamento de Ciencias Exactas 
  Porgramacion Científica 
  Nancy Yissel Cuellar Valdivia
  Valeria Macías Soto
  Luis Fernando Gutiérrez Marfileño 
  Algoritmo que encuentra el valor del área bajo la curva de una función por medio del
  cálculo del área de trapezoides*/
  
#include<stdio.h>
#include<math.h>

void calculo(int, int, int, int);
float funcion(int, int);

int main(){
	int opc, limInf = -3, limSup = 3, intervalos = 6, base = 2;
	do{
  		printf("\n\n Calculo del área bajo la curva por medio de trapezoides de la funcion 2^x");
  		printf("\n 1. Calcular area con los datos predeterminados");
  		printf("\n 2. Cambiar valores de la ecuacion");
  		printf("\n 3. Cambiar valores de calculo");
  		printf("\n 4. Salir\n ");
  		scanf("%d", &opc);
  		switch(opc){
  			case 1:
  				calculo(2, -3, 3, 6);
  				break;
  			case 2:
  				printf("\n Valor de la base");
  				scanf("%d", &base);
  				calculo(base, limInf, limSup, intervalos);
  				break;
  			case 4:
  				printf("\n Fin del programa\n ");
  				system("pause");
  				break;
  			case 3:
  				printf("\n Limite de integracion a: ");
  				scanf("%d", &limInf);
  				printf("\n Limite de integracion b: ");
  				scanf("%d", &limSup);
  				printf("\n Número de intervalos: ");
  				scanf("%d", &intervalos);
  				calculo(base, limInf, limSup, intervalos);
  			default:
  				printf("\n Error");
  				break;
  		}
  	}
  	while(opc != 3);
}
void calculo(int base, int limInf, int limSup, int intervalos){
	int i; 
	float sumatoria = 0;
	for(i=limInf+1; i<limSup; i++){
		sumatoria += funcion(base,i);
		//printf("\n la funcion 2^%d es %.3f",i, funcion(base, i));
		//printf("\n sumatoria = %.4f", sumatoria);
	}
	sumatoria *= 2;
	sumatoria += funcion(base, limInf);
	sumatoria += funcion(base, limSup);
	sumatoria /= (2*intervalos);
	sumatoria *= (limSup - limInf);
	printf("\n El area de la funcion %d^x es %.4f",base, sumatoria);
}
float funcion(int base, int exponente){
	float r = pow(base,exponente);
	return r;
}
