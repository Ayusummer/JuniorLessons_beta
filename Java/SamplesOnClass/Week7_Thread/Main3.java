public class Main3 {
    public static void main(String[] args) {
        BankAccount bankAccount = new BankAccount();
        new Thread(new SonDaughter(bankAccount)).start();
        new Thread(new Parent(bankAccount)).start();
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        System.out.println("当前账户余额为:" + bankAccount.count);
    }
}
