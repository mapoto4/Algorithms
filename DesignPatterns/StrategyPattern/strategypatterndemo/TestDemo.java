package strategypatterndemo;

public class TestDemo {

	public static void main(String[] args) {
		
		Character ch = new Knight();
		ch.fight();
		ch.setWeapon(new AxeBehavior());
		ch.fight();
		ch.display();
		
		Character king = new King();
		king.fight();
		king.display();
	}

}
