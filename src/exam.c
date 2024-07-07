// Includes
#include "../include/exam.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura de Exam
struct exam {
  int id;
  int patient_id;
  int rx_id;
  struct tm *time;
} exam;


// Criar exame
Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time) {
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

  // Precisa de alocar memória para o tempo
  new_exam->time = (struct tm *)malloc(sizeof(struct tm));

  // Verifica se alocou corretamente, caso não: memória liberada
  if (new_exam->time == NULL) {
    printf("Erro ao alocar memória para o tempo do exame.");
    free(new_exam);
    return NULL;
  }
  *(new_exam->time) = *time;

  return new_exam;
}
// Função para liberar memória de um exame
void destroy_exam(Exam *exam) {
  // Sempre verificando se, por acaso, o parametro passado existe
  if (exam != NULL) {

    if (exam->time != NULL) {
      free(exam->time);
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
struct tm *get_exam_time(Exam *exam) {
  if (exam != NULL) {
    return exam->time;
  } else {
    printf("Erro! O exame não existe.\n");
    return NULL;
  }
}
