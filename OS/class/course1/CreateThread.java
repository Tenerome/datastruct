
public class CreateThread{
    public static void main(String args[]){
        MyThread mt =new MyThread();
        mt.start();
        System.out.println("The main thread execution ends");

    }
}
class MyThread extends Thread{
    public void run(){
        for(int i=0;i<5;i++){
            System.out.println("Subthreaded output:"+i);
        }
    }
}