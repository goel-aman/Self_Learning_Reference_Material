public class InnerClassWithLambdaExpression {
    public static void main(String[] args){
        B obj = new B(){
            public void show(){
                System.out.println("Hello");
            }
        };
        obj.show();
    }
}

@FunctionalInterface
interface B{ 
    public void show();
}


// One Way of Doing it.
// class Xyz implements B {
//     public void show()
//     {

//     }
// }