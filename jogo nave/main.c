#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define maxh 6
#define maxl 45

int main(){
    int cenario[maxh][maxl],i,j,pontuação,joga=1,dif=0,cont=0,zera_cont=0,esc,contc=0,pos=2,novamente=1;
    srand((unsigned)time(NULL));

    do{
        pontuação=0;
        // definindo cenário
        for(i=0;i<maxh;i++){
            for(j=0;j<maxl;j++){
                cenario[i][j]=0;
            }
        }
        
        //posição inicial da nave
        cenario[pos][1]=2;

        //seleciona a dificuldade
        do{
            printf("Digite a Dificuldade(3-difcil|2-medio|1-facil)\n-->");
            scanf("%d",&esc);
            printf("%d",esc);
            if(esc==3)
            dif=10;
            else if(esc==2)
            dif=16;
            else if(esc==1)
            dif=22;
            else
            printf("Escolha inválida!");
        }while(dif==0);
        cont=dif;
        
        //Jogo
        printf("\x1b[?25l"); // Esconde o cursor
        system("cls");
        do{

            //atualizações do jogo
            if(zera_cont==1){
                cont=0;
                zera_cont=0;
            }
            cont++;
            contc=0;

            //jogabilidade
            if(kbhit()) {
                char tecla = getch();
                if(tecla == 'w' || tecla == 72){ //cima
                    if(pos>0){
                        pos--;
                        cenario[pos+1][1]=0; //limpa a posição anterior
                    }
                }
                else if(tecla == 's' || tecla == 80){ //baixo
                    if(pos<maxh-1){
                        cenario[pos-1][1]=0; //limpa a posição anterior
                        pos++;
                    }
                }
                else if(tecla == 'q'){ //sair
                    joga=0;
                }
            }

            //atualiza o cenário
            pontuação++;
            printf("\x1b[H"); // Move o cursor para o canto superior esquerdo
            //movimento dos obstáculos
            for(i=0;i<maxh;i++){
                for(j=0;j<maxl;j++){
                    if(j+1 != maxl && cenario[i][j+1]!=2)
                    cenario[i][j]=cenario[i][j+1];
                    else
                    cenario[i][j]=0;
                }
            }
            
            //obstáculos
            for(i=0;i<maxh;i++){
                if(cont>=dif && contc<4){
                    cenario[i][maxl-1] = rand() & 1;
                    zera_cont=1;
                    if(cenario[i][maxl-1]==1)
                        contc++;
                }
                else
                    cenario[i][maxl-1] = 0;
            }
            
            //exibe cenário
            if(cenario[pos][1]==1){
                joga=0;
                printf("\nVoce perdeu!\n");
                sleep(2);
            }
            else
                cenario[pos][1]=2;
            printf("Use W/S ou setas para mover a nave. Pressione 'q' para sair.                pontos: %d\n",pontuação);
            printf("\n------------------------------------------------------------------------------------------------");
            for(i=0;i<maxh;i++){
                printf("\n");
                for(j=0;j<maxl;j++){
                    if(cenario[i][j]==0)
                        printf("  ");
                    else if(cenario[i][j]==1)
                        printf("||");
                    else if(cenario[i][j]==2)
                        printf("<>");
                }
            }
            printf("\n-------------------------------------------------------------------------------------------------\n");
            usleep(10000);


        }while(joga==1);
        system("cls");
        printf("\nFIM DE JOGO!\n");
        sleep(2);
        printf("\n\n\n\n\n\n\n\n                                                   Seus pontos: %d\n",pontuação);
        sleep(2);
        printf("                                        Pressione qualquer tecla para continuar...\n");
        while(kbhit()) getch(); // Limpa o buffer de entrada
        getch(); // Espera até que uma tecla seja pressionada
        system("cls");
        do{
            printf("\x1b[?25h"); // Mostra o cursor
            printf("Deseja jogar novamente? (1-sim|0-nao)\n-->");
            scanf("%d",&novamente);
            if(novamente!=0 && novamente!=1)
                printf("Escolha invalida!\n");}while(novamente!=0 && novamente!=1);
            if(novamente==0){
                printf("Obrigado por jogar!\n");
                sleep(1);
                system("cls");
                printf("saindo...");
                sleep(1);
            }
            else{
                system("cls");
                joga=1;
            }
    }while(novamente==1);
    return 0;
}