
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
         if (root==p||root==q) {
            return root;
        }
        if (root!=null){
            TreeNode lNode=lowestCommonAncestor(root.left,p,q);
            TreeNode rNode=lowestCommonAncestor(root.right,p,q);
            if (lNode!=null&&rNode!=null)
                return root;
            else if(lNode==null) {//两个都在右子树
                return lowestCommonAncestor(rNode, p, q);
            }
            else { //两个都在左子树里面
                return lowestCommonAncestor(lNode, p, q);
            }
        }
        return null;
    }
}