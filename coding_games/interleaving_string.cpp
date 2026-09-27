// https://leetcode.com/problems/interleaving-string/description/

/* Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/

class Solution {
public:
    int func(int i,int j, int k,int n, int m, int l,string &s1, string &s2, string &s3,vector<vector<vector<int>>>&dp)
    {
        
        if(i>=n)
         return s2.substr(j)==s3.substr(k);
        if(j>=m)
         return s1.substr(i)==s3.substr(k);
        if(k>=l)
         return 0; 
        if(dp[i][j][k]!=-1) return dp[i][j][k]; 
        if(s1[i]==s3[k]&&s2[j]==s3[k])
          return dp[i][j][k]= func(i+1,j,k+1,n,m,l,s1,s2,s3,dp)|| func(i,j+1,k+1,n,m,l,s1,s2,s3,dp);
        else if(s1[i]==s3[k])
         return dp[i][j][k]= func(i+1,j,k+1,n,m,l,s1,s2,s3,dp);
        else if(s2[j]==s3[k])
         return dp[i][j][k]= func(i,j+1,k+1,n,m,l,s1,s2,s3,dp);
        else
         return dp[i][j][k]= 0;  
    }
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n=s1.size();
        int m=s2.size();
        int l=s3.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(l,-1)));
        return func(0,0,0,n,m,l,s1,s2,s3,dp);
    }
};