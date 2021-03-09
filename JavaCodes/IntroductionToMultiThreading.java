public class IntroductionToMultiThreading {
    public static void main(String args[]){
        Thread th = Thread.currentThread();

        System.out.println("Current Thread : " + th.getName());

        // 10 Threads .. 
        th.setName("MyThread");

        System.out.println("Updated Thread Name : " + th.getName());

        try{
            Thread.sleep(2000);    
        }
        catch(Exception e){
            System.out.println("Exception occured");
        }
        
        System.out.println("Aman");
    }
}
