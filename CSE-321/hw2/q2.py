"""
2.Provide pseudo code for the following operations on a given binary search tree (BST) with nnodes. 
Derive a recurrence relation for each of your algorithms. 
Calculate the average-case Θ() complexity of the derived recurrence relations.

a)is_balanced(BST): This function checks whether the given binary search tree is balanced or not. 

b)height_of_tree(BST): This function returns the height of the given binary search tree.


"""

class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def height_of_tree(node):
    if node is None:
        return 0
    else:
        lDepth = height_of_tree(node.left)
        rDepth = height_of_tree(node.right)

        # the larger one is the correct
        if lDepth > rDepth:
            return lDepth + 1
        else:
            return rDepth + 1


def is_balanced(node):
    if node is None: 
        return True
 
    left_hight= height_of_tree(node.left)
    right_hight= height_of_tree(node.right)
 
    if (abs(left_hight - right_hight) <= 1) and is_balanced(node.left) and is_balanced(node.right):  # check subtrees are balanced recursively
        return True
 
    return False

#tests
root = Node(3)
root.right = Node(0)
root.left = Node(7)
root.left.right = Node(5)
root.left.left = Node(1)

print("Height:", height_of_tree(root))
print("Is balanced: ", is_balanced(root))

