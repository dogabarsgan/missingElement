// Doga Barsgan
// An algorithm to find the missing element between two arrays that differs by one element

#include <iostream>
#include <vector>

using namespace std;

int missingElement(vector<int> ar1, vector<int> ar2, int first, int last)
{

  if (ar1.size() == 1)
  {
    return ar1[first];
  }

  int middle = (first + last) / 2;

  if (middle == last)
  {
    return ar1[last];
  }

  while (first < last)
  {

    if (ar1[middle] == ar2[middle]) // recurse on the right side
    {
      first = middle + 1;
      return missingElement(ar1, ar2, first, last);
    }
    else if (ar1[middle] != ar2[middle]) // recurse on the left
    {
      last = middle;
      return missingElement(ar1, ar2, first, last);
    }

  }

  return -1;

}

int main()
{

  vector<int> array1;

  for (int i = 0; i < 10; i++)
  {
    array1.push_back(i * 2);
  }

  vector<int> array2 = array1;

  array2.erase(array2.begin() + 4); // which number to delete

  for (int i = 0; i < array1.size(); i++)
  {
    cout << array1[i] << " ";
  }

  cout << endl;

  for (int i = 0; i < array2.size(); i++)
  {
    cout << array2[i] << " ";
  }

  cout << endl;
  cout << "Missing Element: " << missingElement(array1, array2, 0, array1.size()) << endl;

  return 0;
  
}