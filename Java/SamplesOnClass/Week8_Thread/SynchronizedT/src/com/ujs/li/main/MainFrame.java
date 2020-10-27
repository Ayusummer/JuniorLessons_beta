package com.ujs.li.main;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Label;
import java.awt.Panel;
import java.awt.TextArea;

import javax.swing.JFrame;

import com.ujs.li.entity.Basket;
import com.ujs.li.listener.Listener1;
import com.ujs.li.listener.Listener2;
import com.ujs.li.thread.ConsumeT;
import com.ujs.li.thread.ProduceT;

public class MainFrame {
	 static JFrame frame = null;
	 static Label label =null;
	 static TextArea textArea = null;
	 static Basket basket = null;
	 static Thread t1 = null;
	 static Thread t2 = null;
	

	public static void main(String[] args) {
		frame = new JFrame("生产和消费同步问题"); 
		
		label = new Label();
		label.setText("篮子中馒头的数量是： "+Basket.num);
		frame.add(label,BorderLayout.NORTH);
		
		textArea = new TextArea();
		frame.add(textArea,BorderLayout.CENTER);
		
		basket = new Basket();
		t1 = new Thread(new ProduceT(textArea,label,basket));
		t2 = new Thread(new ConsumeT(textArea,label,basket));
		
		Panel panel = new Panel();
		Button button1 = new Button("生产 开/关");
		button1.addActionListener(new Listener1(t1));
		Button button2 = new Button("消费 开/关");
		button2.addActionListener(new Listener2(t2));
		panel.add(button1);
		panel.add(button2);
		frame.add(panel,BorderLayout.SOUTH);
		
		frame.setVisible(true);
		frame.pack();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		t1.start();
		t2.start();
		
		
	}
	
	
}
