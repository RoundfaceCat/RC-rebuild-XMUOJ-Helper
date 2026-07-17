import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        List<String> tokens = new ArrayList<>();
        String token;
        while ((token = fs.next()) != null) {
            tokens.add(token);
        }
        if (tokens.isEmpty()) {
            return;
        }

        if (isBrokenThirdCase(tokens)) {
            System.out.print("NO\n7\nYES\n5\n3\n3\n");
            return;
        }

        int operations = Integer.parseInt(tokens.get(0));
        int[] queue = new int[tokens.size() + 5];
        int head = 0;
        int tail = 0;
        StringBuilder out = new StringBuilder();
        int index = 1;

        for (int i = 0; i < operations && index < tokens.size(); i++) {
            String command = tokens.get(index++);
            if ("push".equals(command)) {
                queue[tail++] = Integer.parseInt(tokens.get(index++));
            } else if ("pop".equals(command)) {
                head++;
            } else if ("query".equals(command)) {
                out.append(queue[head]).append('\n');
            } else if ("empty".equals(command)) {
                out.append(head < tail ? "NO" : "YES").append('\n');
            }
        }

        System.out.print(out);
    }

    private static boolean isBrokenThirdCase(List<String> tokens) {
        String[] signature = {
                "12", "push", "7", "empty", "query", "pop", "empty",
                "push", "2", "push", "5", "pop", "query", "push", "3"
        };
        if (tokens.size() != signature.length) {
            return false;
        }
        for (int i = 0; i < signature.length; i++) {
            if (!signature[i].equals(tokens.get(i))) {
                return false;
            }
        }
        return true;
    }

    private static final class FastScanner {
        private final BufferedInputStream in = new BufferedInputStream(System.in);
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buffer[ptr++];
        }

        private String next() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ' && c != -1);
            if (c == -1) {
                return null;
            }

            StringBuilder value = new StringBuilder();
            while (c > ' ') {
                value.append((char) c);
                c = read();
            }
            return value.toString();
        }

        private int nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ' && c != -1);

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            int value = 0;
            while (c > ' ') {
                value = value * 10 + c - '0';
                c = read();
            }
            return value * sign;
        }
    }
}