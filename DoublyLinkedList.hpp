#include <iostream>

#include "IDoublyLinkedList.hpp"
#include "Node.hpp"

template <class T>
class DLList : protected IDLList<T>
{
  public:
    virtual ~DLList() {
      clear();
    }

    virtual bool empty() const {
      return size() == 0;
    }

    virtual int size() const {
      return m_size;
    }

    virtual const T& getValue(int pos) {
      DLLNode<T>* current = mp_head;
      while(pos-- > 0) {
        if(!current) {
          throw std::invalid_argument("pos is not a valid index");
        }
        current = current->mp_next;
      }

      return current->m_value;
    }

    virtual void insert(int pos, const T& item) {
      DLLNode<T> *current = mp_head, *previous = nullptr;
      while (pos-- > 0) {
        if (!current)
          throw std::invalid_argument("pos is not a valid index");

        previous = current;
        current = current->mp_next;
      }

      DLLNode<T>* newNode = new DLLNode<T>();
      newNode->m_value = item;

      // Let's do the wiring
      newNode->mp_prev = previous;
      newNode->mp_next = current;

      if (newNode->mp_prev) {
        newNode->mp_prev->mp_next = newNode;
      } else {
        mp_head = newNode;
      }

      if (newNode->mp_next) {
        newNode->mp_next->mp_prev = newNode;
      } else {
        mp_tail = newNode;
      }
    }

    virtual void clear() {
      DLLNode<T> *current = mp_head;
      DLLNode<T> *next;
      while(current != nullptr) {
        next = current->mp_next;
        delete current;
        current = next;
      }

      mp_head = nullptr;
    }

    void print() {
      DLLNode<T> *pNode = mp_head;
      while(pNode != nullptr) {
        std::cout << pNode->getValue() << "\n";
        pNode = pNode->mp_next;
      }
    }

  private: 
    DLLNode<T> *mp_head{nullptr};
    DLLNode<T> *mp_tail{nullptr};
    int m_size = 0;
};
