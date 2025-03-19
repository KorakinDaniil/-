#include "fun.h"

bool isMeaningful(const string& text)
{
    // Здесь можно добавить проверку на осмысленность
    // Например, проверка на наличие слов в словаре
    return true; // Для примера всегда возвращаем true
}

// Функция для генерации перестановок
void generatePermutations1(string str)
{
    sort(str.begin(), str.end()); // Сортируем строку для генерации уникальных перестановок
    do
    {
        // Проверяем, начинается ли строка с буквы 'Я'
        if (str[0] == 'Я' && str[1] != 'а' && str[1] != 'е' && isMeaningful(str))
        {
            cout << str << endl; // Выводим осмысленный текст
        }
    } while (next_permutation(str.begin(), str.end()));
}

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
            else
            {
                cout << "Игнорируем символ: " << ch << endl; // Отладочная информация
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

    //string text1 = "зЯеавн"; // Замените на ваш текст
    //generatePermutations1(text1);

    return 0;
}