// Copyright 2022 UNN-IASR
#include <iostream>
#include "fun.h"

int main() {
  // Примеры строк для тестирования
  const char* str1 = "hello world 123 test";
  const char* str2 = "Hello World test A Ab1";
  const char* str3 = "hello world test";
  const char* str4 = "";  // Пустая строка
  const char* str5 = "   ";  // Только пробелы
  setlocale(LC_ALL, "Russian");

  // Пример использования faStr1
  std::cout << "Задача 1\n";
  std::cout << "faStr1(\"" << str1 << "\") = " << faStr1(str1)
            << " слов(а) без цифр" << std::endl;
  std::cout << "faStr1(\"" << str2 << "\") = " << faStr1(str2)
            << " слов(а) без цифр" << std::endl;
  std::cout << "faStr1(\"" << str4 << "\") = " << faStr1(str4)
            << " слов(а) без цифр" << std::endl;

  // Пример использования faStr2
  std::cout << "Задача 2\n";
  std::cout << "faStr2(\"" << str2 << "\") = " << faStr2(str2)
            << " слов(а) с заглавной буквы" << std::endl;
  std::cout << "faStr2(\"" << str1 << "\") = " << faStr2(str1)
            << " слов(а) с заглавной буквы" << std::endl;
  std::cout << "faStr2(\"" << str5 << "\") = " << faStr2(str5)
            << " слов(а) с заглавной буквы" << std::endl;

  // Пример использования faStr3
  std::cout << "Задача 3\n";
  std::cout << "faStr3(\"" << str3 << "\") = " << faStr3(str3)
            << " - средняя длина слова" << std::endl;
  std::cout << "faStr3(\"" << str1 << "\") = " << faStr3(str1)
            << " - средняя длина слова" << std::endl;
  std::cout << "faStr3(\"" << str4 << "\") = " << faStr3(str4)
            << " - средняя длина слова" << std::endl;

  return 0;
}
