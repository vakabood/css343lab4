#include "nodedata.h"

//----------------------------------------------------------------------------
// constructors/destructor  

NodeData::NodeData() { }                         // default

NodeData::~NodeData() { }            // needed so strings are deleted properly

ostream& operator<<(ostream& out, const NodeData& nd) {
    out << "";
    return out;
}

