#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo
#define Arista struct arista
#define Lista struct pila

using nampespace std;

Nodo{
	char dato; 
	Nodo* siguiente;
	Arista* adyacencia; 
	int visitado,terminado;
	int monto; 
	char anterior;
};

Arista{
	Nodo *vrt; 
	Arista *siguiente;
	int peso;
};

Lista{
	Nodo* dato;
	Lista*siguiente;
	//Usada para el recorrido
};

Nodo*inicio = NULL;
Lista*ini = NULL;
Lista*final = NULL; 

void insertarNodo();
void agregarArista(Nodo*aux,Nodo*aux2,Arista*nuevo);
void insertarArista();
void insertarPila(Nodo* aux);
void insertarCola(Nodo* aux);
Nodo *desencolar();
void reiniciar();
void dijkstra();

int main(){   
    int opcion,N,i;
	printf("Número de vertices:");
    scanf("%i",&N);
    for(i=0;i<N;i++){
    	insertarNodo();
	}
	system("cls");
    do{
    	printf("\n 1. Insertar arista\n");
        printf(" 2. Insertar vertice\n");
        printf(" 5. Iniciar algoritmo Dijkstra\n");
        printf(" 6. Salir\n");
        printf(" Ingresa una opcion:");
        scanf("%i",&opcion);
        switch(opcion){
            case 2:
                    insertarNodo();
                    break;
            case 1: insertarArista();
                    break;
            case 3: visualizarGrafo();
                    break;
            case 4: recorridos();
                    break;
            case 5: dijkstra();
			        break;
			case 6: break;
            default: printf(" Opcion no valida\n");
                     break;
        }
        system("pause");
        system("cls");
    }while(opcion!=6);
    return 1;
}

void insertarNodo(){
    Nodo* aux;
	Nodo* nuevo= (Nodo*) malloc(sizeof(Nodo)); //Memory allocate
	fflush(stdin); //limpiar
	printf(" Ingrese vertice:");
	scanf("%c", &nuevo->dato); //Asignar datos al nuevo nodo
	nuevo->siguiente = NULL; 
    nuevo->adyacencia = NULL;
    nuevo->visitado = nuevo->terminado = 0;
    nuevo->monto = -1;
    nuevo->anterior = 0;
    if(inicio == NULL){
        inicio = nuevo; //Si es el primer nodo que insertamos, sera el nodo de inicio
    }
	else{
        aux = inicio;
        while(aux->siguiente !=NULL){
            aux = aux->siguiente; //Avanzar hasta el final de la cola o lista xd
        }
        aux->siguiente = nuevo; //Enlazamos el ultimo de la lista con el nuevo nodo
      }
 }
 
void insertarArista(){   
    char ini, fin;
    Arista* nuevo = (Arista*)malloc(sizeof(Arista));
    nuevo->siguiente = NULL;
    Nodo* aux;
	Nodo* aux2;
    if(inicio == NULL){
         printf(" Error: El grafo está vacio\n");
         return; //Aun no hay nodos, termina funcion
    }
    fflush(stdin);
    printf(" Ingresar nodo inicial y final:\n");
    scanf("%c %c", &ini, &fin);
    printf(" Ingresar peso de la arista:");
    scanf("%i", &nuevo->peso);
    aux = inicio;
    aux2 = inicio;
    while(aux2 != NULL){
        if(aux2->dato == fin){
            break; //Recorrer la lista de nodos hasta que encontremos el nodo que indico el usuario
        }
        aux2 = aux2->siguiente; //asignar espacio
    }
    if(aux2 == NULL){
    	printf(" Error: vertice no encontrado\n");
    	return;
	}
    while(aux != NULL){
        if(aux->dato == ini){
            agregarArista(aux, aux2, nuevo);
            //Enviamos los nodos que unira la arista y a la arista misma
            return;
        }
        aux = aux->siguiente;
    }
    if(aux == NULL)
    	printf(" Error: vertice no encontrado\n");
}

void agregarArista(Nodo* aux, Nodo* aux2, Arista* nuevo){
    Arista* a;
    if(aux->adyacencia == NULL){   
	    aux->adyacencia = nuevo; //Asignar los nodos de llegada y salida a la arista
        nuevo->vrt = aux2;
    }
	else{   
	    a = aux->adyacencia;
        while(a->siguiente != NULL)
            a = a->siguiente;
        nuevo->vrt = aux2;
        a->siguiente = nuevo;
    }
}

void insertarPila(Nodo* aux){
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
	   nuevo->siguiente=ini;
	   ini=nuevo;    	
	}
}

void insertarCola(Nodo*aux){
	Lista*nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->dato=aux;
	nuevo->siguiente=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
		final->siguiente=nuevo;
		final=nuevo;
	}
}

Nodo*desencolar(){
	Lista*aux;
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->siguiente;
		aux->siguiente=NULL;
		if(ini==NULL)
		final=NULL;
	}
	Nodo*resultado=aux->dato;
	free(aux);
	return resultado;
}

void reiniciar(){
	if(inicio!=NULL){
		Nodo*aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}

void dijkstra(){
	Nodo *aux = inicio;
	char a,b;
	fflush(stdin);
	printf(" Ingresar nodo inicial y final:\n");
	scanf("%c %c", &a, &b);
	while(aux != NULL){ //Buscar el nodo con ese nombre
		if(aux->dato == a){
			aux->terminado = 1;
			aux->monto = 0;
			break;
		}
		aux = aux->siguiente;
	}
	if(aux == NULL){
		printf(" Vertice no encontrado\n");
		return;
	}
	while(aux != NULL){
		Arista *a = aux->adyacencia
	    while(a != NULL){
		    if(a->vrt->monto == -1 || (aux->monto + a->peso) < a->vrt->monto){
		    	a->vrt->monto = aux->monto + a->peso; 
		        a->vrt->anterior = aux->dato; 
			}
		    a = a->siguiente;
	    }
	    aux = inicio;
	    Nodo *min = inicio;
	    while(min->anterior == 0 || min->terminado ==1)
	    min=min->siguiente;
	    while(aux!=NULL){
	    	if(aux->monto<min->monto && aux->terminado==0 && aux->anterior!=0)
	    	min=aux;
	    	aux=aux->siguiente;
		}
		aux=min;
		aux->terminado=1;
		if(aux->dato==b)
		break;
	}
	while(aux->anterior!=0){
		insertarPila(aux);
		char temp=aux->anterior;
		aux=inicio;
		while(aux->dato!=temp){
		   aux=aux->siguiente;	
		}
	}
	insertarPila(aux);
	while(ini!=NULL){
		printf("%c ",desencolar()->dato);
	}
		printf("\n");
	reiniciar();
}
