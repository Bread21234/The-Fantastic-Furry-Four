#include "iostream"
#include <map>

using namespace std;


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



int main() {
  string example[] = {"apples", "bone", "banana", "bodacious", "come", "adult", "cart", "cant", "darn"};     
  string alphabet[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

  map<string, int> arrayNum; //maps are just like dictionaries

  for (int i = 0; i < 26; i++)
    {
      arrayNum.insert({alphabet[i],i});
      
				      
    }
  ///////////////////////////////// debug purposes
  cout << "KEY\tELEMENT\n"; 
  for (auto itr = arrayNum.begin(); itr != arrayNum.end(); ++itr) {
    cout << itr->first
	 << "\t" << itr->second << "\n";
  }
  //////////////////////////////////
  
  return 0;
}

