/****************************************************************************************//*

Uses: CRSet, DFA, State, StateEqRel, SymRel
Description: Member function min_Hopcroft implements Hopcroft's n log n minimization algo-
	rithm, as presented in [Wat93b, Algorithm 4.8]

Implementation: The member function uses some encoding tricks to effectively implement the
	abstract algorithm. The combination of the out-transitions of all of the States is stored in a
	CRSet C. Set L from the abstract algorithm is implemented as a mapping from States to int 
	(an array of int is used). Array L should be interpreted as follows: if State *q* a representative,
	then the following pairs still require processing (are still in abstract set L):
	          ([q],C_0),([q],C_1),...,([q],C_(L(q)_1))
	The remaining pairs do not require processing:
			  ([q],C_(L(q))),...,([q],C_(|C|_1))
	This implementation facilities quick scanning of L for the next valid State-CharRange pair.

*//****************************************************************************************/
/*(c) Copyright 1994 by Bruce W. Watson */
// $Revision 1.1 $
// $Date: 1994/05/02 15:59:06 $

#include "CRSet.h"
#include "State.h"
#include "StateSet.h"
#include "StateEqRel.h"
#include "DFA.h"

// Implemeta Algorithm 4.8 (Hopcroft O(n log n) algorithm)
#define FINDEBUG
//#define FIX
DFA& DFA::min_Hopcroft()
{
	assert(class_invariant());

	// This algorithm requires that the DFA not have any final unreachable
	// State.
	//assert(Usefulf());

	State q;

	// Keep track of the combination fo all the out labels of State's.
	CRSet C;
	for (q = 0; q < Q.size(); q++)
	{
		C.combine(T.out_labels(q));
	}

#ifdef FINDEBUG
	std::cout << "C:" << C << std::endl;
#endif // FINDEBUG


	// Encode set L as a mapping from State to [0,|C|] where:
	//            if q is a representative of a class in the partition P, then
	//            L(the abstract list) contains
	//                     ([q],C_0),([q],C_1),...,([q],C_(L(q)_1))
	//            but not
	//                     ([q],C_(L(q))),...,([q],C_(|C|_1))
	int *const L(new int[Q.size()]);
	for (q = 0; q < Q.size(); q++)
	{
		L[q] = 0;
	}




	// Initialize P to be total equivalence relation.
	StateEqRel P(Q.size());

#ifdef FINDEBUG
	std::cout << "P=" << P << std::endl;
#endif // FINDEBUG


	// Now set P to be E_0.
	P.split(F);
#ifdef FINDEBUG
	std::cout << "P=" << P << std::endl;
#endif // FINDEBUG



	// Now, build the set of equivalentatives and initialize L.
	StateSet repr(P.representatives());

#ifdef FINDEBUG
	std::cout << "repr=" << repr << std::endl;
#endif // FINDEBUG

	//repr.intersection(F);
	//repr.intersection(F);

	if (F.size() <= (Q.size() - F.size()))
	{
		repr.intersection(F);
	}
	else
	{
		repr.remove(F);
	}

#ifdef FINDEBUG
	std::cout << "repr= " << repr << std::endl;
#endif // FINDEBUG

	// Do the final set up of L
	for (repr.iter_start(q); !repr.iter_end(q); repr.iter_next(q))
	{
		L[q] = C.size();
	}

#ifdef FINDEBUG
	int count = 0;
	for (q = count; count < Q.size(); count++)
	{
		std::cout << "L[" << count << "]=" << L[count] << ", ";
	}
	std::cout << std::endl << std::endl << std::endl;
	count = 0;
#endif // FINDEBUG

	

	// Use a break to get of this loop
	while (1)
	{
		// Find the first pair in L that still needs processing.
		for (q = 0; q < Q.size() && !L[q]; q++);

		// It may be that we're at the end of the processing.
		if (q == Q.size())
		{
			break;
		}
		else
		{
			// mark this element of L as processed.
			L[q]--;
			CharRange c = C.iterator(L[q]);

			// Iterate over al eq. classes, and try to split them.
			State p;
			repr = P.representatives();

#ifdef FINDEBUG
			std::cout << "iner repr= " << repr << std::endl << std::endl;
#endif // FINDEBUG
			
			for (repr.iter_start(p); !repr.iter_end(p); repr.iter_next(p))
			{
#ifdef FIX
				if (L[q] == C.size())
				{
					L[q]--;
				}
#endif // FIX



#ifdef FINDEBUG
				//std::cout << *this << std::endl;
				using namespace std;
				cout << "p=" << p << ", q=" << q << ", L[q]=" << L[q] ;
				cout << ",   C.iterator(L[q])=" << C.iterator(L[q]) << endl;
				for (count = 0; count < Q.size(); count++)
				{
					std::cout << "L[" << count << "]=" << L[count] << ", ";
				}
				cout << endl;
				cout << "repr=" << repr << endl << std::endl;
				cout << "P=" << P << std::endl << endl;
#endif // FINDEBUG


				// Now split [p] w.r.t (q,C_(L[q]))
				State r(split(p, q, c, P));  //abort with DFA 6 有初始不可达状态时
				// r is the representative of the new split of the 
				// eq. class that was represented by p.

#ifdef FINDEBUG
				//std::cout << "after split : P=" << P ;
				//std::cout << "after split : r=" << r << std::endl << std::endl;
#endif // FINDEBUG


				if (r != Invalid)
				{
					// p and r are the new representatives.
					// Now update L with the smallest of
					// [p] and [r]
#ifdef FINDEBUG
					//std::cout << "P.equiv_class(p).size()=" << P.equiv_class(p).size() << std::endl;
					//std::cout << "P.equiv_class(r).size()=" << P.equiv_class(r).size() << std::endl;
#endif // FINDEBUG

					if (P.equiv_class(p).size() <= P.equiv_class(r).size())
					{
						L[r] = L[p];
						L[p] = C.size();
					}
					else
					{
						L[r] = C.size();
					} // if
				}  // if

#ifdef FINDEBUG
				//std::cout << *this << std::endl;
				//int count = 0;
				cout << "p=" << p << ", q=" << q << ", L[q]=" << L[q] << ",  r =" << r << endl;
				//cout << ",   C.iterator(L[q])=" << C.iterator(L[q]) << ",  r ="  << r <<endl;
				for (count = 0; count < Q.size(); count++)
				{
					std::cout << "L[" << count << "]=" << L[count] << ", ";
				}
				cout << endl;
				cout << "repr=" << repr << endl;
				cout << "P=" << P << std::endl << endl;
				std::cout << "\n************************ A repetetion finnished ************************\n\n" << std::endl;
#endif // FINDEBUG


			} // for
		} // if
	} // while

	// L is no longer needed.
	delete L;

	// we can now use P to compress the DFA.
#ifdef FINDEBUG
	std::cout << "before compress:" << std::endl;
	std::cout << *this << std::endl;
	std::cout << "P=" << P << std::endl;
#endif // FINDEBUG
	compress(P);
#ifdef FINDEBUG
	std::cout << "after compress:" << std::endl;
	std::cout << *this << std::endl;
#endif // FINDEBUG
	assert(class_invariant());
	return (*this);
}