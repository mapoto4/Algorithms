package factorypatterns.factorypattern;

public class NYCCheesePizzaStyle extends Pizza {
	public NYCCheesePizzaStyle() {
		name = "NY style Sauce and Cheese Pizza";
		dough = "Thin Curst Dough";
		sauce = "Marinara Sauce";
		
		toppings.add("Grated Reggiano Cheese");
		
	}

}
