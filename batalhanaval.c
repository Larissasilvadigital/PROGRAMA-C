#include <stdio.h>

#define TAM_TAB 10     // Tamanho do tabuleiro: 10x10
#define TAM_HAB 5      // Tamanho das matrizes de habilidade: 5x5

#define AGUA 0         // Representa água
#define NAVIO 3        // Representa partes dos navios
#define HABILIDADE 5   // Representa área afetada por habilidades

/*  ==========================
    FUNÇÕES AUXILIARES GERAIS
    ========================== */

// Retorna o valor absoluto de um inteiro (para usar nas habilidades)
int absoluto(int x) {
    return (x < 0) ? -x : x;
}

// Inicializa todo o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Imprime o tabuleiro 10x10 de forma organizada
void imprimirTabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("   ");
    for (int j = 0; j < TAM_TAB; j++) {
        printf("%2d ", j);   // Índice das colunas
    }
    printf("\n");

    for (int i = 0; i < TAM_TAB; i++) {
        printf("%2d ", i);   // Índice das linhas
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/*  ==========================
    POSICIONAMENTO DE NAVIOS
    NÍVEL NOVATO + AVENTUREIRO
    ========================== */

/*
 * Função genérica que verifica se é possível posicionar um navio
 * em determinadas coordenadas. Se for possível, o navio é colocado.
 * Retorna 1 se deu certo, 0 se teve algum problema (fora do tabuleiro ou sobreposição).
 */
int posicionarNavioHorizontal(int tabuleiro[TAM_TAB][TAM_TAB],
                              int linha, int colunaInicial, int tamanho) {
    // Validação de limites
    if (linha < 0 || linha >= TAM_TAB) {
        return 0;
    }
    if (colunaInicial < 0 || colunaInicial + tamanho > TAM_TAB) {
        return 0;
    }

    // Verifica sobreposição
    for (int j = colunaInicial; j < colunaInicial + tamanho; j++) {
        if (tabuleiro[linha][j] != AGUA) {
            return 0; // Já tem algo aqui
        }
    }

    // Posiciona o navio
    for (int j = colunaInicial; j < colunaInicial + tamanho; j++) {
        tabuleiro[linha][j] = NAVIO;
    }

    return 1;
}

int posicionarNavioVertical(int tabuleiro[TAM_TAB][TAM_TAB],
                            int linhaInicial, int coluna, int tamanho) {
    // Validação de limites
    if (coluna < 0 || coluna >= TAM_TAB) {
        return 0;
    }
    if (linhaInicial < 0 || linhaInicial + tamanho > TAM_TAB) {
        return 0;
    }

    // Verifica sobreposição
    for (int i = linhaInicial; i < linhaInicial + tamanho; i++) {
        if (tabuleiro[i][coluna] != AGUA) {
            return 0;
        }
    }

    // Posiciona o navio
    for (int i = linhaInicial; i < linhaInicial + tamanho; i++) {
        tabuleiro[i][coluna] = NAVIO;
    }

    return 1;
}

/*
 * Diagonal principal: linha e coluna aumentam juntas (ex: (0,0) -> (1,1) -> (2,2))
 */
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM_TAB][TAM_TAB],
                                     int linhaInicial, int colunaInicial, int tamanho) {
    // Validação de limites
    if (linhaInicial < 0 || colunaInicial < 0) {
        return 0;
    }
    if (linhaInicial + tamanho > TAM_TAB || colunaInicial + tamanho > TAM_TAB) {
        return 0;
    }

    // Verifica sobreposição
    for (int k = 0; k < tamanho; k++) {
        int i = linhaInicial + k;
        int j = colunaInicial + k;
        if (tabuleiro[i][j] != AGUA) {
            return 0;
        }
    }

    // Posiciona o navio
    for (int k = 0; k < tamanho; k++) {
        int i = linhaInicial + k;
        int j = colunaInicial + k;
        tabuleiro[i][j] = NAVIO;
    }

    return 1;
}

/*
 * Diagonal secundária: linha aumenta e coluna diminui (ex: (0,9) -> (1,8) -> (2,7))
 */
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM_TAB][TAM_TAB],
                                      int linhaInicial, int colunaInicial, int tamanho) {
    // Validação de limites
    if (linhaInicial < 0 || colunaInicial < 0 || colunaInicial >= TAM_TAB) {
        return 0;
    }
    if (linhaInicial + tamanho > TAM_TAB) {
        return 0;
    }
    if (colunaInicial - (tamanho - 1) < 0) {
        return 0;
    }

    // Verifica sobreposição
    for (int k = 0; k < tamanho; k++) {
        int i = linhaInicial + k;
        int j = colunaInicial - k;
        if (tabuleiro[i][j] != AGUA) {
            return 0;
        }
    }

    // Posiciona o navio
    for (int k = 0; k < tamanho; k++) {
        int i = linhaInicial + k;
        int j = colunaInicial - k;
        tabuleiro[i][j] = NAVIO;
    }

    return 1;
}

/*  ==========================
    MATRIZES DE HABILIDADE
    NÍVEL MESTRE
    ========================== */

/*
 * Cria uma matriz 5x5 em forma de CONE apontando para baixo.
 * O topo do cone é no centro da primeira linha (linha 0, coluna 2).
 * Usamos 1 para área afetada e 0 para não afetada.
 */
void criarHabilidadeCone(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2; // para TAM_HAB = 5, centro = 2

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            // Vamos formar um triângulo nas 3 primeiras linhas (0, 1, 2)
            if (i <= 2 && absoluto(j - centro) <= i) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

/*
 * Cria uma matriz 5x5 em forma de CRUZ.
 * Cruz no centro: linha central e coluna central preenchidas com 1.
 */
void criarHabilidadeCruz(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

/*
 * Cria uma matriz 5x5 em forma de OCTAEDRO (losango visto de frente).
 * Usamos a condição: |i - centro| + |j - centro| <= 2
 */
void criarHabilidadeOctaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (absoluto(i - centro) + absoluto(j - centro) <= 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

/*
 * Aplica uma matriz de habilidade 5x5 no tabuleiro 10x10,
 * centralizando a habilidade no ponto de origem (linha, coluna).
 * Onde a habilidade for 1, marcamos o tabuleiro com HABILIDADE (5),
 * desde que esteja dentro dos limites do tabuleiro.
 */
void aplicarHabilidade(int tabuleiro[TAM_TAB][TAM_TAB],
                       int habilidade[TAM_HAB][TAM_HAB],
                       int origemLinha, int origemColuna) {
    int centro = TAM_HAB / 2;

    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int linhaTab = origemLinha + (i - centro);
                int colunaTab = origemColuna + (j - centro);

                // Verifica se está dentro do tabuleiro 10x10
                if (linhaTab >= 0 && linhaTab < TAM_TAB &&
                    colunaTab >= 0 && colunaTab < TAM_TAB) {

                    // Marca área afetada pela habilidade com 5
                    tabuleiro[linhaTab][colunaTab] = HABILIDADE;
                }
            }
        }
    }
}

int main(void) {
    // =============================
    // Declaração do tabuleiro
    // =============================
    int tabuleiro[TAM_TAB][TAM_TAB];

    // "Navios" como vetores unidimensionais (nível novato)
    // Aqui usamos apenas como representação conceitual: cada posição vale 3.
    int navioHorizontal[3] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[3]   = {NAVIO, NAVIO, NAVIO};

    // Matrizes de habilidades (nível mestre)
    int habilidadeCone[TAM_HAB][TAM_HAB];
    int habilidadeCruz[TAM_HAB][TAM_HAB];
    int habilidadeOctaedro[TAM_HAB][TAM_HAB];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // =============================
    // NÍVEL NOVATO:
    // 2 navios: 1 horizontal, 1 vertical
    // =============================
    int tamanhoNavio = 3;

    // Coordenadas fixas definidas no código (sem entrada do usuário)
    // Horizontal: linha 1, colunas 1,2,3
    posicionarNavioHorizontal(tabuleiro, 1, 1, tamanhoNavio);

    // Vertical: coluna 5, linhas 4,5,6
    posicionarNavioVertical(tabuleiro, 4, 5, tamanhoNavio);

    // =============================
    // NÍVEL AVENTUREIRO:
    // + 2 navios na diagonal (total 4 navios)
    // =============================

    // Diagonal principal: (0,7), (1,8), (2,9)
    posicionarNavioDiagonalPrincipal(tabuleiro, 0, 7, tamanhoNavio);

    // Diagonal secundária: (7,2), (8,1)? não! vamos usar forma subindo:
    // (7,2), (6,3), (5,4)
    posicionarNavioDiagonalSecundaria(tabuleiro, 7, 2, tamanhoNavio);

    printf("Tabuleiro com navios posicionados (Nível Novato + Aventureiro):\n");
    imprimirTabuleiro(tabuleiro);

    // =============================
    // NÍVEL MESTRE:
    // Habilidades: cone, cruz, octaedro
    // =============================

    // Cria as matrizes de habilidade usando condicionais e loops aninhados
    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);

    // Definimos pontos de origem para cada habilidade diretamente no código
    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 5, origemCruzColuna = 5;
    int origemOctLinha  = 7, origemOctColuna  = 7;

    // Aplica cada habilidade sobre o tabuleiro
    aplicarHabilidade(tabuleiro, habilidadeCone, origemConeLinha, origemConeColuna);
    aplicarHabilidade(tabuleiro, habilidadeCruz, origemCruzLinha, origemCruzColuna);
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, origemOctLinha, origemOctColuna);

    printf("\nTabuleiro com navios (3) e habilidades (5) aplicadas (Nível Mestre):\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}

