// CSCN215 - Count.h - Jeremiah Carter

#pragma once

#include "SelfOrderedListADT.h"
#include "llist.h"
#include <string>

template <typename E>

class Transpose : public SelfOrderedListADT<E> {
private:

	int compares; // number of comparisions

	LList<E> list; // the list itself

public:
	//Default constructor/destructor
	Transpose() { compares = 0; }

	~Transpose() {}

	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	bool find(const E& it)
	{
		list.moveToStart();

		while (list.currPos() < list.length())
		{
			int pos = list.currPos();
			compares++;

			if (list.getValue() == it)
			{
				list.incAccess();

				reorder(pos);

				return true;
			}

			list.next();

		}

		add(it);
		//reorder();


		return false;
	}

	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.
	void add(const E& it)  //Add new 'it' to the list
	{
		list.append(it);
	}


	int getCompares() const   //Returns the number of accumulated compares
	{
		return compares;
	}


	int size() const      //Returns the size of the list
	{
		return list.length();
	}

	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	void printlist()
	{
		list.moveToStart();

		cout << "Number of Comparisions: " << getCompares() << endl;

		cout << "The final list... " << endl;
		while (list.currPos() != list.length())
		{
			cout << list.getValue() << "-" << list.getLinkAccesses() << "  ";
			list.next();
		}

		cout << "List Size: " << size() << endl;

		cout << endl << endl;
	}

	void printlist(int n)
	{
		list.moveToStart();

		cout << "Number of Comparisions: " << getCompares() << endl;

		cout << "The final list... " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << list.getValue() << "-" << list.getLinkAccesses() << "  ";
			list.next();
		}

		cout << "List Size: " << size() << endl;

		cout << endl << endl;
	}

	void reorder(int pos)
	{
		if (pos != 0) {
			// grap current values
			E temp = list.getValue();
			int tempAccesses = list.getLinkAccesses();

			// go to prev element
			list.prev();

			// get the "front" values
			E temp2 = list.getValue();
			int tempAccesses2 = list.getLinkAccesses();

			// --- swap ---
			list.setValue(temp);
			list.setLinkAccesses(tempAccesses);

			list.next();

			list.setValue(temp2);
			list.setLinkAccesses(tempAccesses2);
		}

	}


};

