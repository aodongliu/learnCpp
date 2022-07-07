#include <iostream>
#include <string>

class Example
{
public:
    Example()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    Example(int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};


class Entity
{
private:
    int m_Score;
    std::string m_name;
    Example m_Example;
public:
// No member initialization, created Example class twice: once with default, then with line 30
//    Entity()    {
//        m_name = std::string("Unknown");
//        m_Example = Example(8);
//    }

//  If use member initilization, instantiate Example class just once
    Entity()
        :m_Example(8)
    {
        m_name = std::string("Unknown");
    }
//    Entity()
//        : m_name("Unknown"),m_Score(0)
//    {
//    }

    Entity(const std::string& name)
        : m_name(name)
    {
    }
    const std::string& GetName() const {return m_name;}
};


int main()
{

    Entity e0;
//   std::cout << e0.GetName() << std::endl;

//    Entity e1("Cherno");
//    std::cout << e1.GetName() << std::endl;
}