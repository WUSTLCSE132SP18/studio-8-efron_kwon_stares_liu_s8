package studio8;

import java.io.File;

import com.sun.java_cup.internal.runtime.Scanner;

// TODO: Develop an algorithm to count steps in accelerometer data
//    Major steeps:
//       1. Create a class and main method.
//       2. Using a Scanner and File object, read data from your .csv file.
//       3. Develop and test algorithms to count the "peaks" in the data.

public class CountSteps {
	private double[] z;
	private int counts;
	
	public CountSteps (Scanner scan) {
		this.z = new double[10];
		int count = 0;
	}
	
	public static void main (String[] args) {
			File file = new File("data/data.csv");
			Scanner scan = new Scanner(file);
			
			CountSteps counts = new CountSteps (scan);
			
	}
}

