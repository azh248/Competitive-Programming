import java.util.*;
import java.io.*;

public class passportProcessing {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		HashSet<String> currentAttributes = new HashSet<>();
		HashSet<String> eyeColors = new HashSet<>();
		eyeColors.add("amb");
		eyeColors.add("blu");
		eyeColors.add("brn");
		eyeColors.add("gry");
		eyeColors.add("grn");
		eyeColors.add("hzl");
		eyeColors.add("oth");
		int workingPassports = 0;
		while (sc.hasNextLine()) {
			String s = sc.nextLine().trim();
			if (s.equals("")) {
				if (currentAttributes.size() == 7) {
					workingPassports++;
				}
				currentAttributes.clear();
				continue;
			}
			String[] arr = s.split(" ");
			for (String i : arr) {
				String attribute = i.substring(0, 3);
				String data = i.substring(4);
				if (attribute.equals("byr")) {
					int newData = Integer.parseInt(data);
					if (newData < 1920 || newData > 2002) {
						continue;
					}
				} else if (attribute.equals("iyr")) {
					int newData = Integer.parseInt(data);
					if (newData < 2010 || newData > 2020) {
						continue;
					}
				} else if (attribute.equals("eyr")) {
					int newData = Integer.parseInt(data);
					if (newData < 2020 || newData > 2030) {
						continue;
					}
				} else if (attribute.equals("hgt")) {
					if (data.substring(data.length() - 2).equals("in")) {
						int newData = Integer.parseInt(data.substring(0, data.length() - 2));
						if (newData < 59 || newData > 76) {
							continue;
						}
					} else if (data.substring(data.length() - 2).equals("cm")) {
						int newData = Integer.parseInt(data.substring(0, data.length() - 2));
						if (newData < 150 || newData > 193) {
							continue;
						}
					} else {
						continue;
					}
				} else if (attribute.equals("hcl")) {
					if (data.length() != 7) {
						continue;
					}
					boolean worked = true;
					for (int j = 1; j <= 6; j++) {
						int newData = (int)data.charAt(j); 
						if (newData < 48 || newData > 102 || (newData > 57 && newData < 96)) {
							worked = false;
							break;
						}
					}
					if (!worked) {
						continue;
					}
				} else if (attribute.equals("ecl")) {
					if (!eyeColors.contains(data)) {
						continue;
					}
				} else if (attribute.equals("pid")) {
					String originalData = data;
					try {
						data.charAt(8);
						Integer.parseInt(data);
					} catch (Exception e) {
						continue;
					}
					if (originalData.length() > 9) {
						continue;
					}
				} else if (attribute.equals("cid")) {
					continue;
				}
				currentAttributes.add(attribute);
			}
		}
		System.out.println(workingPassports);
	}
}
