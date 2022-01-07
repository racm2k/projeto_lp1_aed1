//
// Created by diogo on 11/11/2021.
//

#ifndef PROJETO_LP1_AED1_PROJETOLP1_AED1_H
#define PROJETO_LP1_AED1_PROJETOLP1_AED1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct ponto {
    float x, y;
} COORDS;

typedef struct data {
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct pontos_interesse {
    char *nome;
    int id_PoI;
    struct pontos_interesse *next;
} PoI;

typedef struct cidade {
    int id;
    char *nome;
    COORDS localizacao;
    char *descricao;
    PoI *head_pontos_interesse;
    int num_PoI;
    struct cidade *next;
} CIDADE;

typedef struct lista_cidades {
    CIDADE *head_cidades;
    int num_cidades;
    int maxNum_cidades;
} LISTA_CIDADES;

typedef struct viagem {
    int id;
    char *pais;
    bool concluida;
    DATA data_inicio;
    DATA data_fim;
    int nif_cliente;
    CIDADE *cidades;
    int num_cidades;
    int maxNum_cidades;
    struct viagem *next;
    int cap_cidades;
} VIAGEM;


typedef struct clientes {
    int id;
    char *nome;
    char *morada;
    int contacto;
    int nif;
    DATA data_nascimento;
    DATA data_registo;
    VIAGEM *viagens_arr;
    int num_viagens;
    int maxNum_viagens;
    struct clientes *next;
} CLIENTES;

typedef struct lista_clientes {
    CLIENTES *head_clientes;
    int num_clientes;
} LISTA_CLIENTES;

int mainProjeto();
void *criar_lista_clientes();
void *criar_lista_PoI();
void *criar_lista_viagens();
void *criar_lista_cidades();
void inserir_cliente_cabeca(int id, char *nome, char *morada, int contacto, int nif, int brithDay, int birthMon,
                            int birthYear, int diaRegisto, int mesRegisto, int anoRegisto);
void imprimir_clientes();
void imprimir_viagens_cliente(int nif);
void inserir_cliente_cauda(int id, char *nome, char *morada, int contacto, int nif, int brithDay,
                           int birthMon, int birthYear, int diaRegisto, int mesRegisto, int anoRegisto);
void inserir_cliente_ordenado(int id, char *nome, char *morada, int contacto, int nif, bool insNome, int brithDay,
                              int birthMon, int birthYear, int diaRegisto, int mesRegisto, int anoRegisto);
void remover_cliente(int id);
CLIENTES *procurar_cliente_nome(const char *nome);
CLIENTES *procurar_cliente_nif(int nif);

void ordenar_lista_nif();
void imprimir_ordenado();


void inserir_cidade_numa_viagem(int id_viagem, int id_cidade, char *nome_cidade, char *descricao, float x, float y);
void inserir_cidade_lista_global(int id_cidade, char *nome_cidade, char *descricao, float x, float y);
CIDADE *pesquisar_cidade_nome(int id_viagem, char *cidade);
void edit_cidade(int id_viagem, int id_cidade, char *nome_cidade, const char *nova_descricao);
void remove_cidade(int id_viagem, int id_cidade);
void inserir_viagem(int nif, int id_viagem, char *pais_destino, bool isConcluida, int beginDay, int beginMon, int beginYear,
               int endDay, int endMon, int endYear);
void edit_viagem(int nif_cliente, int id_viagem, char *novo_pais);
VIAGEM *pesquisar_viagem(int id_viagem);
void remove_viagem(int id_cliente, int id_viagem);

void imprimir_pois(char *nome_cidade);
void remover_PoI_cidade(char *nome_cidade, char *nome_poi);
void inserir_PoI(char *nome_cidade, int id_poI, char *nome_poI);
PoI *pesquisar_PoI(char *nome_cidade, char *nome_PoI);
void edit_PoI(char *nome_cidade, char *nome_poi, char *novo_nomePoi);

void print_HistoricoViagens_cliente(int nif_cliente, char *pesquisa, int tipoPesquisa);

void escrever_clientes_ficheiro_txt(char *filename);
void escrever_cidades_ficheiro_txt(char *filename);

void ler_cidade_ficheiro_txt(char *filename);
void ler_ficheiro_txt_(char *filename);

void ler_clientes_ficheiro_txt_formatado(char *filename);
void escrever_clientes_ficheiro_txt_formatado(char *filename);

void escrever_clientes_viagens_bin(char *filename);
void ler_clientes_viagens_ficheiro_bin(char *filename);

void ler_cidades_pois_ficheiro_bin(char *filename);
void escrever_cidades_pois_bin(char *filename);

void gerar_relatorio_viagens_cliente_betweenDates(int nif_cliente,DATA dataMin, DATA dataMax, char *filename);

int isBeforeDate(DATA data1, DATA data2);


void quickSort(VIAGEM array[], int low, int high);
int partition(VIAGEM array[], int low, int high);
void swap(VIAGEM *a, VIAGEM *b);
void printArray(VIAGEM array[], int size);
void createPopulation(CLIENTES *cliente, int id_viagem);
int check_arrays(int *arr1[], int size, int *arr2[]);
double dist(COORDS c1, COORDS c2);

#endif //PROJETO_LP1_AED1_PROJETOLP1_AED1_H
