#include "lista.h"

void inicia_lista(t_lista *pl) {
    pl->primeiro = NULL;
}

int lista_vazia(t_lista *pl) {
    return pl->primeiro == NULL;
}

void insere_vip(int e, t_lista *pl) {
    t_no *novo = constroi_no(e);

    if (lista_vazia(pl)) {
        pl->primeiro = novo;
        return;
    }

    if (pl->primeiro->info < 100) {
        novo->proximo = pl->primeiro;
        pl->primeiro = novo;
        return;
    }

    t_no *runner = pl->primeiro;

    while (runner->proximo != NULL &&
           runner->proximo->info >= 100) {
        runner = runner->proximo;
    }

    novo->proximo = runner->proximo;
    runner->proximo = novo;
}

void insere_fim(int e, t_lista *pl) {
    t_no *novo = constroi_no(e);
    if(lista_vazia(pl)) pl->primeiro = novo;
    else {
        t_no *runner = pl->primeiro;
        while(runner->proximo != NULL) {
            runner = runner->proximo;
        }
        runner->proximo = novo;
    }
}

int remove_inicio(t_lista *pl) {
    int copia_valor = pl->primeiro->info;
    t_no *copia_endereco = pl->primeiro;
    pl->primeiro = pl->primeiro->proximo;
    free(copia_endereco);
    return copia_valor;
}

int remove_fim(t_lista *pl) {
    int copia_valor;
    t_no *copia_endereco;
    if(pl->primeiro->proximo == NULL) { //so tem um elemento
        copia_valor = pl->primeiro->info;
        copia_endereco = pl->primeiro;
        pl->primeiro = NULL;
    }
    else {
        t_no *runner = pl->primeiro;
        while(runner->proximo->proximo != NULL) {
            runner = runner->proximo;
        }
        copia_valor = runner->proximo->info;
        copia_endereco = runner->proximo;
        runner->proximo = NULL;
    }
    free(copia_endereco);
    return copia_valor;

}

void exibe_lista(t_lista *pl) {
    if(lista_vazia(pl)) printf("lista vazia\n");
    else {
        t_no *runner = pl->primeiro;
        while(runner != NULL) {
            printf("%d -> ", runner->info);
            runner = runner->proximo;
        }
        printf("//\n");
    }

}