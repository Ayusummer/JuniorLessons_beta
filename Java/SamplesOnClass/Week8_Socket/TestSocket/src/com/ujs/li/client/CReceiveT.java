package com.ujs.li.client;

import java.awt.TextArea;
import java.awt.TextField;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class CReceiveT extends Thread {
	TextArea tf = null;
    Socket s = null;
	
	
	public CReceiveT(TextArea tf, Socket s) {
		super();
		this.tf = tf;
		this.s = s;
	}


	public void run(){
		try {
			while(true){
				DataInputStream dis = new DataInputStream(s.getInputStream());
				tf.append("��������������:"+dis.readUTF());
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
