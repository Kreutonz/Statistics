#include "Sequence.h"
#include <cassert>      //used for testing using 'assert'
#include <iomanip>

#include <iostream>
using std::cout;
using std::endl;
using std::setprecision;


void testDefaultConstructor(){
    Sequence testSeq;
    assert(testSeq.size() == 0);
//    testSeq.printArray();

    Sequence testSeq2;
    assert(testSeq2.size() == 0);
//    testSeq2.printArray();

    cout << "... All default constructor tests passed" << endl;
}

void testCopyConstructor(){
    Sequence seq1;
    Sequence seq2(seq1);
//    seq1.printArray();
//    seq2.printArray();

    assert(seq2.size() == 0);

    double testArr[] = {1.2, 2.4, 3.6};
    seq1.insert(testArr, 3);

//    seq1.printArray();
    Sequence seq3(seq1);
    assert(seq3.size() == 3);
//    seq3.printArray();


    cout << "... All default constructor tests passed" << endl;
}

void testInsertMethod(){
    //*** Test#1 ***
    Sequence seq1;

//    seq1.printArray();          //creates an empty sequence

    seq1.insert(3.2);
//    seq1.printArray();

    seq1.insert(4.8);
    assert(seq1.size() == 2);
//    seq1.printArray();

    seq1.insert(8.3);   //triggers the method to adjust the maxSize
//    seq1.printArray();

    seq1.insert(1.8);
    assert(seq1.size() == 4);
//    seq1.printArray();

    seq1.insert(5.4);  //triggers the method to adjust the maxSize
//    seq1.printArray();

    //*** Test#2 *** (from notes)
    Sequence seq2;
//    seq2.printArray();

    seq2.insert(7);
    seq2.insert(5);
//    seq2.printArray();

    seq2.insert(9);
//    seq2.printArray();

    cout << "... All insert(single parameter) tests passed" << endl;
}

void testInsertTwoMethod(){
    //*** Test#1 *** (when currentSize + parameterSize > maxSize, maxSize = the combination of sizes)
    Sequence seq1;
    seq1.insert(1.1);
    seq1.insert(2.2);
    seq1.insert(3.3);
//    seq1.printArray();

    double newArray[] = {4.4, 5.5, 6.6, 7.7};
    seq1.insert(newArray, 4);
//    seq1.printArray();

    //*** Test#2 *** (when currentSize + parameterSize < maxSize)
    Sequence seq2;
    seq2.insert(9.9);
    seq2.insert(8.8);
    seq2.insert(7.7);
    seq2.insert(6.6);
    seq2.insert(5.5);
//    seq2.printArray();

    double newArray2[] = {2.2, 1.1};
    seq2.insert(newArray2, 2);
//    seq2.printArray();

    //*** Test#3 *** (from notes)
    Sequence seq3;
    seq3.insert(7);
    seq3.insert(5);
    seq3.insert(9);
//    seq3.printArray();

    double newArray3[] = {2, 4, 6};
    seq3.insert(newArray3, 3);
//    seq3.printArray();

    //*** Test#4 ***
    Sequence seq4;
    double newArray4[] = {1};
    seq4.insert(newArray4, 1);
//    seq4.printArray();

    cout << "... all tests passed for insert of a double array parameter and size integer" << endl;
}

void testFindMethod(){
    Sequence seq1;
    assert(seq1.find(42.0) == 0);

    seq1.insert(1.0);
    seq1.insert(1.0);
    seq1.insert(1.0);

    assert(seq1.find(1.0) == 3);

    Sequence seq2;
    seq2.insert(2.0);
    seq2.insert(4.0);
    seq2.insert(2.0);
    seq2.insert(4.0);
    seq2.insert(2.0);
    seq2.insert(4.0);
    seq2.insert(2.0);

    assert(seq2.find(1.0) == 0);
    assert(seq2.find(2.0) == 4);
    assert(seq2.find(4.0) == 3);

    cout << "... All tests passed for count method" << endl;
}

void testSizeMethod(){
    Sequence seq1;
    assert(seq1.size() == 0);

    seq1.insert(1.0);
    assert(seq1.size() == 1);

    seq1.insert(2.0);
    assert(seq1.size() == 2);

    seq1.insert(3.0);
    seq1.insert(4.0);
    seq1.insert(5.0);
    assert(seq1.size() == 5);

    cout << "... All tests passed for size method" << endl;
}

void testSumMethod(){
    Sequence seq1;
    assert(seq1.sum() == 0.0);

    seq1.insert(3.0);
    seq1.insert(4.0);
    seq1.insert(5.0);
    assert(seq1.sum() == 12.0);

    seq1.insert(-3.0);
    seq1.insert(-4.0);
    seq1.insert(-5.0);
    assert(seq1.sum() == 0.0);

    seq1.insert(-50.0);
    seq1.insert(-75.0);
    assert(seq1.sum() == -125.0);

    cout << "... All tests passed for sum method" << endl;
}

void testMeanMethod(){
    Sequence seq1;
    assert(seq1.mean() == 0);

    seq1.insert(1.0);
    seq1.insert(2.0);
    seq1.insert(3.0);
    assert(seq1.mean() == 2.0);

    seq1.insert(6.0);
    seq1.insert(8.0);
    seq1.insert(10.0);
    assert(seq1.mean() == 5.0);

    Sequence seq2;
    seq2.insert(-1.2);
    seq2.insert(-2.4);
    seq2.insert(-3.6);
    assert(seq2.mean() == -2.4);

    cout << "... All tests passed for mean method" << endl;
}

void testMedianMethod(){
    //*** Test#1 *** (when currentSize is 0)
    Sequence seq1;
    assert(seq1.median() == 0.0);

    //*** Test#2 *** (getting a mean value of an even size)
    seq1.insert(10.0);
    seq1.insert(23.0);
    seq1.insert(4.0);
    seq1.insert(55.0);
    assert(seq1.median() == 16.5);

    //*** Test#3 *** (getting a mean value of an odd size)
    seq1.insert(89.0);
    seq1.insert(36.0);
    seq1.insert(14.0);

    assert(seq1.median() == 23.0);

    //*** Test#4 *** (negative double values)
    Sequence seq2;
    double testArr[] = {-36.0, 50.0, -72.0, 45.0};
    seq2.insert(testArr, 4);
    assert(seq2.median() == 4.5);

    cout << "... All tests passed for median method" << endl;
}

void testStdDevMethod(){
    Sequence seq1;
    assert(seq1.stddev() == 0.0);

    double temp[] = {9, 2, 5, 4, 12, 7, 8, 11, 9, 3, 7, 4, 12, 5, 4, 10, 9, 6, 9, 4};
    seq1.insert(temp, 20);
//    seq1.printArray();

    double seq1StdDev = seq1.stddev();
//    cout << "Standard Deviation for seq1: " << seq1StdDev << endl;      //stddev: 2.98329 (rounded)

    Sequence seq2;
    double temp2[] = {10.2, 30.2, 15.6, 28.8, 50.2, 112.3, 0.2, 16.7};
    seq2.insert(temp2, 8);
//    seq2.printArray();

    double seq2StdDev = seq2.stddev();
//    cout << "Standard Deviation for seq2: " << seq2StdDev << endl;      //stddev: 33.1171 (rounded)

    cout << "... All tests passed for stdDev method" << endl;
}

void testConcatenateMethod(){
    Sequence seq1;
    Sequence seq2;
    seq2.insert(3.0);

    //*** Test#1 *** (one Sequence empty, one Sequence with a single value returns array of size 1 and maxSize = 2)
    Sequence seq3 = seq1.concatenate(seq2);
    assert(seq3.size() == 1);
//    seq3.printArray();

    //*** Test#2 *** (combining multiple Sequences of size 3 and 4, returns currentSize = maxSize)
    double testArr[] = {1.0, 2.0, 3.0};
    double testArr2[] = {6.0, 9.0, 12.0};
    seq1.insert(testArr, 3);
    seq2.insert(testArr2, 3);

    Sequence seq4 = seq1.concatenate(seq2);
    assert(seq4.size() == 7);
//    seq4.printArray();

    //*** Test#3 *** (from notes)
    Sequence seq5;
    Sequence seq6;

    seq5.insert(1);
    seq5.insert(3);
    seq5.insert(5);
    assert(seq5.size() == 3);
//    seq5.printArray();

    seq6.insert(2);
    seq6.insert(4);
    seq6.insert(6);
    seq6.insert(8);
    seq6.insert(10);
    seq6.insert(12);
    assert(seq6.size() == 6);
//    seq6.printArray();

    Sequence seq7 = seq5.concatenate(seq6);
    assert(seq7.size() == 9);
//    seq7.printArray();
//    seq5.printArray();
//    seq6.printArray();

    cout << "... All tests passed for concatenateMethod" << endl;
}

void profBasicTest()
{
    Sequence sq1;
    double numbers[] = { 1.1,2.2,3.3 };
    int n = 3;

    sq1.insert(3.14);
//    cout << "Insert \'3.14\': " << endl;
//    sq1.printArray();

    sq1.insert(numbers, n);
//    cout << "Insert \'{ 1.1,2.2,3.3 }\': " << endl;
//    sq1.printArray();


    int pies = sq1.find(3.14);
//    cout << ".find(3.14) : " << pies << endl;

    int sqSize = sq1.size();
//    cout << ".size() : " << sqSize << endl;

    double sqSum = sq1.sum();
//    cout << ".sum()  : " << sqSum << endl;

    double sqMean = sq1.mean();
//    cout << ".mean() : " << sqMean << endl;

    double sqMedian = sq1.median();
//    cout << ".median() : " << sqMedian << endl;

    double sqStddev = sq1.stddev();
//    cout << ".stddev() : " << sqStddev << endl;

    Sequence sq2(sq1);
//    cout << "sq1: " << endl;
//    sq1.printArray();
//    cout << "sq2 (copy of sq1): " << endl;
//    sq2.printArray();
//    cout << endl << ".concatenate() : " << endl;
    Sequence sq3 = sq2.concatenate(sq1);
//    sq3.printArray();

    cout << "end basic test" << endl;
}


// copy into the .cpp file to be able to print method
//void Sequence::printArray() const {           //used for debugging, delete before submission
//    cout << "{";
//    if(currentSize > 0){
//        cout << arr[0];
//        for(int i = 1; i < currentSize; i++){
//            cout << ", ";
//            cout << arr[i];
//        }
//    }
//    cout << "}" << endl;
//    cout << "Current Size: " << currentSize << endl;
//    cout << "Max Size    : " << maxSize << endl;
//}

int main() {
    testDefaultConstructor();
    testCopyConstructor();
    testInsertMethod();
    testInsertTwoMethod();
    testFindMethod();
    testSizeMethod();
    testSumMethod();
    testMeanMethod();
    testMedianMethod();
    testStdDevMethod();
    testConcatenateMethod();
    profBasicTest();
    Sequence a;
    Sequence b;
    Sequence c;

    a = b.concatenate(c);
    return 0;
}
