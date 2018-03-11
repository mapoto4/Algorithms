package observepatterns;

import java.util.ArrayList;

public class WeatherData implements Subject {

	private ArrayList observers;
	private double temperature;
	private double humidity;
	private double pressure;

	public WeatherData() {
		observers = new ArrayList();
	}

	@Override
	public void registerObserver(Observer O) {
		observers.add(O);
	}

	@Override
	public void removeObserver(Observer O) {
		int i = observers.indexOf(O);
		if (i >= 0) {
			observers.remove(i);
		}
	}

	@Override
	public void notifyObserver() {
		for(int i = 0;i<observers.size();i++) {
			Observer observer = (Observer)observers.get(i);
			observer.update(temperature, humidity, pressure);
		}
	}
	
	public void measurementsChanged(){
		notifyObserver();
	}
	
	public void setMeasurements(double temperature,double humidity,double pressure) {
		this.temperature = temperature;
		this.humidity = humidity;
		this.pressure = pressure;
		measurementsChanged();
	}

}
