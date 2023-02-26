#include <iostream>
#include <vector>

int swapCount = 0;
void merge_sort(std::vector<int>& vec, int first, int middle,int last) {
 int left_index = first;
 int right_index = middle + 1;
 std::vector<int> result;

 while(left_index <= middle && right_index <= last) {
     if(vec[left_index] < vec[right_index]) {
        result.push_back(vec[left_index]);
        ++left_index;   
      }
     else {
        result.push_back(vec[right_index]);
        ++right_index;
     }
   ++swapCount;
 }
 while(left_index <= middle) {
  result.push_back(vec[left_index]);  
  ++left_index; 
 }
 while(right_index <= last) {
  result.push_back(vec[right_index]);  
  ++right_index;
 }

 for(int i = first; i <= last; ++i) {
  vec[i] = result[i - first];
   
 }
  
}

void merge(int first_index, int last_index, std::vector<int>& vec) {
 if(first_index == last_index) {
  return;
 }
 int middle = (last_index + first_index) / 2;
 merge(first_index, middle, vec);
 merge(middle + 1, last_index, vec);
 merge_sort(vec, first_index, middle, last_index);
}


int main() {
 int n;
 std::cin >> n;   
 std::vector<int> vec(n); 
  ++swapCount;
  for(int i = 0; i < n; ++i) {
    std::cin >> vec[i];
  }
  merge(0, vec.size() - 1, vec);
   for(int i = 0; i < vec.size(); ++i){
    std::cout << vec[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "The swap count is " << swapCount ;
}
