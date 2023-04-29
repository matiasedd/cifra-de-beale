# Cifra de Beale

## 1. Introdução
O presente trabalho implementa um algoritmo para a [Cifra de Beale](https://pt.wikipedia.org/wiki/Cifras_de_Beale) como atividade avaliativa para a disciplina de Programação 2. A Cifra de Beale é um algoritmo criptográfico que realiza a codificação e decodificação de mensagens criptografas, a partir de um livro cifra. Este algoritmo implementa três funções de criptografia: a codificação da mensagem original a partir de um livro cifra, a decodificação de uma mensagem criptografada, a partir de um arquivo de chaves e a decodificação de uma mensagem criptografada, a partir de um livro cifra.

Obs.: O algoritmo foi projetado para suportar textos codificados somente em ASCII. Sendo assim, os testes foram realizados integralmente utilizando textos escritos em língua inglesa e codificados em ASCII.

## 2. Estruturas de Dados
A estrutura de dados utilizada para nesse trabalho foi a lista encadeada simples. A lista encadead simples foi empregada em duas estruturas do projeto: a lista de números e a lista de caracteres. A lista de números contém um nó para sua raíz e um inteiro representando o tamanho da lista, cada nó possui seu respectivo valor numérico e um ponteiro para o próximo nó. De forma análoga, a lista de caracteres contém um nó para sua raiz, um caractere com seu respectivo valor, além de um ponteiro para a lista de números, pois cada caractere possui uma lista de números. A lista encadeada simples foi escolhida por ser uma estrutura de dados simples e de fácil implementação.

## 3. Estruturas de Projeto
O projeto foi dividido em quatro sub-diretórios: *libs*, *objects*, *src* e *tests*. O diretório *libs* contém as bibliotecas utilizadas no projeto. O diretório *objects* contém os arquivos objetos gerados durante a compilação do projeto. O diretório *src* contém os arquivos fonte do projeto. O diretório *tests* contém os arquivos de teste de execução do projeto. Além disso, o diretório raiz do projeto contém o arquivo Makefile, que é responsável pela compilação do projeto, o arquivo beale.c, que é o arquivo principal do projeto, e o arquivo README, que é o arquivo de documentação do projeto.

Em cada sub-diretório e com suas respectivas extensões de arquivo, os arquivos que compõe o projeto são:

- *lib_beale*: Responsável por implementar as funções de criptografia e descriptografia da Cifra de Beale.
- *lib_num_list*: Responsável por implementar as funções de manipulação da lista de números.
- *lib_char_list*: Responsável por implementar as funções de manipulação da lista de caracteres.
- *lib_utils*: Responsável por implementar funções utilitárias para o projeto.

## 4. Compilação & Execução

Para compilar o projeto, basta executar o comando make no diretório raiz do projeto. O comando make irá gerar os arquivos objetos e o arquivo executável do projeto. Para executar o projeto, basta executar o comando ./beale no diretório raiz do projeto. O comando ./beale irá executar o arquivo executável do projeto.

Abaixo seguem alguns exemplos de execução do projeto:

- Codificar uma mensagem qualquer contida em um arquivo ASCII usando um livro cifra.
```bash
./beale  -e  -b tests/LivroCifra -m tests/MensagemOriginal -o tests/MensagemCodificada -c tests/ArquivoDeChaves
```

- Decodificar uma mensagem, usando um arquivo de códigos
```bash
./beale  -d  -i tests/MensagemCodificada  -c tests/ArquivoDeChaves  -o tests/MensagemDecodificada
```

- Decodificar uma mensagem usando o livro cifra
```bash
./beale -d -i tests/MensagemCodificada -b tests/LivroCifra -o tests/MensagemDecodificada
```

por [Edison Matias](https://github.com/ej0733).

