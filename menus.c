#include<stdio.h>
#include "menus.h"
#include "funcoes.h"
#include "estruturas.h"

#define MENU_CLIENTES 1
#define MENU_RESERVAS 2
#define MENU_PRATOS 3
#define MENU_PEDIDOS 4
#define MENU_PAGAMENTOS 5
#define SAIR_DA_APLICACAO 6

#define NOVO_CLIENTE 1
#define EDITAR_CLIENTE 2
#define ELIMINAR_CLIENTE 3
#define LISTAR_CLIENTE 4
#define PESQUISAR_CLIENTE 5
#define SAIR_DA_APLICACAO 6

void apresentacao()
{
	char opcao;
	printf("\t---------------------------------------------\n");
	printf("\tUNIVERSIDADE CATOLICA DE ANGOLA");
	printf("\tFACULDADE DE ENGENHARIA\n");
	printf("\tPROJECTO DE FUNDAMENTOS DE PROG. I ANO 24-25\n");
	printf("\tAUTOR: FERNANDO AFONSO SEBASTIAO, N. 34422\n");
	printf("\t------------------------------------------------\n");
	printf("\tTEMA: GESTAO DE UM RESTAURANTE\n");
	printf("\tDOCENTE: ENG. OSVALDO RAMOS\n");
	printf("\tOBS: USO EXCLUSIVO DENTRO DA UCAN\n");
	printf("\t------------------------------------------------\n");
	printf("\tSE CONCORDA COM OS TERMOS DE USO DIGITE S, N CASO CONTRARIO\n");
	scanf("%c", &opcao);
	if(opcao == 'S' || opcao == 's')
	menuPrincipal();
	else 
	{
		printf("Muito Obrigado. Ate a proxima!\n");
		return;
	}
}

void menuPrincipal()
{
	int opcao;
	system("cls");
	
	printf("***MENU PRINCIPAL***\n");
	printf("***1 - MENU CLIENTES***\n");
	printf("***2 - MENU RESERVAS***\n");
	printf("***3 - MENU PRATOS***\n");
	printf("***4 - MENU PEDIDOS***\n");
	printf("***5 - MENU PAGAMENTOS");
	printf("***6 - SAIR DA APLICACAO");
	printf("Escolha uma opcao\n");
	scanf("%d", &opcao);
	switch(opcao){
		case MENU_CLIENTES:
			menuCliente();
		break;
		
		case MENU_RESERVAS:
			printf("Menu Reservas\n");
		break;
		
		case MENU_PRATOS:
			printf("Menu pratos\n");
		break;
		
		case MENU_PEDIDOS:
			printf("Menu Pedidos\n");
		break;
		
		case MENU_PAGAMENTOS:
			printf("Menu Pagamentos\n");
		break;
		
		case SAIR_DA_APLICACAO:
			return;
		break;
		
		default:
			printf("Opcao Invalida\n");
	}
	
}

void menuCliente()
{
	
	int opcao;
	
	system("cls");
	
	printf("***MENU CLIENTE***\n");
	printf("***1 - NOVO CLIENTE***\n");
	printf("***2 - EDITAR CLIENTE***\n");
	printf("***3 - ELIMINAR CLIENTE***\n");
	printf("***4 - LISTAR CLIENTE***\n");
	printf("***5 - PESQUISAR CADAVER***\n");
	printf("***6 - SAIR_DA_APLICACAO***\n");
	printf("Escolha uma opcao\n");
	scanf("%d", &opcao);
	
	switch (opcao)
	{
		case NOVO_CLIENTE:
			salvarDadosCliente();
		break;
		
		case EDITAR_CLIENTE:
			printf("Editar Cliente\n");
		break;
		
		case ELIMINAR_CLIENTE:
			printf("Eliminar Cliente\n");
		break;
	
		case LISTAR_CLIENTE:
			printf("Listar Clienter\n");
		break;
		
		case PESQUISAR_CLIENTE:
			printf("Pesquisar Cliente\n");
		break;
			
		case SAIR_DA_APLICACAO:
			return;
		break;
		
		default:
			printf("Opcao Invalida\n");
	}
}
