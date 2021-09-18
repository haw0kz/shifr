#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <vector>
using namespace std;

void Encode(const string& Key,const string& input_file,const string& output_file)
{
    int j = 0;
    ofstream output;
    ifstream input;
    output.open(output_file + ".txt");
    input.open(input_file + ".txt");
    while (!input.eof()) 
    {
        char ch = input.get();
        if (j == Key.length()) 
        {
            j = 0;
        }
        char o;
        o = ((int)ch + (int)Key[j]) % 256;
        output << o;
        j++;
        input.peek();
    }
}

void Decode(const string& Key,const string& input_file,const string& output_file)
{
    int j = 0;
    ifstream input;
    ofstream output;
    output.open(output_file + ".txt");
    input.open(input_file + ".txt");
    while (!input.eof()) 
    {
        char ch = input.get();
        if (j == Key.length()) 
        {
            j = 0;
        }
        char o;
        o = ((int)ch - (int)Key[j] + 256) % 256;
        output << o;
        j++;
        input.peek();
    }
}

int main()
{
    string out, in, key, text;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true)
    { 
        cout << "Введите 1 - зашифровать файл; 2 - расшифровать файл" << endl;
        int command;
        cin >> command;
        switch (command)
        {
            case 1:
            {
                cout << "Введите название входного файла: ";
                cin >> in;
                cout << "Введите название выходного файла: ";
                cin >> out;
                cout << "Введите пароль: ";
                cin >> key;
                Encode(key, in, out);
                break;
            }
            case 2:
            {
                cout << "Введите название входного файла: ";
                cin >> in;
                cout << "Введите название выходного файла: ";
                cin >> out;
                cout << "Введите пароль: ";
                cin >> key;
                Decode(key, in, out);
                break;
            }
        }  
    }
}


   

