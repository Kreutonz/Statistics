//Sequence.h

#pragma once

class Sequence {
private:
    //private variables
    double* arr;
    int currentSize;
    int maxSize;


    //makes a deep-copy of the parameter Sequence (used in assignment-overload-operator method)
    void copySequence(const Sequence& toCopy);


    /*
    * creates a new array in dynamic memory,
    * copies contents of underlying array, deallocates memory and
    * assigns objects pointer to new array
    */
    void resizeArray();


    /*
    * creates a new array in dynamic memory. The underlying array's maximum
    * size is the combined size of underlying array and the size of the
    * array passed in as the parameter. Copies contents of underlying array
    * and array parameter to new array
    */
    void combineArraysWithAdjustMaxSize(double toInsert[], int& size);


public:
    /*
    * default constructor that uses initialization list for currentSize
    * and maxSize variables, creates a new array in dynamic memory based
    * on the maxSize variable
    */
    Sequence();


    /*
     * copy constructor that takes a Sequence object as a parameter
     * and makes a deep copy to the new Sequence object
     */
    Sequence(const Sequence& toCopy);


    //destructor that deallocates memory when a Sequence object is out of scope
    ~Sequence();


    /*
     * Assignment-overload-operator takes in a Sequence object and makes a deep-copy
     * to the previously created Sequence object by using the private method copySequence()
     */
    Sequence& operator=(const Sequence& toCopy);


    /*
     * public method that takes in a double value as a parameter and inserts
     * it at the last available index in the array. If the array is not of a
     * valid size, the objects array-size is changed by calling the resizeArray() method
     */
    void insert(double toInsert);


    /*
     * inserts an array at the end of the objects array. Two parameters:
     * the array to be added and the size of the array passed into the method.
     * Adjusts underlying array maximum size if it cannot take the values of both
     * arrays.
     */
    void insert(double toInsert[], int size);


    /*
     * passed in a double parameter, searches the Sequence's underlying array.
     * Counts appearances of value in the array and returns the count as an integer.
     */
    int find(double toFind) const;


    //returns the current size of the Sequence's array as an integer
    int size() const;


    //returns the sum of all values in the Sequence's array as a double
    double sum() const;


    //calculates the mean (average) of all values in Sequence
    double mean() const;


    /*
     * searches the Sequence's array for the median (middle) value. Has cases for
     * even-sized array (returns the median of middle two values) and odd-sized array
     */
    double median() const;


    /*
     * calculates the standard deviation of the Sequence array
     * standard deviation formula (source: https://www.mathsisfun.com/data/standard-deviation-formulas.html)
     */
    double stddev() const;


    //Creates a new object by combining the values of the calling object and the parameter object
    Sequence concatenate(const Sequence& toAdd) const;
};


