#include "../include/report.h"
#include "../include/exam.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para Report
typedef struct report{
	int id;
	int exam_id;
	Condition *condition_IA;
	int timestamp;
} report;

struct condition_IA
{
  char* name_condition;
  int severity;
};

struct exam {
  int id;
  int patient_id;
  int rx_id;
  Condition* condition_IA;
  int timestamp;
};

// Cria relatório de acordo com a probabilidade de acerto
Report* create_report(int id, Exam* exam, int timestamp){
  Report* r = (Report*)malloc(sizeof(Report));

  if (r == NULL){
    printf("Erro ao alocar memória.\n");
    return NULL;
  }
  r->id = id;
  r->exam_id = exam->id;
  r->timestamp = timestamp;

  srand(time(NULL));
  int num_random = rand() % 100;

  if(num_random < 80){
    r->condition_IA = exam -> condition_IA;
  }
  else{
    Condition *a = get_random_condition();
    while (a == exam->condition_IA){
        a = get_random_condition();
    }
    r->condition_IA = a;
  }
  return r;
}

// Destrói relatório
void destroy_report(Report *report){


}

// Retorna o ID do relatório
int get_report_id(Report *report){
  return report->id;
}

// Retorna a doença do relatório
const char* get_report_condition(Report *report){
  return report->condition_IA;
}

// Retorna o momento que o relatório foi gerado
int get_report_timestamp(Report *report){
  return report->timestamp;
}

void arq_report(Report* report, const char* filename) {
  FILE* file = fopen(filename, "w");
  if (file == NULL) {
      perror("Erro ao abrir o arquivo");
      return;
  }

  fprintf(file, "ID do Laudo: %d\n", report->id);
  fprintf(file, "ID do Exame: %d\n", report->exam_id);
  fprintf(file, "Condição: %s\n", report->condition_IA->name_condition);
  fprintf(file, "Gerado em: %d\n", report->timestamp);
  
  fclose(file);
}

int waiting_time(Report* report, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int exam_id, patient_id, rx_id, timestamp;
    char condition_name[100];
    int condition_severity;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "ID do Exame: %d", &exam_id) == 1) {
            // Ler as próximas linhas para obter os outros campos
            fgets(line, sizeof(line), file); // ID do Paciente
            fgets(line, sizeof(line), file); // ID da Máquina RX
            fgets(line, sizeof(line), file); // Timestamp
            sscanf(line, "Timestamp: %d", &timestamp);
            fgets(line, sizeof(line), file); // Condição do Paciente
            fgets(line, sizeof(line), file); // Gravidade

            if (exam_id == report->exam_id) {
                fclose(file);
                return report->timestamp - timestamp;
            }
        }
    }

    fclose(file);
    printf("Exame não encontrado.\n");
    return -1;
}

float waiting_mean(){
    
}