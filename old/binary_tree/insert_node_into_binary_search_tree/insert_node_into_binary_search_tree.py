import random
import sys

sys.path.append("..")

from binary_tree import BinaryTree


def insert_node_into_binary_search_tree(root, val):
    if root is None:
        return BinaryTree(val)
    else:
        if val > root.val:
            root.right = insert_node_into_binary_search_tree(root.right, val)
        elif val < root.val:
            root.left = insert_node_into_binary_search_tree(root.left, val)

    return root


def print_binary_tree(root, level=0, prefix="Root: "):
    if root is not None:
        print(" " * (level * 4) + prefix + str(root.val))
        if root.left or root.right:
            print_binary_tree(root.left, level + 1, "L--- ")
            print_binary_tree(root.right, level + 1, "R--- ")


def main():
    root = BinaryTree(10, None, None)
    print_binary_tree(root)

    for i in range(15):
        insert_node_into_binary_search_tree(root, random.randint(0, 20))

    print_binary_tree(root)


main()
