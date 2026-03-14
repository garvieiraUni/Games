#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int cond_vitoria(int tab[3][3], int*vit){
    int i, j; 
    // Verifica linhas
    for (i = 0; i < 3; i++) {
        if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2] && tab[i][0] == 1){
            *vit = 1;
            break;
        }
        else if(tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2] && tab[i][0] == 2){
            *vit = 2;
            break;
        }
    }
    // Verifica colunas
    for (j = 0; j < 3; j++) {
        if (tab[0][j] == tab[1][j] && tab[1][j] == tab[2][j] && tab[0][j] == 1){ 
            *vit = 1;
            break;
        }
        else if (tab[0][j] == tab[1][j] && tab[1][j] == tab[2][j] && tab[0][j] == 2){
            *vit = 2;
            break;
        }
    }
    // Verifica diagonais
    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[0][0] == 1)
        *vit = 1;
    else if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2] && tab[0][0] == 2)
        *vit = 2;
    else if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0] && tab[0][2] == 1) 
        *vit = 1;
    else if (tab[0][2] == tab[1][1] && tab[1][1] == tab[2][0] && tab[0][2] == 2)
        *vit = 2;
}

int jogada(int*l, int*c, int tab[3][3]){
    int linha, coluna, valida=1;
    while(valida == 1){
        printf("escolha a linha(1-3): ");
        scanf("%d", &linha);
        while(linha<1||linha>3){
            printf("linha %d invalida, jogue novamente: ", linha);
            scanf("%d", &linha);
        }
        printf("escolha a coluna(1-3): ");
        scanf("%d", &coluna);
        while(coluna<1||coluna>3){
            printf("coluna %d invalida, jogue novamente: ", coluna);
            scanf("%d", &coluna);
        }
        if(tab[linha-1][coluna-1] == 0){
            system("cls");
            printf("jogada computada!\n");
            Sleep(800);
            valida = 0;
    }
        else
            printf("posicao ocupada, jogue novamente!\n");
    }
    *l = linha-1;
    *c = coluna-1;
}

int dificuldade(){
    int dif;
    printf("Escolha a dificuldade:\n1-Facil\n2-Medio\n3-Dificil\n--> ");
    scanf("%d", &dif);
    while(dif<1 || dif>3){
        printf("Dificuldade invalida. Escolha novamente:\n1-Facil\n2-Medio\n3-Dificil\n--> ");
        scanf("%d", &dif);
    }
    return dif;
}

int figura(int *fig_bot){
    int fig;
    printf("Escolha a figura:\n1-X\n2-O\n--> ");
    scanf("%d", &fig);
    while(fig<1 || fig>2){
        printf("Figura invalida. Escolha novamente:\n1-X\n2-O\n--> ");
        scanf("%d", &fig);
    }
    if(fig == 1){
        system("cls");
        printf("Voce escolheu X!\n");
        Sleep(1700);
        system("cls");
    }
    else if(fig == 2){
        system("cls");
        printf("Voce escolheu O!\n");
        Sleep(1700);
        system("cls");
    }
    if(fig==1)
        *fig_bot=2;
    else
        *fig_bot=1;
    return fig;
}