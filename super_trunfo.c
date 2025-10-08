#include <stdio.h>
#include <string.h>

// -----------------------------
// Definição do enum para atributos
typedef enum {
    ATTR_POPULACAO,
    ATTR_AREA,
    ATTR_PIB,
    ATTR_PONTOS_TURISTICOS,
    ATTR_DENSIDADE,
    ATTR_PIB_PER_CAPITA
} Attribute;

// Função para ler uma opção de menu
int lerOpcaoMenu() {
    char buf[16];
    if (fgets(buf, sizeof(buf), stdin) == NULL) return -1;
    int opc;
    if (sscanf(buf, "%d", &opc) != 1) return -1;
    return opc;
}

// Função para comparar dois valores seguindo a regra
int compararSeguindoRegra(Attribute a, double v1, double v2) {
    if (a == ATTR_DENSIDADE) {  // menor vence
        if (v1 < v2) return 1;
        else if (v2 < v1) return 2;
        else return 0;
    } else {  // maior vence
        if (v1 > v2) return 1;
        else if (v2 > v1) return 2;
        else return 0;
    }
}

// Função para comparar um atributo escolhido pelo usuário
int comparacaoInterativa(
    char cidade1[], char codigo1[], unsigned long populacao1, float area1, float pib1, int pontos1, double densidade1, double pibPerCapita1,
    char cidade2[], char codigo2[], unsigned long populacao2, float area2, float pib2, int pontos2, double densidade2, double pibPerCapita2
) {
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade (menor vence)\n6 - PIB per capita\nOpção: ");

    int opc = lerOpcaoMenu();
    Attribute a;
    switch(opc) {
        case 1: a = ATTR_POPULACAO; break;
        case 2: a = ATTR_AREA; break;
        case 3: a = ATTR_PIB; break;
        case 4: a = ATTR_PONTOS_TURISTICOS; break;
        case 5: a = ATTR_DENSIDADE; break;
        case 6: a = ATTR_PIB_PER_CAPITA; break;
        default:
            printf("Opção inválida!\n");
            return 0; // sem vitória
    }

    double v1=0, v2=0;
    switch(a) {
        case ATTR_POPULACAO: v1 = populacao1; v2 = populacao2; break;
        case ATTR_AREA: v1 = area1; v2 = area2; break;
        case ATTR_PIB: v1 = pib1; v2 = pib2; break;
        case ATTR_PONTOS_TURISTICOS: v1 = pontos1; v2 = pontos2; break;
        case ATTR_DENSIDADE: v1 = densidade1; v2 = densidade2; break;
        case ATTR_PIB_PER_CAPITA: v1 = pibPerCapita1; v2 = pibPerCapita2; break;
    }

    printf("\nCarta 1 (%s): %.2f\nCarta 2 (%s): %.2f\n", cidade1, v1, cidade2, v2);

    int resultado = compararSeguindoRegra(a, v1, v2);
    if (resultado == 1) printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    else if (resultado == 2) printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    else printf("Resultado: Empate!\n");

    return resultado;
}

// -----------------------------
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

    // --------- Pergunta sobre digitar novos dados ---------
    char resposta;
    printf("Deseja digitar novos dados para as cartas? (s/n): ");
    scanf(" %c", &resposta);
    getchar();
    if(resposta == 's' || resposta == 'S') {
        // Carta 1
        printf("\n=== Carta 1 ===\n");
        printf("Estado: "); scanf("%19s", estado1);
        printf("Código da carta: "); scanf("%3s", codigo1); getchar();
        printf("Nome da cidade: "); scanf(" %[^\n]", cidade1);
        printf("População: "); scanf("%lu", &populacao1);
        printf("Área (km²): "); scanf("%f", &area1);
        printf("PIB (bilhões): "); scanf("%f", &pib1);
        printf("Número de pontos turísticos: "); scanf("%d", &pontosTuristicos1);

        // Carta 2
        printf("\n=== Carta 2 ===\n");
        printf("Estado: "); scanf("%19s", estado2);
        printf("Código da carta: "); scanf("%3s", codigo2); getchar();
        printf("Nome da cidade: "); scanf(" %[^\n]", cidade2);
        printf("População: "); scanf("%lu", &populacao2);
        printf("Área (km²): "); scanf("%f", &area2);
        printf("PIB (bilhões): "); scanf("%f", &pib2);
        printf("Número de pontos turísticos: "); scanf("%d", &pontosTuristicos2);
    }

    // --------- Cálculos ---------
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;
    float pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;
    float superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0 / densidade1);
    float superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0 / densidade2);

    // --------- Exibição ---------
    printf("\n=== Carta 1 ===\nEstado: %s\nCódigo: %s\nCidade: %s\nPopulação: %lu\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\nSuper Poder: %.2f\n",
           estado1, codigo1, cidade1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1, superPoder1);
    printf("\n=== Carta 2 ===\nEstado: %s\nCódigo: %s\nCidade: %s\nPopulação: %lu\nÁrea: %.2f\nPIB: %.2f\nPontos Turísticos: %d\nDensidade: %.2f\nPIB per Capita: %.2f\nSuper Poder: %.2f\n",
           estado2, codigo2, cidade2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2, superPoder2);

    // --------- Resultados automáticos ---------
    printf("\n=== Comparação Automática ===\n");
    printf("População: Carta 1 venceu (%d)\n", populacao1>populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area1>area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1>pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosTuristicos1>pontosTuristicos2);
    printf("Densidade: Carta 1 venceu (%d)\n", densidade1<densidade2);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pibPerCapita1>pibPerCapita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", superPoder1>superPoder2);

    // --------- Modo Mestre ---------
    int vitorias1=0, vitorias2=0, rodadas=0;
    printf("\n=== Nível Mestre: Jogar várias rodadas ===\n");
    while(1) {
        printf("\nDeseja jogar uma rodada? (1-Sim / 0-Sair): ");
        int opc = lerOpcaoMenu();
        if(opc == 0) break;
        rodadas++;
        int resultado = comparacaoInterativa(cidade1, codigo1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1,
                                             cidade2, codigo2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2);
        if(resultado == 1) vitorias1++;
        else if(resultado == 2) vitorias2++;
        else printf("Empate nesta rodada!\n");
    }

    if(rodadas > 0) {
        printf("\n=== Placar Final ===\n");
        printf("%s: %d vitórias\n", cidade1, vitorias1);
        printf("%s: %d vitórias\n", cidade2, vitorias2);
        if(vitorias1 > vitorias2) printf("Carta 1 (%s) é a grande vencedora!\n", cidade1);
        else if(vitorias2 > vitorias1) printf("Carta 2 (%s) é a grande vencedora!\n", cidade2);
        else printf("O jogo terminou empatado!\n");
    }

    return 0;
}
