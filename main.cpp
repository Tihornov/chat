#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ������� ���짮��⥫�
struct User {
    string login;
    string password;
    string name;
    vector<string> messages;

    User(string login, string password, string name) {
        this->login = login;
        this->password = password;
        this->name = name;
    }
};

// ���᮪ ���짮��⥫��
vector<User> users;

// �㭪�� ��� �஢�ન ����⢮����� ���짮��⥫� � ᯨ᪥
bool userExists(string login) {
    for (User user : users) {
        if (user.login == login) {
            return true;
        }
    }
    return false;
}

// �㭪�� ��� ॣ����樨 ������ ���짮��⥫�
void registerUser() {
    string login, password, name;

    cout << "������ �����: ";
    cin >> login;

    if (userExists(login)) {
        cout << "���짮��⥫� � ⠪�� ������� 㦥 �������." << endl;
        return;
    }

    cout << "������ ��஫�: ";
    cin >> password;

    cout << "������ ���: ";
    cin >> name;

    User user(login, password, name);
    users.push_back(user);

    cout << "���짮��⥫� �ᯥ譮 ��ॣ����஢��." << endl;
}

// �㭪�� ��� �室� � ��
void login() {
    string login, password;

    cout << "������ �����: ";
    cin >> login;

    cout << "������ ��஫�: ";
    cin >> password;

    for (User& user : users) {
        if (user.login == login && user.password == password) {
            cout << "���� ����������, " << user.name << "!" << endl;
            return;
        }
    }

    cout << "������ ����� ��� ��஫�." << endl;
}

// �㭪�� ��� ��ࠢ�� ᮮ�饭�� �����⭮�� ���짮��⥫�
void sendMessage() {
    string receiver, message;

    cout << "������ ����� �����⥫�: ";
    cin >> receiver;

    if (!userExists(receiver)) {
        cout << "���짮��⥫� � ⠪�� ������� �� ������." << endl;
        return;
    }

    cout << "������ ᮮ�饭��: ";
    cin >> message;

    for (User& user : users) {
        if (user.login == receiver) {
            user.messages.push_back(message);
            cout << "����饭�� ��ࠢ����." << endl;
            return;
        }
    }
}

// �㭪�� ��� ��ᬮ�� ᮮ�饭�� �����⭮�� ���짮��⥫�
void viewMessages() {
    string login;

    cout << "������ ����� ���짮��⥫�: ";
    cin >> login;

    if (!userExists(login)) {
        cout << "���짮��⥫� � ⠪�� ������� �� ������." << endl;
        return;
    }

    for (User& user : users) {
        if (user.login == login) {
            if (user.messages.empty()) {
                cout << "��� ᮮ�饭��." << endl;
                return;
            }
            cout << "����饭�� ��� " << user.name << ":" << endl;
            for (string message : user.messages) {
                cout << message << endl;
            }
            return;
        }
    }
}

// �㭪�� ��� ������ ᮮ�饭�ﬨ ����� �ᥬ� ���짮��⥫ﬨ
void chat() {
    string message;

    cout << "������ ᮮ�饭��: ";
    cin >> message;

    for (User& user : users) {
        user.messages.push_back(message);
    }

    cout << "����饭�� ��ࠢ����." << endl;
}

int main() {
    // �᭮���� 横� �ணࠬ��
    while (true) {
        cout << "1. ��������� ������ ���짮��⥫�" << endl;
        cout << "2. �室 � ��" << endl;
        cout << "3. ��ࠢ��� ᮮ�饭�� �����⭮�� ���짮��⥫�" << endl;
        cout << "4. ��ᬮ���� ᮮ�饭�� �����⭮�� ���짮��⥫�" << endl;
        cout << "5. ����� ᮮ�饭�ﬨ ����� �ᥬ� ���짮��⥫ﬨ" << endl;
        cout << "6. ��室" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser();
            break;
        case 2:
            login();
            break;
        case 3:
            sendMessage();
            break;
        case 4:
            viewMessages();
            break;
        case 5:
            chat();
            break;
        case 6:
            return 0;
        default:
            cout << "�����४�� ����" << endl;
        }
    }
}