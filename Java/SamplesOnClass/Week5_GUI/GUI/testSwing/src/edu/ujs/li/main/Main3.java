package edu.ujs.li.main;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.color.ColorSpace;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class Main3 {

	public static void main(String[] args) {
		JFrame frame = new JFrame("test frame");
		frame.setBounds(50, 50, 500, 500);
		
				
		JTextArea tArea = new JTextArea();
		tArea.setBackground(Color.CYAN);
		JButton button1 = new JButton("load");
		JButton button2 = new JButton("save&quit");
		JPanel panel = new JPanel();
		
		panel.add(button1);
		panel.add(button2);
		frame.add(panel,BorderLayout.SOUTH);
		
		frame.add(tArea,BorderLayout.CENTER);
		
//		frame.add(button1,BorderLayout.SOUTH);
//		frame.add(button2,BorderLayout.SOUTH);
		
		
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

	}

}
