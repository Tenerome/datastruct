class KMP{
    public static void getNext(String T,int next[]){
        int i=1,j=0;
        next[1]=0;
        while(i<T.length()){
            if(j==0||T.charAt(i-1)==T.charAt(i-1)){
                i++;
                j++;
                next[i]=j;
            }else{
                j=next[j];
            }
        }
    }
    public static void Index_KMP(String S,String T,int next[]){
        int i=1,j=1;
        while(i<=S.length()&&j<=T.length()){
            if(j==0||S.charAt(i-1)==T.charAt(j-1)){
                i++;
                j++;
            }else{
                j=next[j];
            }
        }
        if(j>T.length()){
            System.out.println("匹配成功");
            System.out.println("T在S中的起始位置为:"+(i-T.length()));
        }else{
            System.out.println("匹配失败");
        }
    }
    public static void main(String[] args) {
        String str="aaaabcdd";
        String ttr="aabc";
        int next[]=new int[100];
        getNext(ttr,next);
        Index_KMP(str,ttr,next);
    }

}