import java.io.*;
import java.util.*;
import java.util.Scanner;

 class stud{
    public int mark;
    public String name;

    public stud(int marks,String name){
        this.mark = marks;
        this.name = name;
    }
}

public class Solution {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        stud[] student;
        int tempnum = num;
        student = new stud[num];
        int i = 0;
        while(num > 0){
            int markss = sc.nextInt();
            sc.nextLine();
            String name = sc.nextLine();
            // System.out.println("name is : " + name );
            // sc.nextLine();
            student[i] = new stud(markss,name);
            i++;
            num--;
        }
        // System.out.println("Before Sorting");
        // for(int m=0;m<tempnum;m++){
        //     System.out.println("student name : " + student[m].name + " student marks : " + student[m].mark);
        // }
        Arrays.sort(student,new Comparator<stud>(){
            @Override
            public int compare(stud a,stud b){
                if(a.mark > b.mark){
                    return -1;
                }
                return 0;
            }
        });

        // System.out.println("After sorting");
        // for(int m=0;m<tempnum;m++){
        //     System.out.println("student name : " + student[m].name + " student marks : " + student[m].mark);
        // }
        System.out.println("The ranks based on their marks: ");
        
        for(int m=0;m<tempnum;m++){
            System.out.println("Rank "+ (m + 1)+ ": " + student[m].name);
        }
    }   
}
