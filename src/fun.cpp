// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cmath>
unsigned int faStr1(const char* str) {
    bool isInsideWord = false;
    bool containsDigit = false;
    unsigned int wordCount = 0;

    while (*str) {
        if (*str != ' ' && !isInsideWord) {
            isInsideWord = true;
            containsDigit = false;
        }
        if (*str != ' ' && isInsideWord) {
            if (*str >= '0' && *str <= '9') {
                containsDigit = true;
            }
        }
        if (*str == ' ' && isInsideWord) {
            if (!containsDigit) {
                wordCount++;
            }
            isInsideWord = false;
        }
        str++;
    }
    if (isInsideWord && !containsDigit) {
        wordCount++;
    }
    return wordCount;
}

unsigned int faStr2(const char* str) {
    bool isInsideWord = false;
    bool startsWithCapital = false;
    bool isAllLowercase = true;
    unsigned int wordCount = 0;

    while (*str) {
        if (*str != ' ' && !isInsideWord) {
            isInsideWord = true;
            startsWithCapital = (*str >= 'A' && *str <= 'Z');
            isAllLowercase = true;
        } else if (*str != ' ' && isInsideWord) {
            if (!(*str >= 'a' && *str <= 'z')) {
                isAllLowercase = false;
            }
        }

        if (*str == ' ' && isInsideWord) {
            if (startsWithCapital && isAllLowercase) {
                wordCount++;
            }
            isInsideWord = false;
        }
        str++;
    }
    if (isInsideWord && startsWithCapital && isAllLowercase) {
        wordCount++;
    }

    return wordCount;
}

unsigned int faStr3(const char* str) {
    bool isInsideWord = false;
    unsigned int wordCount = 0;
    unsigned int totalWordLength = 0;
    unsigned int currentWordLength = 0;

    while (*str) {
        if (*str != ' ' && !isInsideWord) {
            isInsideWord = true;
            currentWordLength = 0;
        }
        if (*str != ' ' && isInsideWord) {
            currentWordLength++;
        }
        if (*str == ' ' && isInsideWord) {
            totalWordLength += currentWordLength;
            wordCount++;
            isInsideWord = false;
        }
        str++;
    }
    if (isInsideWord) {
        totalWordLength += currentWordLength;
        wordCount++;
    }
    if (wordCount == 0) {
        return 0;
    }

    double averageLength = static_cast<double>(totalWordLength) / wordCount;
    return static_cast<unsigned int>(std::round(averageLength));
}
