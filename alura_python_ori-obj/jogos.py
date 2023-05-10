import random
import os

des = True

while des:
    cls = lambda: os.system('cls')
    cls()

    print("******************************")
    print("Bem vindo jogo de Adivinhação!")
    print("******************************")
    print("\n")
    print("Objetivo: adivinhe o número secreto")
    print("\n")

    numero_secreto = int(random.random()*100)

    while not(numero_secreto>0):
        numero_secreto = int(random.random()*100)

    total_de_tentativas = int(input("Digite a quantidade de tentativas: "))

    print(numero_secreto)

    getch = input('').split(" ")[0]
    cls()

    for rodada in range(1, total_de_tentativas):
        print("Tentativa {} de {}".format(rodada, total_de_tentativas))
        chute = int(input("\nDigite o seu número: "))

        cls()

        print("Você digitou", chute)

        if chute < 1 or chute > 100:
            print("\nVocê deve digitar um número entre 1 e 100\n")
            continue

        acertou = chute == numero_secreto
        maior   = chute >  numero_secreto
        menor   = chute <  numero_secreto

        if acertou:
            print("\nVocê acertou!!!")
            break
        elif maior:
            print("\nDigite um número menor")
        elif menor:
            print("\nDigite um número maior")

        print("\nRestam {} tentativas\n".format(total_de_tentativas-rodada))
        getch = input('').split(" ")[0]
        cls()

    if not(acertou):
        print("Fim das tentativas!!!\n")

    getch = input('').split(" ")[0]

    print("Deseja jogar novamente?")
    des = input("S para Sim[] N para Não[] --> ")
    erro = False

    while erro == True:
        if des == 's' or 'S':
            des = True
        elif des == 'n' or 'N':
            des == False
        else:
            print("Digite um valor válido")
            erro = True