
# Simulação de Realização de Exames de Raio-X (PARTE 1)
 
## Descrição
Este projeto tem por objetivo implementar dois tipos abstratos de dados ("Patient" e "Exam"). Através deles, vamos modelar os pacientes que chegam ao hospital e os exames de raio-x, com funções para manipular esses mesmos TADs, incluindo adicionar, remover e buscar elementos.

## Estrutura do Projeto

├── main.c               -> Arquivo principal do programa

├── exam.c        -> Arquivo de implementação do TAD Exames

├── exam.h        -> Arquivo de header do TAD Exames

├── patient.c        -> Arquivo de implementação do TAD Pacientes

├── patient.h        -> Arquivo de header do TAD Pacientes

└── README.md     -> Este arquivo README

## Instalação e Execução

#### 1. Clone o repositório
Primeiro, clone o repositório do GitHub para seu ambiente local:

 ```
 git clone https://github.com/manaLow/ESTDAD.git
 cd ESTDAD
 ```

#### 2. Compile o projeto
Depois de clonar o repositório, compile o projeto usando o GCC. Execute o seguinte comando:

 ```
 gcc -o programa main.c patient.c exam.c
 ```

#### 3. Executar o programa:
Para executar o programa compilado, use o seguinte comando:

 ```
 ./programa
 ```
 
## Funcionalidades

### Exemplo do uso de TADs

#### Patient
print screen do cabeçalho de patient


 - create_patient:
 - destroy_patient:
 - get_patient_id:
 - get_patient_name:
 - get_patient_birthdate:

#### Exam
print screen do cabeçalho de exam


 - create_exam:
 - destroy_exam:
 - get_exam_id:
 - get_exam_patient_id:
 - get_exam_rx_id:
 - get_exam_time:
 











