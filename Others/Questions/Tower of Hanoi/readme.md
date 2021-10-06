# Recursive way approach :- 

First, we put all the basic details and command lines for starting the recursive method in C:

In the next line, we have used a void, which is used as the function return type, and hanoifun, which works as a Hanoi function in C and C++. We have to

move disks from J to L using K, so we have written the function as "J, L, and K" in the below command.

void hanoifun(int n, char J, char L, char K)

In these functions, n==1 is a boolean expression that works to return true if n is 1 or false if n is anything apart from 1.After that, we have written 

functions to move a disk from J to L, then hanoifun(n-1, J, K, L); is used for moving disks from J to K using L.

At last, we used hanoifun(n-1, K, L, J); for moving disks from K to L using J. In these functions “n-1” represents that we are moving an n-1 number of disks from one tower to another.


if (n == 1)

    {
    
        printf("\n Move disk 1 from tower %c to tower %c", J, L);
        
        return;
        
    }
    
    hanoifun(n-1, J, K, L);
    
    printf("\n Move disk %d from tower %c to tower %c", n, J, L);
    
    hanoifun(n-1, K, L, J);
}



So it was the brief information on the recursive method for Tower of Hanoi in C, and we have given the complete explanation of interchanging the positions

of tower names in codes for having a correct output.



# Iterattive way approach :- 

First, we have to create the "n" integer that stands for the number of disks.

Now, create three stacks for auxiliary, destination, and source and create three variables "s" as A, B, and C.

After that, check if the number of disk mod 2 is zero and storing "d" in the temporary variable. Now update "d" as "a" then "a" as a temporary variable.

After updating the variable, create the variable for the number of moves, then update it as the "(n*n) -1."

Now,we have to transerve from "n" to one then provide the current value in a source stack.

After that, we have to transverse from 1 to a total number of moves then check that the current index mod 3 is one. Now, pop the top through the destination and source stack.

In case the popped top of a source stack is the same as "INT_MIN", then we have to push the popped top of the destination to the source stack.

In case the popped top of a destination stack is the same as "INT_MIN",then we have to push the popped top of the source to the destination stack.

In case the popped top of a source stack is more than the popped top of the destination stack, then we have to push the tops in the source stack, or else we can push both in the destination stack. After performing it, we have to print the traversal.

Now, check that the current index mod 3 is two, and we have to pop the top from the source, then the auxiliary stack.

In case the popped top of the source stack is the same as "INT_MIN", then we have to push the popped top of the auxiliary to the source stack.

In case the auxiliary stack's popped top is the same as "INT_MIN" then we have to push a popped top of the source to the auxiliary stack.

In case the popped top of a source stack is more than the popped top of the auxiliary stack, then we have to push the tops in the source stack, or else we can push both auxiliary stacks. After performing it, we have to print the traversal.

Now, check that the current index mod 3 is zero, and we have to pop the top from auxiliary, then the destination stack.

In case the popped top of the source stack is the same as "INT_MIN", then we have to push the popped top of the destination to the auxiliary stack.

In case the destination stack's popped top is the same as "INT_MIN", then we have to push a popped top of the auxiliary to the destination stack.

In case the popped top of the auxiliary stack is more than the popped top of the destination stack, then we have to push the tops in the auxiliary stack, or we can push both the destination stack. After performing it, we have to print the traversal.
