// - <iomanip>
//     + setprecision (fixed)
//     + setw
//     + setfill


// Example program
#include <iostream>
#include <iomanip>
using namespace std;

int main () {
    double f =3.14159;
    cout << setprecision(5) << f << endl; // 3.1416
    cout << setprecision(9) << f << endl; // 3.14159
    cout << fixed;
    cout << setprecision(5) << f << endl; // 3.14159
    cout << setprecision(9) << f << endl; // 3.141590000

    cout << setw(10);
    cout << 77 << endl; // "        77"
    cout << setw(-10);
    cout << 77 << endl; // "77        "

    cout << setfill ('x') << setw (10);
    cout << 77 << endl; // "xxxxxxxx77"

    return 0;
}


// FUNCTION
// - prototype
// - pass-by-value
//     *NOTE copy value
// - pass-by-reference
//     *NOTE another nickname

// BEST PRACTICE
void f1(int n)
void f2(const int& n) // should


// - Address
// - Array address
//     *NOTE: array size for string
//     *NOTE: cout for address of string (char*)


// Example program
#include <iostream>
using namespace std;

int main() {
    int n1;
    int a[2] = {1, 2};
    int n2;
    char s[3] = "ab";
    int n3;

    cout << &n1 << endl;
    cout << a << " " << &a[0] << " " << &a[1] << " " << endl;
    cout << &n2 << endl;
    cout << s << " " << &s[0] << " " << &s[1] << " " << endl;
    cout << &n3 << endl;

    return 0;
}

// gcc
// 0x7ffd8fc2a1b4
// 0x7ffd8fc2a1c0 0x7ffd8fc2a1c0 0x7ffd8fc2a1c4
// 0x7ffd8fc2a1b8
// ab ab b
// 0x7ffd8fc2a1bc

// Example program
#include <iostream>
using namespace std;

int main() {
    int n1;
    int a[2] = {1, 2};
    int n2;
    char s[3] = "ab";
    int n3;

    cout << (long) &n1 << endl;
    cout << (long) a << " " << (long) &a[0] << " " << (long) &a[1] << " " << endl;
    cout << (long) &n2 << endl;
    cout << (long) s << " " << (long) &s[0] << " " << (long) &s[1] << " " << endl;
    cout << (long) &n3 << endl;

    return 0;
}

// gcc
// x756
// x768 x768 x772
// x760
// x784 x784 x785
// x764

// clang
// x668
// x656 x656 x660
// x652
// x648 x648 x649
// x644


// STACK FRAME for function
// inputs
// return address
// local variables


// Example 1
#include <iostream>
using namespace std;

void t1() {
    int x = 0;
    cout << (long) &x << endl;
}

void t2() {
    int x = 0;
    cout << (long) &x << endl;
    t1();
}

int main() {
    t1();
    t2();

    return 0;
}

// gcc
// x524
// x524
// x476


// Example 2
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n > 1) {
        cout << "n = " << n << " at " << (long) &n << endl;
        return (n * factorial(n - 1));
    } else {
        return 1;
    }
}

int main()
{
    cout << factorial(5) << endl;

    return 0;
}

// gcc
// n = 5 at x6044
// n = 4 at x5996
// n = 3 at x5948
// n = 2 at x5900
// 120
=> ???

