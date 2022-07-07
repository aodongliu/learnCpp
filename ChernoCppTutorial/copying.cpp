#include <iostream>
#include <string>
#include <cstring>

class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;

public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size+1];
        memcpy(m_Buffer,string,m_Size);
        m_Buffer[m_Size] = 0;
    }

    ~String()
    {
        delete m_Buffer;
    }

    char& operator[](unsigned int index)
    {
        return m_Buffer[index];
    }

    // If we don't want to allow copying
    //String(const String& other) = delete;

    // The default copy constructor (if we don't supplt one), does this: 
    //String(const String& other)
    //    : m_Buffer(other.m_Buffer), m_Size(other.m_Size){}
    // This is shallow copyging, meaning that we are only copying pointer address, but not the actual object being pointed at

    // Proper way of doing deep copy:
    String(const String& other)
        : m_Size(other.m_Size)
    {
        std::cout << "Copied String" << std::endl;
        m_Buffer = new char[m_Size+1];
        memcpy(m_Buffer,other.m_Buffer,m_Size+1);
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

// Want to pass by const reference to avoid copying (to avoid making new objects)
void PrintString(const String& string)
{
    std::cout << string << std::endl;
}

int main()
{
    String string = "Cherno";

    String second = string;

    second[2] = 'a';

    PrintString(string);
    PrintString(second);
    //std::cout << string << std::endl;
    //std::cout << second << std::endl;
}