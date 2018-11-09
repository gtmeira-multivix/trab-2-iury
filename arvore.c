#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct _arvore {
  struct _arvore *esquerda;
  struct _arvore *direita;
  Candidato cand;
};

Arvore* arvore_inserir(Arvore *a, Candidato cand) {
  
   if (a == NULL) {
        Arvore *b = (Arvore *) malloc(sizeof(Arvore));
        b->cand = cand;
        b->direita = NULL;
        b->esquerda = NULL;
        return b;
    }

    if(cand.numero < a->cand.numero){
        a->esquerda = arvore_inserir(a->esquerda, cand);
    }
    else if(cand.numero > a->cand.numero){
        a->direita = arvore_inserir(a->direita, cand);
    }

    return a;
}

Candidato* arvore_buscar(Arvore *a, int candNumero) {
  
  Candidato *cand_tmp = NULL;

    if (a == NULL){
        printf("\nEste candidato não existe!\n\n");
        return cand_tmp;
    }

    cand_tmp = &a->cand;

    if(candNumero < a->cand.numero){
        cand_tmp = arvore_buscar(a->esquerda, candNumero);
    }
    else if(candNumero > a->cand.numero){
        cand_tmp = arvore_buscar(a->direita, candNumero);
    }

    return cand_tmp;
}

void arvore_imprime_em_ordem(Arvore *a) {
  
   if (a->esquerda != NULL){
        arvore_imprime_em_ordem(a->esquerda);
    }

    printf("%d - Nome: %s, Cargo: %s\n", a->cand.numero, a->cand.nome, a->cand.cargo);

    if (a->direita != NULL){
        arvore_imprime_em_ordem(a->direita);
    }
}
