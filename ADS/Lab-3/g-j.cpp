#include <iostream>
#include <vector>   
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

bool canDeliver(const vector<long long>& children,  long long flights, long long capacity){
    long long totalFlights = 0;
    for (long long child : children) {
        totalFlights += (child + capacity - 1) / capacity; // чтобы узнать сколько нам раз нужно слетать на один остров с определённой ёмкостью 
                                                                            // (например на 20 остров нужно будет слетать два раза с ёмкостью 17)
        if (totalFlights > flights) 
        {
            return false;
        }
    }
    return totalFlights <= flights;
}

    

long long least_posible_capacity(const vector<long long>&children, long long flights){
    long long l = 1;
    long long max_children = *max_element(children.begin(), children.end()); // максимальное количество детей для одного острова
    long long r = max_children;
    
    while(l < r){
        long long mid = ( r + l ) / 2;

        if (canDeliver(children, flights, mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
};
int main(){
    long long num_of_islands, num_of_flights;
    cin >> num_of_islands >> num_of_flights;

    vector <long long> children(num_of_islands);

    for(long long i = 0; i < num_of_islands; i++){
        cin >> children[i];
    }

    cout << least_posible_capacity(children, num_of_flights);  
}