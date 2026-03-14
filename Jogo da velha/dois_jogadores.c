#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funcs.c"

void jogom(){
    system("cls");
    int tabuleiro[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int turno=1, linha, coluna, i, j;
    int vitoria=0, cont_emp=0;

    printf("\njogador 1(x) e jogador 2(o)\n");
    Sleep(1500);
    while(vitoria == 0){
        Sleep(150);
        system("cls");
        Sleep(150);
        cont_emp = 0;
        cond_vitoria(tabuleiro, &vitoria);
        printf("Tabuleiro:\n");
        for(i=0;i<3;i++){
            if(i!=0){
                printf("\n");
                printf("-------------");
                printf("\n");
            }
            for(j=0;j<3;j++){
                if(j==0)
                    printf("| ");
                if(tabuleiro[i][j] == 0)
                    printf("-");
                else if(tabuleiro[i][j] == 1){
                    printf("X");
                    cont_emp++;
                }
                else if(tabuleiro[i][j] == 2){
                    printf("O");
                    cont_emp++;
                }
                printf(" | ");
            }        
        }
        if(vitoria == 0){
            if(cont_emp == 9){
                Sleep(1000);
                printf("\nDeu velha!\n");
                Sleep(1700);
                system("cls");
                break;
            }
            if(turno==1){
                Sleep(500);
                printf("\neh a vez do jogador 1(x)!\n");
                Sleep(1000);
                jogada(&linha, &coluna, tabuleiro);
            }
            else if(turno==2){
                Sleep(500);
                printf("\neh a vez do jogador 2(O)!\n");
                Sleep(1000);
                jogada(&linha, &coluna, tabuleiro);
            }
        }
        tabuleiro[linha][coluna] = turno;
        if(turno==1)
            turno=2;
        else if(turno==2)
            turno=1;
        if (vitoria == 1){
            Sleep(1000);
            printf("\nParabens jogador 1(x), voce venceu!\n");
            Sleep(1700);
            system("cls");
            break;
        }
        else if(vitoria == 2){
            Sleep(1000);
            printf("\nParabens jogador 2(o), voce venceu!\n");
            Sleep(1700);
            system("cls");
            break;
        }
    }
}