#include "include/exam.h"
#include "include/patient.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 1) ------- Criar função genérica para gravar os pacientes, 
//-------- exames ou relatórios em seus respectivos arquivos --- FEITO!

// 2) ------- Criar função que retorna uma das doenças da tabela, 
// ------- de acordo com as chances de cada uma acontecer (em struct) - nome e gravidade
// ----------- Verificar o arquivo exam.c ---- FEITO!

// 3) ------ Criar função que organiza fila dos exames de acordo com prioridades.
//-------- Adicionando a partir da verificação do grau da última. ----- FEITO! =)

// 4) ------ Pesquisar sobre função sleep() mencionada no arquivo de descrição do trabalho.
// --------É necessário printar relatórios sobre o que acontece no hospital
// --------- Talvez criar um arquivo com um relatório geral do hospital.

// 5) ------ Criar o XRMachineManager. Provavelmente em TAD ----- Fazendo...

void create_empty_files(const char* filename) {

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }
    fclose(file);
}


int main()
{
    // Criar os 3 arquivos já no início em branco

    // iniciar contadores

    // Possibilidade de surgir um paciente = 20%

    // Se criar paciente, gravar no arquivo. Colocar paciente na fila
   
    // 5 máquinas para fazer os exames com cada uma demorando 10 unidades de tempo

    // Ao terminar, o exame é gerado e gravado no arquivo txt

    // Gravidade de diagnostico 1 - 6, com suas probabilidades de serem gerados
    
    // Fila do laudo de acordo com a gravidade. Maior número, maior prioridade

    // Gerar laudo e gravar no arquivo txt

    // repetir até tempo chegar a 43200




    // RASCUNHO ----------------------------------------------------------------


// FUNÇÃO AUXILIAR
int evento_ocorre(float probabilidade){
    int num_random = rand() % 100; //Gerar número aleatório entre 0 e 99;

    if(num_random < probabilidade * 100){ //0.2 = 20
        return 1; //Evento ocorre;
    }
    else{
        return 0; //Não ocorre;
    }
}



// PRINCIPAL


qPatient *qp = create_qPatient(); //Criar fila de Pacientes


//Iniciar contagem de tempo
void simular_tempo(int total_tempo, int intervalo){
    for (int tempo = 0; tempo < total_tempo; tempo++){
        //Simulação de alguma tarefa a cada unidade de tempo
        if (evento_ocorre(0.2)){
            Patient* p = create_patient(id, *name, timestamp) //Criar paciente
            arq_patient(*patient, *filename); //Inserir no arquivo
            enqueue_qPatient(qp, id, *name, timestamp) //Inserir paciente na fila

        }


        //Espera pelo intervalo de tempo para simular o avanço do tempo
        sleep(intervalo);
    }

    printf("Simulação concluída!\n");
}

}