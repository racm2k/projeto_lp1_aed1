//
// Created by diogo on 11/11/2021.
//

#include "projetolp1_aed1.h"

CLIENTES *headClientes = NULL;


int mainProjeto(int argc, const char *argv) {
    LISTA_CLIENTES *slc = NULL;
    LISTA_CLIENTES lst = {NULL, 0};
    slc = criar_lista_clientes();

    //CLIENTES c = {1, "Diogo", "rua123", 12345, 99999};
    inserir_cliente_cabeca(slc, &headClientes, headClientes, 1, "Diogo", "rua123", 12345, 99999);
    //CLIENTES c1 = {2, "Ana", "homeless", 00000, 11111};
    //inserir_cliente_cabeca(slc,c);
    inserir_cliente_cabeca(slc, &headClientes, headClientes, 3, "Ana", "homeless", 10010, 11111);
    inserir_cliente_cauda(slc, 20, "Baguetes", "homeless part2", 10101010, 666666);
    inserir_cliente_ordenado_nome(slc, 5, "Colega", "Fiat 205 turbo", 12345698, 741852963);
    inserir_cliente_ordenado_nif(slc, 7, "Miguel", "Fim do mundo", 12345698, 11113);


    imprimir_cliente(slc);
}

void *criar_lista_clientes() {
    LISTA_CLIENTES *node = (LISTA_CLIENTES *) malloc(sizeof(LISTA_CLIENTES));
    node->head = NULL;
    node->num_clentes = 0;
    return node;
}

/*void *criar_no_clientes(STRCUCT_LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif){
    LISTCLIENTES *lc = (LISTCLIENTES *) malloc(sizeof (LISTCLIENTES));
    lc->pclientes.id = id;
    lc->pclientes.nome = (char *) malloc(50 * sizeof (char));
    strcpy(lc->pclientes.nome, nome);
    lc->pclientes.contacto = contacto;
    lc->pclientes.morada = (char *) malloc(50 * sizeof (char));
    strcpy(lc->pclientes.morada, morada);
    lc->pclientes.nif = nif;
    lc->next_cliente = NULL;
    return lc;
}*/

/*void inserir_cliente_cabeca(STRCUCT_LISTA_CLIENTES *slc, CLIENTES c){

    LISTCLIENTES *lc = criar_no_clientes(slc, c.id, c.nome, c.morada, c.contacto, c.nif);

    if (lc != NULL){
        if (slc->head == NULL){
            slc->head = lc;
            slc->num_clentes++;
            return;
        }

        LISTCLIENTES *current = slc->head;

        if (current == slc->head){
            lc->next_cliente = current;
            slc->head = lc;
            slc->num_clentes++;
            return;
        }
    }
}*/

void inserir_cliente_cabeca(LISTA_CLIENTES *slc, CLIENTES **head, CLIENTES *no, int id, char *nome, char *morada, int contacto, int nif) {

    CLIENTES *node = no;
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

        novo_no->next = *head;
        *head = novo_no;
        slc->num_clentes++;
        return;
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

    novo_no->next = *head;
    *head = novo_no;
    slc->num_clentes++;
}

/*void imprimir_cliente(STRCUCT_LISTA_CLIENTES *slc){
    LISTCLIENTES *l = slc->head;
    int i = 1;
    while (l != NULL){
        printf("Cliente: id: %d, nome: %s, morada: %s, contacto: %d, NIF: %d\n", l->pclientes.id, l->pclientes.nome,
               l->pclientes.morada, l->pclientes.contacto, l->pclientes.nif);
        i++;
        l = l->next_cliente;
    }
}*/

void imprimir_cliente(LISTA_CLIENTES *slc) {
    CLIENTES *l = headClientes;
    printf("Num Clientes: %d\n",slc->num_clentes);
    while (l != NULL) {
        printf("Cliente: id: %d, nome: %s, morada: %s, contacto: %d, NIF: %d\n", l->id, l->nome, l->morada,
               l->contacto, l->nif);
        l = l->next;
    }
}

void inserir_cliente_cauda(LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif) {
    CLIENTES *current = headClientes, *ant = NULL;

    ant = (CLIENTES *) malloc(sizeof (CLIENTES));
    ant->id = id;
    ant->nome = (char *) malloc(50 * sizeof(char));
    strcpy(ant->nome, nome);
    ant->morada = (char *) malloc(50 * sizeof(char));
    strcpy(ant->morada, morada);
    ant->contacto = contacto;
    ant->nif = nif;
    ant->next = NULL;
    slc->num_clentes++;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = ant;
}

void inserir_cliente_ordenado_nome(LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif) {
    CLIENTES *c = (CLIENTES *) malloc(sizeof (CLIENTES));
    c->id = id;
    c->nome = (char *) malloc(50 * sizeof(char));
    strcpy(c->nome, nome);
    c->morada = (char *) malloc(50 * sizeof(char));
    strcpy(c->morada, morada);
    c->contacto = contacto;
    c->nif = nif;
    c->next = NULL;
    slc->num_clentes++;

    CLIENTES *current = headClientes, *ant = NULL;
    if (current == NULL){//lista vazia
        current = c;
        slc->num_clentes++;
        return;
    }

    while (current != NULL && strcmp(nome, current->nome) > 0){//enquanto n chegar sitio certo
        ant = current;
        current = current->next;
    }

    if (current == slc->head){//cabeça
        c->next = current;
        slc->head = c;
        slc->num_clentes++;
        return;
    }
    //meio ou cauda
    ant->next = c;
    c->next = current;
    slc->num_clentes++;
}

void inserir_cliente_ordenado_nif(LISTA_CLIENTES *slc, int id, char *nome, char *morada, int contacto, int nif) {
    CLIENTES *c = (CLIENTES *) malloc(sizeof (CLIENTES));
    c->id = id;
    c->nome = (char *) malloc(50 * sizeof(char));
    strcpy(c->nome, nome);
    c->morada = (char *) malloc(50 * sizeof(char));
    strcpy(c->morada, morada);
    c->contacto = contacto;
    c->nif = nif;
    c->next = NULL;
    slc->num_clentes++;

    CLIENTES *current = headClientes, *ant = NULL;
    if (current == NULL){//lista vazia
        current = c;
        slc->num_clentes++;
        return;
    }

    while (current != NULL && nif > current->nif){//enquanto n chegar sitio certo
        ant = current;
        current = current->next;
    }

    if (current == slc->head){//cabeça
        c->next = current;
        slc->head = c;
        slc->num_clentes++;
        return;
    }
    //meio ou cauda
    ant->next = c;
    c->next = current;
    slc->num_clentes++;
}

void remover_cliente(CLIENTES **head, int id){

}

