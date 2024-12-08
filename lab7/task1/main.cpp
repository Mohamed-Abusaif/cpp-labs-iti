#include <iostream>

using namespace std;

class GeoShape
{
protected:
  float dim1;
  float dim2;

public:
  GeoShape()
  {
    dim1 = dim2 = 0;
  }

  GeoShape(float x)
  {
    dim1 = dim2 = x;
  }

  GeoShape(float x, float y)
  {
    dim1 = x;
    dim2 = y;
  }

  void setDim1(float x)
  {
    dim1 = x;
  }

  void setDim2(float x)
  {
    dim2 = x;
  }

  float getDim1()
  {
    return dim1;
  }

  float getDim2()
  {
    return dim2;
  }

  float calculateArea()
  {
    return 0;
  }
};

class Triangle : public GeoShape
{
public:
  Triangle(float b, float h) : GeoShape(b, h) {}

  float calculateArea()
  {
    return 0.5 * dim1 * dim2;
  }
};

class Rect : public GeoShape
{
public:
  Rect(float x, float y) : GeoShape(x, y) {}

  float calculateArea()
  {
    return dim1 * dim2;
  }
};

class Circle : private GeoShape
{
public:
  Circle(float r) : GeoShape(r) {}

  void setRadius(float r)
  { // OR we could override: setDim1()
    dim1 = dim2 = r;
  }

  float getRadius()
  { // OR we could override: getDim1()
    return dim1;
  }

  float calculateArea()
  {
    return 22.0 / 7 * dim1 * dim2;
  }
};

class Square : private Rect
{
public:
  Square(float x) : Rect(x, x) {}

  void setSquareDim(float x)
  { // OR we could override: setDim1()
    dim1 = dim2 = x;
  }

  float getSquareDim()
  { // OR we could override: getDim1()
    return dim1;
  }

  float calculateArea()
  { // Overriding calculateArea() of Rect class.
    return Rect::calculateArea();
  }
};

int main()
{
  Triangle triangle(5, 10);
  Rect rectangle(4, 6);
  Circle circle(3);
  Square square(7);

  cout << "Area of triangle: " << triangle.calculateArea() << endl;
  cout << "Area of rectangle: " << rectangle.calculateArea() << endl;
  cout << "Area of circle: " << circle.calculateArea() << endl;
  cout << "Area of square: " << square.calculateArea() << endl;

  return 0;
}
