//
// Created by diogo on 13/11/2021.
//

#include <stdio.h>
#include "projetolp1_aed1.h"

LISTA_CLIENTES *lc;
LISTA_CIDADES *lcidades;

int main_testes() {
    lc = NULL;
    lc = criar_lista_clientes();


    lcidades = NULL;
    lcidades = criar_lista_cidades();

//        ler_clientes_viagens_ficheiro_bin("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/clientes_viagens_bin.bin");
    /**
     * Testes sobre informaçao dos Clientes
     */

    printf("Testes dos Clientes:\n");

    ///INSERIR CLIENTES
/*
     inserir_cliente_cabeca(1, "Diogo", "rua123", 12345, 99999, 1, 2, 2000, 10, 10, 2010);
     inserir_cliente_cabeca(3, "Ana", "homeless", 10010, 11111, 2, 4, 1999, 20, 21, 2021);
     inserir_cliente_cabeca(4, "Alfredo", "tua tia", 15150, 434313, 4, 6, 2001, 3, 4, 2005);
     inserir_cliente_cauda(20, "Baguetes", "homeless part2", 10101010, 666666, 6, 8, 2000, 1, 2, 2001);
     inserir_cliente_cabeca(17, "Joaquim", "tua prima", 69690, 420420, 8, 10, 1998, 5, 6, 1999);
     inserir_cliente_ordenado(15, "Alberto", "tua mae", 42042, 6969, true, 10, 12, 2000, 30, 12, 2222);
     inserir_cliente_ordenado(11, "Alberta", "tua mae", 42042, 6968, false, 20, 7, 2000, 17, 11, 2231);
*/
//          imprimir_clientes();

    ///REMOVER CLIENTES
    // remover_cliente(1);
//    imprimir_clientes();

    ///PROCURAR CLIENTES
    /* CLIENTES *c1 = procurar_cliente_nome("Alberta");
     if (c1 != NULL) {
         printf("Cliente: id: %d; nome: %s; morada: %s; contacto: %d; NIF: %d; Data Nascimento: %d/%d/%d; Data Registo: %d/%d/%d\n\n",
                c1->id, c1->nome, c1->morada,
                c1->contacto, c1->nif, c1->data_nascimento.dia, c1->data_nascimento.mes, c1->data_nascimento.ano,
                c1->data_registo.dia, c1->data_registo.mes, c1->data_registo.ano);
     }*/

    ///ORDENAR LISTA LIGADA PELO NIF
    // ordenar_lista_nif();
    // imprimir_ordenado();

    /**
      * Testes sobre Viagens
      */

    printf("\nTestes das Viagens:\n");

//    ///INSERIR VIAGEM
/*
     inserir_viagem(6968, 1, "Portugal", true,5,11,2022,12,11,2022);
     inserir_viagem(6968, 5, "Italia", true,21,12,2022,1,1,2023);
     inserir_viagem(6969, 2, "Espanha", true,10,10,2021,20,10,2021);
     inserir_viagem(420420, 2, "Espanha", true,15,11,2021,15,5,2022);
     inserir_viagem(420420, 3, "ahdbahd", true,19,8,2022,5,11,2022);
*/
    // imprimir_viagens_cliente(6968);
    // imprimir_viagens_cliente(420420);

    ///EDITAR VIAGENS
    // edit_viagem(6968,2,"Italia");
    // imprimir_viagens_cliente(6968);

    ///PESQUISAR VIAGENS
    // VIAGEM *viagem = pesquisar_viagem(1);

    // viagem=pesquisar_viagem(1);
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

    printf("\nTestes das Cidades:\n");

    ///INSERIR CIDADE
    // inserir na estrutura para as inserçoes manuais
  /*  inserir_cidade_lista_global(2, "Braga", "uma merda", 0.0, 1.0);
    inserir_cidade_lista_global(1, "Porto", "capital", 2.0, 3.0);
*/
/*
    inserir_cidade_numa_viagem(1, 2, "Braga", "uma merda",254.13f,153.6f);
    inserir_cidade_numa_viagem(1, 1, "Porto", "Porto ",534.24f,765.42f);
    inserir_cidade_numa_viagem(2, 4, "Coimbra", "asdasd ",765.345f,234.654f);
    inserir_cidade_numa_viagem(1, 5, "asdasdwtwf", "asw5j7dasd ",654.74f,746.46f);
    inserir_cidade_numa_viagem(1, 6, "nfhgjr", "metyu ",245.63f,275.46f);
*/
 //    imprimir_viagens_cliente(6968);

    ///PESQUISAR CIDADE
//    pesquisar_cidade_nome(1,"Porto");

    ///EDITAR CIDADE
   // edit_cidade(1,1,"Porto","BEST CITY IN DA WORLDS");
    //imprimir

    ///REMOVER CIDADE
   // remove_cidade(1,2);
/*
    inserir_PoI("Porto", 1, "Estadio do Dragao");
    inserir_PoI("Porto", 2, "Aliados");
    inserir_PoI("Porto", 3, "Clerigos");
    inserir_PoI("Porto", 4, "UFP");
    */
//    imprimir_pois("Porto");
    // remover_PoI_cidade("Porto","UFP");
    // imprimir_pois("Porto");

//    ler_clientes_ficheiro_txt_formatado("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/clientes_viagens_formatado.txt");
  //  escrever_clientes_ficheiro_txt_formatado("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/clientes_viagens_formatado.txt");
//    escrever_clientes_viagens_bin("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/clientes_viagens_bin.bin");
//    escrever_cidades_ficheiro_txt("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/cidades_pois.txt");
    ler_clientes_viagens_ficheiro_bin("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/clientes_viagens_bin.bin");
    ler_cidade_ficheiro_txt("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/cidades_pois.txt");

    escrever_cidades_pois_bin("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/cidades_pois_bin.bin");
    ler_cidades_pois_ficheiro_bin("/home/racm2k/CLionProjects/projeto_lp1_aed1/data/cidades_pois_bin.bin");
//     imprimir_viagens_cliente(6968);

    // remover_PoI_cidade("Porto","Estadio do Dragao");
    // edit_PoI("Porto","UFP","UFP Caralho!");
    // imprimir_pois("Porto");
    // pesquisar_PoI("Porto","Estadio do Dragao");
    // imprimir_clientes();
    // print_HistoricoViagens_cliente(6968,"Porto",0);

    return 0;
}

