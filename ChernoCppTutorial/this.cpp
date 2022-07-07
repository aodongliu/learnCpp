#include <iostream>
#include <string>

//void PrintEntity(Entity* e);

//void PrintEntity2(const Entity& e);

class Entity
{
public:
    int x,y;

    //Entity( int x, int y) : x(x), y(y) {};

    Entity( int x, int y)
    {
        this->x = x;
        this->y = y;

        //PrintEntity(this);
        //PrintEntity2(*this);
    }

    int GetX() const
    {
        return x;
    }
};


//void PrintEntity(Entity* e)
//{
//print
//}

//void PrintEntity2(const Entity& e){}

int main()
{

}