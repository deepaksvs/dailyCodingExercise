#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <stack>
#include <stdio.h>
using namespace std;

bool bin_search_ext(vector<int> arr, int what)
{
    int x = 0;
    int from = 0, to = pow(2, x);
    bool found = false;
    while (true) {
        // test
        try {
            arr.at(to);
            found = binary_search(arr.begin()+from, arr.begin()+to, what);
            if (found) {
                return found;
            }
            x++;
            from = to;
            to = pow(2, x);
        }
        catch (out_of_range e) {
            to = from;
            while(true) {
                try {
                    arr.at(to);
                    to++;
                }
                catch (out_of_range e) {
                    break;
                }
            }
            return binary_search(arr.begin()+from, arr.begin()+to, what);
            
        }
    }
    return found;
}
int main ()
{
    vector<int> ar = {1, 3, 5, 7, 12 ,15, 17, 19, 21, 24,26, 28, 30, 33, 36,39, 51, 53, 55, 61, 67};
    cout << bin_search_ext(ar, 36) << endl;
    
    return 0;
}
