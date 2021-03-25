#include <iostream>
using namespace std;

const float PI = 3.141593;
const float FENCE_PRICE = 35;
const float CONCRETE_PRICE = 20;

class Circle
{
public:
    Circle(float r);
    float circumference();
    float area();

private:
    float radius;
};

Circle::Circle(float r)
{
    radius = r;
}

// // Circle类的构造函数亦可这样写
// Circle::Circle(float r) : radius(r){}

float Circle::circumference()
{
    return 2 * PI * radius;
}

float Circle::area()
{
    return PI * radius * radius;
}

int main()
{
    float radius;
    cin >> radius;
    Circle pool(radius);
    Circle poolRim(radius + 3);

    float fenceCost = poolRim.circumference() * FENCE_PRICE;

    cout << "The price is " << fenceCost << endl;

    float concreteCost = (poolRim.area() - pool.area()) * CONCRETE_PRICE;

    cout << "The price is " << concreteCost << endl;

    return 0;
}