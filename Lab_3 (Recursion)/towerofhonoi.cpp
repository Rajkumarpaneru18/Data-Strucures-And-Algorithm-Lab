
#include<iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxilary){ 
    if(n==1){//base case
        cout<<"move disk 1 from "<<source<<" to "<<destination<<endl;
        return;
    }
    //recursion
    towerOfHanoi(n-1,source,auxilary,destination);
    cout<<"move disk "<< n<<" from "<<source <<" to "<<destination<<endl;
    towerOfHanoi(n-1,auxilary , destination, source);

}
int main(){ 
  
  towerOfHanoi(4, 'S','D','A');
    
}