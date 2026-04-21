#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ================= CONSTANTS =================
#define MAX_USERS 100
#define MAX_HISTORY 100

char history[MAX_HISTORY][100];
int historyCount = 0;

// ================= STRUCTURE =================
// Structure to store user details and wallet

struct User {
    char name[50];
    char password[20];
    int notes[6]; // 10,20,50,100,200,500
};

// ================= GLOBAL DATA =================

struct User users[MAX_USERS];
int userCount = 0;
int currentUser = -1;

// ================= UTILITY FUNCTIONS =================

// Prints a separator line

void printLine() {
    printf("====================================\n");
}

// Prints system header

void printHeader() {
    printLine();
    printf("     CASH MANAGEMENT SYSTEM\n");
    printLine();
}

// ================= MENU =================

// Displays menu options

void menu() {
    printHeader();

    printf("1. Create User\n");
    printf("2. Switch User\n");

    printf("3. Add Money\n");
    printf("4. Display Balance\n");
    printf("5. Check Exact Change\n");
    printf("6. Give Change\n");
    printf("7. Save to File\n");
    printf("8. Load from File\n");
    printf("9. Delete User\n");
    printf("10.Show Transaction History\n");
    printf("11.Reset Wallet\n");

    printf("12.Exit\n");

        

    printLine();
    printf("Enter choice: ");
}

// ================= USER MANAGEMENT =================

// Create a new user

void createUser() {
    if(userCount >= MAX_USERS) {
        printf("User limit reached!\n");
        return;
    }

    printf("Enter user name: ");
    scanf("%s", users[userCount].name);

    printf("Set password(20 characters allowed): ");
    scanf("%s",&users[userCount].password);

    // Initialize wallet to zero

    for(int i=0;i<6;i++) {
        users[userCount].notes[i] = 0;
    }

    currentUser = userCount;
    userCount++;

    printf("User created and selected!\n");
}

// Switch between users

void switchUser() {
    if(userCount == 0) {
        printf("No users available!\n");
        return;
    }

    printf("\nUsers List:\n");

    for(int i=0;i<userCount;i++) {
        printf("%d. %s\n", i, users[i].name);
    }

    printf("Select user: ");
    scanf("%d", &currentUser);

    if(currentUser < 0 || currentUser >= userCount) {
        printf("Invalid selection!\n");
        currentUser = -1;
    } else {
        printf("Switched to %s\n", users[currentUser].name);
    }
}

//Delete user

void deleteUser(){
    if(userCount == 0){
        printf("No users to delete!\n");
        return;
    }

    printf("\nUsers List:\n");

    for(int i=0;i<userCount;i++){
        printf("%d. %s\n",i,users[i].name);
    }

    int index;
    printf("Enter user index to delete: ");
    scanf("%d",&index);

    if(index < 0 || index >= userCount){
        printf("Invalid index!\n");
        return;
    }

    //Shift users

    for(int i=index; i<userCount-1;i++){
        users[i] = users[i+1];
    }

    userCount--;

    if(userCount == 0){
        currentUser = -1;
    }else if(currentUser == index){
        currentUser = -1;
        printf("Deleted current user.Select another.\n");
    }else if(currentUser > index){
        currentUser--;
    }

    addHistory("User deleted");
    printf("User deleted successfully!\n");

}

void addHistory(char msg[]){
if(historyCount < MAX_HISTORY){
    strcpy(history[historyCount],msg);
    historyCount++;
    }
}

//display history

void showHistory(){
if(historyCount == 0){
    printf("No Transactions yet!\n");
return;
}

printf("\nTransaction History: \n");

for(int i =0;i<historyCount;i++){
printf("%d. %s\n",i+1, history[i]);
    }
}

//check password

int checkPassword(){
    char input[20];

    printf("Enter password: ");
    scanf("%s",&input);

    if(strcmp(input, users[currentUser].password) == 0){
        return 1; //correct
    }else{
        printf("Incorrect password!\n");
        return 0; //wrong
    }
}

// ================= CALCULATE TOTAL =================

// Calculates total money in wallet

int calculateTotal(struct User *u) {
    int values[6] = {10,20,50,100,200,500};
    int total = 0;

    for(int i=0;i<6;i++) {
        total += u->notes[i] * values[i];
    }

    return total;
}

// ================= ADD MONEY =================

// Adds money to selected user

void addMoney() {
    if(currentUser == -1) {
        printf("No user selected!\n");
        return;
    }

    if(!checkPassword()){
        return; // protection
    }

    int values[6] = {10,20,50,100,200,500};
    int input;

    printf("\nEnter number of notes:\n");

    for(int i=0;i<6;i++) {
        printf("Rs.%d: ", values[i]);
        scanf("%d", &input);

        if(input < 0) {
            printf("Invalid input! Skipping....\n");
            continue;
        }

        users[currentUser].notes[i] += input;
    }
    addHistory("Money added");
    printf("Money added successfully!\n");
}

// ================= DISPLAY =================

// Displays wallet details

void displayBalance() {
    if(currentUser == -1) {
        printf("No user selected!\n");
        return;
    }

    if(!checkPassword()){
        return;
    }

    int values[6] = {10,20,50,100,200,500};

    printHeader();
    printf("User: %s\n", users[currentUser].name);
    printLine();

    printf("Denomination   Count   Value\n");
    printLine();

    for(int i=0;i<6;i++) {
        printf("Rs.%-10d %-7d %-7d\n",
               values[i],
               users[currentUser].notes[i],
               users[currentUser].notes[i]*values[i]);
    }

    printLine();
    printf("Total Balance: Rs.%d\n",
           calculateTotal(&users[currentUser]));
}

// ================= CHECK CHANGE =================

// Checks if exact change is possible

void checkChange() {
    if(currentUser == -1) {
        printf("No user selected!\n");
        return;
    }

    if(!checkPassword()){
        return;
    }

    int amount;
    printf("Enter amount: ");
    scanf("%d",&amount);

    if(amount <= 0 ) {
        printf("Invalid amount!\n");
        return;
    }

    int values[6] = {10,20,50,100,200,500};

    for(int i=5;i>=0;i--) {
        int required = amount / values[i];

        if(required > users[currentUser].notes[i]) {
            required = users[currentUser].notes[i];
        }

        amount -= required * values[i];
    }

    if(amount == 0)
        printf("Exact change possible\n");
    else
        printf("Exact change NOT possible\n");
}

// ================= GIVE CHANGE =================

// Gives change and updates wallet

void giveChange() {
    if(currentUser == -1) {
        printf("No user selected!\n");
        return;
    }

    if(!checkPassword()){
        return;
    }

    int amount;
    int values[6] = {10,20,50,100,200,500};
    int used[6] = {0};

    printf("Enter amount: ");
    scanf("%d",&amount);

    if(amount <= 0 || amount % 10 != 0) {
        printf("Invalid amount!\n");
        return;
    }

    int temp = amount;

    
    for(int i=5;i>=0;i--) {
        int required = temp / values[i];

        if(required > users[currentUser].notes[i])
            required = users[currentUser].notes[i];

        used[i] = required;
        temp -= required * values[i];
    }

    if(temp != 0) {
        printf("Cannot give exact change!\n");
        return;
    }

    // Deduct notes
    for(int i=0;i<6;i++) {
        users[currentUser].notes[i] -= used[i];
    }

    printHeader();
    printf("CHANGE GIVEN:\n");

    for(int i=5;i>=0;i--) {
        if(used[i] > 0) {
            printf("Rs.%d x %d\n", values[i], used[i]);
        }
    }

    addHistory("Change given");
    printf("Transaction Successful!\n");
}

void resetWallet(){
    if(currentUser == -1){
    printf("No user selected!\n");
    return;
    }

for(int i=0;i<6;i++){
    users[currentUser].notes = 0;
}

printf("Wallet reset to zero!\n");

addHistory("Wallet reset");
}

// ================= SAVE =================

// Saves all users data to file

void saveToFile() {
    FILE *fp = fopen("wallet.txt","w");

    if(fp == NULL) {
        printf("File error!\n");
        return;
    }

    fprintf(fp,"%d\n", userCount);

    for(int i=0;i<userCount;i++) {
        fprintf(fp,"%s ", users[i].name);

        for(int j=0;j<6;j++) {
            fprintf(fp,"%d ", users[i].notes[j]);
        }

        fprintf(fp,"\n");
    }

    fclose(fp);
    printf("Saved successfully!\n");
}

// ================= LOAD =================

// Loads users data from file

void loadFromFile() {
    FILE *fp = fopen("wallet.txt","r");

    if(fp == NULL) {
        printf("No saved data found!\n");
        return;
    }

    fscanf(fp,"%d",&userCount);

    for(int i=0;i<userCount;i++) {
        fscanf(fp,"%s", users[i].name);

        for(int j=0;j<6;j++) {
            fscanf(fp,"%d",&users[i].notes[j]);
        }
    }

    fclose(fp);
    printf("Loaded successfully!\n");
}

// ================= MAIN =================

int main() {
    int choice;

    while(1) {
        menu();
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                createUser();
                break;

            case 2:
                switchUser();
                break;

            case 3:
                addMoney();
                break;

            case 4:
                displayBalance();
                break;

            case 5:
                checkChange();
                break;

            case 6:
                giveChange();
                break;

            case 7:
                saveToFile();
                break;

            case 8:
                loadFromFile();
                break;

            case 9:
                deleteUser();
                break;

            case 10:
                showHistory();
                break;

            case 11:
                resetWallet();
                break;
            
            case 12:
                printf("Thank You.Exiting....\n");
                exit(0);
 
            default:
             printf("Invalid choice!\n");

        }
    }

    return 0;
}
