import java.lang.*;


public class reverse_int {
    public static void main(String[] args)
    {
			System.out.println(reverse(123));
    }
/*
    private static int reverse(int x) {
        if (x > -10 && x < 10) return x;
        boolean negative = false;
        if (x < 0){
            x = -x;
            negative = true;
        }
        StringBuilder sb = itoa(x);
System.out.println(sb);
//        sb.reverse();
        x = atoi(sb.toString());
        return negative ? -x : x;
    }
*/
    public static int reverse(int x) {
        if (x > -10 && x < 10) return x;
        boolean negative = false;
        if (x < 0){
            x = -x;
            negative = true;
        }
        String str = Integer.toString(x);
        StringBuilder sb = new StringBuilder(str);
        sb.reverse();
        x = Integer.parseInt(sb.toString());
        return negative ? -x : x;
    }
    private static int atoi(String str)
    {
        int ret = 0;
//        for (int i : str.length())
        for (char c : str.toCharArray())
        {
            ret *= 10;
            ret += c - '0';
        }
        return ret;
    }
    private static StringBuilder itoa(int x)
    {
        StringBuilder ret = new StringBuilder();
        while (x > 0)
        {
            ret.append(x%10 + '0');
            x /= 10;
        }
        return ret;
    }
}
