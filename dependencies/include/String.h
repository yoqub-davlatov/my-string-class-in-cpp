#pragma once
#include <iostream>

class String
{
private:
    char *m_Buffer;
    unsigned int m_Size;

public:
    String();

    String(const String &other);

    String(const char *entry);

    ~String();

    int length();

    String substring(int st, int num);

    String append(const String &objStr);

    int find(const String &objStr, int pos = 0);

    String& replace(const String &substring, const String &newSubstring);

    static void sort(String arr[], int sz);

    void reverse();

    void toUpper();

    void toLower();

    char at(const int ind);

    bool isEmpty();

    int compare(const String &second);

    String operator+(const String &operand);
    char &operator[](int ind);
    bool operator<(String &second);
    bool operator>(String &second);
    bool operator>=(String &second);
    bool operator<=(String &second);
    bool operator==(const String &second);
    bool operator!=(const String &second);

    friend std::istream &operator>>(std::istream &in, String &obj);

    friend std::istream &getline(std::istream &in, String &obj);

    friend std::ostream &operator<<(std::ostream &out, const String &obj);

    String &operator=(const char *entry);
    String &operator=(const String &other);

    
};
