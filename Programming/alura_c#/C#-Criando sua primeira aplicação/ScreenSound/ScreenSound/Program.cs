// Screen Sound
string mensagemDeBoasVindas = "Boas vindas ao Screen Sound";
//List<string> listaDasBandas = new List<string> {"U2","The Beatles","Calypso"};

Dictionary<string,List<int>> bandasRegistradas = new Dictionary<string,List<int>>();
bandasRegistradas.Add("Linkin Park", new List<int> { 10, 0, 6});
bandasRegistradas.Add("The Beatles", new List<int>());

void ExibirMensagemDeBoasVindas()
{
    Console.WriteLine(@"
        ░██████╗░█████╗░██████╗░███████╗███████╗███╗░░██╗  ░██████╗░█████╗░██╗░░░██╗███╗░░██╗██████╗░
        ██╔════╝██╔══██╗██╔══██╗██╔════╝██╔════╝████╗░██║  ██╔════╝██╔══██╗██║░░░██║████╗░██║██╔══██╗
        ╚█████╗░██║░░╚═╝██████╔╝█████╗░░█████╗░░██╔██╗██║  ╚█████╗░██║░░██║██║░░░██║██╔██╗██║██║░░██║
        ░╚═══██╗██║░░██╗██╔══██╗██╔══╝░░██╔══╝░░██║╚████║  ░╚═══██╗██║░░██║██║░░░██║██║╚████║██║░░██║
        ██████╔╝╚█████╔╝██║░░██║███████╗███████╗██║░╚███║  ██████╔╝╚█████╔╝╚██████╔╝██║░╚███║██████╔╝
        ╚═════╝░░╚════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚═╝░░╚══╝  ╚═════╝░░╚════╝░░╚═════╝░╚═╝░░╚══╝╚═════╝░
    ");
    Console.WriteLine(mensagemDeBoasVindas);
}

void ExibirOpcoesDoMenu()
{
    Console.WriteLine("\nDigite 1 para registrar uma banda");
    Console.WriteLine("Digite 2 para mostrar todas as bandas");
    Console.WriteLine("Digite 3 para avaliar uma banda");
    Console.WriteLine("Digite 4 para exibir a média de uma banda");
    Console.WriteLine("Digite -1 para sair");

    Console.Write("\nDigite a sua opção: ");
    string opcaoEscolhida = Console.ReadLine()!;
    int opcaoEscolhidaNumerica = int.Parse(opcaoEscolhida);

    switch (opcaoEscolhidaNumerica) {
        case 1: RegistrarBanda()          ; break;
        case 2: MostrarBandasRegistradas(); break;
        case 3: AvaliarUmaBanda()         ; break;
        case 4: ExibirMedia()             ; break;
        case 0: Console.WriteLine("Tchau tchau :)"); break;
        default: Console.WriteLine("Opção inválida"); break;
    }
}

void RegistrarBanda()
{
    Console.Clear();
    ExibirTituloDaOpcao("Registro de bandas");

    Console.Write("Digite o nome da banda que deseja registrar: ");

    string nomeDaBanda = Console.ReadLine()!;
    //listaDasBandas.Add(nomeDaBanda);
    bandasRegistradas.Add(nomeDaBanda, new List<int>());

    Console.WriteLine($"A banda {nomeDaBanda} foi registrada!");
    Thread.Sleep(2000);
    Console.Clear();

    ExibirOpcoesDoMenu();
}

void MostrarBandasRegistradas()
{
    Console.Clear();
    ExibirTituloDaOpcao("Exibindo todas as bandas registradas");

    //for (int i = 0; i < listaDasBandas.Count; i++)
    //{
    //    Console.WriteLine($"Banda: {listaDasBandas[i]}");
    //}
    //foreach (string banda in listaDasBandas)
    //{
    //    Console.WriteLine($"Banda: {banda}");
    //}
    foreach(string banda in bandasRegistradas.Keys)
        {
        Console.WriteLine($"Banda: {banda}");
    }

    Console.WriteLine("\nDigite uma tecla para voltar ao menu principal");
    Console.ReadKey();
    Console.Clear();

    ExibirOpcoesDoMenu();
}

void ExibirTituloDaOpcao(string titulo)
{
    int quantidadeDeLetras = titulo.Length;
    string asteriscos = string.Empty.PadLeft(quantidadeDeLetras,'*');
    Console.WriteLine(asteriscos); 
    Console.WriteLine(titulo);
    Console.WriteLine(asteriscos+"\n");
}
 
void AvaliarUmaBanda()
{
    Console.Clear();
    ExibirTituloDaOpcao("Avaliar banda");
    Console.WriteLine("Digite o nome da banda que deseja avaliar: ");
    string nomeDaBanda = Console.ReadLine()!;
    
    if (bandasRegistradas.ContainsKey(nomeDaBanda))
    {
        Console.Write($"Qual a nota que a banda {nomeDaBanda} merece: ");
        int nota = int.Parse(Console.ReadLine()!);
        bandasRegistradas[nomeDaBanda].Add(nota);
        Console.Write($"\nA nota {nota} foi registrada com sucesso para a banda {nomeDaBanda}");
        Thread.Sleep(2000);
        Console.Clear();
        ExibirOpcoesDoMenu();
    }
    else
    {
        Console.WriteLine($"\nA banda {nomeDaBanda} não foi encontrada!");
        Console.WriteLine("\nDigite uma tecla para voltar ao menu principal");
        Console.ReadKey();
        Console.Clear();

        ExibirOpcoesDoMenu();
    }
}

void ExibirMedia()
{
    Console.Clear();
    ExibirTituloDaOpcao("Exibir média da banda");
    Console.WriteLine("Digite o nome da banda que deseja exibir a média: ");
    string nomeDaBanda = Console.ReadLine()!;
    int notas = 0;

    if (bandasRegistradas.ContainsKey(nomeDaBanda))
    {
        //for (int i = 0; i < bandasRegistradas[nomeDaBanda].Count; i++)
        //{
        //    notas += bandasRegistradas[nomeDaBanda][i];
        //}
        //int media = notas / bandasRegistradas[nomeDaBanda].Count;

        List<int> notasDaBanda = bandasRegistradas[nomeDaBanda]; 

        Console.WriteLine($"\nA média da banda {nomeDaBanda} é {notasDaBanda.Average()}");
    }
    else
    {
        Console.WriteLine($"\nA banda {nomeDaBanda} não foi encontrada!");
    }
    Console.WriteLine("\nDigite uma tecla para voltar ao menu principal");
    Console.ReadKey();
    Console.Clear();
    ExibirOpcoesDoMenu();
}

ExibirMensagemDeBoasVindas();
ExibirOpcoesDoMenu();