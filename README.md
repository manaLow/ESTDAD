
# Simulação de Realização de Exames de Raio-X (PARTE 1)

> _Grupo J: Kevin Kliss e Manuely Lemos_
## Descrição
Esta parte do projeto tem por objetivo implementar dois tipos abstratos de dados ("Patient" e "Exam"). Através deles, vamos modelar os pacientes que chegam ao hospital e os exames de raio-x, com funções para manipular esses mesmos TADs, incluindo adicionar, remover e buscar elementos.

## Estrutura do Projeto
.
ESTDAD/ ---> Pasta

|_  main.c # Arquivo principal

|_ Makefile
 
|_  include/ ---> Pasta com os cabeçalhos

|____   exam.h
   
|____   patient.h
   
| _ src/ ---> Pasta com as implementações
 
|____   exam.c
   
|____   patient.c
   
|_ README.md # Este arquivo README


## Execução do Projeto

### Pré-requisitos
Certifique-se de ter os seguintes pacotes instalados:

- GCC (ou outro compilador C)
- Git

Para instalar o GCC e Git, você pode usar os seguintes comandos no seu terminal (para sistemas baseados em Debian/Ubuntu):
 ```
sudo apt update
sudo apt install gcc git
 ```

### Instalação
#### 1. Clone o repositório
Primeiro, clone o repositório do GitHub para seu ambiente local:

 ```
 git clone https://github.com/manaLow/ESTDAD.git
 cd ESTDAD
 ```

#### 2. Compile o projeto
Depois de clonar o repositório, compile o projeto usando o GCC. Execute o seguinte comando:

 ```
 make
 ```
ou
```
 gcc -o main main.c src/patient.c src/exam.c -I include
 ```

#### 3. Executar o programa:
Para executar o programa compilado, use o seguinte comando:

 ```
 ./main
 ```
 
## Funcionalidades

### Exemplo do uso de TADs

#### Patient

![patient](https://github.com/manaLow/ESTDAD/assets/104777338/d172cd82-4427-4735-91de-337a45faf172)

<sup> _Print Screen do arquivo cabeçalho "patient.h"_ <sup/>

 - **create_patient:** Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados
passados como parâmetros e retornando um ponteiro para a estrutura criada.
 - **destroy_patient:** Libera a memória alocada para a estrutura do paciente.
 - **get_patient_id:** Retorna a identificação única do paciente.
 - **get_patient_name:** Retorna nome do paciente.
 - **get_patient_birthdate:** Retorna data de nascimento do paciente.

#### Exam

![Captura de tela 2024-07-07 142113](https://github.com/manaLow/ESTDAD/assets/104777338/ae365ca0-6fbb-4384-a1b1-758f4a469a04)

<sup> _Print Screen do arquivo cabeçalho "exam.h"_ <sup/>

 - **create_exam:** Cria um novo exame, alocando memória para a estrutura, preenchendo os campos com os dados passados como
parâmetros e retornando um ponteiro para a estrutura criada.
 - **destroy_exam:** Libera a memória alocada para a estrutura de exame.
 - **get_exam_id:** Retorna a identificação única do exame.
 - **get_exam_patient_id:** Retorna a identificação única do paciente associado ao exame.
 - **get_exam_rx_id:** Retorna a identificação única do aparelho de raio-X utilizado no exame.
 - **get_exam_time:** Retorna horário de realização do exame.
 











