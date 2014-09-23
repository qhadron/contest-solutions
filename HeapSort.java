import hsa.Console;

import java.lang.reflect.Array;
import java.lang.reflect.InvocationTargetException;

public class HeapSort {

	// algorithm at http://en.wikipedia.org/wiki/Heapsort#Pseudocode
	public static void main(String[] args) throws Exception {
		new Test(10, Integer.class);
		new Test(10, String.class);
		new Test(10, Double.class);
		new Test(10, Boolean.class);
		Test.exit();
	}

	/**
	 * Returns the parent of <code><b>child</b></code>
	 * 
	 * @return parent = floor((n-1) / 2)
	 */
	private static int parent(int child) {
		return (child - 1) >> 1;
	}

	/**
	 * Returns the child of <code><b>root</b></code>
	 * 
	 * @return child = LeftChild = 2*n + 1
	 */
	private static int leftChild(int root) {
		return (root << 1) | 1;
	}

	/**
	 * Returns the child of <code><b>root</b></code>
	 * 
	 * @return child = RightChild = 2*(n+1)
	 */
	private static int rightChild(int root) {
		return (++root << 1);
	}

	/**
	 * Swaps elements a,b in arr
	 * 
	 * @param arr
	 *            the array
	 * @param a
	 *            index a
	 * @param b
	 *            index b
	 */
	private static <T> void swap(T[] arr, int a, int b) {
		T temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	/**
	 * Sorts an array with in a strictly weak ordering
	 * 
	 * @param arr
	 *            the array to sort
	 */
	public static <T extends Comparable<? super T>> void heapSort(T[] arr) {
		sortHeap(arr, 0, arr.length);
	}

	/**
	 * <code>
	 *  <br> while (there is more than 1 element left in the heap):
	 * 	<br>	arrange the arr from [start,end) into a heap
	 *  <br>	move the first element of the heap to the last element of the array
	 *  <br>	decrease the heap size by 1
	 * </code>
	 */
	public static <T extends Comparable<? super T>> void sortHeap(T[] arr,
			int start, int end) {
		while (end > start + 1) { // more than 1 element left in the heap
			makeHeap(arr, start, end); // arrange arr[start,end) to heap
										// structure
			popHeap(arr, start, end); // move the first element of the heap to
										// the last
			end -= 1; // decrease heap size by 1
		}

	}

	/*
	 * algorithm: cur = root with the largest index while (cur is not the first
	 * root): siftDown(arr,cur,end) cur = the biggest smaller root
	 */
	public static <T extends Comparable<? super T>> void makeHeap(T[] arr,
			int start, int end) {
		int cur = parent(end - 1); // find the root with the largest index
		while (cur >= start) { // while the root is still in the heap
			siftDown(arr, cur, end);
			cur -= 1; // go to the next root
		}
	}

	/*
	 * algorithm: cur = start while (cur has at least 1 child): max = the index
	 * of the largest of (cur,leftChild,rightChild) if max != cur: swap(max,cur)
	 * cur = max (continue to the child of cur) else: finished sifting
	 */
	private static <T extends Comparable<? super T>> void siftDown(T[] arr,
			int start, int end) {
		int cur = start; // current root of the subtree
		int max = cur; // the index of the number to swap
		while (leftChild(cur) < end) { // while root has at least 1 child
			max = cur;
			if (arr[max].compareTo(arr[leftChild(cur)]) < 0) { // arr[max] <
																// arr[leftChild(cur)]
				max = leftChild(cur);
			}
			if (rightChild(cur) < end) {
				if (arr[max].compareTo(arr[rightChild(cur)]) < 0) {
					max = rightChild(cur);
				}
			}
			if (max != cur) { // if there needs to be a swap
				swap(arr, cur, max);
				cur = max; // continue to the child
			} else
				return; // done sifting
		}
	}

	// moves the first element of the heap to the end
	public static <T extends Comparable<? super T>> void popHeap(T[] arr,
			int start, int end) {
		swap(arr, start, --end);
	}

	// convert int[] to Integer[] and back while sorting
	public static void heapSort(int[] arr) {
		Integer[] temp = new Integer[arr.length];
		for (int i = 0; i < arr.length; ++i)
			temp[i] = arr[i];
		heapSort(temp);
		for (int i = 0; i < arr.length; ++i)
			arr[i] = temp[i];
	}

}

// algorithm at http://en.wikipedia.org/wiki/Heapsort#Pseudocode

class Test {
	private static final Console c = new Console("HeapSort");

	@SuppressWarnings("unchecked")
	public <T extends Comparable<? super T>> Test(int MAX, Class<T> cls)
			throws InstantiationException, IllegalAccessException,
			IllegalArgumentException, InvocationTargetException,
			NoSuchMethodException, SecurityException {
		T[] arr = (T[]) Array.newInstance(cls, MAX);
		c.println("Enter " + MAX + " " + cls.getSimpleName() + "(s): ");
		for (int i = 0; i < MAX; ++i) {
			if (cls.equals(java.lang.String.class))
				arr[i] = (T) c.readString();
			else
				arr[i] = cls.getDeclaredConstructor(String.class).newInstance(
						c.readString());
		}

		HeapSort.heapSort(arr);

		c.println(); // extra line for spacing
		c.println("The sorted array is:");

		for (int i = 0; i < MAX; ++i)
			c.print(arr[i] + " ");
		c.println("\n"); // trailing blank line
	}
	
	public static final void exit() {
		c.println("Press any key to exit....");
		c.getChar();
		c.close();
	}
}
