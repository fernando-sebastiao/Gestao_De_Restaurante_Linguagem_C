#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

// Definição de DATE
typedef struct
{
    int dia, mes, ano;
} DATE; // Nome mantido como DATE

// Estrutura de cliente
typedef struct
{
    int id;
    char nome[50], telefone[15], 
         email[50], bi[15], nacionalidade[20];
    DATE dataEntrada; // Mantido como DATE
} CLIENTE;

// Estrutura de reserva
typedef struct 
{
    int id, idCliente, numPessoas;
    DATE dataReserva; // Mantido como DATE
    char horario[10], funcionario[50];
} RESERVA;

// Estrutura de prato
typedef struct 
{
    int id;
    char nome[50];
    float preco;
    DATE dataCriacao; // Mantido como DATE
} PRATO;

// Estrutura de pedido
typedef struct
{
    int id, idReserva, idPrato, quantidade;
    float precoTotal;
    char funcionario[50];
    DATE dataPedido; // Mantido como DATE
} PEDIDO;

// Estrutura de pagamento
typedef struct
{
    int id, idPedido;
    DATE dataPagamento; // Mantido como DATE
    float total;
    char funcionario[50];
} PAGAMENTO;

#endif

