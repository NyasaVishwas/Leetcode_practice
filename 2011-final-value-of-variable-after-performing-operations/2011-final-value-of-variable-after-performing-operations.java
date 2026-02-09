class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int X = 0;
        for (String x: operations){
            if (x.equals("++X") || x.equals("X++")) X++;
            if (x.equals("--X") || x.equals("X--")) X--;
        }
        return X;
    }
}