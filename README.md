# Hotel Descanso Garantido

## Coders
- Bernardo Alvim
- Bruna Markowisk
- Matheus Gaston

## Ferramentas

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![Git](https://img.shields.io/badge/git-%23F05033.svg?style=for-the-badge&logo=git&logoColor=white)


## Estrutura do Projeto

```plaintext
hotel-descanso-garantido/
│ 
├── bin/
│   └── main.exe (arquivo de execução do programa)
├── files/
│   └── (arquivos manipulados pelo programa)
├── include/
│   └── hotel.h (biblioteca de funções do programa)
├── obj/
│   └── (arquivos de objetos gerados pelo programa)
├── src/
│   ├── hotel.c (funções do programa)
│   └── main.c (programa principal)
└── Makefile (arquivo de compilação)
```

## Instalação

Clone este repositório

Certifique-se de ter o `Make` e o `gcc` instalados.

Para instalá-los no Unix, insira o seguinte comando:  
```bash
sudo apt-get install gcc make
```
No Windows, é necessário ter o `chocolatey` baixado.
Caso ainda não tenha, insira esse comando no seu PowerShell executado como Administrador
```pwsh
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```
Posteriormente, utilize o `choco` para instalar o `gcc` e o `Make`.
```pwsh
choco install mingw -y
choco install make -y
```
## Compilação

Para compilar o programa, abra o diretório do projeto e insira os seguintes comandos no terminal:
```sh
make
./bin/main.exe
```

## Backlog

## Testes


## Utilização

## Vídeo de apresentação