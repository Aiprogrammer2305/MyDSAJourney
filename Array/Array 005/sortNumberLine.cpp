// sort the array containing negatives and positives 
#include <iostream>
#include <vector>
using namespace std;


void sort(vector<int>& v){
    int n =v.size();
    int i=0;
    int j=n-1;

    while(i<j){
        if(v[i]>0  and v[j]<0){
            swap(v[i], v[j]);
            i++;
            j--;
        } 
        if(v[i] < 0) i++;
        if(v[j] > 0) j--; 
    }
    
}




int main(){
    int n;
    cout << "Enter the length of array: ";
    cin >> n;
    vector<int>v(n);
    cout << "Enter the elements in array: ";
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(v);
    cout << "The sorted array is: ";
    for(int i=0; i < v.size(); i++){
        cout << v[i] << " " ;
    }

    cout << endl; 
    return 0;
}