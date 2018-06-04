import java.util.concurrent.*;
class Test {
	public static void main(String[] args) {
		int N = 8;
		Semaphore semaphore = new Semaphore(5);
		for (int i = 0; i < N; i++) {
			new Worker(i,semaphore).start();
		}
	}

	static class Worker extends Thread {
		private int num;
		private Semaphore semaphore;

		public Worker(int num,Semaphore semaphore) {
			this.num = num;
			this.semaphore = semaphore;
		}

		@Override
		public void run() {
			try {
				semaphore.acquire();
				System.out.println("worker " + num + " use this machine");
				Thread.sleep(3000);
				System.out.println("worker " + num + " work done");
				semaphore.release();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
