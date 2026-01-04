class Solution {
    public int sumFourDivisors(int[] nums) {
        int res=0;
        for (int i=0; i<nums.length; i++){
            int count=0;
            int sum=0;
            for (int j=1; j<=nums[i]; j++){
                if (nums[i]%j==0){
                    sum+=j;
                    count++;
                }
                if(count>4) break;
            }
            if (count==4){
                res+=sum;
            }
        }
        return res;
    }
}