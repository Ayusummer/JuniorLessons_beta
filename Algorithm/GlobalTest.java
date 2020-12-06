public class NQueen {
    private int n;
    private long count;
    private int[] arr;
//    private int nn;

    public NQueen(int n){
        this.n = n;
  //      nn = (1 << n) - 1;
        count = 0;
        arr = new int[n];
    }


    /**
     * row col   i  arr[i]
     * @param row
     * @param col
     * @return
     */
    public boolean Check(int row, int col){
        for(int i = 0; i < row; i++){
            if(col == arr[i] || Math.abs(row - i) == Math.abs(col - arr[i])) //在同一列或者在同一斜线。一定不在同一行
                return false;
        }
        return true;
    }

    public void FindNQueen(int k) {
        if (k == n) {   //求出一种解， count+1
            count++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (Check(k, i)) {   //检查是否满足条件
                arr[k] = i;      //记录
                FindNQueen(k + 1);   //递归查找
            }
        }

    }

    public static void main(String args[]){
        NQueen nQueen = new NQueen(13);
        nQueen.FindNQueen(0);
        System.out.println(nQueen.count);
    }

}

