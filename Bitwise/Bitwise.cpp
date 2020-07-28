#include <iostream>
#include<bits/stdc++.h>

int posOfRightMostDiffBit(int m, int n)
{
    int x = m ^ n;  // Only diffrenet bits in variable x
    x = log2(x^(x&(x-1))) + 1;  // Rightmost bit position in variable x
    return x;
}
void powerSet(std::string set){
  int size = set.length();
  int n = pow(2,size);
  for(int i=0;i < n;i++){
    for(int j=0;j<size;j++){
      if(i & (1<<j)) printf("%c",set[j]);
    }
    printf(", ");
  }
}
//Missing Number in sequence
int xorAll(int* arr){
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = arr[0];
  for(int i=1;i<n;i++){
    k = k ^ arr[i];
  }
  return k;
}
int missingNumberInSeq(int arr[],int mx){
  /* Given n size array, having number from range 0 to n+1, occuring exactly once. Find missing number.
Sol: We will xor every number in arr and xor result with xor of every number in (n+1) array
   */
  int k=1;
  for(int i=2;i<=mx;i++){
    k = k ^ i;
  }
  return (k ^ xorAll(arr));  // all common will cancel out, but the missing one
}

/*XOR have below properties
1. x^0 = x
2. x^(y^z) = (x^y)^z
3. x^x = 0
Using these properties we can solve question in O(N) time
 */
int findOddOccur(int * arr){
 int n = sizeof(arr) / sizeof(arr[0]);
 int k = 0;
 for(int i=0;i<n;i++){
   k = k ^ arr[i];
 }
 return k;
}

int digitCount(int num){
  return log10(num)+1;
}

int bitCount(int num){
  int bit_count = 0;
  while(num!=0){
    num = num & (num - 1);
    bit_count++;
  }
  return bit_count;
}

/* n&(n-1)  will unset the righmost set bit. If number is power of
two, then it must unset the only set bit and should evaluate to 0*/
bool ifPowTwo(int n){
  return n!=0 && ((n&(n-1))== 0);
}

int compliment(int n){
  unsigned int x = n;
  unsigned int z = x;
  unsigned int m = 1;
  for(int i=0;i<65;i++){
    if(z != 0 ){
      z = z >> 1;
      m = m << 1;
      m += 1;
    }else{
      m = m >> 1;
      break;
    }
  }
  unsigned int a = (~x) & (m);
  return a;
}

int main() {
  printf("\nPosition of rightmost different bit: %d\n",posOfRightMostDiffBit(24, 128));

  std::string set = "abcd";
  powerSet(set);

  int arr[9] = {1,2,3,4,5,6,7,9,10}; //missing 8
  std::cout<<"\nMissing is: "<<missingNumberInSeq(arr,10);

  int arr1[9] = {2,4,2,4,2,1,1,4,2};
  printf("\nOnly odd occuring number is: %d", findOddOccur(arr1));

  int num = 2020;
  printf("\nDigits count is %d",digitCount(num));

  int checkPowNum = 32;
  std::cout<<"\nIf power of two? "<<(ifPowTwo(checkPowNum)?"True":"False") ;

  int num2 = 321;
  printf("\nNumber of bits: %d",bitCount(num2));

  int num3 = 11;  // 1011
  printf("\nCompliment of %d is %d",num3,compliment(num3));  // 0100

}