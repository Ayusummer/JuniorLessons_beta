import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.FutureTask;

public class Main1 {
    public static void main(String[] args){
        // 创建一个线程池
        ExecutorService eService = Executors.newCachedThreadPool();
        // 创建线程
        T_Runnable tRunnable = new T_Runnable();

        T_Callable tCallable = new T_Callable();
        FutureTask<Integer> fTask = new FutureTask<>(tCallable);

        // 将线程加入线程池
        eService.submit(tRunnable);    
        eService.submit(fTask);
        System.out.println("end.");
        // 主动关闭线程
        eService.shutdown();
        // > 不会影响到刚才的两个线程,因为它在两个线程都处于空闲状态时才会执行
        // > 存在的问题:当线程存在共享资源时可能会造成冲突

    }
}
