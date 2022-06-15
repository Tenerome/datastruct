public class count {
    public static void main(String[] args) {
        wordcount wc=new wordcount();
        long stime=System.currentTimeMillis();
        wc.Main();
        long etime=System.currentTimeMillis();
        double time=(etime-stime)/1000.0;
        System.out.println("Excute time:"+time+"s");
    }
}
