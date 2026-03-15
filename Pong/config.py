import pygame

# infos da tela
pygame.init()
info = pygame.display.Info()
altura = info.current_h
largura = info.current_w

#Escalonando
ca = altura/100  #Um centésimo da altura
cl = largura/100 #Idem Largura

#Fontes
font_main = pygame.font.SysFont("impact", 200)
main_options = pygame.font.SysFont("consolas", 50)
main_options_exit = pygame.font.SysFont("consolas", 35)