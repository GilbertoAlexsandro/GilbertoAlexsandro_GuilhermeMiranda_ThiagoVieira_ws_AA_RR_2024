#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 14
#define INF 1000000000 // Valor de custo inviável

// Função para calcular o custo total de um caminho
long long calcularCusto(int path[], long long grafo[V][V]) {
  long long custoTotal = 0;
  for (int i = 0; i < V - 1; i++) {
    custoTotal += grafo[path[i]][path[i + 1]];
  }
  custoTotal += grafo[path[V - 1]][path[0]]; // Retorno à cidade inicial
  return custoTotal;
}

// Função para gerar permutações e encontrar o menor custo
void tsp(int pos, int path[], int visited[], long long grafo[V][V],
         long long *minCost) {
  if (pos == V) {
    long long custoAtual = calcularCusto(path, grafo);
    if (custoAtual < *minCost) {
      *minCost = custoAtual;
    }
    return;
  }

  for (int i = 0; i < V; i++) {
    if (!visited[i]) {
      visited[i] = 1;
      path[pos] = i;
      tsp(pos + 1, path, visited, grafo, minCost);
      visited[i] = 0;
    }
  }
}

int main() { // Definindo um grafo de adjacência estático para 12 cidades
  long long grafo[V][V] = {
      {0, 20, 18, 25, 12, 22, 15, 28, 19, 24, 11, 26, 17, 21},
      {20, 0, 23, 17, 21, 19, 26, 13, 25, 18, 22, 15, 24, 27},
      {18, 23, 0, 20, 16, 24, 11, 27, 22, 19, 25, 17, 21, 26},
      {25, 17, 20, 0, 19, 22, 28, 15, 24, 21, 18, 23, 12, 26},
      {12, 21, 16, 19, 0, 14, 25, 20, 18, 24, 22, 17, 26, 19},
      {22, 19, 24, 22, 14, 0, 17, 26, 21, 20, 18, 25, 13, 24},
      {15, 26, 11, 28, 25, 17, 0, 20, 22, 19, 24, 21, 18, 23},
      {28, 13, 27, 15, 20, 26, 20, 0, 24, 22, 19, 25, 17, 21},
      {19, 25, 22, 24, 18, 21, 22, 24, 0, 20, 17, 26, 15, 23},
      {24, 18, 19, 21, 24, 20, 24, 22, 20, 0, 23, 17, 26, 19},
      {11, 22, 25, 18, 22, 18, 24, 19, 17, 23, 0, 21, 26, 20},
      {26, 15, 17, 23, 26, 25, 21, 25, 26, 17, 21, 0, 19, 24},
      {17, 24, 21, 12, 26, 19, 18, 17, 26, 26, 21, 19, 0, 23},
      {21, 27, 26, 26, 19, 24, 23, 21, 23, 19, 20, 24, 23, 0}};

  int path[V];             // Array para armazenar a sequência das cidades
  int visited[V] = {0};    // Array para controlar as cidades visitadas
  long long minCost = INF; // Inicializando o custo mínimo como INF

  visited[0] = 1; // Começando pela cidade 0
  path[0] = 0;

  struct timespec start_time, end_time;

  clock_gettime(CLOCK_MONOTONIC, &start_time);

  tsp(1, path, visited, grafo, &minCost);

  clock_gettime(CLOCK_MONOTONIC, &end_time);

  double execution_time = (end_time.tv_sec - start_time.tv_sec) +
                          (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

  printf("Custo mínimo encontrado: %lld\n", minCost);
  printf("Tempo de execução: %f segundos\n", execution_time);

  return 0;
}