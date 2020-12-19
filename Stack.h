//
// Created by Beşir Kassab on 11.12.2020.
//

#ifndef ASSIGNMENT_3_STACK_H
#define ASSIGNMENT_3_STACK_H
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    int size() const;

    //Push: Place item on top of the stack
    void push(const T& newItem);
    //Top: Take a look at the topmost item without removing it
    void getTop(T& stackTop) const;
    //Pop: Remove item from the top of the stack
    void pop();

    string takeFromFront() const;
    void displayStack() const;
private:
    struct ListNode {
        T item;
        ListNode* next = NULL;
    };
    ListNode* _head = NULL;
    int _size = size();

};

template<typename T>
void Stack<T>::push(const T &newItem) {
    struct ListNode* temp;
    temp = new ListNode();

    // Check if stack is full.
    // Then inserting an element would
    // lead to stack overflow
    if (!temp){
        cout << "\nHeap Overflow";
    }
    // Initialize data into temp data field
    // Put top pointer reference into temp link
    // Make temp as top of Stack
    temp->item = newItem;
    temp->next = _head;
    _head = temp;

}

template<typename T>
void Stack<T>::getTop(T &stackTop) const {
    if (isEmpty()) {
        // stack boş değilse headi verir
        return stackTop;
    }
    else{
        // stack boşsa burası
        cout << "Stack boş" << endl;
    }
}

template<typename T>
void Stack<T>::pop() {
    struct ListNode* temp;

    // Check for stack underflow
    if (isEmpty()){
        cout << "Stack bos " << endl;
        //stack boşsa burası
    }
    else{
        // Top assign into temp
        // Assign second node to top
        // Destroy connection between
        // first and second
        temp = _head;
        _head = _head->next;
        temp->next = NULL;

        //en üstteki elemanı çıkarıp headi bir alttakine eşitler
    }
}



template<typename T>
int Stack<T>::size() const {
    /*
     * Stack sizeını döndüren fonksiyondur.
     */

    struct ListNode* temp = _head;
    int sizeOfStack = 0;

    if(isEmpty()){
        return sizeOfStack;
    }else {
        while (temp->next != NULL) {
            sizeOfStack++;
            temp = temp->next;
        }
        return ++sizeOfStack;
    }
}

template<typename T>
bool Stack<T>::isEmpty() const {
    // check stack if empty or not.
    if(_head == NULL){
        return true;}
    return false;
}

template<typename T>
void Stack<T>::displayStack() const {
    /*
     * This function is for the visualisation. It reaches every element of the stack.
     */

    struct ListNode* temp = _head;
    while(temp != NULL){
        cout << temp->item << endl;
        temp = temp->next;
    }
}

template<typename T>
string Stack<T>::takeFromFront() const {
    /*
     * Returning the head element of the stack.
     */

    struct ListNode* temp;

    if (isEmpty()){
        cout << "Stack bos " << endl;
        return "";
    }
    temp = _head;
    return temp->item;
}

template<typename T>
Stack<T>::Stack() {

}

template<typename T>
Stack<T>::~Stack() {

}

#endif //ASSIGNMENT_3_STACK_H
