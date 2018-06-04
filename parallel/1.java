/*************************************************************************
	> File Name: 1.java
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2018年05月03日 星期四 17时43分34秒
 ************************************************************************/
import java.util.concurrent.*;

class Test {
	private static int waitTime = 0;
	public static void main(String[] args) {
		final CountDownLatch latch = new CountDownLatch(3);
		for (int i = 0;i < 3; i++) {
			waitTime = 1000 + i * 100;
			new Thread() {
				public void run() {
					try {
						System.out.println("sub thread : "+Thread.currentThread().getName() + " is running");
						Thread.sleep(3000 );
						System.out.println("sub thread : "+Thread.currentThread().getName() + " is runned over");
						latch.countDown();
					} catch (InterruptedException e) {
						System.out.println("Exception : "+e.toString());
					}
				}
			}.start();
		}
		System.out.println("main thread running");
		/*
		try {
			System.out.println("wait to 3 thread excute over");
			latch.await();
			System.out.println("3 thread run over");
			System.out.println("waiting thread go on");
		} catch (InterruptedException e) {
			System.out.println("Exception : " + e.toString());
		}
		*/
	}
}
