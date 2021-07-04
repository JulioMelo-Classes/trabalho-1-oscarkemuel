# Trabalho-1
Repositório contendo as especificações do Trabalho 1 da disciplina de LP1

## Compilar e Executar
### Compilação
Para compilar o trabalho, rode os seguintes comandos:
```
mkdir build && cd build
cmake ../
make
```
### Execução
Para executar com suas apostas, rode o seguinte comando:
```
./kenobet bets.txt
```

## Testando erros
### Caso 1 - Repetição de números
```
./kenobet test1.txt
```
### Caso 2 - Quantidade de números na aposta superior a 15 números;
```
./kenobet test2.txt
```
### Caso 3 - Presença de caracteres estranhos (exemplo: strings);
```
./kenobet test3.txt
```
### Caso 4 - Formato diferente;
```
./kenobet test4.txt
```
