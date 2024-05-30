/*Copyright (c) 2024   SNUT 相方圆202218084035 兀朝阳202214024085 李子涵202218084036  All rights reserved*/

#include"employee_data.h"
#include"user_data.h"

int main() {
    User users[MAX_USERS];
    int userCount = 0;
    readUserFromFile(users, userCount);

    Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0; // 总员工数
    readFromFile(employees, employeeCount);
    // 初始化，读取文件，将文件数据保存

    char choice;
    bool loggedIn = false; // 标记用户是否已登录
    string currentUsername; // 当前登录的用户名

    do {
        cout << "请选择操作：" << endl;
        cout << "1. 登录" << endl;
        cout << "2. 注册新账号" << endl;
        cout << "3. 退出" << endl;
        cout << "选择: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case '1':
            loggedIn = login(users, userCount, currentUsername);
            if (loggedIn) {
                cout << "登录成功！" << endl;
            }
            else {
                cout << "登录失败，请检查用户名和密码。" << endl;
            }
            break;
        case '2':
            registerUser(users, userCount);
            break;
        case '3':
            cout << "程序退出成功!" << endl;
            break;
        default:
            cout << "请输入合法的选项。" << endl;
        }

        // 如果用户登录成功，显示员工管理系统选项
        if (loggedIn) {
            char flag;
            do {

                displayMenu();
                cout << "请选择数字范围内的选项" << endl;
                cout << "（对于添加、更新、删除操作，请在退出前选择“6.保存文件”以确保成功保存。）:" << endl;
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
                    cout << "请重新登录!" << endl;
                    loggedIn = false; // 用户更改密码重新登录
                    break;
                case '0':
                    cout << "退出登录成功!" << endl;
                    loggedIn = false; // 用户退出登录
                    break;
                default:
                    cout << "请输入合法的选项。" << endl;
                }
            } while ((flag != '9') && (flag != '0'));
        }
    } while (choice != '3');

    return 0;
}
