//
// Created by diogo on 13/11/2021.
//

#include <stdio.h>
#include "projetolp1_aed1.h"

LISTA_CLIENTES *lc;
LISTA_CIDADES *lcidades;
POPULACAO *populacoes;
ALGORITMO alg;

int main_testes() {
    lc = NULL;
    lc = criar_lista_clientes();

    lcidades = NULL;
    lcidades = criar_lista_cidades();

    //ler_cidade_ficheiro_txt("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_formatado.txt");
    //ler_clientes_ficheiro_txt_formatado("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_formatado.txt");
    //ler_clientes_viagens_ficheiro_bin("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_bin.bin");
    //ler_cidade_ficheiro_txt("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\cidades_pois.txt");
   // ler_cidades_pois_ficheiro_bin("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\cidades_pois_bin.bin");


    /**
     * Testes sobre informaçao dos Clientes
     */

    printf("*********Testes dos Clientes:*********\n");

    ///INSERIR CLIENTES

    inserir_cliente_cabeca(1, "Diogo", "rua123", 12345, 99999, 1, 2, 2000, 10, 10, 2010);
    inserir_cliente_cabeca(3, "Ana", "homeless", 10010, 11111, 2, 4, 1999, 20, 21, 2021);
    inserir_cliente_cabeca(4, "Alfredo", "rua apartado qualquer coisa", 15150, 434313, 4, 6, 2001, 3, 4, 2005);
    inserir_cliente_cauda(20, "Baguetes", "homeless part2", 10101010, 666666, 6, 8, 2000, 1, 2, 2001);
    inserir_cliente_cabeca(17, "Joaquim", "tua casa e minha casa", 69690, 420420, 8, 10, 1998, 5, 6, 1999);
    inserir_cliente_ordenado(15, "Alberto", "rua dr 56", 42042, 6969, true, 10, 12, 2000, 30, 12, 2222);
    inserir_cliente_ordenado(11, "Alberta", "rua da alberta", 42042, 6968, false, 20, 7, 2000, 17, 11, 2231);

    imprimir_clientes();

    ///REMOVER CLIENTES
    remover_cliente(1);
    imprimir_clientes();

    ///PROCURAR CLIENTES
     CLIENTES *c1 = procurar_cliente_nome("Alberta");
     if (c1 != NULL) {
         printf("Cliente: id: %d; nome: %s; morada: %s; contacto: %d; NIF: %d; Data Nascimento: %d/%d/%d; Data Registo: %d/%d/%d\n\n",
                c1->id, c1->nome, c1->morada,
                c1->contacto, c1->nif, c1->data_nascimento.dia, c1->data_nascimento.mes, c1->data_nascimento.ano,
                c1->data_registo.dia, c1->data_registo.mes, c1->data_registo.ano);
     }

    CLIENTES *c2 = procurar_cliente_nif(666666);
    if (c2 != NULL) {
        printf("Cliente: id: %d; nome: %s; morada: %s; contacto: %d; NIF: %d; Data Nascimento: %d/%d/%d; Data Registo: %d/%d/%d\n\n",
               c2->id, c2->nome, c2->morada,
               c2->contacto, c2->nif, c2->data_nascimento.dia, c2->data_nascimento.mes, c2->data_nascimento.ano,
               c2->data_registo.dia, c2->data_registo.mes, c2->data_registo.ano);
    }

    ///ORDENAR LISTA LIGADA PELO NIF
     ordenar_lista_nif();
     imprimir_ordenado();

    /**
      * Testes sobre Viagens
      */

    printf("\n*********Testes das Viagens:*********\n");

    ///INSERIR VIAGEM

    inserir_viagem(6968, 1, "Portugal", 5, 11, 2022, 12, 11, 2022);
    inserir_viagem(6968, 3, "Italia", 21, 12, 2022, 1, 1, 2023);
    inserir_viagem(6968, 2, "Espanha", 15, 6, 2000, 1, 1, 2023);
    inserir_viagem(6968, 4, "Franca", 27, 7, 2007, 1, 1, 2023);
    inserir_viagem(6968, 6, "Belgica", 21, 2, 2015, 1, 1, 2023);
    inserir_viagem(6968, 7, "Alemanha", 13, 12, 2016, 1, 1, 2023);
    inserir_viagem(6968, 8, "Kazaquistao", 7, 8, 2010, 1, 1, 2023);
    inserir_viagem(6968, 9, "Paquistao", 9, 11, 2017, 1, 1, 2023);
    inserir_viagem(6968, 10, "Africa do Sul", 21, 12, 2022, 1, 1, 2023);
    inserir_viagem(6968, 11, "Zimbabwe", 14, 11, 2015, 1, 1, 2023);
    inserir_viagem(6968, 12, "Mongolia", 6, 11, 1999, 1, 1, 2023);
    inserir_viagem(6969, 2, "Espanha", 10, 10, 2021, 20, 10, 2021);
    inserir_viagem(420420, 2, "Espanha", 15, 11, 2021, 15, 5, 2022);
    inserir_viagem(420420, 3, "ahdbahd", 19, 8, 2022, 5, 11, 2022);

    imprimir_viagens_cliente(6968);
    //imprimir_viagens_cliente(420420);

    ///EDITAR VIAGENS
     edit_viagem(6968,2,"Argentina");
     imprimir_viagens_cliente(6968);

    ///PESQUISAR VIAGENS
    VIAGEM *v1 = pesquisar_viagem(1);

    ///REMOVER VIAGENS
    remove_viagem(6968,12);
    remove_viagem(420420, 2);

    imprimir_viagens_cliente(6968);
    //imprimir_viagens_cliente(420420);

    /**
     * Testes sobre Cidades das Cidades
     */

    printf("\n*********Testes das Cidades:*********\n");

    ///INSERIR CIDADE
    // inserir na estrutura para as inserçoes manuais
    inserir_cidade_lista_global(2, "Braga", "uma merda", 0.0f, 1.0f);
    inserir_cidade_lista_global(1, "Porto", "capital", 2.0f, 3.0f);

   // imprimir_viagens_cliente(6869);

    inserir_cidade_numa_viagem(1, "Braga", "uma merda", 254.13f, 153.6f);
    inserir_cidade_numa_viagem(1, "Porto", "Porto ", 534.24f, 765.42f);
    inserir_cidade_numa_viagem(1, "Coimbra", "asdasd ", 765.345f, 234.654f);
    inserir_cidade_numa_viagem(1, "Arouca", "melhor equipa ", 654.74f, 746.46f);
    inserir_cidade_numa_viagem(1, "Penafiel", "casa do semaforo ", 245.63f, 275.46f);



    ///PESQUISAR CIDADE
    //pesquisar_cidade_nome(1,"Porto");

    ///EDITAR CIDADE
    //edit_cidade(1,1,"Porto","BEST CITY IN DA WORLDS");


    ///REMOVER CIDADE
    //remove_cidade(1,2);

    /**
      * Testes sobre Pontos de Interesse das Cidades
      */

    printf("\n***********Testes dos Pontos de Interesse das Cidades:************\n");

    ///INSERIR PONTOS DE INTERESSE

     inserir_PoI("Porto", 1, "Estadio do Dragao");
     inserir_PoI("Porto", 2, "Aliados");
     inserir_PoI("Porto", 3, "Clerigos");
     inserir_PoI("Porto", 4, "UFP");

    //imprimir_pois("Porto");

    ///REMOVER PONTOS DE INTERESSE
    //remover_PoI_cidade("Porto","Clerigos");
    //imprimir_pois("Porto");

    ///EDITAR PONTO DE INTERESSE
    //edit_PoI("Porto","UFP","UFP Caralho!");
    //imprimir_pois("Porto");

    ///PESQUISAR PONTOS DE INTERESSE
    //pesquisar_PoI("Porto","Estadio do Dragao");

    /**
      * Testes Ler/Escrever para ficheiro txt e binario
      */

    printf("\n*********Testes para ler/escrever para ficheiros txt e binario:*********\n");
    ///LER E ESCREVER PARA FICHEIRO TXT E BINARIO
    //ler_clientes_ficheiro_txt_formatado("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_formatado.txt");
    //escrever_clientes_ficheiro_txt_formatado("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_formatado.txt");
    //escrever_clientes_viagens_bin("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_bin.bin");
    //escrever_cidades_ficheiro_txt("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\cidades_pois.txt");
    //ler_clientes_viagens_ficheiro_bin("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\clientes_viagens_bin.bin");
    //ler_cidade_ficheiro_txt("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\cidades_pois.txt");

    escrever_cidades_pois_bin("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\cidades_pois_bin.bin");
    //ler_cidades_pois_ficheiro_bin("C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\cidades_pois_bin.bin");
    //imprimir_viagens_cliente(6968);

    ///GERAÇÃO DE RELATORIOS
    DATA dataMin = {1, 1, 2005};
    DATA dataMax = {1, 1, 2020};
    //gerar_relatorio_viagens_cliente_betweenDates(6968, dataMin, dataMax,"C:\\Users\\diogo\\OneDrive\\Ambiente de Trabalho\\projeto_lp1_aed1\\data\\relatorio_viagens_cliente_6968.txt");


    // remover_PoI_cidade("Porto","Estadio do Dragao");
    // edit_PoI("Porto","UFP","UFP Caralho!");
    // imprimir_pois("Porto");
    // pesquisar_PoI("Porto","Estadio do Dragao");
    // imprimir_clientes();
    //print_HistoricoViagens_cliente(6968,"Porto",0);

  /*  CLIENTES *cl1 = procurar_cliente_nome("Alberta");
    VIAGEM *viagem = pesquisa_viagem_cliente(cl1->nif, 1);
    alg.P = 4;
    alg.nif_cliente = cl1->nif;
    alg.id_viagem = viagem->id;
    alg.E = 2;
    alg.G = 1;
    alg.N = viagem->num_cidades;

    algoritmo(alg);*/

    return 0;
}



