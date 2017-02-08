#include <iostream>
using namespace std;

#define endl '\n';

void TwoOne() {
    const char* msg = "Hello World";
    cout << msg << endl;
}

void TwoTwo() {
    const int n = 5;
    const char* msg = "Hello World";
    
    for (int i = 0; i < n; i++) {
        cout << msg << endl;
    }
    
    cout << endl;
    
    int i = 0;
    while(i++ < n) {
        cout << msg << endl;
    }
    
    cout << endl;
    
    int j = 0;
    do {
        cout << msg << endl;
    } while(++j < n);
}

/*
    compilation error: redefinitin of arg1 with diff type
 */
/*
void ThreeOneOne() {
    int arg1;
    arg1 = -1;
    int x, y, z;
    char myDouble = '5';
    char arg1 = 'A';
    cout << arg1 << endl;
}
 */

/*
    this compiles and prints 'A' because of block scoping,
    arg1 in the top scope can be redeclared in the nested scope.
    Also note we can access arg1 the int within the nested block
    due to scope inheritance (has access to parent scopes)
    if we omit the redeclaration of arg1
 */
void ThreeOneTwo() {
    int arg1;
    arg1 = -1;
    {
        char arg1 = 'A';
        cout << arg1 << endl;
    }
}

/*
    when cout executes, it will look for arg1 within the same scope
    before going up the scope chain, it will print 'A'
 */
void ThreeOneThree() {
    int arg1;
    arg1 = -1;
    {
        char arg1 = 'A';
        cout << arg1 << endl;
    }
}

/*
    the nested block is not in scope of the call to cout
    -1 will be printed out
 */
void ThreeOneFour() {
    int arg1;
    arg1 = -1;
    {
        char arg1 = 'A';
    }
    cout << arg1 << endl;
}

/*
    compilation error: include should be at the top
 */
/*
void ThreeOneFive() {
    using namespace std;
 
    int main() {
        count << "Hello World \n";
        return 0;
    }
 
    #include <iostream>
}
*/

void ThreeTwo() {
    
}


int main(int argc, const char * argv[]) {
    cout << "2.1" << endl;
    TwoOne();
    cout << endl;
    
    cout << "2.2" << endl;
    TwoTwo();
    cout << endl;
    
    cout << "3.1.2" << endl;
    ThreeOneTwo();
    cout << endl;
    
    cout << "3.1.3" << endl;
    ThreeOneThree();
    cout << endl;
    
    cout << "3.1.4" << endl;
    ThreeOneFour();
    cout << endl;
    
    cout << "3.2" << endl;
    ThreeTwo();
    cout << endl;

    return 0;
}
