#include <stdio.h>
#include <conio.h>

void main(){
	char Head[] = "CALCULADORA DE AREAS$";
	char figura1[] = "1. AREA DE UN RECTANGULO$";
	char figura2[] = "2. AREA DE UN CIRCULO$";
	char figura3[] = "3. AREA DE UN TRIANGULO$";
	char opcion[] = "ELEGIR UNA OPCION:$";
	char base[] = "Base$";
	char altura[] = "Altura$";
	char radio[] = "Radio$";
	char area[] = "Area$";
	float bas;
	float alt;
	float rad;
	float a;
	
	int seleccion = 0;	
	
	while (seleccion != 4) {
		asm { 
			// Encabezado
			MOV AX, 0600H
			MOV BH, 01H
			MOV CX, 0000H
			MOV DX, 184FH
			INT 10H
		
			MOV AX, 0600H
			MOV BH, 31H
			MOV CX, 060BH
			MOV DX, 1144H
			INT 10H
		
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 07
			MOV DL, 33
			INT 10H
		
			MOV AH, 09H
			LEA DX, Head
			INT 21H
			
			// Opcion rectangulo
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 22
			MOV DL, 00
			INT 10H
			
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 09
			MOV DL, 20
			INT 10H
		
			MOV AH, 09H
			LEA DX, figura1
			INT 21H
			
			// Opcion circulo
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 11
			MOV DL, 20
			INT 10H
		
			MOV AH, 09H
			LEA DX, figura2
			INT 21H
			
			// Opcion triangulo
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 13
			MOV DL, 20
			INT 10H
		
			MOV AH, 09H
			LEA DX, figura3
			INT 21H
			
			// Elegir opción
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 15
			MOV DL, 20
			INT 10H
		
			MOV AH, 09H
			LEA DX, opcion
			INT 21H
		}
		
		// Leer opcion
		asm {
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 40
			MOV DL, 00
			INT 10H
	
			MOV AH, 02H
			MOV BH, 00
			MOV DH, 15
			MOV DL, 40
			INT 10H
	
			MOV AX, 0600H
			MOV BH, 50H
			MOV CX, 0F21H
			MOV DX, 0F21H
			INT 10H
		}
		scanf ("%d", &seleccion);
		system ("cls");
		
		switch (seleccion) {
			case 1: 
				// Etiquetas
				asm {
				// Encabezado rectangulo
					MOV AX, 0600H
					MOV BH, 01H
					MOV CX, 0000H
					MOV DX, 184FH
					INT 10H
				
					MOV AX, 0600H
					MOV BH, 31H
					MOV CX, 060BH
					MOV DX, 1144H
					INT 10H
				
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 07
					MOV DL, 33
					INT 10H
						
					MOV AH, 09H
					LEA DX, figura1
					INT 21H
		
					// Etiqueta base
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 09
					MOV DL, 20
					INT 10H
			
					MOV AH, 09H
					LEA DX, base
					INT 21H
					
					// Etiqueta altura
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 11
					MOV DL, 20
					INT 10H
					
					MOV AH, 09H
					LEA DX, altura
					INT 21H
			
					// Etiqueta area
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 13
					MOV DL, 20
					INT 10H
			
					MOV AH, 09H
					LEA DX, area
					INT 21H
				}
				// Leer entrada de la base
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
					
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 09
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 0D21H
					MOV DX, 0D23H
					INT 10H
				}
				scanf ("%f", &bas);
				// Leer entrada de la altura
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
			
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 11
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 0F21H
					MOV DX, 0F21H
					INT 10H
				}
				scanf ("%f", &alt);
				// Calcular area
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
			
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 13
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 1121H
					MOV DX, 1124H
					INT 10H
				}
				a = (bas*alt);
				printf ("%f\n\n\n\n\n\n\n", a);
				system ("PAUSE");
				break;
			case 2:
				asm {
				// Encabezado circulo
					MOV AX, 0600H
					MOV BH, 01H
					MOV CX, 0000H
					MOV DX, 184FH
					INT 10H
				
					MOV AX, 0600H
					MOV BH, 31H
					MOV CX, 060BH
					MOV DX, 1144H
					INT 10H
				
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 07
					MOV DL, 33
					INT 10H
						
					MOV AH, 09H
					LEA DX, figura2
					INT 21H
		
					// Etiqueta radio
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 09
					MOV DL, 20
					INT 10H
			
					MOV AH, 09H
					LEA DX, radio
					INT 21H
			
					// Etiqueta area
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 11
					MOV DL, 20
					INT 10H
			
					MOV AH, 09H
					LEA DX, area
					INT 21H
				}
				// Leer entrada del radio
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
					
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 09
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 0D21H
					MOV DX, 0D23H
					INT 10H
				}
				scanf ("%f", &rad);
				// Calcular area
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
			
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 11
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 1121H
					MOV DX, 1124H
					INT 10H
				}
				a = (3.1416*(rad*rad));
				printf ("%f\n\n\n\n\n\n\n", a);
				system ("PAUSE");
				break;
			case 3:
				asm {
				// Encabezado triangulo	
					MOV AX, 0600H
					MOV BH, 01H
					MOV CX, 0000H
					MOV DX, 184FH
					INT 10H
				
					MOV AX, 0600H
					MOV BH, 31H
					MOV CX, 060BH
					MOV DX, 1144H
					INT 10H
				
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 07
					MOV DL, 33
					INT 10H
						
					MOV AH, 09H
					LEA DX, figura3
					INT 21H
		
					// Etiqueta base
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 09
					MOV DL, 20
					INT 10H
			
					MOV AH, 09H
					LEA DX, base
					INT 21H
					
					// Etiqueta altura
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 11
					MOV DL, 20
					INT 10H
					
					MOV AH, 09H
					LEA DX, altura
					INT 21H
			
					// Etiqueta area
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 13
					MOV DL, 20
					INT 10H
			
					MOV AH, 09H
					LEA DX, area
					INT 21H
				}
				// Leer entrada de la base
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
					
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 09
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 0D21H
					MOV DX, 0D23H
					INT 10H
				}
				scanf ("%f", &bas);
				// Leer entrada de la altura
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
			
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 11
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 0F21H
					MOV DX, 0F21H
					INT 10H
				}
				scanf ("%f", &alt);
				// Calcular area
				asm {
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 24
					MOV DL, 00
					INT 10H
			
					MOV AH, 02H
					MOV BH, 00
					MOV DH, 13
					MOV DL, 33
					INT 10H
			
					MOV AX, 0600H
					MOV BH, 50H
					MOV CX, 1121H
					MOV DX, 1124H
					INT 10H
				}
				a = (bas*alt/2);
				printf ("%f\n\n\n\n\n\n\n", a);
				system ("PAUSE");	
				break;
		}	
	}
}
