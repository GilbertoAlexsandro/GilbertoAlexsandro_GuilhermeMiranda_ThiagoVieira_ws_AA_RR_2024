# Seminário de Análise de Algoritmos - Problema do Caixeiro Viajante
## Objetivos
- Função de custo e complexidade
- Código em C do algoritmo proposto
- Experimentação com a execução do algoritmo com diferentes entradas e coleta de tempo de execução
 - Gráfico de linha com o tempo de execução em relação a cada entrada e análise da tendência de comportamento assintótico
 - Apresentar um algoritmo que seja mais eficiente, em
   termos de complexidade, do que o algoritmo analisado
   
## Nosso Trabalho
  box.c: Implementa o algoritmo de força bruta para o problema do Caixeiro Viajante (TSP - Traveling Salesman Problem) com permutações.
  
  nearestNeighbour.c: Implementa o algoritmo do Vizinho Mais Próximo para o problema do Caixeiro Viajante.
  
  arquivo `Apresentação Problema do Caixeiro Viajante.pdf` é a apresentação de slides do trabalho.
  
  Requisitos
  
   Compilador C: O código foi testado usando o compilador GCC disponível na plataforma Replit.
   Plataforma Replit: Os códigos foram projetados para serem executados na plataforma Replit.

   Alterar o Número de Cidades:
   
   Modifique a constante V no início do código para alterar o número de cidades. Lembre-se de atualizar também o tamanho da matriz grafo para refletir o novo número de cidades. Aumentar o número de cidades pode alterar significativamente o custo e o tempo de execução.

   Observações
   
   Para box.c: Este algoritmo é eficiente apenas para um número pequeno de cidades devido à sua complexidade factorial. Para mais cidades, considere usar métodos heurísticos ou aproximados.
   Para nearestNeighbour.c: Este algoritmo é mais rápido que o método de força bruta, mas não garante a solução ótima. Pode ser uma boa alternativa para um número maior de cidades.
   
![Gráfico de Força Bruta](https://github.com/GilbertoAlexsandro/GilbertoAlexsandro_GuilhermeMiranda_ThiagoVieira_ws_AA_RR_2024/blob/main/Gr%C3%A1fico%20For%C3%A7a%20Bruta.jpg?raw=true)
![Gráfico de Vizinho Mais Próximo](https://github.com/GilbertoAlexsandro/GilbertoAlexsandro_GuilhermeMiranda_ThiagoVieira_ws_AA_RR_2024/blob/main/Gr%C3%A1fico%20Vizinho%20Mais%20Pr%C3%B3ximo.jpg?raw=true)
![Gráfico de Comparação](https://github.com/GilbertoAlexsandro/GilbertoAlexsandro_GuilhermeMiranda_ThiagoVieira_ws_AA_RR_2024/blob/main/Gr%C3%A1fico%20Compara%C3%A7%C3%A3o.jpg?raw=true)


