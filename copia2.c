/*
Esse programa faz leitura/escrita em blocos
diferença do programa 1 (fwrite/fread) um bando de byte de cada vez, diferente do copia1 que é um byte de cada vez


*/
#include <stdio.h>

// buffer de 8kb
#define TAMANHO 8192

int main(int argc, char** argv)
{
	// estrutura de dados com as infos que o SO precisa pra poder ir no arquivo e falar com ele, é um ponteiro opaco, nao interessa o que tem dentro dele, porque muda de SO pra SO
	FILE *entrada, *saida;
	
	// em C caracter = byte
	char buffer[TAMANHO];
	int qtd;

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

	qtd = fread(buffer,1,TAMANHO,entrada);
	while(qtd > 0)
	{
		fwrite(buffer,1,qtd,saida);
		qtd = fread(buffer,1,TAMANHO,entrada);
	}

	fclose(entrada);
	fclose(saida);
	return 0;
}

