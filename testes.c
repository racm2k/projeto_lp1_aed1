//
// Created by diogo on 13/11/2021.
//

#include <stdio.h>
#include "projetolp1_aed1.h"

int main_testes() {
    LISTA_CLIENTES *lc = NULL;
    lc = criar_lista_clientes();

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    /**
     * Testes sobre informaçao dos Clientes
     */

    //INSERIR CLIENTES
   /* inserir_cliente_cabeca(lc, 1, "Diogo", "rua123", 12345, 99999, tm, 1, 2, 2000);
    inserir_cliente_cabeca(lc, 3, "Ana", "homeless", 10010, 11111, tm, 2, 4, 1999);
    inserir_cliente_cabeca(lc, 4, "Alfredo", "tua tia", 15150, 434313, tm, 4, 6, 2001);
   // inserir_cliente_cauda(lc, 20, "Baguetes", "homeless part2", 10101010, 666666, tm, 6, 8, 2000);
    inserir_cliente_cabeca(lc, 17, "Joaquim", "tua prima", 69690, 420420, tm, 8, 10, 1998);
    inserir_cliente_ordenado(lc, 15, "Alberto", "tua mae", 42042, 6969, true, tm, 10, 12, 2000);
    inserir_cliente_ordenado(lc, 11, "Alberta", "tua mae", 42042, 6968, false, tm, 20, 7, 2000);
   // imprimir_cliente(lc);*/

    //REMOVER CLIENTES
    // remover_cliente(lc, 1);
    // imprimir_cliente(lc);

    //PROCURAR CLIENTES
    CLIENTES *c1 = procurar_cliente_nome(lc, "Baguetes");
    printf("Cliente: id: %d ; nome: %s ; morada: %s ; contacto: %d ; NIF: %d ; Data Nascimento: %d/%d/%d ; Data Registo: %d/%d/%d\n",
           c1->id, c1->nome, c1->morada,
           c1->contacto, c1->nif, c1->data_nascimento.dia, c1->data_nascimento.mes, c1->data_nascimento.ano,
           c1->data_registo.dia, c1->data_registo.mes, c1->data_registo.ano);

    //ORDENAR LISTA LIGADA PELO NIF
    imprimir_cliente(lc);
   // ordenar_lista_nif(lc);
   // imprimir_ordenado(lc);



    return 0;
}

