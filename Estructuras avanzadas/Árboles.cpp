
//Recorrido de arboles preorden
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

struct Nodo{
	int dato, i, d, v;
	Nodo *derecho;
	Nodo *izquierdo;
	Nodo *padre;
	
};

void menu();
Nodo *crearNodo(int, Nodo *);
void insertarNodo(Nodo *&, int, Nodo *);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int); 
void eliminar(Nodo *, int);
void eliminarNodo(Nodo*);
void reemplazar(Nodo *,Nodo *);
void destruir(Nodo *);
void preorden(Nodo *);
void inorden(Nodo *);
void postorden(Nodo *);
Nodo *minimo(Nodo *);
void busquedaProfundidad(Nodo *, int,int);
void regresion(Nodo *, int, int);

Nodo *arbol = NULL;
int v[20][2];
bool end = false;
int a;

int main(){
	for(int k=0; k<20; k++){
		//con el valor de 0/1 diremos que el nodo en el valor i no ha sido visitado
		v[k][1] = 0;
	}
	menu();
	getch();
	return 0; 
}

void menu(){
	int dato, opcion, contador;
	do{
		cout<<"\t.MENU."<<endl;
		cout<<" 1. Insertar un nuevo nodo"<<endl;
		cout<<" 2. Mostrar el arbol completo"<<endl;
		cout<<" 3. Buscar elemento en el arbol"<<endl;
		cout<<" 4. Recorrido PreOrden"<<endl;
		cout<<" 5. Recorrido InOrden"<<endl;
		cout<<" 6. Recorrido PostOrden"<<endl;
		cout<<" 7. Eliminar nodo"<<endl;
		cout<<" 8. Salir"<<endl;
		cout<<" 9. Busqueda en profundidad"<<endl;
		cout<<"10. Algoritmo Kruskal"<<endl;
		cout<<"11. Algoritmo Dijkstra"<<endl;
		cout<<"\n Ingrese una opcion: ";
		cin>>opcion;
		switch(opcion){
			case 1: 
				cout<<"\n Digite un numero: ";
				cin>>dato;
				insertarNodo(arbol,dato,NULL);
				cout<<"\n";
				break;
			case 2:
				cout<<" Mostrando el arbol completo (rotacion izquierda): \n\n";
				mostrarArbol(arbol,contador);
				cout<<"\n";
				system("pause");
				break;
			case 3:
				cout<<"\n Digite el elemento a buscar: ";
				cin>>dato;
				if(busqueda(arbol,dato)== true){
					cout<<"\n El elemento "<<dato<<" ha sido encontrado dentro del arbol"<<endl;
				}
				else{
					cout<<"\n El elemento "<<dato<<" no ha sido encontrado en el arbol"<<endl;
				}
				system("pause");
					break;
			case 4:
				cout<<"\n Recorrido PreOrden:\n "<<endl;
				preorden(arbol);
				cout<<"\n\n ";
				system("pause");
				break;
			case 5:
				cout<<"\n Recorrido InOrden:\n "<<endl;
				inorden(arbol);
				cout<<"\n\n ";
				system("pause");
				break;
			case 6:
				cout<<"\n Recorrido PostOrden:\n ";
				postorden(arbol);
				cout<<"\n\n ";
				system("pause");
				break;
			case 7:
				cout<<" Digite el nodo a eliminar: ";
				cin>>dato;
				eliminar(arbol,dato);
				cout<<"\n ";
				break;
			case 9:
				cout<<" Digite el nodo a buscar: ";
				cin>>dato;
				int j = 0;
				busquedaProfundidad(arbol, dato, j);
				cout<<"\n ";
				system("pause");
				break;
		}
		system("cls");
	}
	while(opcion != 8);
}
void busquedaProfundidad(Nodo *nodo, int n, int i){
	if(nodo == NULL){ //si el arbol esta vacio
		return;
	}
	if(end==false){ //solo entrara aqui sino hemos encontrado el nodo deseado
		nodo->v = nodo->v + 1;
		v[i][0] = nodo->dato; //darle al vector el valor del nodo en el que nos encontramos
		v[i][1] = v[i][1]+1; //diremos que el nodo ha sido visitado una vez mas
		//cout<<"Vamos en el nodo "<<nodo->dato<<" y el valor de i es "<<i<<" ademas el nodo ha sido visitado "<<v[i][1]<<" veces"<<endl;
		i++;
		if(nodo->dato == n){
			end = true;	//si nos encontramos en elnodo que estamos buscando
			cout<<" Ya terminamos "<<endl;
			cout<<" Algoritmo terminado i vale: "<<i<<endl;
			for(a=0;a<i; a++){
				cout<<" "<<v[a][0];
			}
			cout<<endl<<" ";
			system("pause");
			return;
		}
		else{
			for(a=0;a<i; a++){
				cout<<" "<<v[a][0];
			}
			cout<<endl;
			if(nodo->izquierdo != NULL && nodo->i == 0){ //si aun tiene hijos izquierdos
				cout<<" Hijo izquierdo"<<endl;
				nodo->i = nodo->i + 1; // que ya se bajo una vez por ese hijo
				busquedaProfundidad(nodo->izquierdo, n, i);
			}
			else if(nodo->izquierdo == NULL && nodo->derecho != NULL && nodo->d == 0 || nodo->d==0 && nodo->i >0 && nodo->derecho != NULL){ //si no tiene hijos izquierdos pero si por la derecha
				cout<<" Hijo derecho"<<endl;
				nodo->d = nodo->d + 1;
				busquedaProfundidad(nodo->derecho, n, i);	
			}
			else if(nodo->izquierdo == NULL && nodo->derecho == NULL || nodo->i>0 && nodo->d>0){ 
				// si no tiene hijos o si ya los visito a ambos
				regresion(nodo,n,i);
				/*1: ha sido visitado el mismo como hijo de un nodo
				  2: visito al hijo izquierdo y luego se regreso
				  si el valor es 3 significa que ya visito a sus dos hijos, por lo que ya no tiene nada que hacer en ese nodo
				  entonces hace regresion hasta encontrar a un padre adecuado*/ 
			}		
		}
	}
}
void regresion(Nodo *nodo, int n, int i){
	do{
		cout<<" Regresion"<<endl;
		nodo = nodo->padre;//se regresa con su padre	
		i--; 
	}
	while(nodo->v > 2);//regresar al nodo padre hasta que el vector en la posicion i tenga un valor de menor o igual a 2
	if(nodo->derecho != NULL && nodo->d==0){
		i++;
		nodo->d = nodo->d + 1;
		cout<<" Derecho"<<endl;
		busquedaProfundidad(nodo->derecho, n, i);
	}
	else{
		i--;
		regresion(nodo, n, i);		
	}
}
Nodo *crearNodo(int n, Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->izquierdo = NULL;
	nuevo_nodo->derecho = NULL;
	nuevo_nodo->padre = padre;
	nuevo_nodo->i = 0;
	nuevo_nodo->d = 0;
	nuevo_nodo->v = 0;
	return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){
	if(arbol == NULL){
		Nodo *nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	}
	else{ //si el arbol ya tiene un nodo o mas
		int valorRaiz = arbol->dato;
		if(n < valorRaiz){ //si el elemento es menor al valor de la raiz
			insertarNodo(arbol->izquierdo, n,arbol);
		}
		else{
			insertarNodo(arbol->derecho, n,arbol);
		}
	}
}

bool busqueda(Nodo *arbol, int n){
	if(arbol == NULL){
		return false;
	}
	else if(arbol->dato == n){
		return true;
	}
	else if(n < arbol->dato){
		return busqueda(arbol->izquierdo,n);
	}
	else{
		return busqueda (arbol->derecho,n);
	}
	
	
}

void preorden(Nodo *arbol){
	if(arbol == NULL){ //si el arbol esta vacio
		return;
	}
	else{ 
		cout<<arbol->dato<<"-";
		preorden(arbol->izquierdo);
		preorden(arbol->derecho);
	}
}

void inorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inorden(arbol->izquierdo);
		cout<<arbol->dato<<"-";
		inorden(arbol->derecho);
	}
}

void postorden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		postorden(arbol->izquierdo);
		postorden(arbol->derecho);
		cout<<arbol->dato<<" ";
	}
}

void mostrarArbol(Nodo *arbol, int contador){
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->derecho, contador+1);
		for(int i=0;i<contador;i++){
			cout<<"    ";
		}
	cout<<arbol->dato<<endl;
	mostrarArbol(arbol->izquierdo, contador+1);
	}
}

void eliminar(Nodo* arbol, int n){
	if(arbol == NULL){
		return;
	}
	else if(n < arbol->dato){
		eliminar(arbol->izquierdo,n);
	}
	else if(n > arbol->dato){
		eliminar(arbol->derecho,n);
	}
	else{
		eliminarNodo(arbol);
	}
}

Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->izquierdo){
		return minimo(arbol->izquierdo);
	}
	else{
		return arbol;
	}
}
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izquierdo && nodoEliminar->derecho){
		Nodo *menor = minimo(nodoEliminar->derecho);
		nodoEliminar -> dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izquierdo){
		reemplazar(nodoEliminar,nodoEliminar->izquierdo);
		destruir(nodoEliminar);
	}
	else if(nodoEliminar->derecho){
		reemplazar(nodoEliminar,nodoEliminar->derecho);
		destruir(nodoEliminar);
	}
	else{
		reemplazar(nodoEliminar,NULL);
		destruir(nodoEliminar);
	}
}
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		if(arbol->dato == arbol->padre->izquierdo->dato){
			arbol->padre->izquierdo = nuevoNodo;
		}
		else if(arbol->dato == arbol->padre->derecho->dato){
			arbol->padre->derecho = nuevoNodo;
		}
	}
	if(nuevoNodo){
		nuevoNodo->padre = arbol->padre;
	}
}
void destruir(Nodo *nodo){
	nodo->izquierdo = NULL;
	nodo->derecho = NULL;
	delete nodo;
}
