package com.ujs.li.client;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Panel;
import java.awt.TextArea;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;

import javax.swing.JFrame;

import org.omg.CORBA.ARG_OUT;



public class clientSocket {

	public static void main(String[] args) throws Exception {
		Socket client = new Socket("127.0.0.1",8888);
        JFrame frame = new JFrame("client");
		
		TextArea textArea = new TextArea();
		frame.add(textArea);
		
		Panel panel = new Panel();
		TextField textField = new TextField(60);
		Button button = new Button("发送");
		button.addActionListener(new Monitor(textField,textArea,client));
		textField.addKeyListener(new EnterMonitor(textField, textArea, client));
		panel.add(textField);
		panel.add(button);
		frame.add(panel,BorderLayout.SOUTH);
				
		frame.pack();
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Thread t1 = new CReceiveT(textArea,client);
		t1.start();

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
class EnterMonitor implements KeyListener{
	TextField t = null;
    TextArea textArea;
    Socket s;
    Monitor mo;
    
	public EnterMonitor(TextField t, TextArea textArea, Socket s) {
		super();
		this.t = t;
		this.textArea = textArea;
		this.s = s;
		this.mo = new Monitor(t, textArea, s);
	}

	@Override
	public void keyPressed(KeyEvent arg0) {
		
		
	}

	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent e) {
		if((char)e.getKeyChar()==KeyEvent.VK_ENTER){
			mo.actionPerformed(null);
		}
		
	}
	
}
