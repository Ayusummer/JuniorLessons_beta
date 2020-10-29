package com.ujs.li.server;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.*;
import java.util.*;
import java.util.Timer;

import javax.swing.*;

public class ServSocket {

	public static void main(String[] args) throws Exception {
		ServerSocket server = new ServerSocket(8888);
		JFrame frame = new JFrame("server");
		
		TextArea textArea = new TextArea();
		frame.add(textArea);
		
		Panel panel = new Panel();
		TextField textField = new TextField(60);
		Button button = new Button("发送");
		
		panel.add(textField);
		panel.add(button);
		frame.add(panel,BorderLayout.SOUTH);
				
		frame.pack();
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		Socket socket = server.accept();
		button.addActionListener(new Monitor(textField,textArea,socket));
		Thread thread = new Thread(new ReceiveT(textArea, socket));
		thread.start();
	}

	
}
class Monitor implements ActionListener{
	TextField t = null;
    TextArea textArea;
    Socket s;
    

	
	public Monitor(TextField t, TextArea textArea, Socket s) {
		super();
		this.t = t;
		this.textArea = textArea;
		this.s = s;
	}



	@Override
	public void actionPerformed(ActionEvent e) {
		
		try {
			DataOutputStream dos = new DataOutputStream(s.getOutputStream());
			
				if (!(t.getText().equals(""))) {
					dos.writeUTF(t.getText() + "\n");
					dos.flush();
					textArea.append("我发送了："+t.getText()+"\n");
					t.setText("");
				}
				Thread.sleep(500);
			
		} catch (Exception e1) {
			e1.printStackTrace();
		}
	}
	
}
