#ifndef LIB_H
#define LIB_H

// Inclus�o das bibliotecas nativas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

// Defini��o de constante para o n�mero m�ximo de jogadores
#define MAX_PLAYERS 100

// Defini��o de estruturas

// Estrutura para armazenar informa��es do jogador
typedef struct
{
    char nome[50];
    int Dado_Player;
    int Dado_Player_2;
    int Resultado_Player;
    int Resultado_Def_Player;
} Player;

// Estrutura para armazenar informa��es do computador
typedef struct
{
    int Dado_PC;
    int Dado_PC_2;
    int Resultado_PC;
    int Resultado_Def_PC;
} PC;

// Estrutura para armazenar informa��es da lista de jogadores
typedef struct
{
    char nome[50];
    int jogadas;
    int vitorias;
    double taxa_vitoria_por_jogada;
} Lista_Jogadores;

// Prot�tipos de fun��es

// Exibe o menu principal
void Menu();

// Exibe o menu de login
void Menu_Login(int, Player *, int *, int *);

// Realiza o cadastro de jogadores
void Cadastro(Player *, int *, int *, int);

// Realiza o login de jogadores
void Login(int, Player *, int *, int *);

// Realiza o lan�amento do dado pelo jogador
void Lancar_Dado(Player *, PC *, int *, int *);

// Realiza o lan�amento do dado pelo computador
void Lancar_Dado_PC(PC *, Player *);

// Atualiza os resultados ap�s o jogador decidir segurar o dado
void Segurar_Dado(Player *);

// Realiza o lan�amento de dois dados pelo jogador
void Lancar_Dois_Dados(Player *, PC *, int *, int *);

// Realiza o lan�amento de dois dados pelo computador
void Lancar_Dois_Dado_PC(PC *, Player *);

// Fun��o de compara��o utilizada para ordenar o ranking
int compararRanking(const void *, const void *);

// Calcula a taxa de vit�ria por jogada para um jogador
void CalcularTaxaVitoriaPorJogada(Lista_Jogadores *);

// Exibe o ranking dos jogadores
void Mostrar_Ranking();

// Atualiza as informa��es no arquivo de ranking
void Atualizar_Ranking(Player *, int *, int *);

// Zera os dados dos jogadores e do computador
void Zerar_Dados(Player *, PC *);

// Define a dificuldade do jogo
void Dificuldade(int *);

#endif