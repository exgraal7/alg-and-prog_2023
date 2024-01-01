#include <iostream>

// Начало вставленного кода
class Vector;

class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    void move(const Vector& vec);
};

class Vector {
public:
    int x, y;

    Vector(const Point& start, const Point& end) : x(end.x - start.x), y(end.y - start.y) {}
};

void Point::move(const Vector& vec) {
    x += vec.x;
    y += vec.y;
}
// Конец вставленного кода

int main(){
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    
    Point p(x1, y1);
    Vector dir(Point(x2, y2), Point(x3, y3));
    p.move(dir);
    
    std::cout << p.x << ' ' << p.y;
}
