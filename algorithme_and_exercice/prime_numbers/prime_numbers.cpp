

#include <iostream>
using namespace std;

static void calculatePrimes(int finalNumber){
  int arr[finalNumber+1];

  for(int i = 0; i<=finalNumber;i++) {
    arr[i]=1;
  }
  for(int i =2;i<=finalNumber;i++){
    if(arr[i]==1){
      int temp=i*2;
      while(temp<=finalNumber){
        arr[temp]=0;
        temp+=i;
      }
    }
  }

  //print output
  for(int i = 0; i<=finalNumber;i++) {
    if(arr[i]==1)
      cout << i << endl;
  } 
}


int main(){
  calculatePrimes(7);
}
