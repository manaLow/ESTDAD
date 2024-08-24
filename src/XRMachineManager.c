#include "../include/XRMachineManager.h"
#include "../include/patient.h"
#include "../include/exam.h"
#include <stdio.h>

// Ainda não testei... Irei rever código
typedef struct maquina {
    int rx_id;
    int ocupado;
    int tempo_restante;
    Patient* patient;
};

struct patient {
  int id;
  char* name;
  int timestamp;
} patient;

void inicializa_aparelhos(Machine* aparelhos) {
    for (int i = 0; i < NUM_APARELHOS; i++) {
        aparelhos[i].rx_id = i;
        aparelhos[i].ocupado = 0;
        aparelhos[i].tempo_restante = 0;
        aparelhos[i].patient = NULL;
    }
}

void aloca_paciente(Machine* aparelhos, qPatient* fila) {
    for (int i = 0; i < NUM_APARELHOS; i++) {
        if (!aparelhos[i].ocupado && !fila_vazia(fila)) {
            Patient* patient = dqueue_qPatient(fila);
            aparelhos[i].ocupado = 1;
            aparelhos[i].tempo_restante = 10;
            aparelhos[i].patient = patient;
        }
    }
}

void atualiza_aparelhos(Machine* aparelhos, qExam* qexam ,int unt) {
    for (int i = 0; i < NUM_APARELHOS; i++) {
        if (aparelhos[i].ocupado) {
            aparelhos[i].tempo_restante--;
            if (aparelhos[i].tempo_restante == 0) {
                aparelhos[i].ocupado = 0;
                Exam* exame = create_exam(unt+3, (aparelhos[i].patient)->id, aparelhos[i].rx_id, get_random_condition, unt);
                arq_exam(exame, "db_exames");
                enqueue_qExam(qexam, exame);
                free(aparelhos[i].patient); // Libera a memória do paciente
                aparelhos[i].patient = NULL;
            }
        }
    }
}