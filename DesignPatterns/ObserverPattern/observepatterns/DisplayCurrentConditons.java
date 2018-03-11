package observepatterns;

public class DisplayCurrentConditons implements Observer,DisplayElement{

	private double temperature;
	private double humidity;
	private Subject weatherData;
	
	public DisplayCurrentConditons(Subject weatherData) {
		this.weatherData = weatherData;
		weatherData.registerObserver(this);
		
	}

	@Override
	public void update(double temp, double humidity, double pressure) {
		this.temperature = temp;
		this.humidity = humidity;
		display();
		
	}

	@Override
	public void display() {
		System.out.println("Current conditions: " + temperature +"F degrees and " + humidity + "% humidity.");
	}

}
