# CEFET_RJ-ORGANIZA-O-E-ESTRUTURAS-DE-ARQUIVOS_2024
Aulas ministradas por Renato Mauro, no CEFET-RJ, em 2024.1


obs: ASCII possui símbolos imprimiveis e nao imprimiveis

## ARQUIVO TEXTO
caracteres imprimiveis, menos tabulacao e quebra de linha

## .DAT
extensao inventada, o SO nao vai reconhecer nenhum tipo de extensão

## WB (write binary)
modo de abertura
sobrescreve o arquivo

## SOBRE STRUCTS
se quiser preencher um tip for um tipo primitivo, nao precisa usar strcpy(...) para preencher um dado na struct, caso seja primitivo (int,...) é só colocar direto, ex: p.idade = 21

## SIZEOF
quantos bytes a struct etc gastam na memória (bytes)

## MEMSET
preenche todo espaço de memória com um determinado valor (de uma vez, ao invés de usar o 'for')

## RB (read binary)
modo de abertura
tem que abrir com ele, pois é um arquivo binário

## PUTS
imprime na tela

## FPUTS
imprime na tela e tem que passar um arquivo stdout

## FGETS
pega o arquivo texto (não binário)

## SEEK

```c
  fseek(f, n, seek_...) 
```
#### SEEK_SET
pega um elemento a partir do começo do arquivo
relativo ao início

#### SEEK_CUR
pega um elemento a partir de onde ele está parado no arquivo
relativo ao lugar que está parado

#### SEEK_END
pega um elemento a partir do final do arquivo
relativo ao fim


## FTELL
retorna a posição absoluta onde vc estava

```c
  fseek(f,0,SEEK_END);
  x - ftell(f);
```

o programa acima retorna o tamanho do arquivo em bytes. ele vai pro final do arquivo e "pergunta" onde está

* Ler capítulo 11 do livro do deitel
* link de linguagens bizarras (inclusive, whitespace) - 
* https://programaosso.blogspot.com/2012/11/bizarras-linguagens-de-programacao.html
* Ler sobre - Alan Turing
* usar \c pra escutar bip
