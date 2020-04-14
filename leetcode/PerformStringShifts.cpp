#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;

typedef long long ll;
typedef vector<long long> vi;
typedef pair<long long, long long> ii;
typedef vector<pair<long long, long long>> vii;
typedef stringstream ss;
ll mil() {return numeric_limits<long long>::min();}
ll mal() {return numeric_limits<long long>::max();}

#define R3(i, a, b) for(long long i=(a); i<(b); ++i)
#define R2(i, b) for(long long i=0; i<(b); ++i)
#define R1(b) for(long long i=0; i<(b); ++i)
#define RR(i, a, b) for(long long i=a; i>b; --i)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

// build: ctrl + f9

// run: shift + f10
// debug: shift + f9
// sanitize: shift + f11

string stringShift(string s, const vector<vector<int>>& shift) {
    vector<int> shifts(2, 0);
    for(auto & v : shift) {
        shifts[v[0]] += v[1];
    }
    
    if(shifts[0] > shifts[1]) {
        int numShifts = (shifts[0] - shifts[1])%s.size();
        stringstream s1;
        s1 << s.substr(numShifts) << s.substr(0, numShifts);
        return s1.str();
    }
    else if(shifts[1] > shifts[0]) {
        int numShifts = (shifts[1] - shifts[0])%s.size();
        stringstream s1;
        s1 << s.substr(s.size() - numShifts) << s.substr(0, s.size() - numShifts);
        return s1.str();
    }

    return s;    
}

TEST(MyFunction, test) {
    ASSERT_EQ("cab", stringShift("abc", vector<vector<int>> {{0,1}, {1,2}}));
    ASSERT_EQ("efgabcd", stringShift("abcdefg", vector<vector<int>> {{1,1},{1,1},{0,2},{1,3}}));    
}