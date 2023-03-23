# O Caminho Guloso
* Atividade realizada no 3º período para a disciplina de Algoritmos e Estrutura de Dados I.
* Curso de Engenharia da Computação - CEFET-MG, Campus V. 

## Instruções para a realização da atividade
<b>1 -</b> Criar um sistema que leia K matrizes quadradas no tamanho NxN.<br>
<b>2 -</b> Seu programa deve enumerá-las, de forma a deixá-las organizadas para processamento. <br>
<b>3 -</b> Partindo da primeira matriz, você deve iniciar de um ponto preestabelecido, esse pode ser fornecido pelo usuário ou estar contido em arquivos extras de configuração. Não é permitido definir diretamente no código.<br>
<b>4 -</b> A partir da primeira matriz, você tem como regras: (a) avançar para a próxima coluna; (b) retroceder para coluna anterior; (c)  saltar para a linha de baixo; (d) ir em diagonal para baixo. Todas essas regras só se aplicam se a casa (posição i, j da matriz) ainda não tenha sido descoberta ou já processada. <br>
<b>5 -</b> Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento. <br>
<b>6 -</b> Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado.<br>

## Descrição
O Algoritmo é baseado no conceito de caminhamento em matrizes de forma gulosa. Esse conceito trabalha de forma que não é possível voltar atrás em decisões já tomadas, e que sempre será escolhido o maior valor para caminhar, ou seja, uma vez que eu já caminhei por uma posição da matriz, eu não posso voltar mais nela, e o objetivo é encontrar o maior valor final possível.<br>

## Resolução do Problema
Programa feito na linguagem C++.<br>
- O programa do caminho guloso é constituído por quatro arquivos: matriz.cpp, matriz.hpp, main.cpp, input.data.<br>
- <b>main.cpp:</b> É criado um ponteiro para uma matriz de inteiros e outro para uma variável inteira, chamada de tamanho. Essa variável irá receber uma função que retorna o tamanho da matriz que está dentro do arquivo, nesse caso, o “input.data”. Em seguida, será realizada uma alocação dinâmica para a matriz, utilizando o tamanho retornado. Esses dois elementos serão passados como parâmetros para as funções e utilizados durante todo o código. Ainda na main, será chamada a função “ler_andar_matriz”, que será responsável por realizar todas as instruções do código.<br>
- <b>matriz.hpp:</b> É definida todas as bibliotecas e funções utilizadas no código.<br>
- <b>matriz.cpp:</b> É realizado o desenvolvimento e a chamada de cada função.<br>
- <b>input.data:</b> Arquivo contendo o tamanho das matrizes (na primeira linha) e as próprias matrizes nas linhas seguintes. É importante salientar que a matriz é composta apenas por números inteiros positivos e o seu tamanho é quadrado, ou seja, tem o mesmo número de linhas e colunas. Abaixo um modelo de um arquivo com 4 matrizes 4x4:

<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/arquivo_ex.png">
</p>

- <b>Terminal de comando:</b> Onde é pedido ao usuário para digitar a posição (linha e coluna) pela qual ele quer começar a caminhar na matriz. E onde também é impresso as matrizes em seus formatos originais, em seus formatos com ‘-1’ nas posições onde foram percorridas, e também as somas individuais e total dos valores percorridos.

## Explicação da lógica utilizada
Na função "ler_andar_matriz", no matriz.cpp, é aberto o arquivo “input.data” para leitura, e criado um IF para toda vez que encontrar uma linha da matriz (linha 85). Dentro do IF, é realizado manobras para que uma variável auxiliar tipo string receba somente os elementos dessa matriz, sem os espaços ou “\0” (linha 90). Quando recebido um elemento, ele é transformado para inteiro e adicionado na matriz do programa, que foi passada como parâmetro para a função, e então, a variável é zerada para receber o próximo elemento, até que a matriz seja completamente preenchida (linhas 93 e 106).<br>
<br>Para o caminhamento, será utilizado essa matriz 4x4 para mostrar as decisões tomadas:

<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/matriz_ex.PNG">
</p>

<b>Será utilizado duas cores:</b> <br>
<i>Azul claro:</i> todas as posições da matriz que entrariam na condição apresentada.<br>
<i>Azul escuro:</i> posição selecionada aleatoriamente, dentro das que cumprem a condição, para exemplificação de possíveis caminhos, utilizando as setas.<br><br>

Na função verificar_matriz, foi criado um IF e três ELSE IF’s (condições), que serão analisados enquanto a matriz estiver sendo caminhada:<br>

<b>1º-</b> Irá verificar se a posição atual da matriz não é a primeira ou última coluna, ou última linha, pois nesse caso será possível caminhar para todos os lados, se algum deles já não tiver sido descoberto (linha 157):
<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/matriz_ex4.png">
</p>

<br> <b>2º-</b> Irá verificar se está na primeira coluna e não está na última linha, pois nesse caso será possível andar apenas para direita, diagonal direita e baixo (linha 160):
<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/matriz_ex2.png">
</p>

<br> <b>3º-</b> Irá verificar se está na última coluna e não está na última linha, pois nesse caso será possível andar apenas para esquerda, diagonal esquerda e baixo (linha 163):
<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/matriz_ex3.png">
</p>

<br> <b>4º-</b> Irá verificar se está na última linha e não está na última coluna, pois nesse caso apenas será possível caminhar para a direita (linha 166):
<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/matriz_ex1.png">
</p>

Cada um dos If / Else if irá chamar uma função que verifique qual o maior valor dentro dos caminhos possíveis, e se ele já não foi processado, quando o encontrar, a matriz será direcionada para esse caminho e continuará assim até chegar no fim.<br>

Para cada direção (direita, esquerda, abaixo, diagonal direita, diagonal esquerda) há uma função separada, que irá retornar o valor dessa posição, para realizar a soma, e que também irá substituir o elemento dessa posição por ‘-1’, com o objetivo de que a posição se dê como caminhada.<br>

Em casos de valores iguais, foi adotado uma forma para que a matriz sempre seja direcionada para os lugares mais distantes do final. A prioridade ficou nessa ordem: esquerda, direita, diagonal esquerda, abaixo, diagonal direita. <br>
O exemplo abaixo, com o número ‘58’, mostra esse método na prática. Com a localização atual no [2,3] a opção de caminhar poderia ser para direita [2,4] ou para baixo [3,3], pois é onde tem o maior valor dentre todas as opções possíveis. Seguindo a prioridade, ele foi primeiro para direita, analisou todas as posições novamente, e o ‘58’ era de novo o maior dos valores, então se moveu para baixo. Dessa forma, foi possível pegar os dois ‘58’ e acrescentá-los à soma, caso contrário, se fosse para baixo primeiro, teria deixado de pegar o valor da direita e afetado a soma total, cujo objetivo é ser o maior valor possível:<br>
<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/repeticao_ex.png">
</p>

Quando chegar ao fim de uma matriz, será printado o resultado do caminho e a sua soma, para então fazer a leitura da próxima e chamar todas as mesmas funções.
Assim sendo, o programa irá fazer a leitura de cada uma das matrizes contidas no arquivo, e caminhar por todas elas utilizando a forma gulosa.

## Exemplo de execução:
<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/terminal_ex1.png">
</p>
<p align="center">
<img src="https://github.com/MariRodriguess/O-Caminho-Guloso/blob/aa046bc459b47a820e2bc43dfe601470e53778e2/imgs/terminal_ex2.png">
</p>


## Compilação e Execução
Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução.<br>Para tanto, temos as seguintes diretrizes de execução:

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

## Contato
✉️ <i> mariana.itapec@gmail.com </i>
