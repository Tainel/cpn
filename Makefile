# MAKEFILE - COMPETITIVE PROGRAMMING NOTEBOOK

# Makefile for the CPN project.

#______________________________________________________________________________

# ------ VARIABLES ------ #

# Special variables.
.RECIPEPREFIX := >

# Compiler.
CXX := g++
CXXFLAGS := -std=c++11 -O2 -g -Wconversion -Wshadow -Wall -Wextra -Werror\
-D_GLIBCXX_DEBUG -D_LOCAL_COMP

# Subdirectories.
SRC := source/
ALG := $(SRC)algorithms/
GEO := $(SRC)geometry/
GPH := $(SRC)graphs/
MTH := $(SRC)maths/
STR := $(SRC)strings/
STS := $(SRC)structures/

# Source files.
MAIN := $(SRC)main.cpp
I1A := $(ALG)binary_search.cpp
I1B := $(ALG)dynamic_programming.cpp
I1C := $(ALG)longest_increasing_subsequence.cpp
I1D := $(ALG)nim.cpp
I2A := $(GEO)cartesian_points.cpp
I2B := $(GEO)convex_hull.cpp
I3A := $(GPH)bipartite.cpp
I3B := $(GPH)euler_path.cpp
I3C := $(GPH)graph.cpp
I3D := $(GPH)lowest_common_ancestor.cpp
I3E := $(GPH)minimum_spanning_tree.cpp
I3F := $(GPH)shortest_path.cpp
I3G := $(GPH)strongly_connected_components.cpp
I3H := $(GPH)topological_sort.cpp
I3I := $(GPH)traversal.cpp
I3J := $(GPH)tree.cpp
I4A := $(MTH)basic_algebra.cpp
I4B := $(MTH)combinatorics.cpp
I4C := $(MTH)divisors.cpp
I4D := $(MTH)euler_phi.cpp
I4E := $(MTH)factorization.cpp
I4F := $(MTH)modular_arithmetic.cpp
I4G := $(MTH)primes.cpp
I5A := $(STR)longest_common_subsequence.cpp
I5B := $(STR)palindromes.cpp
I5C := $(STR)string_matching.cpp
I6A := $(STS)disjoint_intervals.cpp
I6B := $(STS)disjoint_set_union.cpp
I6C := $(STS)fenwick_tree.cpp
I6D := $(STS)range_minimum_query.cpp
IMP := $(I1A) $(I1B) $(I1C) $(I1D) $(I2A) $(I2B) $(I3A) $(I3B) $(I3C) $(I3D)\
$(I3E) $(I3F) $(I3G) $(I3H) $(I3I) $(I3J) $(I4A) $(I4B) $(I4C) $(I4D) $(I4E)\
$(I4F) $(I4G) $(I5A) $(I5B) $(I5C) $(I6A) $(I6B) $(I6C) $(I6D)

# OS-dependant variables.
ifeq ($(OS),Windows_NT)
  RM := del /f /q
  EXE := main.exe
else ifndef OS
  UNAME := $(shell uname -s)
  ifeq ($(UNAME),Linux)
    EXE := main
  endif
endif

#______________________________________________________________________________

# ------ ALL ------ #

# Default target.
.PHONY: all
all: build

#______________________________________________________________________________

# ------ TARGETS ------ #

# Build executable.
.PHONY: build
ifndef EXE
build:
>$(error Cannot build due to unknown OS)
else
build: $(EXE)
endif

# Delete executable.
.PHONY: clean
clean:
ifndef EXE
>$(error Cannot clean due to unknown OS)
else
>$(RM) $(EXE)
endif

#______________________________________________________________________________

# ------ AUXILIARIES ------ #

# Create executable.
$(EXE): $(MAIN) $(IMP)
>$(CXX) $(CXXFLAGS) $< -o $@

#______________________________________________________________________________
