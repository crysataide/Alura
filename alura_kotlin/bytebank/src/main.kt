fun main() {
    println("Bem vindo ao Bytebank")

    for (i in 5 downTo 1) {

        val titular: String = "Alex $i"
        val numeroConta: Int = 1000 + 1
        var saldo = i + 10.0

        println("Titular $titular")
        println("Número da conta $numeroConta")
        println("Saldo da conta $saldo")

        println()
    }
//    testaCondicoes(saldo)
}

fun testaCondicoes(saldo: Double) {
    if (saldo > 0.0) {
        println("conta é positiva")
    } else if (saldo == 0.0) {
        println("conta é neutra")
    } else {
        println("conta é negativa")
    }
}