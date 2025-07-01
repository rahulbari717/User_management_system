// ==========================================
// FILE: main.c
// ==========================================

/**
 * @file main.c
 * @brief Entry point and menu system for the User Management System.
 *
 * @details
 * Implements the command-line user interface, including:
 * - Displaying the main menu
 * - Handling user input and navigation
 * - Calling registration and login functions
 *
 * The program follows clean UI principles to ensure simplicity and usability.
 *
 * ## ✨ Features
 * - 📝 Register: New users can create an account with a username and password
 * - 🔐 Login: Existing users can log in securely
 * - 🚪 Exit: Graceful exit from the program
 * - 💾 Persistent user data stored in a file (e.g., `users.txt`)
 * - 🧱 Modular structure (register.c, login.c, main.c, etc.)
 * - ✅ Input validation and basic error handling
 *
 * @author Rahul B.
 * @date 2025-07-01
 * @version 1.0.0
 */

#include <stdio.h>
#include <string.h>


#define MAX_USERS           (10)    // Maximum number of users 10 
#define CREDENTIAL_LENGTH   (30)    // Maximum length of username and password

typedef struct{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

}User;

User user[MAX_USERS];
char userCount = 0;
int user_index; 

void RegisterUser(void);
int LoginUser(void);
void ExitApplication(void);
void fix_fgets_input(char *);
void input_Password(char *password);

int main(void) 
{
    int choice;
    while (1)
    {
        printf("┌────────────────────────────────────────┐\n");
        printf("│        🔐 USER MANAGEMENT MENU 🔐      |\n");
        printf("├────────────────────────────────────────┤\n");
        printf("│                                        │\n");
        printf("│  1. 📝 Register New Account            │\n");
        printf("│  2. 🔑 Login to Existing Account       │\n");
        printf("│  3. 👋 Exit Application                │\n");
        printf("│                                        │\n");
        printf("└────────────────────────────────────────┘\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);   
        getchar();              //  consume the extra enter key

        switch (choice) {
            case 1:
                // Call registration function
                RegisterUser();
                break;
            case 2:
                // Call login function
                user_index = LoginUser();
                if(user_index >= 0){
                    // User is logged in
                    printf("Login successful! Welcome, %s! \n", user[user_index].username);
                }else{
                    // User is not logged in
                    printf("Login Failed, Invalid username or password.\n");
                }
                break;
            case 3:
                // Exit the program
                printf("Exiting Program...\n");
                return 0;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }
}

void RegisterUser(void){
    // Implement your registration logic here
    if (userCount == MAX_USERS) {
        printf("\n Maximum %d of users reached.\n", MAX_USERS);
        return;
    }

    int new_index = userCount;
    printf("\n Register a new user ..."); 
    printf("\n Enter username: ");
    fgets(user[new_index].username, CREDENTIAL_LENGTH, stdin); 
    fix_fgets_input(user[new_index].username);
    input_Password(user[new_index].password);
    userCount++;
    printf("\n User Registered Successfully\n");
}

int LoginUser(void){
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];

    printf("\n Login to existing account ...");
    printf("\n Enter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);
    input_Password(password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, user[i].username) == 0 && 
            strcmp(password, user[i].password) == 0) {
            return i;
        }
    }




    return -1;
}

void fix_fgets_input(char *string) {
    int index = strcspn(string, "\n");
    string[index] = '\0';    
}

void input_Password(char *password) {
    printf(" Enter Password: ");
    fgets(password, CREDENTIAL_LENGTH, stdin); 
    fix_fgets_input(password);
}