#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char,int> map {{'#',0},{'+',1},{'-',1},{'*',2},{'/',2}};

//single_expression_calculation
int scalc ( int a, int b, int op ) {
    switch ( op ) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return -1;
    }
}

//one_step_expression_calculation
void ocalc ( stack<int>& nums, stack<char>& syms ) {
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    int op = syms.top(); syms.pop();
    nums.push(scalc(a,b,op));
    return;
}

//calculate_expression
int calc_expr ( string str ) {
    stack<int> nums;
    stack<char> syms;
    syms.push('#');
    for ( auto c : str ) {
        if ( !map.count(c) ) { nums.push(c-'0'); continue; }
        while ( map[c] < map[syms.top()] ) ocalc ( nums, syms );
        syms.push(c);
    }
    while ( nums.size() > 1 ) ocalc ( nums, syms );
    return nums.top();
}

/*
int main() {
    string str = "1+2*6/3-2";
    cout << calc_expr ( str );
    return 0;
}
*/
