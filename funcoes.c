#include <stdio.h>
#include "estruturas.h"
#include "funcoes.h"

//Relacionado aos dados do cliente

void editarClientePorNome() {
    FILE *arquivo = fopen("CLIENTES.DAT", "rb+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo CLIENTES.DAT!\n");
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do cliente que deseja editar: ");
    getchar();
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Remove o '\n'

    CLIENTE cliente;
    int encontrado = 0;
    
    while (fread(&cliente, sizeof(CLIENTE), 1, arquivo)) {
        if (strcasecmp(cliente.nome, nomeBusca) == 0) {
            encontrado = 1;
            printf("\nCliente encontrado! Insira os novos dados:\n");

            printf("Novo nome: ");
            fgets(cliente.nome, sizeof(cliente.nome), stdin);
            cliente.nome[strcspn(cliente.nome, "\n")] = '\0';

            printf("Novo telefone: ");
            fgets(cliente.telefone, sizeof(cliente.telefone), stdin);
            cliente.telefone[strcspn(cliente.telefone, "\n")] = '\0';

            printf("Novo BI: ");
            fgets(cliente.bi, sizeof(cliente.bi), stdin);
            cliente.bi[strcspn(cliente.bi, "\n")] = '\0';

            printf("Nova nacionalidade: ");
            fgets(cliente.nacionalidade, sizeof(cliente.nacionalidade), stdin);
            cliente.nacionalidade[strcspn(cliente.nacionalidade, "\n")] = '\0';

            printf("Nova data de entrada (dd mm aaaa): ");
            scanf("%d %d %d", &cliente.dataEntrada.dia, &cliente.dataEntrada.mes, &cliente.dataEntrada.ano);
            getchar();

            // Retorna o ponteiro para reescrever no mesmo local
            fseek(arquivo, -sizeof(CLIENTE), SEEK_CUR);
            fwrite(&cliente, sizeof(CLIENTE), 1, arquivo);
            printf("\nCliente atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente '%s' não encontrado!\n", nomeBusca);
    }

    fclose(arquivo);
}

void eliminarClientePorNome() {
	
    FILE *arquivo = fopen("CLIENTES.DAT", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo CLIENTE.DAT!\n");
        return;
    }

    FILE *temp = fopen("TEMP.DAT", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do cliente para remover: ");
    getchar();
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    CLIENTE cliente;
    int encontrado = 0;
    
    while (fread(&cliente, sizeof(CLIENTE), 1, arquivo)) {
        if (strcasecmp(cliente.nome, nomeBusca) == 0) {
            encontrado = 1;
            printf("\nCliente '%s' removido com sucesso!\n", nomeBusca);
        } else {
            fwrite(&cliente, sizeof(CLIENTE), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (!encontrado) {
        printf("Nenhum cliente encontrado com o nome '%s'.\n", nomeBusca);
        remove("TEMP.DAT"); // Exclui o arquivo temporário se nada foi removido
    } else {
        remove("CLIENTES.DAT");  // Remove o original
        rename("TEMP.DAT", "CLIENTE.DAT"); // Renomeia o temporário
    }
}

void pedirDadosCliente(CLIENTE *cliente){
	
	system("cls");
	printf("\tEntrada de Dados para um Novo Cliente\n\n");
	
	printf("Id = %d\n", getNextClienteAutoID());
	
	cliente->id = getNextClienteAutoID();
	getchar();
	printf("Nome?\n");
	gets(cliente->nome);
	
	printf("Telefone?\n");
	gets(cliente->telefone);
	
	printf("BI?\n");
	gets(cliente->bi);
	
	printf("Nacionalidade?\n");
	gets(cliente->nacionalidade);
	
	printf("Data de Entrada [DD-MM-AAAA]?\n");
	scanf("%d%d%d", &cliente->dataEntrada.dia,
		&cliente->dataEntrada.mes, &cliente->dataEntrada.ano);
		
	printf("\nDados Inseridos:\n");
    printf("ID: %d\n", cliente->id);
    printf("Nome: %s\n", cliente->nome);
    printf("Telefone: %s\n", cliente->telefone);
    printf("BI: %s\n", cliente->bi);
    printf("Nacionalidade: %s\n", cliente->nacionalidade);
    printf("Data de Entrada: %d-%d-%d\n", cliente->dataEntrada.dia, cliente->dataEntrada.mes, cliente->dataEntrada.ano);

	puts("\n----------------------------\n");
	
}

void salvarDadosCliente()
{
	FILE *fp;
	CLIENTE cliente;
	
	if (fp = fopen("CLIENTES.DAT", "ab"))
	
	fseek(fp, 0L, SEEK_END);	

	pedirDadosCliente(&cliente);

	if ( fwrite(&cliente, sizeof(CLIENTE), 1, fp) == 1)	
		printf("Registo Salvo com sucesso!\n\n");
	else
		printf("Erro ao Tentar Salvar o Registo!\n");
	
	close(fp);
}

//Gerar Id automatico do cliente
int getNextClienteAutoID()
{
	FILE *fp;
	CLIENTE cliente;
	int nextID = 1;

	fp = fopen("CLIENTES.DAT", "rb");

	rewind(fp);
	
	while( fread(&cliente, sizeof(CLIENTE), 1, fp) == 1)
	{	
		nextID++;
	}
		
	fclose( fp );
	
	return nextID;
}

void mostrarDadosCliente(CLIENTE cliente)
{
	printf("Id: %d\n", cliente.id);
	
	printf("Nome: %s\n", cliente.nome);
		
	printf("BI: %s\n", cliente.bi);

	printf("Telefone: %s\n", cliente.telefone);
	
	printf("Nacionalidade: %s\n", cliente.nacionalidade);
	
	printf("Data de Entrada: [%d-%d-%d]\n", 
		cliente.dataEntrada.dia, 
		cliente.dataEntrada.mes, 
		cliente.dataEntrada.ano);	
	puts("---------------------------------------\n");

}

void listarDadosCliente()
{
	FILE *fp;
	CLIENTE cliente;
	
	//abrir ou criar o ficheiro 
	fp = fopen("CLIENTES.DAT", "rb");
	
	//movimentar o File Pointer
	fseek(fp, 0L, SEEK_SET);	//rewind(fp);	
	
	system("cls");
	
	puts("Listagem de Dados");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&cliente, sizeof(CLIENTE), 1, fp) == 1)
	{		
		puts("---------------------------------------");
		mostrarDadosCliente(cliente);		
	}
		
	fclose( fp );
}

void pesquisarClientePorNome()
{
	FILE *fp;
	CLIENTE cliente;
	char nomeProcurado[50];
	
	//abrir ou criar o ficheiro 
	fp = fopen("CLIENTES.DAT", "rb");
	
	//colocar o File Pointer no principio do ficheiro
	rewind(fp);
		
	puts("Digite o Nome Procurado");
	getchar();
	gets(nomeProcurado);
		
	//escrever os dados da estrutura para o ficheiro
	while( fread(&cliente, sizeof(CLIENTE), 1, fp) == 1)
	{	
		if ( strcmp(cliente.nome, nomeProcurado) == 0)
		{	
			system("cls");
						
			puts("Registo Localizado");
			puts("----------------------------");
			mostrarDadosCliente(cliente);
			
			fclose(fp);
			return;
		}
	}
	
	printf("Cliente %s nao Encontrado(a)!...\n", nomeProcurado);
		
	fclose( fp );
}

void pesquisarClientesPelaData() {
    FILE *fp;
    CLIENTE cliente;
    DATE dataProcurada;
    int encontrado = 0;

    // Abrir o ficheiro
    fp = fopen("CLIENTES.DAT", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo ou arquivo inexistente!\n");
        return;
    }

    // Solicitar a data ao usuï¿½rio
    printf("Digite a Data Procurada (dd/mm/aaaa): ");
    if (scanf("%d/%d/%d", &dataProcurada.dia, &dataProcurada.mes, &dataProcurada.ano) != 3) {
        printf("Erro: formato invï¿½lido!\n");
        fclose(fp);
        return;
    }

    getchar(); // Consumir a quebra de linha para evitar problemas na prï¿½xima leitura

    // Percorrer o arquivo buscando a data
    while (fread(&cliente, sizeof(CLIENTE), 1, fp) == 1) {    
        if (cliente.dataEntrada.dia == dataProcurada.dia && 
            cliente.dataEntrada.mes == dataProcurada.mes && 
            cliente.dataEntrada.ano == dataProcurada.ano) {    
            
            encontrado = 1;
            puts("\nRegisto Localizado:");
            puts("----------------------------");
            mostrarDadosCliente(cliente);
        }
    }

    // Se nenhum cliente foi encontrado
    if (!encontrado) {
        printf("\nNenhum cliente encontrado com a data %02d/%02d/%04d.\n", 
               dataProcurada.dia, dataProcurada.mes, dataProcurada.ano);
    }

    fclose(fp);
}

//Relacionado aos dados da Reserva
void pedirDadosReserva(RESERVA *reserva){
	
	system("cls");

	printf("\tEntrada de Dados para uma Nova Reserva\n\n");
	
	printf("Id = %d\n", getNextReservaAutoID());
	reserva->id = getNextReservaAutoID();
	getchar();
	printf("ID_Cliente?\n");
	scanf("%d", &reserva->idCliente);
	
	printf("Numero_Pessoas?\n");
	scanf("%d", &reserva->numPessoas);
	getchar();
	printf("Horario?\n");
	gets(reserva->horario);
	
	printf("Nome_Do_Funcionario?\n");
	gets(reserva->funcionario);
	
	printf("Data de Entrada [DD-MM-AAAA]?\n");
	scanf("%d%d%d", &reserva->dataReserva.dia,
		&reserva->dataReserva.mes, &reserva->dataReserva.ano);
		
	printf("\nDados Inseridos:\n");
    printf("ID: %d\n", reserva->id);
    printf("ID_Cliente: %d\n", reserva->idCliente);
    printf("Numero_De_Pessoas: %d\n", reserva->numPessoas);
    printf("Horario: %s\n", reserva->horario);
    printf("Nome_Do_Funcionario: %c\n", reserva->funcionario);
    printf("Data de Entrada: %02d-%02d-%04d\n", reserva->dataReserva.dia, reserva->dataReserva.mes, reserva->dataReserva.ano);
}

void salvarDadosReserva()
{	
	FILE *fp;
	RESERVA reserva;
	
	if (fp = fopen("RESERVAS.DAT", "ab"))
	
	fseek(fp, 0L, SEEK_END);	

	pedirDadosReserva(&reserva);

	if ( fwrite(&reserva, sizeof(RESERVA), 1, fp) == 1)	
		printf("Registo Salvo com sucesso!\n");
	else
		printf("Erro ao Tentar Salvar o Registo!\n");
	
	close(fp);
}

int getNextReservaAutoID()
{
	FILE *fp;
	RESERVA reserva;
	int nextID = 1;

	fp = fopen("RESERVAS.DAT", "rb");

	rewind(fp);
	
	while( fread(&reserva, sizeof(RESERVA), 1, fp) == 1)
	{	
		nextID++;
	}
	fclose( fp );
	
	return nextID;
}

void mostrarDadosReserva(RESERVA reserva)
{
	printf("Id: %d\n", reserva.id);
	
	printf("Id_Cliente: %d\n", reserva.idCliente);
		
	printf("Horario: %s\n", reserva.horario);

	printf("Numero_De_Pessoas: %d\n", reserva.numPessoas);
	
	printf("Nome_Funcionario: %s\n", reserva.funcionario);
	
	printf("Data de Reserva: [%d-%d-%d]\n", 
		reserva.dataReserva.dia, 
		reserva.dataReserva.mes, 
		reserva.dataReserva.ano);	
puts("\n---------------------------------------\n");
}

void listarDadosReserva()
{
	FILE *fp;
	RESERVA reserva;
	
	//abrir ou criar o ficheiro 
	fp = fopen("RESERVAS.DAT", "rb");
	
	//movimentar o File Pointer
	fseek(fp, 0L, SEEK_SET);	//rewind(fp);	
	
	system("cls");
	
	puts("Listagem de Dados");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&reserva, sizeof(RESERVA), 1, fp) == 1)
	{		
		puts("---------------------------------------");
		mostrarDadosReserva(reserva);		
	}
		
	fclose( fp );
}

void pesquisarReservasPelaData() {
    FILE *fp;
    RESERVA reserva;
    DATE dataProcurada;
    int encontrado = 0;

    // Abrir o arquivo
    fp = fopen("RESERVAS.DAT", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo ou arquivo inexistente!\n");
        return;
    }

    // Solicitar a data ao usuï¿½rio
    printf("Digite a Data da Reserva Procurada (dd/mm/aaaa): ");
    if (scanf("%d/%d/%d", &dataProcurada.dia, &dataProcurada.mes, &dataProcurada.ano) != 3) {
        printf("Erro: formato invï¿½lido!\n");
        fclose(fp);
        return;
    }

    getchar(); // Consumir a quebra de linha para evitar problemas na prï¿½xima leitura

    // Percorrer o arquivo buscando reservas na data informada
    while (fread(&reserva, sizeof(RESERVA), 1, fp) == 1) {    
        if (reserva.dataReserva.dia == dataProcurada.dia && 
            reserva.dataReserva.mes == dataProcurada.mes && 
            reserva.dataReserva.ano == dataProcurada.ano) {    

            encontrado = 1;
            puts("\nReserva Localizada:");
            puts("----------------------------");
            mostrarDadosReserva(reserva);
        }
    }

    // Se nenhuma reserva foi encontrada
    if (!encontrado) {
        printf("\nNenhuma reserva encontrada para a data %02d/%02d/%04d.\n", 
               dataProcurada.dia, dataProcurada.mes, dataProcurada.ano);
    }

    fclose(fp);
}

void editarReserva() {
    FILE *arquivo = fopen("RESERVAS.DAT", "rb+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo RESERVAS.DAT!\n");
        return;
    }

    int idClienteBusca;
    printf("Digite o ID do cliente da reserva que deseja editar: ");
    scanf("%d", &idClienteBusca);

    RESERVA reserva;
    int encontrado = 0;

    while (fread(&reserva, sizeof(RESERVA), 1, arquivo)) {
        if (reserva.idCliente == idClienteBusca) {
            encontrado = 1;
            printf("\nReserva encontrada! Insira os novos dados:\n");

            printf("Novo número de pessoas: ");
            scanf("%d", &reserva.numPessoas);

            printf("Novo horário (hh:mm): ");
            scanf("%s", reserva.horario);

            printf("Novo funcionário responsável: ");
            getchar(); // Limpa buffer
            fgets(reserva.funcionario, sizeof(reserva.funcionario), stdin);
            reserva.funcionario[strcspn(reserva.funcionario, "\n")] = '\0'; // Remove o '\n'

            // Retorna o ponteiro para reescrever no mesmo local
            fseek(arquivo, -sizeof(RESERVA), SEEK_CUR);
            fwrite(&reserva, sizeof(RESERVA), 1, arquivo);

            printf("\nReserva atualizada com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Reserva para o cliente %d não encontrada!\n", idClienteBusca);
    }

    fclose(arquivo);
}

void eliminarReserva() {
	
    FILE *arquivo = fopen("RESERVAS.DAT", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo RESERVAS.DAT!\n");
        return;
    }

    FILE *tempArquivo = fopen("TEMP.DAT", "wb");
    if (!tempArquivo) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    int idClienteBusca;
    printf("Digite o ID do cliente da reserva que deseja eliminar: ");
    scanf("%d", &idClienteBusca);

    RESERVA reserva;
    int encontrado = 0;

    while (fread(&reserva, sizeof(RESERVA), 1, arquivo)) {
        if (reserva.idCliente == idClienteBusca) {
            encontrado = 1;
            printf("\nReserva para o cliente %d eliminada com sucesso!\n", idClienteBusca);
        } else {
            fwrite(&reserva, sizeof(RESERVA), 1, tempArquivo);
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);

    if (encontrado) {
        remove("RESERVAS.DAT");
        rename("TEMP.DAT", "RESERVAS.DAT");
    } else {
        printf("Reserva para o cliente %d não encontrada!\n", idClienteBusca);
        remove("TEMP.DAT");
    }
}


//Relacionado a Vendas
void pedirDadosVenda(VENDA *venda) {  
	
	system("cls");

	printf("\tEntrada de Dados para uma Nova Reserva\n\n");
	
	printf("Id = %d\n", getNextVendaAutoID());
	venda->id= getNextVendaAutoID();
	getchar();
	printf("ID_Cliente?\n");
	scanf("%d", &venda->id_cliente);

	printf("ID_Produto?\n");
	scanf("%d", &venda->id_produto);
	getchar();
	
	printf("Quantidade?\n");
	scanf("%d", &venda->quantidade);
	getchar();
	printf("Forma_De_Pagamento?\n");
	gets(venda->forma_pagamento);
	
	printf("Nome_Funcionario?\n");
	gets(venda->funcionario);
	
	printf("Valor_total?\n");
	scanf("%d", &venda->valor_total);
	
	printf("Data de Venda [DD-MM-AAAA]?\n");
	scanf("%d%d%d", &venda->data_venda.dia,
		&venda->data_venda.mes, &venda->data_venda.ano);
}

int getNextVendaAutoID()
{
	FILE *fp;
	VENDA venda;
	int nextID = 1;

	fp = fopen("VENDAS.DAT", "rb");

	rewind(fp);
	
	while( fread(&venda, sizeof(VENDA), 1, fp) == 1)
	{	
		nextID++;
	}
	fclose( fp );
	
	return nextID;
}


void pesquisarVendaPelaData() {
    FILE *fp;
    VENDA venda;
    DATE dataProcurada;
    int encontrado = 0;

    // Abrir o ficheiro
    fp = fopen("VENDAS.DAT", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo ou arquivo inexistente!\n");
        return;
    }

    // Solicitar a data ao usuï¿½rio
    printf("Digite a Data Procurada (dd/mm/aaaa): ");
    if (scanf("%d/%d/%d", &dataProcurada.dia, &dataProcurada.mes, &dataProcurada.ano) != 3) {
        printf("Erro: formato invï¿½lido!\n");
        fclose(fp);
        return;
    }

    getchar(); // Consumir a quebra de linha para evitar problemas na prï¿½xima leitura

    // Percorrer o arquivo buscando a data
    while (fread(&venda, sizeof(VENDA), 1, fp) == 1) {    
        if (venda.data_venda.dia == dataProcurada.dia && 
            venda.data_venda.mes == dataProcurada.mes && 
            venda.data_venda.ano == dataProcurada.ano) {    
            
            encontrado = 1;
            puts("\nRegisto Localizado:");
            puts("----------------------------");
            mostrarDadosVenda(venda);
        }
    }

    // Se nenhum cliente foi encontrado
    if (!encontrado) {
        printf("\nNenhuma venda encontrada com a data %02d/%02d/%04d.\n", 
               dataProcurada.dia, dataProcurada.mes, dataProcurada.ano);
    }

    fclose(fp);
}

void salvarDadosVenda()
{	
	FILE *fp;
	VENDA venda;
	
	if (fp = fopen("VENDAS.DAT", "ab"))
	
	fseek(fp, 0L, SEEK_END);	

	pedirDadosVenda(&venda);

	if ( fwrite(&venda, sizeof(VENDA), 1, fp) == 1)	
		printf("Registo Salvo com sucesso!\n");
	else
		printf("Erro ao Tentar Salvar o Registo!\n");
	
	close(fp);
}

void listarDadosVendas()
{
	FILE *fp;
	VENDA venda;
	
	//abrir ou criar o ficheiro 
	fp = fopen("VENDAS.DAT", "rb");
	
	//movimentar o File Pointer
	fseek(fp, 0L, SEEK_SET);	//rewind(fp);	
	
	system("cls");
	
	puts("Listagem de Dados");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&venda, sizeof(VENDA), 1, fp) == 1)
	{		
		puts("---------------------------------------");
		 mostrarDadosVenda(venda);		
	}
		
	fclose( fp );
}

void mostrarDadosVenda(VENDA venda)
{
	printf("Id: %d\n", venda.id);
	
	printf("Id_Cliente: %d\n", venda.id_cliente);
		
	printf("Id_Produto: %d\n", venda.id_cliente);
	
	printf("Quantidade: %d\n", venda.quantidade);

	printf("Valor_Total: %f\n", venda.valor_total);
	
	printf("Forma_Pagamento: %s\n", venda.forma_pagamento);
	
	printf("Nome_Funcionario: %s\n", venda.funcionario);
	
	printf("Data de Venda: [%d-%d-%d]\n", 
		venda.data_venda.dia, 
		venda.data_venda.mes, 
		venda.data_venda.ano);	
puts("---------------------------------------");
}

//Relacionado ao Produto

void mostrarDadosProduto(PRODUTO produto)
{
	printf("Id: %d\n", produto.id);
	
	printf("Nome_Produto: %s\n", produto.nome_produto);
		
	printf("Preco: %d\n", produto.preco);

}

void listarDadosProdutos()
{
	FILE *fp;
	PRODUTO produto;
	
	//abrir ou criar o ficheiro 
	fp = fopen("PRODUTOS.DAT", "rb");
	
	//movimentar o File Pointer
	fseek(fp, 0L, SEEK_SET);	//rewind(fp);	
	
	system("cls");
	
	puts("Listagem de Dados");
	
	//escrever os dados da estrutura para o ficheiro
	while( fread(&produto, sizeof(PRODUTO), 1, fp) == 1)
	{		
		puts("---------------------------------------");
		 mostrarDadosProduto(produto);		
	}
		
	fclose( fp );
}

void salvarDadosProduto()
{	
	FILE *fp;
	PRODUTO produto;
	
	if (fp = fopen("PRODUTOS.DAT", "ab"))
	
	fseek(fp, 0L, SEEK_END);	

	pedirDadosProduto(&produto);

	if ( fwrite(&produto, sizeof(PRODUTO), 1, fp) == 1)	
		printf("Registo Salvo com sucesso!\n");
	else
		printf("Erro ao Tentar Salvar o Registo!\n");
	
	close(fp);
}

void pedirDadosProduto(PRODUTO *produto){  
	
	system("cls");

	printf("\tEntrada de Dados para uma Nova Reserva\n\n");
	
	printf("ID = %d\n", getNextProdutoAutoID());
	produto->id= getNextProdutoAutoID();
	getchar();
	printf("Nome_Produto?\n");
	scanf("%s", &produto->preco);
	
	printf("Preco?\n");
	scanf("%f", &produto->preco);
	getchar();
	
}

int getNextProdutoAutoID()
{
	FILE *fp;
	PRODUTO produto;
	int nextID = 1;

	fp = fopen("PRODUTOS.DAT", "rb");

	rewind(fp);
	
	while( fread(&produto, sizeof(PRODUTO), 1, fp) == 1)
	{	
		nextID++;
	}
	fclose( fp );
	
	return nextID;
}

void pesquisarProdutoPeloNome()
{
	FILE *fp;
	PRODUTO produto;
	char nomeProcurado[50];
	
	//abrir ou criar o ficheiro 
	fp = fopen("PRODUTOS.DAT", "rb");
	
	//colocar o File Pointer no principio do ficheiro
	rewind(fp);
		
	puts("Digite o Nome Procurado");
	getchar();
	gets(nomeProcurado);
		
	//escrever os dados da estrutura para o ficheiro
	while( fread(&produto, sizeof(PRODUTO), 1, fp) == 1)
	{	
		if ( strcmp(produto.nome_produto, nomeProcurado) == 0)
		{	
			system("cls");
						
			puts("Registo Localizado");
			puts("----------------------------");
			mostrarDadosProduto(produto);
			
			fclose(fp);
			return;
		}
	}
	
	printf("%s nao Encontrado(a)!...\n", nomeProcurado);
		
	fclose( fp );
}

void editarProdutoPorNome() {
    FILE *arquivo = fopen("PRODUTOS.DAT", "rb+");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo PRODUTOS.DAT!\n");
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do produto que deseja editar: ");
    getchar();
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0'; // Remove o '\n'

    PRODUTO produto;
    int encontrado = 0;
    
    while (fread(&produto, sizeof(PRODUTO), 1, arquivo)) {
        if (strcasecmp(produto.nome_produto, nomeBusca) == 0) {
            encontrado = 1;
            printf("\nProduto encontrado! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            fgets(produto.nome_produto, sizeof(produto.nome_produto), stdin);
            produto.nome_produto[strcspn(produto.nome_produto, "\n")] = '\0';

            printf("Novo preço: ");
            scanf("%f", &produto.preco);
            getchar();

            // Retorna o ponteiro para reescrever no mesmo local
            fseek(arquivo, -sizeof(PRODUTO), SEEK_CUR);
            fwrite(&produto, sizeof(PRODUTO), 1, arquivo);
            printf("\nProduto atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Produto '%s' não encontrado!\n", nomeBusca);
    }

    fclose(arquivo);
}

void eliminarProdutoPorNome() {
	
    FILE *arquivo = fopen("PRODUTOS.DAT", "rb");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo PRODUTOS.DAT!\n");
        return;
    }

    FILE *temp = fopen("TEMP.DAT", "wb");
    if (!temp) {
        printf("Erro ao criar arquivo temporário!\n");
        fclose(arquivo);
        return;
    }

    char nomeBusca[50];
    printf("Digite o nome do produto para remover: ");
    getchar();
    fgets(nomeBusca, sizeof(nomeBusca), stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    PRODUTO produto;
    int encontrado = 0;
    
    while (fread(&produto, sizeof(PRODUTO), 1, arquivo)) {
        if (strcasecmp(produto.nome_produto, nomeBusca) == 0) {
            encontrado = 1;
            printf("\nProduto '%s' removido com sucesso!\n", nomeBusca);
        } else {
            fwrite(&produto, sizeof(PRODUTO), 1, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (!encontrado) {
        printf("Nenhum produto encontrado com o nome '%s'.\n", nomeBusca);
        remove("TEMP.DAT"); // Exclui o arquivo temporário se nada foi removido
    } else {
        remove("PRODUTOS.DAT");  // Remove o original
        rename("TEMP.DAT", "PRODUTOS.DAT"); // Renomeia o temporário
    }
}
