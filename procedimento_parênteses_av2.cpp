/*
	�ltima quest�o do formul�rio da avalia��o 2
	Dupla: Milena Lins e Gabriel Alves
	Data: 15/12/20
*/

// Fun��es de manipula��o de pilhas do material enviado ao classroom:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct elemento {
	char info;
	struct elemento *prox;
} Elemento;

typedef struct pilha {
	Elemento *topo;
} Pilha;

Pilha* pilha_cria (void) {
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	if (p == NULL) exit(1);
	p->topo = NULL;
	return p;
};

void pilha_push (Pilha* p, float value) {
	Elemento* n = (Elemento*) malloc(sizeof(Elemento));
	if (n == NULL) exit(1);
	n->info = value;
	n->prox = p->topo;
	p->topo = n;
};

int pilha_vazia (Pilha* p) {
	if (p->topo == NULL) {
		return 1;
	};
	return 0;
};

float pilha_pop (Pilha* p) {
	Elemento* t;
	char value;
	if (pilha_vazia(p)) exit(1);
	t = p->topo;
	value = t->info;
	p->topo = p->topo->prox;
	free(t);
	return value;
};



void pilha_exclui (Pilha* p) {
	Elemento *t, *perc = p->topo;
	while (perc != NULL) {
		t = perc->prox;
		free(perc);
		perc = t;
	};
	free (p);
};


// Fun��es de manipula��o de pilha desenvolvidas por n�s (para exibir pilha e, respondendo a quest�o, uma fun��o para verificar sua sintaxe no uso correto dos par�nteses):

void pilha_exibe (Pilha* p) {
	Elemento *t, *perc = p->topo;
	while (perc != NULL) {
		t = perc->prox;
		printf("%c ", perc->info);
		perc = t;
	};
};

void pilha_verifica_sintaxe (Pilha* p) {

	Elemento *t, *perc = p->topo;
	int cont = 0;
	
	while (perc != NULL) {
		t = perc->prox;

		if (cont <= 0) {
			if (perc->info == ')') {
				cont--;
			}
			else if (perc->info == '(') {
				cont++;
			};
		}
		else {
			printf ("Um erro de sintaxe foi detectado: Par�nteses abertos n�o foram fechados! ");
			exit(1);
		};


//		printf ("%c \n", perc->info);
//		printf("__ \n");
		perc = t;
	};
	
	if (cont < 0) {
		printf ("H� par�nteses fechados que n�o foram abertos!");
		exit(1);
	} else {
		printf ("Sintaxe correta! ");
	};
};

main(){
	// Considerar que a express�o � exibida ao contr�rio em pilha_exibe(p), j� que a l�gica de pilha � que o �ltimo elemento da express�o seja exibido primeiro
	// Descomentar os casos que quizer testar, um por vez
	
	/* Caso de sintaxe correta:
	    Pilha *p = pilha_cria ();

	    pilha_push(p, '('); pilha_push(p, 'a'); pilha_push(p, '+'); pilha_push(p, 'b'); pilha_push(p, ')');
	    pilha_exibe(p);
	    pilha_verifica_sintaxe(p);
	*/
	
	/* Caso de erro por par�ntese aberto no final, sem ser fechado:
	    Pilha *p = pilha_cria ();

	    pilha_push(p, ')'); pilha_push(p, 'a'); pilha_push(p, '+'); pilha_push(p, 'b'); pilha_push(p, '(');
	    pilha_exibe(p);
	    pilha_verifica_sintaxe(p);
	*/
	
	/* Caso de erro por par�ntese fechado sem abertura:
	    Pilha *p = pilha_cria ();

	    pilha_push(p, ')'); pilha_push(p, '('); pilha_push(p, 'a'); pilha_push(p, '+'); pilha_push(p, 'b'); pilha_push(p, ')');
	    pilha_exibe(p);
	    pilha_verifica_sintaxe(p);
	*/
};
