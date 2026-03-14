#include <stdio.h>
#include <stdlib.h>
#include "dois_jogadores.c"
#include "um_jogador.c"

int main(){
    int modo;
    system("cls");
    printf("\nEscolha o modo de jogo:\n1-Jogar contra o computador\n2-Jogar contra outro jogador\n0-sair\n--> ");
    scanf("%d", &modo);
    while(modo<0 || modo>2){
        printf("\nModo invalido. Escolha novamente:\n1-Jogar contra o computador\n2-Jogar contra outro jogador\n0-sair\n--> ");
        scanf("%d", &modo);
    }
    if(modo == 1){
        jogo();
        main();
    }
    if(modo == 2){
        jogom();
        main();
    }
    if(modo == 0){
        printf("Saindo do jogo. Obrigado por jogar!\n");
        return 0;
    }
}