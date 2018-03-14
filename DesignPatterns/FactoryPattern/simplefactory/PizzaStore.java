package factorypatterns.simplefactory;

public class PizzaStore {

	SimplePizzaFactory factory;

	public PizzaStore(SimplePizzaFactory factory) {
		this.factory = factory;

	}

	public Pizza orderPizza(String type) {
		Pizza pizza;

		pizza = factory.ceratePizza(type);

		pizza.prepare();
		pizza.bake();
		pizza.cut();
		pizza.box();

		return pizza;

	}

}
