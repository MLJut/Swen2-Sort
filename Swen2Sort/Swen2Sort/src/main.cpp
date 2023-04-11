#include <iostream>
#include <cstdlib>
#include <cctype>
#include <conio.h>
#include <string>
#include "../inc/heapsort.h"
#include "../inc/mergesort.h"
#include "../inc/bubbleSort.h" 

int main(int argc, char* argv[])
{
    if (argc == 1) { //no variables given
        std::cout << "Please add an algorithm" << '\n';
        return 1;
    }

    if (argc == 2) { //only sort algoritm given
        std::cout << "please add at least 1 value" << '\n';
        return 1;
    }
    else if (argc > 102) { //more than 100 values given
        std::cout << "too many values, please add at most 100 values" << '\n';
        return 1;
    }


    int values[100];
    int valuesize = 0;
    char alphaValues[100];
    int alphasize = 0;

    for (int i = 2; i < argc; i++) { //add values to values and alphavalues arrays, ignores all chars besides first if not numeric
        //std::cout << "value " << i - 1 << " = " << argv[i] << std::endl; 
        if (isdigit(argv[i][0])) { //test if first char is a digit, assumes the entire string is a digit if true
            values[valuesize] = atoi(argv[i]);
            valuesize++;
        }
        else { //first char is not a digit
            bool isActuallyADigit = false;
            if (argv[i][0] == '-') { //test if first char is a -
                if (sizeof(argv[i]) > 1) {
                    if (isActuallyADigit = isdigit(argv[i][1])) { //test if argv is a negative numeric value
                        values[valuesize] = atoi(argv[i]); //assumes argv[i] is numeric, negative
                        valuesize++;
                    }
                }
            }
            if (!isActuallyADigit) {
                alphaValues[alphasize] = argv[i][0];    
                alphasize++;
            }
        }
    }

    for (int i = 2; i < argc; i++) //show array before sorting
        std::cout << "value " << i - 1 << " = " << argv[i] << std::endl;

    char* algorithm = argv[1];

    if (strcmp(algorithm, "bubblesort") == 0) {
        bubbleSort(values, valuesize);
        bubbleSort(alphaValues, alphasize);
    }
    else if (strcmp(algorithm, "mergesort") == 0) {
        mergeSort(values, 0, valuesize - 1);
        mergeSort(alphaValues, 0, alphasize - 1);
    }
    else if (strcmp(algorithm, "heapsort") == 0) {
        heapSort(values, valuesize);
        heapSort(alphaValues, alphasize);
    }
    else {
        std::cout << "Please enter valid sorting algorithm: bubblesort, mergesort or heapsort." << '\n';
        return 1;
    }

    //show sorted arrays
    for (int i = 0; i < valuesize; i++) //show array after sorting
        std::cout << "value " << i + 1 << " = " << values[i] << std::endl;

    for (int i = 0; i < alphasize; i++) //show array after sorting
        std::cout << "value " << i + 1 << " = " << alphaValues[i] << std::endl;
    return 0;
};