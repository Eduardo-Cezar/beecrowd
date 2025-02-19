# Ferramenta Irritante de Pintura (1649)

**Link do Problema:** [Ferramenta Irritante de Pintura](https://judge.beecrowd.com/pt/problems/view/1649)  
**Plataforma:** Beecrowd  
**Dificuldade:** 4  

## Descrição do Problema
Talvez você queira saber o que é uma ferramenta irritante de pintura? Primeiro de tudo, a ferramenta de pintura falada só aceita cor preta e branca. Portanto, uma imagem consiste em uma área retangular de pixels, que pode ser preto ou branco. Em segundo lugar, existe apenas uma operação para mudar a cor dos pixels:

Selecione uma área retangular de r linhas e c colunas, que está completamente dentro do quadro. Como resultado da operação, cada pixel no interior do retângulo selecionado muda a sua cor (preto vira branco e branco vira preto).

Inicialmente, todos os pixels são brancos. Para criar uma imagem, a operação descrita acima pode ser aplicada várias vezes. Você pode pintar uma certa imagem que você tem em mente?

## Descrição das Entradas
A entrada contém vários casos de teste. Cada caso de teste inicia com uma linha contendo quatro inteiros n, m, r e c. (1 ≤ r ≤ n ≤ 100, 1 ≤ c ≤ m ≤ 100). As próximas n linhas descrevem uma linha de pixels da pintura que você deseja criar. Cada linha consiste em m caracteres com a descrição do pixel desejado a ser pintado (0 indica a cor branca, 1 indica a cor preta).

Os casos de testes terminam com uma line contendo 4 zeros.

## Descrição das Saidas
Para cada caso de teste, imprima o número mínimo de operações necessárias para criar a pintura, ou -1 se for impossível.
## Exemplo de Entrada e Saída

<div style="display: flex;">
  <div style="flex: 50%; padding: 5px;">
    <h4>Entrada</h4>
    <pre>
3 3 1 1
010
101
010
4 3 2 1
011
110
011
110
3 4 2 2
0110
0111
0000
0 0 0 0
    </pre>
  </div>
  <div style="flex: 50%; padding: 5px;">
    <h4>Saída</h4>
    <pre>
4
6
-1
    </pre>
  </div>
</div>

## Abordagem
O problema exige que transformemos uma imagem inicial (toda branca, representada por 0s) em uma imagem desejada (com 0s e 1s) usando operações de inversão em áreas retangulares de tamanho r x c. A lógica utilizada no código pode ser resumida nos seguintes passos:

Passo 1: A abordagem Gulosa:  
>O código percorre a matriz da imagem desejada de cima para baixo e da esquerda para a direita, e sempre que encontrar um pixel com valor 1, ele realiza uma operação de inversão em uma área retangular de tamanho r x c começando a partir daquele pixel.  

>Essa escolha é gulosa pois ao encontrar um 1, o código decide imediatamente inverter a área r x c que começa naquele ponto, sem considerar o impacto global. Essa decisão localmente ótima funciona porque cada inversão afeta apenas a área selecionada e não interfere nas decisões futuras, ou seja, o problema possui sub-estrutura ótima.

Passo 2: Inversão dos pixels.  
> Na inversão alteramos o valor de cada pixel na área r x c de 0 para 1 ou de 1 para 0, essa operação é realizada até que todos os pixels da matriz sejam 0 ou então que seja impossível continuar.

Passo 3: Verificação.
> Após todas as operações, o código verifica se a matriz resultante contém apenas 0's, caso ainda possua 1's, isso significa que não é possível transformar a imagem inicial na desejada.

**Estruturas de Dados e Algoritmos Escolhidos**
- Matriz Dinâmica (int** mat)
    > A matriz mat é usada para armazenar a imagem desejada, ela é alocada dinamicamente porque o tamanho da imagem (n x m) pode variar para cada caso de teste.
- Abordagem Gulosa  
    > A escolha gulosa foi utilizada porque ela simplifica o problema, ao vez de tentar resolver por bruteforce ou backtracking.

**Complexidade:**  
- Tempo: $$ O(n × m × r × c)$$  
- Espaço: 
$$ O(n ×  m) $$