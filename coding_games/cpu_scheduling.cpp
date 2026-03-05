
#include    <iostream>


int main(){
    int n = 5; // number of processes
    int k =7; // time slots 

    int totalCombibinations = n;
    for (int i = 0 ; i < n-1; ++i){
        totalCombibinations *= (n-1); 
    }
    std::cout << "Total combinations: " << totalCombibinations << std::endl;
}