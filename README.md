# 214-Assignment-2
Sorted Lists
Ethan Berroa
Rushit Sanghrajka
Assignment 2
README.pdf

SortedListPtr SLCreate (CompareFuncT cf, DestructFuncT df);
Analysis of Memory Usage: We assign 3 pointers: list, comparef, and destructf. Head is assigned to NULL. Additonally, we must factor in our two parameters: the function pointers cf and df. Together, they take up 4 bytes * 5, which is 20 bytes of data. As far as running time goes, we are simply performing 5 "basic computer steps" that take constant time. Thus, the function is O(5) = O(1)

void SLDestroy(SortedListPtr list);
Analysis of Memory Usage: In this function, we use two Node pointers: tmp and p. Using them both, we traverse through the SortedList, freeing up all it's Nodes and associated data. Also, our parameter, list, is a 4 byte SortedListPtr. Thus, we use no more the 4 bytes * 3, which is 12 bytes of data to accomplish this function. The running time of this function is dependent on the length of the SortedList, due to the while(p!=NULL) statement. Thus our running time is linearly dependent on our input, or O(n)

int SLInsert(SortedListPtr list, void *newObj)
Analysis of Memory Usage: Our parameters, list and newObj, take up 8 bytes of data since they are both pointers. Since this is our insert function, we have to create a Node object and associated pointers. The Node pointer takes up 4 bytes, while the struct itself takes up another 12 bytes with: data, refctr, and next. If we're adding the Node to the end of the list, next will point to NULL and the struct will only take 8 bytes. In total, we're managing between 24 to 20 bytes of data. With regards to running time, our main point of interest is the while loop: while(p!=NULL). We are going through the list, one by one, and comparing our newObj to the nodes already inserted. At worst, we add our new Object to the very end of our n long list. Thus, the running time is O(n)

int SLRemove(SortedListPtr list, void *NewObj);
Analysis of Memory Usage: First off, our two parameters, list and newObj, take up 8 bytes of data. We use two Node pointers, tmp and prev, to traverse the list while comparing each Node to the target to be deleted, that's another 8 bytes. We also utilize pointers such as: tmp->data, list->comparef, list->destructf, tmp->next, and prev->next. That's another 20 bytes. In total, we manipulate 36 bytes of data. When finding the Big O of this function, our main point of interest is again a while loop set to traverse the whole list at worst, while(tmp!=NULL). Thus, the running time is O(n) once again.

SortedListIteratorPtr SLCreateIterator (SortedListPtr list);
Analysis of Memory Usage: Our SortedListPtr parameter is a 4 byte pointer. We create a SortedListerIterator struct, and a pointer to it, "helper". We then initialize all the struct values using pointers in the list struct. After all is said and done, we use 32 bytes of data. Running time is O(1) because all we're doing in this function is the constant time steps of initializing some data.

