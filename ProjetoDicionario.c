/*
Integrantes do grupo:
Lucas Notargiacomo Mustaro - RA: 10434914
Pedro Henrique Bettega Trama - RA: 10769933

Turma: 02D11
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS (1000) //Número máximo de palavras
#define MAX_TAMANHO (50) //Número máximo da quantidade de caracteres de cada palavra

//Protótipo das funções
int buscaBinaria(char vetor[][50], char palavra[50], int inicio, int fim);

int insercaoOrdenada(char vetor[][50], char palavra[50], int n);

void converterParaMinuscula(char palavra[50]);

int main(){

    //Variáveis
    FILE *file;                                 //Ponteiro do arquivo txt
    char dicionario[MAX_PALAVRAS][MAX_TAMANHO]; //Matriz das palavras
    char palavra[MAX_TAMANHO];                  //Palavra lida do arquivo
    int freqPalavra[MAX_TAMANHO];               //Frequência de cada palavra
    int n = 0;                                  //Número de palavras distintas

    //Abrindo o arquivo em modo de leitura
    file = fopen("dicionario.txt", "r");

    if(file == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //Faz a leitura de cada palavra
    while(fscanf(file, "%49s", palavra) == 1){

        //Chamada da função que converte a palavra em letras minúsculas
        converterParaMinuscula(palavra);

        //Chamada da função da busca binária recursiva
        int pos = buscaBinaria(palavras, palavra, 0, n - 1);

        //Se a palavra estiver contida no dicionário, a frequência aumenta
        if(pos != -1){
            qtdPalavra[pos]++;
        }
        //Caso a palavra não esteja no dicionário, ela é inserida no dicionário 
        else{

            //Verifica se há espaço no dicionário
            if (n < MAX_PALAVRAS){
                
                //Chamada da função de inserção ordenada
                n = insercaoOrdenada(dicionario, freqPalavra, palavra, n);
            }
            else{
                printf("O limite máximo de palavras foi atingido.\n");
                break;
            }
        }
    }
        
    //Fecha o arquivo
    fclose(file);

    //Exibe as palavras e suas frequências
    for(int i = 0; i < n; i++){
        printf("%s, %d\n", dicionario[i], freqPalavra[i]);
    }
    

    return 0;
}

//Função da Busca Binária Recursiva
int buscaBinaria(char vetor[][50], char palavra[50], int inicio, int fim){
    
    //Caso base - o intervalo é vazio
    if(inicio > fim){
        //Retorna -1 pois a palavra não foi encontrada
        return -1;
    }

    //Define o meio do vetor
    int meio = (inicio + fim) / 2;

    //Verifica se a palavra foi encontrada
    if(strcmp(palavra, vetor[meio]) == 0){
        //Retorna o índice do meio do intervalo
        return meio;
    }
    //Faz a busca na metade à direita do elemento central
    else if(strcmp(palavra, vetor[meio]) > 0){
        //Faz a chamada recursiva da função
        return buscaBinaria(vetor, palavra, meio + 1, fim);
    }
    //Faz a busca na metade à esquerda do elemento central
    else {
        return buscaBinaria(vetor, palavra, inicio, meio - 1);
    }
}

//Função da Inserção Ordenada

int insercaoOrdenada(char vetor[][50], int frequencia[], char palavra[], int n) {

    // Começa a percorrer o vetor pela última posição ocupada
    int i = n - 1;

    while(i >= 0 && strcmp(vetor[i], palavra) > 0) {

    // Desloca a palavra atual uma posição à direita (destino, origem)
    strcpy(vetor[i+1], vetor[i]);

    //Desloca a frequência da palavra atual
    frequencia[i+1] = frequencia[i];
     

    i--;

    }

    // Insere a nova palavra na posição correta
    strcpy(vetor[i+1], palavra);

    //Para cada palavra inserida, a frequência inicial será igual a 1
    frequencia[i+1] = 1;

    // Retorna a quantidade de palavras atualizada no vetor
    return n + 1;
}

//Função que converte as palavras lidas em minúsculas
void converterParaMinuscula(char palavra[50]){
    int i;

    //Percorre cada caractere da palavra e converte em letras minúsculas
    for(i = 0; palavra[i] != '\0'; i++){
        palavra[i] = tolower((unsigned char)palavra[i]);
    }

}
