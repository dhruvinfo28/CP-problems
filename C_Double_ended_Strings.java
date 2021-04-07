import java.util.Scanner;
import java.lang.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i=0;i<t;i++){
            String s1,s2; s1 = sc.next(); s2 = sc.next();
            long ans = Integer.MAX_VALUE;
            int n1 = s1.length(), n2 = s2.length();
            String smaller, larger;
            if(n1<n2){ smaller = s1; larger = s2; }
            else{ smaller = s2; larger = s1;}
            n1 = smaller.length(); n2 = larger.length();
            for(int j=0;j<n1; j++){
                for(int k=j;k<n1; k++){
                    String x= smaller.substring(j,k+1);
                    int s = larger.indexOf(x);
                    if(s!=-1){
                        s+= n2 - (s + x.length());
                        s+= n1 - x.length();
                        ans = Math.min(ans,s);  
                    }
                }
            }
            if(ans==Integer.MAX_VALUE){
                ans = smaller.length() + larger.length();
            }
            System.out.println(ans);
        }
    }
}