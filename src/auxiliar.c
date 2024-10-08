#include "../include/auxiliar.h"
#include "../include/patient.h"
#include "../include/exam.h"
#include "../include/report.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// -------------------------------------------------------------------

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

struct qPatient{
    int count;
	qnPatient* front;
	qnPatient* rear;
};

// Definição da estrutura dos nós da fila dos pacientes
struct qnPatient{
	Patient* info;
	qnPatient* next;
};

//Criar arquivos vazios
void create_empty_files(const char* filename) {

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }
    fclose(file);
}

// Gerar nome aleatório
char* random_name() {
    
    const char* nomes[] = {"João", "Maria", "Pedro", "Ana", "Lucas", "Carla", "Zé", "Chico", "Bia", "Tina", "Fulano", "Beltrano", "Ciclano", "Zé Ninguém", "Tio Patinhas"};
    const char* sobrenomes[] = {"Silva", "Santos", "Oliveira", "Souza", "Pereira", "Costa", "Pinto", "Almeida", "Nogueira", "da Silva", "da Esquina", "do Pão", "da Silva Sauro", "do Pé Rachado"};


    // Selecionar aleatoriamente um nome e um sobrenome
    const char* nome = nomes[rand() % (sizeof(nomes) / sizeof(nomes[0]))];
    const char* sobrenome = sobrenomes[rand() % (sizeof(sobrenomes) / sizeof(sobrenomes[0]))];
    
    char* nome_completo = malloc(strlen(nome) + strlen(sobrenome) + 2);
    if (nome_completo == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }
    
    // Concatena o primeiro nome e o sobrenome
    sprintf(nome_completo, "%s %s", nome, sobrenome);
    
    return nome_completo;
}

// -----------------------------------------------------------------------

// Contabilizar quantos laudos ou exames
int contar_laudos(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "ID do Laudo: %*d") == 1) {  // Conta laudos se o nome for db_report
            count++;
        }
    }
    fclose(file);
    return count;
}

int contar_exames(const char* filename){
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "ID do Exame: %*d") == 1) {  // Conta exames se for db_exam
            count++;
        }
    }


    fclose(file);
    return count;
}

// Imprimir relatório geral do hospital
void relatorio_print(int ptotal, const char *report_file, const char *exam_file, qPatient* qp, int unt){ 

    printf(" ---- RELATÓRIO ----\n\n");
    printf("Visitaram o hospital: %d.\n", ptotal);
    printf("Na fila aguardando exame: %d.\n", qp->count);
    int qtd_exam = contar_exames(exam_file);
    int qtd_report = contar_laudos(report_file);
    printf("Realizaram exame: %d\n", qtd_exam); 
    if (qtd_report > 0){
        printf("%d%% receberam laudo.\n", (int)((qtd_report/(double)qtd_exam)*100)); //Modificado
    }
    else{
        printf("0%% receberam laudo.\n");
    }
    double tmd = mean_waiting_time(report_file, exam_file);
    if (tmd > 0.0) {
        printf("Tempo médio de laudo: \n");
        printf("%2.lf", tmd);
        mean_time_by_condition(report_file, exam_file);
    } else {
        printf("Tempo médio de laudo ainda não disponível.\n");
    }

    printf("\n Número de exames feitos depois de %d u.t:", unt);
    printf("\n%d\n\n",qtd_exam);
    

    
}