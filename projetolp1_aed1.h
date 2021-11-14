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
    LISTA_PoI *pontos_interesse;
    struct cidade *next;
}CIDADE;

typedef struct lista_cidades{
    CIDADE *head;
    int num_cidades;
}LISTA_CIDADES;

int mainProjeto();
void *criar_lista_clientes();
void inserir_cliente_cabeca(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif,struct tm data, int brithDay, int birthMon, int birthYear);
void imprimir_cliente(LISTA_CLIENTES *lc);
void inserir_cliente_cauda(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif,struct tm data, int brithDay, int birthMon, int birthYear);
void inserir_cliente_ordenado(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif, bool insNome, struct tm data, int brithDay, int birthMon, int birthYear);
void remover_cliente(LISTA_CLIENTES *lc, int id);
CLIENTES *procurar_cliente_nome(LISTA_CLIENTES *lc, const char *nome);
CLIENTES *procurar_cliente_nif(LISTA_CLIENTES *lc, int nif);
void ordenar_lista_nif(LISTA_CLIENTES *lc);
void imprimir_ordenado(LISTA_CLIENTES *st);


void *criar_lista_cidades();
CIDADE *pesquisar_cidade(LISTA_CIDADES *listaCidades, const char *cidade);
void edit_cidade(LISTA_CIDADES *listaCidades,const char *nome_cidade, const char *nova_descricao);

#endif //PROJETO_LP1_AED1_PROJETOLP1_AED1_H
