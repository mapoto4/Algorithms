package factorypatterns.factorypattern;

public class PizzzaDriveTest {

	public static void main(String[] args) {
		PizzaStore nyStore = new NYCPizzaStore();
		PizzaStore chicagoStore = new ChicagoPizzaStore();
		
		Pizza pizza = nyStore.orderPizza("cheese");
		System.out.println("Ethan ordered a " + pizza.getName()+"\n");
		
		pizza = chicagoStore.orderPizza("cheese");
		System.out.println("Joel ordered a " + pizza.getName()+"\n");
		
		
		
	}
	
	
}
