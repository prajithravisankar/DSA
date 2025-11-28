class BinaryTree:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def count_nodes(root):
    if root is None:
        return 0
    else:
        left_node_count = count_nodes(root.left)
        right_node_count = count_nodes(root.right)
        return 1 + left_node_count + right_node_count


def main():
    # Tree: 5 -> 4 -> 3 -> 2 -> 1
    # Tree:
    #        5
    #      /   \
    #     2     8
    #    / \   / \
    #   1   4 6   12
    #      /
    #     3
    root = BinaryTree(
        5,
        BinaryTree(2, BinaryTree(1), BinaryTree(4, BinaryTree(3))),
        BinaryTree(8, BinaryTree(6), BinaryTree(12)),
    )

    print(f"total nodes: {count_nodes(root)}")


main()
