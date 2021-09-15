#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;

void encryption_Pulkov(const string& key,const string& outputfile,const string& inputfile)
{
    char symbolic;
    ofstream out;
    ifstream in;
    system("chcp 1251");
    out.open(outputfile + ".txt");
    in.open(inputfile + ".txt");
    int i = 0;
    while (1)
    {
        in.get(symbolic);
        if (in.eof())
        {
            break;
        }
        out << (unsigned char)(symbolic + key[i]);
    
        if (i % key.length() == 0)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
}

void decryption_Pulkov(const string& key, const string& outputfile, const string& inputfile)
{
    char symbolic;
    ofstream out;
    ifstream in;
    system("chcp 1251");
    out.open(outputfile + ".txt");
    in.open(inputfile + ".txt");
    int i = 0;
    while (1)
    {
        in.get(symbolic);
        if (in.eof())
        {
            break;
        }
        out << (unsigned char)(symbolic + key[i]);

        if (i % key.length() == 0)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 
    string key;
    string out;
    string in;
    int value;
    while (1)
    {
        cout << "Введите: 1 - Зашифровка файла; 2 - Расшифровка файла" << endl;
        cin >> value;

        if (value == 1)
        {
            cout << "Введите название файла, с которого считываем данные: ";
            cin >> in;
            cout << "Введите название файла, в которой записываем данные: ";
            cin >> out;
            cout << "Введите пароль: ";
            cin >> key;
            encryption_Pulkov(key, out, in);
        }
        else
        {
            cout << "Введите название файла, с которого считываем данные: ";
            cin >> in;
            cout << "Введите название файла, в которой записываем данные: ";
            cin >> out;
            cout << "Введите пароль: ";
            cin >> key;
            decryption_Pulkov(key, out, in);
        }
    }
   return 0;
}


   

