/*
A set in STL is a container that stores unique elements in a particular order. Every operation on a set takes O(1) complexity in the average case and takes O(n) in the worst case.

Syntax:
set<object_type> variable_name;

Example:
set<int> s;
set<string> str;
Functions in set:
insert() – to insert an element in the set.
set<int> s;
s.insert(1);
s.insert(2);
begin() – return an iterator pointing to the first element in the set.
s.begin();
end() – returns an iterator to the theoretical element after the last element.
s.end();
count() – returns true or false based on whether the element is present in the set or not.
set<int> s;
s.insert(1);
s.insert(2);
s.count(2); //returns true
clear() – deletes all the elements in the set.
s.clear();
find() – to search an element in the set.
set<int> s;
s.insert(1);
s.insert(2);
if(s.find(2)!=s.end())
cout<<"true"<<endl;
erase() – to delete a single element or elements between a particular range.
s.erase();
size() – returns the size of the set.
s.size();
empty() – to check if the set is empty or not.
s.empty();
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
  set < int > s;
  for (int i = 1; i <= 10; i++) {
    s.insert(i);
  }

  cout << "Elements present in the set: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;
  int n = 2;
  if (s.find(2) != s.end())
    cout << n << " is present in set" << endl;

  s.erase(s.begin());
  cout << "Elements after deleting the first element: ";
  for (auto it = s.begin(); it != s.end(); it++) {
    cout << * it << " ";
  }
  cout << endl;

  cout << "The size of the set is: " << s.size() << endl;

  if (s.empty() == false)
    cout << "The set is not empty " << endl;
  else
    cout << "The set is empty" << endl;
  s.clear();
  cout << "Size of the set after clearing all the elements: " << s.size();
}