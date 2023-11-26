#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <Windows.h>

using namespace std;
string alg(string &a);
string algReverse(string &a);
string base64_decode(string const& encoded_string);
static inline bool is_base64(unsigned char c);
string base64_encode(string const& str_to_encode);
int getRandom(int min, int max);

const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

int main()
{
    //добавить base64, вставку рандомного знака вместо a или b

    //setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str, fileOutput, logAll;
    int mode, algReps;
    cout << "Enter string: ";
    std::getline(std::cin, str);
    cout << "Enter mode (1-encode, 2-decode): ";
    cin >> mode;
    cout << "Enter the number of algorithm repetitions: ";
    cin >> algReps;
    cout << "Output to file? y/n: ";
    cin >> fileOutput;
    cout << "Log all? y/n: ";
    cin >> logAll;
    if (logAll[0] == 'y')
    {
        if (fileOutput[0] == 'y')
        {
            ofstream output;
            output.open("output.txt");
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    output << i + 1 << ". " << alg(str) << endl;
                }
                else if (mode == 2) {
                    output << i + 1 << ". " << algReverse(str) << endl;
                }
            }
            cout << "Done!" << endl;
            output.close();
        }
        else if (fileOutput[0] == 'n')
        {
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    cout << i + 1 << ". " << alg(str) << endl;
                }
                else if (mode == 2) {
                    cout << i + 1 << ". " << algReverse(str) << endl;
                }
            };
        };
    }
    else if (logAll[0] == 'n')
    {
        if (fileOutput[0] == 'y')
        {
            ofstream output;
            output.open("output.txt");
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    alg(str);
                }
                else if (mode == 2) {
                    algReverse(str);
                }
            }
            output << str << endl << algReps << " repetitions";
            cout << "Done!" << endl;
            output.close();
        }
        else if (fileOutput[0] == 'n')
        {
            for (int i = 0; i < algReps; i++) {
                if (mode == 1) {
                    alg(str);
                }
                else if (mode == 2) {
                    algReverse(str);
                }
            };
            cout << str << endl << algReps << " repetitions\n";

        };
    };
    system("pause");
    return 0;
}

string alg(string &str) {
    str = base64_encode(str);
    int size = str.size();
    int min = 33, max = 126;
    if (size % 2 == 0)
    {
        str.insert(size / 2, 1, getRandom(min, max));
    }
    else if (size % 2 == 1)
    {
        str.insert(0, 1, getRandom(min, max));
    };
    for (int i = 0; i <= size; i++) {
        if (str[i] != 126) {
            str[i] += 1;
        }
        else if (str[i] == 126) {
            str[i] = 33;
        };

    };
    return str;
}

string algReverse(string &str) {
    int size = str.size();

    for (int i = 0; i <= size; i++) {
        if (str[i] != 33) {
            str[i] -= 1;
        }
        else if (str[i] == 33) {
            str[i] = 126;
        };
    };
    if (size % 2 == 0)
    {
        str.erase(0, 1);
    }
    else if (size % 2 == 1)
    {
        str.erase((size - 1) / 2, 1);
    };
    str = base64_decode(str);
    return str;
}

int getRandom(int min, int max) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(min, max); // define the range

    return distr(gen); // generate numbers
}

std::string base64_encode(std::string const& str_to_encode) {
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];
    unsigned int in_len = str_to_encode.size();
    unsigned char const* bytes_to_encode = reinterpret_cast<unsigned char const*>(str_to_encode.c_str());

    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (i = 0; (i < 4); i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        for (j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while ((i++ < 3))
            ret += '=';

    }

    return ret;

}

static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_decode(std::string const& encoded_string) {
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i == 4) {
            for (i = 0; i < 4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j < 4; j++)
            char_array_4[j] = 0;

        for (j = 0; j < 4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}