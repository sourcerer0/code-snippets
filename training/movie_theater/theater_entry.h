#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#ifndef THEATER_ENTRY_H
#define THEATER_ENTRY_H

#include "personal_regist.h"

#define STANDARD 5

typedef struct chair_room{
    int arrange[STANDARD][STANDARD];
    int minimum_age;
    float price_per_chair;
    char movie[25];
}MovTheater;

void SetTheaterChairs(MovTheater *room, float price);

void SetTheaterInfo(MovTheater *room, int age, char movie[25]);

void ReserveChair(MovTheater *room, Client *person, int x_pos, int y_pos);

#endif
