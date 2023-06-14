#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Структура пользователя
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

// Список пользователей
vector<User> users;

// Функция для проверки существования пользователя в списке
bool userExists(string login) {
    for (User user : users) {
        if (user.login == login) {
            return true;
        }
    }
    return false;
}

// Функция для регистрации нового пользователя
void registerUser() {
    string login, password, name;

    cout << "Введите логин: ";
    cin >> login;

    if (userExists(login)) {
        cout << "Пользователь с таким логином уже существует." << endl;
        return;
    }

    cout << "Введите пароль: ";
    cin >> password;

    cout << "Введите имя: ";
    cin >> name;

    User user(login, password, name);
    users.push_back(user);

    cout << "Пользователь успешно зарегистрирован." << endl;
}

// Функция для входа в чат
void login() {
    string login, password;

    cout << "Введите логин: ";
    cin >> login;

    cout << "Введите пароль: ";
    cin >> password;

    for (User& user : users) {
        if (user.login == login && user.password == password) {
            cout << "Добро пожаловать, " << user.name << "!" << endl;
            return;
        }
    }

    cout << "Неверный логин или пароль." << endl;
}

// Функция для отправки сообщения конкретному пользователю
void sendMessage() {
    string receiver, message;

    cout << "Введите логин получателя: ";
    cin >> receiver;

    if (!userExists(receiver)) {
        cout << "Пользователь с таким логином не найден." << endl;
        return;
    }

    cout << "Введите сообщение: ";
    cin >> message;

    for (User& user : users) {
        if (user.login == receiver) {
            user.messages.push_back(message);
            cout << "Сообщение отправлено." << endl;
            return;
        }
    }
}

// Функция для просмотра сообщений конкретного пользователя
void viewMessages() {
    string login;

    cout << "Введите логин пользователя: ";
    cin >> login;

    if (!userExists(login)) {
        cout << "Пользователь с таким логином не найден." << endl;
        return;
    }

    for (User& user : users) {
        if (user.login == login) {
            if (user.messages.empty()) {
                cout << "Нет сообщений." << endl;
                return;
            }
            cout << "Сообщения для " << user.name << ":" << endl;
            for (string message : user.messages) {
                cout << message << endl;
            }
            return;
        }
    }
}

// Функция для обмена сообщениями между всеми пользователями
void chat() {
    string message;

    cout << "Введите сообщение: ";
    cin >> message;

    for (User& user : users) {
        user.messages.push_back(message);
    }

    cout << "Сообщение отправлено." << endl;
}

int main() {
    // Основной цикл программы
    while (true) {
        cout << "1. Регистрация нового пользователя" << endl;
        cout << "2. Вход в чат" << endl;
        cout << "3. Отправить сообщение конкретному пользователю" << endl;
        cout << "4. Просмотреть сообщения конкретного пользователя" << endl;
        cout << "5. Обмен сообщениями между всеми пользователями" << endl;
        cout << "6. Выход" << endl;

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
            cout << "Некорректный ввод" << endl;
        }
    }
}