import java.io.DataInputStream;
import java.net.Socket;

public class MyClientSocket {
    public static void main(String[] args)throws Exception{
        Socket socket = new Socket("127.0.0.1",8888);

        DataInputStream dataInputStream =
            new DataInputStream(socket.getInputStream());
        String string = dataInputStream.readUTF();  // 阻塞式调用(只有收到消息之后程序才会向下进行)
        System.out.println(string);
        System.out.println("end");
    }
}
