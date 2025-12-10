#include<iostream>
#include<vector> // This is for vector use
using namespace std;


// Previous display function will not work because of different vector datatypes
template <class T>
void display(vector<T> &v){
    cout<<"Displaying this vector"<<endl;
    for (int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<double> vec1(4);  // 4-element double vector
    vector<char> vec2(4);  // 4-element character vector
    // vec2.push_back('5');
    // display(vec2);
    vector<char> vec3(vec2);  // 4-element character vector from vec2
    // display(vec3);
    vector<int> vec4(4, 13);   // 6-element vector of 13s
    display(vec4);
    cout<<vec4.size();
    int element, size = 5;
    return 0;
}