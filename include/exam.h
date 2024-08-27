#ifndef EXAM
#define EXAM

// ---------------------------- STRUCT ----------------------------

typedef struct exam Exam;
typedef struct qExam qExam;
typedef struct qnExam qnExam;
typedef struct condition_IA Condition;

Exam *create_exam(int id, int patient_id, int rx_id, Condition* condition, int timestamp); // Criar exame 
Condition* get_random_condition(); // Retorna uma condição aleatória
qExam* create_qExam(); // Criar fila vazia de exames;
int fila_vazia_exam (qExam* q); //V erificar se a fila de exames está vazia;
void enqueue_qExam(qExam* q, Exam* exam); //Inserir exame na fila de acordo com a prioridade;
Exam* dqueue_qExam(qExam* q); // Retirar exame da fila;
void free_qExam(qExam* q); // Liberar memória de uma fila de exames;
void arq_exam(Exam* exam, const char* filename); // Arquiva exame no banco de dados

#endif