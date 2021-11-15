#include <iostream>

bool checkpass(const char* pass) {
    using std::cout; using std::endl;

    int i = 0;
    int differentSigns = 0;

    bool wasDigit = false;
    bool wasUpper = false;
    bool wasLower = false;
    bool wasNonAlphanumeric = false;
    bool finalResult = true;

    while (pass[i] != '\0') {
        bool checkDigit = pass[i] >= '0' && pass[i] <= '9';
        bool checkUpper = pass[i] >= 'A' && pass[i] <= 'Z';
        bool checkLower = pass[i] >= 'a' && pass[i] <= 'z';

        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (pass[j] == pass[i]) {
                flag = false;
                break;
            }
        }

        if (flag)
            differentSigns++;

        if (checkDigit)
            wasDigit = true;

        if (checkUpper)
            wasUpper = true;

        if (checkLower)
            wasLower = true;

        if (!checkDigit && !checkUpper && !checkLower) {
            wasNonAlphanumeric = true;
        }

        i++;
    }

    if (!wasDigit) {
        cout << "Password should have at least 1 digit" << endl;
        finalResult = false;
    }

    if (!wasUpper) {
        cout << "Password should have at least one uppercase letter" << endl;
        finalResult = false;
    }

    if (!wasLower) {
        cout << "Password should have at least one lowercase letter" << endl;
        finalResult = false;
    }

    if (!wasNonAlphanumeric) {
        cout << "Password should have at least one non-alphanumeric character" << endl;
        finalResult = false;
    }

    if (i < 8) {
        cout << "Password should be at least 8 characters long" << endl;
        finalResult = false;
    }

    if (differentSigns < 6) {
        cout << "Password should be at least 6 different characters" << endl;
        finalResult = false;
    }

    return finalResult;
}

int main() {
    using std::cout; using std::endl;

    const char* passes[] =
            {
                    "AbcDe93", "A1b:A1b>", "Ab:Acb<",
                    "abc123><", "Zorro@123", nullptr
            };

    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i])) cout << "OK" << endl;
        cout << endl;
    }
}