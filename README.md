# 🎯 Randomized Reward Game in C++

A simple text-based simulation game written in C++, featuring:

- 👤 User account system (sign up & login)
- 💰 Deposit, withdraw, and balance check system
- 🎲 Randomized reward mechanism (inspired by slot-style logic)
- 🧠 Local file storage using file handling (account.txt)

## 📂 How it works
All user data is stored in `account.txt` with the following format:
username|password|name|age|balance

## 🛠️ Key Concepts Practiced
- C++ input/output and control flow
- File I/O (reading/writing structured user data)
- Simple user session management
- Randomized outcome simulation
- Project structuring for console applications

## ▶️ How to Run
You can compile and run the program using g++:
```bash
g++ -o reward-game main.cpp 
./reward-game
```
*note : I use IDR currency in this project, fyi 1 USD = Rp.16,192,00. when this project created.

This project avoids any real-world monetary use and is strictly for educational purposes to simulate chance-based mechanics, like those found in randomized reward systems in games!
