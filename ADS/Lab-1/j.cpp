#include <bits/stdc++.h>

using namespace std;

int main(){

    char ch;
    int n;
    deque<int> nums;

    do{
        if(ch == '+')
            nums.push_front(n);
        else if(ch == '-')
            nums.push_back(n);
        
        cin >> ch; // нашим символом может оказаться *, поэтому мы сначала должны убедиться в этом, а если нет, то тогда дописываем число и логика начинается сверху
        if(ch == '*'){
            if(nums.empty()){
                cout << "error" << "\n";
                continue;
            }
            cout << nums.front() + nums.back() << "\n";
            nums.pop_front();
            if(nums.size() >= 1)
                nums.pop_back();
            continue;
        }

        cin >> n;
    }
    while(ch != '!');

    

    return 0;
}