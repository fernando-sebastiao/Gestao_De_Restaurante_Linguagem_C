#include <stdio.h>
#include "estruturas.h"
#include "funcoes.h"

void pedirDadosCliente(CLIENTE *cliente){
	
	system("cls");

	printf("\tEntrada de Dados para um Novo Cliente\n\n");
	
	printf("ID?\n");
	scanf("%d", &cliente->id);
	getchar();
	printf("Nome?\n");
	gets(cliente->nome);
	
	printf("Telefone?\n");
	gets(cliente->telefone);
	
	printf("Email?\n");
	gets(cliente->email);
	
	printf("BI?\n");
	gets(cliente->bi);
	
	printf("Nacionalidade?\n");
	gets(cliente->nacionalidade);
	
	printf("Data de Entrada [DD-MM-AAAA]?\n");
	scanf("%d/%d/%d", &cliente->dataEntrada.dia,
		&cliente->dataEntrada.mes, &cliente->dataEntrada.ano);
		
	printf("\nDados Inseridos:\n");
    printf("ID: %d\n", cliente->id);
    printf("Nome: %s\n", cliente->nome);
    printf("Telefone: %s\n", cliente->telefone);
    printf("Email: %s\n", cliente->email);
    printf("BI: %s\n", cliente->bi);
    printf("Nacionalidade: %s\n", cliente->nacionalidade);
    printf("Data de Entrada: %02d-%02d-%04d\n", cliente->dataEntrada.dia, cliente->dataEntrada.mes, cliente->dataEntrada.ano);
	
}

void salvarDadosCliente()
{
	FILE *fp;
	CLIENTE cliente;;
	
	if (fp = fopen("Cliente.DAT", "ab"))
	
	fseek(fp, 0L, SEEK_END);	

	pedirDadosCliente(&cliente);

	if ( fwrite(&cliente, sizeof(CLIENTE), 1, fp) == 1)	
		printf("Registo Salvo com sucesso!\n");
	else
		printf("Erro ao Tentar Salvar o Registo!\n");
	
	close(fp);
}
