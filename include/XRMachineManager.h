#ifndef XR_MACHINE_MANAGER_H
#define XR_MACHINE_MANAGER_H
#define NUM_APARELHOS 5
#include "patient.h"
#include "exam.h"


typedef struct maquina Machine;

void inicializa_aparelhos(Machine* aparelhos);
void aloca_paciente(Machine* aparelhos, qPatient* fila);
void atualiza_aparelhos(Machine* aparelhos, qExam* qexam ,int unt);

#endif