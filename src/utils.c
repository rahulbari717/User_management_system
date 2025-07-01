#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include "utils.h"
#include "user.h"

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
