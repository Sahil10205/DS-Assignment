#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define QUEUE_SIZE 256 

class Queue {
    char arr[QUEUE_SIZE]; 
    int front, rear;
public:
    Queue() : front(-1), rear(-1) {}

    bool empty() const { 
        return (front == -1 || front > rear); 
    }

    void enqueue(char x) {
        if (rear == QUEUE_SIZE - 1) {
            return;
        } 
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = x;
    }

    void dequeue() {
        if (empty()) {
            return;
        }
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }

    char frontVal() const {
        if (empty()) {
            return '\0'; 
        } 
        return arr[front];
    }
};

int main() {
    string s; 
    getline(cin, s);

    Queue q; 
    int freq[256] = {0}; 
    
    for (char c : s) {
        freq[(unsigned char)c]++;
        q.enqueue(c);

        while (!q.empty() && freq[(unsigned char)q.frontVal()] > 1) {
            q.dequeue();
        }

        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.frontVal() << " ";
        }
    }
    cout << endl;

    return 0;
}