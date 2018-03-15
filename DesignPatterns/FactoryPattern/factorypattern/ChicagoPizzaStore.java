package factorypatterns.factorypattern;

public class ChicagoPizzaStore  extends PizzaStore{

	@Override
	Pizza creatPizza(String type) {
		if(type.equals("cheese")) {
			return new NYCCheesePizzaStyle();
		}

		else return null;
	}
}
