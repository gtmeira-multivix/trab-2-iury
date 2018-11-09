#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

typedef struct _arvore {
  struct _arvore *esquerda;
  struct _arvore *direita;
  Candidato cand;
}Arvore;

Arvore* arvore_inserir(Arvore *a, Candidato cand) {
  
   if (a == NULL) {
        Arvore *novo = (Arvore*) malloc(sizeof(Arvore));
        novo->cand= cand;
        novo->direita = NULL;
        novo->esquerda = NULL;
        return novo;
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
  	

    if (a == NULL ){
    	
    	return NULL;
        
    }else if(a->cand.numero == candNumero){
    	printf("%lf", a->cand.nome);
		printf("%lf", a->cand.cargo);
		
		return &a->cand;
		
	}
    		

	if(candNumero < a->cand.numero){
		return arvore_buscar(a->esquerda, candNumero);
	} 
	else {
		return arvore_buscar(a->direita, candNumero);
	}

   
}

void arvore_imprime_em_ordem(Arvore *a) {
	if(a->esquerda != NULL) 
	{
		arvore_imprime_em_ordem(a->esquerda);
	}
	printf("%lf", a->cand.numero);
	printf("%lf", a->cand.nome);
	printf("%lf", a->cand.cargo);
	
	if(a->direita != NULL) 
	{
		arvore_imprime_em_ordem(a->direita);
	}
}
