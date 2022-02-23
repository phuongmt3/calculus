#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

const double PI = 3.14159265359;
const double PI_2 = 2 * PI;
unsigned int MAX_LOOP = 20;
const string PREFIX = "lib_";

double callFunction(string func, double x);
double mySin(double x);
double myCos(double x);
double mySqrt(double x);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Invalid arguments" << endl;
        return 1;
    }

    string func = argv[1];
    double x = stod(argv[2]);
    cout << "Computed by this program:  " << callFunction(func, x) << endl;
    cout << "Computed by C/C++ library: " << callFunction(PREFIX + func, x) << endl;
    
    return 0;
}

double callFunction(string func, double x)
{
    if (func == "cos") {
        return myCos(x);
    } else if (func == "sin") {
        return mySin(x);
    } else if (func == "sqrt") {
        return mySqrt(x);
    } else if (func == PREFIX + "cos") {
        return cos(x);
    } else if (func == PREFIX + "sin") {
        return sin(x);
    } else if (func == PREFIX + "sqrt") {
        return sqrt(x);
    } else {
        cout << "Invalid function" << endl;
        exit(1);
    }
}

/***
    Maclaurin series:
    cos(x) = 1 - x^2/2! + x^4/4! - ...
***/
double myCos(double x) {
    x -= (double) ((int) (x / PI_2)) * PI_2;
    double squareX = x * x;
    double ans = 0;
    double operand = 1;
    for (int i = 1; i < MAX_LOOP; ++i) {
        ans += operand;
        operand *= -squareX / ((2*i-1) * (2*i));
    }
    return ans;
}

/***
    Maclaurin series:
    sin(x) = x - x^3/3! + x^5/5! - ...
***/
double mySin(double x)
{
    x -= (double) ((int) (x / PI_2)) * PI_2;
    double squareX = x * x;
    double ans = 0;
    double operand = x;
    for (int i = 1; i < MAX_LOOP; ++i) {
        ans += operand;
        operand *= -squareX / ((2*i) * (2*i+1));
    }
    return ans;
}

/***
    sqrt(a) (a >= 0) based on Newton method:
    - x_0 = (1+a)/2
    - x_i+1 = (x_i * x_i +  a) / (2 * x_i) 
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    if (x == 0) {
        return 0;
    }
    double preAns = 0, ans = (1+x)/2; //First approximation
    while (ans != preAns) {
        preAns = ans;
        ans = (preAns + x/preAns) / 2;    //Do NOT use: ans = (preAns * preAns + x) / (2 * preAns); 
    }
    return ans;
}
