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

void calculo(int, int);
float funcion(int);

int main(){
	int opc, limInf = 2, limSup = 8;
	do{
  		printf("\n\n Calculo del área bajo la curva por medio de la regla del trapecio simple de la funcion 3ln(x))");
  		printf("\n 1. Calcular area con los datos predeterminados \n Intervalo [2,8]");
  		printf("\n 2. Cambiar valores de calculo");
  		printf("\n 3. Salir\n ");
  		scanf("%d", &opc);
  		switch(opc){
  			case 1:
  				calculo(2, 8);
  				break;
  			case 3:
  				printf("\n Fin del programa\n ");
  				system("pause");
  				break;
  			case 2:
  				printf("\n Limite de integracion a: ");
  				scanf("%d", &limInf);
  				printf("\n Limite de integracion b: ");
  				scanf("%d", &limSup);
  				calculo(limInf, limSup);
  			default:
  				printf("\n Error");
  				break;
  		}
  	}
  	while(opc != 3);
}
void calculo(int limInf, int limSup){
	float sumatoria = 0;
	sumatoria += funcion(limInf);
	sumatoria += funcion(limSup);
	sumatoria /= 2;
	sumatoria *= (limSup - limInf);
	printf("\n El area de la funcion 3ln(x) es %.9f",sumatoria);
}
float funcion(int x){
	float r = log(x);
	r *= 3;
	return r;
}
