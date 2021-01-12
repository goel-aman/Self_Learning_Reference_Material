public class AnonymousInnerClass{
    public static void main(String[] args){
        B obj = new B()
        {
            public void show(){
                System.out.println("Hello");
            }
        };
        obj.show();
    }    
}

class B{
    public void show(){
        System.out.println("Hiii");
    }
}