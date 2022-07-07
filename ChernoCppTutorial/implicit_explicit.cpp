#include <iostream>
#include <string>


class Entity
{
private:
    std::string m_Name;
    int m_Age;
public:
    explicit Entity(const std::string& name) : m_Name(name), m_Age(-1) {}

    explicit Entity(int age) : m_Name("Unknown"),m_Age(age) {}
};

void PrintEntity(const Entity& entity)
{

};


int main()
{


    // if constructor is explicit, wont work
    //Entity b = 22; 
    //PrintEntity(22);
    //PrintEntity(std::string("Cherno"));
    
    // if explicit, need to do this:
    Entity b(22);
    PrintEntity(Entity("Cherno"));
}