package strategypatterndemo;

public abstract class Character {
	WeaponBehavior weaponBehavior;
	
	public  Character(){
	
	}
	
	public abstract void display();
	
	
	public void setWeapon(WeaponBehavior w) {
		weaponBehavior = w;
	}
	
	public void fight() {
		weaponBehavior.useWeapon();
	}
	
	
}
