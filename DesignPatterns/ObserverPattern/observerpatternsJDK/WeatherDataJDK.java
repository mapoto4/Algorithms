package observepatterns;

import java.util.Observable;
import java.util.Observer;

public class WeatherDataJDK extends Observable{
	private double temperature;
	private double humidity;
	private double pressure;
	
	public WeatherDataJDK() {}
	
	public void measurementsChanged() {
		setChanged();
		notifyObservers();
	}
	
	public void setMeasurements(double temperature,double humidity,double pressure) {
		this.temperature = temperature;
		this.humidity = humidity;
		this.pressure = pressure;
		measurementsChanged();
	}

	public double getTemperature() {
		return temperature;
	}

	public double getHumidity() {
		return humidity;
	}

	public double getPressure() {
		return pressure;
	}

	
}
