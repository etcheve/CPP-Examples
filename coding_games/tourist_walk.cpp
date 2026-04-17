#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------------------------------------
// PROBLEM:
//   Given an array of terrain heights, two tourists start
//   at the same block and walk in opposite directions.
//   They can only move to a block of equal or greater height.
//   Return the longest possible distance (right - left + 1)
//   over all possible starting positions.
// -------------------------------------------------------

int solution(vector<int> &blocks) {
    // TODO: implement this
    // the one going left 
    if(blocks.size() < 2){
        return 1;
    }
    std::vector<int> left(blocks.size(),0);
    left[0]=0;
    int lastBestIndex = 0;
    for (int i = 1 ; i < blocks.size(); ++i){
        if (blocks[i-1] < blocks[i]){
            lastBestIndex=i;
        }
        left[i]=lastBestIndex;
    }
    std::vector<int> right(blocks.size(),0);
    right[blocks.size()-1]=blocks.size()-1;
    lastBestIndex = blocks.size()-1;

    for (int i = blocks.size()-2 ; i >= 0; --i){
        if (blocks[i+1]<blocks[i]){
            lastBestIndex = i;
        }
        right[i]= lastBestIndex;
    }
    int bestDiff=0;

    for (int i = 0 ; i< blocks.size(); ++i ){
       bestDiff= std::max(bestDiff, right[i]-left[i]+1);
    }

    return bestDiff;
}

// -------------------------------------------------------
// Helper: run one test case and print PASS / FAIL
// -------------------------------------------------------
void test(const string &label, vector<int> blocks, int expected) {
    int result = solution(blocks);
    bool ok = (result == expected);
    cout << (ok ? "[PASS]" : "[FAIL]")
         << "  " << label
         << "  expected=" << expected
         << "  got=" << result
         << "\n";
}

int main() {
    // --- provided examples ---
    test("Example 1", {1, 5, 7, 4},    3);
    test("Example 2", {2, 6, 6, 3, 7}, 4);
    test("Example 3", {2, 2},          2);

    // --- edge cases ---
    test("All same",       {5, 5, 5, 5},       4); // can walk entire array
    test("Strictly up",   {1, 2, 3, 4},        4); // start at 0, go all right
    test("Strictly down", {4, 3, 2, 1},        4); // start at 3, go all left
    test("Valley",        {5, 1, 5},           2); // can't cross the valley
    test("Two elements",  {3, 3},              2); // minimum case

    return 0;
}