import pygame
from random import randint, choice

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
font_placar = pygame.font.SysFont("Impact", 80)
main_options = pygame.font.SysFont("consolas", 50)
main_options_exit = pygame.font.SysFont("consolas", 35)
instructions_players = pygame.font.SysFont("roboto", 140)
instructions_text1 = pygame.font.SysFont("dataype", 90)
instructions_text2 = pygame.font.SysFont("Iosevka Charon", 60)

#Variáveis
instructions = False

#objetos

class padle:
    def __init__(self, pa0, player, vel=1):
        self.pa0 = pa0 #Posicionamento altura 0 - inicial
        self.paf = pa0+(ca*10) #Posição altura final
        self.player = player
        self.vel = vel # velocidade de movimento
        if player == 1:
            self.pl = (cl*5, cl*7) #posicionamento largura - p1
        else:
            self.pl = (cl*91, cl*93) #posicionamento largura - p2
        self.largura = self.pl[1] - self.pl[0]

    def move_up(self): #mover padle pra cima
        if self.pa0 > 0:
            self.pa0 -= ca*self.vel
            self.paf = self.pa0+(ca*10)

    def move_down(self):
        if self.paf < altura:
            self.pa0 += ca*self.vel
            self.paf = self.pa0+(ca*10)

    def vef_hitbox(self, coord=(int,int)):
        if coord[1] > self.paf or coord[1] < self.pa0:
            return False
        if coord[0] > self.pl[1] or coord[0] < self.pl[0]:
            if self.player == 1:
                return False
        if coord[0] < self.pl[0] or coord[0] > self.pl[1]:
            if self.player == 2:
                return False
        return True
    
class ball:
    def __init__(self, raio = int, pi = (50*cl, 50*ca), velx = 1, vely = 0):
        self.px = pi[0]     # coordenadas centro
        self.py = pi[1]
        self.raio = raio
        self.pnor = (self.px, self.py - raio) #coordenadas de colisão
        self.psul = (self.px, self.py + raio)
        self.poeste = (self.px - raio, self.py)
        self.pnoro = (self.px - raio, self.py - raio)
        self.psudo = (self.px - raio, self.py + raio)
        self.pleste = (self.px + raio, self.py)
        self.pnord = (self.px + raio, self.py - raio)
        self.psude = (self.px + raio, self.py + raio)
        self.esquerda = [self.poeste, self.pnoro, self.psudo, self.psul, self.pnor]
        self.direita = [self.pleste, self.pnord, self.psude, self.psul, self.pnor]
        self.velx = velx
        self.vely = vely
        self.dirx = velx*(cl)         #dir movimento
        self.diry = vely*(ca)

    def atualizamov(self):
        self.dirx = self.velx*(cl/5)        #dir movimento
        self.diry = self.vely*(ca/2)
        self.px += self.dirx
        self.py += self.diry
        self.pnor = (self.px, self.py - self.raio) #coordenadas de colisão
        self.psul = (self.px, self.py + self.raio)
        self.poeste = (self.px - self.raio, self.py)
        self.pnoro = (self.px - self.raio, self.py - self.raio)
        self.psudo = (self.px - self.raio, self.py + self.raio)
        self.pleste = (self.px + self.raio, self.py)
        self.pnord = (self.px + self.raio, self.py - self.raio)
        self.psude = (self.px + self.raio, self.py + self.raio)
        self.esquerda = [self.poeste, self.psudo, self.pnoro, self.psul, self.pnor]
        self.direita = [self.pleste, self.psude, self.pnord, self.psul, self.pnor]
    
    def batida(self, player = int, x=False, randy = True):
        if x:
            if player == 1: self.velx = randint(5, 7)
            else: self.velx = randint(-7, -5)

        if randy: self.vely = choice([-1,1,-1,1,-1,0,1,-1,1,-1,1])
        else: self.vely *= -1 
            
class player:
    def __init__(self):
        self.points = 0
        self.bounces = 0
    
    def point(self):
        self.points += 1
    
    def bounce(self):
        self.bounces += 1
