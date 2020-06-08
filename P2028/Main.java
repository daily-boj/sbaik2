import java.io.*;
import java.lang.Integer;
public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
            OutputStream out = new BufferedOutputStream(System.out);
            int N = Integer.parseInt(bi.readLine());
            while(N > 0) {
                N--;
                int k = Integer.parseInt(bi.readLine());
                String q = Integer.toString(k * k);
                if (q.endsWith(Integer.toString(k))) {
                    out.write("YES\n".getBytes());
                } else {
                    out.write("NO\n".getBytes());
                }
            }
            out.flush();
        } catch (IOException e) {        }
    }
}