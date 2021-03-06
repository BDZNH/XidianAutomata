/*********************************************************************************
	Implementation class: TransPair
	Files: tr-pair.h
	Uses: CharRange, State
	Description: A TransPair is a transition, a structure consisting of a label (a CharRange) and a
	destination State. The two are contained in the TransFair structure.
	Implementation: A struet is defined, without member functions.
 *********************************************************************************/
//#pragma once


#ifndef AUTOMATA_TRANSPAIR_H
#define AUTOMATA_TRANSPAIR_H

#include "CharRange.h"
#include "State.h"

// Implement a single transition, for use in classes TransImpl, Trans(Trans.h
// and Trans.cpp) and class DTrans(Dtrans.h and Dtrans.cpp).
// V �� Q
struct TransPair {
	CharRange transition_label;
	State transition_destination;
};



#endif // !AUTOMATA_TRANSPAIR_H

