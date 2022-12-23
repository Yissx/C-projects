/*Universidad Aut�noma de Aguascalientes
  Centro de Ciencias B�sicas 
  Departamento de Ciencias Exactas 
  Porgramacion Cient�fica 
  Nancy Yissel Cuellar Valdivia
  Luis Fernando Guti�rrez Marfile�o 
  Algoritmo que encuentra una ra�z de cierta funci�n por medio del m�todo de Falsa posici�n*/
  
#include<stdio.h>
#include<math.h>

void calculo(float, float, float);
float funcion(float);
float error(float, float);

int main(){
	int opc;
	float xs = 1.5, xi = 0;
	float e = 0.001;
	do{
  		printf("\n\n Calculo del valor de una razi de la funcion f(x) = xsen(x) - 1");
  		printf("\n 1. Calcular raiz");
  		printf("\n 2. Cambiar la tolerancia de error");
  		printf("\n 3. Cambiar valores del intervalo");
  		printf("\n 4. Salir\n ");
  		scanf("%d", &opc);
  		switch(opc){
  			case 1:
  				calculo(xi, xs, e);
  				break;
  			case 2:
  				printf("\n Epsilon: ");
  				scanf("%f", &e);
  				calculo(xi, xs, e);
  				break;
  			case 4:
  				printf("\n Fin del programa\n ");
  				system("pause");
  				break;
  			case 3:
  				printf(" x1 = ");
	  			scanf("%d",&xi);
	  			printf(" x2 = ");
	  			scanf("%d",&xs);
				break;
  			default:
  				printf("\n Error");
  				break;
  		}
  	}
  	while(opc != 3);
}
void calculo(float xi, float xs, float e){
		float fxi, fxs, xm, fxm, error, def = 0, xf = 100;
		int i = 0;
		do{
			fxs = funcion(xs);
			fxi = funcion(xi);
			//printf("\n f(%.1f) es %.9f", xs, fxs);
			//printf("\n f(%.1f) es %.9f", xi, fxi);
			xm = xs - (fxs * ((xs - xi) / (fxs - fxi)));
			//printf("\n xm es %.9f", xm);
			fxm = funcion(xm);
			//printf("\n f(%.9f) = %.9f", xm, fxm);
			if(fabs(xm - xf) <= e || fxm == 0)
				xf = xm;
			def = fxm * fxi;
			if(def > 0)
				xi = xm;
			else
				xs = xm;
			i++;
		}
		while(i < 20 && fabs(fxm) > e);
		if(i >= 20)
			printf("\n Procedimiento completado sin exito");
		else{
			printf("\n La raiz encontrada es %.11f", xm);
			printf("\n Fueron necesarias %d iteraciones", i);
		}
		    
}
float funcion(float x){
	double result;
  	result = x*(sin(x)) -1;
  	return result;
}
