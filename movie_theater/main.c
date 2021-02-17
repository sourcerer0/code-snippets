#include "personal_regist.h"
#include "theater_entry.h"

void ChangeClientAge(Client *person, int age){
    person->age = age;
}

bool VerifyClientAge(Client *person, int age_compare){
    if (person->age < age_compare){
        printf("Ops! Younger than expected!\n");
        return true;
    }
    else { return false; }
}

void SetClient(Client *person, char name[MAX], int ID, int age, float deposit){
    strcpy(person->name, name);
    person->age = age; 
    person->ID =  ID;
    person->cash = deposit;
}

void MakeDeposit(Client *person, float deposit){
    person->cash += deposit;
}

bool MakePayment(Client *person, float payment_value){
    float remain = person->cash - payment_value;
    if (remain < 0){
        printf("Payment denied!\n");
        return false;
    }
    else{
        person->cash -= payment_value;
        printf("%.2f payment approved! --- %.2f still remaining!\n", payment_value, remain);
        return true;
    }
}

void SetTheaterChairs(MovTheater *room, float price){
    room->price_per_chair = price;

    for (int x=0; x < STANDARD; x++){
        for (int y=0; y < STANDARD; y++){
            room->arrange[x][y] = 0;
        }
    }
}

void SetTheaterInfo(MovTheater *room, int age, char movie[25]){
    room->minimum_age = age;
    strcpy(room->movie, movie);
}

void ReserveChair(MovTheater *room, Client *person, int x_pos, int y_pos){
    int chair = room->arrange[x_pos][y_pos];
    switch (chair){
        case 0:{
            bool younger = VerifyClientAge(&(*person), room->minimum_age);
            if (younger == true){
                printf("I'm sorry, the client is underage!\nOperation cancelled!\n");
                return;
            }
            else {
                bool payment_aproved = MakePayment(&(*person), room->price_per_chair);
                if (payment_aproved){
                    room->arrange[x_pos][y_pos] = person->ID;
                    return;
                }
                else {
                    printf("This client is broke!\n");
                    return;
                }
            }
        }
        default:{
            printf("Chair already occupied!\nTry another one!\n");
            break;
        }
    }
}

int main(){
    // IMPLEMENTATION EXAMPLE
    //************************************

    int ID_ref = 1;

    Client John;
    SetClient(&John, "John Connor",ID_ref, 25, 0);
    MakeDeposit(&John, 100);
    printf("John's:\nName: %s\nID >> %d\nAge >> %d\nCash >> %.2f\n", John.name, John.ID, John.age, John.cash);

    MovTheater CineSystem;
    SetTheaterChairs(&CineSystem, 50);
    SetTheaterInfo(&CineSystem, 24, "The Boys");

    MakePayment(&John, 50);
    MakePayment(&John, 50);
    MakePayment(&John, 50);

    ReserveChair(&CineSystem, &John, 4, 4);
    ReserveChair(&CineSystem, &John, 3, 3);
    ReserveChair(&CineSystem, &John, 2, 2);
    ReserveChair(&CineSystem, &John, 2, 2);
    ReserveChair(&CineSystem, &John, 1, 1);

    return 0;
}
