/*Copyright (c) 2024   SNUT �෽Բ202218084035 أ����202214024085 ���Ӻ�202218084036  All rights reserved*/

#include"employee_data.h"
#include"user_data.h"

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    readUserFromFile(users, userCount);

    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0; // ��Ա����
    readFromFile(employees, employeeCount);
    // ��ʼ������ȡ�ļ������ļ����ݱ���

    char choice;
    bool loggedIn = false; // ����û��Ƿ��ѵ�¼
    string currentUsername; // ��ǰ��¼���û���

    do {
        cout << "��ѡ�������" << endl;
        cout << "1. ��¼" << endl;
        cout << "2. ע�����˺�" << endl;
        cout << "3. �˳�" << endl;
        cout << "ѡ��: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1':
            loggedIn = login(users, userCount, currentUsername);
            if (loggedIn) {
                cout << "��¼�ɹ���" << endl;
            }
            else {
                cout << "��¼ʧ�ܣ������û��������롣" << endl;
            }
            break;
        case '2':
            registerUser(users, userCount);
            break;
        case '3':
            cout << "�����˳��ɹ�!" << endl;
            break;
        default:
            cout << "������Ϸ���ѡ�" << endl;
        }

        // ����û���¼�ɹ�����ʾԱ������ϵͳѡ��
        if (loggedIn) {
            char flag;
            do {

                displayMenu();
                cout << "��ѡ�����ַ�Χ�ڵ�ѡ��" << endl;
                cout << "��������ӡ����¡�ɾ�������������˳�ǰѡ��6.�����ļ�����ȷ���ɹ����档��:" << endl;
                cin >> flag;
                cin.ignore();

                switch (flag) {
                case '1':
                    addEmployee(employees, employeeCount);
                    break;
                case '2':
                    updateEmployee(employees, employeeCount);
                    break;
                case '3':
                    deleteEmployee(employees, employeeCount);
                    break;
                case '4':
                    searchEmployeeById(employees, employeeCount);
                    break;
                case '5':
                    searchEmployeeByName(employees, employeeCount);
                    break;
                case '6':
                    saveToFile(employees, employeeCount);
                    break;
                case '7':
                    readFromFile(employees, employeeCount);
                    break;
                case '8':
                    printAllEmployeeInformation(employees, employeeCount);
                    break;
                case '9':
                    changePassword(users, userCount, currentUsername);
                    cout << "�����µ�¼!" << endl;
                    loggedIn = false; // �û������������µ�¼
                    break;
                case '0':
                    cout << "�˳���¼�ɹ�!" << endl;
                    loggedIn = false; // �û��˳���¼
                    break;
                default:
                    cout << "������Ϸ���ѡ�" << endl;
                }
            } while ((flag != '9') && (flag != '0'));
        }
    } while (choice != '3');

    return 0;
}
