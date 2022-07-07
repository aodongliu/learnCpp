#include <iostream>
#include <string>


class Entity
{
public:
    int x;
public:
    void Print() const {std::cout << "Hello" << std::endl;}
};

class ScopedPtr
{
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity) : m_Obj(entity) {};
    ~ScopedPtr(){delete m_Obj;}

    // Can overload the arrow operator
    const Entity* operator->() const
    {
        return m_Obj;
    }
};


int main()
{
    Entity e;
    e.Print();

    Entity* ptr = &e;
    // can dereference and then call function
    (*ptr).Print();

    ptr->Print();


    ScopedPtr entity = new Entity();
    entity->Print();



}