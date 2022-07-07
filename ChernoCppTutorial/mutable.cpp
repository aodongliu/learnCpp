#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_name;
    mutable int m_DebugCount = 0;

public:
    const std::string& GetName() const
    {
        m_DebugCount++;
        return m_name;
    }
};


int main()
{

    const Entity e;
    e.GetName();

    // can use mutable with lambdas
    int x = 8;
    // '=' pass by value. Need mutable to be able to modify x 
    auto f = [=]() mutable
    {
        x++;
        std::cout << x << std::endl;
    };

    f();
    std::cout << x << std::endl;
}