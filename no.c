/*
Necessario:

Adicionar ou remover nós -- add pronto / remove pronto
Função para verificar a existência de um caminho entre dois nós -- pronto
Uma função para imprimir todas as arestas do grafo. EX: A - 5 - B -- pronto
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_NOS 8

// Definição da estrutura do nó
struct No {
    char letra;
};

typedef struct No no;

// Definição da estrutura do grafo
struct Grafo {
    no* nos[NUM_NOS]; // Array de nós
    int matrizAdjacencia[NUM_NOS][NUM_NOS]; // Matriz de adjacência
};

typedef struct Grafo grafo;

// Função para criar um novo nó
no* criaNo(char letra) {
    no* nova = (no*)malloc(sizeof(no));
    nova->letra = letra;
    return nova;
}


void verificaAresta(grafo *grafo, char no1, char no2){
    int index1 = no1 - 'A';
    int index2 = no2 - 'A';
    if(grafo->matrizAdjacencia[index1][index2] != 0 || grafo->matrizAdjacencia[index2][index1] != 0){
        printf("Existe um caminho!\n");
        printf("%c - %d - %c\n", no1, grafo->matrizAdjacencia[index1][index2], no2);
    }else{
        printf("Nao existe caminho.\n");
    }
}

// Função para criar um novo grafo
grafo* criaGrafo() {
    grafo *novo;
    novo = (grafo *) malloc(sizeof(grafo));
    
    // Inicializando todos os nós como NULL
    for (int i = 0; i < NUM_NOS; i++) {
        novo->nos[i] = NULL;
    }
    
    // Inicializando a matriz de adjacência com 0
    for (int i = 0; i < NUM_NOS; i++) {
        for (int j = 0; j < NUM_NOS; j++) {
            novo->matrizAdjacencia[i][j] = 0;
        }
    }
    
    return novo;
}

// Função para adicionar uma aresta valorada entre dois nós
void adicionaAresta(grafo* grafo, char no1, char no2, int valor) {
    int index1 = no1 - 'A';
    int index2 = no2 - 'A';
    if(grafo->nos[index1] != NULL || grafo->nos[index2] != NULL){
        grafo->matrizAdjacencia[index1][index2] = valor;
        grafo->matrizAdjacencia[index2][index1] = valor;
    }
   return; 
}

// Função para remover uma aresta valorada entre dois nós
void removeAresta(grafo* grafo, int index){
    for (int i = 0; i < NUM_NOS; i++) {
        for (int j = 0; j < NUM_NOS; j++) {
            if(grafo->matrizAdjacencia[i][index] != 0 || grafo->matrizAdjacencia[index][j] != 0){
                grafo->matrizAdjacencia[i][index] = 0;
                grafo->matrizAdjacencia[index][j] = 0;
            }
        }
    }
    return;
}

// Função para remover um nó existente
grafo* removeNo(grafo* grafo, char letra){
    int index = letra - 'A';
    grafo->nos[index] = NULL;
    if(grafo->nos[index] == NULL){
        removeAresta(grafo, index);
    }
}

// Função para imprimir os caminhos do grafo
void imprimeCaminhos(grafo* grafo) {
    for (int i = 0; i < NUM_NOS; i++) {
        for (int j = 0; j < NUM_NOS; j++) {
            if(grafo->matrizAdjacencia[i][j] != 0){
                printf("%c - %d - %c\n\n", 'A' + i, grafo->matrizAdjacencia[i][j], 'A' + j);
            }
        }
    }
    return;
}

int main() {
    grafo* grafo = criaGrafo();
    
    // Criando os nós
    for (char label = 'A'; label < 'A' + NUM_NOS; label++) {
        grafo->nos[label - 'A'] = criaNo(label);
    }
    
    // Adicionando as arestas com seus valores
    adicionaAresta(grafo, 'A', 'B', 5);
    adicionaAresta(grafo, 'A', 'E', 6);
    adicionaAresta(grafo, 'B', 'E', 1);
    adicionaAresta(grafo, 'B', 'G', 10);
    adicionaAresta(grafo, 'C', 'D', 8);
    adicionaAresta(grafo, 'C', 'E', 2);
    adicionaAresta(grafo, 'C', 'F', 5);
    adicionaAresta(grafo, 'C', 'G', 10);
    adicionaAresta(grafo, 'D', 'F', 20);
    adicionaAresta(grafo, 'D', 'G', 5);
    adicionaAresta(grafo, 'D', 'H', 2);
    adicionaAresta(grafo, 'E', 'G', 8);
    adicionaAresta(grafo, 'F', 'H', 20);

    // Verificando existencia de um caminho entre A e H
    verificaAresta(grafo, 'A', 'H');
    printf("\n");

    // Verificando existencia de um caminho entre A e B
    verificaAresta(grafo, 'A', 'B');
    printf("\n");
    
    // Imprimindo a matriz de adjacência
    printf("Matriz de Adjacencia:\n\n");
    imprimeCaminhos(grafo);
    printf("--------------------------------\n");
    
    // Imprimindo a matriz de adjacência sem H
    removeNo(grafo, 'H');
    printf("Matriz de adjacencia:\n\n");
    imprimeCaminhos(grafo);

    return 0;
}
