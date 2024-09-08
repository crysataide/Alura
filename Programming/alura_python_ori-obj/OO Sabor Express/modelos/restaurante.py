from modelos.avaliacao import Avaliacao

class Restaurante:
    restaurantes = []
    
    def __init__(self, nome, categoria):
        self._nome = nome.title()
        self._categoria = categoria.title()
        self._ativo = False
        self._avaliacao = []
        
        Restaurante.restaurantes.append(self)
    def __str__(self):
        return f'{self._nome} | {self._categoria}'
    
    @classmethod
    def lista_restaurantes(cls):
        print(f'{'Restaurante'.ljust(25)} | {'Categoria'.ljust(25)} | {'Avaliação'.ljust(25)} | {'Status'}')
        for i in cls.restaurantes:
            print(f'{i._nome.ljust(25)} | {i._categoria.ljust(25)} | {str(i.media_avaliacao).ljust(25)} | {i.ativo.ljust(25)}')

    @property
    def ativo(self):
        return '☑' if self._ativo else '☐'
    
    def alternar_estado(self):
        self._ativo = not self._ativo

    def receber_avaliacao(self, cliente, nota):
        if 0 < nota <= 5:
            avaliacao = Avaliacao(cliente, nota)
            self._avaliacao.append(avaliacao)

    @property
    def media_avaliacao(self):
        if not self._avaliacao:
            return '-'
        soma_das_notas = sum(avaliacao._nota for avaliacao in self._avaliacao)
        quantidade_de_notas = len(self._avaliacao)

        return round(soma_das_notas/quantidade_de_notas,1)