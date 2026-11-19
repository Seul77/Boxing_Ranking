#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>

template <class T> class List;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);

	T value;
	Link<T> *next;

	friend class List<T>;
};

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}


template <class T>
class List {
public:
	List();
	List(const List<T>&) ;
	~List();

    void addFirst(T);
	void add(T);
	int length() const;
	T get(int) const;
	bool contains(T) const;
	bool empty() const;
	void clear();
	T remove(int);

private:
	Link<T> *head;
	int size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
List<T>::List(const List<T> &source)  {
	Link<T> *p, *q;

	if (source.empty()) {
		size = 0;
		head = 0;
	} 
    else {
		p = source.head;
		head = new Link<T>(p->value);
		q = head;

		p = p->next;
		while(p != 0) {
			q->next = new Link<T>(p->value);
			p = p->next;
			q = q->next;
		}
		size = source.size;
	}
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
int List<T>::length() const {
	return size;
}

template <class T>
T List<T>::get(int index) const {
	int pos;
	Link<T> *p;

	if (index == 0) {
	    return head->value;
	}

	p = head;
	pos = 0;
	while (pos != index) {
		p = p->next;
		pos++;
	}

	return p->value;
}

template <class T>
bool List<T>::contains(T val) const {
	Link<T> *p;

	p = head;
	while (p != 0) {
		if (p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}


template <class T>
void List<T>::addFirst(T val)  {
	Link<T> *newLink;

	newLink = new Link<T>(val);
	newLink->next = head;
	head = newLink;
	size++;
}

template <class T>
void List<T>::add(T val)  {
	Link<T> *newLink, *p;

	newLink = new Link<T>(val);

	if (empty()) {
		addFirst(val);
		return;
	}

	p = head;
	while (p->next != 0) {
		p = p->next;
	}

	newLink->next = 0;
	p->next = newLink;
	size++;
}

template <class T>
T List<T>::remove(int index){
    Link<T> *p = head;
    T valEliminado;
    if (index == 0){
        head = head->next;
        valEliminado = p->value;
        delete p;
        size --;
        return valEliminado;
    }

    for (int i=0; i<index -1; i++){
        p=p->next;
    }
    Link<T> *q = p->next; 
    p->next = q->next;
    valEliminado = q->value;
    size--;
    delete q;

    return valEliminado;
}

template <class T>
void List<T>::clear() {
	Link<T> *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}

#endif