#include <iostream>

int remDup(int a[], int n){
  // remove duplicates from sorted array O(N)
  int res = 1;
  for(int i=1;i<n;i++){
    if(a[i] != a[i-1]){
      a[res] = a[i];
      res ++;
    }
  }
  std::cout << res;
  return res;
}

void leftRot(int a[],int n){
  int l = a[0];
  for(int i=0;i<n-1;i++){
    a[i] = a[(i+1)%n];
  }
  a[n-1] = l;
  for(int i=0;i<n;i++) std::cout<<a[i]<<" ";
}

void reverse(int a[],int l, int h){
  // reverse an array O(N/2)
  int t;
  while(l<h){
    t = a[l];
    a[l] = a[h];
    a[h] = t;
    l++; h--;
  }
}

void leftRotD(int a[],int n, int d){
  // left rotate array by d times(anti-clockwise)
  reverse(a, 0, d-1);//reverse first d
  reverse(a, d, n-1);//reverse secind half
  reverse(a,0,n-1);//reverse complete array
}

void leaders(int a[], int n){
  // An element is called the leader of an array if there is no element greater than it on the right side.
  int l = a[n-1]; // current leader
  for(int i = n-2;i>=0;i--){
    if(a[i] > l){
      std::cout << l << " ";
      l = a[i];
    }
  }
  std::cout << l;
}

int maxDiff(int a[],int n){
  //Maximum Difference problem is to find the maximum of arr[j] - arr[i] where j>i.
  int minv = a[0];
  int res = a[1] - a[0];
  for(int i=1;i<n;i++){
    res = std::max(res,a[i]-minv);
    minv = std::min(minv,a[i]);
  }
  return res;
}

int maxProfit(int price[], int b,int e){
//efficient solution to the Stock Buy and Sell Problem.
//sol: add differences only when stock increases
  int p = 0;
  for(int i=1;i<e;i++){
    if(price[i]>price[i-1]){
      p += price[i] - price[i-1];
    }
  }
  return p;
}

int rainWater(int a[],int n){
  //solve Trapping Rain Water Problem. get volume of trapped water between walls.
  int vol = 0;
  int lmax[n];
  int rmax[n];
  lmax[0] = a[0];
  for(int i=1;i<n;i++){
    lmax[i] = std::max(a[i],lmax[i-1]);
  }
  rmax[n-1] = a[n-1];
  for(int i=n-2;i>=0;i--){
    rmax[i] = std::max(a[i], rmax[i+1]);
  }
  for(int i=1;i<n-1;i++){
    vol+= (std::min(lmax[i], rmax[i]) - a[i]);
  }
  return vol;
}

int maxConsecOnes(int a[], int n){
  //Given binary array, find maximum consecutive 1s length
  int res = 0;
  int cur = 0;
  for(int i=0;i<=n;i++){
    if(a[i] == 0){
      if(cur > res) res = cur;
      cur = 0;
    }else{
      cur++;
    }
  }
  return res;
}
int maxSumSubarr(int a[], int n){
  //Kadane's algorithm.  O(N)
  //find maximum sum subarray of array a[].
  int res = a[0];
  int maxEnding = a[0];
  for(int i=1;i<n;i++){
   maxEnding = std::max(a[i] , maxEnding + a[i]);
   res = std::max(res, maxEnding);
  }
  return res;
}

int maxEvenOdd(int a[],int n){
  int res = 1;
  int c = 1;
  for(int i=1;i<n;i++){
    if((a[i-1]&1 && !(a[i]&1) ) || (a[i]&1 && !(a[i-1]&1) ))
    {
      c++;
      res = std::max(res,c);
    }else c=1;
  }
  return res;
}

int circularSumSubarr(int a[], int n){
  int maxNormal = maxSumSubarr(a, n);
  if(maxNormal < 0) return maxNormal;
  int sum = 0;
  for(int i=0;i<n;i++){
    sum += a[i];
    a[i] = -a[i];
  }
  int maxCircular = sum + maxSumSubarr(a, n);// sum - (-max)
  return std::max(maxNormal, maxCircular);
}
int minAdjDiff(int arr[], int n){    
    // min absolute diffrence of elements in cyclic array
    int minDiff = abs(arr[1] - arr[0]);
    int diff;
    for(int i=2;i<n;i++){
        diff = abs(arr[i] - arr[i-1]);
        minDiff = std::min(diff,minDiff);
    }
    diff = abs(arr[n-1]- arr[0]);
    minDiff = std::min(diff,minDiff);
    return minDiff;
}

int main() {
  int a[] = {2,3,3,4,5,6,6,6,9};
  int b[] = {6,3,9,3,8,5,4,5,1,6};
  int c[] = {5,2,4,6,9};
  int stock[] = {1,5,3,8,12};
  int walls[] = {3,0,1,2,5};
  int bin[] = {0,0,1,1,0,1,1,1,0,1};
  int x[] = {-3,8,-2,4,-5,6};
  int y[] = {5,10,20,6,3,8};
  int z[] = {8,-4,3,-5,4};
  // remDup(a,9);
  // leftRot(b,10);
  // leftRotD(b, 10, 3);for(int i=0;i<10;i++) std::cout<<b[i]<<" ";
  std::cout <<std::endl;
  leaders(b,10);
  //
  // for(int i=0;i<10;i++) std::cout<<b[i]<<" ";
  std::cout <<"\nmax diff: "<<maxDiff(c, 5);
  std::cout <<"\nmax profit: "<<maxProfit(stock, 0, 5);
  std::cout <<"\nwater trapped: "<<rainWater(walls, 5);
  std::cout <<"\nmax consec 1s: "<<maxConsecOnes(bin, 10);
  std::cout <<"\nmax sum of subarray: "<<maxSumSubarr(x  , 6);
  std::cout <<"\nmax len Even-Odd subarray: "<<maxEvenOdd(y, 6);
  std::cout <<"\nmax sum of circular subarray: "<<circularSumSubarr(z, 5);
}