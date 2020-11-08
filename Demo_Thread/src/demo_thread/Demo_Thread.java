package demo_thread;

import java.util.logging.Level;
import java.util.logging.Logger;

public class Demo_Thread {

    public static void main(String[] args) {
        Thread t1= new Thread(new Thread(){
            @Override
            public void run(){
                for (int i = 0; i < 100; i++) {
                    System.out.println("Loading "+i+"%");
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(Demo_Thread.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }
        });
        
        t1.start();
    }
    
}
