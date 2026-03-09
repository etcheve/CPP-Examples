// https://leetcode.com/problems/merge-sorted-array/
#include <vector>
using namespace std;

class Solution {
public:

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int in=n-1;
        int im=m-1;
        for (int i = 0; i < (m+n); ++i){
            if(im < 0 || (in >= 0 && nums2[in] > nums1[im])){
                nums1[(m+n) - i -1 ] = nums2[in];
                --in;
            }else{
            nums1[(m+n) - i -1 ] = nums1[im];
            --im;
            }
        }
    }
};