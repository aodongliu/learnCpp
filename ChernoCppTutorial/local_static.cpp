#include <iostream>

//static i = 0; // but the scope now is different, you can edit it in main. which you might not want
void Function()
{
    static int i = 0;
    i++;
    std::cout << i << std::endl;
}

/*
class Singleton
{
private:
    static Singleton* s_Insurance;
public:
    static Singleton& Get() { return *s_Insurance;}
    void Hello(){}
};
Singleton* Singleton::s_Insurance = nullptr;
*/



class Singleton
{
public:
    static Singleton& Get() 
    { 
        // since it's static, it won't be cleared 
        static Singleton instance;
        return instance;
    }

    void Hello(){}
};


int main()
{
    Singleton::Get().Hello();

    Function();
    Function();
    Function();
    Function();
    Function();
}