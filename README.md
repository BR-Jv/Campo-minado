<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH" crossorigin="anonymous">

O campo minado é um jogo de estratégia baseado em coordenadas. O objetivo é
conseguir localizar onde estão as bombas baseando-se na contagem de espaços
vizinhos. No jogo podemos marcar as posições em que estão as bombas e para ganhar
temos que conseguir abrir todas as coordenadas sem abrir nenhuma bomba.

## Controles e ações do jogo

Os “*” correspondem às bombas, “#” aos espaços vazios e “!” corresponde às bandeiras.

<div>
  <div>
    Níveis de dificuldade do jogo:
    <ul>
      <li>
         Muito Fácil
      </li>
      <li>
           Fácil
      </li>
      <li>
         Médio
      </li>
      <li>
          Difícil 
      </li>
    </ul>
  </div>
  <div>
    Ações disponiveis:
    <ul>
      <li>
        Abrir Célula  
      </li>
      <li>
          Marcar Posição com Bandeira 
      </li>
      <li>
          Desmarcar posição com bandeira
      </li>
      <li>
          Voltar
      </li>
    </ul>  
</div> 
</div>


 

## Regras

* condição de derrota é clicar em uma
coordenada que tenha uma bomba.

* condição de vitória dar-se pela abertura
de todas as coordenadas que não tenham bomba ou consiga marcar todas
as coordenadas com bandeira.


## Fluxos

O jogo segue um fluxo simples e intuitivo. A primeiro momento, vai ser
solicitado qual nível o usuário quer, depois disso, já podemos visualizar o tabuleiro. No
segundo passo, temos que escolher a coordenada que iremos executar uma ação, sendo
essa abrir célula, colocar bandeira ou retirar uma bandeira (no jogo também foi
implementado a opção de voltar, caso o usuário queira inserir outra coordenada). O jogo
só finaliza caso o usuário abra uma posição que tenha bomba, coloque bandeiras em
todas as bombas, ou visualize todas as células que não tem bomba.
Se o usuário digitar uma posição que tem bomba, vai aparecer a mensagem
correspondente à derrota. Nesta mensagem terão as opções de jogar novamente. Caso o
usuário digite para jogar novamente, será feito novamente o começo do fluxo. Se o
usuário digitar para sair, vai aparecer a mensagem de finalização com os créditos dos
criadores do jogo.
Se o conseguir obedecer às condições de vitória, isto é, consiga marcar todas as
bombas com bandeiras ou abrir todas as células que não tem bomba, ele será
direcionado para uma tela de vitória, em que poderá visualizar a opção de jogar
novamente ou sair, sendo essa parte, especificamente, semelhante ao fluxo final dederrota também, em que o usuário pode voltar para o começo do fluxo ou finalizar,
aparecendo assim os créditos finais.

Projeto desenvolvido em equipe(código e relatório). Vale ressaltar que, apesar das distribuições de funções, todos os integrantes
participaram da implementação do código em geral. 

INTEGRANTE  |  FUNÇÃO
------------|------------
Paulo Victor|Calcular números de pistas.
João Victor |Tratar eventos e atualizar tabuleiro.
Maria Clara |Definir a estrutura dos tabuleiros e menu.
Rafael de Melo |Gerar minas aleatórias.


