#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "fake_IA.c"

void jogo(){
    system("cls");
    int tabuleiro[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    int turno=1, linha, coluna, i, j;
    int vitoria=0, cont_emp=0, dif, fig, fig_bot, cont=1, caso=0;

    dif = dificuldade();
    fig = figura(&fig_bot);
    while(vitoria == 0){
        system("cls");
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
                if(turno==fig){
                    printf("\neh a vez do jogador(x)!\n");
                }
                else{
                    printf("\neh a vez do computador(x)!\n");
                }
                Sleep(1500);
                if(fig==1)
                    jogada(&linha, &coluna, tabuleiro);
                else{
                    if(dif==1)
                        jog_facil(&linha, &coluna, tabuleiro);
                    else if(dif==2)
                        jog_medio(&linha, &coluna, tabuleiro, fig_bot);
                    else if(dif==3){
                        caso = jog_dificil(&linha, &coluna, tabuleiro, fig_bot, cont, caso);
                        cont++;
                    }
                }
            }
            else if(turno==2){
                if(turno==fig){
                    printf("\neh a vez do jogador(o)!\n");
                }
                else{
                    printf("\neh a vez do computador(o)!\n");
                }
                Sleep(1500);
                if(fig==2)
                    jogada(&linha, &coluna, tabuleiro);
                else{  
                    if(dif==1)  
                        jog_facil(&linha, &coluna, tabuleiro);
                    else if(dif==2)
                        jog_medio(&linha, &coluna, tabuleiro, fig_bot);
                    else if(dif==3){
                        caso = jog_dificil(&linha, &coluna, tabuleiro, fig_bot, cont, caso);
                        cont++;
                    }
                }
            }
        }
        tabuleiro[linha][coluna] = turno;
        if(turno==1)
            turno=2;
        else if(turno==2)
            turno=1;
        if (vitoria == 1){
            if(fig==1){
                Sleep(1000);
                printf("\nParabens, voce venceu!\n");
                Sleep(1700);
                system("cls");
            }else{
                Sleep(1000);
                printf("\nVoce perdeu!");
                Sleep(1700);
                system("cls");
            }break;
        }
        else if(vitoria == 2){
            if(fig==2){
                Sleep(1000);
                printf("\nParabens, voce venceu!\n");
                Sleep(1700);
                system("cls");
            }else{
                Sleep(1000);
                printf("\nVoce perdeu!");
                Sleep(1700);
                system("cls");
            }break;
        }
    }
}