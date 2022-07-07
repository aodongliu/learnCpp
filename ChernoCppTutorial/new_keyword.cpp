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
    int a = 2; 
    int* b = new int[50];

    // The following two line are almost the same, except that 
    // new will allocate the memory AND call the constructor
    // malloc will only allocate the memory 
    Entity *e = new Entity();
    Entity *e = (Entity*) malloc(sizeof(Entity));

    // new also supports placement, by setting a specific address
    Entity *e = new(b) Entity();

    // if use new, must delete
    delete e;
    delete[] b;


    std::cout << "End";
}