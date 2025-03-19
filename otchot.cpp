#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <Windows.h>

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string filename = "text.txt";
    
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Ошибка: не удалось открыть файл " << filename << endl;
        return 1;
    }

    // Создаем карту для хранения частот символов
    map<char, int> frequency;
    string line;

    // Чтение файла построчно
    while (getline(file, line))
    {
        // Подсчет частоты символов в строке
        for (char ch : line)
        {
            if ((ch >= 'А' && ch <= 'Я') || ch == ' ')// Проверяем, что символ в диапазоне
            { 
                frequency[ch]++;
            }
        }
    }

    file.close(); // Закрываем файл

    // Вывод результатов
    cout << "Частота встречаемости символов:\n";
    for (const auto& pair : frequency)
    {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
