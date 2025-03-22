// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

// Задача 1: Подсчет слов без цифр
unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool in_word = false;
    bool has_digit = false;
    const char* p = str;

    while (*p != '\0') {
        if (!isspace(*p)) {
            if (!in_word) {
                in_word = true;
                has_digit = false;
            }
            if (isdigit(*p)) {
                has_digit = true;
            }
        } else {
            if (in_word) {
                if (!has_digit) {
                    count++;
                }
                in_word = false;
            }
        }
        p++;
    }
    // Проверка последнего слова
    if (in_word && !has_digit) {
        count++;
    }
    return count;
}

// Задача 2: Подсчет слов с заглавной буквы и строчными
unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool in_word = false;
    bool is_valid = false;
    const char* p = str;

    while (*p != '\0') {
        if (!isspace(*p)) {
            if (!in_word) {
                in_word = true;
                is_valid = isupper(*p);  // Первая буква заглавная
            } else {
                if (!islower(*p)) {      // Остальные — строчные
                    is_valid = false;
                }
            }
        } else {
            if (in_word) {
                if (is_valid) {
                    count++;
                }
                in_word = false;
            }
        }
        p++;
    }
    // Проверка последнего слова
    if (in_word && is_valid) {
        count++;
    }
    return count;
}

// Задача 3: Средняя длина слова
unsigned int faStr3(const char* str) {
    unsigned int total_length = 0;
    unsigned int word_count = 0;
    bool in_word = false;
    unsigned int current_length = 0;
    const char* p = str;

    while (*p != '\0') {
        if (!isspace(*p)) {
            if (!in_word) {
                in_word = true;
                current_length = 1;
            } else {
                current_length++;
            }
        } else {
            if (in_word) {
                total_length += current_length;
                word_count++;
                in_word = false;
            }
        }
        p++;
    }
    // Обработка последнего слова
    if (in_word) {
        total_length += current_length;
        word_count++;
    }
    // Вычисление среднего и округление
    if (word_count == 0) {
        return 0;  // Нет слов
    }
    double average = static_cast<double>(total_length) / word_count;
    return static_cast<unsigned int>(std::round(average));
}
