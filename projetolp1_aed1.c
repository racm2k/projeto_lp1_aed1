//
// Created by diogo on 11/11/2021.
//

#include "projetolp1_aed1.h"
#include "testes.c"


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
    node->head = NULL;
    node->num_clientes = 0;
    return node;
}

/**
 * Criar Lista ligada de pontos de interesse das cidades
 * @return node lista de pontos de interesse das cidades criada
 */
void *criar_lista_PoI() {
    LISTA_PoI *node = (LISTA_PoI *) malloc(sizeof(LISTA_PoI));
    node->head = NULL;
    node->num_PoI = 0;
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
void inserir_cliente_cabeca(int id, char *nome, char *morada, int contacto, int nif, struct tm data, int brithDay,
                            int birthMon, int birthYear) {
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
        novo_no->viagens_arr = NULL;
        novo_no->num_viagens = 0;
        novo_no->next = NULL;

        novo_no->next = lc->head;
        lc->head = novo_no;
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
        novo_no->data_registo.ano = data.tm_year + 1900;
        novo_no->data_registo.mes = data.tm_mon + 1;
        novo_no->data_registo.dia = data.tm_mday;
        novo_no->viagens_arr = NULL;
        novo_no->num_viagens = 0;
        novo_no->next = NULL;

        novo_no->next = lc->head;
        lc->head = novo_no;
        lc->num_clientes++;
    }
}

/**
 * Imprimir os clientes
 */
void imprimir_cliente() {
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
void inserir_cliente_cauda(int id, char *nome, char *morada, int contacto, int nif, struct tm data, int brithDay,
                           int birthMon, int birthYear) {
    CLIENTES *current = lc->head, *ant = NULL;

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
    ant->data_registo.ano = data.tm_year + 1900;
    ant->data_registo.mes = data.tm_mon + 1;
    ant->data_registo.dia = data.tm_mday;
    ant->viagens_arr = NULL;
    ant->num_viagens = 0;
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
void inserir_cliente_ordenado(int id, char *nome, char *morada, int contacto, int nif, bool insNome, struct tm data,
                              int brithDay, int birthMon, int birthYear) {
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
    c->viagens_arr = NULL;
    c->num_viagens = 0;
    c->next = NULL;

    if (lc->head == NULL || lc->num_clientes == 0) {
        lc->head = c;
        lc->num_clientes++;
        return;
    } else {
        CLIENTES *current = lc->head, *ant = NULL;

        while (current->next != NULL) {
            if (current->id == id || current->nif == nif) {
                printf("ERRO -> inserir_cliente_ord(): Ja existe um cliente com esse id/nif!! Cliente nao foi introduzido\n");
                return;
            }
            current = current->next;
        }
        current = lc->head;

        if (insNome == true) {  // INSERIR ORDENADO PELO NOME
            while (current != NULL && strcmp(nome, current->nome) > 0) {//enquanto n chegar sitio certo NOME
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
        } else { // INSERIR ORDENADO PELO NIF
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

/**
 * Remover cliente
 * @param id id do cliente
 */
void remover_cliente(int id) {
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

/**
 * procurar cliente por nome
 * @param nome nome do cliente
 * @return cliente encontrado com esse nome
 */
CLIENTES *procurar_cliente_nome(const char *nome) {
    CLIENTES *current = lc->head;

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
    CLIENTES *current = lc->head;

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

/**
 * Imprimir lista ligada ordenada
 */
void imprimir_ordenado() {
    CLIENTES *current = lc->head;
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
void inserir_cidade(int id_viagem, int id_cidade, char *nome_cidade, char *descricao) {
    VIAGEM *viagem = pesquisar_viagem(id_viagem);

    while (viagem != NULL) {
        if (viagem->id == id_viagem) {

            if (viagem->num_cidades == viagem->maxNum_cidades) {
                if (viagem->maxNum_cidades == 0) {
                    viagem->maxNum_cidades = 2;
                } else {
                    viagem->maxNum_cidades *= 2;
                }

                viagem->cidades = (CIDADE *) realloc(viagem->cidades, viagem->maxNum_cidades * sizeof(CIDADE));
            }
            CIDADE *arr_cidades = viagem->cidades;
            for (int i = 0; i < viagem->num_cidades; i++) {
                if (arr_cidades[i].id == id_cidade) {
                    printf("Cidade já existente!!\n");
                    return;
                }
            }


            arr_cidades[viagem->num_cidades].nome = (char *) malloc(50 * sizeof(char));
            strcpy(arr_cidades[viagem->num_cidades].nome, nome_cidade);
            arr_cidades[viagem->num_cidades].descricao = (char *) malloc(50 * sizeof(char));
            strcpy(arr_cidades[viagem->num_cidades].descricao, descricao);
            arr_cidades[viagem->num_cidades].id = id_cidade;
            arr_cidades[viagem->num_cidades].pontos_interesse = NULL;
            arr_cidades[viagem->num_cidades].num_PoI = 0;
            viagem->cidades = arr_cidades;
            viagem->num_cidades++;
            printf("Cidade inserida!!\n");
            return;

        }

        viagem = viagem->next;
    }
}


/**
 * Pesquisa de cidade
 * @param cidade nome da cidade a ser pesquisada
 * @return array das cidades pesquisada
 */
CIDADE *pesquisar_cidade_nome(int id_viagem, char *cidade) {
    CLIENTES *clientes = lc->head;

    if (clientes == NULL) {
        printf("Lista de Clientes Vazia!!\n");
        return NULL;
    }

    VIAGEM *viagem = pesquisar_viagem(id_viagem);
    if (viagem != NULL) {
        CIDADE *arr_cidades = viagem->cidades;
        for (int i = 0; i < viagem->num_cidades; i++) {
            if (strcmp(arr_cidades[i].nome, cidade) == 0) {
                printf("Cidade Encontrada!!\n");
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
void inserir_viagem(int nif, int id_viagem, char *pais_destino) {
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
                    printf("Viagem já existente!!\n");
                    return;
                }
            }
            cliente->viagens_arr = realloc(cliente->viagens_arr, cliente->maxNum_viagens * sizeof(VIAGEM));
            arr_viagens[cliente->num_viagens].id = id_viagem;
            arr_viagens[cliente->num_viagens].pais = (char *) malloc(50 * sizeof(char));
            strcpy(arr_viagens[cliente->num_viagens].pais, pais_destino);
            arr_viagens[cliente->num_viagens].nif_cliente = nif;
            arr_viagens[cliente->num_viagens].cidades = NULL;
            arr_viagens[cliente->num_viagens].num_cidades = 0;
            arr_viagens[cliente->num_viagens].maxNum_cidades = 0;
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
    printf("Cliente %d\tNome: %s\tNIF: %d\tNumero de Viagens: %d\n", cliente->id, cliente->nome, cliente->nif,
           cliente->num_viagens);
    for (int i = 0; i < cliente->num_viagens; i++) {
        printf("ID: %d\tPais: %s Num Cidades: %d\n", current[i].id, current[i].pais, current[i].num_cidades);
        if(current[i].cidades!=NULL){
            for (int j = 0; j < current[i].num_cidades; j++) {
                printf(" Cidade: %s\tDescricao: %s\n", current[i].cidades[j].nome, current[i].cidades[j].descricao);
            }

        }

    }

//    free(current);

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
    CLIENTES *clientes = lc->head;
    if (clientes == NULL) {
        printf("Lista de Clientes vazia!!\n");
        return NULL;
    }
    while (clientes != NULL) {
        VIAGEM *viagens = clientes->viagens_arr;

        for (int i = 0; i < clientes->num_viagens; i++) {
            if (viagens != NULL) {
                if (viagens[i].id == id_viagem) {
                    printf("Viagem encontrada!!\n");
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
void remove_viagem(int id_viagem) {
    VIAGEM *viagem = pesquisar_viagem(id_viagem);
    CLIENTES *clientes = procurar_cliente_nif(viagem->nif_cliente);
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
    for (int i = 0; i < clientes->num_viagens; i++) {
        if (current->id == id_viagem) {
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


CIDADE *create_or_resize_dyn_cidade_array(CIDADE *cidade_arr, int size, int newsize) {
    CIDADE *new_arr = (CIDADE *) calloc(newsize, sizeof(CIDADE));
    for (int i = 0; i < size; i++) {
        *(new_arr + i) = *(cidade_arr + i);
    }
    free(cidade_arr);
    return new_arr;
}



