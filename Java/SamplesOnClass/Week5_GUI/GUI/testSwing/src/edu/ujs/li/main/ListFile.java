package edu.ujs.li.main;

import java.io.*;

public class ListFile {
	public static void main(String[] args) {
		File f = new File("g:");
		/*
		File[] files = f.listFiles();
		for(File ff : files) {
			System.out.println(ff.getName());
		}
		*/
		listChilds(f, 0);
	}
	
	public static void listChilds(File f, int level) {
		
		String preStr = "";
		for(int i=0; i<level; i++) { preStr += "    "; }
			
		System.out.println(preStr + f.getName());
		if(!f.isDirectory()) return;
		File[] childs = f.listFiles();
		for(int i=0; i<childs.length; i++) {
				listChilds(childs[i], level + 1);
		}
	}
}