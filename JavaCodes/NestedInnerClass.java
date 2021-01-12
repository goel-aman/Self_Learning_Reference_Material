public class NestedInnerClass {
    public static void main(String[] args){
        A a = new A();
        A.B obj = new A.B();
        obj.show();
    }
}



class A{
    int rollno;
    string sname;

    static class B{
        public void show(){
            System.out.println("Hello");
        }
    }
}