#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <windows.h> // ADICIONADO: Necessário para SetConsoleOutputCP

// Requisito: Struct Territorio
typedef struct {
    char nome[30];
    char cor[15];
    int tropas;
} Territorio;

// --- PROTÓTIPOS DAS FUNÇÕES ---
void cadastrarTerritorios(Territorio* mapa, int quantidade);
void exibirMapa(Territorio* mapa, int quantidade);
void atacar(Territorio* atacante, Territorio* defensor);
void liberarMemoria(Territorio* mapa);

int main() {
    // Configura o console para UTF-8 (resolve acentuação no VS)
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    setlocale(LC_ALL, "Portuguese_Brazil.65001");

    srand((unsigned int)time(NULL));

    int qtd;
    Territorio* mapa = NULL;

    printf("========================================\n");
    printf("    WAR ESTRUTURADO - FASE DE ATAQUE    \n");
    printf("========================================\n\n");

    printf("Quantos territórios deseja gerenciar? ");
    if (scanf("%d", &qtd) != 1) return 1;

    // Alocação Dinâmica com calloc (zera a memória)
    mapa = (Territorio*)calloc(qtd, sizeof(Territorio));

    if (mapa == NULL) {
        printf("Erro crítico: Falha na alocação de memória.\n");
        return 1;
    }

    cadastrarTerritorios(mapa, qtd);

    int continuar = 1;
    while (continuar) {
        exibirMapa(mapa, qtd);

        int idAtacante, idDefensor;
        printf("\n--- INICIAR ATAQUE ---\n");
        printf("ID do Atacante (1 a %d): ", qtd);
        scanf("%d", &idAtacante);
        printf("ID do Defensor (1 a %d): ", qtd);
        scanf("%d", &idDefensor);

        if (idAtacante < 0 || idAtacante >= qtd || idDefensor < 0 || idDefensor >= qtd) {
            printf("\n[AVISO] IDs inválidos!\n");
        }
        else if (idAtacante == idDefensor) {
            printf("\n[AVISO] Um território não pode atacar a si mesmo!\n");
        }
        else if (strcmp(mapa[idAtacante].cor, mapa[idDefensor].cor) == 0) {
            printf("\n[AVISO] Territórios da mesma cor não se atacam!\n");
        }
        else {
            atacar(&mapa[idAtacante], &mapa[idDefensor]);
        }

        printf("\nDeseja realizar outro ataque? (1-Sim / 0-Sair): ");
        scanf("%d", &continuar);
    }

    liberarMemoria(mapa);
    printf("\nMemória liberada. Fim de jogo!\n");

    return 0;
}

// --- IMPLEMENTAÇÃO DAS FUNÇÕES ---

void cadastrarTerritorios(Territorio* mapa, int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("\n>>> Cadastro do Território %d <<<\n", i+1);
        printf("Nome: ");
        scanf("%s", mapa[i].nome);
        printf("Cor do Exército: ");
        scanf("%s", mapa[i].cor);
        printf("Quantidade de Tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

void exibirMapa(Territorio* mapa, int quantidade) {
    printf("\n================ MAPA ATUAL ================\n");
    for (int i = 0; i < quantidade; i++) {
        printf("ID: %d | %-15s | Cor: %-10s | Tropas: %d\n",
            i, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("============================================\n");
}

void atacar(Territorio* atacante, Territorio* defensor) {
    int dadoAtaque = (rand() % 6) + 1;
    int dadoDefesa = (rand() % 6) + 1;

    printf("\nCOMBATE: %s (%d) vs %s (%d)\n", atacante->nome, dadoAtaque, defensor->nome, dadoDefesa);

    if (dadoAtaque > dadoDefesa) {
        printf(">>> VITÓRIA! %s conquistou %s!\n", atacante->nome, defensor->nome);

        // Atualização via ponteiros (Operador ->)
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas -= defensor->tropas;
    }
    else {
        printf(">>> DERROTA! A defesa de %s resistiu.\n", defensor->nome);
        if (atacante->tropas > 1) {
            atacante->tropas--;
        }
    }
}

void liberarMemoria(Territorio* mapa) {
    if (mapa != NULL) {
        free(mapa);
    }
}