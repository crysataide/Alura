import random
import os

def jogar():

    des = True

    while des:
        cls = lambda: os.system('cls')
        cls()

        print("******************************")
        print("Bem vindo jogo de Adivinhação!")
        print("******************************")
        print("\n")

        numero_secreto = random.randrange(1,101)
        total_de_tentativas = 0
        pontos = 100

        print("Qual o nível de dificuldade?")
        print("[1] Fácil [2]Médio [3]Difícil")
        print("\n")

        nivel = int(input("Defina o nível: "))
        print("\n")

        if nivel == 1:
            print("Dificuldade Fácil")
            total_de_tentativas = 20
        elif nivel ==2:
            print("Dificuldade Médio")
            total_de_tentativas = 10
        elif nivel ==3:
            print("Dificuldade Difícil")
            total_de_tentativas = 5
        else:
            print("Valor inválido")

        print("Quantidade de tentativas: {}".format(total_de_tentativas))

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
                print("\nVocê acertou e fez {} pontos!".format(pontos))
                break
            else:
                if maior:
                    print("\nVocê errou! O seu chute foi maior que o número secreto")
                elif menor:
                    print("\nVocê errou! O seu chute foi menor que o número secreto")
                pontos_perdidos = abs(numero_secreto-chute)
                pontos -= pontos_perdidos

            print("\nRestam {} tentativas\n".format(total_de_tentativas-rodada))
            getch = input('').split(" ")[0]
            cls()

        if not(acertou):
            print("Fim das tentativas!!!\n") 

        getch = input('').split(" ")[0]

        print("Deseja jogar novamente?")
        des = input("S para Sim[] N para Não[] --> ")
        erro = True

        while erro == True:
            if des == 's' or 'S':
                des = True
            elif des == 'n' or 'N':
                des == False
            else:
                print("Digite um valor válido")
                erro = True

if __name__ == "__main__":
    jogar()