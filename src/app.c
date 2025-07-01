#include <stdio.h>
#include <stdlib.h>  // <-- required for exit()
#include "user.h"
#include "app.h"

static void App_DisplayMenu(void) {
    printf("┌────────────────────────────────────────┐\n");
    printf("│        🔐 USER MANAGEMENT MENU 🔐      │\n");
    printf("├────────────────────────────────────────┤\n");
    printf("│                                        │\n");
    printf("│  1. 📝 Register New Account            │\n");
    printf("│  2. 🔑 Login to Existing Account       │\n");
    printf("│  3. 👋 Exit Application                │\n");
    printf("│                                        │\n");
    printf("└────────────────────────────────────────┘\n");
}

static void App_HandleUserChoice(void) {
    int choice;
    int user_index;

    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);
    getchar(); // consume newline

    switch (choice) {
        case 1:
            RegisterUser();
            break;
        case 2:
            user_index = LoginUser();
            if (user_index >= 0) {
                printf("\n Login successful! Welcome, %s! \n", GetUserList()[user_index].username);
            } else {
                printf("\n Login Failed, Invalid username or password.\n");
            }
            break;
        case 3:
            printf("\n Exiting Program...\n");
            exit(0);
        default:
            printf("\n Invalid choice. Please enter a number between 1 and 3.\n");
    }
}

void App_RunMenu(void) {
    while (1) {
        App_DisplayMenu();
        App_HandleUserChoice();
    }
}
