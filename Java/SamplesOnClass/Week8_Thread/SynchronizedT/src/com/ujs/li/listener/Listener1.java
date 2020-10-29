package com.ujs.li.listener;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import com.ujs.li.thread.ProduceT;

public class Listener1 implements ActionListener {
   Thread t = null;
   
	public Listener1(Thread t) {
	super();
	this.t = t;
}

	@Override
	public void actionPerformed(ActionEvent e) {
		
		
		ProduceT.flag2 = !ProduceT.flag2;
		//this.notifyAll();
	}

}
