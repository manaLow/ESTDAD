#ifndef EXAM
#define EXAM

#include <time.h>

typedef struct exam Exam;

Exam* create_exam(int id, int patient_id, int rx_id, struct tm *time);
void destroy_exam(Exam *exam);
int get_exam_id(Exam *exam);
int get_exam_patient_id(Exam *exam);
int get_exam_rx_id(Exam *exam);
struct tm* get_exam_time(Exam *exam);

#endif