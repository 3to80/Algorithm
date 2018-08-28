class Solution:
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        max_val = -1
        Queue = []
        if not root:
            return 0
        Queue.append([root, 1])
        while Queue:
            target = Queue.pop()
            left, right = target[0].left, target[0].right

            if not left and not right:
                max_val = max(max_val, target[1])

            elif not left:
                if target[0].val + 1 != right.val:
                    max_val = max(max_val, target[1])
                    Queue.append([right, 1])
                else:
                    Queue.append([right, target[1]+1])

            elif not right:
                if target[0].val + 1 != left.val:
                    max_val = max(max_val, target[1])
                    Queue.append([left, 1])
                else:
                    Queue.append([left, target[1] + 1])


            else:
                if target[0].val + 1 != left.val:
                    max_val = max(max_val, target[1])
                    Queue.append([left, 1])
                else:
                    Queue.append([left, target[1] + 1])

                if target[0].val + 1 != right.val:
                    max_val = max(max_val, target[1])
                    Queue.append([right, 1])
                else:
                    Queue.append([right, target[1]+1])

        return max_val
