#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool compare(const std::string& left, const std::string& right){
    int right_counter = 0, left_counter = 0;
    for (int i=0; i < right.length(); i++){
        if (right[i] == '1'){
            right_counter++;
        }
    }
    
    for (int i=0; i < left.length(); i++){
        if (left[i] == '1'){
            left_counter++;
        }
    }
    
    if (left_counter > right_counter){
        return true;
    }
    else if (left_counter == right_counter){
        return (std::stoi(left) < std::stoi(right));
    }
    else{
        return false;
    }
}
int main(){
    int count;
    std::cin >> count;
    
    std::vector<std::string> nums(count);
    for(auto& line : nums) std::cin >> line;
    
    std::sort(nums.begin(), nums.end(), compare);
    
    for(auto& line : nums) std::cout << line << ' ';
}
