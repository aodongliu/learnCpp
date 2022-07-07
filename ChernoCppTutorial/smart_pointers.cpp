#include <iostream>
#include <string>
#include <memory>

class Entity
{
private:
    int x;

public: 
    Entity() { std::cout << "Created Entity!" << std::endl;}
    ~Entity() { std::cout << "Destroyed Entity!" << std::endl;}
    void Print() {}
};


int main()
{

    {

        //std::shared_ptr<Entity> e0;
        std::weak_ptr<Entity>  e0;
        {
            // We can use the 'new' keyword, but it's not the safe way. Not preferable
            //std::unique_ptr<Entity> entity(new Entity());
            //std::unique_ptr<Entity> entity = std::make_unique<Entity>();
            //entity->Print();
            // not allowed
            //std::unique_ptr<Entity> e0 = entity;
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            e0 = sharedEntity;

        } // If e0 is a weak pointer, Entity will die here, bacause line 32 doesn't increase the reference count. Here the ref count will go to 0


    } // If e0 is a shared pointer, Entity will die here, when all the shared pointers pointing to it die. 

}