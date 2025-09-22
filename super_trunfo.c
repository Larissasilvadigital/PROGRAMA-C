#include <stdio.h>

int main() {
    // --------- Carta 1 ---------
    char estado1[20] = "Paraná";
    char codigo1[4] = "A01";
    char cidade1[50] = "CURITIBA";
    unsigned long int populacao1 = 1963724;
    float area1 = 4487.1;
    float pib1 = 128.0; // em bilhões
    int pontosTuristicos1 = 6;

    // --------- Carta 2 ---------
    char estado2[20] = "Tocantins";
    char codigo2[4] = "B01";
    char cidade2[50] = "PALMAS";
    unsigned long int populacao2 = 306296;
    float area2 = 11309.5;
    float pib2 = 11.2; // em bilhões
    int pontosTuristicos2 = 6;

    // ---------  ---------
    char resposta;
    printf("Deseja digitar novos dados para as cartas? (s/n): ");
    scanf(" %c", &resposta);
    getchar(); // 
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
        scanf("%lu", &populacao1);
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
        scanf("%lu", &populacao2);
        printf("Área (km²): ");
        scanf("%f", &area2);
        printf("PIB (bilhões): ");
        scanf("%f", &pib2);
        printf("Número de pontos turísticos: ");
        scanf("%d", &pontosTuristicos2);
    }

    // --------- Cálculos ---------
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;

    float superPoder1 = (float)populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0 / densidade1);
    float superPoder2 = (float)populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0 / densidade2);

    // --------- Comparações ---------
    int popVence = populacao1 > populacao2;
    int areaVence = area1 > area2;
    int pibVence = pib1 > pib2;
    int pontosVence = pontosTuristicos1 > pontosTuristicos2;
    int densidadeVence = densidade1 < densidade2; // menor vence
    int pibPCVence = pibPerCapita1 > pibPerCapita2;
    int superPoderVence = superPoder1 > superPoder2;

    // --------- Exibição dos resultados ---------
    printf("\n=== Carta 1 ===\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Pontos Turísticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n=== Carta 2 ===\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Pontos Turísticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: R$ %.2f\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // --------- Resultados das Comparações ---------
    printf("\n=== Comparação de Cartas ===\n");
    printf("População: Carta 1 venceu (%d)\n", popVence);
    printf("Área: Carta 1 venceu (%d)\n", areaVence);
    printf("PIB: Carta 1 venceu (%d)\n", pibVence);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosVence);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidadeVence);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPCVence);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoderVence);

    return 0;
}
