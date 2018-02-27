package strategypatterndemo;

public class King extends Character {

	public King() {
		weaponBehavior = new AxeBehavior();
		
	}
	
	
	@Override
	public void display() {
		System.out.println("I am a King!");	
	}

}
