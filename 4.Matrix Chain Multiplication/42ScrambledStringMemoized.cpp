#include <bits/stdc++.h>
using namespace std;

unordered_map<string, bool> mp;

// Enter Two String: 
// abcdefghijklmnopq
// efghijklmnopqcadb
// Not Scrambled String
   
bool solve(string S1, string S2)
{
    //Base Condition
    if (S1.length() != S2.length()) return false;
    int n = S1.length();

    // Empty strings are scramble strings
    if (n == 0) return true;

    // Equal strings are scramble strings
    if (S1 == S2) return true;
    
    //Main Logic
    
    // make key of type string for search in map
    string key = (S1 + " " + S2);
    // checking if both string are before calculated or not
    // if calculated means find in map then return it's
    // value
    if (mp.find(key) != mp.end()) {
        return mp[key];
    }
    
    bool flag = false;
    for (int i = 1; i < n; i++) {

        //Not Swapping wala Case
        if (solve(S1.substr(0, i), S2.substr(0, i))
            && solve(S1.substr(i, n - i),
                            S2.substr(i, n - i))) 
        {
            flag=true;
            break;
        }

        //Swapping wala Case
        if (solve(S1.substr(0, i),
                        S2.substr(n - i, i))
            && solve(S1.substr(i, n - i),
                            S2.substr(0, n - i))) 
        {
            flag=true;
            break;
        }
    }
    mp[key] = flag;
    return flag;
}
    
bool isScramble(string s1, string s2) {
    if(s1==s2) return true;
    if(s1.size()!=s2.size()) return false;
    return solve(s1,s2);
}

int main(){
    cout<<"Enter Two String: "<<endl;
    string S1,S2;
    cin>>S1>>S2;

    if (isScramble(S1, S2)) {
        cout << "Yes Scrambled String";
    }
    else {
        cout << "Not Scrambled String";
    }
 
    return 0;
}