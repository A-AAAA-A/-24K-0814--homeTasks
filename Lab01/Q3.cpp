#include <iostream>
using namespace std;

class Exam {
private:
    int* score;

public:
    Exam(const int& m) {
        score = new int(m);
    }

    ~Exam() {
        delete score;
    }

    void update(int newScore) {
        *score = newScore;
    }

    void display() const {
        cout << "Score: " << *score << endl;
    }
};

int main() {
    Exam exam1(60);
    Exam exam2 = exam1;  

    exam2.update(95);    

    cout << "Exam1 after modifying Exam2: ";
    exam1.display();     

    cout << "Exam2: ";
    exam2.display();     

    return 0;
}
