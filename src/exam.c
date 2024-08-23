// Includes
#include "../include/exam.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------------------------- STRUCT ----------------------------

// Estrutura de Exam
struct exam {
  int id;
  int patient_id;
  int rx_id;
  Condition* condition_IA;
  int timestamp;
};

// Definição de estrutura do Condition_IA
struct condition_IA
{
  char* name_condition;
  int severity;
};

// Criar exame
Exam *create_exam(int id, int patient_id, int rx_id, Condition (*get_random_condition)(), int timestamp) {
  Exam *new_exam = (Exam *)malloc(sizeof(Exam)); // Alocação de mamória pra estrutura
  // Verifica se foi alocado
  if (new_exam == NULL) { 
    printf("Erro ao alocar memória para o novo exame.");
    return NULL;
  }

  // Inicializar as variáveis do exame
  new_exam->id = id;
  new_exam->patient_id = patient_id;
  new_exam->rx_id = rx_id;
  new_exam->condition_IA = (Condition*)malloc(sizeof(Condition));
    if (new_exam->condition_IA == NULL) {
        printf("Erro ao alocar memória para a condição.\n");
        free(new_exam);
        return NULL;
    }
    *(new_exam->condition_IA) = get_random_condition();
  new_exam->timestamp = timestamp;

  return new_exam;
}
// Função para liberar memória de um exame
void destroy_exam(Exam *exam) {
  // Sempre verificando se, por acaso, o parametro passado existe
  if (exam != NULL) {

    if (exam->timestamp != NULL) {
      free(exam->timestamp);
    }

    free(exam);
  }
}
// Função para retornar o id do exam
int get_exam_id(Exam *exam) {
  if (exam != NULL) {
    return exam->id;
  } else {
    printf("Erro! O exame não existe.\n");
    return -1;
  }
}
// Função para retornar o id do paciente em relação ao exame
int get_exam_patient_id(Exam *exam) {
  if (exam != NULL) {
    return exam->patient_id;
  } else {
    printf("Erro! O exame não existe.\n");
    return -1;
  }
}
// Função para retornar o id da maquina usada no exame
int get_exam_rx_id(Exam *exam) {
  if (exam != NULL) {
    return exam->rx_id;
  } else {
    printf("Erro! O exame não existe.\n");
    return -1;
  }
}
// Função para retornar o horário que o exame foi feito
int get_exam_time(Exam *exam) {
  if (exam != NULL) {
    return exam->timestamp;
  } else {
    printf("Erro! O exame não existe.\n");
    return NULL;
  }
}

// ---------------------------- QUEUE AND NODES ----------------------------

// Definição da estrutura dos nós da fila dos exames
struct qnExam{
	Exam* info;
	qnExam* next;
  qnExam* prev;
};

// Definição da estrutura da fila dos exames
struct qExam{
  int count;
	qnExam* front;
	qnExam* rear;
};

// Criação de filas vazias para exames
qExam* create_qExam(){
	qExam* q = (qExam*)malloc(sizeof(qExam));
    // Verifica se alocou corretament
    if (q == NULL){
        printf("Erro ao alocar memória para a fila vazia.\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    return q;
}

// Função para verificar se a fila de exames está vazia
int fila_vazia_exam (qExam* q){
    return q->front == NULL;
}

// Inserir exame na fila de exames de acordo com a severidade do paciente

void enqueue_qExam(qExam* q, Exam* exam){
    qnExam* node = (qnExam*)malloc(sizeof(qnExam));

    if (node == NULL){
        printf("Erro ao alocar memória para o nó.\n");
        return NULL;
    }

    node->info = exam;

    if (fila_vazia_exam(q)){
        node->next = node->prev = NULL;
        q->front = q->rear = node;
        q->count++;
    }

    else{
      qnExam* temp = q->front;
      // qnExam* temp = node->next;
      while (node->info->condition_IA->severity <= temp->info->condition_IA->severity){
        temp = temp->next;
      }
      node->prev = temp->prev;
      temp->prev = node;
      node->next = temp;
      q->count++;
    }
}

// Função para tirar exame da fila
Exam* dqueue_qExam(qExam* q){
    assert(!fila_vazia_exam(q));

    Exam* p = q->front->info;
    qnExam* node = q->front;

    if (q->front != q->rear){
        q->front = q->front->next;
    }
    else{
        q->front = q->rear = NULL;
    }
    q->count--;
    free(node);
    return p;
}

// Função para liberar a memória de uma fila.
void free_qExam(qExam* q){
    qnExam* node = q->front;
    while(node != NULL){
        qnExam* t = node->next;
        free(node);
        node = t;
    }
    free(q);
}

Condition get_random_condition() {
    // Definição das condições e suas probabilidades
  Condition conditions[] = {
      {"Saúde Normal", 1},
      {"Bronquite", 2},
      {"Pneumonia", 3},
      {"COVID", 4},
      {"Embolia pulmonar", 4},
      {"Derrame pleural", 4},
      {"Fibrose pulmonar", 5},
      {"Tuberculose", 5},
      {"Câncer de pulmão", 6}
  };

  double probabilities[] = {0.3, 0.2, 0.1, 0.1, 0.05, 0.05, 0.05, 0.05, 0.01};
  int num_conditions = sizeof(probabilities) / sizeof(probabilities[0]);

  // Gerar um número aleatório entre 0 e 1
  double rand_num = (double)rand() / RAND_MAX;

  // Selecionar a condição com base no número aleatório
  double cumulative_probability = 0.0;
  for (int i = 0; i < num_conditions; i++) {
      cumulative_probability += probabilities[i];
      if (rand_num <= cumulative_probability) {
          return conditions[i];
      }
  }

  // Caso algo dê errado, retornar a primeira condição como padrão
  return conditions[0];
}


void arq_exam(Exam* exam, const char* filename) {
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
      perror("Erro ao abrir o arquivo");
      return;
  }

  fprintf(file, "ID do Exame: %d\n", exam->id);
  fprintf(file, "ID do Paciente: %d\n", exam->patient_id);
  fprintf(file, "ID da Máquina RX: %d\n", exam->rx_id);
  fprintf(file, "Timestamp: %d\n", exam->timestamp);
  fprintf(file, "Condição do Paciente: %s\n", exam->condition_IA->name_condition);
  fprintf(file, "Gravidade: %d\n", exam->condition_IA->severity);

  fclose(file);
}