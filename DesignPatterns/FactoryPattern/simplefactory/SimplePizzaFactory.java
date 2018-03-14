package factorypatterns.simplefactory;

public class SimplePizzaFactory {

	public Pizza ceratePizza(String type) {
		Pizza pizza = null;
		
		if(type.equals("cheese")) {
			pizza = new CheesePizza();
		} else if(type.equals("pepperoni")) {
			pizza = new PepperonPizza();
		}
		
		return pizza;
		
	}
}
