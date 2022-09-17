
// C++ program to sort an
// array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <functional>

#include<bits/stdc++.h>

using namespace std;



//Needs: ignore special characters. ignore caps

bool isAlphaSmaller(string str1, string str2)
{
  transform(str1.begin(), str1.end(), str1.begin(),::tolower);
  transform(str2.begin(), str2.end(), str2.begin(),::tolower); //converting both strings to lowercase values

  if (str1 < str2) {
    return true;
  }
  return false;
}


vector<string> merge(vector<string> arr1,
		     vector<string> arr2)
{
  int size1 = arr1.size();
  int size2 = arr2.size();
  vector<string> arr3;

  int idx = 0;

  int i = 0;
  int j = 0;
  while (i < size1 && j < size2) {
    if (isAlphaSmaller(arr1[i], arr2[j])) {
      arr3.push_back(arr1[i]);
      i++;
      idx++;
    }
    else {
      arr3.push_back(arr2[j]);
      j++;
      idx++;
    }
  }
  while (i < size1) {
    arr3.push_back(arr1[i]);
    i++;
    idx++;
  }
  while (j < size2) {
    arr3.push_back(arr2[j]);
    j++;
    idx++;
  }
  return arr3;
}

// Function to mergeSort 2 arrays
vector<string> mergeSort(vector<string> arr, int lo, int hi)
{
  if (lo == hi) {
    vector<string> A = { arr[lo] };
    return A;
  }
  int mid = lo + (hi - lo) / 2;
  vector<string> arr1 = mergeSort(arr, lo, mid);
  vector<string> arr2 = mergeSort(arr, mid + 1, hi);

  vector<string> arr3 = merge(arr1, arr2);
  return arr3;
}





void sortingTime(string arr[], int num)
{
  vector<string>  group; //vector is a dynamic array. There are groups equal to the number of words
  for(int i = 0; i < num; i++)
    group.push_back(arr[i]);

  int n = group.size();


  vector<string> a = mergeSort(group, 0, num - 1);

  for (int i = 0; i < n; i++) {
    cout << a[i] << "\n";
  }
}



void print(std::vector<string> const &input)
{
  for (std::vector<std::__cxx11::basic_string<char> >::size_type i = 0; i < input.size(); i++) {
    std::cout << input.at(i) << ' ';
  }
}
int main()
{

  std::vector<string> input;

  string x;
  while (std::cin >> x){
    input.push_back(x);
  }


  string example[input.size()];
  std::copy(input.begin(), input.end(), example);


  int n = sizeof(example) / sizeof(example[0]);
  sortingTime(example, n);
  return 0;
}
 
