/*************************
File: Analise.c
Tema: Gestão de um Restaurante
Nome: Fernando Afonso Sebastiao, 34422
Data: 18.01.2025
**************************/

/*
1. Objectivo do Projecto:
Implementar um sistema capaz de gerir reservas, 
pedidos e pagamentos de clientes num restaurante.

2. Menus
	2.1 - MENU PRINCIPAL
			1 - MENU CLIENTES
			2 - MENU RESERVAS
			3 - MENU PRODUTO
			4 - MENU VENDA
			6 - SAIR DA APLICAÇÃO
			
	2.1.1 - MENU CLIENTES
			1 - NOVO CLIENTE
			2 - EDITAR CLIENTE
			3 - ELIMINAR CLIENTE
			4 - LISTAR CLIENTES
			5 - PESQUISAR CLIENTE POR NOME
			6 - LISTAR CLIENTES PELA DATA
			7 - VOLTAR
			
	2.1.2 - MENU RESERVAS
			1 - NOVA RESERVA
			2 - EDITAR RESERVA
			3 - ELIMINAR RESERVA
			4 - LISTAR RESERVAS
			5 - PESQUISAR RESERVA
			6 - VOLTAR
			
	2.1.3 - MENU PRODUTO
			1 - NOVO PRODUTO
			2 - EDITAR PRODUTO
			3 - ELIMINAR PRODUTO
			4 - LISTAR PRODUTO
			5 - PESQUISAR PRODUTO PELO NOME
			6 - VOLTAR
			
	2.1.4 - MENU VENDA
			1 - NOVA VENDA
			2 - EDITAR VENDA
			3 - ELIMINAR VENDA
			4 - LISTAR VENDA
			5 - PESQUISAR VENDA
			6 - VOLTAR
			
			
3. Entidades
	DATE
		int dia, mes, ano;
		
	CLIENTE
		int id;
		char nome[50], telefone[15],  bi[15];
		
	RESERVA
		int id, idCliente, numPessoas;
		DATE dataReserva;
		char horario[10], funcionario[50];
		
	PRODUTO
	int id; 
	char nome_produto[50]; 
	float preco
		
	VENDA
	int id, id_cliente, id_produto, quantidade;
	char forma_pagamento[20], funcionario[50];
	DATE data_venda;
	float valor_total;
		
4. Ficheiros de Dados
	CLIENTES.DAT
	RESERVAS.DAT
	PRODUTOS.DAT
	VENDAS.DAT
	
5. Implementação
Linguagem C, no IDE: Dev-C++
*/

