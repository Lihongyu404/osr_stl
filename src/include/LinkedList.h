#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

class _BaseNode
{
public:
    _BaseNode *preNode;
    _BaseNode *nextNode;
};

template<typename T>
class _ListNode:public _BaseNode
{
public:
    _ListNode(){}
    _ListNode(const T& tempT)
    {
        value = tempT;
    }
    T value;
};

template<typename T>
struct _Iterator
{
    typedef _Iterator<T>     SelfType;
    typedef _ListNode<T>     ListNode;
public:
    ListNode*   pListNode;
public:
    _Iterator(){}
    _Iterator(const _BaseNode *pbNode):pListNode(static_cast<ListNode *>(const_cast<_BaseNode *>(pbNode))){}
    _Iterator(const SelfType *_Iterator):pListNode(_Iterator->pListNode){}
    T&  operator*()
    {
        return  pListNode->value;
    }
    T*  operator->()
    {
        return  &(pListNode->value);
    }
    SelfType operator++()
    {
        pListNode = static_cast<ListNode *>(pListNode->nextNode);
        return *this;
    }
    SelfType operator++(int)
    {
        SelfType temp(pListNode);
        pListNode = static_cast<ListNode *>(pListNode->nextNode);
        return temp;
    }

    SelfType operator--()
    {
        pListNode = static_cast<ListNode *>(pListNode->preNode);
        return this;
    }
    SelfType operator--(int)
    {
        SelfType temp(pListNode);
        pListNode = static_cast<ListNode *>(pListNode->preNode);
        return temp;
    }
    bool     operator!=(const SelfType & cmpListNode)
    {
        return this->pListNode != cmpListNode.pListNode;
    }
};

template<typename T>
class LinkedList
{
public:
    typedef _Iterator<T>    Iterator;
    typedef _ListNode<T>    ListNode;
    typedef LinkedList<T>   SelfType;
public:
    LinkedList()
    {
        tailNode.nextNode = & tailNode;
        tailNode.preNode  = & tailNode;
		listSize		  = 0;
    }
    Iterator End(){return Iterator(&tailNode);}
    Iterator Begin(){return Iterator(tailNode.nextNode);}
    int PushBack(const T& stnode)
    {
        ListNode* ptempNode = new ListNode(stnode);
        ListNode* ptailNode = static_cast<ListNode *>(tailNode.preNode);
        ptempNode->nextNode           = ptailNode->nextNode;
        ptailNode->nextNode->preNode   = ptempNode;
        ptailNode->nextNode           = ptempNode;
        ptempNode->preNode            = ptailNode;
		listSize++;
        return 0;
    }
    void Erase(const Iterator &del_Iterator)
    {
        if(End()!= Begin())
        {
            ListNode* delNode = static_cast<ListNode *>(del_Iterator.pListNode);
            ListNode* preDelNode = static_cast<ListNode*>(delNode->preNode);
            preDelNode->nextNode = delNode->nextNode;
            delNode->nextNode->preNode = preDelNode;
            delete delNode;
			listSize--;
        }
    }
    void Clear()
    {
        while(End()!= Begin())
        {
            Iterator tmpInterator = Begin();
            Erase(tmpInterator);
        }
    }
	unsigned int Size()
	{
		return listSize;
	}
private:
    LinkedList(const SelfType&){}
    SelfType& operator=(const SelfType&){}
private:
    ListNode 	 tailNode;
	unsigned int listSize;
};

#endif // LINKEDLIST_H_INCLUDED
