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
 * cria lista de cidades
 * @return node lista de cidades criada
 */
void *criar_lista_cidades() {
    LISTA_CIDADES *node = (LISTA_CIDADES *) malloc(sizeof(LISTA_CIDADES));
    node->head = NULL;
    node->num_cidades = 0;
    return node;
}

/**
 * Pesquisa de cidade
 * @param listaCidades lista de todas as cidades
 * @param cidade cidade a ser pesquisada
 * @return cidade pesquisada
 */
CIDADE *pesquisar_cidade(const char *cidade) {
    CIDADE *current = listaCidades->head;
    if (current == NULL) {
        printf("A lista esta vazia!!\n");
        return 0;
    }

    for (int i = 0; i < listaCidades->num_cidades; i++) {
        if (strcmp(current->nome, cidade) == 0) {
            printf("Encotramos a cidade!! \nNome: %s\nDescricao: %s\n", current->nome, current->descricao);
            return current;
        }
    }
    printf("Nao encontramos a cidade pretendida!!\n");
    return NULL;
}


/**
 * Editar informação da descricao de uma cidade
 * @param listaCidades Lista de Cidades
 * @param nome_cidade nome da cidade a editar
 * @param nova_descricao nova descricao da cidade
 */
void edit_cidade(const char *nome_cidade, const char *nova_descricao) {

    CIDADE *cidade = pesquisar_cidade(nome_cidade);

    if (cidade == NULL) {
        return;
    } else {
        strcpy(cidade->descricao, nova_descricao);
        printf("Info da cidade %s alterada!!\n", cidade->nome);
    }
}

/**
 * Inserir um Ponto de Interesse a uma cidade
 * @param listaCidades Lista de todas as cidades
 * @param nome_cidade cidade onde queremos inserir o PoI
 * @param nome_PoI PoI a inserir
 */
void insert_PoI(char *nome_cidade, char *nome_PoI) {
    CIDADE *cidade = pesquisar_cidade(nome_cidade);
    if (cidade == NULL) {
        printf("Cidade nao existe!!\n");
        return;
    } else {
        if (check_dups_PoI(nome_cidade, nome_PoI) == 0) {
            PoI *poI = (PoI *) malloc(sizeof(PoI));
            strcpy(poI->nome, nome_PoI);
            addPoItoGlobalList(poI);
            poI->next = cidade->pontos_interesse;
            cidade->pontos_interesse = poI;
            cidade->num_PoI++;
        } else
            return;
    }
}

/**
 * Editar um Ponto de Interesse de uma cidade
 * @param nome_cidade nome da cidade que contem o ponto de interesse
 * @param nome_PoI nome do ponto de interesse
 * @param novoNome_PoI novo nome do ponto de interesse
 */
void edit_PoI(char *nome_cidade, char *nome_PoI, char *novoNome_PoI) {
    CIDADE *cidade = pesquisar_cidade(nome_cidade);
    if (cidade != NULL) {
        // TO DO
    }
}

/**
 * Pesquisar um Ponto de Interesse de uma cidade
 * @param nome_cidade cidade onde vamos procurar o PoI
 * @param nome_PoI nome do PoI a ser procurado
 * @return retorna um PoI
 */
PoI *pesquisar_PoI(char *nome_cidade, char *nome_PoI) {
    CIDADE *cidade = pesquisar_cidade(nome_cidade);
    if (cidade != NULL) {
        //TO DO
    }
    return NULL;
}

/**
 * Remover um PoI da cidade
 * @param nome_PoI nome do PoI a ser removido
 */
void remove_PoI(char *nome_PoI) {
    //TO DO
}

/**
 * Verifica existencia de PoI duplicados numa cidade
 * @param nome_cidade cidade a procurar duplicados
 * @param nome_PoI PoI a verificar
 * @return retorna 1 se existir , 0 se nao existir e -1 se a cidade nao existir
 */
int check_dups_PoI(char *nome_cidade, char *nome_PoI) {
    CIDADE *cidade = pesquisar_cidade(nome_cidade);
    if (cidade == NULL) {
        printf("Cidade nao existe!!\n");
        return -1;
    } else {
        PoI *poI = cidade->pontos_interesse;
        while (poI != NULL) {
            if (strcmp(poI->nome, nome_PoI) == 0)
                return 1;
        }
    }
    return 0;
}

/**
 * Funcao complementar que adiciona um PoI a estrutura global de PoI's
 * @param poI PoI a ser adicionado
 */
void addPoItoGlobalList(PoI *poI) {
    PoI *current = listaPoI->head;

    while (current->next != NULL) { //JA ENTROU
        if (strcmp(current->nome, poI->nome) != 0) {
            printf("ERRO -> Ja existe um PoI com esse nome!! PoI nao foi introduzido\n");
            return;
        }
        current = current->next;
    }
    current->next = poI;
    listaPoI->num_PoI++;
}

/**
 * Funcao para adicionar uma viagem a um cliente
 * @param nif nif do cliente
 * @param id_viagem id escolhido para a viagem
 * @param pais_destino pais de destino da viagem
 */
void inserir_viagem(int nif, int id_viagem, char *pais_destino) {
    CLIENTES *cliente = procurar_cliente_nif(nif);
    VIAGEM *node = cliente->viagens_arr;
    if (node == NULL) {
        CLIENTES *clientes_arr = lc->head;

        /**
         * Verificar se o id escolhido para a viagem é igual a algum id de alguma viagem de qualquer cliente
         * (ID da viagem é unico globalmente)
         */
        while (clientes_arr != NULL) {
            VIAGEM *cl_viagem = clientes_arr->viagens_arr;
            while (cl_viagem != NULL) {
                if (cl_viagem->id == id_viagem) {
                    printf("\"ERRO -> inserir_viagem(): Ja existe uma viagem com esse id!! Viagem nao foi introduzido\n");
                    return;
                }
                cl_viagem = cl_viagem->next;
            }
            clientes_arr = clientes_arr->next;
        }
        VIAGEM *novo_no = (VIAGEM *) malloc(sizeof(VIAGEM));

        novo_no->id = id_viagem;
        novo_no->pais = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->pais, pais_destino);
        novo_no->nif_cliente = nif;
        novo_no->cidades = NULL;

        novo_no->next = NULL;

        novo_no->next = cliente->viagens_arr;
        cliente->viagens_arr = novo_no;
        cliente->num_viagens++;
        printf("Viagem Inserida!!\n");
        return;
    } else {
        while (node != NULL) {

            if (node->id == id_viagem) {
                printf("ERRO -> inserir_viagem(): Ja existe uma viagem com esse id!! Viagem nao foi introduzido\n");
                return;
            }
            node = node->next;
        }

        CLIENTES *clientes_arr = lc->head;

        /**
         * Verificar se o id escolhido para a viagem é igual a algum id de alguma viagem de qualquer cliente
         * (ID da viagem é unico globalmente)
         */
        while (clientes_arr != NULL) {
            VIAGEM *cl_viagem = clientes_arr->viagens_arr;
            while (cl_viagem != NULL) {
                if (cl_viagem->id == id_viagem) {
                    printf("\"ERRO -> inserir_viagem(): Ja existe uma viagem com esse id!! Viagem nao foi introduzido\\n");
                    return;
                }
                cl_viagem = cl_viagem->next;
            }
            clientes_arr = clientes_arr->next;
        }

        VIAGEM *novo_no = (VIAGEM *) malloc(sizeof(VIAGEM));

        novo_no->id = id_viagem;
        novo_no->pais = (char *) malloc(50 * sizeof(char));
        strcpy(novo_no->pais, pais_destino);
        novo_no->nif_cliente = nif;
        novo_no->cidades = NULL;
        novo_no->next = NULL;

        novo_no->next = cliente->viagens_arr;
        cliente->viagens_arr = novo_no;
        cliente->num_viagens++;
        printf("Viagem Inserida!!\n");

    }
}

/**
 * Funcao para imprimir as viagens de um cliente
 * @param nif nif do cliente
 */
void imprimir_viagens_cliente(int nif) {
    CLIENTES *cliente = procurar_cliente_nif(nif);
    VIAGEM *current = cliente->viagens_arr;
    if (current == NULL) {
        printf("Cliente com o NIF: %d nao tem viagens marcadas!!\n", nif);
    }
    while (current != NULL) {
        printf("ID: %d\tPais: %s\tNIF Cliente: %d\n", current->id, current->pais, current->nif_cliente);
        current = current->next;
    }
}

/**
 * Funcao para criar uma lista global para as viagens
 * @return retorna uma lista para viagens
 */
void *criar_lista_Viagens() {
    LISTA_VIAGENS *node = (LISTA_VIAGENS *) malloc(sizeof(LISTA_VIAGENS));
    node->head = NULL;
    node->num_viagens = 0;
    return node;
}

/**
 * Funcao que cria ou redimensiona um array dinamico de Viagens
 * Se o array nao tiver memoria: criamos e inicializamos o array
 * senao retorna o array com o novo tamanho, e com as novas posicoes a 0
 * @param viagem_arr array a ser criado ou redimensionado
 * @param size tamanho do array antes de chamar a funcao
 * @param newsize novo tamanho
 * @return retorna o array com o novo tamanho
 */
VIAGEM *create_or_resize_dyn_viagem_array(VIAGEM *viagem_arr, int size, int newsize) {
    VIAGEM *new_arr = (VIAGEM *) calloc(newsize, sizeof(VIAGEM));
    for (int i = 0; i < size; i++) {
        *(new_arr + i) = *(viagem_arr + i);
    }
    free(viagem_arr);
    return new_arr;
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

    while (current != NULL) {
        if (current->id == id_viagem) {
            strcpy(current->pais, novo_pais);
            return;
        }
        current = current->next;
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
        if (viagens == NULL) {
            printf("Cliente %s ainda nao tem viagens marcadas!!\n", clientes->nome);
            return NULL;
        }
        while (viagens != NULL) {
            if (viagens->id == id_viagem) {
                printf("Viagem encontrada!!\n");
                return viagens;
            }
            viagens = viagens->next;
        }
        clientes = clientes->next;
    }
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
    VIAGEM *current = clientes->viagens_arr, *anterior = NULL;
    while (current != NULL && current->id != id_viagem) {
        anterior = current;
        current = current->next;
    }
    if (current == clientes->viagens_arr) {
        clientes->viagens_arr = clientes->viagens_arr->next;
        free(current);
        printf("Viagem removida!!\n");
        clientes->num_viagens--;
        return;
    }

    if (current == NULL) {
        printf("A viagem que quer eliminar nao existe!!\n");
    }

    anterior->next = current->next;
    free(current);
    printf("Viagem removida!!\n");
    clientes->num_viagens--;
}