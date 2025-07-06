#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

int randomImg1();
int randomImg2(int image1);
int randomImg3(int image2);
void cekbalance(int balanceAll);
std::string signinPage(std::string& username, std::string password, std::string& name, int& balanceAll);
std::string signupPage(std::string username, std::string password, std::string name, int age);
void updatebalance(const std::string& username, int newbalance);

int main () {
    srand(time(0));

    int image1, image2, image3;
    int selectMenu;
    char selectPlay;
    int balancePlay;
    int balanceAll = 0;
    int deposit;
    int withdrawl;
    int loginMenu;
    int age;
    std::string username, password, name;

    std::cout << "┌─────────────────────────────────────────────────┐\n";
    std::cout << "| Welcome to my randomized reward game simulation |\n";
    std::cout << "|=================================================|\n";
    std::cout << "| 1. Sign in (If you have an account!)            |\n";
    std::cout << "| 2. Sign up (If you don't have an account!)      |\n";
    std::cout << "| 3. To cancel                                    |\n";
    std::cout << "└─────────────────────────────────────────────────┘\n";
    std::cout << "Select menu: ";
    std::cin >> loginMenu;

    if (loginMenu == 1){
        name = signinPage(username, password, name, balanceAll);
        if (name == "") return 0;
    }
    else if (loginMenu == 2){
        name = signupPage(username, password, name, age);
    }
    else if (loginMenu == 3){
        std::cout << "Thanks for visiting our game!";
        return 0;
    }
    else {
        std::cout << "Input a valid option!";
    }

    do {
        std::cout << "Welcome to my randomized reward game simulation, " << name << "!" << '\n';
        std::cout << "===============================================\n";
        std::cout << "1. Play\n2. Deposit\n3. Withdrawl\n4. My balance\n5. Leave\n";
        std::cout << "Select menu (1 - 5): ";
        std::cin >> selectMenu;

        switch (selectMenu) {
        case 1:
            randomImg1();
            randomImg2(image1);
            randomImg3(image2);

            std::cout << "Press 'y' to play, and 'n' to cancel: ";
            std::cin >> selectPlay;
            if (selectPlay == 'y' || selectPlay == 'Y'){
                std::cout << "Input your balance you want to spend: ";
                std::cin >> balancePlay;

                if (balancePlay > balanceAll) {
                    std::cout << "Insufficient balance!\n";
                    std::cout << '\n';
                    break;
                }
                else if (balancePlay <= balanceAll) {
                    balanceAll -= balancePlay;
                    int var1 = randomImg1();
                    int var2 = randomImg2(image1);
                    int var3 = randomImg3(image2);
                    std::cout << var1 << ' ' << var2 << ' ' << var3  << '\n';

                    if (var1 == 1 && var2 == 1 && var3 == 1){
                        std::cout << "Great! You received a reward of Rp." << balancePlay * 10 << '\n' << '\n';
                        balanceAll += balancePlay * 10;
                        updatebalance(username, balanceAll);
                    }
                    else if (var1 == 2 && var2 == 2 && var3 == 2){
                        std::cout << "Great! You received a reward of Rp." << balancePlay * 5 << '\n' << '\n';
                        balanceAll += balancePlay * 5;
                        updatebalance(username, balanceAll);
                    }
                    else if (var1 == 3 && var2 == 3 && var3 == 3){
                        std::cout << "Great! You received a reward of Rp." << balancePlay * 2.5 << '\n' << '\n';
                        balanceAll += balancePlay * 2.5;
                        updatebalance(username, balanceAll);
                    }
                    else if (var1 == 4 && var2 == 4 && var3 == 4){
                        std::cout << "Great! You received a reward of Rp." << balancePlay * .5 << '\n' << '\n';
                        balanceAll += balancePlay * .5;
                        updatebalance(username, balanceAll);
                    }
                    else if(var1 == 5 && var2 == 5 && var3 == 5){
                        std::cout << "Great! You received a reward of Rp." << balancePlay * .25 << '\n' << '\n';
                        balanceAll += balancePlay * .25;
                        updatebalance(username, balanceAll);
                    }
                    else {
                        std::cout << "No reward this time, try again!\n";
                        std::cout << '\n';
                    }

                }
                else {
                    std::cout << "Input a valid number!\n";
                    std::cout << '\n';
                }

            }
            else {
                break;
            }
            break;
        case 2:
            std::cout << "Input your balance to deposit: ";
            std::cin >> deposit;
            if (deposit <= 0){
                std::cout << "Input valid amount!\n";
                std::cout << '\n';
            }
            else if (deposit > 0){
                balanceAll += deposit;
                updatebalance(username, balanceAll);
                std::cout << '\n';
            }
            else{
                std::cout << "Input valid amount!\n";
                std::cout << '\n';
            }
            break;
        case 3:
            std::cout << "Enter the amount of money you want to withdraw ";
            std::cin >> withdrawl;
            if (withdrawl > balanceAll){
                std::cout << "Insufficient balance!\n";
                std::cout << '\n';
            }
            else if (withdrawl <= 0){
                std::cout << "Input a valid number!\n";
                std::cout << '\n';
            }
            else if(withdrawl <= balanceAll){
                balanceAll -= withdrawl;
                updatebalance(username, balanceAll);
                std::cout << '\n';
            }
            else{
                std::cout << "Input a valid number!\n";
                std::cout << '\n';
            }
            break;
        case 4:
            cekbalance(balanceAll);
            std::cout << '\n';
            break;
        default:
            break;
        }
    } while (selectMenu != 5);

    return 0;
}

int randomImg1(){
    int angka1 = (rand() % 5) + 1;
    return angka1;
}

int randomImg2(int image1){
    int angka2 = (rand() % 5) + 1;
    return angka2;
}

int randomImg3(int image2){
    int angka3 = (rand() % 5) + 1;
    return angka3;
}
void cekbalance(int balanceAll){
    std::cout << "Your balance is now Rp." << balanceAll << '\n';
}
std::string signinPage(std::string& username, std::string password, std::string& name, int& balanceAll){
    std::cin.ignore();
    std::cout << "Input your username: ";
    std::getline(std::cin, username);
    std::cout << "Input your password: ";
    std::cin >> password;

    std::ifstream file("account.txt");
    std::string line;
    bool loginBerhasil = false;

    if (file.is_open()){
        while(std::getline(file, line)){
            std::stringstream ss(line);
            std::string fileUsername, filePassword, filename, ageStr, balanceStr;
            int fileage, filebalance;

            std::getline(ss, fileUsername, '|');
            std::getline(ss, filePassword, '|');
            std::getline(ss, filename, '|');
            std::getline(ss, ageStr, '|');
            std::getline(ss, balanceStr, '|');

            fileage = std::stoi(ageStr);
            filebalance = std::stoi(balanceStr);
            
            if (username == fileUsername && password == filePassword){
                loginBerhasil = true;
                name = filename;
                balanceAll = filebalance;
                break;
            }
        }
        file.close();
    }
    else {
        std::cout << "Failed to open account file\n";
    }
    if (loginBerhasil) {
        std::cout << "Login success!\n";
    }
    else {
        std::cout << "Login failed! Incorrect username or password!";
        name = "";
    }
    return name;
}
std::string signupPage(std::string username, std::string password, std::string name, int age){
    std::cin.ignore();
    std::cout << "Your name: ";
    std::getline(std::cin, name);
    std::cout << "Your age: ";
    std::cin >> age;

    if (age < 18){
        std::cout << "Minimum age to play is 18!";
    }
    else if (age >= 100){
        std::cout << "You're too old!";
    }
    else if (age >= 18 && age <100){
        std::cin.ignore();
        std::cout << "Create your username: ";
        std::getline(std::cin, username);
        std::cout << "Create your password: ";
        std::cin >> password;

        std::ofstream file("account.txt", std::ios::app);
        if (file.is_open()){
            file << username << "|" << password << "|" << name << "|" << age << '|' << 0 << '\n';
            file.close();
            std::cout << "===============================================\n";
            std::cout << "Your account has been successfully created!\n";
        }
        else {
            std::cout << "===============================================\n";
            std::cout << "Gagal membuka file untuk menyimpan data\n";
        }
    }
    return name;
}
void updatebalance(const std::string& username, int newbalance){
    std::ifstream infile ("account.txt");
    std::ofstream outfile ("temp.txt");
    std::string line;

    while (std::getline(infile, line)){
        std::stringstream ss(line);
        std::string fileUsername, filePassword, filename, ageStr, balanceStr;

        std::getline(ss, fileUsername, '|');
        std::getline(ss, filePassword, '|');
        std::getline(ss, filename, '|');
        std::getline(ss, ageStr, '|');
        std::getline(ss, balanceStr, '|');

        if (fileUsername == username){
            outfile << fileUsername << "|" << filePassword << "|" << filename << "|" << ageStr << '|' << newbalance << '\n';
        }
        else {
            outfile << line << '\n';
        }
    }
    infile.close();
    outfile.close();
    std::remove("account.txt");
    std::rename("temp.txt", "account.txt");
}