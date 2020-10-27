package edu.ujs.li.main;

public class PreMain {

	public static void main(String[] args) {
		int[] a = new int[3];
		a[0] = 1;
		a[1] = 2;
		a[2] = 3;
		
		for(int j:a){
			System.out.println(j);
		}
		
		//A[] a1 ={new A("tom",1),new A("jerry",2)};
		A[] a1 = new A[2];  
		
		a1[0] = new A("tom",1);
		a1[1] = new A("jerry",2);
				
		for(A animal:a1){
			System.out.println(animal);
		}
		
		

	}

}
class A{
	String name;
	int id;
	public A(String name, int id) {
		super();
		this.name = name;
		this.id = id;
	}
	@Override
	public String toString() {
		return "A [name=" + name + ", id=" + id + "]";
	}
	
}
