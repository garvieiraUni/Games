import pygame
from config import *

pygame.init()
clock = pygame.time.Clock()

def game_start(screen):
    padle1 = padle(ca*45, 1, 1.5)
    padle2 = padle(ca*45, 2, 1.5)
    gameball = ball(cl*1)
    gamerun = True

    while gamerun:
        keys = pygame.key.get_pressed()

        #Eventos
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE: #Tecla Saída - ESC
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
                gameball.batida(1,True, -1)
                break
        #Colisões padle 2
        for point in gameball.direita:
            if padle2.vef_hitbox(point):
                gameball.batida(2,True, -1)
                break
        
        #Bordas
        if gameball.psul[1] >= altura:
            gameball.batida(0, False, 1)    
        if gameball.pnor[1] <= 0:
            gameball.batida(0, False, 0)


        #Elementos gráficos
        screen.fill((0,0,0))
        pygame.draw.line(screen, (255,255,255), (padle1.pl[0], padle1.pa0), (padle1.pl[0], padle1.paf), padle1.largura)
        pygame.draw.line(screen, (255,255,255), (padle2.pl[0], padle2.pa0), (padle2.pl[0], padle2.paf), padle2.largura)
        pygame.draw.circle(screen, (255,255,255), (gameball.px, gameball.py), (gameball.raio))

        pygame.display.flip()
        clock.tick(60)