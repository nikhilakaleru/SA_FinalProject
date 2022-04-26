#pragma once
#include "CoreExports.h"
#include "ISubject.h"
#include <list>
#include <iostream>

class Observer;

class CORE_API CoreSession : ISubject
{
	public:

        // data members
        std::string m_message;
        std::list<IObserver*> m_listObserver;


        // constructor and destructor
        CoreSession();
        ~CoreSession() override;


        /**
         * The subscription management methods.
         */
        void Attach(IObserver* observer) override;
        void Detach(IObserver* observer) override;
        void AlertEveryone() override;
        void NoOfObservererver();
        void ClearObservers();

};

