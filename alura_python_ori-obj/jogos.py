import os
import forca
import adivinhacao

def escolhe_jogo():
    cls = lambda: os.system('cls')

    print("**********************")
    print("== Escolha seu jogo ==")
    print("**********************")
    print("\n")

    jogo = int(input("[1]Forca [2]Adivinhação: "))

    if jogo == 1:
        cls()
        print('Abrindo forca...')
        forca.jogar()
    elif jogo == 2:
        cls()
        print('Abrindo adivinhação...')
        adivinhacao.jogar()
  
if __name__ == "__main__":
    escolhe_jogo()