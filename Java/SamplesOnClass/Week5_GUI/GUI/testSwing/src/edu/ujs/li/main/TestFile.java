package edu.ujs.li.main;

import java.io.File;
import java.io.IOException;

public class TestFile {

	public static void main(String[] args) throws Exception  {
		String  separator = File.separator;
		String filename = "myfile.txt";
		String directory = "mydir1"+separator+"mydir2";
		
		File file = new File(directory,filename);
		if(file.exists()){
			System.out.println("filename"+file.getAbsolutePath());
			System.out.println("file size "+file.length());
		}else{
			file.getParentFile().mkdirs();
			file.createNewFile();
		}

	}

}
