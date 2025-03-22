#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdlib>
using namespace std;
 
// A kuyrugundan B yiginina aktarma
class Queue
{
    stack<int> A, B;
 
public:
    // Kuyruga eleman ekleme
    void enqueue(int data)
    {
        // Ogeyi ilk yigina it
        A.push(data);
    }
 
    // Kuyruktan eleman silme
    int dequeue()
    {
        // iki yiginda bos ise
        if (A.empty() && B.empty())
        {
            cout << "Underflow!!";
            exit(0);
        }
 
        // ikinci yigin bos ise elemanlari birinci yigindan ikinci yigina tasi
        if (B.empty())
        {
            while (!A.empty())
            {
                B.push(A.top());
                A.pop();
            }
            
        }
 
        // ikinci yiginin en üstündeki degeri dondur
        int top = B.top();
        B.pop();
        return top;
    }
};
 
int main()
{
    int values[] = { 1, 2, 3, 4, 5 };
    Queue q;
 
    // degerleri ata
    for (int i =0; i<5 ;i++) {
        q.enqueue(values[i]);
    }
 
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl; 
 
    return 0;
}
