#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    
    int n;
    string old_name, new_name;
    map<string, string> students;
    
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> old_name >> new_name;
        bool ok = 0;
        for(auto student : students){
            if(student.second == old_name){
                students[student.first] = new_name; 
                ok = 1;
            }
        }
        if(!ok) students[old_name] = new_name;
    }
    cout << students.size() << endl;
    
    for(auto student : students) cout << student.first << ' ' << student.second << endl;
    
    return 0;
}