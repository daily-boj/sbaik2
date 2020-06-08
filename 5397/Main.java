import java.io.*;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));
            OutputStream out = new BufferedOutputStream(System.out);
            int amount = Integer.parseInt(bi.readLine());
            LinkedList<Character> list = new LinkedList<>();
            for (int i = 0; i < amount; i++) {
                char[] carr = bi.readLine().toCharArray();
                int cursor = 0;
                for (char c : carr) {
                    if (c == '-') {
                        if (cursor <= 0) continue;
                        cursor--;
                        list.remove(cursor);
                    } else if (c == '<') {
                        cursor = Integer.max(cursor - 1, 0);
                    } else if (c == '>') {
                        cursor = Integer.min(cursor + 1, list.size());
                    } else {
                        list.add(cursor, c);
                        cursor++;
                    }
                }
                StringBuilder sb = new StringBuilder("");
                for (char c : list){
                    sb.append(c);
                }
                out.write((sb.toString() + "\n").getBytes());
                list.clear();
            }
            out.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}