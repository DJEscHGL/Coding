#include <iostream>
#include <string>

using namespace std;

string check_pass (string password)
{
    string valid_pass = "qwerty123";
    string error_message;
    if (password == valid_pass) {
        error_message = "������ ��������.";
    } else {
        error_message = "�������� ������!";
    }
    return error_message;
}

int main()
{
    setlocale(0, "");
    string user_pass;
    cout << "������� ������: ";
    getline (cin, user_pass);
    string error_msg = check_pass (user_pass);
    cout << error_msg << endl;
    return 0;
}
