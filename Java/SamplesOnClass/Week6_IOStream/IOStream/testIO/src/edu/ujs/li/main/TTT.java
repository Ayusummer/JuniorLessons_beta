package edu.ujs.li.main;

import java.io.*;

public class TTT {
	public static void main(String[] args) {
		listF(new File("d:/cxf"), 0);
	}
	
	public static void listF(File f, int level) {
		String preStr = "";
		for(int i=0; i<level; i++) preStr += "    ";
		System.out.println(preStr + f.getName());
		if(f.isDirectory()) {
			File[] files = f.listFiles();
			for(File cf : files) listF(cf, level + 1);
		}
	}
}