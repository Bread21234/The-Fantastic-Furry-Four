import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Javasort2 {
    static int cti(char c){
        return (int)c -96;
    }
    public static Map<Character, Integer> cti = new HashMap<>();
    static ArrayList<String> insertionSort(ArrayList<String> arrl)
    {
        ArrayList<String> arr = arrl;
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            String key = arr.get(i);
            int j = i - 1;

            while (j >= 0 && isAlphabeticallySmaller(key, arr.get(j))) {
                arr.set(j + 1, arr.get(j));
                j = j - 1;
            }
            arr.set(j + 1, key);
        }
        return arr;
    }

    static boolean isAlphabeticallySmaller(String str1, String str2)
    {
        str1 = str1.toUpperCase();
        str2 = str2.toUpperCase();
        if (str1.compareTo(str2) < 0) {
            return true;
        }
        return false;
    }
    static ArrayList<String> bsort(ArrayList<String> arr){
        ArrayList<String>[] adj = new ArrayList[42];
        for(int i=0; i<42; i++){
            adj[i] = new ArrayList<>();
        }
        for(String s: arr) {
            char fl = Character.toLowerCase(s.charAt(0));
            int index = cti.get(fl) - 1;
            adj[index].add(s);
        }
        ArrayList<String> sor = new ArrayList<>();
        for(int i=0; i<42; i++){
            sor.addAll(insertionSort(adj[i]));
        }


        return sor;
    }
    public static void main(String[] args) throws IOException{
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        ArrayList<String> in = new ArrayList<>();
        String str = "";
        while((str=r.readLine())!=null){
            in.add(str);
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
        }
        ArrayList<String> sorted = bsort(in);
	for(String stri: sorted){
	    pw.println(stri);
	}
	pw.close();
    }
}
