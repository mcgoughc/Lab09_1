//
// Created by Chase McGough on 10/10/17.
//

#include <iostream>
#include "ArrayList.h"
#include "ArrayLib.h"

//Constructor
ArrayList::ArrayList(int initialCapacity) {
    array = new int[initialCapacity];
    currCapacity = initialCapacity;
    currItemCount = 0;
}


//Copy Constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy) {
    currItemCount = arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;

    array = new int[currCapacity];
    for (int i = 0; i < currItemCount; ++i) {
        array[i] = arrayListToCopy.array[i];
    }
}


//Overloaded Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList &arrayListToCopy) {
    if(this != &arrayListToCopy){
        delete[] array;

        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;

        array = new int[currCapacity];
        for (int i = 0; i < currItemCount; ++i) {
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}


//Destructor
ArrayList::~ArrayList() {
    delete[] array;
}


void ArrayList::doubleCapacity() {
    int linesRun = 0;
    int* tempArray = copyArray(array, currItemCount, linesRun);

    delete[] array;
    currCapacity = currCapacity*2;
    array = new int[currCapacity];


    for (int j = 0; j < currItemCount; ++j) {
        array[j] = tempArray[j];
    }

    delete[] tempArray;
    tempArray = nullptr;
}


void ArrayList::insertAtEnd(int itemToAdd) {
    if(currCapacity-2 <= currItemCount){
        doubleCapacity();
    }

    array[currItemCount] = itemToAdd;
    currItemCount++;
}


void ArrayList::insertAtFront(int itemToAdd) {
    if(currItemCount == currCapacity) {
        doubleCapacity();
    }

    for (int i = currItemCount-1; i > -1; i--) {
        array[i+1] = array[i];
    }

    array[0] = itemToAdd;
    currItemCount++;
}


void ArrayList::insertAt(int itemToAdd, int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("<Index not in range>");
    }

    //std::cout << "index in method: " << index << std::endl;
    if(currItemCount == currCapacity) {
        doubleCapacity();
    }

    for (int i = currItemCount-1; i >= index; i--) {
        array[i+1] = array[i];
    }

    array[index] = itemToAdd;
    currItemCount++;
}


int ArrayList::getValueAt(int index) {
    if(index < currItemCount && index >= 0){
        return array[index];
    } else{
        throw std::out_of_range("<Index not in range>");
    }
}


int ArrayList::removeValueAt(int index) {
    if(index < 0 || index > currItemCount){
        throw std::out_of_range("Index not in range");
    }

    int output = array[index];
    int linesRun = 0;
    currItemCount--;

    for (int i = index; i < currItemCount; ++i) {
        array[i] = array[i+1];
    }

    return output;
}


bool ArrayList::isEmpty() {
    return currItemCount == 0;
}


int ArrayList::itemCount() {
    return currItemCount;
}


void ArrayList::clearList() {
    currItemCount = 0;
}


std::string ArrayList::toString() {
    return ::toString(array, currItemCount);
}


int ArrayList::findMaxIndex() {
    int linesRun = 0;
    return ::findMaxIndex(array, currItemCount, linesRun);
}


int ArrayList::find(int numToFind) {
    int LinesRun = 0;
    return ::find(array, currItemCount, numToFind, LinesRun);
}


int ArrayList::findLast(int numToFind) {
    int linesRun = 0;
    return ::findLast(array, currItemCount, numToFind, linesRun);
}


