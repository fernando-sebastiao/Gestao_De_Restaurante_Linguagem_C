#include  "estruturas.h"

//Clientes
void pedirDadosCliente(CLIENTE *cliente);
void salvarDadosCliente();
void mostrarDadosCliente(CLIENTE cliente);
void listarDadosCliente();
void pesquisarClientePorNome();
void pesquisarClientesPelaData();
void eliminarClientePorNome();
void editarClientePorNome();

//Reservas
void pedirDadosReserva(RESERVA *reserva);
void salvarDadosReserva();
void mostrarDadosReserva(RESERVA reserva);
void listarDadosReserva();
void pesquisarReservasPelaData();
void editarReserva();
void eliminarReserva();
//Gerar Id automatico
int getNextClienteAutoID();

//Vendas
int getNextVendaAutoID();
void pedirDadosVenda(VENDA *venda);
void salvarDadosVenda();
void listarDadosVendas();
void mostrarDadosVenda(VENDA venda);
void pesquisarVendaPelaData();

//Produto
void pedirDadosProduto(PRODUTO *produto);
void salvarDadosProduto();
void listarDadosProdutos();
void mostrarDadosProduto(PRODUTO produto);
int getNextProdutoAutoID();
void eliminarProdutoPorNome();
void editarProdutoPorNome();
void pesquisarProdutoPeloNome();
