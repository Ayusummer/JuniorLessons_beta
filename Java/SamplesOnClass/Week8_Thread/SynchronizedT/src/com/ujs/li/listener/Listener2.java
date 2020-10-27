package com.ujs.li.listener;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import com.ujs.li.thread.ConsumeT;

public class Listener2 implements ActionListener {
    Thread t = null;
    
	public Listener2(Thread t) {
		super();
		this.t = t;
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		
		ConsumeT.flag2 = !ConsumeT.flag2;
		//this.notifyAll();
	}

}
