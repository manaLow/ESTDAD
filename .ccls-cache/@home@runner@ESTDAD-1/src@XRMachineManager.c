#include "../include/XRMachineManager.h"
#include "../include/exam.h"
#include "../include/patient.h"
#include "../include/report.h"
#include <stdio.h>
#include <stdlib.h>

// Estrutura máquina./
typedef struct maquina {
  int rx_id;
  int ocupado;
  int tempo_restante;
  Patient *patient;

} Machine;

// Estrutura paciente
struct patient {
  int id;
  char *name;
  int timestamp;
} patient;

// Estrutura médico
struct doctor {
  int ocupado;
  int tempo_restante;
  Exam *exame;
};

struct qnExam {
  Exam *info;
  qnExam *next;
  qnExam *prev;
};

// Definição da estrutura da fila dos exames
struct qExam {
  // int countever;
  int count;
  qnExam *front;
  qnExam *rear;
};

// Inicializa máquinas
void inicializa_aparelhos(Machine *aparelhos[]) {
  for (int i = 0; i < 5; i++) {
    aparelhos[i]->rx_id = i + 1;
    aparelhos[i]->ocupado = 0;
    aparelhos[i]->tempo_restante = 0;
    aparelhos[i]->patient = NULL;
  }
}

// Aloca paciente da fila pra os aparelhos
void aloca_paciente(Machine *aparelhos[], qPatient *fila) { 
  for (int i = 0; i < 5; i++) {
    if ((aparelhos[i]->ocupado == 0) && (!fila_vazia(fila))) {
      Patient *patient = dqueue_qPatient(fila);
      aparelhos[i]->ocupado = 1;
      aparelhos[i]->tempo_restante = 10;
      aparelhos[i]->patient = patient;
      //printf("Paciente ID=%d alocado no aparelho ID=%d\n", patient->id, aparelhos[i]->rx_id);
      break;
    }
  }
}

// Atualiza tempo e ocupação
void atualiza_aparelhos(Machine *aparelhos[], qExam *qexam, int unt) {
  for (int i = 0; i < 5; i++) {
    if (aparelhos[i]->ocupado == 1) {
      aparelhos[i]->tempo_restante--;
      if (aparelhos[i]->tempo_restante == 0) {
        aparelhos[i]->ocupado = 0;       
        if (aparelhos[i]->patient != NULL) { //MODIFICADO
          Condition *condition = get_random_condition()
          Exam *exame = create_exam((aparelhos[i]->patient)->id + 1, (aparelhos[i]->patient)->id, aparelhos[i]->rx_id, condition, unt); //Tentei chamar a função antes de colocá-la no parametro
          arq_exam(exame, "db_exam.txt");
          enqueue_qExam(qexam, exame);
          free(aparelhos[i]->patient); // Libera a memória do paciente
          aparelhos[i]->patient = NULL;
        }  
      }  
    }
  }
}

void inicia_atendimento(Doctor *doutor) {
  doutor->exame = NULL;
  doutor->ocupado = 0;
  doutor->tempo_restante = 0;
}

void aloca_atendimento(Doctor *doutor, qExam *q_exams) {
  if (doutor->ocupado == 0 && (q_exams->count > 0)) {
    Exam *exame = dqueue_qExam(q_exams);
    doutor->ocupado = 1;
    doutor->tempo_restante = 30;
    doutor->exame = exame;
  }
}

void atualiza_atendimento(Doctor *doutor, int unt, int i) {
  if (doutor->ocupado == 1) {
    doutor->tempo_restante--;
    if (doutor->tempo_restante == 0) {
      doutor->ocupado = 0;
      Report *report = create_report(i, doutor->exame, unt);
      arq_report(report, "db_report.txt");
      free(doutor->exame); // Libera a memória do exame
      doutor->exame = NULL;
    }
  }
}, Patient p