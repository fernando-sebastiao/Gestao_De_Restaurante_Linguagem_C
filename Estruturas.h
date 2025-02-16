#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H


typedef struct
{
    int dia, mes, ano;
} DATE; 


typedef struct
{
    int id;
    char nome[50], telefone[15], bi[15], nacionalidade[20], genero[10];
    DATE dataEntrada; 
} CLIENTE;


typedef struct 
{
    int id, idCliente, numPessoas;
    char horario[10], funcionario[50];
    DATE dataReserva; 
} RESERVA;

typedef struct
{
	int id; 
	char nome_produto[50]; 
	float preco;
}PRODUTO;


typedef struct
{
	int id, id_cliente, id_produto, quantidade;
	char forma_pagamento[20], funcionario[50];
	DATE data_venda;
	float valor_total;
}VENDA;

#endif

