public class Main{
    public static void main(Stirng[] args){
        BST<Integer> bst = new BST<>();
        Random random = new Random();

        int[] nums = {5, 3, 6, 8, 4, 2};

        for(int num:nums){
            bst.add(num);
        }

        bst.preOrder();
        System.out.println();
        System.out.println(bst);
        bst.levelOrder();

        //Test remove
        int n = 1000;
        for(int i=0; i<n; i++){
            bst.add(random.nextInt(10000));
        }

        ArrayList<Integer> nums = new ArrayList<>();
        while(!bst){
            nums.add(bst.removeMin());
        }
        System.out.println(nums);

        for(int i=1; i<num.size(); i++){
            if(nums.get(i-1) > nums.get(i)){
               throw new IlletalArgumentException("error"); 
            }
        }
    }
}