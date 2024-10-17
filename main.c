//Arquivo com as configurações básicas do jogo
#include "config.h"

void impressaoTabuleiro();

void inicioJogo() {
    for (int linha = 0; linha < tam; linha++) {
        for (int coluna = 0; coluna < tam; coluna++) {
            jogo[linha][coluna].temBomba = 0;
            jogo[linha][coluna].aberto = 0;  
            jogo[linha][coluna].vizinhos = 0;
            jogo[linha][coluna].flag = 0;
            
        }
    }
}

void sortearBombas(int n) {
    int i;
    srand(time(NULL));

    for (i = 1; i <= n; i++) {
        int linha = rand() % tam;
        int coluna = rand() % tam;
        if (jogo[linha][coluna].temBomba == 0) {
            jogo[linha][coluna].temBomba = 1;
        } else {
            i--;
        }
    }
}

int validacaoCoordenadas(int linha, int coluna) {
  if(linha >= 0 && linha < tam && coluna >= 0 && coluna < tam){
    return 1;
  }else{
    return 0;
  }
}

int bombasVizinhas(int linha, int coluna) {
    int quantidade = 0;
  //cima
    if (validacaoCoordenadas(linha - 1, coluna) && jogo[linha - 1][coluna].temBomba)
        quantidade++;
  //baixo
    if (validacaoCoordenadas(linha + 1, coluna) && jogo[linha + 1][coluna].temBomba)
        quantidade++;
  //direita
    if (validacaoCoordenadas(linha, coluna + 1) && jogo[linha][coluna + 1].temBomba)
        quantidade++;
  //esquerda
    if (validacaoCoordenadas(linha, coluna - 1) && jogo[linha][coluna - 1].temBomba)
        quantidade++;
  //superior direita
    if (validacaoCoordenadas(linha+1, coluna + 1) && jogo[linha + 1][coluna +  1].temBomba)
      quantidade++;
  //inferior direita
    if (validacaoCoordenadas(linha-1, coluna + 1) && jogo[linha - 1][coluna + 1].temBomba)
      quantidade++;
  //superior esquerda 
    if (validacaoCoordenadas(linha+1, coluna - 1) && jogo[linha + 1][coluna - 1].temBomba)
      quantidade++;
  //inferior esquerda
    if (validacaoCoordenadas(linha-1, coluna - 1) && jogo[linha - 1][coluna - 1].temBomba)
      quantidade++;
    return quantidade;
}

void contarBombas() {
    for (int linha = 0; linha < tam; linha++) {
        for (int coluna = 0; coluna < tam; coluna++) {
            jogo[linha][coluna].vizinhos = bombasVizinhas(linha, coluna);
        }
    }
}

void inicializarTabuleiro(int tamanho, int bombas) {
    tam = tamanho;
    inicioJogo();
    sortearBombas(bombas);
    contarBombas();
    posicoesParaWin = tam - bombas;
}

void impressaoTabuleiro() {
    printf("\n\n\t   ");
    for (int coluna = 0; coluna < tam; coluna++)
      printf(" %c  ", 'A' + coluna);
    printf("\n\t ");

    for (int coluna = 0; coluna < tam; coluna++)
      printf("----");
    printf("--");

    printf("\n");

    for (int linha = 0; linha < tam; linha++) {
      printf("\t%d |", linha);
      
      if(linha<10){
            printf(" ");
      }
      
      for (int coluna = 0; coluna < tam; coluna++) {

        if(jogo[linha][coluna].aberto){
          contPosiAbertas++;
        }
      
        if (jogo[linha][coluna].flag) {
          printf("!");
        } else {
          if(jogo[linha][coluna].temBomba && jogoAtivo == 0){
            printf("*");
          }else {
            if(jogo[linha][coluna].aberto && jogo[linha][coluna].vizinhos != 0){
              printf("%i" , jogo[linha][coluna].vizinhos);
            }else if (jogo[linha][coluna].aberto && jogo[linha][coluna].vizinhos == 0){
              printf("#");
            } else {
              printf(" ");
            }
          }
        }
        printf(" | ");
      }
      
      printf("\n\t ");
      for (int coluna = 0; coluna < tam; coluna++)
        printf("----");
      printf ("--");
      printf("\n");
  }
}

//Arquivo que contém o menu do jogo
#include "menu.h"

//---------------------ações User-------------------

void abrirCelula(int coluna, int linha); 
int coordColuna(char CoordenadaColuna);
void marcarBandeira(int coluna, int linha);
void desmarcarBandeira(int coluna, int linha);
void perdeuJogo();
void ganhouJogo();

void inputUser(){
  int linha, coluna, acao;
  char CoordenadaColuna;  

  //Limpando o buffer
  setbuf(stdin, NULL);
  
  printf("Escolha uma posição do tabuleiro:\n");
  scanf("%c%i", &CoordenadaColuna, &linha);

  //Conversão do char pra int 
  coluna = coordColuna(CoordenadaColuna);
  
  if(validacaoCoordenadas(coluna, linha))
    {
      printf("Escolha uma ação:\n");
      printf("0. Para abrir posição\n");
      printf("1. Marcar posição com bandeira\n");
      printf("2. Desmarcar posição com bandeira\n");
      printf("3. Voltar\n");
    
      scanf("%i", &acao);

      switch(acao){
        case 0: 
            if( jogo[linha][coluna].flag != 1 ){
              abrirCelula(coluna, linha);
            } else {
              printf("Posição Marcada com bandeira !\n");
            }
          break;
        case 1:
          marcarBandeira(coluna, linha);
          break;
        case 2:
          desmarcarBandeira(coluna, linha);
          break;
        case 3:
          inputUser();
          break;
        default:
          printf("Digite uma ação válida.\n");
      }       
      impressaoTabuleiro();
    } 
    else {
      printf("Por favor informe uma coordenada válida.\n");
    }
  
}

void abrirCelula(int coluna, int linha) {
    jogo[linha][coluna].aberto = 1;
  
    if( jogo[linha][coluna].temBomba == 1 ){ 
      perdeuJogo();
    }else {
      if(contPosiAbertas == posicoesParaWin){
        ganhouJogo();
      }
    }
} 

//Retorna a coordenada da coluna no tipo INT 
int coordColuna(char coluna){
    /*
      Valor ASCII TOTAL (90) - Valor ASCII da posição ( ? ) = CONSTANTE  
      Valor total em DECIMAL - CONSTANTE
    */
      coluna = toupper(coluna);
      int constante = (int) coluna; 
      return 25 - (90-constante);
}

void marcarBandeira(int coluna, int linha){  
  jogo[linha][coluna].flag = 1;
}

void desmarcarBandeira(int coluna, int linha){
  jogo[linha][coluna].flag = 0;
  printf("Bandeira desmarcada com sucesso!\n");
}

void perdeuJogo(){
  printf("A posição escolhida é uma bomba, você perdeu!\n");
  derrotas++;
  jogoAtivo = 0;
}
void ganhouJogo(){
  vitorias++;
  jogoAtivo = 0;
}

//-----------------------------------------------------------
void Creditos(){
  printf("-----------------------------------------------------------\n");
  printf("Jogo avaliativo da Unidade 3 de Algoritmo e programação de computadores.\n");
  printf("Desenvolvedores:\n");
  printf("Paulo Victor das Flores Cabral de Medeiros\n");
  printf("Maria Clara da Silva\n");
  printf("Rafael de Melo Santos Leite\n");
  printf("João Victor Alves\n");
}

int main() {
    //0 - flase 
    //1 - true
    int jogarNovamente = 1;
    
    do {
      exibirMenu(); 
      while(jogoAtivo != 0){
        inputUser();
      }
      printf("Vitorias: %i | Derrotas: %i\n", vitorias, derrotas);
      printf("Deseja jogar novamente ? (1 - Sim, 0 - Não)\n");
    
      setbuf(stdin, NULL);
      
      scanf("%i", &jogarNovamente);
    }while(jogarNovamente != 0);
    
    printf("JOGO ENCERRADO !!\n");
    Creditos();

    return 0;
}