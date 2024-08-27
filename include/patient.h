#ifndef PATIENT
#define PATIENT

#include <time.h>

typedef struct patient Patient;
typedef struct qPatient qPatient;
typedef struct qnPatient qnPatient;

// ---------------------------- STRUCT ----------------------------

Patient* create_patient(int id, const char *name, int timestamp); // Criar paciente
void destroy_patient(Patient *patient); // Deletar paciente
qPatient* create_qPatient(); //Criação de fila vazia de pacientes;
int fila_vazia (qPatient* q);  //Verificar se a fila está vazia;
void enqueue_qPatient(qPatient* q, Patient* patient); //Inserir paciente na fila;
Patient* dqueue_qPatient(qPatient* q); //Retirar paciente da fila;
void free_qPatient(qPatient* q); //Função para liberar memória de uma fila;

// ---------------------------- ARQUIVO ----------------------------

void arq_patient(Patient* patient, const char* filename);

#endif