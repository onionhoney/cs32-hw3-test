// test_tree.cpp


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "testing.h"

using namespace std;


int countIncludes(const double a1[], int n1, const double a2[], int n2);
void exchange(double& x, double& y);
void split(double a[], int n, double splitter,
           int& firstNotGreater, int& firstLess);
void order(double a[], int n);


const int TOTAL_INCLUDES = 7;
bool test_includes(int testIndex) {
    double a[] {10, 50, 40, 20, 50, 40, 30};
    double b1[] {10, 20, 40};
    double b2[] {10, 40, 30};
    double b3[] {20, 10, 40};
    double b4[] {50, 40, 30};

    switch (testIndex) {
        case 0:
            return check(countIncludes(a, 7, b1, 3) == 1);
            
        case 1:
            return check(countIncludes(a, 7, b2, 3) == 2);
            
        case 2:
            return check(countIncludes(a, 7, b3, 3) == 0);
            
        case 3:
            return check(countIncludes(a, 7, b4, 3) == 3);

        case 4:
            return check(countIncludes(a, 7, b1, 0) == 1);

        case 5:
            return check(countIncludes(a, 0, b1, 0) == 1);

        case 6:
            return check(countIncludes(a, 0, b1, 3) == 0);

        default:
            return false;
    }
}


bool test_order() {
    double a[] {10, 50, 40, 20, 50, 40, 30};
    double b[] {10, 20, 30};
    //bondary test
    cout << "=== RUNNING BOUNDARY TEST FOR order ===" << endl;
    order(b, 0);
    if(b[0] == 10 && b[1] == 20 && b[2] == 30)
        cout << "PASSED BONDARY TEST" << endl;
    else{
        cout << "*** FAILURE ***" << endl
        << "fails boundary test" << endl;
    }
    cout << "=== END OF BOUNDARY TEST FOR order ===" << endl;

    // trivial test
    cout << "=== RUNNING TRIVIAL TEST FOR order ===" << endl;
    
    bool trivial_passed = true;
    order(a, sizeof(a) / sizeof(double));
    double last = a[0];
    for (int i = 0; i < 7; ++i) {
        if (a[i] > last) {
            cout << "*** FAILURE ***" << endl
                 << "fails trivial test" << endl;
            trivial_passed = false;
            break;
        }
        last = a[i];
    }
    if (trivial_passed)
        cout << "PASSED TRIVIAL TEST" << endl;
    cout << "=== END OF TRIVIAL TEST FOR order ===" << endl;

    //randomized test
    cout << "=== RUNNING RANDOMIZED TEST FOR order ===" << endl;
    const int SIZE = 100000;
    double d_arr[SIZE];
    srand(time(nullptr));
    for (int i = 0; i < SIZE; ++i) {
        d_arr[i] = rand();
    }

    bool randomized_passed = true;
    order(d_arr, SIZE);
    last = d_arr[0];
    for (int i = 0; i < SIZE; ++i) {
        if (d_arr[i] > last) {
            cout << "*** FAILURE ***" << endl
                 << "fails randomized test" << endl;
            randomized_passed = false;
            break;
        }
        last = d_arr[i];
    }
    if (randomized_passed)
        cout << "PASSED RANDOMIZED TEST" << endl;
    cout << "=== END OF RANDOMIZED TEST FOR order ===" << endl;

    return true;
}


int main() {
    cout << "=== TESTING countIncludes ===" << endl;

    int countIncludes_passed = 0;
    for (int i = 0; i < TOTAL_INCLUDES; ++i) {
        if (!test_includes(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
            << message << endl;
        else
            ++countIncludes_passed;
    }

    cout << "PASSED " << countIncludes_passed
         << " OUT OF " << TOTAL_INCLUDES << endl;
    cout << "=== END OF countIncludes ===" << endl << endl;

    // test order function
    test_order();

    return 0;
}
