#include <stdio.h>
#include <stdlib.h>

int main(){
	int p, src = 1, dst;
	printf("Ejemplo asm en C!\n");
	
	__asm("movl %eax, %ebx\n\t"); //mov eax,1
	//Sin pase de parametros
	__asm__ ( "movl $10, %eax;"
              "movl $20, %ebx;"
	          "add %ebx, %eax;"
	        );
	
 	//Con pase de parametros
	asm ("mov %1, %0\n\t"
	     "add $1, %0"
	     : "=r" (dst)
	     : "r" (src)
	    );
 	printf("%d\n", dst);
	 
    return 0;
}
