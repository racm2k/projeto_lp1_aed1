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

typedef struct lista_clientes{
    CLIENTES *head;
    int num_clentes;
}LISTA_CLIENTES;

int mainProjeto();
void *criar_lista_clientes();
void inserir_cliente_cabeca(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif);
void imprimir_cliente(LISTA_CLIENTES *slc);
void inserir_cliente_cauda(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif);
void inserir_cliente_ordenado_nome(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif);
void inserir_cliente_ordenado(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif,bool insNome);
void inserir_cliente_ordenado_nif(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif);
void remover_cliente(LISTA_CLIENTES *lc, int id);
CLIENTES *procurar_cliente_nome(LISTA_CLIENTES *lc, const char *nome);
CLIENTES *procurar_cliente_nif(LISTA_CLIENTES *lc, int nif);


#endif //PROJETO_LP1_AED1_PROJETOLP1_AED1_H
