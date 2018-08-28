from collections import defaultdict


class Solution:
    def fill_postorder_recursion(self, root, hashmap, answer):
        if not root.left and not root.right:
            hashmap[root.val] = 0
            answer[root.val] = root.val
        else:
            left_distance, right_distance = float('inf'), float('inf')

            if root.left and hashmap[root.left.val] == -1:
                self.fill_postorder_recursion(root.left, hashmap, answer)
                left_distance = hashmap[root.left.val] + 1

            if root.right and hashmap[root.right.val] == -1:
                self.fill_postorder_recursion(root.right, hashmap, answer)
                right_distance = hashmap[root.right.val] + 1

            if left_distance > right_distance:
                hashmap[root.val] = right_distance
                answer[root.val] = answer[root.right.val]
            else:
                hashmap[root.val] = left_distance
                answer[root.val] = answer[root.left.val]

    def fill_preorder_recursion(self, root, parentval, hashmap, answer):

        if parentval != -1 and hashmap[root.val] > hashmap[parentval] + 1:
            hashmap[root.val] = hashmap[parentval] + 1;
            answer[root.val] = answer[parentval]
        if root.left:
            self.fill_preorder_recursion(root.left, root.val, hashmap, answer)
        if root.right:
            self.fill_preorder_recursion(root.right, root.val, hashmap, answer)

    def findClosestLeaf(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        hashmap = defaultdict(lambda: -1)
        answer = defaultdict(lambda: 0)

        self.fill_postorder_recursion(root, hashmap, answer)
        self.fill_preorder_recursion(root, hashmap[root.val], hashmap, answer)
        return answer[k]