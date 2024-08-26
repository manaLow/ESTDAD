#include "include/XRMachineManager.h"
#include "include/auxiliar.h"
#include "include/exam.h"
#include "include/patient.h"
#include "include/report.h"

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct maquina {
  int rx_id;
  int ocupado;
  int tempo_restante;
  Patient *patient;

} Machine;

typedef struct doctor {
  int ocupado;
  int tempo_restante;
  Exam *exame;
} Doctor;

int main() {
  srand(time(NULL)); // Seed pra criar número aleatório toda vez
  // iniciar contadores
  int ptotal = 0; // Número total de pacientes
  int unt = 0;    // Unidade de Tempo
  int id_p = 1;
  int id_l = 0;

  // iniciar filas
  qPatient *q_patients = create_qPatient();
  qExam *q_exams = create_qExam();

  // Criar arquivos
  create_empty_files("db_patient.txt");
  create_empty_files("db_exam.txt");
  create_empty_files("db_report.txt");

  // Inicializa máquinas e médico
  Machine *aparelhos[5];
  for (int i = 0; i < 5; i++) {
    aparelhos[i] = (Machine *)malloc(sizeof(Machine));
    if (aparelhos[i] == NULL) {
      printf("Error allocating memory for Machine\n");
    }
  }

  Doctor *doutor = (Doctor *)malloc(sizeof(Doctor));
  if (doutor == NULL) {
    printf("Error allocating memory for Doctor\n");
  }

  inicializa_aparelhos(aparelhos);
  inicia_atendimento(doutor);

  while (unt < 43200) {

    double patient_chance =
        (double)rand() / RAND_MAX; // numero aletório entre 0 e 1

    if (patient_chance <= 0.2) {
      char *n = random_name();
      Patient *patient = create_patient(id_p++, n, unt);
      arq_patient(patient, "db_patient.txt"); 
      enqueue_qPatient(q_patients, patient);
      ptotal++;
    }
    // PS: Anotações minhas.
    atualiza_aparelhos(aparelhos, q_exams, unt);
    aloca_paciente(aparelhos, q_patients); 
    atualiza_atendimento(doutor, unt, id_l++);
    aloca_atendimento(doutor, q_exams);

    unt++;

    if (unt % 7200 == 0) {
      sleep(4);
      relatorio_print(ptotal, "db_report.txt", "db_exam.txt", q_patients, unt);
    }
  }

  return 0;
}
