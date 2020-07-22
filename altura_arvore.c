#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct No {
	int valor;
	struct No* esquerda;
	struct No* direita;
};

int Altura(struct No* h)
{
	if(h == NULL){
		return 0;
	} else {
		int altura_esquerda = Altura(h->esquerda);
		int altura_direita = Altura(h->direita);
		
		if(altura_esqueda < altura_direita){
			return altura_direita + 1;
		} else {
			return altura_esquerda + 1;
		}
	}
}
