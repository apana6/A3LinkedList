1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
   Name exactly what each one frees, and name the two new calls back in the program responsible
   for putting them on the heap in the first place.
There are two separate delete calls because they each free different data values. Delete doomed->data 
frees the actual value stored in the node, so if an int is created by newint(10) this call will delete
the value within. The second call, delete doomed, frees the object Node that was created in addFront(). 
The calls that put them there in the first place was list->addFront(new int(10)) which creates the 
stored value and Node<T>* fresh = new Node<T>(value) which creates the node. 

2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?
T* means you have a pointer that points to some value, the destructor is necessary to clean up 
the value created with new. So for every new, you need one matching delete. If you forgot the 
destructor then the values created would pile up and leak memory which cannot be reused in the program. 

3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?
addFront() takes ownership of the pointer, this means it is allowed to and is responsible for deleting
it. search() only borrows the pointer so it does not store/delete the search pointer. When it finishes
the pointer still belongs to whoever passed it in and search() cannot delete it. 

4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?
I switched between LinkedList<T> and ArrayList<T> by commenting out one of the return statements 
in makeList() and then running the main. Because it uses List<T> it will run the same operation
you just need to change the implementation you want. 

5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.
I chose override because it tells the compiler that a method is intended to replace a virtual method
from the base class. So if you do not put const on search(), override would see that the signitures 
do not match and show a compile error. 