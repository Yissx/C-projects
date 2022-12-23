/*Universidad Autónoma de Aguascalientes
  Centro de Ciencias Básicas 
  Departamento de Ciencias Exactas 
  Porgramacion Científica 
  Nancy Yissel Cuellar Valdivia
  Valeria Macías Soto
  Luis Fernando Gutiérrez Marfileño 
  Algoritmo que encuentra el valor del área bajo la curva de una función por medio del
  cálculo del área de rectágulos*/
  
#include<stdio.h>
#include<math.h>

void calculo(int, int, int, int);
float funcion(int, int);

int main(){
	int opc, limInf = -3, limSup = 3, intervalos = 6, base = 2;
	do{
  		printf("\n\n Calculo del area bajo la curva por medio de rectangulos de la funcion 2^x");
  		printf("\n 1. Calcular area con los datos predeterminados");
  		printf("\n 2. Cambiar valores de la ecuacion");
  		printf("\n 3. Cambiar valores de calculo");
  		printf("\n 4. Salir\n ");
  		scanf("%d", &opc);
  		switch(opc){
  			case 1:
  				calculo(2, 3, -3, 6);
  				break;
  			case 2:
  				printf("\n Valor de la base");
  				scanf("%d", &base);
  				calculo(base, limSup, limInf, intervalos);
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
  				calculo(base, limSup, limInf, intervalos);
  			default:
  				printf("\n Error");
  				break;
  		}
  	}
  	while(opc != 3);
}
void calculo(int base, int limSup, int limInf, int intervalos){
	int i;
	float sumatoria[2] = {0,0}, mult = (limSup - limInf) / intervalos;
	for(i=limInf; i<limSup;){
		sumatoria [0]+= (funcion(base,i) * mult);
		printf("\n la funcion evaluada en %d es %.4f", i,funcion(base,i));
		i += mult;
	}
	printf("\ la sumatoria inferior es %.4f", sumatoria[0]);
	for(i=limInf+1; i<=limSup;){
		sumatoria [1]+= (funcion(base,i) * mult);
		printf("\n la funcion evaluada en %d es %.4f", i,funcion(base,i));
		i += mult;
	}
	printf("\ la sumatoria superior es %.4f", sumatoria[1]);
	printf("\n El area de la funcion %d^x por la aproximacion rectangular inferior es %.4f",base, sumatoria[0]);
	printf("\n El area de la funcion %d^x por la aproximacion rectangular superior es %.4f",base, sumatoria[1]);
}
float funcion(int base, int exponente){
	float r = pow(base,exponente);
	return r;
}
