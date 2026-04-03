// Last updated: 4/3/2026, 2:04:31 PM
class Solution {
    public int romanToInt(String s) {
        char ch,ch1;
        int pos=0,pos1=0;
        int num=0;
        char sym[]={'I','V','X','L','C','D','M'};
        int val[]={1,5,10,50,100,500,1000};
        for(int i=0;i<(s.length());i++) {
            ch=s.charAt(i);
            ch1=(i==(s.length()-1)?s.charAt(i):s.charAt(i+1));
            for(int j=0;j<7;j++){
                if(ch==sym[j])
                    pos=j;
                if(ch1==sym[j])
                    pos1=j;
            }
            if(pos1>pos) {
                num+=val[pos1]-val[pos];
                i++;
            }
            else
                num+=val[pos];
        }
        return num;
    }
}