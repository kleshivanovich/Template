
#pragma once

template<class T>
class Element {
  T pp;
  Element* next;
 public:
  Element();
  Element(T, Element*);
  ~Element();

  Element* get_next() const;
  void set_next(Element* a);
  T& get_p();
};

template<class T>
class List {
 private:
  Element<T>* first;
  int num;
 public:
  List();
  explicit List(Element<T>*);
  ~List();

  void add(const T&);
  void del(const T&);
  bool has(const T&) const;
  T& find(const T&) const;
  T& find_i(int i) const;

  int get_num() const;
  Element<T>* get_first() const;

  const List<T>& operator =(const List<T>&);
  bool operator ==(const List<T>&) const;
};
