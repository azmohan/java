/*************************************************************************
	> File Name: 2.java
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年05月04日 星期五 10时24分40秒
 ************************************************************************/
import java.util.concurrent.*;
class Test {
	public static void main(String[] args) {
		int n = 4;
		CyclicBarrier barrier = new CyclicBarrier(n);
		for (int i = 0;i < n; i++) {
			new Writer(barrier).start();
		}
	}

	static class Writer extends Thread {
		private CyclicBarrier cyclicBarrier;
		public Writer(CyclicBarrier cyclicBarrier) {
			cyclicBarrier = cyclicBarrier;
		}

		@Override
		public void run() {
			System.out.println("Thread " + Thread.currentThread().getName() + " is writting ");
			try {
				Thread.sleep(5000);
				System.out.println("Thread " + Thread.currentThread().getName() + " is writting over ");
				cyclicBarrier.await();
			} catch (InterruptedException e) {
				e.printStackTrace();
			} catch (BrokenBarrierException e) {
				e.printStackTrace();
			}

			System.out.println("All Thread write over");
		}
	}
}
