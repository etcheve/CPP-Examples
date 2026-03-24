#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// -------------------------------------------------------
// PROBLEM:
//   Given a string S of N digits, return the largest sum
//   of two non-overlapping two-digit fragments of S.
//   Fragments cannot share any character position.
// -------------------------------------------------------

int solution(string &S) {
    int maxSum = -1;
    std::vector<int> nums(S.size(),0);
    for (int i = 0; i < S.size() - 1; ++i){
        nums[i] = (S[i] - '0') * 10 + (S[i + 1] - '0');
    }
    int bestFirst = nums[0];
    for (int i = 2 ; i < nums.size(); ++i){
        bestFirst = std::max(bestFirst, nums[i-2]);
        maxSum = std::max(maxSum, bestFirst+nums[i]);
    }
    
    return maxSum;
}

// -------------------------1------------------------------
// Helper: run one test case and print PASS / FAIL
// -------------------------------------------------------
void test(const string &label, string S, int expected) {
    int result = solution(S);
    bool ok = (result == expected);
    cout << (ok ? "[PASS]" : "[FAIL]")
         << "  " << label
         << "  S=\"" << S << "\""
         << "  expected=" << expected
         << "  got=" << result
         << "\n";
}

int main() {
    // --- provided examples ---
    test("Example 1", "43798",   141);
    test("Example 2", "0001",   10);
    test("Example 3", "0332331", 66);
    test("Example 4", "00331",   34);

    // --- edge cases ---
    test("All zeros",    "0000",   0);    // only possible pair: 00+00 = 0
    test("Min length",   "1234",   12+34);// 12+34=46
    test("All nines",    "9999",   99+99);// 198 — non-overlapping: pos0+pos2
    test("Leading zero", "09990",  99+9); // 99 at pos1, 90 at pos3 → but best is 99+09=108? check
    test("Repeat digit", "1111111",11+11);// 22

    return 0;
}