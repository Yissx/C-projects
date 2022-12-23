/*Nancy Yissel Cuellar Valdivia
5to A Ingeniería en computación inteligente
Universidad Autónoma de Aguascalientes*/

#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, i, j, mayor, k = 0, l, m, color, o;
	printf("\n COLORACION DE GRAFOS");
	printf("\n Algoritmo de Welsh-Powell");
	printf("\n\n Ingrese la cantidad de vertices del grafo: ");
	scanf("%d", &n);
	char cadena[] = {'A','B','C', 'D', 'E'}; 
	printf("\n Matriz de colores\n 1. %c \n 2. %c \n 3. %c \n 4. %c \n 5. %c", cadena[0], cadena[1], cadena[2], cadena[3], cadena[4]);
	printf("\n WARNING: Tomando en cuenta que el vertice 1 es aquel con mayor grado haga lo siguiente:");
	printf("\n Llenado de la matriz de adyacencia: ingrese 1 si es adyacente y 0 si no lo es\n\n");
	int grafo[n][n], adyacencia[n][3], t[n][2];
	for(i = 0; i < n; i ++){
		adyacencia[i][0] = 0; //grado
		adyacencia[i][1] = i; //vector al que corresponde en grafo
		adyacencia[i][2] = 0; //color
	}
	//Llenar matriz de adyacencia
	for(i = 0; i < n; i ++){
		for(j = 0; j < n; j ++){
			if( j == i)
				grafo[i][j] = 0; //Si son iguales no hay arista
			else if(j > i){
				do{
				printf("   [%d][%d] = ", i+1, j+1);
				scanf("%d", &grafo[i][j]);
				grafo[j][i] = grafo[i][j]; //Doble llenado	
				}
				while(grafo[i][j] != 0 && grafo[i][j] != 1);
			}
		}
	}
	//Adyacencia xdddddd
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(grafo[i][j] == 1){
				adyacencia[j][0] += 1;
			}
		}	
	}
	//Mostrar matriz
	printf("\n\n Matriz de adyacencia\n    ");
	for(i = 0; i < n; i ++){
		printf("_%d_", i+1);
	}
	for(i = 0; i < n; i ++){
		printf("\n %d |", i+1);
		for(j = 0; j < n; j ++){
			printf(" %d ", grafo[i][j]);
		}
		//Método de la burbuja
		if(adyacencia[j][0] > adyacencia[j+1][0]){
			t[j][0] = adyacencia[j][0];
			t[j][1] = adyacencia[j][1];
			adyacencia [j][0] = adyacencia[j+1][0];
			adyacencia [j][1] = adyacencia[j+1][1];
			adyacencia[j+1][0] = t[j][0];
			adyacencia[j+1][1] = t[j][1];
		}
	}
	for(i=0; i<n; i++){
		adyacencia[i][0] = i;
	}
	//Todos los vertices ya tienen el color a
	while(k < n){
		//Trabajaremos con el vertice k
		for(i=0; i<k; i++){
			if(grafo[k][i] == 1 && adyacencia[k][2] == adyacencia[i][2])
				adyacencia[k][2] ++;
		}
		for(i=0; i<k; i++){
			if(grafo[k][i] == 1 && adyacencia[k][2] == adyacencia[i][2])
				adyacencia[k][2] ++;
		}
		k ++;
	}
	/*o=0;
	while(o < n){
		//Trabajaremos con el vertice k
		if(adyacencia[0][0] = o){
			for(i=0; i<o; i++){
				if(adyacencia[k][2] == adyacencia[i][2] && grafo[adyacencia[k][0]][i] ==1)
					adyacencia [k][2]++;
			}
		}
		for(i=0; i<k; i++){
			if(adyacencia[k][2] == adyacencia[i][2] && grafo[adyacencia[k][0]][i] ==1)
				adyacencia[k][2]++;
		}
		k++;
		if(k>=n)
			k=0;
	}*/
	for(i = 0; i < n; i ++){
		printf("\n\n Vertice %d tiene el color %c", adyacencia[i][1] +1, cadena[adyacencia[i][2]]);
	}
	return 0;
}
