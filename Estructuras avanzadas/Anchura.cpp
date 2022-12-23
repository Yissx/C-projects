#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

using namespace std;

struct nodo
{
	int valor;
	struct nodo *izq;
	struct nodo *der;
};

typedef struct nodo *ABB;
void inserta(ABB &arbol,int x);
void verArbol(ABB arbol, int nro );
void recorreNivel(ABB arbol);

struct nodoCola
{
	ABB ptr;
	struct nodoCola *sig;
};

struct cola
{
	struct nodoCola *adelante; 
	struct nodoCola *atras; 
};

void inicializa(struct cola &q);
void encola(struct cola &q, ABB n);
ABB desencola(struct cola &q);

main()
{
	setlocale(LC_ALL,"");
	
	ABB arbol = NULL;
	int n,x;
	printf("Cantidad de elementos del árbol\n");
	scanf("%d",&n);
	
	for(int i=0; i<n; i++)
	{
		printf("Ingrese el valor: ");
		scanf("%d",&x);
		inserta(arbol, x);
	}

	printf("Árbol: \n\n\n");
	verArbol(arbol, 0);
	printf("\n\nEmpieza el recorrido... \n\n");
	recorreNivel(arbol);
	return 0;
}

void inserta(ABB &arbol,int x )
{
	if(arbol==NULL)
	{
		arbol=new (struct nodo);
		arbol->valor = x;
		arbol->der = NULL;
		arbol->izq = NULL;
	}
	else
	{
		if(x<arbol->valor) 
		{
			inserta(arbol->izq,x);
		}
		else
		{
			if(x>arbol->valor)
			{
				inserta(arbol->der,x);
			}
		}
	}
}

void verArbol(ABB arbol,int nro)
{
	int i;
	if(arbol==NULL)
	{
		return;
	}
	else
	{
		verArbol(arbol->der,nro+1);
		for (i=0;i<nro;i++)
		{
			printf("   ");
	 	}
	 	printf("%d \n",arbol->valor);
		verArbol(arbol->izq,nro+1);
	}
}

void recorreNivel(ABB arbol)
{
	struct cola q;  
	inicializa(q); 
	if(arbol!=NULL)
	{
		encola(q, arbol);
		while(q.adelante!=NULL)
		{
			arbol = desencola(q);
			printf("%d  ",arbol->valor);
			if(arbol->izq!=NULL)
			{
				encola(q,arbol->izq);
			}
   			if(arbol->der!=NULL) encola(q, arbol->der);
  		}
 	}
}

void inicializa (struct cola &q)
{
	q.adelante =NULL;
	q.atras = NULL;
}

void encola(struct cola &q, ABB n) 
{
	struct nodoCola *p;        
	p =new struct nodoCola;   
	p->ptr =n;                
	p->sig =NULL;             
	if(q.adelante ==NULL)
	{
		q.adelante=p; 
	}
	else
	{
		q.atras->sig =p;      
	}
 	q.atras=p;                 
}

ABB desencola(struct cola &q)  
{
	struct nodoCola *p;
	p=q.adelante;     
	ABB n=p->ptr;
	q.adelante = q.adelante->sig;   
	delete (p);                     
	return n;
}

