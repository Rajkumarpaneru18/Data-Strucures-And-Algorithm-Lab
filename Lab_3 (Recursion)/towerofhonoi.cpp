
#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxilary)
{
  if (n == 1)
  { // base case
    cout << "move disk 1 from " << source << " to " << destination << endl;
    return;
  }
  // recursion
  towerOfHanoi(n - 1, source, auxilary, destination);
  cout << "move disk " << n << " from " << source << " to " << destination << endl;
  towerOfHanoi(n - 1, auxilary, destination, source);
}
int main()
{
  int numberOfDisc;
  cout << "Enter the number of disc: " << endl;
  cin >> numberOfDisc;
  char source, destination, auxilary;
  cout << "Enter the source of a disc: " << endl;
  cin >> source;
  cout << "Enter the destination for disc where you want to store it: " << endl;
  cin >> destination;
  cout << "Enter an auxilary pole: " << endl;
  cin >> auxilary;

  towerOfHanoi(numberOfDisc, source, destination, auxilary);
  return 0;
}