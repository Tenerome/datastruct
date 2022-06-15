 import java.io.BufferedReader;
 import java.io.FileNotFoundException;
 import java.io.FileReader;
 import java.io.IOException;
 import java.util.Map;
 import java.util.Set;
 import java.util.TreeMap;
 import java.util.regex.Matcher;
 import java.util.regex.Pattern;
 
 public class wordcount {
     public static void Main() {
         BufferedReader br = null;
         try {
             br = new BufferedReader(new FileReader("wordcount.txt"));
         } catch (FileNotFoundException e) {
             e.printStackTrace();
         }
         StringBuffer sb1 = new StringBuffer();
         String line = null;
         try {
             while((line = br.readLine()) != null) {
                 sb1 = sb1.append(line);
             }
         } catch (IOException e) {
             e.printStackTrace();
         }
         try {
             br.close();
         } catch (IOException e1) {
             e1.printStackTrace();
         }
         String sb=sb1.toString().toLowerCase();
         Pattern pattern = Pattern.compile("[a-zA-Z']+");
         Matcher matcher = pattern.matcher(sb);
         Map<String, Integer> map = new TreeMap<String, Integer>();
         String word = "";
         Integer num = null;
         int total = 0;
         
         while(matcher.find()) {
             word = matcher.group();
             total ++;
             if(map.containsKey(word)) {
                 num = map.get(word);
                 num += 1;
             } else {
                 num = 1;
             }
             map.put(word, num);
         }
         Set<String> keys = map.keySet();
         for (String key : keys) {
             Integer value = map.get(key);
             System.out.printf("%s: %s\n", key, value);
         }
         System.out.println();
         System.out.println("total words : " + total);
         System.out.println("different words : " + map.size());
     }
 }