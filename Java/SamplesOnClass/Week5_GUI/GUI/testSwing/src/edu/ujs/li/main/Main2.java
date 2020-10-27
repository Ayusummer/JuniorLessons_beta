package edu.ujs.li.main;

import java.awt.BorderLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class Main2 {

	public static void main(String[] args) {
		JFrame frame = new JFrame("test frame");
		frame.setBounds(50, 50, 500, 500);
		//frame.setLayout(new BorderLayout());
		
		JTextArea tArea = new JTextArea();
		JButton button = new JButton("press me more times");
		
		frame.add(tArea);
		//frame.add(tArea);
		
		
		//frame.add(button);
		frame.add(button);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

	}

}
