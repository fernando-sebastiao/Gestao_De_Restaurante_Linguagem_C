#include<stdio.h>
#include "menus.h"
#include "funcoes.h"
#include "estruturas.h"

#define MENU_CLIENTES 1
#define MENU_RESERVAS 2
#define MENU_PRODUTO 3
#define MENU_VENDAS 4
#define SAIR 5

#define NOVO_CLIENTE 1
#define EDITAR_CLIENTE 2
#define ELIMINAR_CLIENTE 3
#define LISTAR_CLIENTE 4
#define PESQUISAR_CLIENTE_POR_NOME 5
#define PESQUISAR_CLIENTE_POR_DATA 6
#define VOLTAR_CLIENTE 7


#define NOVA_RESERVA 1
#define EDITAR_RESERVA 2
#define ELIMINAR_RESERVA 3
#define LISTAR_RESERVA 4
#define PESQUISAR_RESERVA 5
#define VOLTAR_RESERVA 6

#define NOVA_VENDA 1
#define EDITAR_VENDA 2
#define ELIMINAR_VENDA 3
#define LISTAR_VENDA 4
#define PESQUISAR_VENDA 5
#define VOLTAR_VENDA 6

#define NOVO_PRODUTO 1
#define EDITAR_PRODUTO 2
#define ELIMINAR_PRODUTO 3
#define LISTAR_PRODUTO 4
#define PESQUISAR_PRODUTO_NOME 5
#define VOLTAR_PRODUTO 6

void apresentacao()
{
	system("cls");
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
	getchar();
	scanf("%c", &opcao);
	if(opcao == 'S' || opcao == 's')
	menuPrincipal();
	else 
	{
		printf("Muito Obrigado. Ate a proxima!\n");
		return;
	}
}

int login() {
    char email[100];
    char senha[50];

    printf("***** LOGIN *****\n");
    printf("Email: ");
    scanf("%s", email);
    printf("Senha: ");
    scanf("%s", senha);

    // Verifica credenciais
    if (strcmp(email, "fernandosebastiao888@gmail.com") == 0 && strcmp(senha, "Honestidade888") == 0) {
        return 1; 
    } else {
        printf("Credenciais incorretas! Tente novamente.\n\n");
        return 0; 
    }
}

void menuPrincipal()
{
	int opcao;
	system("cls");
	
	printf("***MENU PRINCIPAL***\n");
	printf("***1 - MENU CLIENTES***\n");
	printf("***2 - MENU RESERVAS***\n");
	printf("***3 - MENU PRODUTO***\n");
	printf("***4 - MENU VENDAS***\n");
	printf("***5 - SAIR DA APLICACAO\n");
	printf("Escolha uma opcao\n");
	scanf("%d", &opcao);
	switch(opcao){
		case MENU_CLIENTES:
			menuCliente();
		break;
		
		case MENU_RESERVAS:
			menuReservas();
		break;
		
		case MENU_PRODUTO:
			menuProduto();
		break;
		
		case MENU_VENDAS:
			menuVendas();
		break;
		
		case SAIR:
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
	
	do {
	printf("***MENU CLIENTE***\n");
	printf("***1 - NOVO CLIENTE***\n");
	printf("***2 - EDITAR CLIENTE***\n");
	printf("***3 - ELIMINAR CLIENTE***\n");
	printf("***4 - LISTAR CLIENTE***\n");
	printf("***5 - PESQUISAR POR NOME***\n");
	printf("***6 - LISTAR CLIENTES PELA DATA***\n");
	printf("***7 - VOLTAR\n");
	printf("Escolha uma opcao\n");
	scanf("%d", &opcao);
	
	switch (opcao)
	{
		case NOVO_CLIENTE:
			salvarDadosCliente();
		break;
		
		case EDITAR_CLIENTE:
			editarClientePorNome();
		break;
		
		case ELIMINAR_CLIENTE:
			eliminarClientePorNome();
		break;
	
		case LISTAR_CLIENTE:
			listarDadosCliente();
		break;
		
		case PESQUISAR_CLIENTE_POR_NOME:
			pesquisarClientePorNome();
		break;
		
		case PESQUISAR_CLIENTE_POR_DATA:
			pesquisarClientesPelaData();
		break;
			
		case VOLTAR_CLIENTE:
			menuPrincipal();
		break;
		
		default:
			printf("Opcao Invalida\n");
	}
	}while(opcao != VOLTAR_CLIENTE);
}

void menuReservas(){
		int opcao;
	
	system("cls");
	do{
	printf("\n");
	printf("***MENU RESERVAS***\n");
	printf("***1 - NOVA RESERVA***\n");
	printf("***2 - EDITAR RESERVA***\n");
	printf("***3 - ELIMINAR RESERVA ***\n");
	printf("***4 - LISTAR RESERVA***\n");
	printf("***5 - PESQUISAR RESERVA PELA DATA***\n");
	printf("***6 - VOLTAR***\n");
	printf("\nEscolha uma opcao\n");
	scanf("%d", &opcao);
	
	switch (opcao)
	{
		case NOVA_RESERVA:
			salvarDadosReserva();
		break;
		
		case EDITAR_RESERVA:
			editarReserva();
		break;
		
		case ELIMINAR_RESERVA:
			eliminarReserva();
		break;
	
		case LISTAR_RESERVA:
			listarDadosReserva();
		break;
		
		case PESQUISAR_RESERVA:
			pesquisarReservasPelaData();
		break;
				
		case VOLTAR_RESERVA:
			menuPrincipal();
		break;
		
		default:
			printf("Opcao Invalida\n");
	}
	}while(opcao!=VOLTAR_RESERVA);

}

void menuVendas(){
	
		int opcao;
	
	system("cls");
	do{
	printf("\n");
	printf("***MENU VENDAS***\n");
	printf("***1 - NOVA VENDA***\n");
	printf("***2 - EDITAR VENDA***\n");
	printf("***3 - ELIMINAR VENDA ***\n");
	printf("***4 - LISTAR VENDA***\n");
	printf("***5 - PESQUISAR VENDA***\n");
	printf("***6 - VOLTAR***\n");
	printf("\nEscolha uma opcao\n");
	scanf("%d", &opcao);
	
	switch (opcao)
	{
		case NOVA_VENDA:
			salvarDadosVenda();
		break;
		
		case EDITAR_VENDA:
			printf("Editar Venda\n");
		break;
		
		case ELIMINAR_VENDA:
			printf("Eliminar Venda\n");
		break;
	
		case LISTAR_VENDA:
			listarDadosVendas();
		break;
		
		case PESQUISAR_VENDA:
			pesquisarVendaPelaData();
		break;
				
		case VOLTAR_VENDA:
			menuPrincipal();
		break;
		
		default:
			printf("Opcao Invalida\n");
	}
	}while(opcao!=VOLTAR_VENDA);
}

void menuProduto(){
	
		int opcao;
	
	system("cls");
	do{
	printf("\n");
	printf("***MENU PRODUTO***\n");
	printf("***1 - NOVO PRODUTO***\n");
	printf("***2 - EDITAR PRODUTO***\n");
	printf("***3 - ELIMINAR PRODUTO ***\n");
	printf("***4 - LISTAR PRODUTOS***\n");
	printf("***5 - PESQUISAR PRODUTO***\n");
	printf("***6 - VOLTAR***\n");
	printf("\nEscolha uma opcao\n");
	scanf("%d", &opcao);
	
	switch (opcao)
	{
		case NOVO_PRODUTO:
			salvarDadosProduto();
		break;
		
		case EDITAR_PRODUTO:
			editarProdutoPorNome();
		break;
		
		case ELIMINAR_PRODUTO:
			eliminarProdutoPorNome();
		break;
	
		case LISTAR_PRODUTO:
			listarDadosProdutos();
		break;
		
		case PESQUISAR_PRODUTO_NOME:
			pesquisarProdutoPeloNome();
		break;
				
		case VOLTAR_PRODUTO:
			menuPrincipal();
		break;
		
		default:
			printf("Opcao Invalida\n");
	}
	}while(opcao!=VOLTAR_PRODUTO);
}



