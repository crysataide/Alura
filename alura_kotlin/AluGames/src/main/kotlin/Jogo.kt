data class Jogo(
    val titulo: String,
    val capa: String
) {
    var descricao = ""

    override fun toString(): String {
        return "Meu Jogo'" +
                "Titulo: $titulo \n" +
                "Capa='$capa \n" +
                "Descricao='$descricao \n"
    }
}