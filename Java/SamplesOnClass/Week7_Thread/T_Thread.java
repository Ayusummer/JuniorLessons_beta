public class T_Thread extends Thread{
    public void run(){
        for(int i=0;i<20;i++){
            
            System.out.println("T_Thread"+" "+i);
        }
    }
}