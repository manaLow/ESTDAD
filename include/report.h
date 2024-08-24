#ifndef REPORT_H
#define REPORT_H

typedef struct report Report;
typedef struct condition_IA Condition;

Report* create_report(int id, Exam* exam, int timestamp); //Criar relatório respeitando as probabilidades de acerto do IA
void destroy_report(Report *report);
int get_report_id(Report *report); // Pegar o id do report;
const char* get_report_condition(Report *report); // Pegar o condition do report;
int get_report_timestamp(Report *report); // Pegar o timestamp do report;
void arq_report(Report* report, const char* filename);
int waiting_time(Report *report, const char *exam_filename);
double mean_waiting_time(const char *report_filename, const char *exam_filename);
double mean_time_by_condition(const char *report_filename, const char *exam_filename);

#endif