/////////////////////////////////////////////////////////////////
// Generalised Data Structure Library
/////////////////////////////////////////////////////////////////

/*
----------------------------------------------------------------------------------------
Type                 Name of class for node            Name of class for Functionality
----------------------------------------------------------------------------------------
Singly Linear        SinglyLLLnode                     SinglyLLL
Singly Circular      SinglyCLLnode                     SinglyCLL
Doubly Linear        DoublyLLLnode                     DoublyLLL
Doubly Circular      DoublyCLL node                    DoublyCLL
Stack                Stacknode                         Stack
Queue                Queuenode                         Queue
----------------------------------------------------------------------------------------
*/

/////////////////////////////////////////////////////////////////
//
//  Required Header files
//
/////////////////////////////////////////////////////////////////
#include<iostream>

using namespace std;

/////////////////////////////////////////////////////////////////
// Singly Linear Linked list using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode <T> * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyLLL
{
    private :     
        SinglyLLLnode <T> * first;
        int iCount;

    public :
        SinglyLLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();         
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
        

};

template <class T>
SinglyLLL <T> ::SinglyLLL()
{
        cout<<"Object of SinglyLLL gets created\n";
        this->first = NULL;
        this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertFirst
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T> ::InsertFirst(T no)
{
        SinglyLLLnode <T> * newn = NULL;

        newn = new SinglyLLLnode<T>(no);

        if(first == NULL)
        {
            first = newn;
        }
        else
        {
            newn -> next = this->first;
            this->first = newn;
        }
        this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertLast
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T> ::InsertLast(T no)
{
        SinglyLLLnode <T> * newn = NULL;
        SinglyLLLnode <T> * temp = NULL;

        newn = new SinglyLLLnode<T>(no);

        if(this->iCount == 0)   
        {
            this->first = newn;
        }
        else
        {
            temp = this->first;

            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newn;
        }
        this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteFirst
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T>  ::DeleteFirst()
{
        SinglyLLLnode <T> * temp = NULL;

        if(this->first == NULL)
        {
            return;
        }
        else if(this->first -> next == NULL)    
        {
            delete this->first;
            this->first = NULL;
        }
        else
        {
            temp = this->first;

            this->first = this->first -> next;
            delete temp;
        }
        this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteLast
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T> ::DeleteLast()
{
        SinglyLLLnode <T> * temp = NULL;

        if(this->first == NULL)
        {
            return;
        }
        else if(this->first -> next == NULL)
        {
            delete this->first;
            this->first = NULL;
        }
        else
        {
            temp = this->first;

            while(temp -> next -> next != NULL)
            {
                temp = temp -> next;
            }

            delete temp -> next;
            temp -> next = NULL;
        }

        this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to display data of all nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T> ::Display()       
{
        SinglyLLLnode <T> * temp = NULL;
        int iCnt = 0;

        temp = this->first;

        for(iCnt = 1; iCnt <= this->iCount; iCnt++)    
        {
            cout<<"| "<<temp->data<<"  | -> ";
            temp = temp -> next;
        }
        cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to count no of nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL <T> ::Count()
{
        return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertAtPos
//  Input :           Data of node,Position to insert
//  Output :          Nothing  
//  Description :     Used to insert node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T> ::InsertAtPos(T no, int pos)
{
        int iCnt = 0;
        SinglyLLLnode <T> * temp = NULL;
        SinglyLLLnode <T> * newn = NULL;

        if(pos < 1 || pos > this->iCount+1)
        {
            cout<<"Invalid position";
            return;
        }

        if(pos == 1)
        {
            this->InsertFirst(no);
        }
        else if(pos == this->iCount+1)
        {
            this->InsertLast(no);
        }
        else
        {
            newn = new SinglyLLLnode<T>(no);

            temp = this->first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp -> next;
            }
            newn -> next = temp -> next;
            temp -> next = newn;

        this->iCount++;
        } 
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteAtPos
//  Input :           Position to delete
//  Output :          Nothing  
//  Description :     Used to delete node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T> ::DeleteAtPos(int pos)
{
        int iCnt = 0;
        SinglyLLLnode <T> * temp = NULL;
        SinglyLLLnode <T> * target = NULL;

        if(pos < 1 || pos > this->iCount)
        {
            cout<<"Invalid position";
            return;
        }

        if(pos == 1)
        {
            this->DeleteFirst();
        }
        else if(pos == this->iCount)
        {
            this->DeleteLast();
        }
        else
        {
            temp = this->first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp -> next;
            }

            target = temp -> next;
            temp -> next = target -> next;
            delete target;

            this->iCount--;
        }
}


/////////////////////////////////////////////////////////////////
// Doubly Linear Linked list using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode * next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode <T> * first;
        int iCount;

    public:    
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

template <class T>
DoublyLLL <T> ::DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertFirst
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL <T> ::InsertFirst(T no)
{
    DoublyLLLnode <T>* newn = NULL;

    newn = new DoublyLLLnode <T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertLast
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL <T> ::InsertLast(T no)
{
    DoublyLLLnode <T> * newn = NULL;
    DoublyLLLnode <T> * temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertAtPos
//  Input :           Data of node,Position to insert
//  Output :          Nothing  
//  Description :     Used to insert node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL <T> ::InsertAtPos(T no,int pos)
{
    DoublyLLLnode <T> * temp = NULL;
    DoublyLLLnode <T> * newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteFirst
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL <T> ::DeleteFirst()
{
    if(this->first == NULL)             // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)  // LL contains one node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                // LL contains more tham one node
    {
        this->first = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteLast
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL <T> ::DeleteLast()
{
    DoublyLLLnode <T> * temp = NULL;

    if(this->first == NULL)             // LL is empty
    {
        return;
    }
    else if(this->first->next == NULL)  // LL contains one node
    {
        delete this->first;
        this->first = NULL;
    }
    else                                // LL contains more tham one node
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteAtPos
//  Input :           Position to delete
//  Output :          Nothing  
//  Description :     Used to delete node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL <T> ::DeleteAtPos(int pos)
{
    DoublyLLLnode <T> *  temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to display data of all nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL <T> ::Display()
{
    DoublyLLLnode <T> * temp = NULL;

    temp = this->first;

    cout<<"\nNULL <=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |  <=> ";
        temp = temp->next;
    }
    cout<<"NULL\n";

}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to count no of nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL <T> ::Count()
{
    return this->iCount;
}


///////////////////////////////////////////////////////////////////
// Singly Circular Linked list using Generic Approach
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode <T> * next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class SinglyCLL
{
    private :
        SinglyCLLnode <T> * first;
        SinglyCLLnode <T> * last;
        int iCount;

    public :
        SinglyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void DeleteLast();
        void DeleteFirst();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
        
};

template <class T>
SinglyCLL <T> ::SinglyCLL()
{
    cout<<"Object of SinglyCLL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertFirst
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL <T> ::InsertFirst(T no)
{
    SinglyCLLnode <T> * newn = NULL;

    newn = new SinglyCLLnode <T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first = newn;
    }

    this->last -> next = this->first;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertLast
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL <T> ::InsertLast(T no)
{
    SinglyCLLnode <T> * newn = NULL;

    newn = new SinglyCLLnode <T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
    }
    else
    {  
        this->last -> next = newn;
        this->last = newn;
    }

    this->last -> next = this->first;
    
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteLast
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL <T> ::DeleteLast()
{
    SinglyCLLnode <T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->last;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        
        while(temp -> next != last)
        {
            temp = temp -> next;
        }
        delete last;
        last = temp;
        this->last -> next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteFirst
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL <T> ::DeleteFirst()
{
    SinglyCLLnode <T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first -> next;
        delete temp;
        this->last -> next = this->first;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to display data of all nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL <T> ::Display()
{
    SinglyCLLnode <T> * temp = NULL;

    temp = this->first;
    for(int iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to count no of nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL <T> ::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertAtPos
//  Input :           Data of node,Position to insert
//  Output :          Nothing  
//  Description :     Used to insert node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL <T> ::InsertAtPos(T no, int pos)
{
    SinglyCLLnode <T> * newn = NULL;
    SinglyCLLnode <T> * temp = NULL;
    
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode <T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next;
        temp -> next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteAtPos
//  Input :           Position to delete
//  Output :          Nothing  
//  Description :     Used to delete node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL <T> ::DeleteAtPos(int pos)
{
    SinglyCLLnode <T> * temp = NULL;
    SinglyCLLnode <T> * target = NULL;
    
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }
        
        target = temp -> next;
        temp -> next = target -> next;
        delete target;

        iCount--;
    }
}


///////////////////////////////////////////////////////////////////
// Doubly Circular Linked list using Generic Approach
///////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode <T> * next;
        DoublyCLLnode <T> * prev;

    DoublyCLLnode(T no)
    {
        this->data = no;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCLL
{
    private :
        DoublyCLLnode <T> * first;
        DoublyCLLnode <T> * last;
        int iCount;

    public :
        DoublyCLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
       

};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertFirst
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode <T> * newn = NULL;

    newn = new DoublyCLLnode <T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn -> next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertLast
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode <T> * newn = NULL;

    newn = new DoublyCLLnode <T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn -> prev = last;
        this->last = newn;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   InsertAtPos
//  Input :           Data of node,Position to insert
//  Output :          Nothing  
//  Description :     Used to insert node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode <T> * newn = NULL;
    DoublyCLLnode <T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyCLLnode <T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteFirst
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    DoublyCLLnode <T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteLast
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at last position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    DoublyCLLnode <T> * temp = NULL;
    
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->last;
        this->last = this->last->prev;
        delete temp;
    }
    this->last->next = this->first;
    this->first->prev = this->last;

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   DeleteAtPos
//  Input :           Position to delete
//  Output :          Nothing  
//  Description :     Used to delete node at given position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    DoublyCLLnode <T> * temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp -> next;
        }

        temp -> next = temp -> next -> next;
        delete temp->next->prev;
        temp -> next -> prev = temp;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to display data of all nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode <T> * temp = NULL;

    temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | <=>";
        temp = temp->next;

    }while(temp != this->last->next);
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to count no of nodes
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}


/////////////////////////////////////////////////////////////////
// Stack using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode <T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Stack
{
    private:
        Stacknode <T> * first;
        int iCount;
        
    public:
        Stack();
        void push(T);     
        T pop();          
        T peep();
        void Display();
        int Count();
};

template <class T>
Stack <T>::Stack()
{
    cout<<"Stack gets created successfully...\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   push
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack <T>::push(T no)
{
    Stacknode <T> * newn = NULL;

    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   pop
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack <T> ::pop()
{
    T Value = 0;
    Stacknode <T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    
    delete temp;

    this->iCount--;

    return Value;

}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   peep
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to get the data from top of stack
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack <T> ::peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to display data 
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack <T> :: Display()
{
    Stacknode <T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to count no of elements
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack <T> ::Count()
{
    return this->iCount;
}


/////////////////////////////////////////////////////////////////
// Queue using Generic Approach
/////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode <T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode <T> * first;
        Queuenode <T> * last;
        int iCount;
        
    public:
        Queue();
        void enqueue(T);     
        T dequeue();         
        void Display();
        int Count();
};

template <class T>
Queue <T>::Queue()
{
    cout<<"Queue gets created successfully...\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   enqueue
//  Input :           Data of node
//  Output :          Nothing  
//  Description :     Used to insert node at last of queue
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Queue <T>::enqueue(T no)
{
    Queuenode <T> * newn = NULL;

    newn = new Queuenode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else 
    {   
        this->last->next = newn;
        this->last = this->last->next;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   dequeue
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to delete node at first position
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Queue <T> ::dequeue()
{
    T Value = 0;
    Queuenode <T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<" Queue is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    
    delete temp;

    this->iCount--;

    return Value;

}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Display
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to display data 
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Queue <T> :: Display()
{
    Queuenode <T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | - ";
        temp = temp->next;
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name :   Count
//  Input :           Nothing
//  Output :          Nothing  
//  Description :     Used to count no of elements
//  Author :          Mayuri Shankar Panchal
//  Date :            06/01/2026
//
////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Queue <T> ::Count()
{
    return this->iCount;
}

////////////////////////////////-End of Library-/////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////
//
//  Entry point function for the application
//
/////////////////////////////////////////////////////////////////////////////////////
int main()
{
    SinglyLLL <int> *obj = new SinglyLLL<int>();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();
    iRet = obj->Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();
    iRet = obj->Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj->DeleteFirst();

    obj->Display();
    iRet = obj->Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj->DeleteLast();

    obj->Display();
    iRet = obj->Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj->InsertAtPos(150,3);

    obj->Display();
    iRet = obj->Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    obj->DeleteAtPos(3);

    obj->Display();
    iRet = obj->Count();
    cout<<"\nNumber of nodes are : "<<iRet<<"\n";

    delete obj;

    cout<<"-----------------------------------------------------------------------\n";
    //////////////////////////////////////////////////////////////////////////////

    DoublyLLL <char> * dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',3);

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(3);

    dobj->Display();
    cout<<"Number of nodes are :"<<dobj->Count()<<"\n";

    delete dobj;

    cout<<"-----------------------------------------------------------------------\n";
    //////////////////////////////////////////////////////////////////////////////

    SinglyCLL <int> *cobj = new SinglyCLL<int>();
    int Ret = 0;

    cobj->InsertFirst(51);
    cobj->InsertFirst(21);
    cobj->InsertFirst(11);

    cobj->Display();
    Ret = cobj->Count();
    cout<<"\nNumber of nodes are : "<<Ret<<"\n";

    cobj->InsertLast(101);
    cobj->InsertLast(111);
    cobj->InsertLast(121);

    cobj->Display();
    Ret = cobj->Count();
    cout<<"\nNumber of nodes are : "<<Ret<<"\n";

    cobj->DeleteFirst();

    cobj->Display();
    Ret = cobj->Count();
    cout<<"\nNumber of nodes are : "<<Ret<<"\n";

    cobj->DeleteLast();

    cobj->Display();
    Ret = cobj->Count();
    cout<<"\nNumber of nodes are : "<<Ret<<"\n";

    cobj->InsertAtPos(150,3);

    cobj->Display();
    Ret = cobj->Count();
    cout<<"\nNumber of nodes are : "<<Ret<<"\n";

    cobj->DeleteAtPos(3);

    cobj->Display();
    Ret = cobj->Count();
    cout<<"\nNumber of nodes are : "<<Ret<<"\n";

    delete cobj;

    cout<<"-----------------------------------------------------------------------\n";
    //////////////////////////////////////////////////////////////////////////////

    DoublyCLL<double> *dcobj = new DoublyCLL<double>();
    int dRet = 0;

    dcobj->InsertFirst(51.73468);
    dcobj->InsertFirst(21.623);
    dcobj->InsertFirst(11.276);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->InsertLast(101.12898);
    dcobj->InsertLast(111.7363);
    dcobj->InsertLast(121.278);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->DeleteFirst();

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->DeleteLast();

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->InsertAtPos(150.82738,3);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    dcobj->DeleteAtPos(3);

    dcobj->Display();
    dRet = dcobj->Count();
    cout<<"\nNumber of nodes are : "<<dRet<<"\n";

    delete dcobj;

    cout<<"-----------------------------------------------------------------------\n";
    //////////////////////////////////////////////////////////////////////////////

    Stack <char> * sobj = new Stack<char>();

    sobj->push('A');
    sobj->push('B');
    sobj->push('C');
    sobj->push('D');
    sobj->Display();
    cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Return value of peep is :"<<sobj->peep()<<"\n";
    sobj->Display();
    cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";
    sobj->Display();
    cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

    sobj->push('M');
    sobj->Display();
    cout<<"Number of elements in Stack are :"<<sobj->Count()<<"\n";

    delete sobj;

    cout<<"-----------------------------------------------------------------------\n";
    //////////////////////////////////////////////////////////////////////////////

    Queue <double> * qobj = new Queue<double>();

    qobj->enqueue(11.2323);
    qobj->enqueue(34.2323);
    qobj->enqueue(94.2324);
    qobj->enqueue(65.2324);
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    qobj->enqueue(234.3434);
    qobj->Display();
    cout<<"Number of elements in Queue are :"<<qobj->Count()<<"\n";

    delete qobj;

    return 0;
} // End of main