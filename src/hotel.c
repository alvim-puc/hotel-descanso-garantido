#include "hotel.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

t_hotel inicializaHotel() {
    t_hotel hotel;
    char * path = "./files/hotel.dat";

    FILE *f = fopen(path, "r+b");
    if(f){
        fread(&hotel, sizeof(t_hotel), 1, f);
    } else {
        f = fopen(path, "wb");
        if(!f){
            printf("Erro: Não foi possível criar o arquivo!\n");
            return inicializaHotel();
        }
        strcpy(hotel.nome, "Hotel Descanso Garantido");
        strcpy(hotel.endereco, "Itacaé, Bahia");
        strcpy(hotel.ceos[0], "Bernardo Alvim");
        strcpy(hotel.ceos[1], "Bruna Markowisk");
        strcpy(hotel.ceos[2], "Matheus Gaston");
        hotel.quartos = (quarto*) malloc(sizeof(quarto) * 0);
        hotel.estadias = (estadia*) malloc(sizeof(estadia) * 0);
        hotel.funcionarios = (funcionario*) malloc(sizeof(funcionario) * 0);
        hotel.clientes = (cliente*) malloc(sizeof(cliente) * 0);
        fwrite(&hotel, sizeof(t_hotel), 1, f);
    }
    
    fclose(f);
    return hotel;
}

void atualizaHotel(t_hotel *hotel) {
    FILE *f = fopen("./files/hotel.dat", "wb");
    if (!f) return;

    fwrite(hotel, sizeof(t_hotel), 1, f);

    fclose(f);
}

void fechaHotel(t_hotel *hotel){
    free(hotel->clientes);
    free(hotel->funcionarios);
    free(hotel->estadias);
    free(hotel->quartos);
}

void cadastrarCliente(t_hotel *hotel) {
    char nome[TAM_MAX_NAME], endereco[TAM_MAX_ADDR], telefone[TAM_MAX_CELL], *path = "./files/c.txt";
    int qtd_clientes = 0;

    printf("------------------------------------------------------------\n");
    printf(" Este é o Cadastro de Clientes do %s\n", hotel->nome);
    printf(" Insira os valores solicitados para fazer seu cadastro\n");
    printf("------------------------------------------------------------\n");

    printf("\nNome do cliente: ");
    fgets(nome, TAM_MAX_NAME, stdin);
    nome[strcspn(nome, "\n")] = 0; // remove o \n do final da string

    printf("\nEndereço do cliente: ");
    fgets(endereco, TAM_MAX_ADDR, stdin);
    endereco[strcspn(endereco, "\n")] = 0; // remove o \n do final da string

    printf("\nTelefone do cliente: ");
    fgets(telefone, TAM_MAX_CELL, stdin);
    telefone[strcspn(telefone, "\n")] = 0; // remove o \n do final da string

    FILE *f = fopen(path, "r+");
    if (!f) {
        f = fopen(path, "w");
        if (!f) {
            printf("Erro: Arquivo não pode ser criado.\n");
            return;
        }
    } else {
        fscanf(f, "%d", &qtd_clientes);
    }

    qtd_clientes += 1;

    printf("Quantidade de clientes: %d\n", qtd_clientes);

    hotel->clientes = (cliente*) realloc(hotel->clientes, sizeof(cliente) * qtd_clientes);

    cliente *cliente = &hotel->clientes[qtd_clientes - 1];

    cliente->cod = qtd_clientes;
    cliente->pontos = 0;
    strcpy(cliente->nome, nome);
    strcpy(cliente->endereco, endereco);
    strcpy(cliente->telefone, telefone);

    fseek(f, 0, SEEK_SET); // move para o início do arquivo para escrever
    fprintf(f, "%d", qtd_clientes);
    fclose(f);

    atualizaHotel(hotel);

    printf("Cliente cadastrado com sucesso!\n");
}

void cadastrarFuncionario(t_hotel *hotel) {}
void cadastrarQuarto(t_hotel *hotel) {}
void cadastrarEstadia(t_hotel *hotel) {}
void concluirEstadia(t_hotel *hotel) {}
void mostrarEstadias(t_hotel *hotel) {}

void pesquisar(t_hotel *hotel) {
    printf("------------------------------------------------------------\n");
    printf(" Este é o Centro de Pesquisa do %s\n", hotel->nome);
    printf(" Insira um codigo de Cliente/Funcionario para pesquisar\n");
    printf("------------------------------------------------------------\n");

    int cod, escolha;

    printf("1. Cliente \n2. Funcionario \nEscolha: ");
    scanf("%d", &escolha);
    switch (escolha) {
        case 1:
            printf("Digite o codigo do cliente: ");
            scanf("%d", &cod);

            FILE *f = fopen("./files/c.txt", "r");
            if (!f) return;

            int qtd_clientes = 0;
            fscanf(f, "%d", &qtd_clientes);
            fclose(f);

            cliente *cliente;
            bool found = false;
            for (int i = 0; i < qtd_clientes; i++) {
                if (cod == hotel->clientes[i].cod) {
                    cliente = &hotel->clientes[i];
                    found = true;
                    break;
                }
            }
            if (!found) {
                printf("Cliente não encontrado\n");
                return;
            }

            printf("\n");
            printf("Nome: %s\n", cliente->nome);
            printf("Endereço: %s\n", cliente->endereco);
            printf("Telefone: %s\n", cliente->telefone);
            printf("Pontos: %d\n", cliente->pontos);
            printf("\n");
            break;
        case 2:
            printf("Digite o codigo do funcionario: ");
            scanf("%d", &cod);
            break;
        default:
            break;
    }
}
