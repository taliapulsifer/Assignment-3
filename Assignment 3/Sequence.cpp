// FILE: Sequence.cpp
// CLASS IMPLEMENTED: sequence (see sequence.h for documentation)
// INVARIANT for the sequence ADT:
//   1. The number of items in the sequence is in the member variable
//      used;
//   2. The actual items of the sequence are stored in a partially
//      filled array. The array is a dynamic array, pointed to by
//      the member variable data. For an empty sequence, we do not
//      care what is stored in any of data; for a non-empty sequence
//      the items in the sequence are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.
//   3. The size of the dynamic array is in the member variable
//      capacity.
//   4. The index of the current item is in the member variable
//      current_index. If there is no valid current item, then
//      current_index will be set to the same number as used.
//      NOTE: Setting current_index to be the same as used to
//            indicate "no current item exists" is a good choice
//            for at least the following reasons:
//            (a) For a non-empty sequence, used is non-zero and
//                a current_index equal to used indexes an element
//                that is (just) outside the valid range. This
//                gives us a simple and useful way to indicate
//                whether the sequence has a current item or not:
//                a current_index in the valid range indicates
//                that there's a current item, and a current_index
//                outside the valid range indicates otherwise.
//            (b) The rule remains applicable for an empty sequence,
//                where used is zero: there can't be any current
//                item in an empty sequence, so we set current_index
//                to zero (= used), which is (sort of just) outside
//                the valid range (no index is valid in this case).
//            (c) It simplifies the logic for implementing the
//                advance function: when the precondition is met
//                (sequence has a current item), simply incrementing
//                the current_index takes care of fulfilling the
//                postcondition for the function for both of the two
//                possible scenarios (current item is and is not the
//                last item in the sequence).

#include <cassert>
#include "Sequence.h"
#include <iostream>
using namespace std;

namespace CS3358_FA2023
{
   // CONSTRUCTORS and DESTRUCTOR
   // 
    //In line initialization for class members!!!
   sequence::sequence(size_type initial_capacity) : used(0), current_index(0)
       ,capacity(initial_capacity)
   {
       //Check to see if the intial capacity is less than one,
       //If it is, change to be one!!!
       if (initial_capacity < 1)
       {
           initial_capacity = 1;
       }
       //Set dynamic array 
       data = new value_type[capacity];
   }

   //Copy constructor
   sequence::sequence(const sequence& source) : used(source.used), capacity(source.capacity)
       , current_index(source.current_index)
   {
       data = new value_type[capacity];
       copy(data, capacity, source.data, source.capacity);
   }

   sequence::~sequence()
   {
       delete(data);
       data = NULL;
   }

   // MODIFICATION MEMBER FUNCTIONS
   void sequence::resize(size_type new_capacity)
   {
       //Check to see if the new capacity is valid (>1)
       if (new_capacity < 1)
       {
           capacity = 1;
       }
       //Check to see if new capacity is valid (> used)
       if (new_capacity < used)
       {
           capacity = used;
       }
       //If the new capacity is valid, set the capacity to new
       //capacity
       else
       {
           capacity = new_capacity;
       }
       //Create new dynamic array
       value_type* temp = new value_type[capacity];

       //Copy over data here 

   }

   void sequence::start()
   {
       current_index = 0;
   }

   void sequence::advance()
   {
       //Pre : isItem() returns true!!
       assert(is_item);
       //If it passes assert, increment current_index by one
       current_index++;
   }

   void sequence::insert(const value_type& entry)
   {
       if (used == capacity)
       {
           resize(capacity * 1.5);
       }
       //If there is no current item
       if (!is_item)
       {
           current_index = 0;

       }
       //If there are items already in the sequence, the item is inserted BEFORE the
       //current item.

       //The newly inserted item is now the current Item
   }

   void sequence::attach(const value_type& entry)
   {
       if (used == capacity)
       {
           resize(capacity * 1.5);
       }
       //If there is no current item
       if (!is_item)
       {
           //Insert at the beggining
       }
       //If there is a current item

       //Insert AFTER the current index

       //The new item becomes the current item
   }

   void sequence::remove_current()
   {
       //Pre : is_Item() returns true -> assert

       //Remove current Item, the item after is now the current item

       //If the current item was the last item in the sequence,
       //The sequence is now EMPTY
   }

   sequence& sequence::operator=(const sequence& source)
   {
      cout << "operator=(const sequence& source) not implemented yet" << endl;
      return *this;
   }

   // CONSTANT MEMBER FUNCTIONS
   sequence::size_type sequence::size() const
   {
       return used;
   }

   bool sequence::is_item() const
   {
      //Check to see if the current item is a valid by activating
       //the current member function
       return (current_index != used);
   }

   sequence::value_type sequence::current() const
   {
       //Pre: is_Item() returns true -> assert
       assert(is_item());
       return data[current_index];
   }
}

