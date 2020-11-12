#include <iostream>
#include <sys/time.h>

/* Binary Search*/
int bSearch(int arr[],int n, int s){
  int low = 0;
  int high = n;
  while(high>=low){
    int mid = (low + high)/2;
    if(arr[mid] == s) return mid;
    else if(arr[mid]>s) high = mid - 1;
    else if(arr[mid]<s) low = mid + 1;
  }
  return -1;
}

/* Binary Search Recursive*/
int bSearchRec(int arr[],int low, int high, int s){
  if(high < low) return -1;
  
  int mid = (low+high)/2;
  if(arr[mid] == s) return mid;
  else if(arr[mid]>s) high = mid - 1;
  else if(arr[mid]<s) low = mid + 1;

  return bSearchRec(arr, low, high, s);
}

int main() {
  int arr1[8] = {12,18,32,45,47,80,89,99};

  struct timeval start_time, end_time;
  gettimeofday(&start_time, NULL);
  std::cout <<"\nBinary Search: " << bSearch(arr1,8,89) << std::endl;
  gettimeofday(&end_time, NULL);
  std::cout << "time: "<< end_time.tv_usec - start_time.tv_usec<<std::endl;

  gettimeofday(&start_time, NULL);
  std::cout <<"\nBinary Search Recursive: " << bSearchRec(arr1,0,8,89) << std::endl;
  gettimeofday(&end_time, NULL);
  std::cout << "time: "<< end_time.tv_usec - start_time.tv_usec<<std::endl;
}