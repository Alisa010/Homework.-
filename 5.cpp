#include <iostream>
#include <vector>

std::vector<int> CountingSort(std::vector<int> vec){
    int max = vec[0];
    int min = vec[0];
    for(int i = 0; i < vec.size(); ++i){
        if(max < vec[i])
            max = vec[i];
    }
    for(int i = 0; i < vec.size(); ++i){
        if(min > vec[i])
            min = vec[i];
    }

  std::vector<int> count(max - min + 1); 
    for(int i = 0; i < vec.size(); ++i) {
        count[vec[i] - min]++;
    }

    for(int i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }  
  
    std::vector<int> res(vec.size()); 
    for(int i = 0; i < vec.size(); ++i){
        res[count[vec[i] - min] - 1] = vec[i];
        count[vec[i] - min]--;
    }
    
    return res;
}

int main(){
    std::vector<int> vec{3, -7, 0, 4, 3, -5, 3, -89};
    std::vector<int> result = CountingSort(vec);
    for(auto elem : result){
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return 0;
}