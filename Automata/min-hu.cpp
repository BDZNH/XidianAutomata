// $Revision 1.1 $
// $Date: 1994/05/02 15:59:06 $

#include "CRSet.h"
#include "State.h"
#include "StateSet.h"
#include "SymRel.h"
#include "DFA.h"

// Implement (a version of) Algorithm 4.7 of the minimization Taxonomy.

DFA& DFA::min_HopcroftUllman()
{
	return (*this);
}