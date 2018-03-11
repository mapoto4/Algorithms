package observepatterns;

public class DisplayForecast implements Observer, DisplayElement {

	private double currentPressure = 29.29f;
	private double lastPressure;
	private WeatherData weatherData;

	public DisplayForecast(WeatherData weatherData) {
		this.weatherData = weatherData;
		weatherData.registerObserver(this);
	}

	@Override
	public void display() {
		System.out.print("Forecast: ");
		if (currentPressure > lastPressure) {
			System.out.println("Improving weather on the way!");
		} else if (currentPressure == lastPressure) {
			System.out.println("More of the same");
		} else if (currentPressure < lastPressure) {
			System.out.println("Watch out for cooler, rainy weather");
		}
	}

	@Override
	public void update(double temp, double humidity, double pressure) {
		lastPressure = currentPressure;
		currentPressure = pressure;
		display();
	}

}
