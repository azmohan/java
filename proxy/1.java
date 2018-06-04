
import java.lang.reflect.*;
class MyDynamicProxy {
	public static void main(String [] args) {
		HelloImpl hello = new HelloImpl();
		MyInvocationHandler handler = new MyInvocationHandler(hello);
		Hello proxyHello = (Hello) Proxy.newProxyInstance(HelloImpl.class.getClassLoader(),HelloImpl.class.getInterfaces(),handler);
		proxyHello.sayHello();
	}

	interface Hello {
		void sayHello();
	}

	static class HelloImpl implements Hello {
		@Override
		public void sayHello() {
			System.out.println("Hello World");
		}
	}

	static class MyInvocationHandler implements InvocationHandler {
		private Object target;
		public MyInvocationHandler(Object target) {
			this.target = target;
		}

		@Override
		public Object invoke(Object proxy,Method method,Object[] args) throws Throwable {
			System.out.println("Invoking sayHello");
			Object result = method.invoke(target,args);
			return result;
		}
	}
}
