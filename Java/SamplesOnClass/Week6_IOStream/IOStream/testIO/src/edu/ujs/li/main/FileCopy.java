package edu.ujs.li.main;

import java.io.*;
public class FileCopy {
  public static void main(String[] args)throws Exception {
	  int b = 0;
	  FileReader in = null;
	  FileWriter out = null;
	
			in = new FileReader("d:/workspace/CompanyListener.java");
			out = new FileWriter("d:/workspace/log.txt");
			while((b=in.read())!=-1){
			  out.write(b);
			}
			out.close();
			in.close();
	
	  System.out.println("文件已复制");
  }
}
