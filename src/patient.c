// Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/patient.h"

// Estrutura
struct patient {
  int id;
  char* name;
  struct tm* birthdate;
} patient;

// Função para alocar memória e inicializar um paciente
Patient *create_patient(int id, const char *name, struct tm *birthdate){
    // Alocação de memória
    Patient* new_patient = (Patient *)malloc(sizeof(Patient));
    // Verifica se alocou corretamente
    if (new_patient == NULL)
    {
        printf("Erro ao alocar memória para novo paciente.\n");
        return NULL;
    }

    // Inicializa variáveis
    new_patient -> id = id;
    new_patient -> name = strdup(name);
    // Verificando se alocação e inicialização deu certo
    if (new_patient->name == NULL){
        printf("Erro ao alocar memória para o nome do paciente.\n");
        free(new_patient);
        return NULL;
    }

    new_patient -> birthdate = (struct tm*)malloc(sizeof(struct tm));
    // Verificando se alocação e inicialização deu certo
    if (new_patient->birthdate == NULL){
        printf("Erro ao alocar memória para a data de nascimento do paciente.\n");
        free(new_patient->name);
        free(new_patient);
        return NULL;
    }

    *(new_patient->birthdate) = *birthdate;

    return new_patient;
}
// Função para liberar memória de um cadastro de paciente
void destroy_patient(Patient* patient){
    // Verificando se o paciente existe (tem alguma memória alocada já)
    if (patient != NULL){

        if (patient->name != NULL){
            free(patient -> name);
        }

        if (patient->birthdate != NULL){
            free(patient -> birthdate);
        }

        free(patient);
    }
}
// Função para retornar a id de um paciente
int get_patient_id(Patient* patient){
    // Verificando se o ponteiro passado aponta para um paciente
    if (patient != NULL){
        return patient->id;
    }
    else{
        printf("Erro! O paciente não existe.\n");
        return -1;
    }
}
// Função para retornar o nome de um paciente
const char *get_patient_name(Patient* patient){
    if (patient != NULL){
        return patient->name;
    }
    else{
        printf("Erro! O paciente não existe.\n");
        return NULL;
    }
}

// Função para retornar a data de nascimento de um paciente
struct tm* get_patient_birthdate(Patient *patient){
    if (patient != NULL){
        return patient->birthdate;
    }
    else{
        printf("Erro! O paciente não existe.\n");
        return NULL;
    }
}
