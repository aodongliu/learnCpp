#include <iostream>
#include <string>

class Entity
{
private:
    int m_X, m_Y;
    int* p;

public:
    // Can't modify the class, i.e, class variables are read-only
    int GetX() const
    {
        return m_X;
    }

    // if need to change m_X, can't set const 
    void SetX(int x)
    {
        m_X = x;
    }

    // First const:  we're returning a int pointer that can't be modified 
    // Second const: content of pointer can't be modified
    // Third const:  class variable p can't be modified
    const int* const GetP() const
    {
        return p;
    }

    void PrintEntity(const Entity& e)
    {
        std::cout << e.GetX() << std::endl;
    }
};




int main()
{
    const int MAX_AGE = 90;

    // Can't change the content of a pointer
    // -> Can't do *a = 2;
    // -> Can do a = (int*) &MAX_AGE; (can still change the pointer itself)
    //const int* a = new int;
    // int const* a = new int; (means the same thing. Const is before *)

    // Can change the content of the pointer, but can't reassign the pointer to point to something else
    // -> Can do *a = 2;
    // -> Can't do a = (int*) &MAX_AGE;  
    int* const a = new int;

    //*a = 2;

    //a = (int*) &MAX_AGE;


}