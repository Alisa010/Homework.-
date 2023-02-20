#include <iostream>
#include <vector>
#include <algorithm>

int findNumbersOfSwaps(std::vector<int>& vec) {
    std::vector<std::pair<int, int>> res(vec.size());
    for (int i = 0; i < vec.size(); i++) {
        res[i].first = vec[i];
        res[i].second = i;
    }
    std::sort(res.begin(), res.end());
    int swap_count = 0;
    int i = 0;
    while (i < vec.size()) {
        if (res[i].first == vec[i] || res[i].second == i) {
            ++i;
            continue;
        }
        else {
            std::swap(res[i].first, res[res[i].second].first);
            std::swap(res[i].second, res[res[i].second].second);
            if (res[i].second != i) {
                i--;
          }
        swap_count++;
        ++i;
    }
    return swap_count;
  }
}
int main() {
    std::vector<int> arr = {1, 5, 7, 3};
    std::cout << "Minimum number of swaps is " << findNumbersOfSwaps(arr);
}