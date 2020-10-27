package edu.ujs.li.listener;

import java.awt.TextArea;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;
import javax.swing.JTextArea;

public class CompanyListener implements ActionListener {

	JTextArea TextArea;
	
	public CompanyListener(JTextArea textArea) {
		super();
		TextArea = textArea;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		JOptionPane.showMessageDialog(null, TextArea.getText(),
				"company",JOptionPane.DEFAULT_OPTION);
	}

}
