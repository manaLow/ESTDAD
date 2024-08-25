#ifndef EXAM
#define EXAM

// ---------------------------- STRUCT ----------------------------

typedef struct exam Exam;
typedef struct qExam qExam;
typedef struct qnExam qnExam;
typedef struct condition_IA Condition;

Exam *create_exam(int id, int patient_id, int rx_id, Condition (*get_random_condition)(), int timestamp); // Criar exame
void destroy_exam(Exam *exam); // Destruir exame
int get_exam_id(Exam *exam); // Obter id exame
int get_exam_patient_id(Exam *exam);// Obter id do paciente do exame
int get_exam_rx_id(Exam *exam); //Obter id da máquina do exame
int get_exam_time(Exam *exam); // Obter timestamp do exame
Condition* get_random_condition(); // Retorna uma condição aleatória


// ---------------------------- QUEUE AND NODE ----------------------------

qExam* create_qExam(); // Criar fila vazia de exames;
int fila_vazia_exam (qExam* q); //V erificar se a fila de exames está vazia;
void enqueue_qExam(qExam* q, Exam* exam); //Inserir exame na fila de acordo com a prioridade;
Exam* dqueue_qExam(qExam* q); // Retirar exame da fila;
void free_qExam(qExam* q); // Liberar memória de uma fila de exames;


// ---------------------------- ARQUIVO ----------------------------

void arq_exam(Exam* exam, const char* filename); // Arquiva exame no banco de dados

#endif