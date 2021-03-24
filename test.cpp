#include "./headers/calc_expr.h"
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    string str = "1+2*6/3-2";
    cout << calc_expr ( str );
    return 0;
}