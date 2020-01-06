/** \file OA.cpp
    \author Wojciech Jarosz
*/

#include <OA.h>

using namespace std;

unsigned OrthogonalArray::setOffsetType(unsigned ot)
{
    if (ot < NUM_OFFSET_TYPES)
        m_ot = ot;
    return m_ot;
}
vector<string> OrthogonalArray::offsetTypeNames() const
{
    return {{"CTR", "J", "MJ", "CMJ"}};
}
