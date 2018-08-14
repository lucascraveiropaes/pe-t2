#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <limits.h>
#include <time.h>

#define A_LIMIT 5000
#define B_LIMIT 10000
#define C_LIMIT 20000
#define D_LIMIT 30000

void readArray(int* origin_array, char filename[50], char arrayName) {
	char line[30], value[30];
	FILE *fptr = fopen(filename, "r");
	
	if(fptr == NULL) {
		printf("Não foi possível abrir o arquivo de arrays.\n");
	} else {
		while(fgets(line, 30, fptr) != NULL) {
			sscanf(line, "%s\n", value);
			
			*origin_array = atoi(value);
			origin_array++;
		}
		printf("Array %c criado com sucesso.\n", arrayName);
	}
	
	fclose(fptr);
}

void orderArray(int* origin_array, int limit, char arrayName) {
	int* array = origin_array;
	int i, j;
	
	for (i = 0; i < limit-1; i++) {
		for (j = 0; j < limit-i-1; j++) {
			int* a = array;
			int* b = ++array;
						
        	if (*a < *b) {
				int x = *a;
				*a = *b;
				*b = x;
			}
		}
		array = origin_array;
	}

	printf("Array %c ordenado com sucesso.\n", arrayName);
}

void saveOrderedArray(int* origin_array, int limit, char filename[50], char arrayName) {
	int* array = origin_array;
	int i;
	FILE *fptr = fopen(filename, "w");
	
	if(fptr == NULL) {
		printf("Não foi possível salvar o array ordenado.\n\n");
	} else {
		for (i = 0; i < limit; i++) {
			fprintf(fptr,"%d\n", *array);
			array++;
		}
		
		printf("Array %c salvo com sucesso.\n", arrayName);
	}
	
	fclose(fptr);
}

void executeFunctions(int* array, char basefile[50], char exitfile[50], int limit, char arrayName) {
	clock_t start, end;
    
    start = clock();
     
	readArray(array, basefile, arrayName);
	orderArray(array, limit, arrayName);
	saveOrderedArray(array, limit, exitfile, arrayName);
	
	end = clock();
	double finalTime = ((double) (end - start)) / CLOCKS_PER_SEC;
	
	printf("Tempo usado: %f\n\n", finalTime);
	
}

int main() {
	int A[A_LIMIT], B[B_LIMIT], C[C_LIMIT], D[D_LIMIT], i;
	
	executeFunctions(A, "../A.txt", "Ordenado-A.txt", A_LIMIT, 'A');
	executeFunctions(B, "../B.txt", "Ordenado-B.txt", B_LIMIT, 'B');
	executeFunctions(C, "../C.txt", "Ordenado-C.txt", C_LIMIT, 'C');
	executeFunctions(D, "../D.txt", "Ordenado-D.txt", D_LIMIT, 'D');	
}
