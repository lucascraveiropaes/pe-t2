#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int createArray(char name[50], int limit) {
	FILE *fptr = fopen(name, "w"); 	// Criando arquivo com vetor
	int i=0, n=-1;
	
	if(fptr == NULL) { // Mensagem de erro caso n�o consiga abrir o arquivo
		printf("\nN�o foi poss�vel criar o vetor");
		return 0;
	}
	
	for(i = 0; i < limit; i++) {
		n = (rand() % 10000) + 1; // Gerando n�mero de 1 at� 10.000
	
		fprintf(fptr,"%d\n", n); // Salva o conte�do enviado no par�metro no final do arquivo
	}

	fclose(fptr);
	
	return 1;
}

int main() {
	srand( (unsigned) time(NULL) );	
	
	createArray("A.txt",  5000);
	createArray("B.txt", 10000);
	createArray("C.txt", 20000);
	createArray("D.txt", 30000);
}
