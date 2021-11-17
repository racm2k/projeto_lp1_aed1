//
// Created by diogo on 13/11/2021.
//

#include <stdio.h>
#include "projetolp1_aed1.h"

LISTA_CLIENTES *lc;
LISTA_VIAGENS *lv;
LISTA_CIDADES *lcidades;
LISTA_PoI *listaPoI;


int main_testes() {
    lc = NULL;
    lc = criar_lista_clientes();

    lv = NULL;
    lv = criar_lista_viagens();

    lcidades = NULL;
    lcidades = criar_lista_cidades();

    listaPoI = NULL;
    listaPoI = criar_lista_PoI();

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    /**
     * Testes sobre informaçao dos Clientes
     */

    ///INSERIR CLIENTES
    inserir_cliente_cabeca(1, "Diogo", "rua123", 12345, 99999, tm, 1, 2, 2000);
    inserir_cliente_cabeca(3, "Ana", "homeless", 10010, 11111, tm, 2, 4, 1999);
    inserir_cliente_cabeca(4, "Alfredo", "tua tia", 15150, 434313, tm, 4, 6, 2001);
    inserir_cliente_cabeca(17, "Joaquim", "tua prima", 69690, 420420, tm, 8, 10, 1998);
    inserir_cliente_cauda(20, "Baguetes", "homeless part2", 10101010, 666666, tm, 6, 8, 2000);
    inserir_cliente_ordenado(15, "Alberto", "tua mae", 42042, 6969, true, tm, 10, 12, 2000);
    inserir_cliente_ordenado(11, "Alberta", "tua mae", 42042, 6968, false, tm, 20, 7, 2000);
    imprimir_clientes();

    ///REMOVER CLIENTES
    remover_cliente(1);
    imprimir_clientes();

    ///PROCURAR CLIENTES
    procurar_cliente_nome("Alberta");


    ///ORDENAR LISTA LIGADA PELO NIF
//    ordenar_lista_nif();
//    imprimir_ordenado();

    ///INSERIR VIAGEM
    inserir_viagem(6968, 1, "Portugal",true);
//    inserir_viagem(6968,2,"Espanha");
//    inserir_viagem(420420,2,"Espanha");
//    inserir_viagem(6968,1,"Portugal");
//    imprimir_viagens_cliente(6968);

    ///EDITAR VIAGENS
//    edit_viagem(6968,2,"Italia");

    ///PESQUISAR VIAGENS
    VIAGEM *viagem = (VIAGEM *) malloc(sizeof(VIAGEM));

//    viagem=pesquisar_viagem(1);
    ///REMOVER VIAGENS

    ///INSERIR CIDADE
//    inserir_cidade(1, 2, "Braga", "uma merda");
    inserir_cidade(1, 1, "Porto", "Porto ");
//    inserir_cidade(2, 4, "Coimbra", "asdasd ");

//    remove_viagem(6968,2);
//    remove_viagem(420420,2);
//    inserir_cidade(1, 5, "asdasdwtwf", "asw5j7dasd ");
//    inserir_cidade(1, 6, "nfhgjr", "metyu ");
    ///PESQUISAR CIDADE
    pesquisar_cidadeOfViagem_nome(1,"Porto");
    ///EDITAR CIDADE
//    edit_cidade(1,1,"Porto","BEST CITY IN DA WORLDS");
    ///REMOVER CIDADE
//    remove_cidade(1,2);

//    printf("boas\n");

//    imprimir_viagens_cliente(6968);
//    imprimir_viagens_cliente(420420);

    inserir_PoI("Porto",1,"Estadio do Dragao");
    inserir_PoI("Porto",2,"Aliados");
    inserir_PoI("Porto",3,"Clérigos");
    inserir_PoI("Porto",4,"UFP");
    imprimir_pois("Porto");
//    remover_PoI_cidade("Porto","Estadio do Dragao");
    edit_PoI("Porto","UFP","UFP Caralho!");
    imprimir_pois("Porto");
    pesquisar_PoI("Porto","Estadio do Dragao");

    print_HistoricoViagens_cliente(6968,"Porto",0);
    return 0;
}

