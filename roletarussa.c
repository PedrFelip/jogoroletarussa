#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_REVOLVER 6

// Função para girar o tambor do revólver
void girarTambor(int *tambor) {
    srand(time(NULL));
    *tambor = rand() % TAMANHO_REVOLVER;
}

// Função para verificar se o jogador sobrevive ou morre
int atirar(int *tambor, int *bala) {
    if (*tambor == *bala) {
        printf("Você morreu!\n");
        return 0;
    } else {
        printf("Você sobreviveu!\n");
        return 1;
    }
}

int main() {
    int tambor, bala, rodadas = 0;

    // Inicializa o tambor e a posição da bala
    girarTambor(&tambor);
    bala = rand() % TAMANHO_REVOLVER;

    printf("Bem-vindo ao jogo de Roleta Russa!\n");

    // Loop do jogo
    while (1) {
        printf("\nPressione Enter para girar o tambor e puxar o gatilho...\n");
        getchar(); // Espera o jogador pressionar Enter

        girarTambor(&tambor);
        rodadas++;

        printf("Rodada %d: ", rodadas);

        if (!atirar(&tambor, &bala)) {
            printf("Fim de jogo! Você sobreviveu por %d rodadas.\n", rodadas);
            break;
        }

        // Condição de vitória
        if (rodadas >= TAMANHO_REVOLVER - 1) {
            printf("Você chegou às duas últimas rodadas! Deseja atirar? (s/n): \n");
            char escolha;
            scanf(" %c", &escolha);

            if (escolha == 's') {
                if (!atirar(&tambor, &bala)) {
                    printf("Fim de jogo! Você sobreviveu por %d rodadas.\n", rodadas);
                    break;
                } else {
                    printf("Parabéns! Você sobreviveu e ganhou o prêmio!\n");
                    break;
                }
            } else if (escolha == 'n')
            {
               printf("Você optou por não atirar.\n");
               printf("Você saiu vivo mas não vai ganhar prêmio\n");
               break;
            }

        }
    }

    return 0;
}
