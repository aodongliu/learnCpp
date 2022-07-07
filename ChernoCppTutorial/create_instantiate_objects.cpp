#include <iostream>
#include <string>

using String = std::string;
class Entity
{
private:
    String m_name;

public:
    Entity() : m_name("Unknown") {}
    Entity(const String& name) : m_name(name) {}
    const String& GetName() const{ return m_name;}
};


int main()
{
    Entity* e;
    {
    // on stack
    //    Entity entity("Cherno");
    
    // on heap
        Entity* entity = new Entity("Cherno");
        e = entity;
        std::cout << e->GetName() << std::endl;
    }

    std::cout << "End";
    delete e;
}