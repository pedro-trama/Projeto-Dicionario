/*
Integrantes do grupo:
Lucas Notargiacomo Mustaro - RA: 10434914
Pedro Henrique Bettega Trama - RA: 10769933

Turma: 02D11
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS (1000)

//Protótipo das funções
int buscaBinaria(char vetor[][50], char palavra[50], int inicio, int fim);

int insercaoOrdenada(char vetor[][50], char palavra[50], int n);

int main(){

    //Variáveis
    FILE *file;
    char palavra[50];
    char minuscula[50];
    int i;

    //Abrindo o arquivo em modo de leitura
    file = fopen("dicionario.txt", "r");

    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //Faz a leitura de cada palavra
    while(fscanf(file, "%49s", palavra) == 1){
        //Percorre cada caractere da palavra e converte para letras minúsculas
        for(i = 0; palavra[i] != 0; i++){
            minuscula[i] = tolower((unsigned char)palavra[i]);
        }
        //Faz com que a palavra termine com caractere nulo
        minuscula[i] = '\0';

        //Exibe as palavras uma por vez
        printf("%s\n", minuscula);

        //Fecha o arquivo
        fclose(file);
    }

    return 0;
}

//Função da Busca Binária Recursiva
int buscaBinaria(char vetor[][50], char palavra[50], int inicio, int fim){
    //Define o meio do vetor
    int meio = (inicio + fim) / 2;

    //Caso base - o intervalo é vazio
    if(inicio > fim){
        //Retorna -1 pois a palavra não foi encontrada
        return -1;
    }
    //Verifica se a palavra foi encontrada
    else if(strcmp(palavra, vetor[meio]) == 0){
        //Retorna o índice do meio do intervalo
        return meio;
    }
    //Faz a busca na metade à esquerda do elemento central
    else if(strcmp(palavra, vetor[meio]) > 0){
        //Faz a chamada recursiva da função descartando a metade esquerda do vetor
        return buscaBinaria(vetor, palavra, meio + 1, fim);
    }
    //Faz a busca na metade à direita do elemento central
    else {
        return buscaBinaria(vetor, palavra, inicio, meio - 1);
    }
}

//Função da Inserção Ordenada

int insercaoOrdenada(char vetor[][50], char palavra[], int n) {

    // Começa a percorrer o vetor pela última posição ocupada
    int i = n - 1;

    while(i >= 0 && strcmp(vetor[i], palavra) > 0) {

    // Desloca a palavra atual uma posição à direita (destino, origem)
    strcpy(vetor[i+1], vetor[i]);

    i--;

    }

    // Insere a nova palavra na posição correta
    strcpy(vetor[i+1], palavra);

    // Retorna a quantidade de palavras atualizada no vetor
    return n + 1;
}
