#include <iostream>
#include <string>
using namespace std;
int main()
{   
    string x, y;
    cin >> x >> y;
    if (x.length() >= y.length()) cout << "go" << endl;
    else cout << "no" << endl;
    return 0;
}