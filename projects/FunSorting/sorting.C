
// C++ program to sort an
// array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cctype>

#include<bits/stdc++.h>

using namespace std;



//Needs: ignore special characters. ignore caps

void bubbleSort(char arr[], int num)
{
  char temp;

  for (int i = 0; i < num; i++)
    {
      for (int j = 0; j < num - 1 - i; j++)
	{
	  if (strcmp(arr[j], arr[j+1]) > 0)
	    {
	      strcpy(temp,arr[j]);
	      strcpy(arr[j], arr[j+1]);
	      strcpy(arr[j+1], temp);
	    }
	}
    }
}


void sortingTime(string arr[], int num)
{

  vector<string>  group[255]; //vector is a dynamic array. There are groups equal to the number of words
  for(int i = 0; i < num; i++)
    {
      char firstChar = tolower(arr[i][0]); //gets first char of word
      int d = int(firstChar); //ascii vaue of first letter
      group[d].push_back(arr[i]);
      //      cout << "group[" << d << "] contains: " << group[d] << " ";    
    }
  
  
  for (int i = 0; i < 255; i++)
    if (group[i].begin() != group[i].end())
      //  sort(group[i].begin(), group[i].end()); //can add another sorting method for increased efficiency. Current one thinks capitals are higher
      bubbleSort(group[i], num)


  int index = 0;
  for (int i = 0; i < 26; i++)
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

  // this makes the alpha dict -> could hardcode for processing benefits

  //  map<char, int> divNum; //maps are just like dictionaries
  //char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  //for (int i = 0; i < sizeof(alphabet); i++)
  //  divNum.insert({alphabet[i],i});
