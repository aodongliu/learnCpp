#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) {
        std::cout << "Constructed" << std::endl;
    }
    
    Vertex(const Vertex& other) 
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Copied" << std::endl;
    }

    Vertex(Vertex&& other) 
        : x(other.x), y(other.y), z(other.z)
    {
        std::cout << "Moved" << std::endl;
    }
};


std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;

}

void Function(const std::vector<Vertex>& vertex){

}

int main(){

    std::cout << "Push back"    << std::endl;
    std::vector<Vertex> vertices;
    // create on main function stack, and copied to vertices object 
    vertices.push_back(Vertex(1,2,3));

    // two more copies
    vertices.push_back(Vertex(4,5,6));

    // three more copies
    vertices.push_back(Vertex(7,8,9));
    std::cout << std::endl;


    std::cout << "Reserve and Push back"    << std::endl;
   // use reserve, total 3 copies
   
   std::vector<Vertex> vertices1;
   Vertex v1(1,2,3), v2(4,5,6), v3(7,8,9);
   vertices1.reserve(3);
   vertices1.push_back(v1);
   vertices1.push_back(v2);
   vertices1.push_back(v3);
    std::cout << std::endl;
    


   // using emplace back, no copies
   std::cout << "Reserve and Emplace back"    << std::endl;
   std::vector<Vertex> vertices2;
   vertices2.reserve(3);
   vertices2.emplace_back(1,2,3);
   vertices2.emplace_back(4,5,6);
   vertices2.emplace_back(7,8,9);
    std::cout << std::endl;


}