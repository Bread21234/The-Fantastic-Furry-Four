import java.util.*;
import java.io.*;

public class Javasort1 {
    static int cti(char c){
        return (int)c -96;
    }
    public static Map<Character, Integer> cti = new HashMap<>();
    static ArrayList<String> bubbleSort(ArrayList<String> arrl, int n)
    {
        ArrayList<String> arr = arrl;
        String temp;
        boolean swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (isAlphabeticallySmaller(arr.get(j + 1), arr.get(j))) {
                    temp = arr.get(j);
                    arr.set(j,arr.get(j+1));
                    arr.set(j + 1, temp);
                    swapped = true;
                }
            }
            if (swapped == false)
                break;
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
            adj[cti.get(fl)-1].add(s);
        }
        ArrayList<String> sor = new ArrayList<>();
        for(int i=0; i<42; i++){
            int sn = adj[i].size();
            sor.addAll(bubbleSort(adj[i],sn));
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
	    pw.println(str);
	}
	pw.close();
    }
}
