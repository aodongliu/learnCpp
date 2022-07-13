#include <iostream>
#include <vector>

void PrintValue(int value)
{
    std::cout<< "Value: " << value << std::endl;
}


void ForEach(const std::vector<int>& values, void (*func)(int))
{
    for (int value: values)  func(value);
}

void HelloWorld(int a)
{
    std::cout << "Hello World! Value: " << a << std::endl;
}

int main()
{
    // Ways to use function pointers

    // 1. use auto
    auto function = HelloWorld;
    
    // 2. use the actual type of the function pointer. we can then call: cherno()
    void(*cherno)(int) = HelloWorld;
    //    The above is hard to read. Can use typedef:
    typedef void(*HelloWorldFunction)(int);
    HelloWorldFunction function2= HelloWorld;

    //function2(8);
    //cherno(5);

    std::vector<int> values = {1,2,3,4,5};

    
    ForEach(values, PrintValue);

    // Can write the function inline using lambda function:
    // []: capture
    ForEach(values,[](int value) {std::cout << "Value (lambda function): " << value << std::endl;});

}