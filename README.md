# Hotel Descanso Garantido

## Coders
- Bernardo Alvim
- Bruna Markowisk
- Matheus Gaston

## Ferramentas

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
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
.\output
```

## Testes

## Utilização

## Vídeo de apresentação
