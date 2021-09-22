public class CreateThread{
    public static  void main(String args[]){
        MyThread mt =new MyThread();
        mt.start();
        System.out.println("The main thread execution ends");

    }
}
