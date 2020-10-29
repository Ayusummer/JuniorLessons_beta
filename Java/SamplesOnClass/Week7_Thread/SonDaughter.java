public class SonDaughter implements Runnable {
    BankAccount bankAccount = new BankAccount();
    public SonDaughter(BankAccount bankAccount){
        this.bankAccount = bankAccount;
    }
    public void run(){
        for(int i=0;i<10;i++){
            bankAccount.getMoney();
        }
    }
    
}
