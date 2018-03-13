package decoratepatterns;

public class StarBuckCoffee {

	public static void main(String[] args) {
	
		Beverage coffee = new Espresso();
		
		System.out.println(coffee.getDescription()+ "$ " + coffee.cost());
		
		Beverage coffee2 = new Espresso();
		coffee2 = new Mocha(coffee2);
		System.out.println(coffee2.getDescription()+ "$ " + coffee2.cost());
		
		Beverage coffee3 = new Espresso();
		coffee3 = new Mocha(coffee3);
		coffee3 = new Soy(coffee3);
		coffee3 = new Whip(coffee3);
		System.out.println(coffee3.getDescription()+ "$ " + coffee3.cost());
		
		
		
	}

}
