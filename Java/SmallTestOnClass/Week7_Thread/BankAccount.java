public class BankAccount {
    int count = 1000;

    public void getMoney(){
        int temp;
        temp = count;
        temp = temp - 500;

        count = temp;
        System.out.println("kids:The current count is:"+count);
    }

    public void saveMoney(){
        int temp;
        temp = count;
        temp = temp + 500;

        count = temp;
        System.out.println("parents:The current count is:"+count);
    }
}
