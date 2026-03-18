import pygame
from game import *
from config import *
import sys

# Inicialização
pygame.init()

#Definindo a Tela
screen = pygame.display.set_mode((largura, altura), pygame.FULLSCREEN | pygame.SCALED)
pygame.display.set_caption("Pong")

clock = pygame.time.Clock()

#Definindo textos
welcome = font_main.render("PONG!", True, (255, 255, 255))
play = main_options.render("Pressione ENTER para iniciar", True, (255,255,255))
continua = main_options.render("Pressione ENTER para continuar", True, (255,255,255), (0,0,0))
exit = main_options_exit.render("ESC para sair", True, (120,120,120))
player1 = instructions_players.render("Player 1", True, (255,255,255))
player2 = instructions_players.render("Player 2", True, (255,255,255))
player_control = instructions_text1.render("Controles", True, (255,255,255))
player_instructions_up = instructions_text2.render("Subir", True, (255,255,255))
player_instructions_down = instructions_text2.render("Descer", True, (255,255,255))
key_w = instructions_text2.render("W", True, (255,255,255))
key_s = instructions_text2.render("S", True, (255,255,255))
key_up = instructions_text2.render("^", True, (255,255,255))
key_down = instructions_text2.render("v", True, (255,255,255))

#Janela principal rodando:
running = True
while running:

    #Eventos
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE: #Tecla Saída - ESC
                if instructions:
                    instructions = False
                else:
                    running = False
            elif event.key == pygame.K_RETURN:
                if instructions:
                    game_start(screen, 5)
                    instructions = False
                else:
                    instructions = True

    #Elementos gráficos
    screen.fill((0,0,0))

    if instructions:

        #player 1
        screen.blit(player1, (cl*12, ca*7))
        screen.blit(player_control, (cl*14, ca*23))

        #controles p1
        screen.blit(player_instructions_up, (cl*10, ca*45))
        pygame.draw.line(screen, (40,40,40), (cl*33.7,ca*44), (cl*33.7, ca*50), round(cl*4))
        screen.blit(key_w, (cl*32.5, ca*45))

        screen.blit(player_instructions_down, (cl*10, ca*55))
        pygame.draw.line(screen, (40,40,40), (cl*33.7,ca*54), (cl*33.7, ca*60), round(cl*4))
        screen.blit(key_s, (cl*33, ca*55))

        #player2
        screen.blit(player2, (cl*62, ca*7))
        screen.blit(player_control, (cl*64.5, ca*23))

        #controles p2
        screen.blit(player_instructions_up, (cl*60.5, ca*45))
        pygame.draw.line(screen, (40,40,40), (cl*83.7,ca*44), (cl*83.7, ca*50), round(cl*4))
        screen.blit(key_up, (cl*83, ca*45))

        screen.blit(player_instructions_down, (cl*60.5, ca*55))
        pygame.draw.line(screen, (40,40,40), (cl*83.7,ca*54.4), (cl*83.7, ca*60.5), round(cl*4))
        screen.blit(key_down, (cl*83, ca*55))


        pygame.draw.line(screen, (255,255,255), (cl*50, ca*100), (cl*50, ca*0), 8)
        screen.blit(continua, (cl*26, ca*85))
    else:
        screen.blit(welcome, (cl*34.5, ca*10))
        screen.blit(play, (cl*26, ca*70))
        screen.blit(exit, (cl*42, ca*80))

    #Atualização da tela
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()