#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/user.h"
#include "../include/utils.h"

// Helpers to indicate test status
#define TEST_PASS(msg) printf("\x1b[32m✔ %s\x1b[0m\n", msg)
#define TEST_FAIL(msg) printf("\x1b[31m✖ %s\x1b[0m\n", msg)

void reset_users(void) {
    User* users = GetUserList();
    for (int i = 0; i < MAX_USERS; i++) {
        memset(users[i].username, 0, CREDENTIAL_LENGTH);
        memset(users[i].password, 0, CREDENTIAL_LENGTH);
    }

    // Hack: reset count via multiple decrement
    extern void ResetUserCount(void);
    ResetUserCount();  // Add this function in user.c
}

void test_register_normal() {
    reset_users();

    User* users = GetUserList();
    strcpy(users[0].username, "u1");
    strcpy(users[0].password, "p1");
    IncrementUserCount();

    strcpy(users[1].username, "u2");
    strcpy(users[1].password, "p2");
    IncrementUserCount();

    if (GetUserCount() == 2) TEST_PASS("Register normal increment");
    else TEST_FAIL("Register normal failed");
}

void test_register_limit() {
    reset_users();

    User* users = GetUserList();
    for (int i = 0; i < MAX_USERS; i++) {
        strcpy(users[i].username, "usr");
        strcpy(users[i].password, "pwd");
        IncrementUserCount();
    }

    RegisterUser(); // Should not register; limit reached

    if (GetUserCount() == MAX_USERS)
        TEST_PASS("Register at limit does not overflow");
    else
        TEST_FAIL("Register limit overflowed");
}

void test_login_success() {
    reset_users();

    User* users = GetUserList();
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "root");
    IncrementUserCount();

    int idx = LoginUserStub("admin", "root");
    if (idx == 0) TEST_PASS("LoginUserStub valid credentials");
    else TEST_FAIL("LoginUserStub valid credentials failed");
}

void test_login_fail() {
    reset_users();

    User* users = GetUserList();
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "root");
    IncrementUserCount();

    int idx = LoginUserStub("admin", "wrong");
    if (idx == -1) TEST_PASS("LoginUserStub wrong password");
    else TEST_FAIL("LoginUserStub wrong password failed");
}

void test_fix_fgets_input() {
    char buf[] = "hello\n";
    fix_fgets_input(buf);
    if (strcmp(buf, "hello") == 0)
        TEST_PASS("fix_fgets_input strips newline");
    else
        TEST_FAIL("fix_fgets_input failed stripping");
}

int main(void) {
    printf("Running tests...\n\n");
    test_fix_fgets_input();
    test_register_normal();
    test_register_limit();
    test_login_success();
    test_login_fail();
    printf("\nTests complete.\n");
    return 0;
}
