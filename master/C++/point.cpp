#include <iostream>
#include <math.h>
//实现点，线，圆，球体，求圆的周长和面积，球体的面积和体积

class point {
  private:
    int x;
    int y;
    int z;

  public:
    point(int xx, int yy, int zz) : x(xx), y(yy), z(zz){};
    ~point(){};
    void print() {
        std::cout << "(x = " << x << "y = " << y << "z= " << z << ")"
                  << std::endl;
    }
    int getx() { return x; }
    int gety() { return y; }
    int getz() { return z; }
};

class line {
  private:
    point start;
    point end;

  public:
    line(point p1, point p2) : start(p1), end(p2){};
    ~line(){};
    double length() {
        int lenx = end.getx() - start.getx();
        int leny = end.gety() - start.gety();
        int lenz = end.getz() - start.getz();
        //		std::cout<<lenx<<"\t"<<leny<<"\t"<<lenz<<std::endl;
        return sqrt(lenx * lenx + leny * leny + lenz * lenz);
    }
};

class yuan : public line {
  public:
    yuan(point center, point end) : line(center, end) {}

    double getmianji() {
        return 3.1415926 * ((this->length()) * (this->length()));
    }

    double getzhouchang() { return 3.1415926 * 2 * (this->length()); }
};

class qiu : public yuan {
  public:
    qiu(point p1, point p2) : yuan(p1, p2) {}

    double getmianji() {
        return 3.1415926 * (this->length()) * (this->length()) * 4;
    }

    double gettiji() {
        return 4 / 3 * 3.1415926 * (this->length()) * (this->length()) *
               (this->length());
    }
};

int main() {
    point p1(0, 0, 0);
    point p2(0, 0, 10);
    p1.print();
    p2.print();
    line line1(p1, p2);
    std::cout << line1.length() << std::endl;

    yuan yuan1(p1, p2);
    std::cout << "yuan mianji-> " << yuan1.getmianji() << std::endl;
    std::cout << "yuan zhouchang-> " << yuan1.getzhouchang() << std::endl;

    qiu qiu1(p1, p2);
    std::cout << "qiu mianji-> " << qiu1.getmianji() << std::endl;
    std::cout << "qiu tiji-> " << qiu1.gettiji() << std::endl;
    return 0;
}
