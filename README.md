# 🔐 User Management System in C

[![Build](https://img.shields.io/badge/build-passing-brightgreen)](#)
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![Language](https://img.shields.io/badge/language-C-blue.svg)](#)

---

A modular User Management System written in C. This terminal-based application demonstrates clean code practices, interactive CLI handling, and test-driven design—all written with professional-grade architecture.

---

## 🚀 Features

📝 Register new users (username + password)

🔐 Login with secure terminal password input

💾 Stores up to 10 users in memory

🧱 Fully modular (.c + .h file separation)

✅ Unit-tested login and input logic

🔧 Makefile with run, test, clean, and full targets

---

## 📋 Requirements

GCC Compiler 4.8 or newer

Make utility

Linux/macOS/WSL

POSIX terminal support (for password masking)

---

## 📂 Project Structure

<pre> 
User_Management_System/ 
├── 📁 build/ # 🏗️ Compiled objects & executables 
│ ├── user_mgmt # Binary 
│ └── user_tests # Unit test binary 
├── 📁 include/ # 📋 Header files 
│ ├── app.h 
│ ├── user.h 
│ └── utils.h 
├── 📁 src/ # 💻 Source files 
│ ├── app.c 
│ ├── main.c 
│ ├── user.c 
│ └── utils.c 
├── 📁 test/ # 🧪 Unit test file 
│ └── user_tests.c 
├── Makefile # ⚙️ Build automation 
├── LICENSE # 📜 MIT License 
└── README.md # 📖 This file 
</pre>

---

```bash
# 📥 Clone the repository
git clone https://github.com/rahulbari717/User_Management_System.git
cd User_Management_System

# 🧹 Clean previous builds
make clean

# 🔨 Compile the project
make

# 🚀 Run the program
make run

# 🧪 Run unit tests
make test
```
---
## 🔐 How It Works
User launches the app using make run

Main menu allows:

Registering a new user

Logging in as existing user

Gracefully exiting

Passwords are entered securely (input masked in terminal)

Basic validation and feedback is provided after each action

System supports up to 10 users stored in RAM

---

## 🧪 Unit Tests

Tested functionality includes:

✅ Credential matching (LoginUserStub)

✅ Registration limit enforcement

✅ Input trimming via fix_fgets_input()

Results are printed with ✔️ for success and ❌ for failure.

---

## 🎯 Future Roadmap

🔐 Password hashing

👥 Role-based user support (Admin/User)

---

## 📜 License
This project is open-sourced under the MIT License. See LICENSE for details.

---

## 🙌 Acknowledgements
Built with ❤️ in a Linux terminal
Created for learning, sharing, and writing clean embedded C code ✨
Designed to demonstrate real-world programming concepts in C

---

## DM me if you have any questions! 💬

[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/rahul-bari-embeddeddeveloper/)
[![Email](https://img.shields.io/badge/Email-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:rahulbari717@gmail.com)
[![GitHub](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/rahulbari717)

---
