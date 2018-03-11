package observepatterns;

public class WeatherStation {
	
	public static void main(String[] args) {

		WeatherData weatherData = new WeatherData();
		WeatherDataJDK wdJKD = new WeatherDataJDK();
		
		DisplayCurrentConditons currentDisplay = new DisplayCurrentConditons(weatherData);
		DisplayStatics staticsDisplay = new DisplayStatics(weatherData);
		DisplayForecast forecastDisplay = new DisplayForecast(weatherData);
		
		DisplayCurrentConditionsJDK cd = new DisplayCurrentConditionsJDK(wdJKD);
		
	
		weatherData.setMeasurements(80, 65, 30.4f);
		weatherData.setMeasurements(82, 70, 29.2f);

		wdJKD.setMeasurements(80, 65, 30.4f);
		
	}
	
}
