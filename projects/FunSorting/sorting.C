// C++ program to sort an
// array using bucket sort
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;



//Needs: ignore special characters. ignore caps

void sortingTime(string arr[], int num)
{
  // this makes the alpha dict -> could hardcode for processing benefits

  map<char, int> divNum; //maps are just like dictionaries
  char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  
  for (int i = 0; i < sizeof(alphabet); i++)
    divNum.insert({alphabet[i],i});

  vector<string> group[num]; //vector is a dynamic array. There are groups equal to the number of words
  int d = 0;
  
  for(int i = 0; i < num; i++)
    {
      char firstChar = arr[i][0]; //gets first char of word
      d == divNum[firstChar]; //THIS STUPID = MADE ME DEBUG FOR 30+ MINS
      group[d].push_back(arr[i]);
    }

  for (int i = 0; i < num; i++)
    sort(group[i].begin(), group[i].end()); //can add another sorting method for increased efficiency. Current one thinks capitals are higher
 
  int index = 0;
  for (int i = 0; i < num; i++)
    for (int j = 0; j < group[i].size(); j++)
      arr[index++] = group[i][j];
  
}


int main()
{
  string example[] = {"death", "ketamine", "poop", "apples", "bone","Capital", "banana","pee", "bodacious", "come", "adult", "cart", "cant", "darn"};
  int n = sizeof(example) / sizeof(example[0]);
  sortingTime(example, n);


  cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
      cout << example[i] << " ";
  return 0;
}

/*
  map<char, int> arrayNum = {{0,a,}, 
			     {1,b,},
			     {2,c,},
			     {3,d,},
			     {4,e,},
			     {5,f,},
			     {6,g,},
			     {7,h,},
			     {8,i,},
			     {9,j,},
			     {10,k,},
			     {11,l,},
			     {12,m,},
			     {13,n,},
			     {14,o,},
			     {15,p,},
			     {16,q,},
			     {17,r,},
			     {18,s,},
			     {19,t,},
			     {18,u,},
			     {19,v,},
			     {20,w,},
			     {21,x,},
			     {22,y,},
			     {23,z,}} //hardcoded temporarily -> might actually save processing time tho
  		  
*/
