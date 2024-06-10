// hotel.h

#ifndef HOTEL_H
#define HOTEL_H

#include <stdbool.h>

#define TAM_MAX_ADDR 60
#define TAM_MAX_NAME 50
#define TAM_MAX_ROLE 30
#define TAM_MAX_CELL 25
#define TAM_DATE 8

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

typedef struct {
    char endereco[TAM_MAX_ADDR];
    char nome[TAM_MAX_NAME];
    char ceos[3][TAM_MAX_NAME];
    funcionario *funcionarios;
    estadia *estadias;
    cliente *clientes;
    quarto *quartos;
} t_hotel;

t_hotel inicializaHotel();
void atualizaHotel(t_hotel *hotel);
void cadastrarCliente(t_hotel *hotel);
void cadastrarFuncionario(t_hotel *hotel);
void cadastrarQuarto(t_hotel *hotel);
void cadastrarEstadia(t_hotel *hotel);
void concluirEstadia(t_hotel *hotel);
void mostrarEstadias(t_hotel *hotel);
void pesquisar(t_hotel *hotel);

#endif // HOTEL_H
