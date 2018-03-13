package decoratepatterns;

public class Whip extends CondimentDecorator{
	Beverage beverage;
	
	public Whip(Beverage beverage) {
		this.beverage = beverage;
	}
	

	@Override
	public String getDescription() {
		return beverage.getDescription()+",whip ";
	}

	@Override
	public double cost() {
		return 4 + beverage.cost();
	}

}
