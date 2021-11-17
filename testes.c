//
// Created by diogo on 13/11/2021.
//

#include <stdio.h>
#include "projetolp1_aed1.h"

LISTA_CLIENTES *lc;


int main_testes() {
    lc = NULL;
    lc = criar_lista_clientes();


    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    /**
     * Testes sobre informaçao dos Clientes
     */

    printf("Testes dos Clientes:\n");

    ///INSERIR CLIENTES
   /* inserir_cliente_cabeca(1, "Diogo", "rua123", 12345, 99999, tm, 1, 2, 2000);
    inserir_cliente_cabeca(3, "Ana", "homeless", 10010, 11111, tm, 2, 4, 1999);
    inserir_cliente_cabeca(4, "Alfredo", "tua tia", 15150, 434313, tm, 4, 6, 2001);
    inserir_cliente_cauda(20, "Baguetes", "homeless part2", 10101010, 666666, tm, 6, 8, 2000);
    inserir_cliente_cabeca(17, "Joaquim", "tua prima", 69690, 420420, tm, 8, 10, 1998);
    inserir_cliente_ordenado(15, "Alberto", "tua mae", 42042, 6969, true, tm, 10, 12, 2000);
    inserir_cliente_ordenado(11, "Alberta", "tua mae", 42042, 6968, false, tm, 20, 7, 2000);
    imprimir_cliente();*/

    ///REMOVER CLIENTES
   // remover_cliente(1);
   // imprimir_cliente();

    ///PROCURAR CLIENTES
    CLIENTES *c1 = procurar_cliente_nome("Alberta");
    if (c1 != NULL) {
        printf("Cliente: id: %d; nome: %s; morada: %s; contacto: %d; NIF: %d; Data Nascimento: %d/%d/%d; Data Registo: %d/%d/%d\n\n",
               c1->id, c1->nome, c1->morada,
               c1->contacto, c1->nif, c1->data_nascimento.dia, c1->data_nascimento.mes, c1->data_nascimento.ano,
               c1->data_registo.dia, c1->data_registo.mes, c1->data_registo.ano);
    }

    ///ORDENAR LISTA LIGADA PELO NIF
   // ordenar_lista_nif();
   // imprimir_ordenado();

    /**
      * Testes sobre Viagens
      */

    printf("\nTestes das Viagens:\n");

    ///INSERIR VIAGEM
   /* inserir_viagem(6968, 1, "Portugal");
    inserir_viagem(6968, 5, "Italia");
    inserir_viagem(6969,2,"Espanha");
    inserir_viagem(420420,2,"Espanha");
    inserir_viagem(420420,3,"ahdbahd");*/

   // imprimir_viagens_cliente(6968);
   // imprimir_viagens_cliente(420420);

    ///EDITAR VIAGENS
   // edit_viagem(6968,2,"Italia");
   // imprimir_viagens_cliente(6968);

    ///PESQUISAR VIAGENS
   // VIAGEM *viagem = pesquisar_viagem(1);

    ///REMOVER VIAGENS
   // remove_viagem(2,6968);
   // remove_viagem(2,420420);

   // printf("here\n");
   // imprimir_viagens_cliente(6968);
   // printf("here22222222\n");
   // imprimir_viagens_cliente(420420);

    /**
     * Testes sobre Cidades das Cidades
     */

    printf("\nTestes das Ciadades:\n");

    ///INSERIR CIDADE
   // inserir_cidade(1, 2, "Braga", "uma merda");
   // inserir_cidade(1, 1, "Porto", "Porto ");
   // inserir_cidade(2, 4, "Coimbra", "asdasd ");
   // inserir_cidade(1, 5, "asdasdwtwf", "asw5j7dasd ");
   // inserir_cidade(1, 6, "nfhgjr", "metyu ");

    ///PESQUISAR CIDADE
   // pesquisar_cidade_nome(1,"Porto");

    ///EDITAR CIDADE
   // edit_cidade(1,1,"Porto","BEST CITY IN DA WORLDS");
    //imprimir

    ///REMOVER CIDADE
   // remove_cidade(1,2);
   // imprimir_viagens_cliente(6968);


   // escrever_clientes_ficheiro_txt("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens.txt");
    escrever_clientes_ficheiro_txt_formatado("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_formatado.txt");
   // ler_ficheiro_txt_("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens.txt");
    ler_ficheiro_txt_formatado("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_formatado.txt");


    return 0;
}

