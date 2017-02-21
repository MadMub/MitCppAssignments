#include <iostream>
using namespace std;

void TwoOne()
{
    const char* msg = "Hello World";
    cout << msg << endl;
}

void TwoTwo()
{
    const int n = 5;
    const char* msg = "Hello World";
    
    for (int i = 0; i < n; i++)
    {
        cout << msg << endl;
    }
    
    cout << endl;
    
    int i = 0;
    while(i++ < n)
    {
        cout << msg << endl;
    }
    
    cout << endl;
    
    int j = 0;
    do
    {
        cout << msg << endl;
    } while(++j < n);
}

/*
    compilation error: redefinitin of arg1 with diff type
 */
/*
void ThreeOneOne()
{
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
void ThreeOneTwo()
{
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
void ThreeOneThree()
{
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
void ThreeOneFour()
{
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
void ThreeOneFive()
{
    using namespace std;
 
    int main() {
        count << "Hello World \n";
        return 0;
    }
 
    #include <iostream>
}
*/

void ThreeTwo()
{
    int n;
    cin >> n;
    
    int sum = 0;
    int max = -99999; // naive super small number
    int min = 99999; // naive super big number
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sum = sum + num;
        if(num < min)
        {
            min = num;
        }
        if (num > max)
        {
            max = num;
        }
    }
    
    int range = max - min;
    double mean = double(sum) / double(n);
    
    cout << "Mean: " << mean << endl;
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
    cout << "Range: " << range << endl;
}

void ThreeThree()
{
    int n;
    cin >> n;
    int primes[n];
    int primesFound = 0;
    int numberToTest = 2;
    while(primesFound < n) {
        bool isPrime = true;
        for(int i = 0; i < primesFound; i++)
        {
            if(numberToTest % primes[i] == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            primes[primesFound] = numberToTest;
            primesFound++;
            cout << numberToTest << " ";
        }
        numberToTest++;
    }
    cout << endl;
}

void ThreeFourOne()
{
    while(true)
    {
        int n;
        cin >> n;
        int result = n >= 0 && n % 5 == 0 ? n / 5 : -1;
        cout << result;
    }
}

void ThreeFourTwo()
{
    while(true)
    {
        int n;
        cin >> n;
        if(n < 0 || n % 5 != 0)
        {
            continue;
        }
        cout << n / 5;
    }
}

void ThreeFourThree()
{
    while (true)
    {
        int n;
        cin >> n;
        if(n < 0)
        {
            cout << "Goodbye!" << endl;
            break;
        }
        if(n % 5 != 0)
        {
            continue;
        }
        cout << n / 5;
    }
}

/*
    I really have no clue what this function does other an accumlate
    2 ^ n bobs when n doles are odd...
    ... just looked at answers apparently something called
    russian peasant multiplication... never heard of it.
 */
/*
void ThreeFiveOne()
{
    int accumulator;
    while(true)
    {
        if(dole == 0) break; // end the loop when dole is 0
        accumulator += ((dole % 2 == 1) ? bob : 0); //accumlate bob if dole
                                                    // is odd
        dole /= 2; // factor 2 out of dole
        bob *= 2; // multiply bob by 2
    }
    cout << accumulator << endl; // printout accumulation
}
 */


/*
    This program always returns 1. OS would thing program errored
    (nonzero return)
 */
/*
void ThreeFiveTwo()
{
 #define o 1 // that is an oh not zero
 
 int main()
 {
    return o;
 }
}
 */

/* Getting lazy, tired of rewriting source */

/* 3.5.3 */
/*
    I really don't know, calculates squares of inverse values up to N.
    Then within each iteration flip the sign of the accumulation up to i
    times.
    
    The answer flew over my head too, something about a series
    (calc 2 was a real struggle for me in uni)
 */

/*
    Yes this compiles despite awkward forloop. It calculates factorials
 */
void FourOne()
{
    short number;
    cout << "Enter a number...";
    cin >> number;
    
    cout << "the factorial of " << number << " is ";
    int accumulator = 1;
    for(; number > 0; accumulator *= number--);
    cout << accumulator << endl;
}

/*
    Factorials cannot be calculated for negative numbers.
 */
void FourTwo()
{
    short number;
    cout << "Enter a number...";
    cin >> number;
    
    if(number < 0) {
        cout << "cannot calcuate factorials of negative numbers" << endl;
        return;
    }
    
    cout << "the factorial of " << number << " is ";
    int accumulator = 1;
    for(; number > 0; accumulator *= number--);
    cout << accumulator << endl;
}

/* 4.3 */
/*
    Factorials exponentiate pretty quickly, we will overflow int eventually
 */

void FourFour()
{
    short number;
    cout << "Enter a number...";
    cin >> number;
    
    if(number < 0) {
        cout << "cannot calcuate factorials of negative numbers" << endl;
        return;
    }
    
    cout << "the factorial of " << number << " is ";
    long long accumulator = 1;
    for(; number > 0; accumulator *= number--);
    cout << accumulator << endl;
}

/* 4.5 */
/* it would be a big hardcoded switch statement... */
/* a more interesting implementation (and intuitive)
    would be using recursion
 */

/* 4.6 */
/* our code accounts for most results except ones that would overflow past long long */

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
    //ThreeTwo();
    cout << endl;
    
    cout << "3.3" << endl;
    //ThreeThree();
    cout << endl;
    
    cout << "3.4.1" << endl;
    //ThreeFourOne();
    cout << endl;
    
    cout << "3.4.2" << endl;
    //ThreeFourTwo();
    cout << endl;
    
    cout << "3.4.3" << endl;
    //ThreeFourThree();
    cout << endl;
    
    cout << "4.1" << endl;
    //FourOne();
    cout << endl;
    
    cout << "4.2" << endl;
    //FourTwo();
    cout << endl;
    
    cout << "4.4" << endl;
    FourFour();
    cout << endl;

    return 0;
}
