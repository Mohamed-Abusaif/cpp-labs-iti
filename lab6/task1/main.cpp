#include <iostream>
#include <graphics.h>
#define BLACK  0
#define BLUE  1
#define GREEN  2
#define CYAN  3
#define RED  4
#define MAGENTA 5
#define BROWN  6
#define LIGHTGRAY  7


using namespace std;

class Point {   
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}

    int getX() { return x; }
    int getY() { return y; }
};

class Shape { 
protected:
int color;
public:
Shape(){
color=BLACK;

}
Shape(int x){
color =x;

};
};


class Line :public Shape{ 
private:
    Point start;
    Point end;
public:
    Line() : Shape (BLACK) , start(0,0), end(0,0) {}
    Line(int x1, int y1, int x2, int y2,int color) : Shape (color) , start(x1, y1), end(x2, y2) {}

    void draw() {
         setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};

class Rect :public Shape{ 
private:
    Point ul;
    Point lr;
public:
    Rect() : Shape (BLACK) , ul(0,0), lr(0,0) {}
    Rect(int x1, int y1, int x2, int y2,int color) : Shape (color), ul(x1, y1), lr(x2, y2) {}

    void draw() {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};

class Circle :public Shape{ 
private:
    Point center;
    int radius;
public:
    Circle() : Shape (BLACK), center(0,0), radius(0) {}
    Circle(int m, int n, int r,int color) : Shape (color), center(m, n), radius(r) {}

    void draw() {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};

class Picture { 
private:
    int cNum, rNum, lNum;
    Circle* pCircles;
    Rect* pRects;
    Line* pLines;

public:
    Picture() : cNum(0), rNum(0), lNum(0), pCircles(nullptr), pRects(nullptr), pLines(nullptr) {}

    void setCircles(int cn, Circle* pC) {
        cNum = cn;
        pCircles = pC;
    }

    void setRects(int rn, Rect* pR) {
        rNum = rn;
        pRects = pR;
    }

    void setLines(int ln, Line* pL) {
        lNum = ln;
        pLines = pL;
    }

    void paint() {
        for (int i = 0; i < cNum; i++) {
            pCircles[i].draw();
        }
        for (int i = 0; i < rNum; i++) {
            pRects[i].draw();
        }
        for (int i = 0; i < lNum; i++) {
            pLines[i].draw();
        }
    }
};

int main() {
int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Graphic Mode
    Picture myPic;

    Circle cArr[3] = { Circle(50, 50, 50,RED), Circle(200, 100, 100,CYAN), Circle(420, 50, 30,RED) };
    Rect rArr[2] = { Rect(30, 40, 170, 100,RED), Rect(420, 50, 500, 300,RED) };
    Line lArr[2] = { Line(420, 50, 300, 300,LIGHTGRAY), Line(40, 500, 500, 400,BLUE) };

    myPic.setCircles(3, cArr);
    myPic.setRects(2, rArr);
    myPic.setLines(2, lArr);

    myPic.paint();

    getch();
    getch();

    return 0;
}