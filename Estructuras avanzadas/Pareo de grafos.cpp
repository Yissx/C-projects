#include<iostream>
#include<stdlib.h>
#define N 10

using namespace std;

//m es numero de renglones y n de columnas
int renglon[N][2], columna[N][2]; //Contador de columnas y renglones disponibles
int matriz[N][N];

void contarVectores(int, int); //Hacer el conteo de cuantas aristas tiene un grafo
void evaluarMinimo(int, int);
void evaluarMaximo(int, int);
int main(){
	int n, m, i, j, k;
	cout<<"\t\t Pareo de grafos\n"<<endl;
	cout<<" Numero de vertices (horizontales): ";
	cin>>n;
	cout<<" Numero de vertices (verticales): ";
	cin>>m;	
	cout<<" Llenado de la matriz de adyacencia"<<endl;
	k = m+1; //Auxiliar para las impresiones
	for(i =0; i<m; i++){
		for(j=0; j<n; j++){
			cout<<" "<<i+1<<", "<<k<<" -> "; //Llenado de la matriz de adyacencia
			cin>>matriz[i][j];
			k++;
		}
		cout<<endl;
		k= m+1;
	}
	//renglon[i][1] va a guardar si ya trabajamos con ese renglon
	for(i=0;i<m;i++){
		renglon[i][1] = 0;
	}
	for(i=0; i<n; i++){
		columna[i][1]=0;
	}
	contarVectores(n, m);
}

void contarVectores(int n, int m){
	int k = 1, i, j, total=0; //total va a ser utilizado para indicar si ya todos los renglones y columnas son 0 para asi detener el algoritmo o seguir implementándolo
	/*columna[i][0] almacena cuantos valores de la columna son diferentes de 0, lo mismo es con renglon
	lo reiniciamos porque vamos a volver a hacer la suma de cada columna y renglon*/
	for(i=0; i<n; i++){
		columna[i][0]= 0;
	}
	for(i=0; i<m; i++){
		renglon[i][0] = 0;
	}
	cout<<" Matriz de adyacencia"<<endl;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			cout<<" ["<<matriz[i][j]<<"]"; //Mostrar matriz de adyacencia
			if(matriz[i][j] != 0)
				renglon[i][0] +=  1; //Suma de los valores del renglón
		}
		//Si tenemos mas de un valor en el renglon o si no hemos trabajado con él
		if(renglon[i][0]>1)
			total+= renglon[i][0];//saber si ya arreglamos esa parte, porque nos va a dar 1 y lo seguiremos tomando en cuenta en las envaluaciones
		cout<<" "<<renglon[i][0]<<endl;
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if(matriz[j][i] != 0){
				columna[i][0] += 1;//Suma de los valores de la columna
			}
		}
		if(columna[i][0]>0)
			total+= columna[i][0];
		cout<<"  "<<columna[i][0]<<" ";
	}
	if(total>(m+n))
		evaluarMaximo(n,m);
	else{
		cout<<endl<<" Algoritmo terminado"<<endl<<" ";
		system("pause");
	}
}

void evaluarMaximo(int n, int m){
	int i, j;
	cout<<endl<<" Evaluar minimo"<<endl;
	bool cr = false; //Si el booleano es falso, significa que utilizaremos el vector de las columnas, si es verdadero, el de los renglones
	int lugar, menor = 100; //Guarda el numero menor de aristas de un grafo
 	int vector[10];
	//Evaluar los vertices con menos aristas del grafo
	cout<<" Evaluando el menor de los renglones"<<endl;
	for(i=0; i<m; i++){
		if(renglon[i][0]<menor && renglon[i][0]>1){
			menor = renglon[i][0];
			lugar = i;
			cout<<" Nuevo menor "<<renglon[i][0]<<endl;
 		}
 	}
 	if(menor>1){//Existe la posibilidad de que un nodo de la columna tenga menos aristas que los del renglon
  		for(i=0;i<n;i++){
   			if(columna[i][0]<menor && columna[i][0]>1){
    	  	    menor = columna[i][0];
    	   	    lugar = i;
    	   	    cout<<" Nuevo menor "<<columna[i][0]<<endl;
    	   	    cr = true;
   			}
  		 }
 	 }
 	 //Ahora que conocemos cual renglon/columna evaluaremos, pasamos esa columna o renglon a "vector"
 	 int mayor = 0, lugar2; //auxiliar que encuentra el numero mayor dentro del renglon o columna seleccionado previamente
 	 if(cr==false){//renglon
 	     cout<<" El renglon seleccionado es el siguiente:"<<endl;
 	     renglon[lugar][1] ++;
 	 	 for(i=0;i<n;i++){
 	 	 	 vector[i] = matriz[lugar][i];
 	 	 	 cout<<" "<<vector[i];
 	 	 	 if(mayor < vector[i]){
 	 	 	 	//Aqui seleccionamos cuál valor del vector es el mayor para poder eliminar los demás valores
 	 	 	 	mayor = vector[i];
 	 	 	 	lugar2 = i;
 	 	 	 }	
 	 	 }
 	 	 cout<<endl<<" El mayor es: "<<mayor<<endl;
 	 	 //Eliminar los elementos sobrantes
 	 	 cout<<" Y la matriz quedo:"<<endl;
 	 	 for(i=0;i<m;i++){
 	 	 	for(j=0;j<n;j++){
 	 	 		if(i==lugar || j == lugar2)//Si en la matriz de adyacencia nos encontramos en el mismo renglon o columna que mayor
				   matriz[i][j] = 0;
				if(i==lugar && j== lugar2)
				   matriz[i][j]=mayor;
				cout<<" ["<<matriz[i][j]<<"]";
 	 	 	}
 	 	 	cout<<endl;
 	 	 }
 	 	 contarVectores(n,m);
 	  }
 	  else{
 	   	 cout<<" La columna seleccionada es la siguiente:"<<endl;
 	   	 columna[lugar][1] ++;
 	  	 for(i=0;i<m;i++){
 	  	     vector[i] = matriz[lugar][i];
 	  	     cout<<" "<<vector[i];
 	  	     if(mayor < vector[i]){
 	  	     	mayor = vector[i];
 	  	     	lugar2 = i;
 	  	     }
 	   	 }
 	   	 cout<<" El mayor es: "<<mayor<<endl;
 	   	 cout<<" Y la matriz quedo:"<<endl;
 	   	 for(i=0; i<n; i++){
 	   	 	for(j=0; j<n; j++){
 	   	 		if(i==lugar2 || j==lugar)
 	   	 			matriz[i][j] = 0;
 	   	 		if(i==lugar2 && j ==lugar)
 	   	 			matriz[i][j]= mayor;
 	   	 		cout<<" ["<<matriz[i][j]<<"]";
 	   	 	}
 	   	 	cout<<endl;
 	   	 }
 	   	 contarVectores(n,m);
 	   }
}
