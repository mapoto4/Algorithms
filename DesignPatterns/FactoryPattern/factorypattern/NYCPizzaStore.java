package factorypatterns.factorypattern;

public class NYCPizzaStore extends PizzaStore{
	
	@Override
	Pizza creatPizza(String type) {
		if(type.equals("cheese")) {
			return new NYCCheesePizzaStyle();
		}

		else return null;
	}

}
