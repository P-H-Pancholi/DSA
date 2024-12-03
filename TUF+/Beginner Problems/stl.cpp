#include <bits/stdc++.h>
using namespace std;

void explainPair() {
    // stores multiple values in a single var.
    pair<int, int> pr1 = {2, 8}; // make_pair
    cout << pr1.first << " " << pr1.second << endl;

    pair<int, char> pr2 = make_pair(2, 'b');
    cout << pr2.first << " " << pr2.second << endl;

    pair<pair<int, char>, int> pr3 = {{4, 'h'}, 8};
    cout << pr3.first.second << endl;

}

void explainVector() {
    //vector is dynamic in nature unlike array
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(0);

    cout << vec.size() << endl;

    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    // iterator
    vector<int>::iterator beginItr = vec.begin(); // returns pointer to the begining of vec vector.
    vector<int>::iterator endItr = vec.end(); // points to the pointer after the end element.
    for(auto i = beginItr; i < endItr; i++ ){ // auto can be used
        cout << *i << " ";
    }
    cout << endl;

    // for each
    for(auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    // reverse iterator
    auto reverseBegin = vec.rbegin();
    auto reverseEnd = vec.rend();
    for(auto i = reverseBegin; i < reverseEnd; i++){ // reverse concept so we are using ++
        cout << *i << " ";
    }
    cout << endl;

    vector<int> vec1(5);
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(0);
    // 0 0 0 0 0 1 2 0 
    for(auto i : vec1){
        cout << i << " ";
    }
    cout << endl;

    vector<int> dupvec(vec1.begin() + 1, vec1.end()-1);
    // 0 0 0 0 1 2
    for(auto i : dupvec){
        cout << i << " ";
    }
    cout << endl;

    // erase : takes two iterator first & last & deletes from first to last elements.
    // clear : clears vector
    // swap : takes two vector & swaps.
}

void explainList() {
    list<int> ls = {6, 7};
    // list allows you to insert at front.
    ls.push_front(1);
    // 1 6 7
    for( auto i : ls){
        cout << i << " ";
    }
    cout << endl;
}

void explainStack() {
    // LIFO
    stack<int> st;
    st.push(1);
    st.push(7);

    cout << st.top() << " "; // 7
    st.pop(); // deletes 7
    cout << st.top() << " "; // 1
    st.pop(); // deletes 1
}

int main() {
    explainPair();
    explainVector();
    explainList();
    explainStack();
    return 0;
}