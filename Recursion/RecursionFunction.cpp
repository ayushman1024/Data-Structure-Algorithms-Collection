#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int sumOfDigits(int n){
  if(n<=0) return 0;
  return n%10 + sumOfDigits(n/10);
}
void printNnumbers(int n){
  //Print 1 to N
  if(n <1) return;
  printNnumbers(n-1);
  std::cout << n<<" ";
}

int countDigits(int n){
  // Count digits in number
  if(n<10) return 1;
  return 1+countDigits(n/10);
}

int digitalRoot(int n){ //Eg. DigitalRoot(191)=1+9+1=>11=>1+1=>2
  if(n <10) return n;
  return digitalRoot(n%10 + digitalRoot(n/10));
}

long long fibonacci(int n){ //nth fibonacci number
  if(n==1 | n==0) return n;
  return fibonacci(n-1) + fibonacci(n-2);
}

int rodCutting(int n, int a, int b, int c){
  //
    if(n == 0)
      return 0;
    if(n < 0)
      return -1;
    int res = std::max(std::max(rodCutting(n-a, a, b, c), rodCutting(n-b, a, b, c)), 
              rodCutting(n-c, a, b, c));
    
    if(res== -1)
      return -1;
    return 1+res;
}

void subset(string s, string curr, int index){
  // generates all subsets and print from string
  if(s.length() == index){
    cout << curr <<", ";
    return;
  }
  subset(s,curr,index+1);
  subset(s,curr+s[index],index+1);
}
int subsetSum(int s[], int n, int sum){
  // return number of subets of set having sum = sum | Theta(2^n)
  if(n ==0)return (sum == 0)?1:0;
  return subsetSum(s,n-1,sum) +
  subsetSum(s,n-1,sum-s[n-1]);
}

int main() {
  printNnumbers(6);
}