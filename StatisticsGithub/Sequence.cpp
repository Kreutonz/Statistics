//Sequence.cpp

#include "Sequence.h"
#include <algorithm>  //used for sort()
#include <cmath>      //used for sqrt()

using std::sort;

//***************
//PRIVATE-METHODS
//***************


//makes a deep-copy of the parameter Sequence (used in assignment-overload-operator method)
void Sequence::copySequence(const Sequence& toCopy) {
    delete[] arr;                                       //deallocate memory associated with object to change
    currentSize = 0;                                    //reset the currentSize
    maxSize = toCopy.maxSize;
    arr = new double[maxSize];                          //assigns a new array to the pointer
    for(int i = 0; i < toCopy.currentSize; i++){        //copies the contents of parameter array to underlying array
        arr[i] = toCopy.arr[i];
        currentSize++;
    }
}


/*
 * creates a new array in dynamic memory,
 * copies contents of underlying array, deallocates memory and
 * assigns objects pointer to new array
 */
void Sequence::resizeArray() {
    maxSize = maxSize * 2;
    double* temp = new double[maxSize];
    for(int i = 0; i < currentSize; i++){
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}


/*
 * creates a new array in dynamic memory. The underlying array's maximum
 * size is the combined size of underlying array and the size of the
 * array passed in as the parameter. Copies contents of underlying array
 * and array parameter to new array
 */
void Sequence::combineArraysWithAdjustMaxSize(double toInsert[], int& size){
    maxSize = currentSize + size;
    double* temp = new double[maxSize];         //creates a new array based on current size and size of parameter
    for(int i = 0; i < currentSize; i++){       //copies over contents of original array to new array
        temp[i] = arr[i];
    }
    for(int j = 0; j < size; j++){              //copies the contents of parameter array to end of new array
        temp[currentSize] = toInsert[j];
        currentSize++;
    }
    delete[] arr;
    arr = temp;
}


//******************
//PUBLIC-METHODS
//******************


/*
 * default constructor that uses initialization list for currentSize
 * and maxSize variables, creates a new array in dynamic memory based
 * on the maxSize variable
 */
Sequence::Sequence()
: currentSize(0), maxSize(2)
{
    arr = new double[maxSize];
}


/*
 * copy constructor that takes a Sequence object as a parameter
 * and makes a deep copy to the new Sequence object
 */
Sequence::Sequence(const Sequence& toCopy)   //copy constructor
: currentSize(toCopy.currentSize), maxSize(toCopy.maxSize)
{
    arr = new double[toCopy.maxSize];
    for(int i = 0; i < toCopy.currentSize; i++){
        arr[i] = toCopy.arr[i];
    }
}


//destructor that deallocates memory when a Sequence object is out of scope
Sequence::~Sequence(){
    delete[] arr;
    arr = nullptr;
}


/*
 * Assignment-overload-operator takes in a Sequence object and makes a deep-copy
 * to the previously created Sequence object by using the private method copySequence()
 */
Sequence& Sequence::operator=(const Sequence& toCopy) {        //assignment overload
    if(this != &toCopy){
        copySequence(toCopy);
    }
    return *this;
}


/*
 * public method that takes in a double value as a parameter and inserts
 * it at the last available index in the array. If the array is not of a
 * valid size, the objects array-size is changed by calling the resizeArray() method
 */
void Sequence::insert(double toInsert){
    if(currentSize == maxSize){
        resizeArray();
    }
    arr[currentSize] = toInsert;                //insert value at end of current values
    currentSize++;
}


/*
 * inserts an array at the end of the objects array. Two parameters:
 * the array to be added and the size of the array passed into the method.
 * Adjusts underlying array maximum size if it cannot take the values of both
 * arrays.
 */
void Sequence::insert(double toInsert[], int size){
    if((currentSize + size) > maxSize){
        combineArraysWithAdjustMaxSize(toInsert, size);
    }else{
        for(int i = 0; i < size; i++){
            arr[currentSize] = toInsert[i];
            currentSize++;
        }
    }
}


/*
 * passed in a double parameter, searches the Sequence's underlying array.
 * Counts appearances of value in the array and returns the count as an integer.
 */
int Sequence::find(double toFind) const{
    int count = 0;
    for(int i = 0; i < currentSize; i++){
        if(arr[i] == toFind){
            count++;
        }
    }
    return count;
}


//returns the current size of the Sequence's array as an integer
int Sequence::size() const{
    return currentSize;
}


//returns the sum of all values in the Sequence's array as a double
double Sequence::sum() const{
    double sum = 0.0;
    for(int i = 0; i < currentSize; i++){
        sum += arr[i];
    }
    return sum;
}


//calculates the mean (average) of all values in Sequence
double Sequence::mean() const{
    if(currentSize == 0){
        return 0.0;
    }
    double sumOfArr = this->sum();
    return sumOfArr / currentSize;
}


/*
 * searches the Sequence's array for the median (middle) value. Has cases for
 * even-sized array (returns the median of middle two values) and odd-sized array
 */
double Sequence::median() const{
    if(currentSize == 0){                       //returns a median value of 0.0 when the Array is empty
        return 0.0;
    }
    double temp[currentSize];                   //creates a temp array on the stack
    for(int i = 0; i < currentSize; i++){       //copies contents of array to temp array
        temp[i] = arr[i];
    }
    sort(temp, temp + currentSize);   //sort the array

    if(currentSize % 2 == 0){                   //find median for even nums
        int upperIndex = currentSize / 2;
        int lowerIndex = upperIndex - 1;
        return (temp[lowerIndex] + temp[upperIndex]) / 2;
    }else{                                      //find median value for odds
        int index = currentSize / 2;
        return temp[index];
    }
}


/*
 * calculates the standard deviation of the Sequence array
 * standard deviation formula (source: https://www.mathsisfun.com/data/standard-deviation-formulas.html)
 */
double Sequence::stddev() const {
    if(currentSize == 0){
        return 0.0;
    }
    double meanValue = this->mean();
    double sum = 0.0;
    for(int i = 0; i < currentSize; i++){
        double valueToSquare = (arr[i] - meanValue);
        sum += valueToSquare * valueToSquare;
    }
    double meanOfSquareDifferences = sum / currentSize;
    return sqrt(meanOfSquareDifferences);
}


//Creates a new object by combining the values of the calling object and the parameter object
Sequence Sequence::concatenate(const Sequence& toAdd) const {
    Sequence temp = *this;
    temp.insert(toAdd.arr, toAdd.currentSize);
    return temp;
}


