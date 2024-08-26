#include "../include/report.h"
#include "../include/exam.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura para Report
typedef struct report
{
  int id;
  int exam_id;
  Condition *condition_IA;
  int timestamp;
} report;

// Estrutura para categoria de prioridade;
struct condition_IA
{
  char *name_condition;
  int severity;
};

// Estrutura do exame
struct exam
{
  int id;
  int patient_id;
  int rx_id;
  Condition *condition_IA;
  int timestamp;
};

// Estrutura para calcular as médias
typedef struct
{
  char name_condition[100];
  int total_waiting_time;
  int count;
} ConditionStats;

// Cria relatório de acordo com a probabilidade de acerto
Report *create_report(int id, Exam *exam, int timestamp)
{
  Report *r = (Report *)malloc(sizeof(Report));

  if (r == NULL)
  {
    printf("Erro ao alocar memória.\n");
    return NULL;
  }
  r->id = id;
  r->exam_id = exam->id;
  r->timestamp = timestamp;

  srand(time(NULL));
  int num_random = rand() % 100;

  if (num_random < 80)
  {
    r->condition_IA = exam->condition_IA;
  }
  else
  {
    Condition *a = get_random_condition();
    while (a == exam->condition_IA)
    {
      a = get_random_condition();
    }
    r->condition_IA = a;
  }
  return r;
}

// Retorna o ID do relatório
int get_report_id(Report *report)
{
  if (report == NULL)
  {
    return 0;
  }
  return report->id;
}

// Retorna o momento que o relatório foi gerado
int get_report_timestamp(Report *report)
{
  return report->timestamp;
}

// Grava o report no banco de dados
void arq_report(Report *report, const char *filename)
{
  FILE *file = fopen(filename, "a");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return;
  }

  fprintf(file, "ID do Laudo: %d\n", report->id);
  fprintf(file, "ID do Exame: %d\n", report->exam_id);
  fprintf(file, "Condição: %s\n", report->condition_IA->name_condition);
  fprintf(file, "Gerado em: %d\n", report->timestamp);

  fclose(file);
}

// Tempo de espera pelo laudo
int waiting_time(Report *report, const char *exam_filename)
{
  FILE *file = fopen(exam_filename, "r");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return -1;
  }

  int exam_id, timestamp;
  char line[256];

  while (fgets(line, sizeof(line), file))
  {
    if (sscanf(line, "ID do Exame: %d", &exam_id) == 1)
    {
      // Ler as próximas linhas para obter os outros campos
      fgets(line, sizeof(line), file); // ID do Paciente
      fgets(line, sizeof(line), file); // ID da Máquina RX
      fgets(line, sizeof(line), file); // Timestamp
      sscanf(line, "Timestamp: %d", &timestamp);
      fgets(line, sizeof(line), file); // Condição do Paciente
      fgets(line, sizeof(line), file); // Gravidade

      if (exam_id == report->exam_id)
      {
        fclose(file);
        return report->timestamp - timestamp;
      }
    }
  }

  fclose(file);
  printf("Exame não encontrado.\n");
  return -1;
}

double mean_waiting_time(const char *report_filename, const char *exam_filename)
{
  FILE *file = fopen(report_filename, "r");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return -1;
  }

  int total_waiting_time = 0;
  int valid_reports = 0;
  int report_id, exam_id, timestamp;
  char line[256];

  while (fgets(line, sizeof(line), file))
  {
    if (sscanf(line, "ID do Laudo: %d", &report_id) == 1)
    {
      // Ler as próximas linhas para obter os outros campos
      fgets(line, sizeof(line), file); // ID do Exame
      sscanf(line, "ID do Exame: %d", &exam_id);
      fgets(line, sizeof(line), file); // Condição
      fgets(line, sizeof(line), file); // Gerado em
      sscanf(line, "Gerado em: %d", &timestamp);

      // Criar um relatório temporário para calcular o tempo de espera
      Condition condition = {"", 0}; // Condição fictícia
      Report report = {report_id, exam_id, &condition, timestamp};

      int wait_time = waiting_time(&report, exam_filename);
      if (wait_time != -1)
      {
        total_waiting_time += wait_time;
        valid_reports++;
      }
    }
  }
  fclose(file);

  if (valid_reports == 0)
  {
    return 0.00; // Evitar divisão por zero
  }

  return (float)total_waiting_time / valid_reports;
}


// Função que calcula e imprime tempo de espera médio por condição
double mean_time_by_condition(const char *report_filename, const char *exam_filename)
{
  FILE *file = fopen(report_filename, "r");
  if (file == NULL)
  {
    perror("Erro ao abrir o arquivo");
    return -1;
  }

  ConditionStats conditions[100];
  int num_conditions = 0;
  char line[256];
  int report_id, exam_id, timestamp;
  char condition_name[100];

  while (fgets(line, sizeof(line), file))
  {
    if (sscanf(line, "ID do Laudo: %d", &report_id) == 1)
    {
      fgets(line, sizeof(line), file); // ID do Exame
      sscanf(line, "ID do Exame: %d", &exam_id);
      fgets(line, sizeof(line), file); // Condição
      sscanf(line, "Condição: %s", condition_name);
      fgets(line, sizeof(line), file); // Gerado em
      sscanf(line, "Gerado em: %d", &timestamp);

      Condition condition = {"", 0};
      strcpy(condition.name_condition, condition_name);
      Report report = {report_id, exam_id, &condition, timestamp};

      int wait_time = waiting_time(&report, exam_filename);
      if (wait_time != -1)
      {
        int found = 0;
        for (int i = 0; i < num_conditions; i++)
        {
          if (strcmp(conditions[i].name_condition, condition_name) == 0)
          {
            conditions[i].total_waiting_time += wait_time;
            conditions[i].count++;
            found = 1;
            break;
          }
        }
        if (!found)
        {
          strcpy(conditions[num_conditions].name_condition, condition_name);
          conditions[num_conditions].total_waiting_time = wait_time;
          conditions[num_conditions].count = 1;
          num_conditions++;
        }
      }
    }
  }
  fclose(file);

  printf("Tempo médio de espera por condição:\n");
  for (int i = 0; i < num_conditions; i++)
  {
    double mean_time = (double)conditions[i].total_waiting_time / conditions[i].count;
    printf("Condição: %s, Tempo médio: %.2f\n", conditions[i].name_condition, mean_time);
  }

  return 0.0;
}
