// struct:
// https://en.cppreference.com/w/cpp/keyword/struct.html

#include <cmath>
#include <iostream>

struct Point2D
{
    double x;
    double y;

    double magnitude() { return std::sqrt(x * x + y * y); }
};

struct Point3D; // redundantno

struct NamedInt
{
    int value;
    const char* name;
};

struct Point3D
{
    double x;
    double y;
    double z;

    double magnitude() const;
};

int main()
{
  Point3D point3D = Point3D { 1, 2, 3 };
  Point2D point2D = { 2, 3 };
  NamedInt namedInt1 = { 1, "jedan" };
  NamedInt namedInt2 = { 2, "dva" };

  std::cout << "Point3D (" << point3D.x << ", " << point3D.y << ", " << point3D.z << ") -> " << point3D.magnitude() << std::endl;
  std::cout << "Point2D (" << point2D.x << ", " << point2D.y << ") -> " << point2D.magnitude() << std::endl;
  std::cout << "NamedInt1 \"" << namedInt1.name << "\" -> " << namedInt1.value << std::endl;
  std::cout << "NamedInt2 \"" << namedInt2.name << "\" -> " << namedInt2.value << std::endl;
}

double Point3D::magnitude() const
{
  return std::sqrt(x * x + y * y + z * z);
}
