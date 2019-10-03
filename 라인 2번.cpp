import java.io.*;
class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String size = br.readLine();

		int idx1 = size.indexOf("x");
		int idx2 = size.indexOf(":");

		String X = size.substring(idx2 + 2, idx1 - 1);
		String Y = size.substring(idx1 + 2);
		System.out.println(X);
		System.out.println(Y);


		String bc = br.readLine();
		int idx3 = bc.indexOf(":");
		String hex = bc.substring(idx3 + 2);
		hex = hex.replaceFirst("^0x", "");
		int n1 = Integer.parseInt(hex, 16);
		System.out.println(n1);

		String f = br.readLine();
		int idx4 = f.indexOf(":");
		String nn = f.substring(idx4 + 2);
		int n = Integer.parseInt(nn);
		System.out.println(n);

		String S = br.readLine();

		for (int i = 0; i<n; i++) {
			String whad = br.readLine();
			String spliting[] = whad.split("\\s");
			int YorN;
			String yes = "yes";
			if (spliting[3].equals(yes)) YorN = 1;
			else YorN = 0;
			System.out.println(spliting[1] + "x" + spliting[2] + ", " + spliting[4] + ", " + YorN);
		}
	}
}