1. Why does concat only need to work between two lists of the same 
   representation? What would you have to do differently, or what would go
   wrong, if you tried to make it work between LinkedList and ArrayList?

   Concat only works between the same type of list because each representation 
will store its data differently. An array list uses array pointers, while a
Linked list uses nodes connected by links. If I tried to combine it different 
representations directly, I would not be able to access the other lists data directly.
My code uses dynamic_cast to check whether the two lists have the same representation. 

2. Walk through reverse() on your linked list: name the three pointers you 
   need alive at once, and explain why losing track of any one of them mid-loop
   corrupts the list.

   My linked list reserve method uses three pointers - previous, current, and next.
Current is the node that gets changed, and previous is the node that comes before it, and 
next saves the rest of the list before the link is changed. Losing one of these pointers means 
I could lose access to part of the list or connect the nodes wrong. 

3. addAnywhere and deleteAnywhere both need a bounds check. What's the valid 
   range for positions in each, and what does your implementation do if a caller
   passes a position outside it?

   The valid positions for addAnywhere are from 0 to size_ since a new item 
can be inserted one position past the current last item. deleteAnywhere is from 0 t0 
size_-1 since an item must already exist at the specific location. An invalid position results 
with a return and no change to the list. 

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?
   
   LinkedList::concat needs to walk to the end because the list does not keep a tail pointer.
The last node must be found before the other list can be connected to it. Id the list had a tail pointer,
concat could attach the second list in O(1) time, but the tail pointer would need to be updated 
whenever nodes were added, deleted, reversed or concatenated. 

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

   In my array list, the addAnywhere method takes the existing elements and shifts 
them from right to left starting at the end of the list. This creates an empty space
at the requested position. If I shifted from left to right, I could overwrite values before
moving them causing data loss. 

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.

   It changes direction in main.cpp on the line table->reverse(). Before this call is made, the players
appear in their original order and after the call the list is printed in the opposite order. This will 
show that the direction of the players changed. Without reverse(), the players would stay in the same spots
even after the reverse card is played. 