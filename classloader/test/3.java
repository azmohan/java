public abstract class ClassLoader {
    // The parent class loader for delegation
    // Note: VM hardcoded the offset of this field, thus all new fields
    // must be added *after* it.
    private final ClassLoader parent;

    protected ClassLoader() {
        this(checkCreateClassLoader(), null, getSystemClassLoader());
    }
    protected ClassLoader(ClassLoader parent) {
        this(checkCreateClassLoader(), null, parent);
    }
    protected ClassLoader(String name, ClassLoader parent) {
        this(checkCreateClassLoader(name), name, parent);
    }
    private ClassLoader(Void unused, String name, ClassLoader parent) {
        this.name = name;
        this.parent = parent;
        this.unnamedModule = new Module(this);
        if (ParallelLoaders.isRegistered(this.getClass())) {
            parallelLockMap = new ConcurrentHashMap<>();
            package2certs = new ConcurrentHashMap<>();
            assertionLock = new Object();
        } else {
            // no finer-grained lock; lock on the classloader instance
            parallelLockMap = null;
            package2certs = new Hashtable<>();
            assertionLock = this;
        }
    }
}
