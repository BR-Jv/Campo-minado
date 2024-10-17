void exibirMenu() {
    int escolhaMenu;

    printf("##### Bem-vindo(a) ao Jogo Campo Minado #####\n\n");
    printf ("Asteriscos (*) significam cedulas com bombas.\n");
    printf ("Espaços em branco (#) significam cedulas vazias.\n");
    printf ("(!) significam bandeiras.\n\n"); 
    
  
    printf("Escolha o nivel de dificuldade do tabuleiro.\n");
    printf("1. Muito facil (8x8).\n");
    printf("2. Facil (12x12).\n");
    printf("3. Medio (16x16).\n");
    printf("4. Dificil (20x20).\n");
    printf("0. Sair.\n");
  
    printf("Digite o nivel desejado: ");
    scanf("%d", &escolhaMenu);

    switch (escolhaMenu) {
        case 1:
            inicializarTabuleiro(8, 9);
          printf ("\n\nPara iniciar o jogo, primeiro selecione uma coluna (A-H) e, em seguida, escolha uma linha (0-7).\n");
            break;
        case 2:
            inicializarTabuleiro(12, 13);
          printf ("\n\nPara iniciar o jogo, primeiro selecione uma coluna (A-L) e, em seguida, escolha uma linha (0-11).\n");
            break;
        case 3:
            inicializarTabuleiro(16, 17);
          printf ("\n\nPara iniciar o jogo, primeiro selecione uma coluna (A-P) e, em seguida, escolha uma linha (0-15).\n");
            break;
        case 4:
            inicializarTabuleiro(20, 21);
          printf ("\n\nPara iniciar o jogo, primeiro selecione uma coluna (A-T) e, em seguida, escolha uma linha (0-19).\n");
            break;
        case 0:
            printf("Encerrando jogo.\n");
            break;
        default:
            printf("Opcao invalida. Tente novamente.\n");
    }

    if (escolhaMenu != 0) {
      impressaoTabuleiro();
    }else {
      jogoAtivo = 0;
    }
  
}
