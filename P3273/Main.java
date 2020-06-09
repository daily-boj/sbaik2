import java.io.*;
import java.util.HashSet;
public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
            OutputStream out = new BufferedOutputStream(System.out);
            
            int n = Integer.parseInt(bi.readLine());
            HashSet<Integer> set = new HashSet<>(n);
            String[] line = bi.readLine().split(" ");
            for (String s : line) {
                set.add(Integer.parseInt(s));
            }
            
            int target  = Integer.parseInt(bi.readLine());
            int match = 0;
            for (Integer i : set) {
                if (set.contains(target - i)) {
                    match++;
                }
            }
            out.write((match/2 + "\n").getBytes());
            out.flush();
        } catch (IOException e) {        }
    }
}