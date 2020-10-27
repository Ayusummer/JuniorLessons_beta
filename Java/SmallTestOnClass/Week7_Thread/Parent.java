public class Parent implements Runnable {
    BankAccount bankAccount = new BankAccount();
    public Parent(BankAccount bankAccount){
        this.bankAccount = bankAccount;
    }
    public void run(){
        for(int i=0;i<10;i++){
            bankAccount.saveMoney();
        }
    }
    
}
