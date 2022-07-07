#include <iostream>

int main()
{
    int example[5];
    int* ptr = example;
    for (int i = 0; i < 5; i++) 
        example[i] = 2;

    example[2] = 5;
    //*(ptr+2)  = 6;
    *(int*) ((char*)ptr + 8)=6;
    *(int*) ((char*)ptr + 4)=6;


    // do it on the heap
    int* another = new int[5];

    for (int i = 0; i < 5; i++) 
        another[i] = 2;

    delete[] another;

    std::cout << example[0] <<std::endl;
    std::cout << example <<std::endl;

    std::cin.get();
}