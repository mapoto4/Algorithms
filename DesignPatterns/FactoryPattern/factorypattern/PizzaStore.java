package factorypatterns.factorypattern;

public abstract class PizzaStore {

	public Pizza orderPizza(String type) {

		Pizza pizza;

		pizza = creatPizza(type);

		pizza.prepare();
		pizza.bake();
		pizza.cut();
		pizza.box();

		return pizza;

	}

	 abstract Pizza creatPizza(String type);

}
