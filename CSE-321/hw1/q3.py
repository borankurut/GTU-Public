""" 
    Provide pseudo code for the following operations on a given binary search tree (BST) with a height of n.
    Analyze the time complexity (in terms of Big-Oh notation) of your code for each of the following:

    a) Merging with another BST of height n. 
    b) Finding the kth smallest element in the BST.
    c) Balancing the BST. 
    d) Finding elements within a specified value range. 


a) Merging with another BST of height n:

    In-order traversal of both BSTs take O(n) time for each of them.
    Merging two sorted lists takes O(n) time.
    Building a balanced BST from the merged list takes O(n).
    Overall time complexity is O(n).

b) Finding the kth smallest element in the BST:

    In-order traversal to create a sorted list takes O(n) time in worst case.
    Getting the kth smallest element from the sorted list takes O(1) time.
    Overall time complexity is O(n).

c) Balancing the BST:

    The sorted list obtained from the in-order traversal is balanced in the merge.
    Building a balanced BST from the sorted list takes O(n) time.
    Overall time complexity is O(n).

d)Finding elements within a specified value range:

    In the worst case, the range search can traverse the height of the BST, which results in a time complexity of O(n).
    But, if the tree is balanced, the time complexity can be lower.
    Overall time complexity is O(n) in the worst case.

"""

class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def merge_bsts(root1, root2):
    # in-order traversal to get sorted lists from BSTs
    list1 = in_order_traversal(root1, [])
    list2 = in_order_traversal(root2, [])

    # merge two sorted lists
    merged_list = merge_sorted_lists(list1, list2)

    # build a balanced BST from the merged list
    return sorted_list_to_bst(merged_list)

def in_order_traversal(node, result):
    if node:
        in_order_traversal(node.left, result)
        result.append(node.key)
        in_order_traversal(node.right, result)
    return result

def merge_sorted_lists(list1, list2):
    merged_list = []
    i = 0
    j = 0

    # append preserving order
    while i < len(list1) and j < len(list2):
        if list1[i] < list2[j]:
            merged_list.append(list1[i])
            i += 1
        else:
            merged_list.append(list2[j])
            j += 1

    # copy the remaining
    while i < len(list1):
        merged_list.append(list1[i])
        i += 1

    while j < len(list2):
        merged_list.append(list2[j])
        j += 1

    return merged_list

def sorted_list_to_bst(sorted_list):
    if not sorted_list:
        return None

    mid = len(sorted_list) // 2 # integer division
    root = TreeNode(sorted_list[mid])

    root.left = sorted_list_to_bst(sorted_list[:mid]) # left part is untill mid
    root.right = sorted_list_to_bst(sorted_list[mid + 1:]) # right part is mid to end

    return root

def kth_smallest_element(root, k):
    result = []
    in_order_traversal_for_kth(root, k, result)
    if result:
        return result[0]
    else:
        return None

def in_order_traversal_for_kth(node, k, result):
    if node and len(result) < k:
        in_order_traversal_for_kth(node.left, k, result)
        result.append(node.key)
        in_order_traversal_for_kth(node.right, k, result)

def find_elements_in_range(root, low, high):
    result = []
    range_search(root, low, high, result)
    return result

def range_search(node, low, high, result):
    if node:
        if low <= node.key <= high:
            range_search(node.left, low, high, result)
            result.append(node.key)
            range_search(node.right, low, high, result)
        elif node.key < low:
            range_search(node.right, low, high, result)
        else:
            range_search(node.left, low, high, result)

def print_in_order(node):
    if node:
        print_in_order(node.left)
        print(node.key, end=' ')
        print_in_order(node.right)

def main():
    bst1 = TreeNode(5)
    bst1.left = TreeNode(3)
    bst1.right = TreeNode(8)

    bst2 = TreeNode(7)
    bst2.left = TreeNode(4)
    bst2.right = TreeNode(10)

    # merging BSTs
    # balancing is done during the merge 
    merged_bst = merge_bsts(bst1, bst2)
    print("Merged BST:")
    print_in_order(merged_bst)
    print()

    # finding the kth smallest element
    k = 3
    kth_smallest = kth_smallest_element(merged_bst, k)
    print(f"{k}th smallest element: {kth_smallest}\n")

    # finding elements within range
    low, high = 4, 8
    elements_in_range = find_elements_in_range(merged_bst, low, high)
    print(f"Elements in the range [{low}, {high}]: {elements_in_range}")

main()

