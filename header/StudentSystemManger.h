#include <stdio.h>
#include <stdlib.h>


typedef struct _Student
{
    int stuNum;
    char name[20];
    int score;
} Student;

typedef struct _Node
{
    Student stu;
    struct _Node* next;
} Node;

void Welcome();

void InputStudent(Node *head);

void PrintStudent(Node *head);

void DeleteStudent(Node *head);

void CountStudent(Node *head);

void ReviseStudent(Node *head);

void SortScore(Node* head);

void SaveStdent(Node *head);

void LoadStudent(Node *head);
