/*Copyright (c) 2024   SNUT �෽Բ202218084035 أ����202214024085 ���Ӻ�202218084036  All rights reserved*/

#include <iostream>
#include <fstream> // ����ifstream��ofstream���࣬������������ļ�
#include <sstream> // istringstream���롢ostringstream��� �� stringstream�������


const int MAX_USERS = 100; // ����û���
const char XOR_KEY_USER = 0x5A; // �û����ݵ������Կ,�����ѡ������ֵ��Ϊ�����ܵ���Կ,ʮ��������λ��

struct User {
    string username;
    string password;
};// �û��ṹ��


bool login(User users[], int& userCount, string& loggedInUsername);// �û���¼ģ��
void registerUser(User users[], int& userCount);// �û�ע��ģ��
void changePassword(User users[], int userCount, const string loggedInUsername);// �û�����ģ��
void saveUserToFile(const User users[], int userCount);// ����ģ��
void readUserFromFile(User users[], int& userCount);// ��ȡģ��

bool login(User users[], int& userCount, string& loggedInUsername)
{   // �û���¼ģ��
    string username, password;
    cout << "\n�������û���: ";
    cin >> username;

    for (int i = 0; i < userCount; ++i)
    {
        if (users[i].username == username)
        {
            cout << "����������: ";
            cin >> password;

            if (users[i].password == password)
            {
                cout << "��¼�ɹ���" << endl;
                loggedInUsername = users[i].username;  // ͨ�����ò������ݳɹ���¼���û���
                return true;
            }
            else
            {
                cout << "������󣬵�¼ʧ�ܡ�" << endl;
                return false;
            }
        }
    }

    cout << "�û������ڣ���¼ʧ�ܡ�" << endl;
    return false;
}


void registerUser(User users[], int& userCount) {
    // �û�ע��ģ��
    User newUser;
    cout << "�������µ��û���: ";
    cin >> newUser.username;

    // ����û����Ƿ��Ѵ���
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == newUser.username) {
            cout << "�û����Ѵ��ڣ���ѡ��ͬ���û�����" << endl;
            return;
        }
    }

    cout << "���������루��λ���룩: ";
    cin >> newUser.password;

    users[userCount++] = newUser;
    saveUserToFile(users, userCount);

    cout << "�û�ע��ɹ���" << endl;
}


void changePassword(User users[], int userCount, const string loggedInUsername)
{
    // �û�����ģ��
    string newPassword;

    for (int i = 0; i < userCount; ++i)
    {
        if (users[i].username == loggedInUsername)
        {
            cout << "������������(��λ����): ";
            cin >> newPassword;

            users[i].password = newPassword;

            saveUserToFile(users, userCount); // �޸ĳɹ��󱣴�

            cout << "�����޸ĳɹ���" << endl;
            return;
        }
    }

    cout << "�û������ڣ��޸�����ʧ�ܡ�" << endl;
}


void readUserFromFile(User users[], int& userCount) {
    // ��ȡ�û�ģ��
    userCount = 0; // ���ļ���ȡ֮ǰ�����������

    ifstream userFile("User_Data.csv");
    if (!userFile.is_open()) {
        cout << "���û������ļ����ж�ȡʱ����" << endl;
        return;
    }

    string line;
    while (getline(userFile, line)) {
        stringstream ss(line);

        getline(ss, users[userCount].username, ',');
        getline(ss, users[userCount].password);

        // �����û�����
        for (char& c : users[userCount].username)
            c ^= XOR_KEY_USER;
        for (char& c : users[userCount].password)
            c ^= XOR_KEY_USER;

        userCount++;
    }

    userFile.close();
    cout << "�ѳɹ����û������ļ��ж�ȡ���ݡ�" << endl;
}

void saveUserToFile(const User users[], int userCount) {
    // �����û�����
    ofstream userFile("User_Data.csv");
    if (!userFile.is_open()) {
        cout << "���û������ļ�����д��ʱ����" << endl;
        return;
    }

    for (int i = 0; i < userCount; ++i) {
        // �����û�����
        string encryptedUsername = users[i].username;
        string encryptedPassword = users[i].password;

        for (char& c : encryptedUsername)
            c ^= XOR_KEY_USER;
        for (char& c : encryptedPassword)
            c ^= XOR_KEY_USER;

        userFile << encryptedUsername << "," << encryptedPassword << endl;
    }

    userFile.close();
    cout << "�û������ѳɹ����浽�ļ���" << endl;
}
