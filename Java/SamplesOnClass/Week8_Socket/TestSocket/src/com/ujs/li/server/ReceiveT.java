package com.ujs.li.server;

import java.awt.TextArea;
import java.io.DataInputStream;
import java.io.IOException;
import java.net.Socket;

public class ReceiveT extends Thread {
	TextArea tf = null;
    Socket s = null;
	
	
	public ReceiveT(TextArea tf, Socket s) {
		super();
		this.tf = tf;
		this.s = s;
	}


	public void run(){
		try {
			while(true){
				DataInputStream dis = new DataInputStream(s.getInputStream());
				tf.append("�ͻ�����������:"+dis.readUTF());
			}
		} catch (IOException e) {
				e.printStackTrace();
		}
	}
}
