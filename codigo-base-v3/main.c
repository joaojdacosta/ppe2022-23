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
#include "tarefa.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
t_listas l;
t_tarefas lt;

void menu(int );

int main(int argc, char *argv[]) {
		
	iniciar (&l);
	iniciar_tarefas (&lt);
	
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
		case 1: // Listar as tarefas do dia
		case 2: // Listar as tarefas importantes
		case 3: // Listar as tarefas planeadas
		
			break;
		default:
			menu(op);
	}
	
		} while(6);
	
	return 0;
}

void menu(int b){
	
	int i, p;
	t_lista k;
	t_tarefa t;
	
	if(!encontrar(l, b, &k))
		return;
	
	do {
		printf("\nLista %s [%d]\n\n",k.nome,k.id);
		printf("1. Adicionar\n");
		printf("2. Lista de tarafas\n");
		printf("3. Tarafas concluidas\n");
		printf("4. Voltar\n");
		
		printf("\n\nComando: ");
		scanf("%d",&i);	
		
		switch(i){
			case 1: // adicionar 

				printf("\n\nADICIONAR TAREFA\n\n");
				
				puts("Digite a descricao:");
				fflush(stdin);
				gets(t.descricao);
				puts("E importante? (0 - Nao ou 1 - Sim):");
				scanf("%d",&t.importante);
				puts("E para hoje? (0 - Nao ou 1 - Sim):");
				scanf("%d",&t.hoje);
				puts("Tem prazo?: (se sim, digite a data,...)");
				fflush(stdin);
				gets(t.prazo);
				t.id_lista = k.id;
				
				if(!adicionar_tarefa (&lt, t))
					puts("Memoria insuficiente...");
				else
					puts("Tarefa adicionada com sucesso!!!!");
				
				break;
			case 2: // listar
				printf("\n\n\nTarefas da lista %s\n\n",k.nome);
				for(p = 0; p < lt.t; p++)
					if(lt.v[p].id_lista == k.id)
						printf("%d, %s, %s\n",
							lt.v[p].id,
							lt.v[p].descricao,
							(lt.v[p].importante == 1)? "Importante": "Nao importante"
							);
				break;
			case 3: //listar tarefas concluidas	
				break;
		}
	}while(i != 4);
}
