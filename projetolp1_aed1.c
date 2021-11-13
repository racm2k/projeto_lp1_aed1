//
// Created by diogo on 11/11/2021.
//

#include "projetolp1_aed1.h"

int mainProjeto() {
    LISTA_CLIENTES *lc = NULL;
    lc = criar_lista_clientes();

    inserir_cliente_cabeca(lc, 1, "Diogo", "rua123", 12345, 99999);
    // inserir_cliente_ordenado_nome(lc, 5, "agfga", "gargagg", 124234, 141341341);

    inserir_cliente_cabeca(lc, 3, "Ana", "homeless", 10010, 11111);
    inserir_cliente_cabeca(lc, 4, "Alfredo", "serralheiro", 15150, 434313);
    inserir_cliente_cauda(lc, 20, "Baguetes", "homeless part2", 10101010, 666666);
    inserir_cliente_cabeca(lc, 17, "Joaquim", "carpintrolha", 69690, 420420);
    //  inserir_cliente_ordenado_nome(lc, 5, "Colega", "Fiat 205 turbo", 12345698, 741852963);
    //  inserir_cliente_ordenado_nif(lc, 7, "Miguel", "Fim do mundo", 12345698, 11113);

    imprimir_cliente(lc);
    // remover_cliente(lc, 1);
    // imprimir_cliente(lc);
    // procurar_cliente_nome(lc, "Baguetes");
    procurar_cliente_nif(lc, 11111);

    return 0;
}

void *criar_lista_clientes() {
    LISTA_CLIENTES *node = (LISTA_CLIENTES *) malloc(sizeof(LISTA_CLIENTES));
    node->head = NULL;
    node->num_clentes = 0;
    return node;
}

void inserir_cliente_cabeca(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif) {
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
        novo_no->next = NULL;

        novo_no->next = lc->head;
        lc->head = novo_no;
        lc->num_clentes++;
        return;
    } else {

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
        novo_no->next = NULL;

        novo_no->next = lc->head;
        lc->head = novo_no;
        lc->num_clentes++;
    }

}

void imprimir_cliente(LISTA_CLIENTES *lc) {
    CLIENTES *l = lc->head;
    printf("**************CLIENTES**************\nNum Clientes: %d\n", lc->num_clentes);
    while (l != NULL) {
        printf("Cliente: id: %d, nome: %s, morada: %s, contacto: %d, NIF: %d\n", l->id, l->nome, l->morada,
               l->contacto, l->nif);
        l = l->next;
    }
    printf("**************FIM DE LISTA**********\n");
}

void inserir_cliente_cauda(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif) {
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
    ant->next = NULL;


    current->next = ant;
}

void inserir_cliente_ordenado(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif, bool insNome) {
    CLIENTES *c = (CLIENTES *) malloc(sizeof(CLIENTES));
    c->id = id;
    c->nome = (char *) malloc(50 * sizeof(char));
    strcpy(c->nome, nome);
    c->morada = (char *) malloc(50 * sizeof(char));
    strcpy(c->morada, morada);
    c->contacto = contacto;
    c->nif = nif;
    c->next = NULL;

    if (lc->head == NULL || lc->num_clentes == 0) {
        lc->head = c;
        lc->num_clentes++;
        return;
    } else {

        CLIENTES *current = lc->head, *ant = NULL;

        if (current->id == id || current->nif == nif) { //not
            printf("ERRO -> inserir_cliente_ord(): Ja existe um cliente com esse id/nif!! Cliente nao foi introduzido\n");
            return;
        }

        if (insNome==true){

            while (current != NULL) {
                if (strcmp(nome, current->nome) < 0){
                    ant = current;
                    return;
                }
                current = current->next;
            }

            if (current == lc->head) {//cabeça
                c->next = current;
                lc->head = c;
                lc->num_clentes++;
                return;
            }
            //meio ou cauda
            ant->next = c;
            c->next = current;
            lc->num_clentes++;
        }

    }

}

void inserir_cliente_ordenado_nif(LISTA_CLIENTES *lc, int id, char *nome, char *morada, int contacto, int nif) {
    CLIENTES *c = (CLIENTES *) malloc(sizeof(CLIENTES));
    c->id = id;
    c->nome = (char *) malloc(50 * sizeof(char));
    strcpy(c->nome, nome);
    c->morada = (char *) malloc(50 * sizeof(char));
    strcpy(c->morada, morada);
    c->contacto = contacto;
    c->nif = nif;
    c->next = NULL;

    if (lc->head == NULL || lc->num_clentes == 0) {
        lc->head = c;
        lc->num_clentes++;
        return;
    }

    CLIENTES *current = lc->head, *ant = NULL;

    while (current != NULL && nif > current->nif) {//enquanto n chegar sitio certo
        ant = current;
        current = current->next;
    }

    if (current == lc->head) {//cabeça
        c->next = current;
        lc->head = c;
        lc->num_clentes++;
        return;
    }
    //meio ou cauda
    ant->next = c;
    c->next = current;
    lc->num_clentes++;
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
        lc->num_clentes--;
        return;
    }

    if (current == NULL) {
        printf("O cliente que quer eliminar nao existe!!\n");
        return;
    }

    anterior->next = current->next;
    free(current);
    lc->num_clentes--;
}

CLIENTES *procurar_cliente_nome(LISTA_CLIENTES *lc, const char *nome) {
    CLIENTES *current = lc->head;

    for (int i = 0; i < lc->num_clentes; i++) {
        if (current->nome == nome) {
            return current;
        }
        current = current->next;
    }
    printf("Nao encontramos o cliente pedido!!");
    return NULL;
}

CLIENTES *procurar_cliente_nif(LISTA_CLIENTES *lc, int nif) {
    CLIENTES *current = lc->head;

    for (int i = 0; i < lc->num_clentes; i++) {
        if (current->nif == nif) {
            printf("Encontramos o cliente!! %d", nif);
            return current;
        }
        current = current->next;
    }
    printf("Nao encontramos o cliente pedido!!");
    return NULL;
}