/*
	Name: TaskMan
	Copyright: ISPTEC
	Author: joaojdacosta@gmail.com
	Date: 08/12/22 15:24
	Description: Software para gestão de tarefas.
*/

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
t_listas l;

void menu(int );

int main(int argc, char *argv[]) {
		
	iniciar (&l);
	int i, op;
	char nome[30];
	
	do {

	printf("Menu\n");
	printf("1. Meu dia\n");
	printf("2. Importante\n");
	printf("3. Planeada\n");
	for(i = 0; i < l.t; i++)
		printf("%d. %s\n",l.v[i].id,l.v[i].nome);
	printf("-1. Adicionar\n");
	printf("-2. Remover\n");
	
	printf("\n\nComando: ");
	scanf("%d",&op);
	
	switch(op){
		case -1:
			puts("Digite o nome da lista: ");
			fflush(stdin);
			gets(nome); // leitura
			if(adicionar(&l, nome)){
				puts("Lista inserida com sucesso!!! ");
				
			} else {
				puts("Erro!!! A lista ja existe...");
			}
			break;
		case -2:
			puts("Digite o id da lista a remover: ");
			scanf("%d",&i); // leitura
			if(remover(&l, i)){
				puts("Lista removida com sucesso!!! ");
				
			} else {
				puts("Erro!!! A lista inexistente...");
			}
			break;
			// 
		case 1: // 
		case 2:
		case 3: break;
		default:
			menu(op);
	}
	
		} while(6);
	
	return 0;
}

void menu(int b){
	
	int i;
	t_lista k;
	
	if(!encontrar(l, b, &k))
		return;
	
	printf("\nLista %s\n\n",k.nome);
	printf("1. Adicionar\n");
	printf("2. Lista de tarafas\n");
	printf("3. Tarafas concluidas\n");
	printf("4. Voltar\n");
	
	printf("\n\nComando: ");
	scanf("%d",&i);	
}
