/*******************************************************************************
File:         tmDpptrArray.cpp
Project:      TreeMaker 5.x
Purpose:      Implementation file for dangle-proof array of pointers
Author:       Robert J. Lang
Modified by:
Created:      2003-11-15
Copyright:    2003 Robert J. Lang. All Rights Reserved.
*******************************************************************************/

#include "tmDpptrArray.h"
#include "tmDpptrTarget.h"
#include "tmCondition.h"
#include "tmFacet.h"
#include "tmCrease.h"
#include "tmVertex.h"
#include "tmPoly.h"
#include "tmPath.h"
#include "tmEdge.h"
#include "tmNode.h"

/*****
Destructor. Inform all objects that they're no longer referenced by us
*****/
template <class T>
tmDpptrArray<T>::~tmDpptrArray()
{
    for (std::size_t i = 0; i < this->size(); ++i) {
        tmDpptrTarget* target = dynamic_cast<tmDpptrTarget*>((*this)[i]);
        if (target) {
            DstRemoveMeAsDpptrSrc(target);
        }
    }
}

// Explicit instantiations for the types used in your code
template class tmDpptrArray<tmCondition>;
template class tmDpptrArray<tmFacet>;
template class tmDpptrArray<tmCrease>;
template class tmDpptrArray<tmVertex>;
template class tmDpptrArray<tmPoly>;
template class tmDpptrArray<tmPath>;
template class tmDpptrArray<tmEdge>;
template class tmDpptrArray<tmNode>;