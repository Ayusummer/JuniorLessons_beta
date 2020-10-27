package com.ujs.li.thread;

import java.awt.Label;
import java.awt.TextArea;

import com.ujs.li.entity.Basket;

public class ConsumeT implements Runnable {
	public static boolean flag1 = true;
	public static boolean flag2 = true;
	TextArea t = null;
	Label l = null;
	Basket basket = null;

	public ConsumeT(TextArea t, Label l, Basket basket) {
		super();
		this.t = t;
		this.l = l;
		this.basket = basket;
	}

	@Override
	public void run() {
		while (flag1) {
           if(flag2){
			basket.get();
			l.setText("篮子中馒头的数量是： " + Basket.num);
			t.append("线程消费了食物。还剩" + Basket.num + "个食物\n");
           }else{
        	   try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
           }
		}

	}

}
