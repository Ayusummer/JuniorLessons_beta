import java.io.*;
public class TestFileWriter {
  public static void main(String[] args) {
    FileWriter fw = null;
    try {
      fw = new FileWriter("d:\\bak\\unicode.dat");
      for(int c=0;c<=50000;c++){
        fw.write(c);
      }
      fw.close();
    } catch (IOException e1) {
    	e1.printStackTrace();
      System.out.println("ÎÄ¼þÐ´Èë´íÎó");
      System.exit(-1);
    }
  }
}
