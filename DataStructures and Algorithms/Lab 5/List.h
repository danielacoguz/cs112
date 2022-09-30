/*List.h
 * Student Name: John Cho
 * Student Name: Daniela Contreras ldc6
 * Date: 10/7/2021
 * Begun by: Joel C. Adams, for CS 112 at Calvin University.
 */

#ifndef LIST_H_
#define LIST_H_
#include <stdexcept>
using namespace std;

typedef double Item;

class List {
public:
	List();
	unsigned getSize()const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item& it);
	List(const List& original);
	List& operator=(const List& rhs);
	virtual ~List();

private:
	struct Node { //inner struct
		Node();
		Node(Item it, Node *next);
		~Node();

		Item myItem;
		Node *myNext;

	};
	unsigned mySize;
	Node * myFirst;
	Node * myLast;
	friend class ListTester;
};

#endif /* LIST_H_ */
