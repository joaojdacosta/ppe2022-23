/*
	Name: TaskMan
	Copyright: ISPTEC
	Author: joaojdacosta@gmail.com
	Date: 08/12/22 15:24
	Description: Software para gestão de tarefas.
*/

typedef struct {
	int id;  // identificador
	char nome[30]; // descrição
	int fixo; // valor para identificar as listas nativas
}t_lista;

typedef struct {
	t_lista v[7]; // conjunto de 7 listas
	int t; // elementos adicionados
} t_listas;

void iniciar (t_listas *);

/**
* A funcao permite 
*/
int adicionar(t_listas *, char nome[30]);

int remover(t_listas *, int);

int encontrar(t_listas , int , t_lista *);



