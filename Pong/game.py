import pygame
from config import *
from time import sleep

pygame.init()
clock = pygame.time.Clock()

def game_start(screen, pontos=10):
    player1 = player()
    player2 = player()
    gamerun = True

    while gamerun and player1.points<pontos and player2.points<pontos:
        gameball = ball(cl*1)
        padle1 = padle(ca*45, 1, 1.5)
        padle2 = padle(ca*45, 2, 1.5)
        disputa = True
        inicio = True
        while disputa:
            keys = pygame.key.get_pressed()

            #Eventos
            for event in pygame.event.get():
                if event.type == pygame.KEYDOWN:
                    if event.key == pygame.K_ESCAPE: #Tecla Saída - ESC
                        pontos = 0
                        disputa = False
                        gamerun = False

            if keys[pygame.K_w]:
                padle1.move_up()
            if keys[pygame.K_s]:
                padle1.move_down()
            if keys[pygame.K_UP]:
                padle2.move_up()
            if keys[pygame.K_DOWN]:
                padle2.move_down()

        #Posições e verificações
            gameball.atualizamov()
            
            #Colisões Padle 1
            for point in gameball.esquerda:
                if padle1.vef_hitbox(point):
                    gameball.batida(1,True)
                    player1.bounce()
                    break
            #Colisões padle 2
            for point in gameball.direita:
                if padle2.vef_hitbox(point):
                    gameball.batida(2,True)
                    player2.bounce()
                    break
            
            #Bordas
            if gameball.psul[1] >= altura:
                gameball.batida(0, False, False)    
            if gameball.pnor[1] <= 0:
                gameball.batida(0, False, False)
            if gameball.poeste[0] < 0:
                player2.point()
                disputa = False
            if gameball.pleste[0] > largura:
                player1.point()
                disputa = False

            #Elementos gráficos
            screen.fill((0,0,0))

            placar1 = font_placar.render(f'{player1.points}', True, (255,255,255))
            screen.blit(placar1, (cl*30, ca*2))

            placar2 = font_placar.render(f'{player2.points}', True, (255,255,255))
            screen.blit(placar2, (cl*70, ca*2))

            pygame.draw.line(screen, (255,255,255), (padle1.pl[0], padle1.pa0), (padle1.pl[0], padle1.paf), round(padle1.largura))
            pygame.draw.rect(screen, (255,255,255), (padle2.pl[0], padle2.pa0, round(padle2.largura), (padle2.paf - padle2.pa0))) 
            pygame.draw.circle(screen, (255,255,255), (gameball.px, gameball.py), (gameball.raio))

            pygame.display.flip()
            clock.tick(60)
            if inicio:
                sleep(1)
            inicio = False