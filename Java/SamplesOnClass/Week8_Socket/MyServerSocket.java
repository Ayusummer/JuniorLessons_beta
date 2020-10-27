import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class MyServerSocket {
    public static void main(String[] args) throws Exception {
        ServerSocket serverSocket = new ServerSocket(8888);

        Socket socket = serverSocket.accept();  // 阻塞式调用

        DataOutputStream dataOutputStream = 
            new DataOutputStream(socket.getOutputStream());
        //dataOutputStream.writeUTF("Hello");
        Socket socket1 = serverSocket.accept();  // 阻塞式调用

    }
}
