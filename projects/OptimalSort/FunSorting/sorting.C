
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

// actually dookie and never to be used here again. 
void selection(vector<string>& arr)
{
  int n = arr.size();

  for (int i = 0; i < n - 1; i++){
    int minIndex = i; //initialize minimum value

    for (int j = i + 1; j < n; j++)
      if (isAlphaSmaller(arr[j],arr[minIndex]))
	minIndex = j;

    string temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
  }
}


void insertion(vector<string>& arr)
{
  int n = arr.size();
  for(int i = 0; i < n - 1; ++i)
    {
      string key = arr[i];
      int j = i -1;

      //essentially, works by moving elemts that are greater than the key to one poisiton ahead of their current position
      while (j >= 0 && isAlphaSmaller(key, arr[j])){
	arr[j + 1] = arr[j]; //moving it one index
	j = j - 1;
      }
      arr[j + 1] = key;
    }
}
//////////////////////////////////////////////




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
  vector<string>  group[255]; //vector is a dynamic array. There are groups equal to the number of words
  for(int i = 0; i < num; i++)
    {
      char firstChar = tolower(arr[i][0]); //gets first char of word
      int d = int(firstChar); //ascii vaue of first letter
      group[d].push_back(arr[i]);
    }


  for (int i = 0; i < 255; i++)
    if (group[i].begin() != group[i].end())
      {
	int n = sizeof(group[i]) / sizeof(group[0]);
	//	insertion(group[i]);
	vector<string> a = mergeSort(group[i], 0, n - 1);
      }

  int index = 0;
  for (int i = 0; i < 255; i++)
    for (std::vector<std::__cxx11::basic_string<char> >::size_type j = 0; j < group[i].size(); j++)
      arr[index++] = group[i][j];

}



void print(std::vector<string> const &input)
{
  for (std::vector<std::__cxx11::basic_string<char> >::size_type i = 0; i < input.size(); i++) {
    std::cout << input.at(i) << ' ';
  }
}

string removeSpecialCharacter(string s)
{
  for (std::vector<std::__cxx11::basic_string<char> >::size_type i = 0; i < s.size(); i++) {

    // Finding the character whose
    // ASCII value fall under this
    // range
    if ((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z'))
      {
	// erase function to erase
	// the character
	s.erase(i, 1);
	i--;
      }
  }
  return s;
}

bool allletters(std::string const &str) {
  return std::all_of(str.begin(), str.end(), [](char const &c) {
    return std::isalpha(c);
  });
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

  //example = (const string[])example;

  int n = sizeof(example) / sizeof(example[0]);

  map<string,string> processor;
  for(int i=0;i<n;i++){
    if(!allletters(example[i])){
      string newword = removeSpecialCharacter(example[i]);
      processor.insert(make_pair(newword,example[i]));
      example[i] = newword;
    }
  }


  for (int i = 0; i < n; i++)
    transform(example[i].begin(), example[i].end(), example[i].begin(), ::tolower);


  sortingTime(example, n);



  for(int i =0;i<n;i++){
    if (processor.count(example[i]) > 0){
      example[i] = processor[example[i]];
    }
  }

  cout << "\n" << "Sorted Words:" << "\n";
  for (int i = 0; i < n; i++)
    cout << example[i] << "\n";
  return 0;
}
 
