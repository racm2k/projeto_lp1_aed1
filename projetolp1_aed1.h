//
// Created by diogo on 11/11/2021.
//

#ifndef PROJETO_LP1_AED1_PROJETOLP1_AED1_H
#define PROJETO_LP1_AED1_PROJETOLP1_AED1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/*typedef struct listClientes{
    CLIENTES pclientes;
    struct listClientes *next_cliente;
}LISTCLIENTES;

typedef struct struct_lista_clientes{
    CLIENTES *head;
    int num_clentes;
}STRCUCT_LISTA_CLIENTES;*/

typedef struct lista_clientes{
    CLIENTES *head;
    int num_clentes;
}LISTA_CLIENTES;

int mainProjeto(int argc,const char *argv);
//void inserir_cliente_cabeca();
void *criar_lista_clientes();
//void *criar_no_clientes(STRCUCT_LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif);
//void inserir_cliente_cabeca(STRCUCT_LISTA_CLIENTES *slc, CLIENTES c);
void inserir_cliente_cabeca(LISTA_CLIENTES *slc, CLIENTES **head, CLIENTES *no, int id, char *nome, char *morada, int contacto, int nif);
//void imprimir_cliente(STRCUCT_LISTA_CLIENTES *slc);
void imprimir_cliente(LISTA_CLIENTES *slc);
void inserir_cliente_cauda(LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif);
void inserir_cliente_ordenado_nome(LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif);
void inserir_cliente_ordenado_nif(LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif);
void remover_cliente(CLIENTES **head, int id);


#endif //PROJETO_LP1_AED1_PROJETOLP1_AED1_H
