#ifndef USER_H
#define USER_H

#define MAX_USERS           (10)
#define CREDENTIAL_LENGTH   (30)

typedef struct {
    char username[CREDENTIAL_LENGTH];
    char password[CREDENTIAL_LENGTH];
} User;

// extern User user[MAX_USERS];
// extern char userCount;

User* GetUserList(void);
char GetUserCount(void);
void IncrementUserCount(void);
void ResetUserCount(void);

int LoginUser(void);
void RegisterUser(void);
int LoginUserStub(const char *username, const char *password);


#endif // USER_H
