//
// Created by Beşir Kassab on 11.12.2020.
//

#ifndef ASSIGNMENT_3_QUEUE_H
#define ASSIGNMENT_3_QUEUE_H
#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    int size() const;
    //Enqueue: Items are added to the back of the queue
    void enqueue(const T& newItem);
    //Dequeue: Items are removed from the front of the queue
    void dequeue();
    //Get Front: Take a look at the first item
    void getFront(T& queueTop) const;
    string takeFromFront() const;
    void displayQueue() const;

private:
    struct QueueNode {
        T item;
        QueueNode *next = NULL;
    };
    int _size;
    /* to avoid the traversal to the last node,
     an additional pointer to the last node is defined*/
    QueueNode *_frontNode = NULL;
    QueueNode *_lastNode = NULL;
};

template<typename T>
void Queue<T>::getFront(T &queueTop) const {

}

template<typename T>
void Queue<T>::dequeue() {
    if (_frontNode == NULL) {
        return;
    }

    // Store previous front and
    // move front one node ahead
    //QueueNode* temp = getFront();
    _frontNode = _frontNode->next;

    // If front becomes NULL, then
    // change rear also as NULL
    if (_frontNode == NULL) {
        _lastNode = NULL;
    }
    //delete (temp); // dikkat et
}

template<typename T>
void Queue<T>::enqueue(const T &newItem) {
    QueueNode* temp = new QueueNode();
    temp->item = newItem;

    // If queue is empty, then
    // new node is front and rear both
    if (_lastNode == NULL) {
        _frontNode = _lastNode = temp;
        return;
    }

    // Add the new node at
    // the end of queue and change rear
    _lastNode->next = temp;
    _lastNode = temp;
}

template<typename T>
int Queue<T>::size() const {
    /*
     * This function is returning queue size.
     */

    QueueNode* temp = _frontNode;
    int sizeOfQueue = 0;
    if(isEmpty()){
        return sizeOfQueue;
    }else {
        while (temp->next != NULL) {
            sizeOfQueue++;
            temp = temp->next;
        }
        return ++sizeOfQueue;
    }
}

template<typename T>
bool Queue<T>::isEmpty() const {
    /*
     * check if queue is empty.
     */

    if(_lastNode == NULL){
        return true;
    }
    return false;
}
template <typename T>
void Queue<T>::displayQueue() const{
    /*
     * This function is for the visualisation. It reaches every element of the queue.
     */

    QueueNode* temp = _frontNode;
    while(temp != NULL){
        cout << temp->item << endl;
        temp = temp->next;
    }
}

template<typename T>
string Queue<T>::takeFromFront() const{
    /*
     * Returning the front element of the stack.
     */

    if (_frontNode == NULL) {
        cout << "Error, NO TRUCK" << endl;
        return "";
    }
    string theCar = _frontNode->item;

    return theCar;
}

template<typename T>
Queue<T>::~Queue() {

}

template<typename T>
Queue<T>::Queue() {

}


#endif //ASSIGNMENT_3_QUEUE_H
