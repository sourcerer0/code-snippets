#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef PERSONAL_REGIST_H
#define PERSONAL_REGIST_H

#define MAX 25

typedef struct Pessoa{
    char name[MAX];
    int age;
    int ID;
    float cash;
}Client;

void SetClient(Client *person, char name[MAX], int ID, int age, float deposit);

void ChangeClientAge(Client *person, int age);

bool VerifyClientAge(Client *person, int age_compare);

void MakeDeposit(Client *person, float deposit);

bool MakePayment(Client *person, float payment_value);

#endif
