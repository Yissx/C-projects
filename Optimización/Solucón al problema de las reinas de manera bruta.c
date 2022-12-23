#include<stdio.h>
#include<stdbool.h>
#include<time.h>

int main(){
	unsigned t1, t0;
	t0 = clock();
	int soluciones = 0, noSoluciones, i, j, k, l, m, n;
	for(i = 0; i < 25; i ++){
		for(j = 0; j < 25; j++){
			for(k = 0; k < 25; k ++){
				for(l = 0; l < 25; l ++){
					for(m = 0; m < 25; m ++){
						if(i >= 0 && i < 5 && j > 4 && j < 10 && k > 9 && k < 15 && l > 14 && l < 20 && m > 19 && m < 25){
							//No choque horizontal 
							if(i % 5 != j % 5 && i % 5 != k % 5 && i % 5 != l % 5 && i % 5 !=  m % 5 && j % 5 != k % 5 && j % 5 != l % 5 && j % 5!= m % 5 && k % 5 != l % 5 && k % 5 != m % 5 && l % 5 != m % 5){
								//No choque vertical
								if(j - i != 4 && k - i != 8 && l - i != 12 && m - i != 16 && k - j != 4 && l - j != 8 && m - j != 12 && l - k != 4 && m - k != 8 && m - l != 4){
									//No choque en la diagonal inferior
									if(j - i != 6 && k - i != 12 && l - i != 18 && m - i != 24 && k - j != 6 && l - j != 12 && m - j != 18 && l - k != 6 && m - k != 12 && m - l != 6){
										soluciones ++;
										for(n = 0; n < 25; n++){
											if(n % 5 == 0)
												printf("\n");
											if(i == n || j == n || k == n || l == n || m == n)
												printf(" [R]");
											else
												printf(" [ ]");
										}
										printf("\n\n");
									}
								}
							}
						}
						noSoluciones ++;
					}
				}
			}
		}
	}
	t1 = clock();
	printf("\n %d soluciones al problema de las 5 reinas", soluciones);
	printf(" de %d posibles soluciones", noSoluciones);
	double time = (double)(t1-t0)/CLOCKS_PER_SEC;
	printf("\n\n Tiempo de ejecucion: %f segundos\n ", time);
	system("pause");
	return 0;
}

