import java.util.*;

public class G_generateBinaryStrings {
    public static List<String> generateBinaryStrings(int n) {
      // code here
      List<String> ans = new ArrayList<>();
          ans.add("0");
          ans.add("1");
      return generateBinaryStrings(n,ans); 
      
    }
      public static List<String> generateBinaryStrings(int n,List<String> ans ) {
      // code here
      if(n==1){
          return ans;
      }
      ans=generateBinaryStrings(n-1,ans);
      List<String> copy = new ArrayList<>(ans);
      ans.clear();
      for(int i=0;i<copy.size();i++){
          String s=copy.get(i);
          ans.add(s+"0");
          if(s.charAt(s.length()-1)!='1'){
          ans.add(s+"1");
          }
      }
      return ans;
    }

    public static void main(String[] args) {
        int n = 4;
        List<String> result = generateBinaryStrings(n);
        System.out.println(result);
      }
  }