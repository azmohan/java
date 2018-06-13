class GenericMethodTest {
    public static <E> void printArray(E[] inputArray) {
        for (E element : inputArray) {
            System.out.printf("%s ",element);
        }
        System.out.println();
    }

    public static void main(String args[]) {
        Integer[] intArray = {1,2,3,4,5};
        Double[] doubleArray = {1.0,2.0,3.0,4.0,5.0};
        Character[] charArray = {'H','E','L','L','O'};

        System.out.println("Integer array elements : ");
        printArray(intArray);
        System.out.println("Double array elements : ");
        printArray(doubleArray);
        System.out.println("Character array elements : ");
        printArray(charArray);

    }
}
