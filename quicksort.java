import java.util.Scanner;

public class quicksort {
	
	
	public static void swap(int[] n, int a, int b) {
		if (a==b||n[a]==n[b])
			return;
		int c = n[a];
		n[a] = n[b];
		n[b] = c;
	}
	
	public static int med3(int a, int b, int c) {
		if (b > a) {
			if (c > b)
				return b;
			else {
 				if (c > a)
					return c;
				else
					return a;
			}
		} else {
			if (c > a)
				return a;
			else {
				if (c > b)
					return c;
				else
					return b;
			}
		}
	}
	
	
	public static void qsort(int[] n) {
		qs(n,0,n.length);
	}
	
	///sorts array from [l,r)
	public static void qs(int[] n, int l, int r) {
		if (r - l < 2)
			return;
		if (r - l == 2)
			if (n[--r] < n[l]) {
				swap(n,l,r);
			} else
				return;
		int start = l, end = r;
		--r;
		int p = med3(n[l],n[r],n[(l+r)/2]);
		//System.out.println("=============================================");
		System.out.printf("[%d,%d) %d\n",l,r,p);
		while(l <= r) {
			while (n[l] < p)
				++l;
			while(n[r] > p)
				--r;
			//System.out.printf("in between: (%d,%d):%d&%d\n",l,r,n[l],n[r]);
			if (l <= r) {
				swap(n,l,r);
				++l;
				--r;
			}
			//print(n);
		}
		//System.out.printf("[%d,%d)\t[%d,%d)\n",start,r+1,l,end);
		//System.out.println();
		qs(n,start,++r);
		qs(n,l,end);
	}
	
	public static void print(int[] n) {
		for (int i : n)
			System.out.print(i + " ");
		System.out.println();
	}
	
	public static void main(String[] args) {
		int[] test = new int[20];
		for (int i = 0; i < test.length; ++i)
			test[i] = (int)(Math.random() * test.length);
		print(test);
		qsort(test);
		print(test);
	}
}