# Lista de Exercicios - Ponteiros em C

Este README funciona como uma anotacao de estudo da lista sobre ponteiros em C. A ideia aqui nao e apenas guardar "a resposta", mas registrar o que cada questao ensinou, como pensar no problema e quais erros sao comuns.

## Ideia central da lista

Ao longo da lista, os principais conceitos praticados foram:

- diferenca entre valor, endereco e valor apontado
- declaracao e uso de ponteiros
- operador `&` para pegar endereco
- operador `*` para acessar o conteudo apontado
- aritmetica de ponteiros
- relacao entre vetores e ponteiros
- passagem por referencia em funcoes
- percorrer strings com ponteiros

Em C, ponteiro nao guarda diretamente o valor da variavel. Ele guarda o endereco dela na memoria. Para acessar o valor armazenado naquele endereco, usamos `*ponteiro`.

Exemplo conceitual:

- `x` -> valor da variavel
- `&x` -> endereco da variavel
- `p` -> ponteiro que guarda um endereco
- `*p` -> valor que esta no endereco guardado em `p`

## Questao 1 - Inspecao de memoria

### O que a questao pedia

- declarar uma variavel `int`
- declarar uma variavel `float`
- declarar um ponteiro para cada tipo
- fazer os ponteiros apontarem para as variaveis
- imprimir valores e enderecos

### O que foi aprendido

- cada variavel ocupa um lugar na memoria
- esse lugar possui um endereco
- ponteiro e uma variavel especial que guarda endereco
- o tipo do ponteiro precisa combinar com o tipo da variavel

### Como pensar

Se a pergunta e "onde esta guardado o valor?", voce usa `&variavel`.
Se a pergunta e "qual valor esta nesse endereco?", voce usa `*ponteiro`.

### Ponto importante

Nunca usar `*p` antes de fazer `p` apontar para um endereco valido.

## Questao 2 - Ponteiros cruzados

### O que a questao pedia

- fazer `p1` apontar para `A`
- fazer `p2` apontar para `B`
- trocar os ponteiros
- sem trocar os valores das variaveis

### O que foi aprendido

- trocar ponteiros e diferente de trocar valores
- `p1` e `p2` guardam enderecos
- `*p1` e `*p2` representam os valores apontados

### Como pensar

Se a questao pede trocar "quem aponta para quem", voce mexe em:

- `p1`
- `p2`

Se a questao pedisse trocar os valores, voce mexeria em:

- `*p1`
- `*p2`

### Erro classico

Confundir `p1` com `*p1`.

## Questao 3 - Incremento indireto

### O que a questao pedia

- declarar uma variavel inteira
- usar um ponteiro para somar 5
- depois multiplicar por 2
- sem acessar diretamente a variavel

### O que foi aprendido

- e possivel alterar uma variavel sem usar o nome dela
- para isso basta ter um ponteiro apontando para ela
- `*p = *p + 5` altera o valor original

### Como pensar

O ponteiro guarda o endereco da variavel. Entao, ao alterar `*p`, voce esta alterando o conteudo daquela posicao de memoria.

### Ponto importante

Se a regra disser "somente via ponteiro", o ideal e que toda a manipulacao relevante use `*p`.

## Questao 4 - Swap manual

### O que a questao pedia

- trocar os valores de duas variaveis inteiras
- usando ponteiros
- sem usar variavel auxiliar tradicional

### O que foi aprendido

- a troca agora e de valores, nao de ponteiros
- portanto a manipulacao correta e feita em `*p1` e `*p2`
- uma forma de fazer sem `temp` e usando soma e subtracao

### Como pensar

Se a troca e dos valores, a logica precisa atuar sobre o conteudo apontado:

- `*p1`
- `*p2`

### Observacao

Para estudo, soma/subtracao funciona bem. Em codigo real, `temp` costuma ser mais claro e seguro.

## Questao 5 - Vetor com ponteiros

### O que a questao pedia

- percorrer um vetor usando ponteiro
- sem usar indice
- imprimir os valores
- somar todos os elementos com aritmetica de ponteiros

### O que foi aprendido

- o nome do vetor aponta para o primeiro elemento
- vetor e ponteiro estao fortemente ligados em C
- `*(p + i)` acessa o elemento da posicao `i`

### Como pensar

Se `p = v`, entao:

- `*p` -> primeiro elemento
- `*(p + 1)` -> segundo
- `*(p + 2)` -> terceiro

### Ponto importante

Pode usar um `for` com contador. O que nao pode, se a regra proibir, e acessar com `v[i]`.

## Questao 6 - Modificacao por funcao

### O que a questao pedia

- criar uma funcao `void dobra(int *x);`
- dobrar o valor da variavel recebida
- testar na `main`

### O que foi aprendido

- funcoes podem alterar variaveis da `main` se receberem o endereco delas
- isso acontece porque o parametro e um ponteiro
- passagem por referencia em C e feita usando endereco e ponteiro

### Como pensar

Se a funcao recebe:

```c
int *x
```

entao ela recebe um endereco.

Dentro da funcao:

- `x` -> endereco recebido
- `*x` -> valor da variavel original

### Ponto importante

Se passar apenas o valor, a funcao recebe uma copia. Se passar `&variavel`, ela recebe o endereco e pode alterar a original.

## Questao 7 - Maior elemento do vetor

### O que a questao pedia

- criar `int maior(int *v, int tamanho);`
- percorrer o vetor sem usar `v[i]`
- retornar o maior valor

### O que foi aprendido

- como receber vetor em funcao usando ponteiro
- como comparar elementos e manter um "maior atual"
- como usar o primeiro elemento como referencia inicial

### Como pensar

O raciocinio natural e:

1. assumir que o primeiro elemento e o maior
2. percorrer o restante
3. se encontrar valor maior, atualizar

### Ponto importante

Se o primeiro elemento ja foi usado como base, o laco comeca no segundo.

## Questao 8 - Contagem de caracteres

### O que a questao pedia

- criar `int conta(char *str, char c);`
- contar quantas vezes um caractere aparece numa string
- usando apenas ponteiros

### O que foi aprendido

- string em C e um vetor de `char` terminado por `'\0'`
- da para percorrer string caractere por caractere com ponteiro
- `ptr++` avanca para o proximo caractere

### Como pensar

Enquanto o caractere atual nao for `'\0'`:

- comparar `*ptr` com o caractere procurado
- se forem iguais, incrementar contador
- avancar o ponteiro

### Erro classico

Comparar sempre `*str` em vez de comparar o ponteiro que esta caminhando pela string.

## Questao 9 - Inversao de vetor

### O que a questao pedia

- criar `void inverte(int *v, int tamanho);`
- inverter o vetor sem vetor auxiliar
- usando dois ponteiros: inicio e fim

### O que foi aprendido

- usar dois ponteiros apontando para extremos opostos do vetor
- trocar os valores dos extremos
- avancar um para frente e outro para tras

### Como pensar

O processo e:

1. `inicio` aponta para o primeiro elemento
2. `fim` aponta para o ultimo
3. trocar `*inicio` com `*fim`
4. fazer `inicio++` e `fim--`
5. repetir ate eles se encontrarem ou se cruzarem

### Ponto importante

Os movimentos `inicio++` e `fim--` precisam acontecer dentro do laco.

## Questao 10 - Intercalacao de vetores

### O que a questao pedia

- criar `void intercala(int *v1, int *v2, int *v3, int n);`
- formar `v3` com elementos de `v1` e `v2`
- resultado com tamanho `2n`

### O que foi aprendido

- como percorrer dois vetores ao mesmo tempo
- como comparar elementos de dois ponteiros diferentes
- como preencher um terceiro vetor usando ponteiro de saida

### Como pensar

Enquanto ainda houver elementos nos dois vetores:

- comparar `*v1` e `*v2`
- copiar o menor para `*v3`
- avancar o ponteiro correspondente
- avancar `v3`

Depois:

- copiar o restante de `v1`, se houver
- copiar o restante de `v2`, se houver

### Observacao

Essa logica faz sentido para vetores de entrada ordenados.

## Questao 11 - Comparacao de strings

### O que a questao pedia

- criar uma versao propria de `strcmp`
- retornar `0` se iguais
- retornar valor negativo se a primeira for menor
- retornar valor positivo se a primeira for maior

### O que foi aprendido

- comparacao lexicografica de strings
- como andar simultaneamente por duas strings
- como decidir comparacao a partir do primeiro caractere diferente

### Como pensar

Enquanto os caracteres atuais forem iguais e ainda nao tiver chegado ao fim:

- avancar `s1`
- avancar `s2`

Quando parar:

- retornar a diferenca entre os caracteres atuais

### Ideia central

O primeiro ponto onde as strings diferem decide qual e menor ou maior. Se terminarem juntas sem diferenca, sao iguais.

## Resumo final

Ao terminar a lista, os principais aprendizados foram:

- declarar e usar ponteiros com seguranca
- entender a diferenca entre variavel, endereco e conteudo apontado
- percorrer vetores com aritmetica de ponteiros
- percorrer strings ate `'\0'`
- modificar valores por meio de ponteiros
- passar enderecos para funcoes para alterar variaveis externas
- comparar e manipular dados sem depender de indexacao tradicional

## Erros comuns que vale lembrar

- confundir `p` com `*p`
- usar `*p` antes de inicializar o ponteiro
- trocar valor quando a questao queria trocar ponteiro
- trocar ponteiro quando a questao queria trocar valor
- esquecer de avancar o ponteiro dentro do laco
- comparar sempre o primeiro caractere da string em vez do ponteiro que esta andando
- misturar quantidade de elementos com quantidade de bytes ao usar `sizeof`

## Regra mental util para ponteiros

Sempre pergunte:

- essa variavel guarda valor ou guarda endereco?
- eu preciso do endereco (`&`) ou do conteudo apontado (`*`)?
- estou mudando o ponteiro ou estou mudando o valor apontado por ele?

Se essas tres perguntas estiverem claras, a maior parte dos exercicios com ponteiros fica muito mais facil de resolver.
