// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>    

int main() {
    int n, a;
    int res[300000] = {0};
    int max = 300000;
    
    std::cin >> n;
    
    for(int i = 1; i<=n ; i++) {
        std::cin >> a;
        
        int current_shortest_path = res[i] > 0 ? res[i]: max;
        
        int path_moving_from_previous = i==1 ? 0 : res[i-1] + 1;
        
        int path_moving_from_next = res[i+1] > 0 ? res[i+1] + 1 : max;
        
        int shortest_path_from_adjecent = std::min(path_moving_from_previous, path_moving_from_next);
        
        res[i] = std::min(current_shortest_path,shortest_path_from_adjecent);

        // in case the shortcut presents a shorter path to intersection a
        
        if (a!= i && (res[a] == 0 || res[i] + 1 < res[a])) {
            res[a] = res[i] + 1;
            // go backwards starting from a and see if there's a new shortest path to arrive to intecections before (till the mid point between a and i)
            for (int j = a-1; j >= (a+i)/2 && j > 1 ; j--) {
                if (res[j] == 0 || res[j+1] + 1 < res[j]) {
                    res[j] = res[j+1] + 1;
                } else {
                    break;
                }
            }
        } 
        // last if and loop can be removed by adding a queue of the shortcut ends, so that instead of going backwards step by step, we compare shortest path found (from previous intersection or a previous shortcut) with the shortest path found from at the next intersection with shortcut leading to (it plus diff between that intersection and current one)

    }
   
    for (int i=1; i<= n; i++) {
        std::cout<<res[i];
        if (i!=n) std::cout << " ";
    }
    return 0;
}
