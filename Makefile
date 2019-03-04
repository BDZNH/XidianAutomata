#!/bin/bash
CCFLAG = -Wall -fexceptions -g -std=c++11 -lwiringPi -lpthread -DNDEBUG
CC = g++

ALL: Automata.o BitVec.o CharRange.o

Automata.o: Automata.cpp
	$(CC) $(CCFLAG) -c "Automata/Automata.cpp" -o "obj/Automata.o"

BitVec.o: BitVec.cpp
	$(CC) $(CCFLAG) -c "Automata/BitVec.cpp" -o "obj/BitVec.o"
CharRange.o: CharRange.cpp
	$(CC) $(CCFLAG) -c "Automata/CharRange.cpp" -o "obj/BitVec.o"
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