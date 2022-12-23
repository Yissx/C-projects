/*Universidad Aut�noma de Aguascalientes
  Centro de Ciencias B�sicas 
  Departamento de Ciencias Exactas 
  Porgramacion Cient�fica 
  Nancy Yissel Cuellar Valdivia
  Valeria Mac�as Soto
  Luis Fernando Guti�rrez Marfile�o 
  Algoritmo que encuentra el valor del �rea bajo la curva de una funci�n por medio del
  c�lculo del �rea de trapezoides*/
  
#include<stdio.h>
#include<math.h>

void calculo(int, int);
float funcion(int);

int main(){
	int opc, limInf = 2, limSup = 8;
	do{
  		printf("\n\n Calculo del �rea bajo la curva por medio de la regla del trapecio simple de la funcion 3ln(x))");
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
