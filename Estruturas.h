
typedef struct 
{
	int dia, mes, ano;
}DATE;

typedef struct
{
	int id;
		char nome[50], telefone[15], 
		email[50], bi[15], nacionalidade[20];
}CLIENTE;

typedef struct 
{
	int id, idCliente, numPessoas;
		DATE dataReserva;
		char horario[10], funcionario[50];
}RESERVA;

typedef struct 
{
		int id;
		char nome[50];
		float preco;
}PRATO;

typedef struct
{
	int id, idReserva, idPrato, quantidade;
		float precoTotal;
		char funcionario[50];
} PEDIDO;

typedef struct
{
	int id, idPedido;
		DATE dataPagamento;
		float total;
		char funcionario[50];
} PAGAMENTO;
