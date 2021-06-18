/** ADT bag: Link-based implementation.*/
#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>




#include "LinkedBag.h"

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : itemCount(0), headPtr(nullptr) {}

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType> &aBag) {
    itemCount = aBag.itemCount;
    Node<ItemType>* origChainPtr = aBag.headPtr;

    if (origChainPtr == nullptr)
        headPtr = nullptr;
    else
    {
        //copy first node
        headPtr = new Node<ItemType>();
        headPtr->setItem(origChainPtr->getItem());

        //copy remaining nodes
        Node<ItemType>* newChainPtr = headPtr;
        origChainPtr = origChainPtr->getNext();

        while(origChainPtr != nullptr)
        {
            //get next item from original chain
            ItemType nextItem = origChainPtr->getItem();

            origChainPtr = origChainPtr->getNext(); //advance original chain pointer

            //create a new node containing the next item
            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            //Link new node to end of new chain
            newChainPtr->setNext(newNodePtr);

            //Advance pointer to new last node
            newChainPtr = newChainPtr->getNext();
        }

        newChainPtr->setNext(nullptr);
    }
}

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag() {
    clear();
}

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const {
    return this->itemCount;
}

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const {
    return (this->itemCount == 0);
}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType &anEntry) {
    Node<ItemType>* nextNodePtr = new Node<ItemType>(anEntry, this->headPtr);

    this->headPtr = nextNodePtr;
    itemCount++;

    return true;
}

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType &anEntry) {
    Node<ItemType>* entryNodePtr = getPointerTo(anEntry, headPtr);
    bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);

    if (canRemoveItem)
    {
        //copy data from first node to located node
        entryNodePtr->setItem(headPtr->getItem());

        //Delete first node
        Node<ItemType>* nodeToDeletePtr = headPtr;
        headPtr = headPtr->getNext();

        //return node to the system
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;

        itemCount--;
    }

    return canRemoveItem;
}

template<class ItemType>
void LinkedBag<ItemType>::clear() {

    Node<ItemType>* nodeToDeletePtr = this->headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }

    itemCount = 0;
}

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType &anEntry) const {
    return getPointerTo(anEntry, this->headPtr) != nullptr;
}

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    return countFrequency(anEntry, 0, this->headPtr);
}

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const {
    std::vector<ItemType> bagContents = std::vector<ItemType>();
    fillVector(&bagContents, this->headPtr);

    return bagContents;
}

template<class ItemType>
void LinkedBag<ItemType>::fillVector(std::vector<ItemType> *bagContents, Node<ItemType> *curPtr) const {
    if (curPtr != nullptr)
    {
        bagContents->push_back(curPtr->getItem());
        fillVector(bagContents, curPtr->getNext());
    }
}

template<class ItemType>
int LinkedBag<ItemType>::countFrequency(const ItemType &anEntry, int counter, Node<ItemType> *curPtr) const {
    int frequency = 0;
    if ((curPtr != nullptr) && (counter < itemCount)) {
        if (anEntry == curPtr->getItem()) {
            frequency = 1 + countFrequency(anEntry, counter + 1, curPtr->getNext());
        }
        else {
            frequency = countFrequency(anEntry, counter + 1, curPtr->getNext());
        }
    }

    return frequency;

}

template<class ItemType>
Node<ItemType> *LinkedBag<ItemType>::getPointerTo(const ItemType &target, Node<ItemType> *curPtr) const {
    Node<ItemType>* result = nullptr;
    if (curPtr != nullptr)
    {
        if (target == curPtr->getItem())
            result = curPtr;
        else
            result = getPointerTo(target, curPtr->getNext());
    }

    return result;
}
