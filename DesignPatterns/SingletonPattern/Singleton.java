package SingletonPattern;

public class Singleton {

	public static Singleton Instance;

	private Singleton() {
		
	}

	public static Singleton getInstance() {

		if (Instance == null) {
			Instance = new Singleton();
		}

		return Instance;

	}

}
