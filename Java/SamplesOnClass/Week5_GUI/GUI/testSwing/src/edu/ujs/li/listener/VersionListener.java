package edu.ujs.li.listener;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JOptionPane;

public class VersionListener implements ActionListener {

	@Override
	public void actionPerformed(ActionEvent arg0) {
		JOptionPane.showMessageDialog(null, "vision 1.0","vision"
				,JOptionPane.DEFAULT_OPTION);

		
	}

}
