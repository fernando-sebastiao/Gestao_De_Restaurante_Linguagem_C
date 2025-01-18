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
			3 - MENU PRATOS
			4 - MENU PEDIDOS
			5 - MENU PAGAMENTOS
			6 - SAIR DA APLICAÇÃO
			
	2.1.1 - MENU CLIENTES
			1 - NOVO CLIENTE
			2 - EDITAR CLIENTE
			3 - ELIMINAR CLIENTE
			4 - LISTAR CLIENTES
			5 - PESQUISAR CLIENTE
			6 - VOLTAR
			
	2.1.2 - MENU RESERVAS
			1 - NOVA RESERVA
			2 - EDITAR RESERVA
			3 - ELIMINAR RESERVA
			4 - LISTAR RESERVAS
			5 - PESQUISAR RESERVA
			6 - VOLTAR
			
	2.1.3 - MENU PRATOS
			1 - NOVO PRATO
			2 - EDITAR PRATO
			3 - ELIMINAR PRATO
			4 - LISTAR PRATOS
			5 - PESQUISAR PRATO
			6 - VOLTAR
			
	2.1.4 - MENU PEDIDOS
			1 - NOVO PEDIDO
			2 - EDITAR PEDIDO
			3 - ELIMINAR PEDIDO
			4 - LISTAR PEDIDOS
			5 - PESQUISAR PEDIDO
			6 - VOLTAR
			
	2.1.5 - MENU PAGAMENTOS
			1 - REGISTAR PAGAMENTO
			2 - EDITAR PAGAMENTO
			3 - ELIMINAR PAGAMENTO
			4 - LISTAR PAGAMENTOS
			5 - PESQUISAR PAGAMENTO
			6 - VOLTAR
			
3. Entidades
	DATE
		int dia, mes, ano;
		
	Cliente
		int id;
		char nome[50], telefone[15], email[50];
		
	Reserva
		int id, idCliente, numPessoas;
		DATE dataReserva;
		char horario[10], funcionario[50];
		
	Prato
		int id;
		char nome[50];
		float preco;
		
	Pedido
		int id, idReserva, idPrato, quantidade;
		float precoTotal;
		char funcionario[50];
		
	Pagamento
		int id, idPedido;
		DATE dataPagamento;
		float total;
		char funcionario[50];
		
4. Ficheiros de Dados
	Clientes.DAT
	Reservas.DAT
	Pratos.DAT
	Pedidos.DAT
	Pagamentos.DAT
	
5. Implementação
Linguagem C, no IDE: Dev-C++
*/

