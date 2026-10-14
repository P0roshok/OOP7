#include <iostream>
using namespace std;

class B1 {
    int b1;
public:
    B1(int x) {
        b1 = x;
    }
    void show_B1() {
        cout << "B1 = " << b1 << endl;
    }
};
class B2 {
    int b2;
public:
    B2(int x) {
        b2 = x;
    }
    void show_B2() {
        cout << "B2 = " << b2 << endl;
    }
};

class D1 : 
public B1, 
private B2 {
    int d1;
public:
    D1(int x, int y, int z) : B1(y), B2(z) {
        d1 = x;
    }
    void show_D1() {
        cout << "D1 = " << d1 << endl;
        show_B1();
        show_B2();
    }
};

class D2 : 
private D1 {
    int d2;
public:
    D2(int x, int y, int z, int j) : D1(y, z, j) {
        d2 = x;
    }
    void show_D2() {
        cout << "D2 = " << d2 << endl;
        show_D1();
    }
};

class D3 : public D2 {
    int d3;
public:
    D3(int x, int y, int z, int j, int k) : D2(y, z, j, k) {
        d3 = x;
    }
    void show_D3() {
        cout << "D3 = " << d3 << endl;
        show_D2();
    }
};

int main() {
    D3 obj(1, 2, 3, 4, 5);

    obj.show_D3();

    return 0;
}
