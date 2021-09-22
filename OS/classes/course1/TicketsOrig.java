package classes.course1;

public class TicketsOrig {
    public static void main(String args[]){
        Runnable r=()->{
            while(Ticket.TCount>0){
                System.out.println(Thread.currentThread().getName()+"Sell one ticket,remaining "+--Ticket.TCount);
            }
        };
        Thread t1=new Thread(r,"t1");
        Thread t2=new Thread(r,"t2");
        Thread t3=new Thread(r,"t3");
        t1.start();
        t2.start();
        t3.start();
    }
}
