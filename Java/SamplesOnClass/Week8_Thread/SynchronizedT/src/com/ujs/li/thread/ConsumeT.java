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
			l.setText("��������ͷ�������ǣ� " + Basket.num);
			t.append("�߳�������ʳ���ʣ" + Basket.num + "��ʳ��\n");
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
