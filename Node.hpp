#pragma once

template <class T>
struct DLLNode
{
  DLLNode() = default;

  ~DLLNode() {
    //delete mp_next;
    //delete mp_prev;
  }

  DLLNode(T value, DLLNode *next, DLLNode *prev) 
    : m_value(value), mp_next(next), mp_prev(prev) { }

  void setValue(T value) { m_value = value; }
  int getValue() const { return m_value; }

  T m_value = T();
  DLLNode *mp_next = nullptr;
  DLLNode *mp_prev = nullptr;
};
