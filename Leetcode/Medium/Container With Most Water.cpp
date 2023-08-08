class Solution {
public:
    int maxArea(vector<int>& height) {
        int answer = 0;

        // index
        int left = 0;
        int right = height.size() - 1;

        int current_area = 0;
        while(left < right){
            int h = std::min(height[left], height[right]);
            current_area = h * (right - left);

            answer = std::max(answer, current_area);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }


        return answer;
    }
};