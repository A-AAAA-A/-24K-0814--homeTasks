#include <iostream>
#include <string>

struct StudentNode {
    std::string name;
    int score;
    StudentNode* next;

    StudentNode(std::string n, int s) : name(n), score(s), next(nullptr) {}
};

struct Bucket {
    StudentNode* head;
    StudentNode* tail;

    Bucket() : head(nullptr), tail(nullptr) {}
};

int powerOfTen(int place) {
    int power = 1;
    for (int i = 0; i < place; ++i) {
        power *= 10;
    }
    return power;
}

int getDigit(int number, int place) {
    int divisor = powerOfTen(place);
    return (number / divisor) % 10;
}

void addToBucket(Bucket& bucket, StudentNode* node) {
    node->next = nullptr; 

    if (!bucket.head) {
        bucket.head = node;
        bucket.tail = node;
    } else {
        bucket.tail->next = node;
        bucket.tail = node;
    }
}

void RadixSort(StudentNode*& head) {
    if (!head || !head->next) {
        return; 
    }

    const int maxDigits = 3; 

    Bucket buckets[10]; 

    for (int d = 0; d < maxDigits; ++d) {
        StudentNode* current = head;
        while (current) {
            int digit = getDigit(current->score, d);
            StudentNode* nextNode = current->next;
            
            addToBucket(buckets[digit], current);

            current = nextNode;
        }

        head = nullptr;
        StudentNode* tail = nullptr;

        for (int i = 0; i < 10; ++i) {
            if (buckets[i].head) {
                if (!head) {
                    head = buckets[i].head;
                    tail = buckets[i].tail;
                } else {
                    tail->next = buckets[i].head;
                    tail = buckets[i].tail;
                }

                buckets[i].head = nullptr;
                buckets[i].tail = nullptr;
            }
        }
        if (tail) {
            tail->next = nullptr;
        }
    }
}

void displayList(StudentNode* head) {
    StudentNode* current = head;
    while (current) {
        std::cout << "Name: " << current->name << ", Score: " << current->score << "\n";
        current = current->next;
    }
}

void cleanupList(StudentNode* head) {
    StudentNode* current = head;
    while (current) {
        StudentNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    StudentNode* head = new StudentNode("Alice", 95);
    head->next = new StudentNode("Bob", 12);
    head->next->next = new StudentNode("Charlie", 100);
    head->next->next->next = new StudentNode("Diana", 5);
    head->next->next->next->next = new StudentNode("Eve", 87);
    head->next->next->next->next->next = new StudentNode("Frank", 42);
    head->next->next->next->next->next->next = new StudentNode("Grace", 10);
    head->next->next->next->next->next->next->next = new StudentNode("Henry", 77);

    std::cout << "Original Unsorted List:\n";
    displayList(head);
    std::cout << "\n";

    RadixSort(head);

    std::cout << "Sorted List by Score (Ascending):\n";
    displayList(head);

    cleanupList(head);

    return 0;
}
