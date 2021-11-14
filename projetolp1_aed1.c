//
// Created by diogo on 11/11/2021.
//

#include "projetolp1_aed1.h"
#include "testes.c"


int mainProjeto() {
    main_testes();

    return 0;
}

void *criar_lista_clientes() {
    LISTA_CLIENTES *node = (LISTA_CLIENTES *) malloc(sizeof(LISTA_CLIENTES));
    node->head = NULL;
    node->num_clientes = 0;
    return node;
}

void inserir_cliente_cabeca(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif, struct tm data, int brithDay, int birthMon, int birthYear) {
    CLIENTES *node = lc->head;
    if (node == NULL) {
        CLIENTES *novo_no = (CLIENTES *) malloc(sizeof(CLIENTES));

        novo_no->id = id;
        novo_no->nome = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->nome, nome);
        novo_no->morada = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->morada, morada);
        novo_no->contacto = contacto;
        novo_no->nif = nif;
        novo_no->data_nascimento.dia = brithDay;
        novo_no->data_nascimento.mes = birthMon;
        novo_no->data_nascimento.ano = birthYear;
        novo_no->data_registo.ano = data.tm_year + 1900;
        novo_no->data_registo.mes = data.tm_mon + 1;
        novo_no->data_registo.dia = data.tm_mday;
        novo_no->next = NULL;

        novo_no->next = lc->head;
        lc->head = novo_no;
        lc->num_clientes++;
        return;
    }
    else {
        while (node != NULL) {//JA NAO É INFINITO

            if (node->id == id || node->nif == nif) {
                printf("ERRO -> inserir_cliente_cabeca(): Ja existe um cliente com esse id/nif!! Cliente nao foi introduzido\n");
                return;
            }
            node = node->next;
        }

        CLIENTES *novo_no = (CLIENTES *) malloc(sizeof(CLIENTES));

        novo_no->id = id;
        novo_no->nome = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->nome, nome);
        novo_no->morada = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->morada, morada);
        novo_no->contacto = contacto;
        novo_no->nif = nif;
        novo_no->data_nascimento.dia = brithDay;
        novo_no->data_nascimento.mes = birthMon;
        novo_no->data_nascimento.ano = birthYear;
        novo_no->data_registo.ano = data.tm_year + 1900;
        novo_no->data_registo.mes = data.tm_mon + 1;
        novo_no->data_registo.dia = data.tm_mday;
        novo_no->next = NULL;

        novo_no->next = lc->head;
        lc->head = novo_no;
        lc->num_clientes++;
    }
}

void imprimir_cliente(LISTA_CLIENTES *lc) {
    CLIENTES *l = lc->head;
    printf("**************CLIENTES*************\nnum_clientes: %d\n", lc->num_clientes);
    while (l != NULL) {
        printf("Cliente: id: %d ; nome: %s ; morada: %s ; contacto: %d ; NIF: %d ; Data Nascimento: %d/%d/%d ; Data Registo: %d/%d/%d\n",
               l->id, l->nome, l->morada,
               l->contacto, l->nif, l->data_nascimento.dia, l->data_nascimento.mes, l->data_nascimento.ano,
               l->data_registo.dia, l->data_registo.mes, l->data_registo.ano);
        l = l->next;
    }
    printf("**************FIM DE LISTA**********\n");
}

void inserir_cliente_cauda(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif, struct tm data, int brithDay, int birthMon, int birthYear) {
    CLIENTES *current = lc->head, *ant = NULL;

    while (current->next != NULL) { //JA ENTROU
        if (current->id == id || current->nif == nif) {
            printf("ERRO -> inserir_cliente_cauda(): Ja existe um cliente com esse id/nif!! Cliente nao foi introduzido\n");
            return;
        }
        current = current->next;
    }

    ant = (CLIENTES *) malloc(sizeof(CLIENTES));
    ant->id = id;
    ant->nome = (char *) malloc(50 * sizeof(char));
    strcpy(ant->nome, nome);
    ant->morada = (char *) malloc(50 * sizeof(char));
    strcpy(ant->morada, morada);
    ant->contacto = contacto;
    ant->nif = nif;
    ant->data_nascimento.dia = brithDay;
    ant->data_nascimento.ano = birthYear;
    ant->data_nascimento.mes = birthMon;
    ant->data_registo.ano = data.tm_year + 1900;
    ant->data_registo.mes = data.tm_mon + 1;
    ant->data_registo.dia = data.tm_mday;
    ant->next = NULL;

    current->next = ant;
    lc->num_clientes++;
}

void inserir_cliente_ordenado(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif, bool insNome, struct tm data, int brithDay, int birthMon, int birthYear) {
    CLIENTES *c = (CLIENTES *) malloc(sizeof(CLIENTES));
    c->id = id;
    c->nome = (char *) malloc(50 * sizeof(char));
    strcpy(c->nome, nome);
    c->morada = (char *) malloc(50 * sizeof(char));
    strcpy(c->morada, morada);
    c->contacto = contacto;
    c->nif = nif;
    c->data_nascimento.dia = brithDay;
    c->data_nascimento.ano = birthYear;
    c->data_nascimento.mes = birthMon;
    c->data_registo.ano = data.tm_year + 1900;
    c->data_registo.mes = data.tm_mon + 1;
    c->data_registo.dia = data.tm_mday;
    c->next = NULL;

    if (lc->head == NULL || lc->num_clientes == 0){
        lc->head = c;
        lc->num_clientes++;
        return;
    }
    else {
        CLIENTES *current = lc->head, *ant = NULL;

        while (current->next != NULL){
            if (current->id == id || current->nif == nif){
                printf("ERRO -> inserir_cliente_ord(): Ja existe um cliente com esse id/nif!! Cliente nao foi introduzido\n");
                return;
            }
            current = current->next;
        }
        current = lc->head;

        if (insNome == true) {  // INSERIR ORDENADO PELO NOME
            while (current != NULL && strcmp(nome, current->nome) > 0){//enquanto n chegar sitio certo NOME
                ant = current;
                current = current->next;
            }
            if (current == lc->head) {//cabeça
                c->next = current;
                lc->head = c;
                lc->num_clientes++;
                return;
            }
            //meio ou cauda
            ant->next = c;
            c->next = current;
            lc->num_clientes++;
        }
        else { // INSERIR ORDENADO PELO NIF
            while (current != NULL && nif > current->nif) {//enquanto n chegar sitio certo NIF
                ant = current;
                current = current->next;
            }
            if (current == lc->head) {//cabeça
                c->next = current;
                lc->head = c;
                lc->num_clientes++;
                return;
            }
            //meio ou cauda
            ant->next = c;
            c->next = current;
            lc->num_clientes++;
        }
    }
}

void remover_cliente(LISTA_CLIENTES *lc, int id) {
    if (lc->head == NULL) {
        printf("A lista esta vazia!!");
        return;
    }

    CLIENTES *anterior = NULL, *current = lc->head;

    while (current != NULL && current->id != id) {
        anterior = current;
        current = current->next;
    }

    if (current == lc->head) {
        lc->head = lc->head->next;
        free(current);
        lc->num_clientes--;
        return;
    }

    if (current == NULL) {
        printf("O cliente que quer eliminar nao existe!!\n");
        return;
    }

    anterior->next = current->next;
    free(current);
    lc->num_clientes--;
}

CLIENTES *procurar_cliente_nome(LISTA_CLIENTES *lc, const char *nome) {
    CLIENTES *current = lc->head;

    if (current == NULL){
        printf("A lista esta vazia!!\n");
        return 0;
    }

    for (int i = 0; i < lc->num_clientes; i++) {
        if (strcmp(current->nome, nome) == 0) {
            printf("Encontramos o cliente!! Nome: %s\n", nome);
            return current;
        }
        current = current->next;
    }
    printf("Nao encontramos o cliente pedido!!\n");
    return 0;
}

CLIENTES *procurar_cliente_nif(LISTA_CLIENTES *lc, int nif) {
    CLIENTES *current = lc->head;

    if (current == NULL){
        printf("A lista esta vazia!!\n");
        return 0;
    }

    for (int i = 0; i < lc->num_clientes; i++) {
        if (current->nif == nif) {
            printf("Encontramos o cliente!! Nif: %d\n", nif);
            return current;
        }
        current = current->next;
    }
    printf("Nao encontramos o cliente pedido!!\n");
    return 0;
}

void ordenar_lista_nif(LISTA_CLIENTES *lc) {
    CLIENTES *current = lc->head, *nova = NULL;
    int aux;

    if (current == NULL) {
        printf("Nao existe nenhum cliente na lista!");
        return;
    }

    while (current != NULL) {
        nova = current->next;

        while (nova != NULL) {
            if (current->nif > nova->nif) {  //se o nif for > q o nif da nova
                aux = current->nif;        //guardo o valor do nif na variavel temp
                current->nif = nova->nif;   //e mete no meu current nif a variavel q estava no nova
                nova->nif = aux;           //ponho no nova a variavel q estava no temp q era o current nif
            }
            nova = nova->next;
        }
        current = current->next;
    }
}

void imprimir_ordenado(LISTA_CLIENTES *st) {
    CLIENTES *current = st->head;
    printf("**************Lista Ordenada*************\n");
    while (current != NULL) {
        printf("NIF: %d;\t Nome: %s \n", current->nif, current->nome);
        current = current->next;
    }
}