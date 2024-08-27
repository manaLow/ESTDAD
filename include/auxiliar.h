#ifndef AUXILIAR_H
#define AUXILIAR_H

typedef struct qPatient qPatient;
typedef struct qnPatient qnPatient;
typedef struct qnExam qnExam;
typedef struct qExam qExam;

void create_empty_files(const char* filename);
char* random_name();
int contar_laudos(const char* filename);
int contar_exames(const char* filename);
void relatorio_print(int ptotal, const char *report_file, const char *exam_file, qPatient* qp, int unt);


#endif