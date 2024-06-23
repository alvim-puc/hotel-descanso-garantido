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
│   └── (arquivos de gravação)
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
Já no Windows, é necessário ter o `chocolatey` baixado.
Caso ainda não tenha, insira esse comando no seu PowerShell executado como Administrador
```pwsh
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```
Posteriormente, utilize o `choco` para instalar o `MinGW`.
```pwsh
choco install mingw -y
```
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
    <td>#3</td>
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
    <td>#4</td>
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
    <td>#5</td>
    <td>Pesquisar cliente por código</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>ID do cliente: </strong> < ID do cliente cadastrado no teste #1 ></li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>ID: </strong> < Código do cliente cadastrado no teste #1 ></li>
        <li><strong>Nome: </strong> Alvim</li>
        <li><strong>Endereço: </strong> Rua das Dores, 444</li>
        <li><strong>Telefone: </strong> 3196289</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
  <tr>
    <td>#6</td>
    <td>Pesquisar cliente por nome</td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>Nome: </strong> Alvim</li>
      </ul>
    </td>
    <td>
      <ul style="list-style: none; padding: 0;">
        <li><strong>ID: </strong> < Código do cliente cadastrado no teste #1 ></li>
        <li><strong>Nome: </strong> Alvim</li>
        <li><strong>Endereço: </strong> Rua das Dores, 444</li>
        <li><strong>Telefone: </strong> 3196289</li>
      </ul>
    </td>
    <td>Aprovado</td>
  </tr>
</table>

## Utilização

## Links

| Placeholder  | URL 
---------------|-------------------------------
| Repositório  | https://github.com/alvim-puc/hotel-descanso-garantido
| Apresentação | https://youtu.be
