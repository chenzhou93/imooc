public class Main{
    public static void main(String[] args){
        //Open new space
        int[] arr = new int[10];

        //Visit, assignment
        for(int i=0; i<arr.length; i++){
            arr[i] = i;
        }

        //Initialization
        int[]scores = new int[]{100, 99, 66};
        for(int i=0; i<scores.length; i++){
            System.out.println(scores[i]);
        }

        //For each loop
        for(int score: scores){
            System.out.println(score);
        }

        //Edit
        scores[0] = 98;
    }
}