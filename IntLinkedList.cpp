//
// Created by Chase McGough on 10/31/17.
//

#include "IntLinkedList.h"
#include <iostream>

//Constructor
IntLinkedList::IntLinkedList() {
    currItemCount = 0;
    front = nullptr;
    end = nullptr;
}

//Copy Constructor
IntLinkedList::IntLinkedList(const IntLinkedList &listToCopy) {
    currItemCount = listToCopy.currItemCount;
    if(listToCopy.front == nullptr){
        front = nullptr;
        end = nullptr;
    }else{
        LinkedNode* curr = listToCopy.front;
        LinkedNode* newNode = new LinkedNode(curr->getItem());
        front = newNode;
        end = newNode;
        curr = curr->getNext();

        while(curr != listToCopy.end){
            insertAtEnd(curr->getItem());
            curr = curr->getNext();
        }
        insertAtEnd(listToCopy.end->getItem());
    }
}

//Assignment Operator
IntLinkedList& IntLinkedList::operator=(const IntLinkedList &listToCopy) {
    if(this != &listToCopy){
        clearList();
        currItemCount = listToCopy.currItemCount;
        
        if(listToCopy.front == nullptr){
            front = nullptr;
            end = nullptr;
        }else{
            LinkedNode* curr = listToCopy.front;

            while(curr->getNext() != nullptr){
                insertAtEnd(curr->getItem());
                curr = curr->getNext();
            }
            insertAtEnd(listToCopy.end->getItem());
        }
    }

    return *this;

}

//Destructor
IntLinkedList::~IntLinkedList() {
    while (!isEmpty() && front->getNext() != nullptr){
        LinkedNode* temp = front;
        front = front->getNext();
        currItemCount--;
        delete temp;
    }
    delete front;
    front = nullptr;
    end = nullptr;

}

//Add item to end
void IntLinkedList::insertAtEnd(int itemToAdd) {
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if(front == nullptr){
        front = newNode;
        end = newNode;
    } else{
        end->setNext(newNode);
        end = newNode;
    }
    currItemCount++;

}

//Add item to front
void IntLinkedList::insertAtFront(int itemToAdd) {
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if(front == nullptr){
        front = newNode;
        end = newNode;
    } else{
        newNode->setNext(front);
        front = newNode;
    }
    currItemCount++;

}

//Add item at index
void IntLinkedList::insertAt(int itemToAdd, int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }
    LinkedNode* newNode = new LinkedNode(itemToAdd);
    if(index == 0){
        newNode->setNext(front);
        front = newNode;
        currItemCount++;
    }else {
        LinkedNode *first = front;
        int count = 0;
        while (first->getNext() != nullptr && count < index - 1) {
            first = first->getNext();
            count++;
        }
        LinkedNode *last = first->getNext();

        first->setNext(newNode);
        newNode->setNext(last);
        currItemCount++;
    }

}

//Return value at index
int IntLinkedList::getValueAt(int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }
    LinkedNode* curr = front;
    for (int i = 0; i < index; ++i) {
        curr = curr->getNext();
    }
    return curr->getItem();

}

//Remove value at index
int IntLinkedList::removeValueAt(int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }
    int output = 0;
    LinkedNode* toDelete = front;

    if(index == 0){
        front = front->getNext();
        output = toDelete->getItem();

    }else {
        LinkedNode *first = front;
        int count = 0;
        while (toDelete->getNext() != nullptr && count < index) {
            first = toDelete;
            toDelete = toDelete->getNext();
            count++;
        }

        if (toDelete == front) {
            front = front->getNext();
        } else {
            first->setNext(toDelete->getNext());
        }
        int output = toDelete->getItem();
    }

    delete toDelete;
    toDelete = nullptr;
    currItemCount--;
    return output;
}

//Return if there are no items
bool IntLinkedList::isEmpty() {
    return currItemCount==0;
}

int IntLinkedList::itemCount(){
    return currItemCount;
}

//Clear items from list
void IntLinkedList::clearList() {
    while(!isEmpty() && front->getNext() != nullptr){
        LinkedNode* temp = front;
        front = front->getNext();
        currItemCount--;
        delete temp;
    }

    currItemCount = 0;
    delete front;
    front = nullptr;
    end = nullptr;
}

//Print list as a string
std::string IntLinkedList::toString() {
    LinkedNode* curr = front;
    std::string output = "{";
    while(curr != nullptr){
        output += std::to_string(curr->getItem()) + ", ";
        curr = curr->getNext();
    }

    output.erase(output.end()-2, output.end());
    output += "}";
    return output;

}

//Return index of max value
int IntLinkedList::findMaxIndex() {
    if(front == nullptr){
        return -1;
    }
    int max = front->getItem();
    int idx = 0;
    int count = 0;
    LinkedNode* curr = front;

    while(curr != nullptr){
        if(curr->getItem() > max){
            max = curr->getItem();
            idx = count;
        }
        curr = curr->getNext();
        count++;
    }
    return idx;

}

//Return index of first iteration numToFind
int IntLinkedList::find(int numToFind) {
    int idx = -1;
    int count = 0;
    bool found = false;
    LinkedNode* curr = front;

    while (curr != nullptr && !found){
        if(curr->getItem() == numToFind){
            idx = count;
            found = true;
        }
        curr = curr->getNext();
        count++;
    }
    return idx;

}

//Return index of last iteration numToFind
int IntLinkedList::findLast(int numToFind) {
    int idx = -1;
    int count = 0;
    LinkedNode* curr = front;

    while(curr != nullptr){
        if(curr->getItem() == numToFind){
            idx = count;
        }
        curr = curr->getNext();
        count++;

    }
    return idx;

}