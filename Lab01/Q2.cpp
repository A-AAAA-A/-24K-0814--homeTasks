#include <iostream>
using namespace std;

class Box {
private:
    int* val;

public:
    
    Box() {
        val = new int(0);
    }

    Box(const int& v) {
        val = new int(v);
    }

    Box(const Box& other) {
        val = new int(*(other.val));
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete val;
            val = new int(*(other.val));
        }
        return *this;
    }

    ~Box() {
        delete val;
    }

    void setVolume(int newVal) {
        *val = newVal;
    }

    void display() const {
        cout << "Volume: " << *val << endl;
    }
};

int main() {
    Box box1(10);
    cout << "Box1: ";
    box1.display();

    Box box2 = box1;  
    box2.setVolume(25);

    cout << "After modifying Box2:" << endl;
    cout << "Box1: ";
    box1.display();  
    cout << "Box2: ";
    box2.display();  

    return 0;
}
