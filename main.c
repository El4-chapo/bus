#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define total_seats 14
#define MAX_BUSES 10
#define MAX_NAME_LENGTH 30
#define NUM_ROUTES 10
int seats[total_seats];
int name[MAX_NAME_LENGTH];
int password[MAX_NAME_LENGTH];



void bookSeat(int seatnumber){
   	if (seatnumber >= 1 && seatnumber <= total_seats){
        if (seats[seatnumber - 1] == 0){
            seats[seatnumber - 1] == 1;
            printf("seat %d booked succesfully !\n", seatnumber);
        } else if (seatnumber == 1) {
            printf("seat %d  is already booked.\n", seatnumber);
        } else {
            printf("invalid seat number .Please enter a valid seat number\n");
		}
     }
}

void signUp(){
    FILE *credential;
    credential = fopen("credentials.txt", "a+");

    printf("Create a username: ");
    scanf("%s", name);
    printf("Create a strong password: ");
    scanf("%s", password);

    fprintf(credential, "%s %s\n", name, password);

    fclose(credential);
}

void logIn(FILE *credential){
    char username[MAX_NAME_LENGTH];
    char password[MAX_NAME_LENGTH];
    char fileUsername[MAX_NAME_LENGTH];
    char filePassword[MAX_NAME_LENGTH];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);
    rewind(credential);

    while (fscanf(credential, "%s %s", fileUsername, filePassword) != EOF) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            printf("Log in successful");
            return 1;
        } else {
            printf("Log in unsuccessful");
        }
    }

    //Struct to represent a bus schedule
typedef struct
{
    char departure[MAX_NAME_LENGTH];
    char destination[MAX_NAME_LENGTH];
    int totalSeats;
    int availableSeats;
} BusSchedule;

// An array to represent the bus routes

char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH] =
{
  {"Thika","Nairobi"},
  {"Thika","Muranga"},
  {"Thika","kiambu"},
  {"Nairobi","mlolongo"},
  {"Nairobi","Eldoret"},
  {"Nairobi","kisumu"},
  {"Nairobi","Nakuru"},
  {"Nairobi","Nanyuki"},
  {"Nairobi","Meru"},
  {"Nairobi","Mombasa"},

 };



// function to add a new bus schedule
void addBusSchedule(char busDetails[NUM_ROUTES][2][MAX_NAME_LENGTH])
{
    system("cls");

    char destination[MAX_NAME_LENGTH];
    char departure[MAX_NAME_LENGTH];

    printf("Enter the place of departure: ");
    scanf("%s", departure);
    printf("Enter the destination: ");
    scanf("%s", destination);

    strcpy(busDetails[NUM_ROUTES][0], departure);
    strcpy(busDetails[NUM_ROUTES][1], destination);

    printf("New bus schedule added: %s to %s\n", departure, destination);

}

void cancelOrModifyBus();{
    int busIndex;

    //display available buses for employee to choose
    printf("available Buses:\n");
    for (int i = 0; i < MAX_BUSES; ++i){
        if (strlen(buses[i].source) > 0){
            printf("%d. from %s to%s available seats: %d\n", i + 1,
                   buses[i].source, buses[i].destination, buses[i].availableSeats);
        }
}
    printf("enter the number of bus to cancel or to modify: ");
    scanf("&d", &busIndex);
    if (busIndex >= 1 && busIndex <= MAX_BUSES && strlen(buses[busesIndex - 1].source) > 0){
        int option;
        printf("options:\n");
        printf("1. cancel bus\n");
        printf("2. modify bus\n");
        printf("Enter your choice\n");
        scanf("%d", &option);

        switch (option){
            case 1:
                //cancel the bus
                strcpy(buses[busIndex - 1].source, "");
                strcpy(buses[busIndex - 1].destination, "");
                buses[busIndex - 1].availableSeats = 0;
                printf("Bus canceled successfully.\n");
                break;
            case 2 :
                //modify the bus
                printf("Enter the new number if avaialableSeats: ");
                scanf("%d", &buses[busesIndex - 1].availableSeats);
                printf("Bus modified successfully.\n");
                break;
                default;
                printf("invalid choice.no changes made.\n");
            }
    }else{
    printf("invalid bus number. please enter a number between 1 and %d.\n",MAX_BUSES);
    }
}
int main(){
    FILE *credential;
    credential = fopen("credentials.txt", "a+");
    int choice, seatnumber, choice2;

    printf("Choose an option\n");
    printf("1. Sign up\n");
    printf("2. Login\n");
    printf("3. Exit\n");
    scanf("%d", &choice2);

    if (choice2 == 1){
        signUp();
    } else if (choice2 == 2){
        logIn(credential);
        fclose(credential);
    } else if (choice2 == 3){
        return 0;
    } else {
        printf("Invalid choice");
    }

        while (1){
            printf("bus reservation system\n");
            printf("1. display available seats\n");
            printf("2. book a seat\n");
            printf("3. exit\n");
            printf("enter your choice:");

         scanf("%d", &choice);

         switch (choice){
            case 1:
                displayseats();
                break;
            case 2:
                printf("enter the seat you want to book: ");
                scanf("%d", &seatnumber);
                bookSeat(seatnumber);
                break;
            case 3:
                exit(0);
            default:
                printf("invalid chioce.please enter a valid option\n");
         }
         }


    return 0;
         }

