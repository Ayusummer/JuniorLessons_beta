public class T_Runnable implements Runnable {
    public void run(){
        for(int i=0;i<20;i++){
            System.out.println("T_Runnable"+" "+i);
        }
    }
    
}
