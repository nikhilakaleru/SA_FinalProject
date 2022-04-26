#include "Observer.h"
#include "..\AppPartOps\DelMeBadPattern.h"
#include <iostream>



bool Observer::UpdateOnEventType(EventTypes eventType)
{
    if (eventType == m_eventType)
    {
        return true;
    }
    else
    {
        return false;
    }
}
