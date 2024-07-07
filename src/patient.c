#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "include/patient.h"

struct patient {
  int id;
  char* name;
  struct tm* birthdate;
} patient;


Patient *create_patient(int id, const char *name, struct tm *birthdate){
    Patient* new_patient = (Patient *)malloc(sizeof(Patient));
    if (new_patient == NULL)
    {
        printf("Erro ao alocar memória para novo paciente.\n");
        return NULL;
    }
    new_patient -> id = id;
    new_patient -> name = strdup(name);
    if (new_patient->name == NULL){
        printf("Erro ao alocar memória para o nome do paciente.\n");
        free(new_patient);
        return NULL;
    }

    new_patient -> birthdate = (struct tm*)malloc(sizeof(struct tm));
    if (new_patient->birthdate == NULL){
        printf("Erro ao alocar memória para a data de nascimento do paciente.\n");
        free(new_patient->name);
        free(new_patient);
        return NULL;
    }

    *(new_patient->birthdate) = *birthdate;

    return new_patient;
}

void destroy_patient(Patient* patient){
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

int get_patient_id(Patient* patient){
    if (patient != NULL){
        return patient->id;
    }
    else{
        printf("Erro! O paciente não existe.\n");
        return -1;
    }
}

const char *get_patient_name(Patient* patient){
    if (patient != NULL){
        return patient->name;
    }
    else{
        printf("Erro! O paciente não existe.\n");
        return NULL;
    }
}


struct tm* get_patient_birthdate(Patient *patient){
    if (patient != NULL){
        return patient->birthdate;
    }
    else{
        printf("Erro! O paciente não existe.\n");
        return NULL;
    }
}
