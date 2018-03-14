package observepatterns;

import java.util.Observable;
import java.util.Observer;

public class DisplayCurrentConditionsJDK implements Observer, DisplayElement {

	Observable observable;
	private double temperature;
	private double humidity;

	public DisplayCurrentConditionsJDK(Observable observable) {
		this.observable = observable;
		observable.addObserver(this);
	}

	@Override
	public void display() {
		System.out.println("Current conditions JDK: " + temperature + "F degrees and " + humidity + "% humidity.");

	}

	@Override
	public void update(Observable o, Object arg) {
		if (o instanceof WeatherDataJDK) {
			WeatherDataJDK weatherDataJDK = (WeatherDataJDK) o;
			this.temperature = weatherDataJDK.getTemperature();
			this.humidity = weatherDataJDK.getHumidity();
			display();

		}

	}

}
