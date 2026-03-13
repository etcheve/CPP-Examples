#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Problem:
You are given an array representing nails with different lengths.

You have a hammer and you can hammer at most K nails.

When you hammer a nail, you reduce its length by 1 unit.

Goal:
Maximize the number of nails that end up having the same final length.

Return the maximum number of nails with equal length after at most K hammer operations.
*/

// todo fix r+1 overflow
// 
int maxEqualNails(vector<int>& nails, int K)
{
    std::sort(nails.begin(), nails.end());
    int index = 1;
    int indexL = 0;
    int indexR = 0;
    int remainingK = K;
    int maxEqual = 0;
    while( indexR < nails.size() && index < nails.size()){
       int diff = nails[index]-nails[indexL];
       if(diff == 0){
        indexR = index;
        maxEqual = max(maxEqual, index-indexL+1);
        ++index;
        continue;
       }
       if (remainingK >= diff){
            remainingK -= diff;
            maxEqual = max(maxEqual, index-indexL+1);
        }else{
            if (indexR+1 >= nails.size()){
                break;
            }
            remainingK += (nails[indexR+1] - nails[indexL] )* (indexR-indexL+1);
            indexL = indexR+1;
            indexR = indexL;
        }

      ++index;
    }
    return maxEqual;

}


/* ------------------- Test helper ------------------- */

void runTest(vector<int> nails, int K, int expected)
{
    try
    {
        int result = maxEqualNails(nails, K);

        cout << "Result: " << result
             << " | Expected: " << expected
             << (result == expected ? "  OK" : "  FAIL")
             << endl;
    }
    catch(const exception& e)
    {
        cout << "Function not implemented yet." << endl;
    }
}


/* ------------------- Main ------------------- */

int main()
{
    cout << "Running tests...\n" << endl;

    // Test 1
    runTest({2,3,3,4}, 1, 3);
    // Explanation:
    // hammer 4 -> 3
    // result: [2,3,3,3]

    // Test 2
    runTest({5,5,5}, 2, 3);
    // Already equal

    // Test 3
    runTest({1,2,3,4}, 3, 3);
    // hammer 4->3 and 2->1 etc depending strategy

    // Test 4
    runTest({8,5,6,7}, 3, 3);

    // Test 5
    runTest({10,10,9,8,7}, 2, 3);

    return 0;
}