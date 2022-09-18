import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Javasort3 {
    static int cti(char c){
        return (int)c -96;
    }
    public static Map<Character, Integer> cti = new HashMap<>();
    static String[] mergeSort(String[] Arr,
                              int lo, int hi)
    {
        if (lo == hi) {
            String[] A = { Arr[lo] };
            return A;
        }
        int mid = lo + (hi - lo) / 2;
        String[] arr1 = mergeSort(Arr, lo, mid);
        String[] arr2 = mergeSort(Arr, mid + 1, hi);

        String[] arr3 = merge(arr1, arr2);
        return arr3;
    }

    static String[] merge(
            String[] Arr1, String[] Arr2)
    {
        int m = Arr1.length;
        int n = Arr2.length;
        String[] Arr3 = new String[m + n];

        int idx = 0;

        int i = 0;
        int j = 0;

        while (i < m && j < n) {
            if (isAlphabeticallySmaller(
                    Arr1[i], Arr2[j])) {

                Arr3[idx] = Arr1[i];
                i++;
                idx++;
            }
            else {
                Arr3[idx] = Arr2[j];
                j++;
                idx++;
            }
        }
        while (i < m) {
            Arr3[idx] = Arr1[i];
            i++;
            idx++;
        }
        while (j < n) {
            Arr3[idx] = Arr2[j];
            j++;
            idx++;
        }
        return Arr3;
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
	    if(adj[i].size()>0){
		String[] inp = new String[adj[i].size()];
		inp = adj[i].toArray(inp);
		String[] sorte = mergeSort(inp,0,inp.length-1);
		sor.addAll(Arrays.asList(sorte));
	    }
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
