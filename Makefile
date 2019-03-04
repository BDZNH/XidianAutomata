#!/bin/bash
CCFLAG = -Wall -fexceptions -g -std=c++11 -lwiringPi -lpthread -DNDEBUG
CC = g++

objets = Automata.o BitVec.o CharRange.o Constrs.o CRSet.o Dconstrs.o Deriv.o DFA.o DSIS.o \
	DSISopt.o DSLBFA.o DSRBFA.o DSRE.o DSREopt.o DSRFA.o DSRFA2.o DTrans.o DTransRel.o \
	FA.o Iconstrs.o ISImpl.o LBFA.o RBFA.o RE.o RFA.o Sig-FA.o Sig-re.o Sig-RFA.o StateEqRel.o \
	StateRel.o StateSet.o SymRel.o Trans.o TransImpl.o TransRel.o Automata/AutomataTest.o \
	Automata/CRSetTest.o Automata/RFATest.o Automata/StateRelTest.o Automata/StateSetTest.o \
	Automata/StateTo(StateSet)Test.o Automata/ThompsonTest.o Automata/TransTest.o

Automata: $(objets)
	$(CC) $(CCFLAG) -o Automata $(objets)


# AutomataTest.cpp
#     CRSetTest.cpp
#     RFATest.cpp
#     StateRelTest.cpp
#     StateSetTest.cpp
#     StateTo(StateSet)Test.cpp
#     ThompsonTest.cpp
#     TransTest.cpp
# Automata.o: Automata.cpp
# 	$(CC) $(CCFLAG) -c "Automata/Automata.cpp" -o "obj/Automata.o"

# BitVec.o: BitVec.cpp
# 	$(CC) $(CCFLAG) -c "Automata/BitVec.cpp" -o "obj/BitVec.o"
# CharRange.o: CharRange.cpp
# 	$(CC) $(CCFLAG) -c "Automata/CharRange.cpp" -o "obj/BitVec.o"
# Constrs.cpp
# CRSet.cpp
# Dconstrs.cpp
# Deriv.cpp
# DFA.cpp
# DSDeRemer.cpp
# DSDFARev.cpp
# DSFA.cpp
# DSIS.cpp
# DSISopt.cpp
# DSLBFA.cpp
# DSRBFA.cpp
# DSRE.cpp
# DSREopt.cpp
# DSRFA.cpp
# DSRFA2.cpp
# DTrans.cpp
# DTransRel.cpp
# FA.cpp
# Iconstrs.cpp
# ISImpl.cpp
# LBFA.cpp
# RBFA.cpp
# RE.cpp
# RFA.cpp
# Sig-FA.cpp
# Sig-re.cpp
# Sig-RFA.cpp
# StateEqRel.cpp
# StateRel.cpp
# StateSet.cpp
# SymRel.cpp
# Trans.cpp
# TransImpl.cpp
# TransRel.cpp