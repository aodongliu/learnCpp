#include <iostream>
#include <string>


class Entity
{
private:
    int x;

public: 
    Entity() { std::cout << "Created Entity!" << std::endl;}
    ~Entity() { std::cout << "Destroyed Entity!" << std::endl;}
};


int* CreateArray()
{
    int array[50];
    //Wrong! created in the stack, will get cleared 
    return array;
}

//Fix #1:
//int* CreateArray() 
//{
//    int* array = new int[50];
//    return array;
//}

//Fix #2, create on stack one level higher, and pass it in
void CreateArray(int* array)
{
// fill our array
}   

class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr) : m_Ptr(ptr) {}
    ~ScopedPtr() {delete m_Ptr;}
};

int main()
{
    int array[50];
    CreateArray(array);
    {
        // on the stack
        //Entity e;

        // on the heap
        Entity* e = new Entity();
    }

    {
        ScopedPtr e = new Entity();
    }

}