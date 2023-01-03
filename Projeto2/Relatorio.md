# Relatório 2º Projeto ASA 2022/2023 

## Grupo: tp012

**Alunos: David Pires (103458) Diogo Miranda (102536)**

***

## Descrição do Problema e da Solução

**Problema:** Dado um grafo G = (V,E), determinar o caminho de maior peso possível no grafo (Maximum Spanning Tree).

**Solução:** Aplicação do Algoritmo de Kruskal mas com uma pequena alteração. Até ao sort o algoritmo mantém-se porém depois percorre-se as edges do fim do vetor para o início (ordem decrescente) em vez do início do vetor para o fim (ordem crescente). Desta forma retira-se primeiro as edges de maior peso, obtendo-se a Maximum Spanning Tree.


## Análise Teórica

- Ler o input dado (simples loop que lê todas as entradas (#V, #E, edges)): O(E+2) = **O(E)**

- Criação do vetor para guardar os vértices e a sua raiz: **O(V)**

- Criação do vetor para guardar as edges: **O(E)**

- Dar sort no vetor de edges (utilizada a função `sort()` da biblioteca `<algorithm>`): **O(E.log(E))**

- Implementação de Kruskal, percorrer todas as edges, O(E) vezes a complexidade de uma chamada à função `notCycle()`. Na função `notCycle()` todos os parents da tree com menor tamanho são unidos à maior àrvore, com compressão de caminhos percorre-se todos os vértices (± procura em àrvore binária, tem complexidade O(log(E))). Assim a complexidade é: **O(E.log(E))**

> **_NOTA:_** Note-se que a nossa implementação de Kruskal não utiliza o critério de desempate por rank na junção de àrvores pelo que a procura nas àrvores será mais lenta que log(E) no pior caso. A nossa implementação de Kruskal terá uma complexidade um pouco pior que a demonstrada.


Complexidade Global:

$$O(E \times log(E))$$


***

# Relatório 2º Projeto ASA 2022/2023


## Grupo: tp012 

**Alunos: David Pires (103458) Diogo Miranda (102536)**

## Avaliação Experimental dos Resultados

> **_NOTA:_** Os seguintes resultados foram obtidos através de cortes do seguinte **ADD LINK teste ADD LINK** com o comando `sed` de UNIX. Os resultados foram obtidos com a ferramenta [hyperfine](https://github.com/sharkdp/hyperfine) e são uma média de entre 100~200 testes.

![](./Resources/Recursao.png)

Podemos concluir que gráfico aproxima-se da função E.log(E) (gráfico em baixo) pelo que suporta a tese que a complexidade global é:

$$O(E \times log(E))$$

Com esta complexidade este algoritmo é extremamente ineficiente, no entanto com a introdução da programação dinâmica conseguimos tornar o algoritmo bastante mais eficiente.

![](./Resources/ProgramacaoDinamica.png)

Este gráfico aproxima-se da função (Explicitado na última página):

$$ O({\mathrm{e}^n}) $$

Embora ainda bastante ineficiente este algoritmo, com programação dinâmica é extremamente mais rápido que o anterior, como se pode ver em comparação com os dois gráficos.

***
