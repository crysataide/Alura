from modelos.restaurante import Restaurante

restaurante_praca = Restaurante('praca','gourmet')
restaurante_praca.receber_avaliacao('Gui', 10)
restaurante_praca.receber_avaliacao('Lais', 8)
restaurante_praca.receber_avaliacao('Emy', 5)

# restaurante_japones = Restaurante('Japa Food','Japonesa')
# restaurante_mexicano = Restaurante('mexican Food','Mexicana')

def main():
    Restaurante.lista_restaurantes()

if __name__ == '__main__':
    main()