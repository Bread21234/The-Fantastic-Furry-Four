import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Javasort4 {
    static int cti(char c){
        return (int)c -96;
    }
    public static Map<Character, Integer> cti = new HashMap<>();
    public static void stringRadixSort(List<String> list) {
        if (list.size() <= 1) {
            return;
        }

        List<String>[] buckets = new List[43];
        for (int i = 0; i < buckets.length; i++) {
            buckets[i] = new LinkedList<>();
        }
        int largestLength = -1;
        int secondLargestLength = 0;
        for (String s : list) {
            int length = s.length();
            if (length >= largestLength) {
                secondLargestLength = largestLength;
                largestLength = length;
            } else if (secondLargestLength < length) {
                secondLargestLength = length;
            }
        }


        for (int i = secondLargestLength == largestLength ? secondLargestLength-1 : secondLargestLength; i >= 0; i--) {
            for (String word : list) {
                int index = (word.length() <= i) ? 0 : cti.get(word.charAt(i))-1;
                buckets[index].add(word);
            }

            list.clear();

            for (List<String> lst : buckets) {
                if (lst != null) {
                    list.addAll(lst);
                    lst.clear();
                }
            }
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        ArrayList<String> in = new ArrayList<>();
        String str;
        while((str=r.readLine())!=null){
            in.add(str.toLowerCase());
        }

        //ArrayList<String> in = new ArrayList<>(Arrays.asList("death", "ketamine", "poop", "apples", "bone","Capital", "banana","pee", "bodacious", "come", "adult", "cart", "cant", "darn"));
        //int n = in.size();
        for(char c: "abcdefghijklmnopqrstuvwxyz".toCharArray()){
            cti.put(c,cti(c));
        }
        for(int i=0;i<1;i++){
            cti.put('á',27);
            cti.put('â',28);
            cti.put('å',29);
            cti.put('Å',30);
            cti.put('ä',31);
            cti.put('ç',32);
            cti.put('é',33);
            cti.put('è',34);
            cti.put('ê',35);
            cti.put('í',36);
            cti.put('ñ',37);
            cti.put('ó',38);
            cti.put('ô',39);
            cti.put('ö',40);
            cti.put('û',41);
            cti.put('ü',42);
            cti.put('\'',43);
            cti.put('-',44);
        }
        stringRadixSort(in);
	for(String stri: in){
	    pw.println(stri);
	}
        pw.close();
    }
}
