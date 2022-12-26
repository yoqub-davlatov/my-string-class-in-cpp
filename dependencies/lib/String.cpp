#include "String.h"

String::String()
{
    m_Buffer = new char[1];
    m_Buffer[0] = '\0';
    m_Size = 0;
}


String::String(const char *charArr)
{
    int length = 0;

    while (charArr[length])
    {
        length++;
    }

    m_Buffer = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        m_Buffer[i] = charArr[i];
    }

    m_Buffer[length] = '\0';
    m_Size = length;
}

String::String(const String &other)
    : m_Size(other.m_Size)
{
    m_Buffer = new char[other.m_Size + 1];
    m_Size = other.m_Size;
    for (int i = 0; i <= m_Size; i++)
    {
        m_Buffer[i] = other.m_Buffer[i];
    }
}

String &String::operator=(const String &other)
{

    if (this == &other)
    {
        return *this;
    }
    delete[] m_Buffer;

    m_Buffer = new char[other.m_Size + 1];

    for (int i = 0; i <= other.m_Size; i++)
    {
        m_Buffer[i] = other.m_Buffer[i];
    }

    m_Size = other.m_Size;
    return *this;
}

String &String::operator=(const char *other)
{
    String a(other);
    return *this = a;
}

String::~String()
{
    delete[] m_Buffer;
}

int String::length()
{
    return m_Size;
}

String String::substring(int pos, int len)
{
    String res;
    if (pos >= m_Size)
    {
        return res;
    }

    int substringLength = (m_Size - pos > len) ? len : m_Size - pos;

    char *temp = new char[substringLength + 1];

    for (int i = 0; i < substringLength; i++)
    {
        temp[i] = m_Buffer[i + pos];
    }
    temp[substringLength] = '\0';

    delete[] res.m_Buffer;
    res.m_Buffer = temp;
    res.m_Size = substringLength;
    return res;
}

String String::append(const String &objStr)
{
    String res;
    delete[] res.m_Buffer;

    res.m_Buffer = new char[m_Size + objStr.m_Size + 1];

    for (int i = 0; i < m_Size; i++)
    {
        res.m_Buffer[i] = m_Buffer[i];
    }

    for (int i = 0; i <= objStr.m_Size; i++)
    {
        res.m_Buffer[m_Size + i] = objStr.m_Buffer[i];
    }

    res.m_Size = m_Size + objStr.m_Size;

    return res;
}

int String::find(const String &obj, int pos)
{
    for (int i = pos; i <= m_Size - obj.m_Size; i++)
    {
        int j = 0;
        while (i + j < m_Size and j < obj.m_Size and m_Buffer[i + j] == obj.m_Buffer[j])
        {
            j++;
        }
        if (j == obj.m_Size)
        {
            return i;
        }
    }
    return -1;
}

String& String::replace(const String &substring, const String &newSubstring)
{
    int pos = this->find(substring);
    if (pos == -1)
    {
        return *this;
    }
    int newSize = m_Size + newSubstring.m_Size - substring.m_Size;
    char *temp = new char[newSize + 1];
    for (int i = 0; i < pos; i++)
    {
        temp[i] = m_Buffer[i];
    }
    for (int i = 0; i < newSubstring.m_Size; i++)
    {
        temp[i + pos] = newSubstring.m_Buffer[i];
    }

    for (int i = pos + substring.m_Size, j = pos + newSubstring.m_Size; i < m_Size; i++, j++)
    {
        temp[j] = m_Buffer[i];
    }
    temp[newSize] = '\0';
    m_Size = newSize;
    delete[] m_Buffer;
    m_Buffer = temp;
    return *this;
}

void String::sort(String *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                String temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void String::reverse()
{
    int i = 0;
    int j = m_Size - 1;
    while (i < j)
    {
        char temp = m_Buffer[i];
        m_Buffer[i] = m_Buffer[j];
        m_Buffer[j] = temp;
        i++;
        j--;
    }
}

void String::toUpper()
{
    for (int i = 0; i < m_Size; i++)
    {
        if (m_Buffer[i] >= 'a' and m_Buffer[i] <= 'z')
        {
            m_Buffer[i] -= 32;
        }
    }
}

void String::toLower()
{
    for (int i = 0; i < m_Size; i++)
    {
        if (m_Buffer[i] >= 'A' and m_Buffer[i] <= 'Z')
        {
            m_Buffer[i] += 32;
        }
    }
}

char String::at(const int ind)
{
    if (ind < m_Size)
    {
        return m_Buffer[ind];
    }
    return 0;
}

bool String::isEmpty()
{
    return m_Size == 0;
}

int String::compare(const String &second)
{
    if (m_Size != second.m_Size)
    {
        return 0;
    }
    for (int i = 0; i < m_Size; i++)
    {
        if (m_Buffer[i] != second.m_Buffer[i])
        {
            return 0;
        }
    }
    return 1;
}

String String::operator+(const String &operand)
{
    return this->append(operand);
}

bool String::operator==(const String &second)
{
    return this->compare(second);
}

bool String::operator!=(const String &second)
{
    return !(this->compare(second));
}

bool String::operator<(String &second)
{
    for (int i = 0; i <= m_Size; i++)
    {
        if (m_Buffer[i] == second.m_Buffer[i])
        {
            continue;
        }
        if (m_Buffer[i] < second.m_Buffer[i])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

bool String::operator>(String &second)
{
    return second < *this;
}

bool String::operator<=(String &second)
{
    return !(second > *this);
}

bool String::operator>=(String &second)
{
    return !(second < *this);
}

std::ostream &operator<<(std::ostream &out, const String &obj)
{
    out << obj.m_Buffer;
    return out;
}

char &String::operator[](int index)
{
    return m_Buffer[index];
}

std::istream& operator>>(std::istream &in, String &obj)
{
    delete[] obj.m_Buffer;
    obj.m_Size = 0;
    
    char *buf = new char[257];
    in >> buf;
    for (int i = 0; buf[i] != '\0'; i++)
    {
        obj.m_Size++;
    }
    obj.m_Buffer = new char[obj.m_Size + 1];
    for (int i = 0; i < obj.m_Size; i++)
    {
        obj.m_Buffer[i] = buf[i];
    }
    obj.m_Buffer[obj.m_Size] = '\0';
    
    delete buf;
    return in;
}

std::istream &getline(std::istream &in, String &obj)
{
    delete[] obj.m_Buffer;
    obj.m_Size = 0;
    
    char *buf = new char[257];
    in.getline(buf, 256);
    for (int i = 0; buf[i] != '\0'; i++)
    {
        obj.m_Size++;
    }
    obj.m_Buffer = new char[obj.m_Size + 1];
    for (int i = 0; i < obj.m_Size; i++)
    {
        obj.m_Buffer[i] = buf[i];
    }
    obj.m_Buffer[obj.m_Size] = '\0';
    
    delete buf;
    return in;
}