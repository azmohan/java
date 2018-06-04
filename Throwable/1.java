class Test {
	public static void main(String[] args) {
		try {
			Class.forName("Hello");
		} catch (ClassNotFoundException e) {
			System.out.println(e.toString());
		}
	}
}
