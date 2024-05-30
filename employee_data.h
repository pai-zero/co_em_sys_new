/*Copyright (c) 2024   SNUT �෽Բ202218084035 أ����202214024085 ���Ӻ�202218084036  All rights reserved*/

#include <iostream>
#include <fstream> // ����ifstream��ofstream���࣬������������ļ�
#include <sstream> // istringstream���롢ostringstream��� �� stringstream�������

const int MAX_EMPLOYEES = 1000; // ���Ա������

const char XOR_KEY = 0x5A; // �û����ݵ������Կ,�����ѡ������ֵ��Ϊ�����ܵ���Կ��ʮ��������λ��

using namespace std;



struct Employee
{
    int id;
    string name;
    string gender;
    string education;
    string position;
    string idNumber;
    string phoneNumber;
    string notes;
};// Ա����Ϣ�ṹ��



void displayMenu();                                               // �˵�ģ��
void addEmployee(Employee employees[], int& count);               // ���ģ��
void updateEmployee(Employee employees[], int count);             // �޸�ģ��
void deleteEmployee(Employee employees[], int& count);            // ɾ��ģ��
void searchEmployeeById(const Employee employees[], int count);   // ��ѯģ�飬���Ų�ѯ
void searchEmployeeByName(const Employee employees[], int count); // ��ѯģ�飬������ѯ
void printAllEmployeeInformation(const Employee employees[], int count);// ��ӡģ�飬���ȫ��Ա����Ϣ
void saveToFile(const Employee employees[], int count);           // ����ģ��
void readFromFile(Employee employees[], int& count);              // ��ȡģ��
// const����ָ�����,��ֹ�������޸ģ����� const int i=5;֮��i�޷���������ֵ

void displayMenu()
{
    // �˵�ģ��
    cout << "\nԱ������ϵͳ�˵���" << endl;
    cout << "1. ���Ա��" << endl;
    cout << "2. ����Ա��" << endl;
    cout << "3. ɾ��Ա��" << endl;
    cout << "4. �����Ų�ѯԱ��" << endl;
    cout << "5. ��������ѯԱ��" << endl;
    cout << "6. �����ļ�" << endl;
    cout << "7. ��ȡ�ļ�" << endl;
    cout << "8. ��ӡȫ��Ա����Ϣ" << endl;
    cout << "9. ��������" << endl;
    cout << "0. �˳�" << endl;
}





void addEmployee(Employee employees[], int& count)
{
    // ���ģ��
    Employee emp; // �����Ա��
    cout << "\n�����������Ա������Ϣ:" << endl;
    cout << "����: ";
    cin >> emp.id;
    cin.ignore(); // �ӻ�������������з�

    // ���Ա���Ƿ��Ѵ���
    for (int i = 0; i < count; ++i)
    {
        if (employees[i].id == emp.id)
        {
            cout << "�˹��� " << emp.id << " �Ѵ��ڡ�������ѡ��" << endl;
            return;
        }
    }

    // getline()������<iostream>��
    cout << "����: ";
    getline(cin, emp.name); // cin >> emp.name;
    cout << "�Ա�: ";
    getline(cin, emp.gender);
    cout << "ѧ��: ";
    getline(cin, emp.education);
    cout << "ְλ: ";
    getline(cin, emp.position);
    cout << "���֤��: ";
    getline(cin, emp.idNumber);
    cout << "�绰��: ";
    getline(cin, emp.phoneNumber);
    cout << "��ע��Ϣ: ";
    getline(cin, emp.notes);

    employees[count++] = emp;

    cout << "Ա����Ϣ��ӳɹ���" << endl;
}

void updateEmployee(Employee employees[], int count)
{
    // �޸�ģ��
    int empId; // ���޸�Ա������
    cout << "\n����Ҫ���µ�Ա���Ĺ���: ";
    cin >> empId;
    cin.ignore(); // �ӻ�������������з�

    for (int i = 0; i < count; ++i)
    {
        if (employees[i].id == empId)
        {
            cout << "�����Ա���ĸ�����ϸ��Ϣ " << empId << ":" << endl;
            cout << "����: ";
            getline(cin, employees[i].name);
            cout << "�Ա�: ";
            getline(cin, employees[i].gender);
            cout << "ѧ��: ";
            getline(cin, employees[i].education);
            cout << "ְλ: ";
            getline(cin, employees[i].position);
            cout << "���֤��: ";
            getline(cin, employees[i].idNumber);
            cout << "�绰��: ";
            getline(cin, employees[i].phoneNumber);
            cout << "��ע��Ϣ: ";
            getline(cin, employees[i].notes);


            cout << "Ա����Ϣ���³ɹ���" << endl;
            return;
        }
    }

    cout << "Ա��" << empId << " ��Ϣ������Ϣ���С�" << endl;
}

void deleteEmployee(Employee employees[], int& count)
{
    // ɾ��ģ��
    int empId; // ��ɾ��Ա������
    cout << "\n����Ҫɾ����Ա���Ĺ���: ";
    cin >> empId;
    cin.ignore(); // �ӻ�������������з�

    for (int i = 0; i < count; ++i)
    {
        if (employees[i].id == empId)
        {
            for (int j = i; j < count - 1; ++j)
            {
                employees[j] = employees[j + 1];
            }

            --count;
            cout << "Ա�� " << empId << " ɾ���ɹ���" << endl;
            return;
        }
    }

    cout << "Ա�� " << empId << " ��Ϣ������Ϣ���С�" << endl;
}

void searchEmployeeById(const Employee employees[], int count)
{
    // ��ѯģ�飬���Ų�ѯ
    int empId; // ����ѯԱ������
    cout << "\n����Ҫ���ҵ�Ա������: ";
    cin >> empId;

    for (int i = 0; i < count; ++i)
    {
        if (employees[i].id == empId)
        {
            cout << "\nԱ����Ϣ:" << endl;
            cout << "����: " << employees[i].id << endl;
            cout << "����: " << employees[i].name << endl;
            cout << "�Ա�: " << employees[i].gender << endl;
            cout << "ѧ��: " << employees[i].education << endl;
            cout << "ְλ: " << employees[i].position << endl;
            cout << "���֤��: " << employees[i].idNumber << endl;
            cout << "�绰��: " << employees[i].phoneNumber << endl;
            cout << "��ע��Ϣ: " << employees[i].notes << endl;
            return;
        }
    }

    cout << "Ա�� " << empId << " ��Ϣ������Ϣ���С�" << endl;
}

void searchEmployeeByName(const Employee employees[], int count)
{
    // ��ѯģ�飬������ѯ
    string empName; // ����ѯԱ������
    cout << "\n����Ҫ���ҵ�Ա������: ";
    getline(cin, empName);

    for (int i = 0; i < count; ++i)
    {
        if (employees[i].name == empName)
        {
            cout << "\nԱ����Ϣ:" << endl;
            cout << "����: " << employees[i].id << endl;
            cout << "����: " << employees[i].name << endl;
            cout << "�Ա�: " << employees[i].gender << endl;
            cout << "ѧ��: " << employees[i].education << endl;
            cout << "ְλ: " << employees[i].position << endl;
            cout << "���֤��: " << employees[i].idNumber << endl;
            cout << "�绰��: " << employees[i].phoneNumber << endl;
            cout << "��ע��Ϣ: " << employees[i].notes << endl;
            return;
        }
    }

    cout << "Ա�� " << empName << " ��Ϣ������Ϣ����" << endl;
}


void  printAllEmployeeInformation(const Employee employees[], int count)
{
    // ��ӡȫ��Ա����Ϣ
    for (int i = 0; i < count; ++i)
    {

            cout << "\nԱ����Ϣ:" << endl;
            cout << "����: " << employees[i].id << endl;
            cout << "����: " << employees[i].name << endl;
            cout << "�Ա�: " << employees[i].gender << endl;
            cout << "ѧ��: " << employees[i].education << endl;
            cout << "ְλ: " << employees[i].position << endl;
            cout << "���֤��: " << employees[i].idNumber << endl;
            cout << "�绰��: " << employees[i].phoneNumber << endl;
            cout << "��ע��Ϣ: " << employees[i].notes << endl;
    }

    return;
}


void saveToFile(const Employee employees[], int count)
{   
    // ����ģ�� 
    ofstream outfile("Employee_Data.csv"); // д���ļ���ʹ��<<
    if (!outfile.is_open())
    {
        cout << "���ļ�����д��ʱ����" << endl;
        return;
    }

    for (int i = 0; i < count; ++i)
    {
        // ������
        string encryptedName = employees[i].name;
        string encryptedGender = employees[i].gender;
        string encryptedEducation = employees[i].education;
        string encryptedPosition = employees[i].position;
        string encryptedIdNumber = employees[i].idNumber;
        string encryptedPhoneNumber = employees[i].phoneNumber;
        string encryptedNotes = employees[i].notes;

        for (char& c : encryptedName)
            c ^= XOR_KEY; // '^=��'���ֵ�������������Ĳ��������Ҳ�Ĳ��������������������������ֵ�����Ĳ�������

        for (char& c : encryptedGender)
            c ^= XOR_KEY;

        for (char& c : encryptedEducation)
            c ^= XOR_KEY;

        for (char& c : encryptedPosition)
            c ^= XOR_KEY;

        for (char& c : encryptedIdNumber)
            c ^= XOR_KEY;

        for (char& c : encryptedPhoneNumber)
            c ^= XOR_KEY;

        for (char& c : encryptedNotes)
            c ^= XOR_KEY;

        outfile << employees[i].id << ","
            << encryptedName << ","
            << encryptedGender << ","
            << encryptedEducation << ","
            << encryptedPosition << ","
            << encryptedIdNumber << ","
            << encryptedPhoneNumber << ","
            << encryptedNotes << endl;
    }

    outfile.close();
    cout << "�����ѳɹ����浽�ļ���" << endl;
}


void readFromFile(Employee employees[], int& count)
{
    // ��ȡģ��
    count = 0; // ���ļ���ȡ֮ǰ�����������


    ifstream infile("Employee_Data.csv"); // ifstreamĬ�������뷽ʽ���ļ�
    if (!infile.is_open())
    {
        cout << "���ļ����ж�ȡʱ����" << endl;
        return;
    }

    string line;
    while (getline(infile, line))
    {
        stringstream ss(line);
        // stringstream������std�У������ַ�����Ϊ�����д���
        // �������Ϊ��line�е�Ԫ�ز��Ϊ����Employee�е�Ԫ�أ�����ж�Ϊ��,��
        Employee emp;
        char delimiter = ',';

        ss >> emp.id;
        ss >> delimiter;

        getline(ss, emp.name, delimiter);
        // ���ڴ��ַ��� ss �ж�ȡһ�����ݣ�ֱ������ָ���ķָ��� delimiter ���ߵ������Ľ�β��
        // ���ڶ�ȡ���洢Ա����������ֱ���������ŷָ������ߵ�����β��

        getline(ss, emp.gender, delimiter);
        getline(ss, emp.education, delimiter);
        getline(ss, emp.position, delimiter);
        getline(ss, emp.idNumber, delimiter);
        getline(ss, emp.phoneNumber, delimiter);
        getline(ss, emp.notes);

        // ������
        for (char& c : emp.name)
            c ^= XOR_KEY;

        for (char& c : emp.gender)
            c ^= XOR_KEY;

        for (char& c : emp.education)
            c ^= XOR_KEY;

        for (char& c : emp.position)
            c ^= XOR_KEY;

        for (char& c : emp.idNumber)
            c ^= XOR_KEY;

        for (char& c : emp.phoneNumber)
            c ^= XOR_KEY;

        for (char& c : emp.notes)
            c ^= XOR_KEY;

        employees[count++] = emp;
    }

    infile.close();
    cout << "�ѳɹ����ļ��ж�ȡ���ݡ�" << endl;
}



