//
// Created by Chase McGough on 9/5/17.
//

#include <iostream>
#include <string>
#include "ArrayLib.h"


std::string toString(const int *arrayPtr, int size) {
    std::string output = "{";

    if (size < 1) {
        output += "}";
    } else {
        for (int i = 0; i < size; ++i) {
            output += std::to_string(arrayPtr[i]) + ", ";
        }
        output.erase(output.end() - 2, output.end());
        output += "}";
    }

    return output;
}


int findMaxIndex(const int *arrayPtr, int size, int &numLinesRun) {
    numLinesRun += 3;

    if (size < 1) {
        return -1;
    }

    int position = 0;
    int max = arrayPtr[0];
    bool found = false;
    numLinesRun += 4;

    numLinesRun += 2;
    for (int i = 0; i < size; ++i) {
        if (arrayPtr[i] > max) {
            max = arrayPtr[i];
            position = i;
            found = true;
            numLinesRun += 3;
        }
        numLinesRun += 3;
    }

    numLinesRun+=1;
    if(found){
        return position;
    }else{
        return false;
    }

}


int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun){
    numLinesRun += 4;
    if(size <= 0){
        return -1;
    }
    numLinesRun+=3;
    for (int i = 0; i < size; ++i) {
        if(arrayPtr[i] == numToFind){
            return i;
        }
        numLinesRun+=3;
    }
    return -1;
}


int findLast(const int* arrayPtr, int size, int numToFind, int &numLinesRun) {
    numLinesRun += 7; //Parameter and For loop

    for (int i = size - 1; i > 0; i--) { //For the length of the array:
        if (arrayPtr[i] == numToFind) { //Check if the data at i matches the number to find
            return i;
        }
        numLinesRun += 3; //Inside for loop
    }

    return -1;
}


int binFind(const int *arrayPtr, int min, int max, int numToFind, int& numLinesRun) { //TAIL
    numLinesRun += 5; //Parameters

    if (min <= max) { //If end values are different
        int middle = (min + max) / 2; //Calculate middle value
        numLinesRun += 2; //Beginning of If

        if (arrayPtr[middle] > numToFind) { //If current value is greater than middle value
            numLinesRun += 2; //If and recursive call

            return binFind(arrayPtr, min, middle - 1, numToFind, numLinesRun); //Call binary search on bottom half of array

        } else if (arrayPtr[middle] < numToFind) { //If current value is less than middle value
            numLinesRun += 2; //If and recursive call

            return binFind(arrayPtr, middle + 1, max, numToFind, numLinesRun); //Call binary search on top half of array

        } else {
            numLinesRun += 1; //Else and recursive call

            return middle; //If neither, return middle index

        }

    } else {
        numLinesRun += 1; //Else and recursive call

        return -1; //If ends of array are the same, return -1

    }
}


int binFind(const int *arrayPtr, int size, int numToFind, int& numLinesRun) {
    numLinesRun += 5; //Parameters and recursive call
    return binFind(arrayPtr, 0, size - 1, numToFind, numLinesRun); //Call binary search with top and bottom values
}


int genRandInt(int min, int max, int &numLinesRun) {
    numLinesRun += 3; //Parameters

    int randNum;
    randNum = rand() % (max - min + 1) + min;
    numLinesRun += 2; //Random number

    return randNum;
}


int *genRandArray(int size, int min, int max, int &numLinesRun) {
    numLinesRun += 4; //Parameters

    if (min > max) { //If min is greater than max: Swap values
        int temp = min;
        min = max;
        max = temp;
        numLinesRun += 3; //If interior
    }
    numLinesRun += 1; //If statement

    int *newRandArr = new int[size];

    numLinesRun += 3; //New array and beginning of loop
    for (int i = 0; i < size; ++i) { //For each index:
        newRandArr[i] = genRandInt(min, max, numLinesRun); //Get a random number in the range
        numLinesRun += 3; //For interior
    }

    return newRandArr;

}


int *genShuffledArray(int size, int &numLinesRun) {
    if (size < 1) {
        return nullptr;
    }
    numLinesRun += 3; //check size and setup parameters

    int *newShufArr = new int[size];
    int rand;
    int temp;
    numLinesRun += 5; //Initialize variables and for loop

    for (int j = 0; j <= size; ++j) {
        newShufArr[j] = j + 1; //Write all numbers in order, to array, with offset to start at 1
        numLinesRun += 3; //Internal For
    }

    numLinesRun += 2; //For loop setup
    for (int i = 0; i < size; ++i) {
        rand = genRandInt(0, size - 1, numLinesRun); //Get random index
        temp = newShufArr[i]; //Write value to holding variable
        //std::cout << "idx: " << i << " rand: " << rand << std::endl;
        //std::cout << "temp: " << temp << " rand val: " << newShufArr[rand] << std::endl;
        newShufArr[i] = newShufArr[rand]; //Swap current value with value at rand
        newShufArr[rand] = temp; //Write original value to rand


        numLinesRun += 6; //internal for
    }

    //std::cout << toString(newShufArr, size) << std::endl; //This may be necessary for function to work. Unsure of why.

    return newShufArr;
}


int *copyArray(const int *arrayToCopy, int size, int &numLinesRun) {
    numLinesRun += 3; //Parameters
    int* dupArray = new int[size];
    numLinesRun += 3; //Variables and For loop

    for (int i = 0; i < size; ++i) { //For the length of the array to be copied
        dupArray[i] = arrayToCopy[i]; //Record each piece of data to the new array
        numLinesRun += 3; //Inside For loop
    }

    return dupArray;
}


void sort(int *arrayToSort, int size, int &numLinesRun) { //Bubble sort
    numLinesRun += 3; //Parameter setup

    int temp;
    numLinesRun += 3; //Variables and for loop

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arrayToSort[j] > arrayToSort[j + 1]) { //If current value is greater than next value

                temp = arrayToSort[j]; //Write current value to temp location
                arrayToSort[j] = arrayToSort[j + 1]; //Write next value to current index
                arrayToSort[j + 1] = temp; //Write original value to next index

                numLinesRun += 3; //Inside If
            }

            numLinesRun += 3; //Internal for
        }

        numLinesRun += 4; //Internal for
    }
}

int* merge(const int *a1, int size1, const int *a2, int size2, int &numLinesRun) {
    int size3 = size1 + size2;
    int* mergedArr = new int[size3];
    int a1Idx = 0;
    int a2Idx = 0;
    int a3Idx = 0;
    numLinesRun += 9;

    while(a3Idx < size3){
        if(a1Idx < size1 && a2Idx < size2){
            if(a1[a1Idx] <= a2[a2Idx]){
                mergedArr[a3Idx] = a1[a1Idx];
                a1Idx++;
                a3Idx++;
            } else{
                mergedArr[a3Idx] = a2[a2Idx];
                a2Idx++;
                a3Idx++;
            }
        } else if(a1Idx < size1){
            mergedArr[a3Idx] = a1[a1Idx];
            a1Idx++;
            a3Idx++;
        } else if(a2Idx < size2){
            mergedArr[a3Idx] = a2[a2Idx];
            a2Idx++;
            a3Idx++;
        }


    }

    return mergedArr;
}

int *mergesort(const int *arrayToSort, int size, int &numLinesRun) {
    return nullptr;
}