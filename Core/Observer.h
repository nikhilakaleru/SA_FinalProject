#pragma once
#include "CoreExports.h"
#include "IObserver.h"
#include "CoreSession.h"

class CORE_API Observer : public IObserver 
{
   
    public:

        void RemoveMeFromTheList();
        bool UpdateOnEventType(EventTypes eventType);

        EventTypes m_eventType;
    
};

