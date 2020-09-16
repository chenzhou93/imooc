import java.util.HashSet;
import java.util.HashMap;

public class Main{
    public static void main(String[] args){
        int a = 42;
        //((Integer)a ).hashCode();
        System.out.println(((Integer)a ).hashCode()); //42

        int b = -42;
        System.out.println(((Integer)b).hashCode()); //-42

        int c = -3.1415926;
        System.out.println(((Double)c).hashCode()); //219937201

        String d = "imooc";
        System.out.println(d.hashCode()); //-100327135

        Student student = new Student(3, 2, "bobo", "Liu");
        System.out.println(student.hashCode()); //94107933

        HashSet<Student> set = new HashSet<>();
        set.add(student);

        HashMap<Student, Integer> scores = new HashMap<>();
        scores.put(student, 100);
    }
}