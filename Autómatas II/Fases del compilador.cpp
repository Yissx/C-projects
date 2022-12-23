#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <Windows.h>



#define num 13
int cont=0;
int j;
	
	// x=5;y=2;z=x+y;
	

void Arbol(char cadena[num],int xcont,int ycont,int sentencia);
void Analisis_Sintactico(char cadena[num],int xcont,int ycont,int sentencia);
void Analisis_Semantico(char cadena[num],int xcont,int ycont,int sentencia);
void Optimizador_codigo_fuente(char cadena[num],int xcont,int ycont,int sentencia);
void Generador_codigo(char cadena[num], int xcont, int ycont,int sentencia);
void Optimizador_de_codigo_objeto(char cadena[num], int xcont, int ycont,int sentencia);
void q0 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q1 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q2 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q3 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q4 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q5 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q6 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q7 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);
void q8 (int i,char cadena[num], int Bandera, int xcont, int ycont,int sentencia);


void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
 }  

int portada()
{
		
	system("Color B0");

	Sleep(300);
	
	printf("\n\n\n\n\n\n\t\t\t\t\t       ELEMENTOS DE UN COMPILADOR \n\n\n\n");
	Sleep(300);
	printf("\t\t\t\t      Andrea Juliett Ordaz de Vierna ID: 189420\n\n");
	Sleep(300);
	printf("\t\t\t\t      Marco Antonio Martinez Gaytan  ID: 253959\n\n");
	Sleep(300);	
	printf("\t\t\t\t      Montserrat Alejandra Ulloa Rivera  ID: 253959\n\n");
	Sleep(300);
	printf("\t\t\t\t      Andrea de Santiago Legaspi ID: 211343\n\n");
	Sleep(300);
	printf("\t\t\t\t      Nancy Yissel Cuellar Valdivia  ID: 256351\n\n");
	Sleep(300);
	printf("\t\t\t\t      Valeria Macias Soto  ID: 254312\n\n");
	Sleep(300);
	printf("\n\t\t\t\t                23 de agosto de 2021");
	
	Sleep(300);
	
	printf("\n\n\t\t\t\t\t ");
	
	system("pause");
	system("cls");

	
	printf("\n\n\n\t\t\t\t\t\t    INTRODUZCA EL CODIGO");

	gotoxy(3,6);printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95);
	
	
}

int main()
{
	
	char cadena[num];
	int xcont,ycont,totalcont;
	portada();
	int Bandera = 0;
	int sentencia=3;


	printf("\n\n  Es importante que las lineas introducidas sea de la siguiente manera:\n\n ");
	printf("\t\t\t\tx=numero entero (0 - 9);y=numero entero (0 - 9);z=x+y;\n\n");
	printf("\t\t Codigo: ");
	
	scanf("%s",&cadena);
	int i = 0;
	printf("\n\n\n\n\t\t");
		system("pause");
		system("cls");
		q0(i,cadena,Bandera,xcont,ycont,sentencia);
	
	printf("\n\n\n");
	system("pause");
	
}


void q0(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	if(cadena[i] == 'x')
	{
		cadena[i] = 'x';
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tCargando");
		for(j=0;j<5;j++){
			Sleep(600);
			printf(".");
		}
		system("cls");
		
		printf("\n\n\t\t\t\t\t   ANALIZADOR LEXICO\n\n\n");
		
				printf("\t\t\t\t\t %c %c: identificador\n\n",175,cadena[i]);
		
		q1(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
	else 
	{
		printf("Error en la compilacion");
	}
}

void q1(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	if(cadena[i] == '=')
	{
		cadena[i] = '=';
				printf("\t\t\t\t\t %c %c: asignacion\n\n",175,cadena[i]);
	
		q2(i + 1, cadena,Bandera,xcont,ycont, sentencia); //1 io
	}
	
	else 
	{
		printf("Error en la compilacion");
	}
	
}

void q2(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	if(cadena[i] == '0')
	{
		cadena[i] = '0';
		
		if(Bandera == 0){
			xcont= 0;
		}
		else if(Bandera == 1){
			ycont=0;
		}
		
			
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);

		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
	else if(cadena[i] == '1')
	{
		cadena[i] = '1';
		
		if(Bandera == 0){
			xcont= 1;
		}
		else if(Bandera == 1){
			ycont=1;
		}
		
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);
		
		
		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
	else if(cadena[i] == '2')
	{
		cadena[i] = '2';
		
		if(Bandera == 0){
			xcont= 2;
		}
		else if(Bandera == 1){
			ycont=2;
		}
		
		
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);
	
		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
	else if(cadena[i] == '3')
	{
		cadena[i] = '3';
		
		if(Bandera == 0){
			xcont= 3;
		}
		else if(Bandera == 1){
			ycont=3;
		}
		
				
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);

		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
		else if(cadena[i] == '4')
	{
		cadena[i] = '4';
		
		if(Bandera == 0){
			xcont= 4;
		}
		else if(Bandera == 1){
			ycont=4;
		}
		
	
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);
		
		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
		else if(cadena[i] == '5')
	{
		cadena[i] = '5';
		
			if(Bandera == 0){
			xcont= 5;
		}
		else if(Bandera == 1){
			ycont=5;
		}
		
			
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);
		
		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
		else if(cadena[i] == '6')
	{
		cadena[i] = '6';
		
		if(Bandera == 0){
			xcont= 6;
		}
		else if(Bandera == 1){
			ycont=6;
		}
		
	
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);

		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
		else if(cadena[i] == '7')
	{
		cadena[i] = '7';
		
		if(Bandera == 0){
			xcont= 7;
		}
		else if(Bandera == 1){
			ycont=7;
		}
		
			
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);

		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
		else if(cadena[i] == '8')
	{
		cadena[i] = '8';
		
		if(Bandera == 0){
			xcont= 8;
		}
		else if(Bandera == 1){
			ycont= 8;
		}
		
	
				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);

		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
		else if(cadena[i] == '9')
	{
		cadena[i] = '9';
		
			if(Bandera == 0){
			xcont= 9;
		}
		else if(Bandera == 1){
			ycont= 9;
		}
		

				printf("\t\t\t\t\t %c %c: numero\n\n",175,cadena[i]);
		
		q2(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
		else if(cadena[i] == ';')
	{
		cadena[i] = ';';
			
				printf("\t\t\t\t\t %c %c: punto y coma\n\n",175,cadena[i]);
				
		q3(i + 1, cadena,Bandera,xcont,ycont,sentencia); //1 io
	}
	
	
}	

void q3(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia) //Comienza 1
{
	
	
	Bandera=1;
	
	if(cadena[i] == 'z')
	{
		cadena[i] = 'z';
		
				printf("\t\t\t\t\t %c %c: identificador\n\n",175,cadena[i]);
	
		q4(i+1, cadena,Bandera,xcont,ycont, sentencia);
	}
	
		else if(cadena[i] == 'y')
	{
		cadena[i] = 'y';
	
				printf("\t\t\t\t\t %c %c: identificador\n\n",175,cadena[i]);
	
	    q5(i+1, cadena,Bandera,xcont,ycont,sentencia);
	}
	
	else if(cadena[4] != 'y'){
		sentencia = 1;
		Arbol(cadena,xcont,ycont,sentencia);

	}
	else if(cadena[8] != 'z'){
		sentencia = 2;
		Arbol(cadena,xcont,ycont,sentencia);
	}
}

void q4(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	if(cadena[i] == '=')
	{
		cadena[i] = '=';
	
				printf("\t\t\t\t\t %c %c: asignador\n\n",175,cadena[i]);

		q6(i+1, cadena,Bandera,xcont,ycont,sentencia);
	}
}

void q5(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	
	if(cadena[i] == '=')
	{
		cadena[i] = '=';
				
				printf("\t\t\t\t\t %c %c: asignador\n\n",175,cadena[i]);
	
		q2(i+1, cadena,Bandera,xcont,ycont,sentencia);
	}
}

void q6(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	
	if(cadena[i] == 'x')
	{
		cadena[i] = 'x';

				printf("\t\t\t\t\t %c %c: identificador\n\n",175,cadena[i]);
	
		q7(i+1, cadena,Bandera,xcont,ycont,sentencia);
	}
}

void q7(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	if(cadena[i] == 'y')
	{
		cadena[i] = 'y';
			
				printf("\t\t\t\t\t %c %c: identificador\n\n",175,cadena[i]);
	
		q7(i+1, cadena,Bandera,xcont,ycont,sentencia);
	}
	else if(cadena[i] == '+')
	{
		cadena[i] = '+';
			
				printf("\t\t\t\t\t %c %c: signo mas\n\n",175,cadena[i]);
	
	    q7(i+1, cadena,Bandera,xcont,ycont,sentencia);
	}
	
		else if(cadena[i] == ';')
	{
		cadena[i] = ';';
	
				printf("\t\t\t\t\t %c %c: punto y coma\n\n",175,cadena[i]);

	    q8(i+1, cadena,Bandera,xcont,ycont,sentencia);
	}
}

void q8(int i, char cadena[num], int Bandera, int xcont, int ycont, int sentencia)
{
	printf("\n\n\t\t\t\t");
		system("pause");
	system("cls");
	Arbol(cadena,xcont,ycont,sentencia);
	


}


void Arbol(char cadena[num], int xcont, int ycont, int sentencia){
	
		
	printf("\n\n\n\n\t\t\t\t\t");
		system("pause");
			system("cls");
	
	printf("\n\n\n\n\t\t\t\t\t\tARBOL DE ANALISIS GRAMATICAL\n\n");
	printf("\t\tEs un auxiliar util para visualizar la sintaxis de un programa o de un elemento de programa\n\t\tpero no es eficaz en su representacion de esa estructura.\n\n");
	Sleep(300);
	
	system("pause");
	system("cls");
	
	switch(sentencia){
		case 1:{

			system("cls");
			
			gotoxy(48,5);printf("Expresion");
	Sleep(50);
	
	gotoxy(52,6);printf("%c",179);
	Sleep(50);
	gotoxy(52,7);printf("%c",179);
	Sleep(50);
	gotoxy(52,8);printf("%c",179);
	Sleep(50);
		
	gotoxy(41,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(52,10);printf("%c",179);
	Sleep(50);
	gotoxy(52,11);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(43,10);printf("/");
	Sleep(50);
	gotoxy(42,11);printf("/");
	Sleep(50);
		
	gotoxy(61,10);printf("%c",92);
	Sleep(50);
	gotoxy(62,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(52,12);printf("%c",cadena[1]);
	Sleep(50);
	
	gotoxy(37,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(41,13);printf("%c",179);
	Sleep(50);
	gotoxy(41,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(58,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(63,13);printf("%c",179);
	Sleep(50);
	gotoxy(63,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,15);printf("Expresion de");
	gotoxy(38,16);printf("subindice");
	Sleep(50);
	
	gotoxy(41,17);printf("%c",179);
	Sleep(50);
	gotoxy(41,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(37,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(41,20);printf("%c",179);
	Sleep(50);
	gotoxy(41,21);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(36,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(41,23);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(58,15);printf("Expresion");
	gotoxy(59,16);printf("aditivo");
	Sleep(50);
	
	gotoxy(63,17);printf("%c",179);
	Sleep(50);
	gotoxy(63,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(58,19);printf("Expresion");
	Sleep(300);
	
	gotoxy(63,20);printf("%c",179);
	Sleep(50);
	gotoxy(63,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(61,22);printf("Numero");
	Sleep(300);
	
	gotoxy(63,23);printf("%c",cadena[2]);
	Sleep(300);

			break;
		}
		
		
		
		case 2:{
			
			
			gotoxy(53,5);printf("Expresion");
	Sleep(50);
	
	gotoxy(51,6);printf("/");
	Sleep(50);
	gotoxy(50,7);printf("/");
	Sleep(50);
	gotoxy(49,8);printf("/");
	Sleep(50);
	
	gotoxy(61,6);printf("%c",92);
	Sleep(50);
	gotoxy(62,7);printf("%c",92);
	Sleep(50);
	gotoxy(63,8);printf("%c",92);
	Sleep(50);
	
	
	
	gotoxy(26,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(36,10);printf("%c",179);
	Sleep(50);
	gotoxy(36,11);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(28,10);printf("/");
	Sleep(50);
	gotoxy(27,11);printf("/");
	Sleep(50);
		
	gotoxy(46,10);printf("%c",92);
	Sleep(50);
	gotoxy(47,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(36,12);printf("%c",cadena[1]);
	Sleep(50);
	
	gotoxy(22,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(26,13);printf("%c",179);
	Sleep(50);
	gotoxy(26,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(43,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(48,13);printf("%c",179);
	Sleep(50);
	gotoxy(48,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(21,15);printf("Expresion de");
	gotoxy(23,16);printf("subindice");
	Sleep(50);
	
	gotoxy(26,17);printf("%c",179);
	Sleep(50);
	gotoxy(26,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(22,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(26,20);printf("%c",179);
	Sleep(50);
	gotoxy(26,21);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(21,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(26,23);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(43,15);printf("Expresion");
	gotoxy(44,16);printf("aditivo");
	Sleep(50);
	
	gotoxy(48,17);printf("%c",179);
	Sleep(50);
	gotoxy(48,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(43,19);printf("Expresion");
	Sleep(300);
	
	gotoxy(48,20);printf("%c",179);
	Sleep(50);
	gotoxy(48,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(46,22);printf("Numero");
	Sleep(300);
	
	gotoxy(48,23);printf("%c",cadena[2]);
	Sleep(300);
	
	gotoxy(63,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(64,10);printf("/");
	Sleep(50);
	gotoxy(63,11);printf("/");
	Sleep(50);
	
	gotoxy(74,10);printf("%c",179);
	Sleep(50);
	gotoxy(74,11);printf("%c",179);
	Sleep(50);
	
	
	
	gotoxy(83,10);printf("%c",92);
	Sleep(50);
	gotoxy(84,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(74,12);printf("%c",cadena[5]);
	Sleep(50);
	
	gotoxy(58,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(62,13);printf("%c",179);
	Sleep(50);
	gotoxy(62,14);printf("%c",179);
	Sleep(50);
	
	
	
	gotoxy(57,15);printf("Expresion de");
	gotoxy(58,16);printf("subindice");
	Sleep(50);
	
	gotoxy(62,17);printf("%c",179);
	Sleep(50);
	gotoxy(62,18);printf("%c",179);
	Sleep(50);
	
    gotoxy(58,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(62,20);printf("%c",179);
	Sleep(50);
	gotoxy(62,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(56,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(62,23);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(81,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(85,13);printf("%c",179);
	Sleep(50);
	gotoxy(85,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(81,15);printf("Expresion");
	gotoxy(81,16);printf("aditivo");
	Sleep(50);
	
	gotoxy(85,17);printf("%c",179);
	Sleep(50);
	gotoxy(85,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(81,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(85,20);printf("%c",179);
	Sleep(50);
	gotoxy(85,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(82,22);printf("Numero");
	Sleep(50);
	
	gotoxy(85,23);printf("%c",cadena[6]);
	Sleep(50);
	
		
			
			break;
		}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		case 3:{
			
			gotoxy(51,5);printf("Expresion");
	Sleep(50);
	
	gotoxy(50,5);printf("-");
	Sleep(50);
	gotoxy(49,5);printf("-");
	Sleep(50);
	gotoxy(48,5);printf("-");
	Sleep(50);
	gotoxy(17,5);printf("---------------------------------");
	Sleep(50);
	
	
	gotoxy(61,5);printf("------------------------------");
	Sleep(50);
	
	gotoxy(17,6);printf("%c",179);
	Sleep(50);
	gotoxy(17,7);printf("%c",179);
	Sleep(50);
	gotoxy(17,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(55,6);printf("%c",179);
	Sleep(50);
	gotoxy(55,7);printf("%c",179);
	Sleep(50);
	gotoxy(55,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(6,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(17,10);printf("%c",179);
	Sleep(50);
	gotoxy(17,11);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(8,10);printf("/");
	Sleep(50);
	gotoxy(7,11);printf("/");
	Sleep(50);
		
	gotoxy(26,10);printf("%c",92);
	Sleep(50);
	gotoxy(27,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(17,12);printf("%c",cadena[1]);
	Sleep(50);
	
	gotoxy(2,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(6,13);printf("%c",179);
	Sleep(50);
	gotoxy(6,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(23,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(28,13);printf("%c",179);
	Sleep(50);
	gotoxy(28,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(1,15);printf("Expresion de");
	gotoxy(3,16);printf("subindice");
	Sleep(50);
	
	gotoxy(6,17);printf("%c",179);
	Sleep(50);
	gotoxy(6,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(2,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(6,20);printf("%c",179);
	Sleep(50);
	gotoxy(6,21);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(1,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(6,23);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(23,15);printf("Expresion");
	gotoxy(24,16);printf("aditivo");
	Sleep(50);
	
	gotoxy(28,17);printf("%c",179);
	Sleep(50);
	gotoxy(28,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(23,19);printf("Expresion");
	Sleep(300);
	
	gotoxy(28,20);printf("%c",179);
	Sleep(50);
	gotoxy(28,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(26,22);printf("Numero");
	Sleep(300);
	
	gotoxy(28,23);printf("%c",cadena[2]);
	Sleep(300);
	
	gotoxy(43,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(55,10);printf("%c",179);
	Sleep(50);
	gotoxy(55,11);printf("%c",179);
	Sleep(50);
	
	gotoxy(44,10);printf("/");
	Sleep(50);
	gotoxy(43,11);printf("/");
	Sleep(50);
	
	
	gotoxy(63,10);printf("%c",92);
	Sleep(50);
	gotoxy(64,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(55,12);printf("%c",cadena[5]);
	Sleep(50);
	
	gotoxy(38,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(42,13);printf("%c",179);
	Sleep(50);
	gotoxy(42,14);printf("%c",179);
	Sleep(50);
	
	
	
	gotoxy(37,15);printf("Expresion de");
	gotoxy(38,16);printf("subindice");
	Sleep(50);
	
	gotoxy(42,17);printf("%c",179);
	Sleep(50);
	gotoxy(42,18);printf("%c",179);
	Sleep(50);
	
    gotoxy(38,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(42,20);printf("%c",179);
	Sleep(50);
	gotoxy(42,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(42,23);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(61,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(65,13);printf("%c",179);
	Sleep(50);
	gotoxy(65,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(61,15);printf("Expresion");
	gotoxy(61,16);printf("aditivo");
	Sleep(50);
	
	gotoxy(65,17);printf("%c",179);
	Sleep(50);
	gotoxy(65,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(61,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(65,20);printf("%c",179);
	Sleep(50);
	gotoxy(65,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(62,22);printf("Numero");
	Sleep(50);
	
	gotoxy(65,23);printf("%c",cadena[6]);
	Sleep(50);
	
	gotoxy(90,6);printf("%c",179);
	Sleep(50);
	gotoxy(90,7);printf("%c",179);
	Sleep(50);
	gotoxy(90,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(79,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(90,10);printf("%c",179);
	Sleep(50);
	gotoxy(90,11);printf("%c",179);
	Sleep(50);
	
	gotoxy(80,10);printf("/");
	Sleep(50);
	gotoxy(79,11);printf("/");
	Sleep(50);
	
	gotoxy(100,10);printf("%c",92);
	Sleep(50);
	gotoxy(101,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(90,12);printf("%c",cadena[9]);
	Sleep(50);
	
	gotoxy(74,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(78,13);printf("%c",179);
	Sleep(50);
	gotoxy(78,14);printf("%c",179);
	Sleep(50);

	gotoxy(73,15);printf("Expresion de");
	gotoxy(75,16);printf("subindice");
	Sleep(50);
	
	gotoxy(78,17);printf("%c",179);
	Sleep(50);
	gotoxy(78,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(74,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(78,20);printf("%c",179);
	Sleep(50);
	gotoxy(78,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(72,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(78,23);printf("%c",cadena[8]);
	Sleep(50);
	
	gotoxy(100,12);printf("Expresion");
	Sleep(50);
	
	gotoxy(104,13);printf("%c",179);
	Sleep(50);
	gotoxy(104,14);printf("%c",179);
	Sleep(50);
	
	gotoxy(100,15);printf("Expresion");
	gotoxy(101,16);printf("aditivo");
	Sleep(50);
	
	gotoxy(100,17);printf("/");
	Sleep(50);
	gotoxy(99,18);printf("/");
	Sleep(50);
	
	gotoxy(109,17);printf("%c",92);
	Sleep(50);
	gotoxy(110,18);printf("%c",92);
	Sleep(50);
	
	gotoxy(90,19);printf("Expresion");
	Sleep(50);
		
	gotoxy(94,20);printf("%c",179);
	Sleep(50);
	gotoxy(94,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(89,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(94,23);printf("%c",cadena[10]);
	Sleep(50);
	
	gotoxy(104,17);printf("%c",179);
	Sleep(50);
	gotoxy(104,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(104,19);printf("%c",cadena[11]);
	Sleep(50);
	
	gotoxy(108,19);printf("Expresion");
	Sleep(50);
	
	gotoxy(112,20);printf("%c",179);
	Sleep(50);
	gotoxy(112,21);printf("%c",179);
	Sleep(50);
	
	gotoxy(106,22);printf("Identificador");
	Sleep(50);
	
	gotoxy(112,23);printf("%c",cadena[12]);
	Sleep(50);
			break;
		}
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	Analisis_Sintactico(cadena,xcont,ycont,sentencia);
	
}

void Analisis_Sintactico(char cadena[num], int xcont, int ycont, int sentencia){
	
		
	printf("\n\n\n\n\n\n\n\t\t\t");
		system("pause");
			system("cls");

	printf("\n\n\n\n\t\t\t\tANALIZADOR SINTACTICO\n\n");
	printf("\t\tRecibe el codigo fuente en la froma de tokens proveniente del analizador lexico\n\t\t y realiza el análisis sintáctico, que determina la estructura del programa\n\n\n\t\t\t");
	
	system("pause");
	system("cls");
	
	
	switch(sentencia){
		
		
		
		case 1:{
			
			
						
	gotoxy(49,5);printf("Expresion ");
	Sleep(50);
	
	
	gotoxy(52,6);printf("%c",179);
	Sleep(50);
	gotoxy(52,7);printf("%c",179);
	Sleep(50);
	gotoxy(52,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(41,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(43,10);printf("/");
	Sleep(50);
	gotoxy(42,11);printf("/");
	Sleep(50);
		
	gotoxy(61,10);printf("%c",92);
	Sleep(50);
	gotoxy(62,11);printf("%c",92);
	Sleep(50);
	
	
	gotoxy(41,12);printf("%c",179);
	Sleep(50);
	gotoxy(41,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(63,12);printf("%c",179);
	Sleep(50);
	gotoxy(63,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,14);printf("Expresion de");
	gotoxy(38,15);printf("subindice");
	Sleep(50);
	
	gotoxy(41,16);printf("%c",179);
	Sleep(50);
	gotoxy(41,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(41,18);printf("%c",179);
	Sleep(50);
	gotoxy(41,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(35,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(41,21);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(58,14);printf("Expresion");
	gotoxy(59,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(63,16);printf("%c",179);
	Sleep(50);
	gotoxy(63,17);printf("%c",179);
	Sleep(50);

	gotoxy(63,18);printf("%c",179);
	Sleep(50);
	gotoxy(63,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(61,20);printf("Numero");
	Sleep(50);
	
	gotoxy(62,21);printf("%c",cadena[2]);
	Sleep(50);
	

	
			
			
			
			break;
		}
		
		
		
		case 2:{
			
			
	gotoxy(52,5);printf("Expresion ");
	Sleep(50);
	
		gotoxy(51,6);printf("/");
	Sleep(50);
	gotoxy(50,7);printf("/");
	Sleep(50);
	gotoxy(49,8);printf("/");
	Sleep(50);
	
	gotoxy(61,6);printf("%c",92);
	Sleep(50);
	gotoxy(62,7);printf("%c",92);
	Sleep(50);
	gotoxy(63,8);printf("%c",92);
	Sleep(50);
	



	
	gotoxy(26,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(28,10);printf("/");
	Sleep(50);
	gotoxy(27,11);printf("/");
	Sleep(50);
		
	gotoxy(46,10);printf("%c",92);
	Sleep(50);
	gotoxy(47,11);printf("%c",92);
	Sleep(50);
	
	
	gotoxy(26,12);printf("%c",179);
	Sleep(50);
	gotoxy(26,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(48,12);printf("%c",179);
	Sleep(50);
	gotoxy(48,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(21,14);printf("Expresion de");
	gotoxy(23,15);printf("subindice");
	Sleep(50);
	
	gotoxy(26,16);printf("%c",179);
	Sleep(50);
	gotoxy(26,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(26,18);printf("%c",179);
	Sleep(50);
	gotoxy(26,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(20,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(26,21);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(43,14);printf("Expresion");
	gotoxy(44,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(48,16);printf("%c",179);
	Sleep(50);
	gotoxy(48,17);printf("%c",179);
	Sleep(50);

	gotoxy(48,18);printf("%c",179);
	Sleep(50);
	gotoxy(48,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(46,20);printf("Numero");
	Sleep(50);
	
	gotoxy(47,21);printf("%c",cadena[2]);
	Sleep(50);
	
	gotoxy(63,9);printf("Expresion de asignacion");
	Sleep(300);
	
	gotoxy(65,10);printf("/");
	Sleep(50);
	gotoxy(64,11);printf("/");
	Sleep(50);
	
	
	gotoxy(82,10);printf("%c",92);
	Sleep(50);
	gotoxy(83,11);printf("%c",92);
	Sleep(50);

	
	gotoxy(63,12);printf("/");
	Sleep(50);
	gotoxy(62,13);printf("/");
	Sleep(50);
	
	gotoxy(57,14);printf("Expresion de");
	gotoxy(58,15);printf("subindice");
	Sleep(50);
	
	gotoxy(62,16);printf("%c",179);
	Sleep(50);
	gotoxy(62,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(62,18);printf("%c",179);
	Sleep(50);
	gotoxy(62,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(56,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(62,21);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(84,12);printf("%c",92);
	Sleep(50);
	gotoxy(85,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(81,14);printf("Expresion");
	gotoxy(81,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(85,16);printf("%c",179);
	Sleep(50);
	gotoxy(85,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(85,18);printf("%c",179);
	Sleep(50);
	gotoxy(85,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(82,20);printf("Numero");
	Sleep(50);
	
	gotoxy(85,21);printf("%c",cadena[6]);
	Sleep(50);
	
			break;
		}
		
		
	
		case 3:{
			
			
	gotoxy(51,5);printf("Expresion ");
	Sleep(50);
	
	gotoxy(50,5);printf("-");
	Sleep(50);
	gotoxy(49,5);printf("-");
	Sleep(50);
	gotoxy(48,5);printf("-");
	Sleep(50);
	gotoxy(17,5);printf("---------------------------------");
	Sleep(50);
	
	
	gotoxy(61,5);printf("------------------------------");
	Sleep(50);
	
	gotoxy(17,6);printf("%c",179);
	Sleep(50);
	gotoxy(17,7);printf("%c",179);
	Sleep(50);
	gotoxy(17,8);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(55,6);printf("%c",179);
	Sleep(50);
	gotoxy(55,7);printf("%c",179);
	Sleep(50);
	gotoxy(55,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(6,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(8,10);printf("/");
	Sleep(50);
	gotoxy(7,11);printf("/");
	Sleep(50);
		
	gotoxy(26,10);printf("%c",92);
	Sleep(50);
	gotoxy(27,11);printf("%c",92);
	Sleep(50);
	
	
	gotoxy(6,12);printf("%c",179);
	Sleep(50);
	gotoxy(6,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(28,12);printf("%c",179);
	Sleep(50);
	gotoxy(28,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(1,14);printf("Expresion de");
	gotoxy(3,15);printf("subindice");
	Sleep(50);
	
	gotoxy(6,16);printf("%c",179);
	Sleep(50);
	gotoxy(6,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(6,18);printf("%c",179);
	Sleep(50);
	gotoxy(6,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(0,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(6,21);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(23,14);printf("Expresion");
	gotoxy(24,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(28,16);printf("%c",179);
	Sleep(50);
	gotoxy(28,17);printf("%c",179);
	Sleep(50);

	gotoxy(28,18);printf("%c",179);
	Sleep(50);
	gotoxy(28,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(26,20);printf("Numero");
	Sleep(50);
	
	gotoxy(27,21);printf("%c",cadena[2]);
	Sleep(50);
	
	gotoxy(43,9);printf("Expresion de asignacion");
	Sleep(300);
	
	gotoxy(45,10);printf("/");
	Sleep(50);
	gotoxy(44,11);printf("/");
	Sleep(50);
	
	
	gotoxy(62,10);printf("%c",92);
	Sleep(50);
	gotoxy(63,11);printf("%c",92);
	Sleep(50);

	
	gotoxy(43,12);printf("/");
	Sleep(50);
	gotoxy(42,13);printf("/");
	Sleep(50);
	
	gotoxy(37,14);printf("Expresion de");
	gotoxy(38,15);printf("subindice");
	Sleep(50);
	
	gotoxy(42,16);printf("%c",179);
	Sleep(50);
	gotoxy(42,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(42,18);printf("%c",179);
	Sleep(50);
	gotoxy(42,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(42,21);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(64,12);printf("%c",92);
	Sleep(50);
	gotoxy(65,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(61,14);printf("Expresion");
	gotoxy(61,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(65,16);printf("%c",179);
	Sleep(50);
	gotoxy(65,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(65,18);printf("%c",179);
	Sleep(50);
	gotoxy(65,19);printf("%c",179);
	Sleep(50);
	
	gotoxy(62,20);printf("Numero");
	Sleep(50);
	
	gotoxy(65,21);printf("%c",cadena[6]);
	Sleep(50);
		
	gotoxy(90,6);printf("%c",179);
	Sleep(50);
	gotoxy(90,7);printf("%c",179);
	Sleep(50);
	gotoxy(90,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(79,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(82,10);printf("/");
	Sleep(50);
	gotoxy(81,11);printf("/");
	Sleep(50);
	
	gotoxy(100,10);printf("%c",92);
	Sleep(50);
	gotoxy(101,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(80,12);printf("/");
	Sleep(50);
	gotoxy(79,13);printf("/");
	Sleep(50);

	gotoxy(73,14);printf("Expresion de");
	gotoxy(75,15);printf("subindice");
	Sleep(50);
	
	gotoxy(79,16);printf("%c",179);
	Sleep(50);
	gotoxy(79,17);printf("%c",179);
	Sleep(50);
	
	gotoxy(79,18);printf("%c",179);
	Sleep(50);
	gotoxy(79,19);
	printf("%c",179);
	Sleep(50);
	
	gotoxy(72,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(79,21);printf("%c",cadena[8]);
	Sleep(50);
	
	gotoxy(102,12);printf("%c",92);
	Sleep(50);
	gotoxy(103,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(100,14);printf("Expresion");
	gotoxy(101,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(100,16);printf("/");
	Sleep(50);
	gotoxy(99,17);printf("/");
	Sleep(50);
	
	gotoxy(109,16);printf("%c",92);
	Sleep(50);
	gotoxy(110,17);printf("%c",92);
	Sleep(50);
	
	gotoxy(98,18);printf("/");
	Sleep(50);
	gotoxy(97,19);printf("/");
	Sleep(50);
	
	
	gotoxy(89,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(94,21);printf("%c",cadena[10]);
	Sleep(50);
	
	gotoxy(112,19);printf("%c",92);
	gotoxy(111,18);printf("%c",92);
	Sleep(50);
	Sleep(50);
	
	gotoxy(106,20);printf("Identificador");
	Sleep(50);
	
	gotoxy(113,21);printf("%c",cadena[12]);
	Sleep(50);
	

	
	
}

	
}

	Analisis_Semantico(cadena,xcont,ycont,sentencia);
}


void Analisis_Semantico(char cadena[num], int xcont, int ycont, int sentencia){
	
		printf("\n\n\n\t\t\t\t\t");
	
		system("pause");
	system("cls");

	printf("\n\n\n\n\t\t\t\t\tANALIZADOR SEMANTICO\n\n");
	printf("\t\tDetermina su comportamiento durante el tiempo de ejecucion, pero la mayoria de los\n\t\tlenguajes de programacion tienencaracteristicas que se pueden determinar");
	printf("antes de la\n\t\tejecucion e incluso no se pueden expresar de manera adecuada como sintaxis y\n\t\tanalizarsemediante el analizador sintactico. ");
	
	system("pause");
	system("cls");
	
	switch(sentencia){
		
		
		
		
		
		
		
		
		
		
		case 1:{
			
							
	gotoxy(48,5);printf("Expresion ");
	Sleep(50);
	
	
	gotoxy(52,6);printf("%c",179);
	Sleep(50);
	gotoxy(52,7);printf("%c",179);
	Sleep(50);
	gotoxy(52,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(41,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(43,10);printf("/");
	Sleep(50);
	gotoxy(42,11);printf("/");
	Sleep(50);
		
	gotoxy(61,10);printf("%c",92);
	Sleep(50);
	gotoxy(62,11);printf("%c",92);
	Sleep(50);
	
	
	gotoxy(41,12);printf("%c",179);
	Sleep(50);
	gotoxy(41,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(63,12);printf("%c",179);
	Sleep(50);
	gotoxy(63,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,14);printf("Expresion de");
	gotoxy(38,15);printf("subindice");
	gotoxy(36,16);printf("entero");
	
	Sleep(50);
	
	gotoxy(41,17);printf("%c",179);
	Sleep(50);
	gotoxy(41,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(41,19);printf("%c",179);
	Sleep(50);
	gotoxy(41,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(35,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(41,22);printf("%c",cadena[0]);
	Sleep(50);
	gotoxy(41,23);printf("entero");
	Sleep(50);
	
	gotoxy(58,14);printf("Expresion");
	gotoxy(59,15);printf("aditivo");
	gotoxy(59,16);printf("entero");
	
	Sleep(50);
	
	gotoxy(63,17);printf("%c",179);
	Sleep(50);
	gotoxy(63,18);printf("%c",179);
	Sleep(50);

	gotoxy(63,19);printf("%c",179);
	Sleep(50);
	gotoxy(63,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(61,21);printf("Numero");
	Sleep(50);
	
	gotoxy(62,22);printf("%c",cadena[2]);
	Sleep(50);
	gotoxy(60,23);printf("entero");
	Sleep(50);

			
	
			break;
		}
		
		
		
		
		
		
		
		
		
		case 2:{
			
			
			
			
			
	gotoxy(52,5);printf("Expresion ");
	Sleep(50);
	
		gotoxy(51,6);printf("/");
	Sleep(50);
	gotoxy(50,7);printf("/");
	Sleep(50);
	gotoxy(49,8);printf("/");
	Sleep(50);
	
	gotoxy(61,6);printf("%c",92);
	Sleep(50);
	gotoxy(62,7);printf("%c",92);
	Sleep(50);
	gotoxy(63,8);printf("%c",92);
	Sleep(50);
	



	
	gotoxy(26,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(28,10);printf("/");
	Sleep(50);
	gotoxy(27,11);printf("/");
	Sleep(50);
		
	gotoxy(46,10);printf("%c",92);
	Sleep(50);
	gotoxy(47,11);printf("%c",92);
	Sleep(50);
	
	
	gotoxy(26,12);printf("%c",179);
	Sleep(50);
	gotoxy(26,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(48,12);printf("%c",179);
	Sleep(50);
	gotoxy(48,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(21,14);printf("Expresion de");
	gotoxy(23,15);printf("subindice");
	gotoxy(24,16);printf("entero");
	
	Sleep(50);
	
	gotoxy(26,17);printf("%c",179);
	Sleep(50);
	gotoxy(26,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(26,19);printf("%c",179);
	Sleep(50);
	gotoxy(26,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(20,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(26,22);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(24,23);printf("entero");
	Sleep(50);
	
	gotoxy(43,14);printf("Expresion");
	gotoxy(44,15);printf("aditivo");
	Sleep(50);
	gotoxy(44,16);printf("entero");
	Sleep(50);
	
	gotoxy(48,17);printf("%c",179);
	Sleep(50);
	gotoxy(48,18);printf("%c",179);
	Sleep(50);

	gotoxy(48,19);printf("%c",179);
	Sleep(50);
	gotoxy(48,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(46,21);printf("Numero");
	Sleep(50);
	
	gotoxy(48,22);printf("%c",cadena[2]);
	Sleep(50);
	
	gotoxy(47,23);printf("entero");
	Sleep(50);
	
	gotoxy(63,9);printf("Expresion de asignacion");
	Sleep(300);
	
	gotoxy(65,10);printf("/");
	Sleep(50);
	gotoxy(64,11);printf("/");
	Sleep(50);
	
	
	gotoxy(82,10);printf("%c",92);
	Sleep(50);
	gotoxy(83,11);printf("%c",92);
	Sleep(50);

	
	gotoxy(63,12);printf("/");
	Sleep(50);
	gotoxy(62,13);printf("/");
	Sleep(50);
	
	gotoxy(57,14);printf("Expresion de");
	gotoxy(58,15);printf("subindice");
	Sleep(50);
	gotoxy(60,16);printf("entero");
	Sleep(50);
	
	gotoxy(62,17);printf("%c",179);
	Sleep(50);
	gotoxy(62,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(62,19);printf("%c",179);
	Sleep(50);
	gotoxy(62,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(56,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(62,22);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(60,23);printf("entero");
	Sleep(50);
	
	gotoxy(84,12);printf("%c",92);
	Sleep(50);
	gotoxy(85,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(81,14);printf("Expresion");
	gotoxy(81,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(81,16);printf("entero");
	Sleep(50);
	
	
	gotoxy(85,17);printf("%c",179);
	Sleep(50);
	gotoxy(85,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(85,19);printf("%c",179);
	Sleep(50);
	gotoxy(85,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(82,21);printf("Numero");
	Sleep(50);
	
	gotoxy(85,22);printf("%c",cadena[6]);
	Sleep(50);
	
	gotoxy(83,23);printf("entero");
	Sleep(50);
			
			break;
		}
		
		
		
		case 3:{
			
			gotoxy(51,5);printf("Expresion ");
	Sleep(50);
	
	gotoxy(50,5);printf("-");
	Sleep(50);
	gotoxy(49,5);printf("-");
	Sleep(50);
	gotoxy(48,5);printf("-");
	Sleep(50);
	gotoxy(17,5);printf("---------------------------------");
	Sleep(50);
	
	
	gotoxy(61,5);printf("------------------------------");
	Sleep(50);
	
	gotoxy(17,6);printf("%c",179);
	Sleep(50);
	gotoxy(17,7);printf("%c",179);
	Sleep(50);
	gotoxy(17,8);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(55,6);printf("%c",179);
	Sleep(50);
	gotoxy(55,7);printf("%c",179);
	Sleep(50);
	gotoxy(55,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(6,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(8,10);printf("/");
	Sleep(50);
	gotoxy(7,11);printf("/");
	Sleep(50);
		
	gotoxy(26,10);printf("%c",92);
	Sleep(50);
	gotoxy(27,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(6,12);printf("%c",179);
	Sleep(50);
	gotoxy(6,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(28,12);printf("%c",179);
	Sleep(50);
	gotoxy(28,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(1,14);printf("Expresion de");
	gotoxy(3,15);printf("subindice");
	Sleep(50);
	gotoxy(3,16);printf("Entero");
	Sleep(50);
	
	gotoxy(6,17);printf("%c",179);
	Sleep(50);
	gotoxy(6,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(6,19);printf("%c",179);
	Sleep(50);
	gotoxy(6,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(0,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(6,22);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(4,23);printf("Entero");
	Sleep(50);
	
	gotoxy(23,14);printf("Expresion");
	gotoxy(24,15);printf("aditivo");
	Sleep(50);
	gotoxy(24,16);printf("Entero");
	Sleep(50);
	
	gotoxy(28,17);printf("%c",179);
	Sleep(50);
	gotoxy(28,18);printf("%c",179);
	Sleep(50);

	gotoxy(28,19);printf("%c",179);
	Sleep(50);
	gotoxy(28,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(26,21);printf("Numero");
	Sleep(50);
	
	gotoxy(28,22);printf("%c",cadena[2]);
	Sleep(50);
	
	gotoxy(26,23);printf("Entero");
	Sleep(50);
	
	gotoxy(43,9);printf("Expresion de asignacion");
	Sleep(300);

	gotoxy(45,10);printf("/");
	Sleep(50);
	gotoxy(44,11);printf("/");
	Sleep(50);
	
	
	gotoxy(62,10);printf("%c",92);
	Sleep(50);
	gotoxy(63,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(43,12);printf("/");
	Sleep(50);
	gotoxy(42,13);printf("/");
	Sleep(50);
	
	gotoxy(37,14);printf("Expresion de");
	gotoxy(38,15);printf("subindice");
	Sleep(50);
	gotoxy(38,16);printf("Entero");
	Sleep(50);
	
	gotoxy(42,17);printf("%c",179);
	Sleep(50);
	gotoxy(42,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(42,19);printf("%c",179);
	Sleep(50);
	gotoxy(42,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(42,22);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(40,23);printf("Entero");
	Sleep(50);
	
	gotoxy(64,12);printf("%c",92);
	Sleep(50);
	gotoxy(65,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(61,14);printf("Expresion");
	gotoxy(61,15);printf("aditivo");
	Sleep(50);
	gotoxy(61,16);printf("Entero");
	Sleep(50);
	
	gotoxy(65,17);printf("%c",179);
	Sleep(50);
	gotoxy(65,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(65,19);printf("%c",179);
	Sleep(50);
	gotoxy(65,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(62,21);printf("Numero");
	Sleep(50);
	
	gotoxy(65,22);printf("%c",cadena[6]);
	Sleep(50);
	
	gotoxy(63,23);printf("Entero");
	Sleep(50);
		
	gotoxy(90,6);printf("%c",179);
	Sleep(50);
	gotoxy(90,7);printf("%c",179);
	Sleep(50);
	gotoxy(90,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(79,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(82,10);printf("/");
	Sleep(50);
	gotoxy(81,11);printf("/");
	Sleep(50);
	
	gotoxy(100,10);printf("%c",92);
	Sleep(50);
	gotoxy(101,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(80,12);printf("/");
	Sleep(50);
	gotoxy(79,13);printf("/");
	Sleep(50);

	gotoxy(73,14);printf("Expresion de");
	gotoxy(75,15);printf("subindice");
	Sleep(50);
	
	gotoxy(76,16);printf("Entero");
	Sleep(50);
	
	gotoxy(79,17);printf("%c",179);
	Sleep(50);
	gotoxy(79,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(79,19);printf("%c",179);
	Sleep(50);
	gotoxy(79,20);
	printf("%c",179);
	Sleep(50);
	
	gotoxy(72,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(79,22);printf("%c",cadena[8]);
	Sleep(50);
	
	gotoxy(77,23);printf("Entero");
	Sleep(50);
	
	gotoxy(102,12);printf("%c",92);
	Sleep(50);
	gotoxy(103,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(100,14);printf("Expresion");
	gotoxy(101,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(102,16);printf("Entero");
	Sleep(50);
	
	gotoxy(100,17);printf("/");
	Sleep(50);
	gotoxy(99,18);printf("/");
	Sleep(50);
	
	gotoxy(109,17);printf("%c",92);
	Sleep(50);
	gotoxy(110,18);printf("%c",92);
	Sleep(50);
	
	gotoxy(98,19);printf("/");
	Sleep(50);
	gotoxy(97,20);printf("/");
	Sleep(50);
	
	
	gotoxy(89,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(94,22);printf("%c",cadena[10]);
	Sleep(50);
	
	gotoxy(92,23);printf("Entero");
	Sleep(50);
	
	gotoxy(111,19);printf("%c",92);
	Sleep(50);
	gotoxy(112,20);printf("%c",92);
	Sleep(50);
	
	gotoxy(106,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(114,22);printf("%c",cadena[12]);
	Sleep(50);
	
	gotoxy(112,23);printf("Entero");
	Sleep(50);
			

			
			break;
		}
	}
	
	
	
	
	
	
	
	printf("\n\n\n\n \t\t\t");
	
		system("pause");
	system("cls");
	
		Optimizador_codigo_fuente(cadena,xcont,ycont,sentencia);
		
}




void Optimizador_codigo_fuente(char cadena[num], int xcont, int ycont, int sentencia){
	
	int contotal;
	
	printf("\n\n\n\n\t\t\t\tOPTIMIZADOR DE CODIGO FUENTE\n\n\n");
	printf("\t\tEl punto mas anticipado en el que la mayoria de las etapas de optimizacion se pueden\n\t\t");
	printf("realizar es precisamente despues del analisis semantico, y puede haber posibilidades\n\t\t");
	printf("para el mejoramiento del codigo que dependeran solo del codigo fuente.");
	
	contotal=xcont+ycont;
	
	printf("\n\n\n\t\t\t\t");
	system("pause");
	
	system("cls");
	
	
		switch(sentencia){
		
		case 1:{
			
			gotoxy(48,5);printf("Expresion ");
	Sleep(50);
	
	
	gotoxy(52,6);printf("%c",179);
	Sleep(50);
	gotoxy(52,7);printf("%c",179);
	Sleep(50);
	gotoxy(52,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(41,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(43,10);printf("/");
	Sleep(50);
	gotoxy(42,11);printf("/");
	Sleep(50);
		
	gotoxy(61,10);printf("%c",92);
	Sleep(50);
	gotoxy(62,11);printf("%c",92);
	Sleep(50);
	
	
	gotoxy(41,12);printf("%c",179);
	Sleep(50);
	gotoxy(41,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(63,12);printf("%c",179);
	Sleep(50);
	gotoxy(63,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,14);printf("Expresion de");
	gotoxy(38,15);printf("subindice");
	gotoxy(36,16);printf("entero");
	
	Sleep(50);
	
	gotoxy(41,17);printf("%c",179);
	Sleep(50);
	gotoxy(41,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(41,19);printf("%c",179);
	Sleep(50);
	gotoxy(41,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(35,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(41,22);printf("%c",cadena[0]);
	Sleep(50);
	gotoxy(41,23);printf("entero");
	Sleep(50);
	
	gotoxy(58,14);printf("Expresion");
	gotoxy(59,15);printf("aditivo");
	gotoxy(59,16);printf("entero");
	
	Sleep(50);
	
	gotoxy(63,17);printf("%c",179);
	Sleep(50);
	gotoxy(63,18);printf("%c",179);
	Sleep(50);

	gotoxy(63,19);printf("%c",179);
	Sleep(50);
	gotoxy(63,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(61,21);printf("Numero");
	Sleep(50);
	
	gotoxy(62,22);printf("%c",cadena[2]);
	Sleep(50);
	gotoxy(60,23);printf("entero");
	Sleep(50);

			
			
			break;
		}
		
		
		
		case 2:{
			
					
			
			
			
	gotoxy(52,5);printf("Expresion ");
	Sleep(50);
	
		gotoxy(51,6);printf("/");
	Sleep(50);
	gotoxy(50,7);printf("/");
	Sleep(50);
	gotoxy(49,8);printf("/");
	Sleep(50);
	
	gotoxy(61,6);printf("%c",92);
	Sleep(50);
	gotoxy(62,7);printf("%c",92);
	Sleep(50);
	gotoxy(63,8);printf("%c",92);
	Sleep(50);
	



	
	gotoxy(26,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(28,10);printf("/");
	Sleep(50);
	gotoxy(27,11);printf("/");
	Sleep(50);
		
	gotoxy(46,10);printf("%c",92);
	Sleep(50);
	gotoxy(47,11);printf("%c",92);
	Sleep(50);
	
	
	gotoxy(26,12);printf("%c",179);
	Sleep(50);
	gotoxy(26,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(48,12);printf("%c",179);
	Sleep(50);
	gotoxy(48,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(21,14);printf("Expresion de");
	gotoxy(23,15);printf("subindice");
	gotoxy(24,16);printf("entero");
	
	Sleep(50);
	
	gotoxy(26,17);printf("%c",179);
	Sleep(50);
	gotoxy(26,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(26,19);printf("%c",179);
	Sleep(50);
	gotoxy(26,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(20,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(26,22);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(24,23);printf("entero");
	Sleep(50);
	
	gotoxy(43,14);printf("Expresion");
	gotoxy(44,15);printf("aditivo");
	Sleep(50);
	gotoxy(44,16);printf("entero");
	Sleep(50);
	
	gotoxy(48,17);printf("%c",179);
	Sleep(50);
	gotoxy(48,18);printf("%c",179);
	Sleep(50);

	gotoxy(48,19);printf("%c",179);
	Sleep(50);
	gotoxy(48,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(46,21);printf("Numero");
	Sleep(50);
	
	gotoxy(48,22);printf("%c",cadena[2]);
	Sleep(50);
	
	gotoxy(47,23);printf("entero");
	Sleep(50);
	
	gotoxy(63,9);printf("Expresion de asignacion");
	Sleep(300);
	
	gotoxy(65,10);printf("/");
	Sleep(50);
	gotoxy(64,11);printf("/");
	Sleep(50);
	
	
	gotoxy(82,10);printf("%c",92);
	Sleep(50);
	gotoxy(83,11);printf("%c",92);
	Sleep(50);

	
	gotoxy(63,12);printf("/");
	Sleep(50);
	gotoxy(62,13);printf("/");
	Sleep(50);
	
	gotoxy(57,14);printf("Expresion de");
	gotoxy(58,15);printf("subindice");
	Sleep(50);
	gotoxy(60,16);printf("entero");
	Sleep(50);
	
	gotoxy(62,17);printf("%c",179);
	Sleep(50);
	gotoxy(62,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(62,19);printf("%c",179);
	Sleep(50);
	gotoxy(62,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(56,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(62,22);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(60,23);printf("entero");
	Sleep(50);
	
	gotoxy(84,12);printf("%c",92);
	Sleep(50);
	gotoxy(85,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(81,14);printf("Expresion");
	gotoxy(81,15);printf("aditivo");
	Sleep(50);
	
	gotoxy(81,16);printf("entero");
	Sleep(50);
	
	
	gotoxy(85,17);printf("%c",179);
	Sleep(50);
	gotoxy(85,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(85,19);printf("%c",179);
	Sleep(50);
	gotoxy(85,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(82,21);printf("Numero");
	Sleep(50);
	
	gotoxy(85,22);printf("%c",cadena[6]);
	Sleep(50);
	
	gotoxy(83,23);printf("entero");
	Sleep(50);
			
			
			break;
		}
		
		
		case 3:{
			
				gotoxy(51,5);printf("Expresion ");
	Sleep(50);
	
	gotoxy(50,5);printf("-");
	Sleep(50);
	gotoxy(49,5);printf("-");
	Sleep(50);
	gotoxy(48,5);printf("-");
	Sleep(50);
	gotoxy(17,5);printf("---------------------------------");
	Sleep(50);
	
	
	gotoxy(61,5);printf("------------------------------");
	Sleep(50);
	
	gotoxy(17,6);printf("%c",179);
	Sleep(50);
	gotoxy(17,7);printf("%c",179);
	Sleep(50);
	gotoxy(17,8);printf("%c",179);
	Sleep(50);
	
	
	gotoxy(55,6);printf("%c",179);
	Sleep(50);
	gotoxy(55,7);printf("%c",179);
	Sleep(50);
	gotoxy(55,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(6,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(8,10);printf("/");
	Sleep(50);
	gotoxy(7,11);printf("/");
	Sleep(50);
		
	gotoxy(26,10);printf("%c",92);
	Sleep(50);
	gotoxy(27,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(6,12);printf("%c",179);
	Sleep(50);
	gotoxy(6,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(28,12);printf("%c",179);
	Sleep(50);
	gotoxy(28,13);printf("%c",179);
	Sleep(50);
	
	gotoxy(1,14);printf("Expresion de");
	gotoxy(3,15);printf("subindice");
	Sleep(50);
	gotoxy(3,16);printf("Entero");
	Sleep(50);
	
	gotoxy(6,17);printf("%c",179);
	Sleep(50);
	gotoxy(6,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(6,19);printf("%c",179);
	Sleep(50);
	gotoxy(6,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(0,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(6,22);printf("%c",cadena[0]);
	Sleep(50);
	
	gotoxy(4,23);printf("Entero");
	Sleep(50);
	
	gotoxy(23,14);printf("Expresion");
	gotoxy(24,15);printf("aditivo");
	Sleep(50);
	gotoxy(24,16);printf("Entero");
	Sleep(50);
	
	gotoxy(28,17);printf("%c",179);
	Sleep(50);
	gotoxy(28,18);printf("%c",179);
	Sleep(50);

	gotoxy(28,19);printf("%c",179);
	Sleep(50);
	gotoxy(28,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(26,21);printf("Numero");
	Sleep(50);
	
	gotoxy(27,22);printf("%c",cadena[2]);
	Sleep(50);
	
	gotoxy(25,23);printf("Entero");
	Sleep(50);
	
	gotoxy(43,9);printf("Expresion de asignacion");
	Sleep(300);

	gotoxy(45,10);printf("/");
	Sleep(50);
	gotoxy(44,11);printf("/");
	Sleep(50);
	
	
	gotoxy(62,10);printf("%c",92);
	Sleep(50);
	gotoxy(63,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(43,12);printf("/");
	Sleep(50);
	gotoxy(42,13);printf("/");
	Sleep(50);
	
	gotoxy(37,14);printf("Expresion de");
	gotoxy(38,15);printf("subindice");
	Sleep(50);
	gotoxy(39,16);printf("Entero");
	Sleep(50);
	
	gotoxy(42,17);printf("%c",179);
	Sleep(50);
	gotoxy(42,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(42,19);printf("%c",179);
	Sleep(50);
	gotoxy(42,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(36,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(42,22);printf("%c",cadena[4]);
	Sleep(50);
	
	gotoxy(40,23);printf("Entero");
	Sleep(50);
	
	gotoxy(64,12);printf("%c",92);
	Sleep(50);
	gotoxy(65,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(61,14);printf("Expresion");
	gotoxy(61,15);printf("aditivo");
	Sleep(50);
	gotoxy(62,16);printf("Entero");
	Sleep(50);
	
	gotoxy(65,17);printf("%c",179);
	Sleep(50);
	gotoxy(65,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(65,19);printf("%c",179);
	Sleep(50);
	gotoxy(65,20);printf("%c",179);
	Sleep(50);
	
	gotoxy(62,21);printf("Numero");
	Sleep(50);
	
	gotoxy(65,22);printf("%c",cadena[6]);
	Sleep(50);
	
	gotoxy(63,23);printf("Entero");
	Sleep(50);
		
	gotoxy(90,6);printf("%c",179);
	Sleep(50);
	gotoxy(90,7);printf("%c",179);
	Sleep(50);
	gotoxy(90,8);printf("%c",179);
	Sleep(50);
	
	gotoxy(79,9);printf("Expresion de asignacion");
	Sleep(50);
	
	gotoxy(82,10);printf("/");
	Sleep(50);
	gotoxy(81,11);printf("/");
	Sleep(50);
	
	gotoxy(100,10);printf("%c",92);
	Sleep(50);
	gotoxy(101,11);printf("%c",92);
	Sleep(50);
	
	gotoxy(80,12);printf("/");
	Sleep(50);
	gotoxy(79,13);printf("/");
	Sleep(50);

	gotoxy(73,14);printf("Expresion de");
	gotoxy(75,15);printf("subindice");
	Sleep(50);
	
	gotoxy(76,16);printf("Entero");
	Sleep(50);
	
	gotoxy(79,17);printf("%c",179);
	Sleep(50);
	gotoxy(79,18);printf("%c",179);
	Sleep(50);
	
	gotoxy(79,19);printf("%c",179);
	Sleep(50);
	gotoxy(79,20);
	printf("%c",179);
	Sleep(50);
	
	gotoxy(72,21);printf("Identificador");
	Sleep(50);
	
	gotoxy(79,22);printf("%c",cadena[8]);
	Sleep(50);
	
	gotoxy(77,23);printf("Entero");
	Sleep(50);
	
	gotoxy(102,12);printf("%c",92);
	Sleep(50);
	gotoxy(103,13);printf("%c",92);
	Sleep(50);
	
	gotoxy(102,14);printf("Numero");
	Sleep(50);
	
	gotoxy(104,15);printf("%d",contotal); // Suma de x y y
	Sleep(50);
	
	gotoxy(102,16);printf("Entero");
	Sleep(50);
	
			
			break;
		}
		
	}
	
	

	printf("\n\n\n\n\n\n\n\n\n");
	
	system("pause");
	system("cls");
	Generador_codigo(cadena,xcont,ycont,sentencia);
	
		
	
}





void Generador_codigo(char cadena[num], int xcont, int ycont, int sentencia){
	
	printf("\n\n\t\t\t\t\tGENERADOR DE CODIGO\n\n\n");
	
	printf("\n\t\tToma el codigo intermedio o R1 Y genera el codigo para la maquina objeto\n\n");

	printf("\t\tEn este medio de se escribe el codigo objeto en la forma de lenguaje ensamblador\n");
	printf("\t\tpara facilitar su comprension, aunque la mayoria de los compiladores generan el\n");
	printf("\t\tcodigo objeto de manera directa\n\n");
	
	system("pause");
	system("cls");
	
	switch(sentencia){
		
		case 1:{
			
				printf("\n\n\t\t Codigo ensamblador resultante:\n\n");
	
	printf("\t\t\t\t\tmovl $%d, -4(%rbp)\n",xcont);
			break;
		}
		
		case 2:{
			
				printf("\n\n\t\t Codigo ensamblador resultante:\n\n");
	
	printf("\t\t\t\t\tmovl $%d -4(%rbp)\n",xcont);
	printf("\t\t\t\t\tmovl $%d, -8(%rbp)\n",ycont);;
			break;
		}
		
		case 3:{
			
				printf("\n\n\t\t Codigo ensamblador resultante:\n\n");
	
	printf("\t\t\t\t\tpush rbp\n");
	printf("\t\t\t\t\tmov rbp,rsp\n");
	printf("\t\t\t\t\tmov DWORD PTR [rbp-4], %d\n",xcont);
	printf("\t\t\t\t\tmov DWORD PTR [rbp-8], %d\n",ycont);
	printf("\t\t\t\t\tmov edx, DWORD PTR [rbp-8]\n");
	printf("\t\t\t\t\tmov eax, DWORD PTR [rbp-8]\n");
	printf("\t\t\t\t\tadd eax, edx\n");
	printf("\t\t\t\t\tmov DWORD PTR [rbp-8], eax\n");
	printf("\t\t\t\t\tmov eax, 0 \n");
	printf("\t\t\t\t\tpop rbp \n");
	printf("\t\t\t\t\tret");
			
			break;
		}
	}
	
	
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");

	
	system("pause");
	system("cls");
	
	Optimizador_de_codigo_objeto(cadena, xcont, ycont, sentencia);
}


void Optimizador_de_codigo_objeto(char cadena[num], int xcont, int ycont, int sentencia){
	
	printf("\n\n\t\t\t\t\tOPTIMIZADOR DE CODIGO OBJETO\n\n\n");
	
	printf("\n\t\tEn esta fase el compilador intenta mejorar el codigo objeto generado por el generador\n");

	printf("\t\tde codigo, dichas mejoras incluyen la seleccion de modos de direccionamiento para mejorar\n");
	printf("\t\tel rendimiento, reemplazando las instrucciones lentas por otras rapidas, y eliminando las\n");
	printf("\t\toperaciones redundantes o innecesarias.\n\n");
	
	system("pause");
	system("cls");
	
		switch(sentencia){
		
		case 1:{
			
				printf("\n\n\t\t Codigo ensamblador resultante:\n\n");
	
	printf("\t\t\t\t\tmovl $%d, -4(%rbp)\n",xcont);
			break;
		}
		
		case 2:{
			
				printf("\n\n\t\t Codigo ensamblador resultante:\n\n");
	
	printf("\t\t\t\t\tmovl $%d -4(%rbp)\n",xcont);
	printf("\t\t\t\t\tmovl $%d, -8(%rbp)\n",ycont);;
			break;
		}
		
		case 3:{
			
				printf("\n\n\t\t Codigo ensamblador resultante:\n\n");
	
	printf("\t\t\t\t\tpush rbp\n");
	printf("\t\t\t\t\tmov rbp,rsp\n");
	printf("\t\t\t\t\tmov DWORD PTR [rbp-4], %d\n",xcont);
	printf("\t\t\t\t\tmov DWORD PTR [rbp-8], %d\n",ycont);
	printf("\t\t\t\t\tmov edx, DWORD PTR [rbp-8]\n");
	printf("\t\t\t\t\tmov eax, DWORD PTR [rbp-8]\n");
	printf("\t\t\t\t\tadd eax, edx\n");
	printf("\t\t\t\t\tmov DWORD PTR [rbp-8], eax\n");
	printf("\t\t\t\t\tmov eax, 0 \n");
	printf("\t\t\t\t\tpop rbp \n");
	printf("\t\t\t\t\tret");
			
			break;
		}
	}
	
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");

	

}


