#include "exam.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct exam {
  int id;
  int patient_id;
  int rx_id;
  struct tm *time;
} exam;

Exam *create_exam(int id, int patient_id, int rx_id, struct tm *time) {
  Exam *new_exam = (Exam *)malloc(sizeof(Exam));
  if (new_exam == NULL) {
    printf("Erro ao alocar memória para o novo exame.");
    return NULL;
  }

  // Inicializar as variáveis do exame
  new_exam->id = id;
  new_exam->patient_id = patient_id;
  new_exam->rx_id = rx_id;

  new_exam->time = (struct tm *)malloc(sizeof(struct tm));
  if (new_exam->time == NULL) {
    printf("Erro ao alocar memória para o tempo do exame.");
    free(new_exam);
    return NULL;
  }
  *(new_exam->time) = *time;

  return new_exam;
}

void destroy_exam(Exam *exam) {
  if (exam != NULL) {

    if (exam->time != NULL) {
      free(exam->time);
    }

    free(exam);
  }
}

int get_exam_id(Exam *exam) {
  if (exam != NULL) {
    return exam->id;
  } else {
    printf("Erro! O exame não existe.\n");
    return -1;
  }
}

int get_exam_patient_id(Exam *exam) {
  if (exam != NULL) {
    return exam->patient_id;
  } else {
    printf("Erro! O exame não existe.\n");
    return -1;
  }
}

int get_exam_rx_id(Exam *exam) {
  if (exam != NULL) {
    return exam->rx_id;
  } else {
    printf("Erro! O exame não existe.\n");
    return -1;
  }
}

struct tm *get_exam_time(Exam *exam) {
  if (exam != NULL) {
    return exam->time;
  } else {
    printf("Erro! O exame não existe.\n");
    return NULL;
  }
}