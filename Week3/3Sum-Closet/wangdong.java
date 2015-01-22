public class Solution {
    public int threeSumClosest(int[] num, int target) {
        Arrays.sort(num);
        
        int min = 65535;
        int result = 0;
        for(int i = 0; i < num.length; i++) {
            int left = i + 1;
            int right = num.length - 1;
            while(left < right) {
                int sum = num[i] + num[left] + num [right];
                if(sum == target) {
                    return sum;
                }
                if(sum < target) {
                    if(Math.abs(sum - target) < min) {
                        min = Math.abs(sum - target);
                        result = sum;
                    }
                    left++;
                }
                else {
                    if(Math.abs(sum - target) < min) {
                        min = Math.abs(sum - target);
                        result = sum;
                    }
                    right--;
                }
            }
        }
        return result;
    }
}
