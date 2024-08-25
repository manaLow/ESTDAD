#ifndef XR_MACHINE_MANAGER_H
#define XR_MACHINE_MANAGER_H
#define NUM_APARELHOS 5
#include "patient.h"
#include "exam.h"


typedef struct maquina Machine;
typedef struct doctor Doctor;

void inicializa_aparelhos(Machine* aparelhos); //Inicializar os aparelhos;
void aloca_paciente(Machine* aparelhos, qPatient* fila); //Aloca os pacientes para as máquinas;
void atualiza_aparelhos(Machine* aparelhos, qExam* qexam ,int unt); //Atualiza o funcionamento dos aparelhos;
void inicia_atendimento(Doctor *doutor); // Inicia médico
void aloca_atendimento(Doctor *doutor, qExam *q_exams); // Aloca exame para atendimento
void atualiza_atendimento(Doctor *doutor, int unt, int i); // Atualiza atendimento

#endif