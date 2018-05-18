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

void add_vector(vector<int>::iterator one_begin, vector<int>::iterator one_end, 
        vector<int>::iterator two_begin, vector<int>::iterator two_end,
        int &carry, vector<int> &res)
{
    int sum;
    if ((one_begin == one_end) && (two_begin == two_end)) {
        return;
    }
    add_vector(one_begin+1, one_end, two_begin+1, two_end, carry, res);
    sum = *one_begin + *two_begin + carry;
    carry = sum/10;
    sum = sum%10;
    res.push_back(sum);
    return;
}

vector<int> add (vector<int> one, vector<int> two)
{
    vector<int> res;
    stack<int> s;
    int l1 = (int)one.size();
    int l2 = (int)two.size();
    int carry = 0, num;

    vector<int>::iterator n1s = one.begin(), n1e = one.end();
    vector<int>::iterator n2s = two.begin(), n2e = two.end();
    int diff = abs(l1 - l2);
    if (l1 > l2) {
        while (diff) {
            s.push(*n1s);
            diff--;
            n1s++;
        }
    }
    else if (l2 > l1) {
        while (diff) {
            s.push(*n2s);
            diff--;
            n2s++;
        }
    }
    add_vector(n1s, n1e, n2s, n2e, carry, res);
    while (!s.empty()) {
        num = s.top();
        s.pop();
        num += carry;
        carry = num/10;
        num = num%10;
        res.push_back(num);
    }
    if (carry != 0) {
        res.push_back(carry);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main ()
{
    vector<int> number1 = {9,9,9};
    vector<int> number2 = {1};
    vector<int> res = add(number1, number2);

    for (auto &i: res) {
        cout << i;
    }
    return 0;
}
