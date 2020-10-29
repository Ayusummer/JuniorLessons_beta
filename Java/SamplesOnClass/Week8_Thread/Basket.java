public class Basket{
    public static int num = 0;
    public synchronized void put(){
        try{
            if(Basket.num >= 30){
                this.wait();    
            }
            Thread.sleep((int)(Math.random() * 1000));
            num = num +(int)(Math.random() *10 + 1);
            num = num >= 30? 30 : num;
            this.notify();
        }catch(InterruptedException e){
            e.printStackTrace();
        }

    }
}