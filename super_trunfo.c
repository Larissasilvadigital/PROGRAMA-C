#include <stdio.h>

int main() {
    // --------- Carta 1 ---------
    char estado1[20] = "Paraná";
    char codigo1[4] = "A01";
    char cidade1[50] = "CURITIBA";
    int populacao1 = 1963724;
    float area1 = 4487.1;
    float pib1 = 128.0; // em bilhões
    int pontosTuristicos1 = 6;

    // --------- Carta 2 ---------
    char estado2[20] = "Tocantins";
    char codigo2[4] = "B01";
    char cidade2[50] = "PALMAS";
    int populacao2 = 306296;
    float area2 = 11309.5;
    float pib2 = 11.2; // em bilhões
    int pontosTuristicos2 = 6;

    // --------- Perguntar se quer digitar novos dados ---------
    char resposta;
    printf("Deseja digitar novos dados para as cartas? (s/n): ");
    scanf(" %c", &resposta);
    getchar(); // limpa o Enter

    if(resposta == 's' || resposta == 'S') {
        // Carta 1
        printf("\n=== Carta 1 ===\n");
        printf("Estado: ");
        scanf("%19s", estado1);
        printf("Código da carta: ");
        scanf("%3s", codigo1); getchar();
        printf("Nome da cidade: ");
        scanf(" %[^\n]", cidade1);
        printf("População: ");
        scanf("%d", &populacao1);
        printf("Área (km²): ");
        scanf("%f", &area1);
        printf("PIB (bilhões): ");
        scanf("%f", &pib1);
        printf("Número de pontos turísticos: ");
        scanf("%d", &pontosTuristicos1);

        // Carta 2
        printf("\n=== Carta 2 ===\n");
        printf("Estado: ");
        scanf("%19s", estado2);
        printf("Código da carta: ");
        scanf("%3s", codigo2); getchar();
        printf("Nome da cidade: ");
        scanf(" %[^\n]", cidade2);
        printf("População: ");
        scanf("%d", &populacao2);
        printf("Área (km²): ");
        scanf("%f", &area2);
        printf("PIB (bilhões): ");
        scanf("%f", &pib2);
        printf("Número de pontos turísticos: ");
        scanf("%d", &pontosTuristicos2);
    }

    // --------- Cálculos ---------
    float densidade1 = populacao1 / area1;
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    // --------- Exibição dos resultados ---------
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);

    return 0;
}

