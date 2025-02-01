#include  "estruturas.h"

//Clientes
void pedirDadosCliente(CLIENTE *cliente);
void salvarDadosCliente();
void mostrarDadosCliente(CLIENTE cliente);
void listarDadosCliente();
void pesquisarClientePorNome();
void pesquisarClientesPelaData();

//Reservas
void pedirDadosReserva(RESERVA *reserva);
void salvarDadosReserva();
void mostrarDadosReserva(RESERVA reserva);
void listarDadosReserva();

//Gerar Id automatico
int getNextClienteAutoID();

//Vendas
int getNextVendaAutoID();
void pedirDadosVenda(VENDA *venda);
void salvarDadosVenda();
void listarDadosVendas();
void mostrarDadosVenda(VENDA venda);

//Produto
void pedirDadosProduto(PRODUTO *produto);
void salvarDadosProduto();
void listarDadosProdutos();
void mostrarDadosProduto(PRODUTO produto);
int getNextProdutoAutoID();
void pesquisarProdutoPeloNome();
