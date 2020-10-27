public class BankAccount {
    public int count = 1000;

    public void getMoney(){
        int temp;
        // 对类的当前对象加锁
        synchronized(this){
            temp = count;
            temp = temp - 500;
            count = temp;
            System.out.println("kids:The current count is:"+count);
        }
    }

    public void saveMoney(){
        int temp;
        synchronized(this){
            temp = count;
            temp = temp + 500;
            count = temp;
            System.out.println("parents:The current count is:"+count);
        }

    }
}
