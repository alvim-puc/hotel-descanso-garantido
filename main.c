#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX_ADDR 60
#define TAM_MAX_NAME 50
#define TAM_MAX_ROLE 30
#define TAM_MAX_CELL 25
#define TAM_DATE 8
#define SUCCESS 0

typedef struct {
  int cod;
  int pontos;
  char nome[TAM_MAX_NAME];
  char endereco[TAM_MAX_ADDR];
  char telefone[TAM_MAX_CELL];
} cliente;

typedef struct {
  int cod;
  double salario;
  char nome[TAM_MAX_NAME];
  char cargo[TAM_MAX_ROLE];
  char telefone[TAM_MAX_CELL];
} funcionario;

typedef struct {
  int num;
  int hospedes;
  double diaria;
  bool status;
} quarto;

typedef struct {
  int cod;
  int num_quarto;
  int cod_cliente;
  int diarias;
  char entrada[TAM_DATE];
  char saida[TAM_DATE];
} estadia;

struct s_hotel {
  char endereco[TAM_MAX_ADDR];
  char nome[TAM_MAX_NAME];
  char ceos[3][TAM_MAX_NAME];
  funcionario * funcionarios;
  estadia * estadias;
  cliente * clientes;
  quarto * quartos;
} typedef t_hotel;

int menu();
void clr();
void pesquisar(t_hotel * hotel);
void cadastrarQuarto(t_hotel * hotel);
void mostrarEstadias(t_hotel * hotel);
void concluirEstadia(t_hotel * hotel);
void cadastrarEstadia(t_hotel * hotel);
void cadastrarCliente(t_hotel * hotel);
void cadastrarFuncionario(t_hotel * hotel);
t_hotel inicializaHotel();

int main(int argc, char ** agrv){
  setlocale(LC_ALL, "");

  t_hotel hotel = inicializaHotel();
  printf("\n------------------------------------------------\n");
  printf("Bem vind@ ao %s\nOnde voce é prioridade para nós\n", hotel.nome);
  printf("%s", hotel.endereco);
  printf("\n------------------------------------------------\n");

  int choice;
  do{
    choice = menu();
    clr();
    switch(choice) {
      case 1:
        inserirCliente(hotel);
        break;
    }
  } while(choice != 0);

  return SUCCESS;
}

int menu(){
  int choice;

  printf("1. Cadastrar um Cliente\n");
  printf("2. Cadastrar um Funcionario\n");
  printf("3. Cadastrar um Quarto\n");
  printf("4. Cadastrar uma Estadia\n");
  printf("5. Dar baixa em uma Estadia\n");
  printf("6. Pesquisar\n");
  printf("7. Mostrar estadias\n");
  printf("8. Calcular fidelidade\n");
  printf("0. Exit\n");
  printf("Escolha: ");
  scanf("%d", &choice);

  return choice;
}

void clr(){
  #ifdef __unix__
    system("clear");
  #else 
    system("cls");
  #endif
}

t_hotel inicializaHotel(){
  t_hotel hotel;
  strcpy(hotel.nome, "Hotel Descanso Garantido");
  strcpy(hotel.endereco, "Itacaé, Bahia");
  strcpy(hotel.ceos[0], "Bernardo Alvim");
  strcpy(hotel.ceos[1], "Bruna Markowisk");
  strcpy(hotel.ceos[2], "Matheus Gaston");
  hotel.quartos = (quarto*) malloc(sizeof(quarto) * 0);
  hotel.estadias = (estadia*) malloc(sizeof(estadia) * 0);
  hotel.funcionarios = (funcionario*) malloc(sizeof(funcionario) * 0);
  hotel.clientes = (cliente*) malloc(sizeof(cliente) * 0);

  return hotel;
}

void cadastrarCliente(t_hotel * hotel){
  int cod, pontos, qtd_clientes = 0;
  char nome[TAM_MAX_NAME], endereco[TAM_MAX_ADDR], telefone[TAM_MAX_CELL];

  printf("-----------------------------------------------------\n");
  printf("Este é o Cadastro de Clientes do %s\n", hotel.nome);
  printf("Insira os valores solicitados para fazer seu cadastro\n");
  printf("-----------------------------------------------------\n");

  printf("\nNome do cliente: ");
  fgets(name, TAM_MAX_NAME, stdin);
  printf("\nEndereço do cliente: ");
  fgets(endereco, TAM_MAX_ADDR, stdin);
  printf("\nTelefone do cliente: ");
  fgets(telefone, TAM_MAX_CELL, stdin);
  
  FILE * f = fopen("/files/c.txt", "w+");
  if(!f) return

  fscanf(f, "%d", &qtd_clientes);
  qtd_clientes++;
  hotel.clientes = (cliente*) realloc(hotel.clientes, sizeof(cliente) * qtd_clientes);
  
  cliente * cliente = hotel.cliente[qtd_clientes-1];

  cliente->cod = qtd_clientes;
  cliente->pontos = 0;
  strcpy(cliente->nome, nome);
  strcpy(cliente->endereco, endereco);
  strcpy(cliente->telefone, telefone);

  fprintf(f, "%d", qtd_clientes);
  fclose(f);

}