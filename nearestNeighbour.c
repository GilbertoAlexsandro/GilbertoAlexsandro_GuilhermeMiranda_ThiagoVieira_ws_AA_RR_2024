#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 5
#define INF 1000000000 // Valor de custo inviável

// Função para encontrar o vizinho mais próximo
int vizinhoMaisProximo(int grafo[V][V], int start, int *caminho) {
    int visitado[V] = {0};
    int custoTotal = 0;
    int atual = start;

    visitado[start] = 1;
    caminho[0] = start;

    for (int i = 1; i < V; i++) {
        int proxCidade = -1;
        int menorDist = INF;  // Inicializa com INF para garantir que encontramos um mínimo válido

        for (int j = 0; j < V; j++) {
            // Verifica se a cidade não foi visitada e se o caminho não é inviável (INF)
            if (!visitado[j] && grafo[atual][j] < menorDist && grafo[atual][j] != INF) {
                menorDist = grafo[atual][j];
                proxCidade = j;
            }
        }

        // Se não encontrou um caminho viável, o grafo pode estar desconectado
        if (proxCidade == -1) {
            fprintf(stderr,
                    "Erro: Não foi possível encontrar uma cidade vizinha não visitada a partir da cidade %d.\n",
                    atual);
            exit(EXIT_FAILURE);
        }

        visitado[proxCidade] = 1;
        caminho[i] = proxCidade;
        custoTotal += menorDist;
        atual = proxCidade;
    }

    caminho[V] = start;  // Retorno à cidade inicial
    custoTotal += grafo[atual][start];  // Adiciona o custo de voltar à cidade inicial

    return custoTotal;
}

int main() {
    int grafo[V][V] = {
        {0, 10, 20, 30, 25},
        {10, 0, 15, 35, 20},
        {20, 15, 0, 30, 28},
        {30, 35, 30, 0, 22},
        {25, 20, 28, 22, 0}
    };

    // Captura o tempo de início
    clock_t start_time = clock();

    int caminho[V + 1];
    int custoInicial = vizinhoMaisProximo(grafo, 0, caminho);

    // Captura o tempo de término
    clock_t end_time = clock();

    // Calcula o tempo de execução em segundos
    double execution_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Custo inicial (Vizinho Mais Próximo): %d\n", custoInicial);
    printf("Caminho inicial: ");
    for (int i = 0; i <= V; i++) {
        printf("%d ", caminho[i]);
    }
    printf("\n");

    // Exibe o tempo de execução
    printf("Tempo de execução: %f segundos\n", execution_time);

    return 0;
}