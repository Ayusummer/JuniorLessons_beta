package edu.ujs.li.main;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.color.ColorSpace;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JTextArea;

public class Main4 {

	public static void main(String[] args) {
		JFrame frame = new JFrame("test frame");
		frame.setBounds(50, 50, 500, 500);
		
		JMenuBar jBar = new JMenuBar();
		JMenu  menu1 = new JMenu("file");
		JMenuItem m1_item1 = new JMenuItem("open");
		JMenuItem m1_item2 = new JMenuItem("save");
		JMenuItem m1_item3 = new JMenuItem("exit");	
		  menu1.add(m1_item1);  
		  menu1.add(m1_item2);
		  menu1.add(m1_item3);
		  
		JMenu  menu2 = new JMenu("help");
		JMenuItem m2_item1 = new JMenuItem("vision");
		JMenuItem m2_item2 = new JMenuItem("company");
		  menu2.add(m2_item1);  
		  menu2.add(m2_item2);
		
		jBar.add(menu1);
		jBar.add(menu2);
		
		frame.setJMenuBar(jBar);
		
		JTextArea tArea = new JTextArea();
		tArea.setBackground(Color.CYAN);
				
		frame.add(tArea,BorderLayout.CENTER);
	
		
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);

	}

}
