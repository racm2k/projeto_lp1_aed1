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

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct clientes{
    int id;
    char *nome;
    char *morada;
    int contacto;
    int nif;
    DATA data_nascimento;
    DATA data_registo;
    struct clientes *next;
}CLIENTES;

typedef struct pontos_interesse{
    char *nome;
    struct pontos_interesse *next;
}PoI;

typedef struct lista_PoI{
    PoI *head;
    int num_PoI;
}LISTA_PoI;

typedef struct lista_clientes{
    CLIENTES *head;
    int num_clientes;
}LISTA_CLIENTES;

typedef struct cidade{
    char *nome;
    char *descricao;
    PoI *pontos_interesse;
    int num_PoI;
    struct cidade *next;
}CIDADE;

typedef struct lista_cidades{
    CIDADE *head;
    int num_cidades;
}LISTA_CIDADES;

typedef struct viagem{
    int id;
    char *pais;
    struct viagem *next;
}VIAGEM;

int mainProjeto();
void *criar_lista_clientes();
void *criar_lista_PoI();
void inserir_cliente_cabeca(int id, char *nome, char *morada, int contacto, int nif,struct tm data, int brithDay, int birthMon, int birthYear);
void imprimir_cliente();
void inserir_cliente_cauda(int id, char *nome, char *morada, int contacto, int nif,struct tm data, int brithDay, int birthMon, int birthYear);
void inserir_cliente_ordenado(int id, char *nome, char *morada, int contacto, int nif, bool insNome, struct tm data, int brithDay, int birthMon, int birthYear);
void remover_cliente(int id);
CLIENTES *procurar_cliente_nome(const char *nome);
CLIENTES *procurar_cliente_nif(int nif);
void ordenar_lista_nif();
void imprimir_ordenado();


void *criar_lista_cidades();
CIDADE *pesquisar_cidade(const char *cidade);
void edit_cidade(const char *nome_cidade, const char *nova_descricao);

int check_dups_PoI(char *nome_cidade, char *nome_PoI);
void insert_PoI(char *nome_cidade, char *nome_PoI);
void addPoItoGlobalList(PoI *poI);
void edit_PoI(char *nome_cidade, char *nome_PoI, char *novoNome_PoI);
PoI *pesquisar_PoI(char *nome_cidade,char *nome_PoI);
void remove_PoI(char *nome_PoI);

#endif //PROJETO_LP1_AED1_PROJETOLP1_AED1_H
