import pygame
import config
from config import ca, cl, font_main, main_options, main_options_exit
import sys

# Inicialização
pygame.init()

#Definindo a Tela
screen = pygame.display.set_mode((config.largura, config.altura), pygame.FULLSCREEN | pygame.SCALED)
pygame.display.set_caption("Pong")

clock = pygame.time.Clock()

#Definindo textos
welcome = font_main.render("PONG!", True, (255, 255, 255))
play = main_options.render("Pressione ENTER para iniciar", True, (255,255,255))
exit = main_options_exit.render("ESC para sair", True, (120,120,120))

#Janela principal rodando:
running = True
while running:

    #Tecla Saída - ESC
    for event in pygame.event.get():
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_ESCAPE:
                running = False

    #Elementos gráficos
    screen.fill((0,0,0))
    screen.blit(welcome, (cl*34.5, ca*10))
    screen.blit(play, (cl*25.5, ca*70))
    screen.blit(exit, (cl*41, ca*80))

    #Atualização da tela
    pygame.display.flip()
    clock.tick(60)

pygame.quit()
sys.exit()