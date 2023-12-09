// Inclui o arquivo de cabe�alho "lib.h", que cont�m defini��es e declara��es de fun��es utilizadas no c�digo principal.
#include "lib.h"

// Fun��o principal que representa o menu do jogo.
void Menu()
{
    // Define a l�ngua que o c�digo ser� executado para Portugu�s.
    setlocale(LC_ALL, "Portuguese");

    // Declara��o de vari�veis inteiras para op��es, dificuldade, status do jogo, vit�rias e contagem de jogadas.
    int opcao, dificuldade = 1, continuar_jogo = 1, vitoria = 0, cont_jogadas = 0;

    // Cria��o de inst�ncias das structs Player e PC (representando o jogador e o computador).
    Player player;
    PC computador;

    // Inicializa��o de resultados para zero.
    player.Resultado_Player = 0;
    player.Resultado_Def_Player = 0;
    computador.Resultado_PC = 0;
    computador.Resultado_Def_PC = 0;

    // Inicializa��o do gerador de n�meros aleat�rios usando o tempo atual.
    srand(time(NULL));

    // Chama a fun��o Menu_Login passando algumas vari�veis por refer�ncia.
    Menu_Login(opcao, &player, &vitoria, &cont_jogadas);

    // Loop principal do jogo.
    while (continuar_jogo)
    {
        // Calcula a soma dos resultados do jogador.
        int Soma_Resultado_Def = player.Resultado_Player + player.Resultado_Def_Player;

        // Mostra informa��es da rodada.
        if (player.Dado_Player != 1)
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, Soma_Resultado_Def, computador.Resultado_Def_PC);
            printf("Quantidade de jogadas: %d\n", cont_jogadas);
            printf("Vitorias: %d\n", vitoria);
        }
        else
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, player.Resultado_Def_Player, computador.Resultado_Def_PC);
            printf("Vit�rias: %d\n", vitoria);
        }

        // Verifica se o jogo ainda est� em andamento e mostra op��es ao jogador.
        if (computador.Resultado_Def_PC < 100 && player.Resultado_Def_Player < 100)
        {
            printf("1. Lan�ar o dado\n2. Segurar\n3. Alterar Dificuldade\n4. Mostrar Ranking\n5. Encerrar o jogo\n");
            scanf("%d", &opcao);
            getchar();
            system("cls");
        }

        // Estrutura switch para lidar com diferentes op��es.
        switch (opcao)
        {
        case 1:
            // Caso 1: Chama a fun��o Lancar_Dado ou Lancar_Dois_Dados com base na dificuldade.
            if (dificuldade == 1)
            {
                Lancar_Dado(&player, &computador, &vitoria, &cont_jogadas);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dados(&player, &computador, &cont_jogadas, &vitoria);
            }
            break;

        case 2:
            // Caso 2: Chama a fun��o Segurar_Dado e, dependendo da dificuldade, chama Lancar_Dado_PC ou Lancar_Dois_Dado_PC.
            Segurar_Dado(&player);
            if (dificuldade == 1)
            {
                Lancar_Dado_PC(&computador, &player);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dado_PC(&computador, &player);
            }
            break;

        case 3:
            // Caso 3: Chama a fun��o Dificuldade para alterar a dificuldade.
            Dificuldade(&dificuldade);
            break;

        case 4:
            // Caso 4: Chama a fun��o Mostrar_Ranking para exibir o ranking.
            Mostrar_Ranking(&player, &vitoria, &cont_jogadas);
            break;

        case 5:
            // Caso 5: Encerra o jogo.
            printf("Encerrando o jogo...\n");
            continuar_jogo = 0;
            break;

        default:
            // Caso padr�o: Mensagem de opera��o inv�lida.
            printf("Opera��o inv�lida!\n");
            break;
        }
    }
}

// Inclui o arquivo de cabe�alho "lib.h", que cont�m defini��es e declara��es de fun��es utilizadas no c�digo principal.
#include "lib.h"

// Fun��o principal que representa o menu do jogo.
void Menu()
{
    // Define a l�ngua que o c�digo ser� executado para Portugu�s.
    setlocale(LC_ALL, "Portuguese");

    // Declara��o de vari�veis inteiras para op��es, dificuldade, status do jogo, vit�rias e contagem de jogadas.
    int opcao, dificuldade = 1, continuar_jogo = 1, vitoria = 0, cont_jogadas = 0;

    // Cria��o de inst�ncias das structs Player e PC (representando o jogador e o computador).
    Player player;
    PC computador;

    // Inicializa��o de resultados para zero.
    player.Resultado_Player = 0;
    player.Resultado_Def_Player = 0;
    computador.Resultado_PC = 0;
    computador.Resultado_Def_PC = 0;

    // Inicializa��o do gerador de n�meros aleat�rios usando o tempo atual.
    srand(time(NULL));

    // Chama a fun��o Menu_Login passando algumas vari�veis por refer�ncia.
    Menu_Login(opcao, &player, &vitoria, &cont_jogadas);

    // Loop principal do jogo.
    while (continuar_jogo)
    {
        // Calcula a soma dos resultados do jogador.
        int Soma_Resultado_Def = player.Resultado_Player + player.Resultado_Def_Player;

        // Mostra informa��es da rodada.
        if (player.Dado_Player != 1)
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, Soma_Resultado_Def, computador.Resultado_Def_PC);
            printf("Quantidade de jogadas: %d\n", cont_jogadas);
            printf("Vitorias: %d\n", vitoria);
        }
        else
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, player.Resultado_Def_Player, computador.Resultado_Def_PC);
            printf("Vit�rias: %d\n", vitoria);
        }

        // Verifica se o jogo ainda est� em andamento e mostra op��es ao jogador.
        if (computador.Resultado_Def_PC < 100 && player.Resultado_Def_Player < 100)
        {
            printf("1. Lan�ar o dado\n2. Segurar\n3. Alterar Dificuldade\n4. Mostrar Ranking\n5. Encerrar o jogo\n");
            scanf("%d", &opcao);
            getchar();
            system("cls");
        }

        // Estrutura switch para lidar com diferentes op��es.
        switch (opcao)
        {
        case 1:
            // Caso 1: Chama a fun��o Lancar_Dado ou Lancar_Dois_Dados com base na dificuldade.
            if (dificuldade == 1)
            {
                Lancar_Dado(&player, &computador, &vitoria, &cont_jogadas);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dados(&player, &computador, &cont_jogadas, &vitoria);
            }
            break;

        case 2:
            // Caso 2: Chama a fun��o Segurar_Dado e, dependendo da dificuldade, chama Lancar_Dado_PC ou Lancar_Dois_Dado_PC.
            Segurar_Dado(&player);
            if (dificuldade == 1)
            {
                Lancar_Dado_PC(&computador, &player);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dado_PC(&computador, &player);
            }
            break;

        case 3:
            // Caso 3: Chama a fun��o Dificuldade para alterar a dificuldade.
            Dificuldade(&dificuldade);
            break;

        case 4:
            // Caso 4: Chama a fun��o Mostrar_Ranking para exibir o ranking.
            Mostrar_Ranking(&player, &vitoria, &cont_jogadas);
            break;

        case 5:
            // Caso 5: Encerra o jogo.
            printf("Encerrando o jogo...\n");
            continuar_jogo = 0;
            break;

        default:
            // Caso padr�o: Mensagem de opera��o inv�lida.
            printf("Opera��o inv�lida!\n");
            break;
        }
    }
}

// Inclui o arquivo de cabe�alho "lib.h", que cont�m defini��es e declara��es de fun��es utilizadas no c�digo principal.
#include "lib.h"

// Fun��o principal que representa o menu do jogo.
void Menu()
{
    // Define a l�ngua que o c�digo ser� executado para Portugu�s.
    setlocale(LC_ALL, "Portuguese");

    // Declara��o de vari�veis inteiras para op��es, dificuldade, status do jogo, vit�rias e contagem de jogadas.
    int opcao, dificuldade = 1, continuar_jogo = 1, vitoria = 0, cont_jogadas = 0;

    // Cria��o de inst�ncias das structs Player e PC (representando o jogador e o computador).
    Player player;
    PC computador;

    // Inicializa��o de resultados para zero.
    player.Resultado_Player = 0;
    player.Resultado_Def_Player = 0;
    computador.Resultado_PC = 0;
    computador.Resultado_Def_PC = 0;

    // Inicializa��o do gerador de n�meros aleat�rios usando o tempo atual.
    srand(time(NULL));

    // Chama a fun��o Menu_Login passando algumas vari�veis por refer�ncia.
    Menu_Login(opcao, &player, &vitoria, &cont_jogadas);

    // Loop principal do jogo.
    while (continuar_jogo)
    {
        // Calcula a soma dos resultados do jogador.
        int Soma_Resultado_Def = player.Resultado_Player + player.Resultado_Def_Player;

        // Mostra informa��es da rodada.
        if (player.Dado_Player != 1)
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, Soma_Resultado_Def, computador.Resultado_Def_PC);
            printf("Quantidade de jogadas: %d\n", cont_jogadas);
            printf("Vitorias: %d\n", vitoria);
        }
        else
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, player.Resultado_Def_Player, computador.Resultado_Def_PC);
            printf("Vit�rias: %d\n", vitoria);
        }

        // Verifica se o jogo ainda est� em andamento e mostra op��es ao jogador.
        if (computador.Resultado_Def_PC < 100 && player.Resultado_Def_Player < 100)
        {
            printf("1. Lan�ar o dado\n2. Segurar\n3. Alterar Dificuldade\n4. Mostrar Ranking\n5. Encerrar o jogo\n");
            scanf("%d", &opcao);
            getchar();
            system("cls");
        }

        // Estrutura switch para lidar com diferentes op��es.
        switch (opcao)
        {
        case 1:
            // Caso 1: Chama a fun��o Lancar_Dado ou Lancar_Dois_Dados com base na dificuldade.
            if (dificuldade == 1)
            {
                Lancar_Dado(&player, &computador, &vitoria, &cont_jogadas);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dados(&player, &computador, &cont_jogadas, &vitoria);
            }
            break;

        case 2:
            // Caso 2: Chama a fun��o Segurar_Dado e, dependendo da dificuldade, chama Lancar_Dado_PC ou Lancar_Dois_Dado_PC.
            Segurar_Dado(&player);
            if (dificuldade == 1)
            {
                Lancar_Dado_PC(&computador, &player);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dado_PC(&computador, &player);
            }
            break;

        case 3:
            // Caso 3: Chama a fun��o Dificuldade para alterar a dificuldade.
            Dificuldade(&dificuldade);
            break;

        case 4:
            // Caso 4: Chama a fun��o Mostrar_Ranking para exibir o ranking.
            Mostrar_Ranking(&player, &vitoria, &cont_jogadas);
            break;

        case 5:
            // Caso 5: Encerra o jogo.
            printf("Encerrando o jogo...\n");
            continuar_jogo = 0;
            break;

        default:
            // Caso padr�o: Mensagem de opera��o inv�lida.
            printf("Opera��o inv�lida!\n");
            break;
        }
    }
}

// Inclui o arquivo de cabe�alho "lib.h", que cont�m defini��es e declara��es de fun��es utilizadas no c�digo principal.
#include "lib.h"

// Fun��o principal que representa o menu do jogo.
void Menu()
{
    // Define a l�ngua que o c�digo ser� executado para Portugu�s.
    setlocale(LC_ALL, "Portuguese");

    // Declara��o de vari�veis inteiras para op��es, dificuldade, status do jogo, vit�rias e contagem de jogadas.
    int opcao, dificuldade = 1, continuar_jogo = 1, vitoria = 0, cont_jogadas = 0;

    // Cria��o de inst�ncias das structs Player e PC (representando o jogador e o computador).
    Player player;
    PC computador;

    // Inicializa��o de resultados para zero.
    player.Resultado_Player = 0;
    player.Resultado_Def_Player = 0;
    computador.Resultado_PC = 0;
    computador.Resultado_Def_PC = 0;

    // Inicializa��o do gerador de n�meros aleat�rios usando o tempo atual.
    srand(time(NULL));

    // Chama a fun��o Menu_Login passando algumas vari�veis por refer�ncia.
    Menu_Login(opcao, &player, &vitoria, &cont_jogadas);

    // Loop principal do jogo.
    while (continuar_jogo)
    {
        // Calcula a soma dos resultados do jogador.
        int Soma_Resultado_Def = player.Resultado_Player + player.Resultado_Def_Player;

        // Mostra informa��es da rodada.
        if (player.Dado_Player != 1)
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, Soma_Resultado_Def, computador.Resultado_Def_PC);
            printf("Quantidade de jogadas: %d\n", cont_jogadas);
            printf("Vitorias: %d\n", vitoria);
        }
        else
        {
            printf("Rodada: %s %d - PC %d\n", player.nome, player.Resultado_Def_Player, computador.Resultado_Def_PC);
            printf("Vit�rias: %d\n", vitoria);
        }

        // Verifica se o jogo ainda est� em andamento e mostra op��es ao jogador.
        if (computador.Resultado_Def_PC < 100 && player.Resultado_Def_Player < 100)
        {
            printf("1. Lan�ar o dado\n2. Segurar\n3. Alterar Dificuldade\n4. Mostrar Ranking\n5. Encerrar o jogo\n");
            scanf("%d", &opcao);
            getchar();
            system("cls");
        }

        // Estrutura switch para lidar com diferentes op��es.
        switch (opcao)
        {
        case 1:
            // Caso 1: Chama a fun��o Lancar_Dado ou Lancar_Dois_Dados com base na dificuldade.
            if (dificuldade == 1)
            {
                Lancar_Dado(&player, &computador, &vitoria, &cont_jogadas);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dados(&player, &computador, &cont_jogadas, &vitoria);
            }
            break;

        case 2:
            // Caso 2: Chama a fun��o Segurar_Dado e, dependendo da dificuldade, chama Lancar_Dado_PC ou Lancar_Dois_Dado_PC.
            Segurar_Dado(&player);
            if (dificuldade == 1)
            {
                Lancar_Dado_PC(&computador, &player);
            }
            if (dificuldade == 2)
            {
                Lancar_Dois_Dado_PC(&computador, &player);
            }
            break;

        case 3:
            // Caso 3: Chama a fun��o Dificuldade para alterar a dificuldade.
            Dificuldade(&dificuldade);
            break;

        case 4:
            // Caso 4: Chama a fun��o Mostrar_Ranking para exibir o ranking.
            Mostrar_Ranking(&player, &vitoria, &cont_jogadas);
            break;

        case 5:
            // Caso 5: Encerra o jogo.
            printf("Encerrando o jogo...\n");
            continuar_jogo = 0;
            break;

        default:
            // Caso padr�o: Mensagem de opera��o inv�lida.
            printf("Opera��o inv�lida!\n");
            break;
        }
    }
}

// Fun��o para lan�ar o dado do jogador.
void Lancar_Dado(Player *player, PC *computador, int *victory, int *jogadas)
{
    // Verifica se o jogador tirou 1.
    if (player->Dado_Player == 1)
    {
        // Se o jogador tirar 1, perde os pontos da rodada.
        printf("Voc� tirou 1! Perdeu os pontos da rodada.\n");
        player->Resultado_Player = 0;
        Lancar_Dado_PC(computador, player);
    }
    else
    {
        // Adiciona o valor do dado � pontua��o do jogador.
        player->Resultado_Player += player->Dado_Player;

        // Verifica se o dado tirado � maior que 6.
        if (player->Dado_Player > 6)
        {
            // Se o dado for maior que 6, jogador perde os pontos da rodada.
            printf("Voc� tirou 1! Perdeu os pontos da rodada.\n");
            player->Resultado_Player = 0;
            return;
        }

        // Exibe o valor tirado no dado.
        printf("Voc� tirou %d\n", player->Dado_Player);

        // Incrementa o n�mero de jogadas.
        (*jogadas)++;

        // Atualiza o ranking do jogador.
        Atualizar_Ranking(player, jogadas, victory);

        // Verifica se a pontua��o do jogador � positiva.
        if (player->Resultado_Player > 0)
        {
            player->Resultado_Def_Player += player->Resultado_Player;
        }

        // Verifica se a pontua��o do jogador atingiu 100.
        if (player->Resultado_Def_Player >= 100)
        {
            // Se a pontua��o do jogador atingir 100, ele ganha.
            system("cls");
            printf("%s ganhou!\n", player->nome);
            Zerar_Dados(player, computador);
            (*victory)++;
            Atualizar_Ranking(player, jogadas, victory);
        }
        else
        {
            // Caso contr�rio, atualiza a pontua��o acumulada do jogador.
            player->Resultado_Def_Player = player->Resultado_Def_Player - player->Resultado_Player;
        }
    }
}

// Fun��o para o jogador decidir segurar os pontos da rodada.
void Segurar_Dado(Player *player)
{
    // Adiciona os pontos da rodada � pontua��o total do jogador.
    player->Resultado_Def_Player += player->Resultado_Player;
    // Zera os pontos da rodada atual.
    player->Resultado_Player = 0;
}

// Fun��o para simular a jogada do computador ao lan�ar um dado.
void Lancar_Dado_PC(PC *computador, Player *player)
{
    // Mensagem indicando que � a vez do computador jogar.
    printf("Vez do Computador\n");

    // Loop enquanto a pontua��o do computador for menor que 100.
    while (computador->Resultado_PC < 100)
    {
        // Gera um n�mero aleat�rio de 1 a 20 para simular o lan�amento do dado pelo computador.
        computador->Dado_PC = 1 + (rand() % 20);

        // Se o resultado do dado for maior que 6, ajusta para um valor entre 2 e 6.
        if (computador->Dado_PC > 6)
        {
            computador->Dado_PC = 2 + rand() % (6 - 2 + 1);
        }

        // Verifica se o computador tirou 1.
        if (computador->Dado_PC == 1)
        {
            // Mensagem indicando que o computador tirou 1 e perdeu os pontos da rodada.
            printf("Computador tirou 1! Perdeu os pontos da rodada.\n");
            // Zera a pontua��o do computador na rodada.
            computador->Resultado_PC = 0;
            // Sai do loop.
            break;
        }
        else
        {
            // Adiciona o resultado do dado � pontua��o do computador na rodada.
            computador->Resultado_PC += computador->Dado_PC;

            // Mensagem indicando o resultado do dado do computador.
            printf("Computador tirou %d\n", computador->Dado_PC);

            // Verifica se a pontua��o total do computador atingiu ou ultrapassou 100.
            if (computador->Resultado_Def_PC >= 100)
            {
                // Mensagem indicando que o computador ganhou.
                system("cls");
                printf("Computador ganhou!\n");
                // Zera as pontua��es para iniciar um novo jogo.
                Zerar_Dados(player, computador);
                // Sai do loop.
                break;
            }

            // Verifica se a pontua��o do computador na rodada atingiu 20.
            if (computador->Resultado_PC >= 20)
            {
                // Mensagem indicando que o computador decidiu parar.
                printf("O computador decidiu parar\n");
                // Adiciona a pontua��o da rodada � pontua��o total do computador.
                computador->Resultado_Def_PC += computador->Resultado_PC;
                // Zera a pontua��o do computador na rodada.
                computador->Resultado_PC = 0;
                // Sai do loop.
                break;
            }
        }
    }
}

// Fun��o para simular o lan�amento de dois dados pelo jogador.
void Lancar_Dois_Dados(Player *player, PC *computador, int *cont_jogadas, int *victory)
{
    // Gera valores aleat�rios para os dois dados do jogador.
    player->Dado_Player = 1 + (rand() % 6);
    player->Dado_Player_2 = 1 + (rand() % 6);

    // Verifica se algum dos dados tirou 1.
    if (player->Dado_Player == 1 || player->Dado_Player_2 == 1)
    {
        // Mensagem indicando que o jogador tirou 1 e perdeu os pontos da rodada.
        printf("Voc� tirou 1! Perdeu os pontos da rodada.\n");
        // Zera a pontua��o do jogador na rodada.
        player->Resultado_Player = 0;
        // Simula a jogada do computador ap�s o jogador tirar 1.
        Lancar_Dois_Dado_PC(computador, player);
    }
    else
    {
        // Adiciona o resultado dos dois dados � pontua��o do jogador na rodada.
        player->Resultado_Player += player->Dado_Player;
        player->Resultado_Player += player->Dado_Player_2;

        // Mensagem indicando os resultados dos dois dados do jogador.
        printf("Voc� tirou %d e %d\n", player->Dado_Player, player->Dado_Player_2);

        // Incrementa o contador de jogadas.
        (*cont_jogadas)++;
        // Atualiza o ranking com base nos resultados da jogada.
        Atualizar_Ranking(player, cont_jogadas, victory);

        // Verifica se a pontua��o do jogador na rodada � positiva.
        if (player->Resultado_Player > 0)
        {
            // Adiciona a pontua��o da rodada � pontua��o total do jogador.
            player->Resultado_Def_Player += player->Resultado_Player;
        }

        // Verifica se a pontua��o total do jogador atingiu ou ultrapassou 100.
        if (player->Resultado_Def_Player >= 100)
        {
            // Mensagem indicando que o jogador ganhou.
            system("cls");
            printf("Player ganhou!\n");
            // Incrementa a contagem de vit�rias.
            (*victory)++;
            // Zera as pontua��es para iniciar um novo jogo.
            Zerar_Dados(player, computador);
            // Atualiza o ranking com base nos resultados da partida.
            Atualizar_Ranking(player, cont_jogadas, victory);
        }
        else
        {
            // Ajusta a pontua��o do jogador na rodada.
            player->Resultado_Def_Player = player->Resultado_Def_Player - player->Resultado_Player;
        }
    }
}

// Fun��o para simular o lan�amento de dois dados pelo computador.
void Lancar_Dois_Dado_PC(PC *computador, Player *player)
{
    // Mensagem indicando que � a vez do computador.
    printf("Vez do Computador\n");

    // Loop enquanto a pontua��o do computador na rodada for menor que 100.
    while (computador->Resultado_PC < 100)
    {
        // Gera valores aleat�rios para os dois dados do computador.
        computador->Dado_PC = 1 + (rand() % 20);
        computador->Dado_PC_2 = 1 + (rand() % 20);

        // Verifica se algum dos dados tirou 1.
        if (computador->Dado_PC == 1 || computador->Dado_PC_2 == 1)
        {
            // Mensagem indicando que o computador tirou 1 e perdeu os pontos da rodada.
            printf("Computador tirou 1! Perdeu os pontos da rodada.\n");
            // Zera a pontua��o do computador na rodada.
            computador->Resultado_PC = 0;
            // Sai do loop.
            break;
        }
        else
        {
            // Adiciona o resultado dos dois dados � pontua��o do computador na rodada.
            computador->Resultado_PC += computador->Dado_PC;
            computador->Resultado_PC += computador->Dado_PC_2;

            // Mensagem indicando os resultados dos dois dados do computador.
            printf("Computador tirou %d e %d\n", computador->Dado_PC, computador->Dado_PC_2);

            // Verifica se a pontua��o total do computador atingiu ou ultrapassou 100.
            if (computador->Resultado_Def_PC >= 100)
            {
                // Mensagem indicando que o computador ganhou.
                system("cls");
                printf("Computador ganhou!\n");
                // Zera as pontua��es para iniciar um novo jogo.
                Zerar_Dados(player, computador);
                // Sai do loop.
                break;
            }

            // Verifica se a pontua��o do computador na rodada � maior ou igual a 20.
            if (computador->Resultado_PC >= 20)
            {
                // Mensagem indicando que o computador decidiu parar.
                printf("O computador decidiu parar\n");
                // Adiciona a pontua��o da rodada � pontua��o total do computador.
                computador->Resultado_Def_PC += computador->Resultado_PC;
                // Zera a pontua��o do computador na rodada.
                computador->Resultado_PC = 0;
                // Sai do loop.
                break;
            }
        }
    }
}

// Fun��o para atualizar o arquivo de ranking com novos resultados do jogador.
void Atualizar_Ranking(Player *player, int *cont_jogadas, int *victory)
{
    // Abre o arquivo de ranking original para leitura.
    FILE *arquivo_ranking_temp = fopen("./arquivo_ranking_temp.txt", "w+");
    FILE *arquivo_ranking = fopen("./arquivo_ranking.txt", "r");

    // Vari�veis para armazenar dados do arquivo de ranking.
    char nome[50];
    int jogadas, vitorias;
    char linha[100];

    // Percorre cada linha do arquivo de ranking original.
    while (fgets(linha, sizeof(linha), arquivo_ranking) != NULL)
    {
        // L� os dados de cada linha.
        sscanf(linha, "%[^,],%d,%d", nome, &jogadas, &vitorias);

        // Verifica se o nome na linha atual � o mesmo do jogador atual.
        if (strcmp(nome, player->nome) == 0)
        {
            // Se for, escreve os novos dados do jogador no arquivo tempor�rio.
            fprintf(arquivo_ranking_temp, "%s,%d,%d\n", player->nome, *cont_jogadas, *victory);
        }
        else
        {
            // Se n�o for, mant�m os dados originais no arquivo tempor�rio.
            fprintf(arquivo_ranking_temp, "%s,%d,%d\n", nome, jogadas, vitorias);
        }
    }

    // Fecha os arquivos.
    fclose(arquivo_ranking_temp);
    fclose(arquivo_ranking);

    // Remove o arquivo de ranking original.
    remove("./arquivo_ranking.txt");
    // Renomeia o arquivo tempor�rio para o nome original.
    rename("./arquivo_ranking_temp.txt", "./arquivo_ranking.txt");
}

// Fun��o de compara��o para qsort, ordena a lista de jogadores com base em crit�rios espec�ficos.
int compararRanking(const void *a, const void *b)
{
    // Converte os ponteiros gen�ricos para ponteiros do tipo Lista_Jogadores.
    const Lista_Jogadores *jogadorA = (const Lista_Jogadores *)a;
    const Lista_Jogadores *jogadorB = (const Lista_Jogadores *)b;

    // Ordena por maior taxa de vit�ria por jogada.
    if (jogadorA->taxa_vitoria_por_jogada > jogadorB->taxa_vitoria_por_jogada)
    {
        return -1;
    }
    else if (jogadorA->taxa_vitoria_por_jogada < jogadorB->taxa_vitoria_por_jogada)
    {
        return 1;
    }

    // Se as taxas de vit�rias por jogada s�o iguais, ordena por maior vit�ria.
    if (jogadorA->vitorias > jogadorB->vitorias)
    {
        return -1;
    }
    else if (jogadorA->vitorias < jogadorB->vitorias)
    {
        return 1;
    }

    // Se as maiores vit�rias s�o iguais, ordena por menor n�mero de jogadas.
    if (jogadorA->jogadas < jogadorB->jogadas)
    {
        return -1;
    }
    else if (jogadorA->jogadas > jogadorB->jogadas)
    {
        return 1;
    }

    // Se todas as condi��es anteriores forem iguais, considera os jogadores como equivalentes.
    return 0;
}

// Fun��o para calcular a taxa de vit�ria por jogada de um jogador.
void CalcularTaxaVitoriaPorJogada(Lista_Jogadores *jogador)
{
    // Adicione o c�lculo da taxa de vit�ria por jogada aqui.

    // Verifica se o jogador possui pelo menos uma jogada para evitar divis�o por zero.
    // Calcula a taxa de vit�ria por jogada usando a f�rmula: (vit�rias / jogadas) se jogadas != 0, sen�o, define como 0.
    jogador->taxa_vitoria_por_jogada = (jogador->jogadas != 0) ? (double)jogador->vitorias / jogador->jogadas : 0;
}

// Fun��o para mostrar o ranking dos jogadores.
void Mostrar_Ranking()
{
    // Abre o arquivo de ranking para leitura.
    FILE *arquivo_ranking = fopen("./arquivo_ranking.txt", "r");

    // Verifica se o arquivo foi aberto corretamente.
    if (arquivo_ranking != NULL)
    {
        Lista_Jogadores lista[100]; // Array para armazenar informa��es dos jogadores.
        char linha[100];            // String para armazenar cada linha do arquivo.
        int cont = 0;               // Contador de jogadores.

        // L� cada linha do arquivo, extrai informa��es e calcula a taxa de vit�ria por jogada.
        while (fgets(linha, sizeof(linha), arquivo_ranking) != NULL)
        {
            sscanf(linha, "%[^,],%d,%d", lista[cont].nome, &lista[cont].jogadas, &lista[cont].vitorias);
            CalcularTaxaVitoriaPorJogada(&lista[cont]); // Calcula a taxa de vit�ria por jogada
            cont++;
        }

        // Ordena o ranking usando qsort com base nas fun��es definidas em compararRanking.
        qsort(lista, cont, sizeof(Lista_Jogadores), compararRanking);

        // Mostra os resultados hier�rquicos no console.
        for (int i = 0; i < cont; i++)
        {
            printf("Nome do jogador: %s\n", lista[i].nome);
            printf("Quantidade de jogadas: %d\n", lista[i].jogadas);
            printf("Quantidade de vit�rias: %d\n\n", lista[i].vitorias);
        }

        getchar();     // Aguarda uma entrada do usu�rio antes de continuar.
        system("cls"); // Limpa a tela do console.

        fclose(arquivo_ranking); // Fecha o arquivo de ranking.
    }
    else
    {
        fprintf(stderr, "Erro ao abrir o arquivo de ranking\n"); // Exibe uma mensagem de erro se o arquivo n�o puder ser aberto.
    }
}

// Fun��o para resetar os dados do jogo (pontua��es, resultados e valores dos dados).
void Zerar_Dados(Player *player, PC *computador)
{
    computador->Resultado_Def_PC = 0; // Zera a pontua��o do computador.
    player->Resultado_Def_Player = 0; // Zera a pontua��o do jogador.
    player->Resultado_Player = 0;     // Zera o resultado da jogada do jogador.
    computador->Resultado_PC = 0;     // Zera o resultado da jogada do computador.
    player->Dado_Player = 0;          // Zera o valor do dado do jogador.
    computador->Dado_PC = 0;          // Zera o valor do dado do computador.
}

// Fun��o para escolher a dificuldade do jogo.
void Dificuldade(int *dificuldade)
{
    // Exibe as op��es de dificuldade.
    printf("1. F�cil\n2. Dif�cil\n");

    // Solicita ao jogador que escolha a dificuldade.
    scanf("%d", &*dificuldade);

    // Limpa a tela do console para melhor visualiza��o.
    system("cls");

    // Estrutura de sele��o para exibir a mensagem correspondente � dificuldade escolhida.
    switch (*dificuldade)
    {
    case 1:
        printf("Modo F�cil\n"); // Mensagem para o modo f�cil.
        break;
    case 2:
        printf("Modo Dif�cil\n"); // Mensagem para o modo dif�cil.
        break;

    default:
        printf("Op��o inv�lida"); // Mensagem para op��o inv�lida.
        break;
    }
}