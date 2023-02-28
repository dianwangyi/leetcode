#include<string>
#include<vector>
using namespace std;

// @lc code=start
int maxArea(vector<int>& height) {
    int area = 0, left = 0, right = 0, width = 0;
    for(int leftIndex = 0; leftIndex < height.size()-1; leftIndex++){
        for(int rightIndex = leftIndex+1; rightIndex < height.size(); rightIndex++){
            left = height[leftIndex];
            right = height[rightIndex];
            width = rightIndex - leftIndex;
            int tempArea = min(left, right) * width;
            area = max(area, tempArea);
        }
    }
    return area;
}

int main(){
    vector<int> h = {1,2};
    int ans = maxArea(h);
    return 0;
}
