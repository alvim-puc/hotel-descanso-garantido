# Hotel Descanso Garantido

Visando resolver a desorganização de cadastros e reservas, [nós](#coders) desenvolvemos um programa que soluciona os problemas apontados por nosso cliente o [Hotel Descanso Garantido](#hotel-descanso-garantido).

## Coders
- Bernardo Alvim
- Bruna Markowisk
- Matheus Gaston

## Ferramentas

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)


## Estrutura do Projeto

```plaintext
hotel-descanso-garantido/
├── data/
│   └── (arquivos de gravação das informações contidas nas classes)
├── libs/
│   └── (bibliotecas de funções e classes do programa)
└── main.cpp 
```

## Backlog

| ID | Requisitos 
|----|----------------------------------------------------
| 01 | O sistema deve ter a função de cadastrar um cliente
| 02 | O sistema deve ter a função de cadastrar um funcionário
| 03 | O sistema deve ter a função de cadastrar um quarto
| 04 | O sistema deve ter a função de cadastrar uma estadia
| 05 | O sistema deve ter a funão de dar baixa em uma estadia
| 06 | O sistema deve calcular os pontos de fidelidade de um cliente após a baixa de sua estadia
| 07 | O sistema deve possibilitar a pesquisa de clientes e de funcionários

<table>
  <tr>
    <th>Sprint</th>
    <th>Início</th>
    <th>Término</th>
    <th>Backlog</th>
    <th>Responsáveis</th>
  </tr>
  <tr>
    <td>1</td>
    <td>12/06</td>
    <td>17/06</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li>RF 01</li>
        <li>RF 02</li>
        <li>RF 07</li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li>Bernardo</li>
        <li>Bruna</li>
        <li>Bernardo e Bruna</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>2</td>
    <td>18/06</td>
    <td>22/06</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li>RF 03</li>
        <li>RF 04</li>
        <li>RF 05</li>
        <li>RF 06</li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li>Bruna</li>
        <li>Bernardo e Bruna</li>
        <li>Bruna e Matheus</li>
        <li>Matheus</li>
      </ul>
    </td>
  </tr>
  <tr>
    <td>3</td>
    <td>22/06</td>
    <td>23/06</td>
    <td>Testes</td>
    <td>Matheus</td>
  </tr>
</table>


## Instalação

Clone este repositório

Certifique-se de ter o **compilador de C++** instalado.

Para instalá-los nos sistemas Debian, insira o seguinte comando:  
```bash
sudp apt update
sudo apt-get install g++
```
No Fedora e cia, estes:
```bash
sudo dnf update
sudo dnf install gcc-c++
```
No Arch ☠️:
```bash
sudo pacman -Syu
sudo pacman -S gcc
```
Já no Windows, é necessário seguir este [tutorial](https://www.youtube.com/watch?v=1Uw9EV4Te8M) para instalar o compilador.

Pronto, agora você possui todas as ferramentas necessárias para usar o projeto, para ver sua versão do g++ rode:
```cmd
g++ --version
```
## Compilação

Para compilar o programa, abra o diretório do projeto e insira os seguintes comandos no terminal:
```sh
cd hotel-descanso-garantido/
g++ main.cpp -o output
./output
```

## Testes

<table>
  <tr>
    <th>ID</th>
    <th>Escopo</th>
    <th>Entrada</th>
    <th>Saída esperada</th>
    <th>Status</th>
  </tr>
  <tr>
    <td>#1</td>
    <td>Cadastro de cliente</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Nome: </strong> Alvim</li>
        <li><strong>Endereço: </strong> Rua das Dores, 444</li>
        <li><strong>Telefone: </strong> 3196289</li>
      </ul>
    </td>
    <td>Cliente cadastrado com sucesso!</td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#2</td>
    <td>Cadastro de cliente com telefone já usado</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Nome: </strong> Bernardo</li>
        <li><strong>Endereço: </strong> Rua das Cores, 555</li>
        <li><strong>Telefone: </strong> 3196289</li>
      </ul>
    </td>
    <td>Este telefone ja esta cadastrado. (repetirá até digitar um telefone não usado)</td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#3</td>
    <td>Cadastro de funcionário</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Nome: </strong> Markowisk</li>
        <li><strong>Telefone: </strong> 31928393</li>
        <li><strong>Cargo: </strong> Supervisora</li>
        <li><strong>Salário: </strong> 2000</li>
      </ul>
    </td>
    <td>Funcionário cadastrado com sucesso!</td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#4</td>
    <td>Cadastro de funcionário com telefone já usado</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Nome: </strong> Bruna</li>
        <li><strong>Telefone: </strong> 31928393</li>
        <li><strong>Cargo: </strong> Recepcionista</li>
        <li><strong>Salário: </strong> 1200</li>
      </ul>
    </td>
    <td>Este telefone ja esta cadastrado. (repetirá até digitar um telefone não usado)</td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#5</td>
    <td>Cadastro de quarto</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Número: </strong> 505</li>
        <li><strong>Quantidade de Hóspedes: </strong> 2</li>
        <li><strong>Diária: </strong> 250</li>
      </ul>
    </td>
    <td>Quarto cadastrado com sucesso!</td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#6</td>
    <td>Cadastro de quarto já existente</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Número: </strong> 505 (Número do quarto cadastrado no teste #3)</li>
        <li>A função é parada porque o número do quarto já existe</li>
      </ul>
    </td>
    <td>Este quarto já existe.</td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#7</td>
    <td>Pesquisar cliente por código</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Codigo do cliente: </strong> < ID do cliente cadastrado no teste #1 ></li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Codigo: </strong> < Código do cliente cadastrado no teste #1 ></li>
        <li><strong>Nome: </strong> alvim</li>
        <li><strong>Endereço: </strong> Rua das Dores, 444</li>
        <li><strong>Telefone: </strong> 3196289</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#8</td>
    <td>Pesquisar cliente por nome</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Nome: </strong> Alvim</li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Codigo: </strong> < Código do cliente cadastrado no teste #1 ></li>
        <li><strong>Nome: </strong> alvim</li>
        <li><strong>Endereço: </strong> Rua das Dores, 444</li>
        <li><strong>Telefone: </strong> 3196289</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#9</td>
    <td>Pesquisar por código</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Codigo do: </strong> < Codigo do funcionário cadastrado no teste #2 ></li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Codigo: </strong> < Código do funcionário cadastrado no teste #3 ></li>
        <li><strong>Nome: </strong> markowisk</li>
        <li><strong>Telefone: </strong> 31928393</li>
        <li><strong>Cargo: </strong> Supervisora</li>
        <li><strong>Salário: </strong> 2000</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#10</td>
    <td>Pesquisar por nome</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Nome: </strong> Markowisk</li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Codigo: </strong> < Código do funcionário cadastrado no teste #3 ></li>
        <li><strong>Nome: </strong> markowisk</li>
        <li><strong>Telefone: </strong> 31928393</li>
        <li><strong>Cargo: </strong> Supervisora</li>
        <li><strong>Salário: </strong> 2000</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#1</td>
    <td>Listagem de quartos</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li>(Não há entrada)</li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Número: </strong> 505</li>
        <li><strong>Quantidade de Hóspedes: </strong> 2</li>
        <li><strong>Diária: </strong> 250</li>
        <li><strong>Disponibilidade: </strong> desocupado</li>
        <br>
        <li>(Outros quartos cadastrados...)</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#12</td>
    <td>Cadastro de estadia</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Número: </strong> 505</li>
        <li><strong>Quantidade de Hóspedes: </strong> 2</li>
        <li><strong>Data de entrada: </strong> 21/05/2022</li>
        <li><strong>Data de saída: </strong> 24/05/2022</li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li>Quarto número: 505 esta desocupado</li>
        <li>Este quarto possui uma diaria de: 250</li>
        <li>Status do quarto atualizado com sucesso!</li>
        <li>O valor total eh: 750</li>
        <li><strong>Estadia registrada com sucesso!</strong></li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#13</td>
    <td>Pesquisar estadia</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Codigo do cliente: </strong> < Codigo do cliente cadastrado no teste #1 ></li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Estadia #</strong>< ID da estadia cadastrada no teste #12 ></li>
        <li><strong>Hóspede: </strong> Alvim</li>
        <li><strong>Quarto: </strong>< Número do quarto cadastrado no teste #5 ></li>
        <li><strong>Data de entrada: </strong> 21/05/2022</li>
        <li><strong>Data de saída: </strong> 24/05/2022</li>
        <li><strong>Valor da diária: </strong> 250</li>
        <li><strong>Valor total: </strong> 750</li>
        <br>
        <li>(Outras estadias no nome do cliente)</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#14</td>
    <td>Dar baixa em estadia</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>ID da estadia: </strong> < ID da estadia cadastrada no teste #12 ></li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li>Status do quarto atualizado com sucesso!</li>
        <li>Pontos do cliente atualizados com sucesso!</li>
        <li><strong>Estadia encerrada com sucesso e quarto desocupado.</strong></li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
</table>

## Utilização

<table>
  <thead>
    <tr>
      <th>Opção</th>
      <th>Funcionalidade</th>
      <th>Descrição</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>0</td>
      <td>Encerrar o programa</td>
      <td>Encerra a execução do software.</td>
    </tr>
    <tr>
      <td>1</td>
      <td>Cadastrar um cliente</td>
      <td>Solicita as informações necessárias para cadastro de um cliente e insere um novo cliente no arquivo.</td>
    </tr>
    <tr>
      <td>2</td>
      <td>Cadastrar um funcionário</td>
      <td>Solicita as informações necessárias para cadastro de um funcionário e insere um novo funcionário no arquivo.</td>
    </tr>
    <tr>
      <td>3</td>
      <td>Cadastrar um quarto</td>
      <td>Solicita as informações necessárias para cadastro de um quarto e insere um novo quarto no arquivo.</td>
    </tr>
    <tr>
      <td>4</td>
      <td>Cadastrar uma estadia</td>
      <td>Solicita as informações necessárias para cadastro de uma estadia e insere uma nova estadia no arquivo.</td>
    </tr>
    <tr>
      <td>5</td>
      <td>Pesquisar um cliente</td>
      <td>Pesquisa um cliente pelo código ou nome e imprime todos os dados do cliente encontrado.</td>
    </tr>
    <tr>
      <td>6</td>
      <td>Pesquisar um funcionário</td>
      <td>Pesquisa um funcionário pelo código ou nome e imprime todos os dados do funcionário encontrado.</td>
    </tr>
    <tr>
      <td>7</td>
      <td>Listar os quartos</td>
      <td>Lista todos os quartos cadastrados e imprime todos os dados dos quartos.</td>
    </tr>
    <tr>
      <td>8</td>
      <td>Pesquisar uma estadia</td>
      <td>Pesquisa uma estadia pelo código do cliente e imprime todos os dados da estadia encontrada.</td>
    </tr>
    <tr>
      <td>9</td>
      <td>Dar baixa em uma estadia</td>
      <td>Registra a saída do cliente pelo seu código e encerra a estadia no sistema, atualizando o status do quarto e pontos do cliente.</td>
    </tr>
  </tbody>
</table>


## Links

| Placeholder  | URL 
---------------|-------------------------------
| Repositório  | https://github.com/alvim-puc/hotel-descanso-garantido
| Apresentação | https://youtu.be/ZFW1MSyd2aI
