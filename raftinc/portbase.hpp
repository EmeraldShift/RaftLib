/**
 * portbase.hpp - Interface for port types.  Ensures that 
 * all port sub-classes have at least the functions listed
 * below.
 *
 * @author: Jonathan Beard
 * @version: Sun Nov 30 10:22:46 2014
 * 
 * Copyright 2014 Jonathan Beard
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef _PORTBASE_HPP_
#define _PORTBASE_HPP_  1

#include "portiterator.hpp"
#include "portmap_t.hpp"
#include "defs.hpp"


class PortBase
{
public:
   PortBase()           = default;
   virtual ~PortBase()  = default;
   
   /**
    * operator[] - enables lookup of ports by name,
    * which in turn enables the user to name each
    * port something that is telling of the underlying
    * function.
    * @param   port_name - name of the port you wish to get
    * @return FIFO&
    * @throws - should throw a PortNotFoundException if port_name
    * doesn't exist.
    */
   virtual FIFO& operator[]( const raft::port_key_type &&port_name ) = 0;

   /**
    * hasPorts - should return false if this port object is
    * empty.
    * @return bool - true if no ports
    */
   virtual bool  hasPorts() = 0;
   /**
    * begin - returns a forward iterator to the port list,
    * implementations should be thread safe so that auto-
    * parallelized code can function properly.
    * @return PortIterator - points to first port, not 
    * in alphabetical or necessarily any order.
    */
   virtual PortIterator begin() = 0;
   /**
    * end - returns one past the end of the iterator, should
    * be suitable for usage in a for( xxx : xxx ) loop just
    * as in any other meaningful usage of a forward iterator.
    * @return PortIterator - points to one past the last port.
    */
   virtual PortIterator end()   = 0;

};
#endif /* END _PORTBASE_HPP_ */
