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
#include "app.h"    

int main(void) 
{
    App_RunMenu();
    return 0;
}
