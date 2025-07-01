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
#include <unistd.h>
#include <termios.h>

#define MAX_USERS           (10)    // Maximum number of users 10 
#define CREDENTIAL_LENGTH   (30)    // Maximum length of username and password

typedef struct
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
}User;

User user[MAX_USERS];
char userCount = 0;
int user_index; 

void RegisterUser(void);
int LoginUser(void);
void fix_fgets_input(char *);
void input_credentials(char *username, char *password);

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
                    printf("\n Login successful! Welcome, %s! \n", user[user_index].username);
                }else{
                    // User is not logged in
                    printf("\n Login Failed, Invalid username or password.\n");
                }
                break;
            case 3:
                // Exit the program
                printf("\n Exiting Program...\n");
                return 0;
                break;
            default:
                printf("\n Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }
}

void RegisterUser(void)
{
    // Implement your registration logic here
    if (userCount == MAX_USERS) 
    {
        printf("\n Maximum %d of users reached.\n", MAX_USERS);
        return;
    }

    int new_index = userCount;
    printf("Register a new user ..."); 
    fgets(user[new_index].username, CREDENTIAL_LENGTH, stdin); 
    fix_fgets_input(user[new_index].username);
    input_credentials(user[new_index].username, user[new_index].password);
    userCount++;
    printf("\n User Registered Successfully\n");
}

int LoginUser(void)
{
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];


    input_credentials(username,password);

    for (int i = 0; i < userCount; i++) 
    {
        if (strcmp(username, user[i].username) == 0 && 
            strcmp(password, user[i].password) == 0) {
            return i;
        }
    }

    return -1;
}

void fix_fgets_input(char *string)
{
    int index = strcspn(string, "\n");
    string[index] = '\0';    
}

void input_credentials(char *username, char *password)
{
    printf("Enter username: ");
    fgets(username, CREDENTIAL_LENGTH, stdin);
    fix_fgets_input(username);

    printf("Enter Password: ");
    fflush(stdout);
    // Disable terminal echo
    struct termios old_settings, new_settings;
    tcgetattr(STDIN_FILENO, &old_settings);
    new_settings = old_settings;
    new_settings.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
	
    char ch;
    int i = 0;
    
    while ((ch = getchar()) != '\n' && ch != EOF && i < CREDENTIAL_LENGTH - 1) {
        if (ch == '\b' || ch == 127) {
            if (i > 0) {
                i--;
                printf("\b \b");
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
   
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);

    // printf("\n\nFor debuging -%s-%s-\n", username, password);
}
