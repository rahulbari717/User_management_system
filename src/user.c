#include <stdio.h>
#include <string.h>
#include "user.h"
#include "utils.h"

static User user[MAX_USERS];
static char userCount = 0;

User* GetUserList(void) {
    return user;
}

void ResetUserCount(void) {
    userCount = 0;
}

char GetUserCount(void) {
    return userCount;
}

void IncrementUserCount(void) {
    if (userCount < MAX_USERS)
        userCount++;
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

int LoginUserStub(const char *username, const char *password) {
    for(int i = 0; i < userCount; i++)
        if(strcmp(username, user[i].username)==0 &&
           strcmp(password, user[i].password)==0)
            return i;
    return -1;
}
