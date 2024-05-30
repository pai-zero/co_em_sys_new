/*Copyright (c) 2024   SNUT 相方圆202218084035 兀朝阳202214024085 李子涵202218084036  All rights reserved*/

#include <iostream>
#include <fstream> // 包含ifstream、ofstream两类，包含输入输出文件
#include <sstream> // istringstream输入、ostringstream输出 和 stringstream输入输出


const int MAX_USERS = 100; // 最大用户数
const char XOR_KEY_USER = 0x5A; // 用户数据的异或密钥,你可以选择其他值作为异或加密的密钥,十六进制四位数

struct User {
    string username;
    string password;
};// 用户结构体


bool login(User users[], int& userCount, string& loggedInUsername);// 用户登录模块
void registerUser(User users[], int& userCount);// 用户注册模块
void changePassword(User users[], int userCount, const string loggedInUsername);// 用户改密模块
void saveUserToFile(const User users[], int userCount);// 保存模块
void readUserFromFile(User users[], int& userCount);// 读取模块

bool login(User users[], int& userCount, string& loggedInUsername)
{   // 用户登录模块
    string username, password;
    cout << "\n请输入用户名: ";
    cin >> username;

    for (int i = 0; i < userCount; ++i)
    {
        if (users[i].username == username)
        {
            cout << "请输入密码: ";
            cin >> password;

            if (users[i].password == password)
            {
                cout << "登录成功！" << endl;
                loggedInUsername = users[i].username;  // 通过引用参数传递成功登录的用户名
                return true;
            }
            else
            {
                cout << "密码错误，登录失败。" << endl;
                return false;
            }
        }
    }

    cout << "用户不存在，登录失败。" << endl;
    return false;
}


void registerUser(User users[], int& userCount) {
    // 用户注册模块
    User newUser;
    cout << "请输入新的用户名: ";
    cin >> newUser.username;

    // 检查用户名是否已存在
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == newUser.username) {
            cout << "用户名已存在，请选择不同的用户名。" << endl;
            return;
        }
    }

    cout << "请输入密码（六位密码）: ";
    cin >> newUser.password;

    users[userCount++] = newUser;
    saveUserToFile(users, userCount);

    cout << "用户注册成功！" << endl;
}


void changePassword(User users[], int userCount, const string loggedInUsername)
{
    // 用户改密模块
    string newPassword;

    for (int i = 0; i < userCount; ++i)
    {
        if (users[i].username == loggedInUsername)
        {
            cout << "请输入新密码(六位密码): ";
            cin >> newPassword;

            users[i].password = newPassword;

            saveUserToFile(users, userCount); // 修改成功后保存

            cout << "密码修改成功！" << endl;
            return;
        }
    }

    cout << "用户不存在，修改密码失败。" << endl;
}


void readUserFromFile(User users[], int& userCount) {
    // 读取用户模块
    userCount = 0; // 在文件读取之前清除现有数据

    ifstream userFile("User_Data.csv");
    if (!userFile.is_open()) {
        cout << "打开用户数据文件进行读取时出错。" << endl;
        return;
    }

    string line;
    while (getline(userFile, line)) {
        stringstream ss(line);

        getline(ss, users[userCount].username, ',');
        getline(ss, users[userCount].password);

        // 解密用户数据
        for (char& c : users[userCount].username)
            c ^= XOR_KEY_USER;
        for (char& c : users[userCount].password)
            c ^= XOR_KEY_USER;

        userCount++;
    }

    userFile.close();
    cout << "已成功从用户数据文件中读取数据。" << endl;
}

void saveUserToFile(const User users[], int userCount) {
    // 保存用户数据
    ofstream userFile("User_Data.csv");
    if (!userFile.is_open()) {
        cout << "打开用户数据文件进行写入时出错。" << endl;
        return;
    }

    for (int i = 0; i < userCount; ++i) {
        // 加密用户数据
        string encryptedUsername = users[i].username;
        string encryptedPassword = users[i].password;

        for (char& c : encryptedUsername)
            c ^= XOR_KEY_USER;
        for (char& c : encryptedPassword)
            c ^= XOR_KEY_USER;

        userFile << encryptedUsername << "," << encryptedPassword << endl;
    }

    userFile.close();
    cout << "用户数据已成功保存到文件。" << endl;
}
