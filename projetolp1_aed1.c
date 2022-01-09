//
// Created by diogo on 11/11/2021.
//

#include "projetolp1_aed1.h"
#include "testes.c"
#include <time.h>
#include <math.h>


int mainProjeto() {
    main_testes();

    return 0;
}

/**
 * Criar Lista ligada de clientes
 * @return node lista de clientes criada
 */
void *criar_lista_clientes() {
    LISTA_CLIENTES *node = (LISTA_CLIENTES *) malloc(sizeof(LISTA_CLIENTES));
    node->head_clientes = NULL;
    node->num_clientes = 0;
    return node;
}

/**
 * Criar Lista ligada de cidades
 * @return node lista de cidades criada
 */
void *criar_lista_cidades() {
    LISTA_CIDADES *node = (LISTA_CIDADES *) malloc(sizeof(LISTA_CIDADES));
    node->head_cidades = NULL;
    node->num_cidades = 0;
    return node;
}

/**
 * Inserir os clientes à cabeça
 * @param id id do cliente
 * @param nome nome do cliente
 * @param morada morada do cliente
 * @param contacto contacto do cliente
 * @param nif nif do cliente
 * @param data data de registo do cliente
 * @param brithDay dia nascimento do cliente
 * @param birthMon mês nascimento do cliente
 * @param birthYear ano nascimento do cliente
 */
void inserir_cliente_cabeca(int id, char *nome, char *morada, int contacto, int nif, int brithDay,
                            int birthMon, int birthYear, int diaRegisto, int mesRegisto, int anoRegisto) {
    CLIENTES *node = lc->head_clientes;
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
        novo_no->data_registo.ano = anoRegisto;
        novo_no->data_registo.mes = mesRegisto;
        novo_no->data_registo.dia = diaRegisto;
        novo_no->viagens_arr = NULL;
        novo_no->num_viagens = 0;
        novo_no->maxNum_viagens = 0;
        novo_no->next = NULL;

        novo_no->next = lc->head_clientes;
        lc->head_clientes = novo_no;
        lc->num_clientes++;
        return;
    } else {
        while (node != NULL) {

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
        novo_no->data_registo.dia = diaRegisto;
        novo_no->data_registo.mes = mesRegisto;
        novo_no->data_registo.ano = anoRegisto;
        novo_no->viagens_arr = NULL;
        novo_no->num_viagens = 0;
        novo_no->maxNum_viagens = 0;
        novo_no->next = NULL;

        novo_no->next = lc->head_clientes;
        lc->head_clientes = novo_no;
        lc->num_clientes++;
    }
}

/**
 * Imprimir os clientes
 */
void imprimir_clientes() {
    CLIENTES *l = lc->head_clientes;
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

/**
 * Inserir os clientes à cauda
 * @param id id do cliente
 * @param nome nome do cliente
 * @param morada morada do cliente
 * @param contacto contacto do cliente
 * @param nif nif do cliente
 * @param data data de registo do cliente
 * @param brithDay dia nascimento do cliente
 * @param birthMon mês nascimento do cliente
 * @param birthYear ano nascimento do cliente
 */
void inserir_cliente_cauda(int id, char *nome, char *morada, int contacto, int nif, int brithDay,
                           int birthMon, int birthYear, int diaRegisto, int mesRegisto, int anoRegisto) {
    CLIENTES *current = lc->head_clientes, *ant = NULL;

    if (current == NULL) {
        inserir_cliente_cabeca(id, nome, morada, contacto, nif, brithDay, birthMon, birthYear, diaRegisto, mesRegisto,
                               anoRegisto);
        return;
    }

    while (current->next != NULL) {
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
    ant->data_registo.ano = anoRegisto;
    ant->data_registo.mes = mesRegisto;
    ant->data_registo.dia = diaRegisto;
    ant->viagens_arr = NULL;
    ant->num_viagens = 0;
    ant->maxNum_viagens = 0;
    ant->next = NULL;

    current->next = ant;
    lc->num_clientes++;
}

/**
 * Inserir os clientes ordenados pelo nome ou nif
 * @param id id do cliente
 * @param nome nome do cliente
 * @param morada morada do cliente
 * @param contacto contacto do cliente
 * @param nif nif do cliente
 * @param insNome variavel que identifica se é para ordenar por nome ou nif (TRUE = nome, False = nif)
 * @param data data de registo do cliente
 * @param brithDay dia nascimento do cliente
 * @param birthMon mês nascimento do cliente
 * @param birthYear ano nascimento do cliente
 */
void inserir_cliente_ordenado(int id, char *nome, char *morada, int contacto, int nif, bool insNome,
                              int brithDay, int birthMon, int birthYear, int diaRegisto, int mesRegisto,
                              int anoRegisto) {
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
    c->data_registo.ano = anoRegisto;
    c->data_registo.mes = mesRegisto;
    c->data_registo.dia = diaRegisto;
    c->viagens_arr = NULL;
    c->num_viagens = 0;
    c->maxNum_viagens = 0;
    c->next = NULL;

    if (lc->head_clientes == NULL || lc->num_clientes == 0) {
        lc->head_clientes = c;
        lc->num_clientes++;
        return;
    } else {
        CLIENTES *current = lc->head_clientes, *ant = NULL;

        while (current->next != NULL) {
            if (current->id == id || current->nif == nif) {
                printf("ERRO -> inserir_cliente_ord(): Ja existe um cliente com esse id/nif!! Cliente nao foi introduzido\n");
                return;
            }
            current = current->next;
        }
        current = lc->head_clientes;

        if (insNome == true) {  // INSERIR ORDENADO PELO NOME
            while (current != NULL && strcmp(nome, current->nome) > 0) {//enquanto n chegar sitio certo NOME
                ant = current;
                current = current->next;
            }
            if (current == lc->head_clientes) {//cabeça
                c->next = current;
                lc->head_clientes = c;
                lc->num_clientes++;
                return;
            }
            //meio ou cauda
            ant->next = c;
            c->next = current;
            lc->num_clientes++;
        } else { // INSERIR ORDENADO PELO NIF
            while (current != NULL && nif > current->nif) {//enquanto n chegar sitio certo NIF
                ant = current;
                current = current->next;
            }
            if (current == lc->head_clientes) {//cabeça
                c->next = current;
                lc->head_clientes = c;
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

/**
 * Remover cliente
 * @param id id do cliente
 */
void remover_cliente(int id) {
    if (lc->head_clientes == NULL) {
        printf("A lista esta vazia!!");
        return;
    }

    CLIENTES *anterior = NULL, *current = lc->head_clientes;

    while (current != NULL && current->id != id) {
        anterior = current;
        current = current->next;
    }

    if (current == lc->head_clientes) {
        lc->head_clientes = lc->head_clientes->next;
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

/**
 * procurar cliente por nome
 * @param nome nome do cliente
 * @return cliente encontrado com esse nome
 */
CLIENTES *procurar_cliente_nome(const char *nome) {
    CLIENTES *current = lc->head_clientes;

    if (current == NULL) {
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

/**
 * procurar cliente por nif
 * @param nome nome do cliente
 * @return cliente encontrado com esse nif
 */
CLIENTES *procurar_cliente_nif(int nif) {
    CLIENTES *current = lc->head_clientes;

    if (current == NULL) {
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

/**
 * Ordenar lista ligada por nif
 */
void ordenar_lista_nif() {
    CLIENTES *current = lc->head_clientes, *nova = NULL;
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

/**
 * Imprimir lista ligada ordenada
 */
void imprimir_ordenado() {
    CLIENTES *current = lc->head_clientes;
    printf("**************Lista Ordenada*************\n");
    while (current != NULL) {
        printf("NIF: %d;\t Nome: %s \n", current->nif, current->nome);
        current = current->next;
    }
}

/**
 * Funcao para inserir uma cidade numa viagem
 *
 * @param id_viagem id da viagem onde vamos inserir a cidade
 * @param id_cidade id da cidade escolhido para identificacao
 * @param nome_cidade nome da cidade inserida
 * @param descricao descricao da cidade inserida
 */
void inserir_cidade_numa_viagem(int id_viagem,char *nome_cidade, char *descricao, float x, float y) {
    VIAGEM *viagem = pesquisar_viagem(id_viagem);
    CIDADE *cidades=viagem->cidades;

    if(cidades==NULL){
        CIDADE *novo_no = (CIDADE *) malloc(sizeof(CIDADE));
        novo_no->id = viagem->num_cidades+1;
        novo_no->num_PoI = 0;
        novo_no->head_pontos_interesse = NULL;
        novo_no->next = NULL;
        novo_no->nome = (char *) malloc(sizeof(char));
        strcpy(novo_no->nome, nome_cidade);
        novo_no->descricao = (char *) malloc(sizeof(char));
        strcpy(novo_no->descricao, descricao);
        novo_no->localizacao.x = x;
        novo_no->localizacao.y = y;
        novo_no->next=viagem->cidades;
        viagem->cidades=novo_no;
        viagem->num_cidades++;
        return;
    }else{
        while (cidades!=NULL){
            if(strcmp(cidades->nome,nome_cidade)==0){
                printf("cidade ja existente!!\n");
                return;
            }
            cidades=cidades->next;
        }

        CIDADE *novo_no = (CIDADE *) malloc(sizeof(CIDADE));
        novo_no->id = viagem->num_cidades+1;
        novo_no->num_PoI = 0;
        novo_no->head_pontos_interesse = NULL;
        novo_no->next = NULL;
        novo_no->nome = (char *) malloc(sizeof(char));
        strcpy(novo_no->nome, nome_cidade);
        novo_no->descricao = (char *) malloc(sizeof(char));
        strcpy(novo_no->descricao, descricao);
        novo_no->localizacao.x = x;
        novo_no->localizacao.y = y;
        novo_no->next=viagem->cidades;
        viagem->cidades=novo_no;
        viagem->num_cidades++;
    }
}

/**
 * Função para inserir uma cidade na lista global de cidades
 * @param id_cidade  id da cidade
 * @param nome_cidade nome da cidade
 * @param descricao descrição da cidade
 * @param x coordenada x
 * @param y coordenada y
 */
void inserir_cidade_lista_global(int id_cidade, char *nome_cidade, char *descricao, float x, float y) {
    CIDADE *node = lcidades->head_cidades;
    if (node == NULL) {
        CIDADE *novo_no = (CIDADE *) malloc(sizeof(CIDADE));
        novo_no->id = id_cidade;
        novo_no->num_PoI = 0;
        novo_no->head_pontos_interesse = NULL;
        novo_no->next = NULL;
        novo_no->nome = (char *) malloc(sizeof(char));
        strcpy(novo_no->nome, nome_cidade);
        novo_no->descricao = (char *) malloc(sizeof(char));
        strcpy(novo_no->descricao, descricao);
        novo_no->localizacao.x = x;
        novo_no->localizacao.y = y;
        novo_no->next = lcidades->head_cidades;
        lcidades->head_cidades = novo_no;
        lcidades->num_cidades++;
        printf("cidade inserida na lista global!!\n");

        return;
    } else {
        while (node != NULL) {
            if (strcmp(node->nome, nome_cidade) == 0) {
                return;
            }
            node = node->next;
        }
        CIDADE *novo_no = (CIDADE *) malloc(sizeof(CIDADE));
        novo_no->id = id_cidade;
        novo_no->num_PoI = 0;
        novo_no->head_pontos_interesse = NULL;
        novo_no->next = NULL;
        novo_no->nome = (char *) malloc(sizeof(char));
        strcpy(novo_no->nome, nome_cidade);
        novo_no->descricao = (char *) malloc(sizeof(char));
        strcpy(novo_no->descricao, descricao);
        novo_no->localizacao.x = x;
        novo_no->localizacao.y = y;
        novo_no->next = lcidades->head_cidades;
        lcidades->head_cidades = novo_no;
        lcidades->num_cidades++;
        printf("cidade inserida na lista global!!\n");
    }
}

/**
 * Pesquisa de cidade
 * @param cidade nome da cidade a ser pesquisada
 * @return array das head_cidades pesquisada
 */
CIDADE *pesquisar_cidade_nome(int id_viagem, char *cidade) {
    CLIENTES *clientes = lc->head_clientes;

    if (clientes == NULL) {
        printf("Lista de Clientes Vazia!!\n");
        return NULL;
    }

    VIAGEM *viagem = pesquisar_viagem(id_viagem);
    if (viagem != NULL) {
        CIDADE *arr_cidades = viagem->cidades;
        for (int i = 0; i < viagem->num_cidades; i++) {
            if (strcmp(arr_cidades[i].nome, cidade) == 0) {
                printf("Cidade Encontrada!! Cidade: %s\n", viagem->cidades[i].nome);
                return &arr_cidades[i];
            }
        }
        printf("Nao encontramos a cidade pretendida!!\n");
        return NULL;
    }
    return NULL;
}


/**
 * Editar informação da descricao de uma cidade
 * @param listaCidades Lista de Cidades
 * @param nome_cidade nome da cidade a editar
 * @param nova_descricao nova descricao da cidade
 */
void edit_cidade(int id_viagem, int id_cidade, char *nome_cidade, const char *nova_descricao) {
    CIDADE *current = pesquisar_cidade_nome(id_viagem, nome_cidade);
    VIAGEM *viagem = pesquisar_viagem(id_viagem);

    if (current != NULL) {
        for (int i = 0; i < viagem->num_cidades; i++) {
            if (current[i].id == id_cidade) {
                strcpy(current[i].descricao, nova_descricao);
                printf("Info da cidade %s alterada!!\n", current[i].nome);
                return;
            }
        }
    }
}

/**
 * Funcao para remover uma cidade de uma viagem
 * @param id_viagem id da viagem de onde vamos remover a cidade
 * @param id_cidade id da cidade a ser removida
 */
void remove_cidade(int id_viagem, int id_cidade) {
    VIAGEM *viagem = pesquisar_viagem(id_viagem);
    CIDADE *current = viagem->cidades;
    if (current == NULL) {
        printf("Nao ha cidades para remover!!\n");
        return;
    }
    int id = -1;
    for (int i = 0; i < viagem->num_cidades; i++) {
        if (current[i].id == id_cidade) {
            id = i;
        }
    }
    if (id >= 0) {
        for (int i = id; i < viagem->num_cidades; i++) {
            current[i] = current[i + 1];
        }
        printf("Cidade removida da Viagem com id: %d\n", id_viagem);
        viagem->num_cidades--;
    }
}

/**
 * Funcao para adicionar uma viagem a um cliente
 * @param nif nif do cliente
 * @param id_viagem id escolhido para a viagem
 * @param pais_destino pais de destino da viagem
 */
void
inserir_viagem(int nif, int id_viagem, char *pais_destino, bool isConcluida, int beginDay, int beginMon, int beginYear,
               int endDay, int endMon, int endYear) {
    CLIENTES *cliente = procurar_cliente_nif(nif);

    while (cliente != NULL) {
        if (cliente->nif == nif) {
            if (cliente->num_viagens == cliente->maxNum_viagens) {
                if (cliente->maxNum_viagens == 0) {
                    cliente->maxNum_viagens = 2;
                } else {
                    cliente->maxNum_viagens *= 2;
                }
                cliente->viagens_arr = (VIAGEM *) realloc(cliente->viagens_arr,
                                                          cliente->maxNum_viagens * sizeof(VIAGEM));
            }
            VIAGEM *arr_viagens = cliente->viagens_arr;
            for (int i = 0; i < cliente->num_viagens; i++) {
                if (arr_viagens[i].id == id_viagem) {
                    printf("Viagem ja existente!!\n");
                    return;
                }
            }
            arr_viagens[cliente->num_viagens].id = id_viagem;
            arr_viagens[cliente->num_viagens].pais = (char *) malloc(50 * sizeof(char));
            strcpy(arr_viagens[cliente->num_viagens].pais, pais_destino);
            arr_viagens[cliente->num_viagens].nif_cliente = nif;
            arr_viagens[cliente->num_viagens].cidades = NULL;
            arr_viagens[cliente->num_viagens].num_cidades = 0;
            arr_viagens[cliente->num_viagens].data_inicio.dia = beginDay;
            arr_viagens[cliente->num_viagens].data_inicio.mes = beginMon;
            arr_viagens[cliente->num_viagens].data_inicio.ano = beginYear;
            arr_viagens[cliente->num_viagens].data_fim.dia = endDay;
            arr_viagens[cliente->num_viagens].data_fim.mes = endMon;
            arr_viagens[cliente->num_viagens].data_fim.ano = endYear;
            arr_viagens[cliente->num_viagens].maxNum_cidades = 0;
            arr_viagens[cliente->num_viagens].concluida = isConcluida;
            arr_viagens[cliente->num_viagens].next = NULL;
            cliente->viagens_arr = arr_viagens;
            cliente->num_viagens++;
            return;
        }
        cliente = cliente->next;
    }
}

/**
 * Funcao para imprimir as viagens de um cliente
 * @param nif nif do cliente
 */
void imprimir_viagens_cliente(int nif) {
    CLIENTES *cliente = procurar_cliente_nif(nif);
    VIAGEM *current = cliente->viagens_arr;
    printf("Cliente id[%d]\tNome: %s\tNIF: %d\tNumero de Viagens: %d\n", cliente->id, cliente->nome, cliente->nif,
           cliente->num_viagens);
    for (int i = 0; i < cliente->num_viagens; i++) {
        printf("ID: %d\tPais: %s\tNum Cidades: %d\n", current[i].id, current[i].pais, current[i].num_cidades);
        while (current[i].cidades != NULL) {
            printf("Cidade: %s Descricao: %s\n",current[i].cidades->nome,current[i].cidades->descricao);
        current[i].cidades=current[i].cidades->next;
        }
    }
}

/**
 * Funcao para editar uma viagem de um cliente
 * @param nif_cliente nif do cliente
 * @param id_viagem id da viagem a editar
 * @param novo_pais alteracao a ser feita
 */
void edit_viagem(int nif_cliente, int id_viagem, char *novo_pais) {
    CLIENTES *cliente = procurar_cliente_nif(nif_cliente);
    VIAGEM *current = cliente->viagens_arr;

    if (current != NULL) {
        for (int i = 0; i < cliente->num_viagens; i++) {

            if (current[i].id == id_viagem) {
                strcpy(current[i].pais, novo_pais);
                return;
            }
        }
    }
}

/**
 * Funcao para pesquisar uma viagem enviando o seu id por parametro
 * @param id_viagem id da viagem a procurar
 * @return Se existir, retorna a estrutura da viagem procurada, senao retorna NULL
 */
VIAGEM *pesquisar_viagem(int id_viagem) {
    CLIENTES *clientes = lc->head_clientes;
    if (clientes == NULL) {
        printf("Lista de Clientes vazia!!\n");
        return NULL;
    }
    while (clientes != NULL) {
        VIAGEM *viagens = clientes->viagens_arr;

        for (int i = 0; i < clientes->num_viagens; i++) {
            if (viagens != NULL) {
                if (viagens[i].id == id_viagem) {
                    printf("\nViagem encontrada!!\t ID_viagem: %d\t Pais: %s\n", viagens->id, viagens->pais);
                    return &viagens[i];
                }
            }
        }
        clientes = clientes->next;
    }
    printf("Viagem nao encontrada!!\n");
    return NULL;
}

/**
 * Funcao para remover uma viagem enviando o seu id por parametro
 * @param id_viagem id da viagem a remover
 */
void remove_viagem(int nif_cliente, int id_viagem) {
    CLIENTES *clientes = procurar_cliente_nif(nif_cliente);
    if (clientes == NULL) {
        printf("Cliente nao existe!!\n");
        return;
    }
    VIAGEM *current = clientes->viagens_arr;
    int id = -1;
/*
 * inicializamos a -1 para, caso nao haja uma viagem com o id que queremos remover,
 * dá fail na verificacao abaixo e nao elimina nenhuma posicao por engano
*/
    if (clientes->num_viagens == 1 && current->id == id_viagem) {
        current = NULL;
        clientes->num_viagens--;
    } else {
        for (int i = 0; i < clientes->num_viagens; i++) {
            if (current[i].id == id_viagem) {
                id = i;
            }
        }
        if (id >= 0) {
            for (int i = id; i < clientes->num_viagens; i++) {
                current[i] = current[i + 1];
            }
            printf("Viagem removida!!\n");
            clientes->num_viagens--;
        }
    }
}

/**
 * Funcao para adicionar um ponto de interesse a uma cidade
 * @param nome_cidade
 * @param id_poI
 * @param nome_poI
 */
void inserir_PoI(char *nome_cidade, int id_poI, char *nome_poI) {
    CIDADE *current = lcidades->head_cidades;

    while (current != NULL) {
        if (strcmp(current->nome, nome_cidade) == 0)
            break;
        current = current->next;
    }

    PoI *node = current->head_pontos_interesse;

    if (node == NULL) {
        PoI *novo_no = (PoI *) malloc(sizeof(PoI));

        novo_no->id_PoI = id_poI;
        novo_no->nome = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->nome, nome_poI);
        novo_no->next = NULL;

        novo_no->next = current->head_pontos_interesse;
        current->head_pontos_interesse = novo_no;
        current->num_PoI++;
        printf("PoI inserido!!\n");
        return;
    } else {
        while (node != NULL) {
            if (strcmp(node->nome, nome_poI) == 0) {
                printf("ERRO -> inserir_poi(): Ja existe um poi com esse nome!! poi nao foi introduzido\n");
                return;
            }
            node = node->next;
        }

        PoI *novo_no = (PoI *) malloc(sizeof(PoI));

        novo_no->id_PoI = id_poI;
        novo_no->nome = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->nome, nome_poI);
        novo_no->next = NULL;

        novo_no->next = current->head_pontos_interesse;
        current->head_pontos_interesse = novo_no;

        current->num_PoI++;

        printf("PoI inserido!!\n");
    }
}

/**
 * Funçao que escreve para ficheiro txt a informaçao do cliente e das suas viagens
 * @param filename
 */
void escrever_clientes_ficheiro_txt(char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp != NULL) {
        fprintf(fp, "Numero de Clientes: %d\n", lc->num_clientes);

        CLIENTES *c = lc->head_clientes;
        while (c != NULL) {
            fprintf(fp,
                    "Cliente: id: %d; nome: %s; morada: %s; contacto: %d; NIF: %d; Data Nascimento: %d/%d/%d; Data Registo: %d/%d/%d\n",
                    c->id, c->nome, c->morada,
                    c->contacto, c->nif, c->data_nascimento.dia, c->data_nascimento.mes,
                    c->data_nascimento.ano,
                    c->data_registo.dia, c->data_registo.mes, c->data_registo.ano);
            if (c->viagens_arr == NULL) {
                fprintf(fp, "\t\tNao ha viagens marcadas para este cliente!!\n\n");
            } else {
                for (int i = 0; i < c->num_viagens; i++) {
                    fprintf(fp, "\t\tViagens: ID_viagem: %d, Pais: %s Data Inicio: %d/%d/%d , Data Fim: %d/%d/%d\n",
                            c->viagens_arr[i].id, c->viagens_arr[i].pais, c->viagens_arr[i].data_inicio.dia,
                            c->viagens_arr[i].data_inicio.mes, c->viagens_arr[i].data_inicio.ano,
                            c->viagens_arr[i].data_fim.dia, c->viagens_arr[i].data_fim.mes,
                            c->viagens_arr[i].data_fim.ano);
                }
                fprintf(fp, "\n");
            }
            c = c->next;
        }
    }
    fclose(fp);
}

/**
 * Função para ler clientes e a sua informação de ficheiro txt
 * @param filename
 */
void ler_clientes_ficheiro_txt_formatado(char *filename) {
    FILE *fp = fopen(filename, "r");
    int num_clientes = 0;
    int num_viagens = 0;

    if (fp != NULL) {
        fscanf(fp, "%*s %*s %*s %d\n", &num_clientes);

        int id_clientes = 0;
        int *id_viagens = (int *) malloc(sizeof(int));
        char *nome = (char *) malloc(100 * sizeof(char));
        char *morada = (char *) malloc(100 * sizeof(char));
        int contacto = 0, nif = 0;
        int dia_nascimento = 0, mes_nascimento = 0, ano_nascimento = 0;
        int dia_registo = 0, mes_registo = 0, ano_registo = 0;
        int dia_inicio = 0, mes_inicio = 0, ano_inicio = 0, dia_fim = 0, mes_fim = 0, ano_fim = 0;
        char pais[100];

        for (int i = 0; i < num_clientes; i++) {
            fscanf(fp, "%d; %99[^;]; %99[^;]; %d; %d; %d/%d/%d; %d/%d/%d\n", &id_clientes, nome, morada, &contacto,
                   &nif, &dia_nascimento,
                   &mes_nascimento, &ano_nascimento, &dia_registo, &mes_registo, &ano_registo);

            inserir_cliente_ordenado(id_clientes, nome, morada, contacto, nif, true, dia_nascimento,
                                     mes_nascimento, ano_nascimento, dia_registo, mes_registo, ano_registo);

            fscanf(fp, "%*s %*s %*s %d\n", &num_viagens);

            for (int j = 0; j < num_viagens; j++) {
                fscanf(fp, "%d, %s, %d/%d/%d, %d/%d/%d\n", &id_viagens[j], pais, &dia_inicio, &mes_inicio, &ano_inicio,
                       &dia_fim, &mes_fim, &ano_fim);
                inserir_viagem(nif, id_viagens[j], pais, true, dia_inicio, mes_inicio, ano_inicio, dia_fim, mes_fim,
                               ano_fim);
            }
            imprimir_viagens_cliente(nif);
        }
        imprimir_clientes();
        fclose(fp);
    }
}

/**
 * Função que escreve para ficheiro txt a informaçao do cliente e das suas viagens
 * (formatado)
 * @param filename
 */
void escrever_clientes_ficheiro_txt_formatado(char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp != NULL) {
        fprintf(fp, "Numero de Clientes: %d\n", lc->num_clientes);
        CLIENTES *c = lc->head_clientes;
        while (c != NULL) {
            fprintf(fp, "%d; %s; %s; %d; %d; %d/%d/%d; %d/%d/%d\n",
                    c->id, c->nome, c->morada,
                    c->contacto, c->nif, c->data_nascimento.dia, c->data_nascimento.mes, c->data_nascimento.ano,
                    c->data_registo.dia, c->data_registo.mes,
                    c->data_registo.ano);
            if (c->viagens_arr == NULL) {
                fprintf(fp, "Numero de viagens: %d\n\n", c->num_viagens);
            } else {
                fprintf(fp, "Numero de viagens: %d\n", c->num_viagens);
                for (int i = 0; i < c->num_viagens; i++) {
                    fprintf(fp, "%d, %s, %d/%d/%d, %d/%d/%d\n",
                            c->viagens_arr[i].id, c->viagens_arr[i].pais, c->viagens_arr[i].data_inicio.dia,
                            c->viagens_arr[i].data_inicio.mes, c->viagens_arr[i].data_inicio.ano,
                            c->viagens_arr[i].data_fim.dia, c->viagens_arr[i].data_fim.mes,
                            c->viagens_arr[i].data_fim.ano);
                }
                fprintf(fp, "\n");
            }
            c = c->next;
        }
    }
    fclose(fp);
}

/**
 * Função para escrever as cidades e suas informações para ficheiro txt
 * @param filename
 */
void escrever_cidades_ficheiro_txt(char *filename) {
    FILE *fp = fopen(filename, "w");

    if (fp != NULL) {
        fprintf(fp, "Num de Cidades: %d\n", lcidades->num_cidades);
        CIDADE *cidade = lcidades->head_cidades;
        if (cidade != NULL) {
            while (cidade != NULL) {
                fprintf(fp, "%d, %s, %s, %.2f, %.2f\n", cidade->id, cidade->nome, cidade->descricao,
                        cidade->localizacao.x,
                        cidade->localizacao.y);
                PoI *poI = cidade->head_pontos_interesse;
                if (poI == NULL) {
                    fprintf(fp, "Numero Pontos Interesse: %d\n", cidade->num_PoI);
                } else {
                    fprintf(fp, "Numero Pontos Interesse: %d\n", cidade->num_PoI);
                    while (poI != NULL) {
                        fprintf(fp, "%s, %s, %d\n", cidade->nome, poI->nome, poI->id_PoI);
                        poI = poI->next;
                    }
                }
                fprintf(fp, "\n");
                cidade = cidade->next;
            }
        }
    }
    fclose(fp);
}

/**
 * Função para ler cidades e a sua informação de ficheiro txt
 * @param filename
 */
void ler_cidade_ficheiro_txt(char *filename) {
    FILE *fp = fopen(filename, "r");
    int num_cidades = 0;
    int numero_poI = 0;

    if (fp != NULL) {
        fscanf(fp, "%*s %*s %*s %d\n", &num_cidades);

        int id_cidades = 0;
        int *id_poI = (int *) malloc(sizeof(int));
        char *nome_cidade = (char *) malloc(100 * sizeof(char));
        char *descricao = (char *) malloc(100 * sizeof(char));
        float x, y;
        char ponto_interesse[100];

        for (int i = 0; i < num_cidades; i++) {
            fscanf(fp, "%d, %99[^,], %99[^,], %f, %f\n", &id_cidades, nome_cidade, descricao, &x, &y);
            inserir_cidade_lista_global(id_cidades, nome_cidade, descricao, x, y);

            fscanf(fp, "%*s %*s %*s %d\n", &numero_poI);

            for (int j = 0; j < numero_poI; j++) {
                fscanf(fp, "%99[^,], %99[^,], %d\n", nome_cidade, ponto_interesse, &id_poI[j]);
                inserir_PoI(nome_cidade, id_poI[j], ponto_interesse);
            }
        }
        fclose(fp);
    }
}

/**
 * Imprimir os pontos de interesse de uma dada cidade
 * @param nome_cidade nome da cidade a imprimir os pontos de interesse
 */
void imprimir_pois(char *nome_cidade) {
    CIDADE *node = lcidades->head_cidades;
    while (node != NULL) {
        if (strcmp(node->nome, nome_cidade) == 0)
            break;
        node = node->next;
    }

    PoI *current = node->head_pontos_interesse;
    while (current != NULL) {
        printf("Cidade: %s\tPoI:%s\n", node->nome, current->nome);
        current = current->next;
    }
}

/**
 * Remover ponto de interesse de uma dada cidade
 * @param nome_cidade nome da cidade a remover o ponto de interesse
 * @param nome_poi ponto de interesse a ser removido
 */
void remover_PoI_cidade(char *nome_cidade, char *nome_poi) {
    CIDADE *node = lcidades->head_cidades;

    if (node != NULL) {
        while (node->next != NULL) {
            if (strcmp(node->nome, nome_cidade) == 0) {
                break;
            }
            node = node->next;
        }
        CIDADE *cidade = node;
        PoI *current = cidade->head_pontos_interesse, *anterior = NULL;

        if (current != NULL) {
            while (current->next != NULL && strcmp(current->nome, nome_poi) != 0) {
                anterior = current;
                current = current->next;
            }

            if (current == cidade->head_pontos_interesse) {
                cidade->head_pontos_interesse = cidade->head_pontos_interesse->next;
                free(current);
                cidade->num_PoI--;
                return;
            }
        } else {
            printf("O PoI que quer eliminar nao existe!!\n");
        }

        anterior->next = current->next;
        free(current);
        cidade->num_PoI--;
    }
}

/**
 * Editar pontos de interesse de uma dada cidade
 * @param nome_cidade nome da cidade a editar o ponto de interesse
 * @param nome_poi nome do ponto de interesse a editar
 * @param novo_nomePoi novo ponto de interesse
 */
void edit_PoI(char *nome_cidade, char *nome_poi, char *novo_nomePoi) {
    CIDADE *node = lcidades->head_cidades;

    if (node != NULL) {
        while (node != NULL) {
            if (strcmp(node->nome, nome_cidade) == 0) {
                break;
            }
            node = node->next;
        }
        CIDADE *cidade = node;
        PoI *current = cidade->head_pontos_interesse, *anterior = NULL;

        while (current != NULL) {
            if (strcmp(current->nome, nome_poi) == 0) {
                strcpy(current->nome, novo_nomePoi);
                return;
            }
            current = current->next;
        }
    }

}

/**
 * Pesquisar pontos de interesse de uma dada cidade
 * @param nome_cidade nome da cidade a ser procurada
 * @param nome_PoI nome do ponto de interesse a pesquisar
 * @return
 */
PoI *pesquisar_PoI(char *nome_cidade, char *nome_PoI) {
    CIDADE *node = lcidades->head_cidades;
    if (node != NULL) {
        while (node != NULL) {
            if (strcmp(node->nome, nome_cidade) == 0) {
                break;
            }
            node = node->next;
        }
        CIDADE *cidade = node;
        PoI *current = cidade->head_pontos_interesse;
        while (current != NULL) {
            if (strcmp(current->nome, nome_PoI) == 0) {
                printf("PoI %s da cidade %s encontrado!!\n", current->nome, node->nome);
                return current;
            }
            current = current->next;
        }
    }
    printf("PoI nao encontrado!!\n");
    return NULL;
}

/**
 * Imprimir o historico de viagens de um dado cliente
 * @param nif_cliente nif do cliente a pesquisar
 * @param pesquisa
 * @param tipoPesquisa (tipoPesquisa == 0 -> pesquisar cidade pelo nome) || (tipoPesquisa == 1 -> pesquisar pontos de interesse)
 */
void print_HistoricoViagens_cliente(int nif_cliente, char *pesquisa, int tipoPesquisa) {
    CLIENTES *cliente = procurar_cliente_nif(nif_cliente);
    VIAGEM *viagens = cliente->viagens_arr;
    printf("Historico do Cliente %s com id [%d]:\n", cliente->nome, cliente->nif);

    if (viagens != NULL) {
        while (viagens != NULL && viagens->concluida) {
            if (tipoPesquisa == 0) {
                CIDADE *cidade = pesquisar_cidade_nome(viagens->id, pesquisa);
                if (cidade != NULL) {
                    printf("Viagem ao pais %s e visitou a cidade %s\n", viagens->pais, cidade->nome);
                    return;
                }
            }
            if (tipoPesquisa == 1) {
                CIDADE *cidades = lcidades->head_cidades;
                if (cidades != NULL) {
                    while (cidades != NULL) {
                        PoI *poI = pesquisar_PoI(cidades->nome, pesquisa);
                        if (poI != NULL) {
                            printf("Viagem ao pais %s e visitou o PoI %s\n", viagens->pais, poI->nome);
                            return;
                        }
                        cidades = cidades->next;
                    }
                }
            }
            viagens = viagens->next;
        }
    }
}

/**
 * Função para escrever as viagens dos clientes para um ficheiro binário
 * @param filename
 */
void escrever_clientes_viagens_bin(char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp != NULL) {
        fwrite(&lc->num_clientes, sizeof(int), 1, fp);

        CLIENTES *clientes = lc->head_clientes;

        while (clientes != NULL) {
            fwrite(&clientes->id, sizeof(int), 1, fp);
            int size_nome = (int) strlen(clientes->nome) + 1;
            fwrite(&size_nome, sizeof(int), 1, fp);
            fwrite(clientes->nome, sizeof(char), size_nome, fp);
            long size_morada = (long) strlen(clientes->morada) + 1;
            fwrite(&size_morada, sizeof(long), 1, fp);
            fwrite(clientes->morada, sizeof(char), size_morada, fp);
            fwrite(&clientes->contacto, sizeof(int), 1, fp);
            fwrite(&clientes->nif, sizeof(int), 1, fp);
            fwrite(&clientes->data_nascimento.dia, sizeof(int), 1, fp);
            fwrite(&clientes->data_nascimento.mes, sizeof(int), 1, fp);
            fwrite(&clientes->data_nascimento.ano, sizeof(int), 1, fp);
            fwrite(&clientes->data_registo.dia, sizeof(int), 1, fp);
            fwrite(&clientes->data_registo.mes, sizeof(int), 1, fp);
            fwrite(&clientes->data_registo.ano, sizeof(int), 1, fp);
            fwrite(&clientes->num_viagens, sizeof(int), 1, fp);
            VIAGEM *viagens = clientes->viagens_arr;
            while (viagens != NULL) {
                fwrite(&viagens->id, sizeof(int), 1, fp);
                int size_pais = (int) strlen(viagens->pais) + 1;
                fwrite(&size_pais, sizeof(int), size_pais, fp);
                fwrite(viagens->pais, sizeof(char), size_pais, fp);
                fwrite(&viagens->data_inicio.dia, sizeof(int), 1, fp);
                fwrite(&viagens->data_inicio.mes, sizeof(int), 1, fp);
                fwrite(&viagens->data_inicio.ano, sizeof(int), 1, fp);
                fwrite(&viagens->data_fim.dia, sizeof(int), 1, fp);
                fwrite(&viagens->data_fim.mes, sizeof(int), 1, fp);
                fwrite(&viagens->data_fim.ano, sizeof(int), 1, fp);
                viagens = viagens->next;
            }
            clientes = clientes->next;
        }
    } else
        printf("Erro ao criar ficheiro!!!\n");
    fclose(fp);
}

/**
 * Função para ler as viagens dos clientes de ficheiro binário
 * @param filename
 */
void ler_clientes_viagens_ficheiro_bin(char *filename) {
    FILE *fp = fopen(filename, "rb");
    LISTA_CLIENTES *listaClientes = lc;
    if (fp != NULL) {
        int num_clientes = 0;
        fread(&listaClientes->num_clientes, sizeof(int), 1, fp);
        for (int i = 0; i < num_clientes; i++) {
            int id_cliente = 0;
            fread(&id_cliente, sizeof(int), 1, fp);
            int size_nome;
            fread(&size_nome, sizeof(int), 1, fp);
            char nome[50] = "";
            fread(&nome, size_nome, 1, fp);
            long size_morada;
            fread(&size_morada, sizeof(long), 1, fp);
            char morada[150] = "";
            fread(&morada, size_morada, 1, fp);
            int contato = 0, nif = 0;
            fread(&contato, sizeof(int), 1, fp);
            fread(&nif, sizeof(int), 1, fp);
            int dia_nasc = 0, mes_nasc = 0, ano_nasc = 0, dia_reg = 0, mes_reg = 0, ano_reg = 0;
            fread(&dia_nasc, sizeof(int), 1, fp);
            fread(&mes_nasc, sizeof(int), 1, fp);
            fread(&ano_nasc, sizeof(int), 1, fp);
            fread(&dia_reg, sizeof(int), 1, fp);
            fread(&mes_reg, sizeof(int), 1, fp);
            fread(&ano_reg, sizeof(int), 1, fp);
            int num_viagens = 0;
            fread(&num_viagens, sizeof(int), 1, fp);
            inserir_cliente_ordenado(id_cliente, nome, morada, contato, nif, true, dia_nasc, mes_nasc, ano_nasc,
                                     dia_reg, mes_reg, ano_reg);
            for (int j = 0; j < num_viagens; j++) {
                int id_viagem = 0;
                fread(&id_viagem, sizeof(int), 1, fp);
                int size_pais = 0;
                fread(&size_pais, sizeof(int), 1, fp);
                char pais[50] = "";
                fread(&pais, size_pais, 1, fp);
                int diaInicio = 0, mesInicio = 0, anoInicio = 0, diaFim = 0, mesFim = 0, anoFim = 0;
                fread(&diaInicio, sizeof(int), 1, fp);
                fread(&mesInicio, sizeof(int), 1, fp);
                fread(&anoInicio, sizeof(int), 1, fp);
                fread(&diaFim, sizeof(int), 1, fp);
                fread(&mesFim, sizeof(int), 1, fp);
                fread(&anoFim, sizeof(int), 1, fp);

                inserir_viagem(nif, id_viagem, pais, true, diaInicio, mesInicio, anoInicio, diaFim, mesFim, anoFim);
            }
        }
    } else
        printf("Erro ao abrir o ficheiro!!!\n");
}

/**
 * Função para escrever os pontos de interesse de cada cidade para ficheiro binário
 */
void escrever_cidades_pois_bin(char *filename) {
    FILE *fp = fopen(filename, "wb");

    if (fp != NULL) {
        fwrite(&lcidades->num_cidades, sizeof(int), 1, fp);

        CIDADE *cidade = lcidades->head_cidades;

        while (cidade != NULL) {
            fwrite(&cidade->id, sizeof(int), 1, fp);
            int size_nome_cidade = (int) strlen(cidade->nome) + 1;
            fwrite(&size_nome_cidade, sizeof(int), 1, fp);
            fwrite(cidade->nome, sizeof(char), size_nome_cidade, fp);
            long size_descricao = (long) strlen(cidade->descricao) + 1;
            fwrite(&size_descricao, sizeof(long), 1, fp);
            fwrite(cidade->descricao, sizeof(char), size_descricao, fp);
            fwrite(&cidade->localizacao.x, sizeof(float), 1, fp);
            fwrite(&cidade->localizacao.y, sizeof(float), 1, fp);
            fwrite(&cidade->num_PoI, sizeof(int), 1, fp);
            PoI *poIs = cidade->head_pontos_interesse;
            while (poIs != NULL) {
                fwrite(&size_nome_cidade, sizeof(int), size_nome_cidade, fp);
                fwrite(poIs->nome, sizeof(char), size_nome_cidade, fp);
                int size_pontos_interesse = (int) strlen(poIs->nome) + 1;
                fwrite(&size_pontos_interesse, sizeof(int), size_pontos_interesse, fp);
                fwrite(poIs->nome, sizeof(char), size_pontos_interesse, fp);
                fwrite(&poIs->id_PoI, sizeof(int), 1, fp);
                poIs = poIs->next;
            }
            cidade = cidade->next;
        }
    } else
        printf("Erro ao criar ficheiro!!!\n");
    fclose(fp);
}

/**
 * Função para ler os pontos de interesse de cada cidade de um ficheiro binário
 * @param filename
 */
void ler_cidades_pois_ficheiro_bin(char *filename) {
    FILE *fp = fopen(filename, "rb");
    LISTA_CIDADES *listaCidades = lcidades;
    if (fp != NULL) {
        int num_cidades = 0;
        fread(&listaCidades->num_cidades, sizeof(int), 1, fp);
        for (int i = 0; i < num_cidades; i++) {
            int id_cidade = 0;
            fread(&id_cidade, sizeof(int), 1, fp);
            int size_nome_cidade;
            fread(&size_nome_cidade, sizeof(int), 1, fp);
            char nome_cidade[50] = "";
            fread(&nome_cidade, size_nome_cidade, 1, fp);
            long size_descricao;
            fread(&size_descricao, sizeof(long), 1, fp);
            char descricao[150] = "";
            fread(&descricao, size_descricao, 1, fp);
            float x = 0, y = 0;
            fread(&x, sizeof(float), 1, fp);
            fread(&y, sizeof(float), 1, fp);
            int num_pontos_interesse = 0;
            fread(&num_pontos_interesse, sizeof(int), 1, fp);
            inserir_cidade_lista_global(id_cidade, nome_cidade, descricao, x, y);
            for (int j = 0; j < num_pontos_interesse; j++) {
                fread(&nome_cidade, size_nome_cidade, 1, fp);
                int size_ponto_interesse = 0;
                fread(&size_ponto_interesse, sizeof(int), 1, fp);
                char ponto_interesse[50] = "";
                fread(&ponto_interesse, size_ponto_interesse, 1, fp);
                int id_ponto_interesse = 0;
                fread(&id_ponto_interesse, sizeof(int), 1, fp);
            }
            imprimir_pois(nome_cidade);
        }
    } else
        printf("Erro ao abrir o ficheiro!!!\n");
}

/**
 * Função para comparar 2 dadas datas
 * @param data1 primeira data a comparar
 * @param data2 segunda data a comparar
 * @return
 */
int isBeforeDate(DATA data1, DATA data2) {
    int date1 = (data1.ano * 10000) + (data1.mes * 100) + (data1.dia);
    int date2 = (data2.ano * 10000) + (data2.mes * 100) + (data2.dia);

    if (date1 < date2)
        return 1;
    if (date1 > date2)
        return -1;
    else
        return 0;
}

/**
 * Função para ordenar as viagens de um cliente
 * @param nif_cliente nif do cliente a ordenar as viagens
 * @return array de viagens ordenado
 */
VIAGEM *orderByViagem(int nif_cliente) {
    CLIENTES *clientes = lc->head_clientes;
    while (clientes != NULL && clientes->nif != 6968)
        clientes = clientes->next;

    VIAGEM *viagens_arr = clientes->viagens_arr;

    int n = clientes->num_viagens;

    printf("Array de Viagens a ordenar\n");
    printArray(viagens_arr, n);
    quickSort(viagens_arr, 0, n - 1);

    printf("Array de viagens ordenado: \n");
    printArray(viagens_arr, n);

    return viagens_arr;
}

/**
 * Gerar relátorio das viagens de um cliente entre 2 datas
 * @param nif_cliente nif do cliente a gerar relatorio
 * @param dataMin data minima para comparar
 * @param dataMax data maxima para comparar
 * @param filename
 */
void gerar_relatorio_viagens_cliente_betweenDates(int nif_cliente, DATA dataMin, DATA dataMax, char *filename) {
    VIAGEM *viagens_arr = orderByViagem(nif_cliente);
    CLIENTES *cliente = procurar_cliente_nif(nif_cliente);
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        int num_viagens = cliente->num_viagens;
        fprintf(fp, "Cliente %s com nif [%d]:\n", cliente->nome, nif_cliente);
        fprintf(fp, "Viagens entre %d/%d/%d e %d/%d/%d :\n", dataMin.dia, dataMin.mes, dataMin.ano, dataMax.dia,
                dataMax.mes, dataMax.ano);
        for (int i = 0; i < num_viagens; i++) {
            if (isBeforeDate(viagens_arr[i].data_inicio, dataMin) == -1 &&
                isBeforeDate(viagens_arr[i].data_inicio, dataMax) == 1) {
                fprintf(fp, "\t\tViagem ao pais %s\n", viagens_arr[i].pais);
            }
        }
    }
}


/**
 * Swap aos valores de a e b
 * @param a apontador para a
 * @param b apontador para b
 */
void swap(VIAGEM *a, VIAGEM *b) {
    VIAGEM t = *a;
    *a = *b;
    *b = t;
}

/**
 *
 * @param array
 * @param low
 * @param high
 * @return
 */
int partition(VIAGEM array[], int low, int high) { // function to find the partition position

    // select the rightmost element as pivot
    VIAGEM pivot = array[high];

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (isBeforeDate(array[j].data_inicio, pivot.data_inicio) == 1) {

            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // return the partition point
    return (i + 1);
}

/**
 *
 * @param array
 * @param low
 * @param high
 */
void quickSort(VIAGEM array[], int low, int high) {
    if (low < high) {

        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

/**
 * Funçao para imprimir o array
 * @param array array de elementos a imprimir
 * @param size tamanho do array
 */
void printArray(VIAGEM array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s  %d/%d/%d", array[i].pais, array[i].data_inicio.dia, array[i].data_inicio.mes,
               array[i].data_inicio.ano);
    }
    printf("\n");
}

/**
 * Funçao para criar uma matrix
 * @param Rows linhas da matrix
 * @param Cols colunas da matrix
 * @return
 */
int **allocate_board(int Rows, int Cols) {
    // allocate Rows rows, each row is a pointer to int
    int **board = (int **) malloc(Rows * sizeof(int *));
    int row;

    for (row = 0; row < Rows; row++) {
        board[row] = (int *) malloc(Cols * sizeof(int)); //para cada linha alocar memoria para as col
    }
    return board;
}

/**
 * Funçao para libertar uma matrix
 * @param board matrix criada
 * @param Rows linhas da matrix
 */
void free_board(int **board, int Rows) {
    int row;

    for (row = 0; row < Rows; row++) { //percorre as linhas da matrix e da free
        free(board[row]);
    }

    free(board); // Eventually free the memory of the pointers to the rows
}

/**
 * Funçao para gerar aleatoriamente uma populaçao inicial
 * @param cliente cliente a que pertence a viagem
 * @param id_viagem id da viagem
 * @param numPops num de populaçoes a criar
 */
void createPopulation(CLIENTES *cliente, int id_viagem, int numPops) {
    VIAGEM *viagens = cliente->viagens_arr;
    srand(time(0));
    VIAGEM viagem;
    populacoes = (POPULACAO *) malloc(sizeof(POPULACAO));
    populacoes->trajetos = (INDIVIDUO *) malloc(numPops * sizeof(INDIVIDUO));
    populacoes->tamPopulacao = numPops;

    for (int i = 0; i < cliente->num_viagens; i++) {
        if (viagens[i].id == id_viagem) {
            viagem = viagens[i];
            break;
        }
    }

    int v[viagem.num_cidades];
    int **matrix = allocate_board(numPops, viagem.num_cidades);
    printf("\nTrajetos possiveis: \n");

    INDIVIDUO *cd = (INDIVIDUO *) malloc(numPops * sizeof(INDIVIDUO));
    for (int i = 0; i < viagem.num_cidades; i++) { //array inicial
        v[i] = i + 1;
    }
    for (int k = 0; k < numPops; k++) {
        for (int j = 0; j < viagem.num_cidades; j++) { //array random
            int temp = v[j];
            int randomIndex = rand() % viagem.num_cidades;

            v[j] = v[randomIndex];
            v[randomIndex] = temp;
        }

        int *arr = (int *) malloc(viagem.num_cidades * sizeof(int));

        for (int i = 0; i < viagem.num_cidades; i++) {
            //  printf("%d ", v[i]);
            matrix[k][i] = v[i];
            arr[i] = v[i];
        }

        cd[k].array_order = arr;
        cd[k].id_trajeto = k;

        populacoes->trajetos[k] = cd[k];

        printf("Id_trajeto: %d - ", populacoes->trajetos[k].id_trajeto);
        for (int i = 0; i < viagem.num_cidades; i++) {
            printf("%d ", populacoes->trajetos[k].array_order[i]);
        }
        printf("\n");
    }

    printf("\nMatrix: \n");
    for (int x = 0; x < numPops; x++) {
         printf("%d - ", x);
        for (int z = 0; z < viagem.num_cidades; z++) {
            printf("%d ", matrix[x][z]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * Funçao para pesquisar a cidade para usarmos na funçao de calcular a aptidao de cada populaçao
 * @param v apontador para as viagens
 * @param id_cidade id da cidade
 * @return cidade encontrada
 */
CIDADE *pesquisa_cidade_fitness(VIAGEM *v , int id_cidade) {
    CIDADE *cidades = v->cidades;
    CIDADE *aux=(CIDADE*) malloc(sizeof(CIDADE));

    while (cidades != NULL) {
        if (cidades->id == id_cidade) {
            aux=cidades;
            break;
        }
        cidades = cidades->next;
    }
    return aux;
}

/**
 * Funçao para pesquisar as viagens de um dado cliente
 * @param nif_cliente nif do cliente para procurar a viagem
 * @param id_viagem id da viagem
 * @return viagem encontrada
 */
VIAGEM *pesquisa_viagem_cliente(int nif_cliente, int id_viagem) {
    VIAGEM *viagem=(VIAGEM*) malloc(sizeof(VIAGEM));
    CLIENTES *cliente = procurar_cliente_nif(nif_cliente);
    VIAGEM *viagens = cliente->viagens_arr;
    for (int i = 0; i < cliente->num_viagens; i++) {
        if (viagens[i].id == id_viagem) {
            viagem = &viagens[i];
        }
    }
    return viagem;
}

/**
 * Funçao para calcular a distancia entre 2 coordenadas
 * @param c1 coordenada 1
 * @param c2 coordenada 2
 * @return distancia entre as 2 coordenadas
 */
double dist(COORDS c1, COORDS c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

/**
 * Funçao para calcular a aptidao de cada individuo numa dada populaçao
 * @param v apontador para a viagem
 * @param nif_cliente nif do cliente
 */
void fitness(VIAGEM *v, int nif_cliente) {
    CIDADE *arr = (CIDADE *) malloc(v->num_cidades * sizeof(CIDADE));
    INDIVIDUO *trajetos = populacoes->trajetos;
    for (int i = 0; i < populacoes->tamPopulacao; i++) {
        float aux = 0;

        for (int j = 0; j < v->num_cidades; j++) {
            arr[j] = *(pesquisa_cidade_fitness(v, trajetos[i].array_order[j]));
            printf("%s ",arr[j].nome);
        }
        printf("\n");
        aux += (float) dist(arr[v->num_cidades - 1].localizacao, arr[0].localizacao);
        for (int j = 0; j < v->num_cidades - 1; j++) {
            aux += (float) dist(arr[j].localizacao, arr[j + 1].localizacao);
        }
        aux = 1 / aux;
        trajetos[i].aptidao = aux;
        printf("Trajeto: %d -> Aptidao: %f\n\n", i, trajetos[i].aptidao);
    }
}

int check_arrays(int *arr1[], int size, int *arr2[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (arr1[i] == arr2[j])
                count++;
        }
    }

    if (count == size)
        return 1;
    return 0;
}

void cruzamento(VIAGEM *v1){
    CIDADE *arr = (CIDADE *) malloc(v1->num_cidades * sizeof(CIDADE));
    INDIVIDUO *trajetos = populacoes->trajetos;
    INDIVIDUO *aux = populacoes->trajetos; //ordenado aptidao

    float maior_apt = 0.0f;
    float maior_apt2 = 0.0f;

    for (int i = 0; i < populacoes->tamPopulacao; i++) {
        if(trajetos[i].aptidao > trajetos[i + 1].aptidao && trajetos[i].aptidao > maior_apt){
            maior_apt = trajetos[i].aptidao;
            printf("Trajeto_apt1 = %f\n", maior_apt);
        }
    }

    for (int i = 0; i < populacoes->tamPopulacao; i++) {
        if(trajetos[i].aptidao > trajetos[i + 1].aptidao && trajetos[i].aptidao < maior_apt && trajetos[i].aptidao >= maior_apt2){
            maior_apt2 = trajetos[i].aptidao;
            printf("Trajeto_apt2 = %f\n", maior_apt2);
        }
    }

}