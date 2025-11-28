class BinaryTree:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def binary_search_count_height(root):
    if root is None:
        return 0
    else:
        return 1 + max(
            binary_search_count_height(root.left),
            binary_search_count_height(root.right),
        )


def main():
    root = BinaryTree(
        10,
        BinaryTree(
            5,
            BinaryTree(2, BinaryTree(1), BinaryTree(3)),
            BinaryTree(7, None, BinaryTree(8, BinaryTree(6))),
        ),
        BinaryTree(
            15,
            BinaryTree(12, None, BinaryTree(13)),
            BinaryTree(20, BinaryTree(18), BinaryTree(25)),
        ),
    )
    print(f"height of binary tree: {binary_search_count_height(root)}")


main()
