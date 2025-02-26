# DCC014
Projeto realizado durante a disciplina Inteligência Artificial

## Como rodar

No diretório raíz do projeto, rode o comando
```
sh start.sh
```

E siga as intruções do menu.

## Explicação da estrutura do código

O código possui as seguintes classes:

1. No
2. Lista
3. Aresta
4. Vertice
5. Grafo

A **estrutura No** são elementos genéricos (template) linkados por ponteiros de anterior e próximo. 
métodos importantes:
- getElemento()
- getProximo()
- getAnterior()

Esses objetos No são organizados pela **estrutura de Lista**, assim podemos diretamente conseguir o final, o começo e a quantidade de elementos.

Além disso, a estrutura de Lista também possui seus próprios **operadores de iteração**. Dessa forma, podemos usar da seguinte forma, seja listaDeInteiros declarado por Lista<int>,

for (int i : listaDeInteiros)

A **classe Vertice** é composta por seu id e por uma Lista de Aresta. A **Aresta** é uma classe que possui um custo (peso) e um Vertice de destino.

Tudo isso é controlado pela **classe Grafo**, que possui uma Lista de objetos Vertice. A classe Lista nos dá tanto um conjunto de objetos Aresta quanto de objetos Vertice.


