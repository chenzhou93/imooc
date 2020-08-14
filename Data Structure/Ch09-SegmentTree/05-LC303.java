class NumArray{
    private SegmentTree<Integer> segmentTree;

    public numArray(int[] nums){
        if(nums.length > 0){
            Integer[] data = new Integer[nums.length];
            for(int i=0; i<nums.length; i++){
                data[i] = nums[i];
            }
            segmentTree = new SegmentTree<>(data, (a,b)-> a + b);
        }
    }

    public int sumRange(int i, int j){
        if(segmentTree == null){
            throw;
        }
        return segmentTree.query(i, j);
    }
}