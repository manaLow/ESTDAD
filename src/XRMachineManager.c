#include "../include/XRMachineManager.h"
#include "../include/patient.h"
#include "../include/exam.h"
#include "../include/report.h"
#include <stdio.h>

// Estrutura máquina
typedef struct maquina
{
    int rx_id;
    int ocupado;
    int tempo_restante;
    Patient *patient;
};

// Estrutura paciente
struct patient
{
    int id;
    char *name;
    int timestamp;
} patient;

// Estrutura médico
typedef struct doctor
{
    int ocupado;
    int tempo_restante;
    Exam *exame;
} Doctor;

// Inicializa máquinas
void inicializa_aparelhos(Machine *aparelhos)
{
    for (int i = 0; i < NUM_APARELHOS; i++)
    {
        aparelhos[i].rx_id = i;
        aparelhos[i].ocupado = 0;
        aparelhos[i].tempo_restante = 0;
        aparelhos[i].patient = NULL;
    }
}

// Aloca paciente da fila pra os aparelhos
void aloca_paciente(Machine *aparelhos, qPatient *fila)
{
    for (int i = 0; i < NUM_APARELHOS; i++)
    {
        if (!aparelhos[i].ocupado && !fila_vazia(fila))
        {
            Patient *patient = dqueue_qPatient(fila);
            aparelhos[i].ocupado = 1;
            aparelhos[i].tempo_restante = 10;
            aparelhos[i].patient = patient;
            break;
        }
    }
}

// Atualiza tempo e ocupação
void atualiza_aparelhos(Machine *aparelhos, qExam *qexam, int unt)
{
    for (int i = 0; i < NUM_APARELHOS; i++)
    {
        if (aparelhos[i].ocupado)
        {
            aparelhos[i].tempo_restante--;
            if (aparelhos[i].tempo_restante == 0)
            {
                aparelhos[i].ocupado = 0;
                Exam *exame = create_exam( (aparelhos[i].patient)->id + 1, (aparelhos[i].patient)->id, aparelhos[i].rx_id, get_random_condition, unt);
                arq_exam(exame, "db_exames");
                enqueue_qExam(qexam, exame);
                free(aparelhos[i].patient); // Libera a memória do paciente
                aparelhos[i].patient = NULL;
            }
        }
    }
}

void inicia_atendimento(Doctor *doutor)
{
    doutor->exame = NULL;
    doutor->ocupado = 0;
    doutor->tempo_restante = 0;
}

void aloca_atendimento(Doctor *doutor, qExam *q_exams)
{
    if (doutor->ocupado == 0 && !fila_vazia(q_exams))
    {
        Exam *exame = dqueue_qExam(q_exams);
        doutor->ocupado = 1;
        doutor->tempo_restante = 30;
        doutor->exame = exame;
    }
}

void atualiza_atendimento(Doctor *doutor, int unt, int i)
{
    if (doutor->ocupado == 1)
    {
        doutor->tempo_restante--;
        if (doutor->tempo_restante == 0)
        {
            doutor->ocupado = 0;
            Report *report = create_report(i, doutor->exame, unt);
            arq_report(report, "db_report.txt");
            free(doutor->exame); // Libera a memória do exame
            doutor->exame = NULL;
        }
    }
}