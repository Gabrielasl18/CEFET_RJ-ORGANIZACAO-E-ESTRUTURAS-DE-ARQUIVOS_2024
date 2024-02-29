#include <stdio.h>

// stdout, stdin, stderr

int main(int argc, char** argv)
{
	FILE *entrada, *saida;
	int c;

	if(argc != 3)
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

	saida = fopen(argv[2],"wb");
	if(!saida)
	{
		fclose(entrada);
		fprintf(stderr,"Arquivo %s não pode ser aberto para escrita\n", argv[2]);
		return 1;
	}

	c = fgetc(entrada);

	// só existe EOF depois de uma leitura frustada, quando na linha 32 pedir o primeiro byte e ele nao entregar (o arquivo tá fazio), ou seja, precisa de uma leitura antes
	// EOF é um estado onde o ponteiro de leitura do arquivo está numa posição onde tem dados pra leitura do arquivo
	while(c != EOF)
	{
		fputc(c, saida);
		c = fgetc(entrada);
	}

	fclose(entrada);
	fclose(saida);
	return 0;
}

