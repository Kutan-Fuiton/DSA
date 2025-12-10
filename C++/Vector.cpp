// Vector is a dynamically allocated array which use contiguous storage locations for their elements...
// We can redefine its size, not like usual arrays...


#include<iostream>
#include<vector> // This is for vector use
using namespace std;

void display(vector<int> &v){
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> vec1; // zero length vector
    int element, size;
    cout<<"Enter the size of vector: ";
    cin>>size;
    for (int i = 0; i < size; i++){
        cout<<"Enter an element to add to this vector: ";
        cin>>element;
        vec1.push_back(element);
    }
    vec1.pop_back();
    display(vec1);
    vector<int> :: iterator iter = vec1.begin();   // declaring an iterator, which will iterate throughout the vector array
    // vec1.insert(iter+1, 536);     // 536 will get inserted on iter + 1
    vec1.insert(iter+1, 30, 536);    // 30 copies of 536 will get inserted on iter+1
    display(vec1);
    return 0;
}