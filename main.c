#include "include/auxiliar.h"
#include "include/exam.h"
#include "include/patient.h"
#include "include/report.h"
#include "include/XRMachineManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>  


int main()
{

    // iniciar contadores
    int ptotal = 0; // Número total de pacientes 
    int unt = 0; // Unidade de Tempo
    int id_p = 1; 
    int id_l = 0;


    // iniciar filas 
    qPatient* q_patients = create_qPatient();
    qExam* q_exams = create_qExam();

    // Criar arquivos
    create_empty_files("db_patient.txt");
    create_empty_files("db_exam.txt");
    create_empty_files("db_report.txt");

    // Inicializa máquinas e médico
    Machine* aparelhos[5];  // Declaração do array de máquinas
    inicializa_aparelhos(aparelhos);   // Chamada da função para inicializar as máquinas

    Doctor* doutor;  // Declaração da variável do tipo Doctor
    inicia_atendimento(doutor);  // Chamada da função para iniciar o atendimento

    while (unt < 43200){

        srand(time(NULL)); // Seed pra criar número aleatório toda vez
        double patient_chance = (double)rand() / RAND_MAX; // numero aletório entre 0 e 1

        if (patient_chance <= 0.2){
            char* n = random_name();
            Patient* patient = create_patient(id_p, n, unt);
            enqueue_qPatient(q_patients,patient);
            arq_patient(patient,"db_patient.txt");
            ptotal++;
        }

        atualiza_aparelhos(aparelhos, q_exams, unt);
        aloca_paciente(aparelhos, q_patients);
        atualiza_atendimento(doutor, unt,id_l++);
        aloca_atendimento(doutor, q_exams);
        
        unt++;

        if(unt % 7200 == 0){
            sleep(4);
            relatorio_print(ptotal, "db_report.txt", "db_exam.txt", q_patients);
        }
    }

}
