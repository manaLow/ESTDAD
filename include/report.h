#ifndef REPORT_H
#define REPORT_H

typedef struct report Report;
typedef struct condition_IA Condition;
typedef struct exam Exam;

Report* create_report(int id, Exam* exam, int timestamp); //Criar relatório respeitando as probabilidades de acerto do IA
void destroy_report(Report *report); //Deletar o report;
void arq_report(Report* report, const char* filename); //Gravar report no banco de dados;
int waiting_time(Report *report, const char *exam_filename); // Tempo de espera pelo laudo
double mean_waiting_time(const char *report_filename, const char *exam_filename); //Tempo médio de espera por laudo;
double mean_time_by_condition(const char *report_filename, const char *exam_filename); //Tempo médio de espera por laudo por condição;

#endif