#include <stdio.h>

/*
gcc -o ex1 ex1.c 
./cp1 testeG.
*/

int main(int argc, char** argv)
{
	FILE *entrada;
	int c, count = 1;

	if(argc != 2)
	{
		fprintf(stderr,"Erro na chamada do comando.\n");
		fprintf(stderr,"Uso: %s [ARQUIVO ORIGEM] [ARQUIVO DESTINO].\n", argv[0]);
		return 1;
	}

	entrada = fopen(argv[1],"rb");
	if(!entrada)
	{
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

	c = fgetc(entrada);

	// só existe EOF depois de uma leitura frustada, quando na linha 32 pedir o primeiro byte e ele nao entregar (o arquivo tá fazio), ou seja, precisa de uma leitura antes
	// EOF é um estado onde o ponteiro de leitura do arquivo está numa posição onde tem dados pra leitura do arquivo
	while(c != EOF)
	{
		c = fgetc(entrada);
		if(c == '\n') {
        	count++;
		}
	}

	fclose(entrada);
    printf("%d", count);
	return 0;
}
