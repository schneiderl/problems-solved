import sys
    
def check_binary_search_tree_(root, MIN=None, MAX=None):
    if not root:
        return True
    if MIN is None or MAX is None:
        min_int = -sys.maxsize -1
        max_int = sys.maxsize
        return check_binary_search_tree_(root, min_int, max_int)
    else:
        if (root.data > MIN and root.data < MAX and check_binary_search_tree_(root.left, MIN, root.data) and check_binary_search_tree_(root.right, root.data, MAX)):
            return True
        else:
            return False