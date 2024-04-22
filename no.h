#include <stdio.h>

#define MAX_VERTICES 8

int adj_matrix[MAX_VERTICES][MAX_VERTICES];

// Inicializa a matriz de adjacência
void initializeMatrix(int vertices) {
    int i, j;
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}

// Adiciona uma aresta entre os vértices u e v com peso weight
void addEdge(int u, int v, int weight) {
    adj_matrix[u][v] = weight;
    adj_matrix[v][u] = weight; // Se o grafo for direcionado, remova esta linha
}

// Remove uma aresta entre os vértices u e v
void removeEdge(int u, int v) {
    adj_matrix[u][v] = 0;
    adj_matrix[v][u] = 0; // Se o grafo for direcionado, remova esta linha
}

// Imprime a matriz de adjacência
void printMatrix(int vertices) {
    int i, j;
    printf("Matriz de Adjacência:\n");
    printf("  ");
    for (i = 0; i < vertices; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");
    for (i = 0; i < vertices; i++) {
        printf("%c ", 'A' + i);
        for (j = 0; j < vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, arestas, u, v, weight, i;
    char u_vertex, v_vertex;

    printf("Digite o número de vértices e arestas: ");
    scanf("%d %d", &vertices, &arestas);

    initializeMatrix(vertices);

    printf("Digite as arestas (no formato A B weight):\n");
    for (i = 0; i < arestas; i++) {
        scanf(" %c %c %d", &u_vertex, &v_vertex, &weight);
        u = u_vertex - 'A';
        v = v_vertex - 'A';
        addEdge(u, v, weight);
    }

    printMatrix(vertices);

    return 0;
}