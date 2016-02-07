// test_linear.cpp


#include <iostream>
#include <string>
#include "testing.h"

using namespace std;


bool anyTrue(const double a[], int n);
int countTrue(const double a[], int n);
int firstTrue(const double a[], int n);
int indexOfMin(const double a[], int n);
bool includes(const double a1[], int n1, const double a2[], int n2);


bool somePredicate(double x) {
    return x < 0;
}


const int TOTAL_ANYTRUE = 4;
bool test_anyTrue(int testIndex) {
    double a[] {1, 1, -1, 1, -1, 1};

    switch (testIndex) {
    case 0:
        return check(anyTrue(a, sizeof(a) / sizeof (double)));

    case 1:
        return check(!anyTrue(a, 2));

    case 2:
        return check(!anyTrue(a, -1));

    case 3:
        return check(!anyTrue(a, 0));

    default:
        return false;
    }
}


const int TOTAL_COUNTTRUE = 5;
bool test_countTrue(int testIndex) {
    double a[] {1, 1, -1, 1, -1, 1};

    switch (testIndex) {
    case 0:
        return check(countTrue(a, sizeof(a) / sizeof (double)) == 2);

    case 1:
        return check(countTrue(a, 2) == 0);

    case 2:
        return check(countTrue(a, 3) == 1);

    case 3:
        return check(countTrue(a, 0) == 0);

    case 4:
        return check(countTrue(a, -1) == 0);

    default:
        return false;
    }
}


const int TOTAL_FIRSTTRUE = 5;
bool test_firstTrue(int testIndex) {
    double a[] {1, 1, -1, 1, -1, 1};

    switch (testIndex) {
    case 0:
        return check(firstTrue(a, sizeof(a) / sizeof (double)) == 2);

    case 1:
        return check(firstTrue(a, 2) == -1);

    case 2:
        return check(firstTrue(a, 3) == 2);

    case 3:
        return check(firstTrue(a, 0) == -1);

    case 4:
        return check(firstTrue(a, -1) == -1);

    default:
        return false;
    }
}


const int TOTAL_INDEXOFMIN = 5;
bool test_indexOfMin(int testIndex) {
    double a[] {1, 3, -2, -1, -2, 0};

    switch (testIndex) {
    case 0:
        return check(indexOfMin(a, sizeof(a) / sizeof (double)) == 2);

    case 1:
        return check(indexOfMin(a, 2) == 0);

    case 2:
        return check(indexOfMin(a, 3) == 2);

    case 3:
        return check(indexOfMin(a, 0) == -1);

    case 4:
        return check(firstTrue(a, -1) == -1);

    default:
        return false;
    }
}


const int TOTAL_INCLUDES = 5;
bool test_includes(int testIndex) {
    double a[] {10, 50, 40, 20, 50, 40, 30};
    double b1[] {50, 20, 30};
    double b2[] {50, 40, 40};
    double b3[] {50, 30, 20};
    double b4[] {10, 20, 20};

    switch (testIndex) {
    case 0:
        return check(includes(a, 7, b1, 3));

    case 1:
        return check(includes(a, 7, b2, 3));

    case 2:
        return check(!includes(a, 7, b3, 3));

    case 3:
        return check(!includes(a, 7, b4, 3));
    case 4:
        return check(includes(a, 7, b1, 0));

    default:
        return false;
    }
}


int main() {
    cout << "=== TESTING anyTrue ===" << endl;

    int anyTrue_passed = 0;
    for (int i = 0; i < TOTAL_ANYTRUE; ++i) {
        if (!test_anyTrue(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
                 << message << endl;
        else
            ++anyTrue_passed;
    }

    cout << "PASSED " << anyTrue_passed
         << " OUT OF " << TOTAL_ANYTRUE << endl;
    cout << "=== END OF anyTrue ===" << endl << endl;


    cout << "=== TESTING countTrue ===" << endl;

    int countTrue_passed = 0;
    for (int i = 0; i < TOTAL_COUNTTRUE; ++i) {
        if (!test_countTrue(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
                 << message << endl;
        else
            ++countTrue_passed;
    }

    cout << "PASSED " << countTrue_passed
         << " OUT OF " << TOTAL_COUNTTRUE << endl;
    cout << "=== END OF countTrue ===" << endl << endl;


    cout << "=== TESTING firstTrue ===" << endl;

    int firstTrue_passed = 0;
    for (int i = 0; i < TOTAL_FIRSTTRUE; ++i) {
        if (!test_firstTrue(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
                 << message << endl;
        else
            ++firstTrue_passed;
    }

    cout << "PASSED " << firstTrue_passed
         << " OUT OF " << TOTAL_FIRSTTRUE << endl;
    cout << "=== END OF firstTrue ===" << endl << endl;


    cout << "=== TESTING indexOfMin ===" << endl;

    int indexOfMin_passed = 0;
    for (int i = 0; i < TOTAL_INDEXOFMIN; ++i) {
        if (!test_indexOfMin(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
                 << message << endl;
        else
            ++indexOfMin_passed;
    }

    cout << "PASSED " << indexOfMin_passed
         << " OUT OF " << TOTAL_INDEXOFMIN << endl;
    cout << "=== END OF indexOfMin ===" << endl << endl;


    cout << "=== TESTING includes ===" << endl;

    int includes_passed = 0;
    for (int i = 0; i < TOTAL_INCLUDES; ++i) {
        if (!test_includes(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
                 << message << endl;
        else
            ++includes_passed;
    }

    cout << "PASSED " << includes_passed
         << " OUT OF " << TOTAL_INCLUDES << endl;
    cout << "=== END OF includes ===" << endl;


    return 0;
}
