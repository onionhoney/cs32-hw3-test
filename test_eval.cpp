// test_eval.cpp


#include "Map.h"
#include <iostream>
#include <string>
#define check(EX) (handle(#EX, EX))

using namespace std;
string message;

bool handle(const char *msg, bool result) {
    if (result) {
        message = "Success";
        return true;
    } else {
        message = msg;
        return false;
    }
}


int evaluate(std::string infix, const Map& values,
             std::string& postfix, int& result);


const int TOTAL_TEST_CASE = 40;

bool test(int testIndex) {
    // testIndex : index of the test number
    // corresponding to switch statement

    char vars[] = { 'A', 'a', 'e', 'i', 'o', 'u', 'y', 'z', '#' };
    int  vals[] = { 10, 3,  -9,   6,   2,   4,   1,  0  };
    Map m;
    for (int k = 0; vars[k] != '#'; k++)
        m.insert(vars[k], vals[k]);

    int answer = 999;
    string pf;

    switch (testIndex) {
    case 0:
        return check(evaluate("a+ e", m, pf, answer) == 0  &&
               pf == "ae+"  &&  answer == -6);

    case 1:
        return check(evaluate("     (a+e  )", m, pf, answer) == 0 &&
               pf == "ae+"  &&  answer == -6);

    case 2:
        return check(evaluate("     (a+e  ", m, pf, answer) == 1 &&
               answer == 999);

    case 3:
        return check(evaluate("", m, pf, answer) == 1  &&  answer == 999);

    case 4:
        return check(evaluate("a+", m, pf, answer) == 1  &&  answer == 999);

    case 5:
        return check(evaluate("a)", m, pf, answer) == 1 && answer == 999);

    case 6:
        return check(evaluate("a i", m, pf, answer) == 1  &&  answer == 999);

    case 7:
        return check(evaluate("ai", m, pf, answer) == 1  &&  answer == 999);
        
    // Postfix grammar is not accepted. Following the pseudocode, however,
    // will probably neglect this.
    
    case 8:
        return check(evaluate("ai+", m, pf, answer) == 1  &&  answer == 999);

    case 9:
        return check(evaluate("()", m, pf, answer) == 1  &&  answer == 999);

    case 10:
        return check(evaluate("y(o+u)", m, pf, answer) == 1  &&  answer == 999);

    case 11:
        return check(evaluate("a+E", m, pf, answer) == 1  &&  answer == 999);

    case 12:
        return check(evaluate("(a+(i-o)", m, pf, answer) == 1  &&  answer == 999);
    
    // Unary opertors not allowed
    
    case 13:
        return check(evaluate("-a", m, pf, answer) == 1  &&  answer == 999);

    case 14:
        return check(evaluate("o/(-a+e)", m, pf, answer) == 1 && answer == 999);

    case 15:
        return check(evaluate("   -a+b", m, pf, answer) == 1 && answer == 999);

    case 16:
        return check(evaluate("a*b", m, pf, answer) == 2  &&
               pf == "ab*"  &&  answer == 999);

    case 17:
        return check(evaluate("y +o *(   a-u)  ", m, pf, answer) == 0 &&
               pf == "yoau-*+"  &&  answer == -1);

    case 18:
        return check(evaluate("o/(y-y)", m, pf, answer) == 3  &&
               pf == "oyy-/"  &&  answer == 999);

    case 19:
        return check(evaluate(" a  ", m, pf, answer) == 0  &&
               pf == "a"  &&  answer == 3);

    case 20:
        return check(evaluate("((a))", m, pf, answer) == 0  &&
               pf == "a"  &&  answer == 3);

    case 21:
        return check(evaluate("    (a+y)  ", m, pf, answer) == 0 &&
               pf == "ay+" && answer == 4);

    case 22:
        return check(evaluate(" (a + i   u)  ", m, pf, answer) == 1 &&
               answer == 999);

    case 23:
        return check(evaluate("   )  a + y ", m, pf, answer) == 1 &&
               answer == 999);

    case 24:
        return check(evaluate(" (  ) ", m, pf, answer) == 1 &&
               answer == 999);

    case 25:
        return check(evaluate(" (-a +o  ) ", m, pf, answer) == 1 &&
               answer == 999);

    case 26:
        return check(evaluate(" (a +o  )  u ", m, pf, answer) == 1 &&
               answer == 999);

    case 27:
        return check(evaluate(" (a + u) *  i -  ", m, pf, answer) == 1 &&
               answer == 999);

    case 28:
        return check(evaluate(" (a + u) *  i (  ", m, pf, answer) == 1 &&
               answer == 999);

    case 29:
        return check(evaluate(" (a + u) *  i )  ", m, pf, answer) == 1 &&
               answer == 999);
    
    // Existence in map must come after postfix conversion.
    
    case 30:
        return check(evaluate(" A + a", m, pf, answer) == 1 && 
            answer == 999);
    
    // Some more tests with zero
    
    case 31:
        return check(evaluate(" /z", m, pf, answer) == 1 &&
            answer == 999);
    
    // Check if operators of equal precedence is sorted by order
    
    case 32:
        return check(evaluate("(z / a * z + z)", m, pf, answer) == 0 &&
            pf == "za/z*z+" &&  answer == 0);
    // More on parenthesis mismatch
    
    case 33:
        return check(evaluate(" (a/)u", m, pf, answer) == 1 &&
                answer == 999);
    case 34:
        return check(evaluate(" a(-u)", m, pf, answer) == 1 &&
                answer == 999);

    // Smallberg saith: those which contain'd 
    // () shall not be allow'd in thy programme.
    //
    case 35:
        return check(evaluate(" a + () + i", m, pf, answer) == 1 &&
                answer == 999);
    case 36:
        return check(evaluate(" a + i()", m, pf, answer) == 1 &&
                answer == 999);
    case 37:
        return check(evaluate(" a + ()i", m, pf, answer) == 1 &&
                answer == 999);
    // Operators that are not supposed to be accepted
    case 38:
        return check(evaluate(" a ^ i", m, pf, answer) == 1 && 
                answer == 999);
    // We should test longer cases that are like 32
    case 39:
        return check(evaluate("a / i *  e / o / e", m, pf, answer) == 0
                && pf == "ai/e*o/e/" && answer == 0);
    default:
        return true;
    }
}


int main() {
    cout << "====== RUNNING TEST CASE FOR EVAL ======"
         << endl;

    int passed = 0;
    for (int i = 0; i < TOTAL_TEST_CASE; ++i) {
        if (!test(i))
            cout << "*** FAILURE ***" << endl
                 << "fails test case " << i << endl
                 << message << endl;
        else
            ++passed;
    }
    cout << "====== TEST CASE FOR EVAL ENDS ======"
         << endl;

    if (passed == TOTAL_TEST_CASE)
        cout << "****** ALL TESTS PASSED ******" << endl;
    else
        cout << "PASSED " << passed
             << " OUT OF " << TOTAL_TEST_CASE << endl;

    return 0;
}
