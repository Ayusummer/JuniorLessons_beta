package com.ujs.li.entity;

public class Basket {
	
	public static int num=0;
	
	public  synchronized void put(){
			
		try {
			if (Basket.num >= 30) {
				this.wait();
			}
			
			Thread.sleep((int) (Math.random() * 1000));
			num=num+(int) (Math.random() * 10+1);
			num = num>=30?30:num;
			this.notify();
						
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public  synchronized void get(){
		try {
			if (Basket.num <= 0) {
				this.wait();
			}
			
			Thread.sleep((int) (Math.random() * 1000));
			num=num-(int) (Math.random() * 10+1);
			num = num<=0?0:num;
			this.notify();
		
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
