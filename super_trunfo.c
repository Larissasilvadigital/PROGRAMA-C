#include <stdio.h>

int main() {
    // --------- Variáveis da Carta 1 ---------
    char estado1;
    char codigo1[4];
    char cidade1[50];
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // --------- Variáveis da Carta 2 ---------
    char estado2;
    char codigo2[4];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // --------- Entrada de dados da Carta 1 ---------
    printf("=== Carta 1 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Código da carta: ");
    scanf("%s", codigo1);
    getchar(); // limpa o Enter que ficou no buffer

    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("População: ");
    scanf("%d", &populacao1);
    getchar();

    printf("Área (km²): ");
    scanf("%f", &area1);
    getchar();

    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib1);
    getchar();

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos1);
    getchar();

    // --------- Entrada de dados da Carta 2 ---------
    printf("\n=== Carta 2 ===\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Código da carta: ");
    scanf("%s", codigo2);
    getchar(); // limpa o Enter que ficou no buffer

    printf("Nome da cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("População: ");
    scanf("%d", &populacao2);
    getchar();

    printf("Área (km²): ");
    scanf("%f", &area2);
    getchar();

    printf("PIB (bilhões de reais): ");
    scanf("%f", &pib2);
    getchar();

    printf("Número de pontos turísticos: ");
    scanf("%d", &pontosTuristicos2);
    getchar();

    // --------- Exibição dos dados ---------
    printf("\n=== Dados das Cartas ===\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);

    return 0;
}
