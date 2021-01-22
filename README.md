# Binary-Tree-Display-Library
Using the display_tree.cpp file, any binary tree (BST/AVL) can be displayed

## How to use:
1. Store your tree declaration/definition file as .cpp/.h without main function.
2. Make sure, there is a getRoot() function if "root" is private or protected. Else, there is no need for getRoot().
3. Include the .cpp/.h file which you created in the display_tree.cpp file.
	ex: #include "avl.cpp" or #include "bst.cpp"
4. To display, include both the tree file as well as the display_tree file in a separate file.
	ex: #include "avl.cpp"
	    #include "display_tree.cpp"
5. The syntax for calling the display function after creating the tree(say b) is:
	- display_tree(b.root); //if root is public
	- display_tree(b.getRoot()); //if root is private or protected

### Note:
1. When there are too many levels, the alignment may change due to the window size of the cmd prompt or IDE. 
   In that case, use the following statement in main function, to output the tree to a text file.
	 - freopen("output.txt", "w", stdout);
2. This display_tree function works only for integers as of now.
3. C++17 or above is needed.
