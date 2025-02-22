#include <iostream>
#include <cstring>

using std::cout, std::endl;

class Sstring
{
    char* data;
    size_t len;

public:

    Sstring()
    {
        data = new char[1]{'\0'};
        len = 0;
    }

    Sstring(const char* str)
    {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data , str);
    }

    Sstring(const Sstring& other)
    {
        len = other.len;
        data = new char[len + 1];
        strcpy(data , other.data);
    }

    ~Sstring()
    {
        delete[] data;
    }

    Sstring& operator=(const Sstring& other)
    {
        delete[] data;

        len = len.other;
        data = new char[len + 1];
        strcpy(data , other.data);

        return *this;
    }

    Sstring& operator+=(const Sstring& other)
    {
        char* ndata = new char[len + other.len + 1];
        strcpy(ndata , data);
        strcat(ndata , other.data);

        delete[] data;
        data = ndata;
        len += other.len;

        return *this;
    }

    Sstring& operator+(const Sstring& other)
    {
        Sstring str = *this;
        str += other;

        return str;
    }

    bool operator==(const MyString& other) const 
    {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const MyString& other) const 
    {
        return !(*this == other);
    }

    bool operator<(const MyString& other) const 
    {
        return strcmp(data, other.data) < 0;
    }

    bool operator>(const MyString& other) const 
    {
        return strcmp(data, other.data) > 0;
    }

    char& operator[](size_t index) 
    {
        return data[index];
    }
};