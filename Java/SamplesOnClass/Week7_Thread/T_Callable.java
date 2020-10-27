import java.util.concurrent.Callable;

public class T_Callable implements Callable<Integer> {
    public Integer call() throws Exception{
        int sum = 0;
        for(int i=0;i<20;i++){
            System.out.println("T_Callable"+" "+i);
            sum += i;
        }
        return sum;
    }
}
