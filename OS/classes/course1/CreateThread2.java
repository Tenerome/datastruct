package classes.course1;
public class CreateThread2{
    public static void main(String args[]){
        Runnable r=()->{
            for(int i=0;i<5;i++)
                System.out.println("Thread output:"+i);
       
        };
        Thread t=new Thread(r);
        t.start();
        System.out.println("The main thread ends");

    }
}