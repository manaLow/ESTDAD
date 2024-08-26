# Simulação de Exames de Raio-X e Diagnóstico (PARTE 2)

> _Grupo M: Kevin Kliss e Manuely Lemos_
## Descrição
A segunda parte do projeto tem por objetivo simular uma situação em que pacientes chegam ao hospital e, de acordo com a urgência dos seus pré diagnósticos, são organizados em uma fila virtual de atendimento. Além dos tipos abstratos de dados, ainda utilizados na primeira parte do projeto, serão implementadas filas e arquivos que armazenarão dados ao longo de todo percurso do paciente até a entrega do laudo final.

## Estrutura do Projeto
.
ESTDAD/ ---> Pasta

|_  main.c # Arquivo principal

|_ Makefile

|_  include/ ---> Pasta com os cabeçalhos

|____   exam.h

|____   patient.h

|____   report.h

|____   XRMachineManager.h

|____   auxiliar.h

| _ src/ ---> Pasta com as implementações

|____   exam.c

|____   patient.c

|____   report.c

|____   XRMachineManager.c

|____   auxiliar.c

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

![patient](link do printscreen)

<sup> _Print Screen do arquivo cabeçalho "patient.h"_ <sup/>

 - **create_patient:** Cria um novo paciente, alocando memória para a estrutura, preenchendo os campos internos com os dados
 passados como parâmetros e retornando um ponteiro para a estrutura criada.
 - **destroy_patient:** Libera a memória alocada para a estrutura do paciente.
 - **get_patient_id:** Retorna a identificação única do paciente.
 - **get_patient_name:** Retorna nome do paciente.
 - **get_patient_timestamp:** Retorna o timestamp do paciente.
 - **create_qPatient:** Criação de fila vazia para pacientes.
 - **fila_vazia:** Verificar se a fila está vazia.
 - **enqueue_qPatient:** Inserir paciente na fila.
 - **dqueue_qPatient:** Retirar paciente da fila.
 - **free_qPatient:** Função para liberar memória de uma fila.
 - **arq_patient:** Gravar paciente no banco de dados.

 ## Exemplo de Uso do Projeto