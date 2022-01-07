public class testa {
    public static void prin(){
        System.out.println("prin");
    }
    public static void prin1(){
        System.out.println("prin1");
    }
    public static void main(String[] args) {
        int a=0;
        a=a+2;
        prin1();
        a++;
        prin();
        System.out.println(a);
    }
}
