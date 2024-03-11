class Restaurante:
    def __init__(self, nome, categoria):
        self.nome = ''
        self.categoria = ''
        self.ativo = False
    def __str__(self):
        return f'{self.nome} | {self.categoria}'
    
restaurante_praca = Restaurante('Praça','Gourmet')
restaurante_pizza = Restaurante('Pizza Express','Italiana')

print(vars(restaurante_praca))
print(vars(restaurante_pizza))