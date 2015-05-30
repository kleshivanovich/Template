
#pragma once

template<class T>
Element<T>::Element() {
  pp = T();
  next = 0;
}

template<class T>
Element<T>::Element(T pp, Element *next) {
  this->pp = pp;
  this->next = next;
}

template<class T>
Element<T>::~Element() {}

template<class T>
Element<T> * Element<T>::get_next() const {
  return next;
}

template<class T>
void Element<T>::set_next(Element* next) {
  this->next = next;
}

template<class T>
T& Element<T>::get_p() {
  return pp;
}


template<class T>
List<T>::List() {
  first = new Element<T>;
  num = 0;
}

template<class T>
List<T>::List(Element<T>* first) {
  this->first = first;
  num = 0;
}

template<class T>
List<T>::~List() {
  Element<T>* cur;

  while (first) {
    cur = first->get_next();
    delete first;
    first = cur;
  }
}

template<class T>
int List<T>::get_num() const {
  return num;
}

template<class T>
Element<T>* List<T>:: get_first() const {
  return first;
}

template<class T>
void List<T>::add(const T& pp) {
  Element<T>* cur = first;
  while (cur->get_next())
    cur = cur->get_next();

  cur->set_next(new Element<T>(pp, 0));
  ++num;
}

template<class T>
void List<T>::del(const T& el) {
  Element<T> *buf;
  Element<T>* cur = first;

  while (!(cur->get_next()->get_p() == el)) {
    cur = cur->get_next();
  }
  buf = cur->get_next();
  cur->set_next(cur->get_next()->get_next());

  --num;

  delete buf;
}

template<class T>
bool List<T>::has(const T& el) const {
  Element<T>* cur = first;

  while ((cur) && (!(cur->get_p() == el))) {
    cur = cur->get_next();
  }
  if (cur) {
    if (cur->get_p() == el)
      return true;
  }

  return false;
}

template<class T>
T& List<T>::find(const T& el) const {
  Element<T>* cur = first;

  while ((cur) && (!(cur->get_p() == el)))
    cur = cur->get_next();

  return cur->get_p();
}

template<class T>
T& List<T>::find_i(int i) const {
  Element<House>* cur = first;

  for (int j = 0; j < i; ++j)
    cur = cur->get_next();

  return cur->get_p();
}

template<class T>
bool List<T>::operator ==(const List<T>& list) const {
  Element<T>* cur = first;
  Element<T>* cur2 = list.first;

  while (cur) {
    if (!(cur->get_p() == cur2->get_p()))
      return false;

    cur = cur->get_next();
    cur2 = cur2->get_next();
  }

  return true;
}

template<class T>
const List<T>& List<T>::operator =(const List<T>& list) {
  if (this != &list) {
    Element<T>* cur;

    while (first) {
      cur = first->get_next();
      delete first;
      first = cur;
    }
    first = new Element<T>();

    cur = list.first->get_next();
    while (cur) {
      add(cur->get_p());
      cur = cur->get_next();
    }
  }

  return *this;
}
