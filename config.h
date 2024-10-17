#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

typedef struct {
    int temBomba;  
    int aberto;       
    int vizinhos;
    int flag;  
    int vazio; //vizinhos pode ser usada pra validar se um campo está vazio ou não
} Celula;

Celula jogo[20][20];
int tam = 8;
int jogoAtivo = 1; // 1 = ativo, 0 = inativo
int derrotas = 0;
int vitorias = 0;
int posicoesParaWin = 0;
int contPosiAbertas = 0;