#ifndef AUXILIAR_H
#define AUXILIAR_H

typedef struct patient Patient;
typedef struct qPatient qPatient;
typedef struct qnPatient qnPatient;

void create_empty_files(const char* filename);
char* random_name();
int contar_laudos_exames(const char* filename);
void relatorio_print(int ptotal, const char *report_file, const char *exam_file, qPatient* qp);


#endif