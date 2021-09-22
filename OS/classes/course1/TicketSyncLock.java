import java.util.concurrent.locks.ReentrantLock;

public class TicketSyncLock {
    public static void main(String[] args) {
        ReentrantLock lock =new ReentrantLock();
        Runnable r=()->{
            while(Ticket.TCount>0){
                lock.lock();
                if(Ticket.TCount<=0)
                    return;
                System.out.println(Thread.currentThread().getName()+"Sell one ticket,remaining "+--Ticket.TCount);
                lock.unlock();
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
