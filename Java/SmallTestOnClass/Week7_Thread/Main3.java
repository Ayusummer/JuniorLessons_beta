public class Main3 {
    public static void main(String[] args){
        BankAccount bankAccount = new BankAccount();
        new Thread(new SonDaughter(bankAccount)).start();
        new Thread(new Parent(bankAccount)).start();
    }
}
