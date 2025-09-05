#include <iostream>
#include <string>
using namespace std;

class ResearchPaper {
private:
    string* authorList;
    int numAuthors;

public:
    
    ResearchPaper(int count) {
        numAuthors = count;
        authorList = new string[numAuthors];
    }

    ResearchPaper(const ResearchPaper& other) {
        numAuthors = other.numAuthors;
        authorList = new string[numAuthors];
        for (int i = 0; i < numAuthors; ++i) {
            authorList[i] = other.authorList[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& rhs) {
        if (this != &rhs) {
            delete[] authorList;
            numAuthors = rhs.numAuthors;
            authorList = new string[numAuthors];
            for (int i = 0; i < numAuthors; ++i) {
                authorList[i] = rhs.authorList[i];
            }
        }
        return *this;
    }

    ~ResearchPaper() {
        delete[] authorList;
    }

    void setAuthor(const string& name, int index) {
        if (index >= 0 && index < numAuthors) {
            authorList[index] = name;
        }
    }

    void showAuthors() const {
        for (int i = 0; i < numAuthors; ++i) {
            cout << authorList[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ResearchPaper paper1(3);
    paper1.setAuthor("saadi", 0);
    paper1.setAuthor("kamil", 1);
    paper1.setAuthor("usman", 2);

    cout << "Paper 1 Authors: ";
    paper1.showAuthors();

    ResearchPaper paper2 = paper1;  
    paper2.setAuthor("bhide", 1);
    cout << "Paper 2 Authors (after change): ";
    paper2.showAuthors();

    ResearchPaper paper3(3);
    paper3 = paper1;  
    paper3.setAuthor("jethalal", 2);
    cout << "Paper 3 Authors (after assignment and change): ";
    paper3.showAuthors();

    return 0;
}
