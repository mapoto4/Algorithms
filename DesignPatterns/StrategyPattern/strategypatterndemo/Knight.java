package strategypatterndemo;

public class Knight extends Character {
	
	public Knight() {
		weaponBehavior = new KnifeBehavior();
		
	}

	@Override
	public void display() {
		System.out.println("I am a Knight!");
	}

}
