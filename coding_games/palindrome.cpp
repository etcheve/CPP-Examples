#include<vector>
#include <iostream>
#include<string>
#include <unordered_map>


class UnionFind{
    private: 
     std::vector<int> parent_;
    int size_;
    public:
     UnionFind(int size ){
        parent_.resize(size);
        for (int i = 0; i < size; ++i){
            parent_[i] = i;
        }
        size_ = size;
    }

    // find looks for the parent of the element and performs path comrpesion 
    int find(int x ){
        if (parent_[x] == x){
            return x;
        }
        parent_[x] = find(parent_[x]);
        return parent_[x];
    }

    void merge(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX != rootY){
            parent_[rootX] = rootY;
        }
    }
};

int main( ){
    std::string s = "abccba";
    int k = 2;
    int n = s.size();
    UnionFind uf(n);
    // create palindrome restrictions 
    for ( int i =0; i<n/2; ++i){
        uf.merge(i,n-1-i);
    }

    // create k distance restrictions
    for (int i = 0 ; i < k; ++i){
        for (int j = i+k; j < n; j+=k){
            uf.merge(i,j);
        }
    }

    // group characters by their root parent and count frequencies
    std::unordered_map<int, std::vector<char>> groups;
    for ( int i = 0; i < n ; ++i){
        int root = uf.find(i);
        groups[root].push_back(s[i]);
    }

    int totalOperations = 0;
    for ( auto &group : groups){
        std::vector<char> &chars = group.second;
        int rootSize = chars.size();
        
        // count frequency of each character in the group
        std::unordered_map<char, int> freq;
        for ( char c : chars){
            freq[c]++;
        }

        // find the maximum frequency of any character in the group
        int maxFreq = 0;
        for ( auto &entry : freq){
            maxFreq = std::max(maxFreq, entry.second);
        }
        // add to number of operations needed to make all restrctions match 
        totalOperations += rootSize - maxFreq;
    }
    std::cout << "Minimum operations needed: " << totalOperations << std::endl;
    return totalOperations;
}


