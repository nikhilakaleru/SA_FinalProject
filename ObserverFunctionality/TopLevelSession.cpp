#include "TopLevelSession.h"
// inherit all the top level session specific observers here
#include "DrawingObservser.h"
#include "../AppPartOps/PartObserver.h"
//#include "Observer.h"
#include "../Core/Observer.h"
#include "..\AppPartOps\DelMeBadPattern.h"


TopLevelSession::TopLevelSession() : m_observerForSavePart(nullptr), m_observerForClosePart(nullptr), m_observerForOpenPart(nullptr), m_observerForDrawInk(nullptr), m_observerForEraseInk(nullptr)
{
    std::cout << "Hi, New Top Level Session is Created\n";
}

TopLevelSession& TopLevelSession::GetInstance()
{
    static TopLevelSession instance;

    return instance;
}

void TopLevelSession::SetupDefaultObservers()
{
    m_observerForSavePart = new PartObserver(TopLevelSession::GetInstance(), PartObserver::SavePart);
    m_observerForClosePart = new PartObserver(TopLevelSession::GetInstance(), PartObserver::ClosePart);
    m_observerForOpenPart = new PartObserver(TopLevelSession::GetInstance(), PartObserver::OpenPart);
   /* m_observerForDrawInk = new DrawingObservser(TopLevelSession::GetInstance(), DrawingObservser::OpenPart);
    m_observerForEraseInk = new DrawingObservser(TopLevelSession::GetInstance(), DrawingObservser::OpenPart);*/

}


TopLevelSession::~TopLevelSession() {
    std::cout << "Goodbye, I was the Top Level Session.\n";
}

static std::string  GenerateMessageFromEvent(Observer::EventTypes eventType)
{
    std::string retVal;
    if (eventType == Observer::ClosePart)
    {
        retVal = "Close Part was Called";
    }
    else if (eventType == Observer::OpenPart)
    {
        retVal = "Open Part was Called";
    }
    else if (eventType == Observer::SavePart)
    {
        retVal = "Save Part was Called";
    }
    else if (eventType == Observer::CreatePart)
    {
        retVal = "Create Part was Called";
    }
    else
    {
        retVal = "Unknown Event Type";
    }

    return retVal;
}



void TopLevelSession::Notify(Observer::EventTypes eventType)
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    NoOfObservererver();
    while (iterator != m_listObserver.end())
    {
        Observer* observer = dynamic_cast<Observer*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage);
        }
        ++iterator;
    }
}

void TopLevelSession::Notify(Observer::EventTypes eventType, void* data)
{
    std::string generateMessage = GenerateMessageFromEvent(eventType);

    std::list<IObserver*>::iterator iterator = m_listObserver.begin();
    NoOfObservererver();
    while (iterator != m_listObserver.end())
    {
        Observer* observer = dynamic_cast<Observer*>(*iterator);
        if (observer != nullptr && observer->UpdateOnEventType(eventType))
        {
            observer->Update(generateMessage, data);
        }
        ++iterator;
    }
}

void TopLevelSession::InitiateMessage(IObserver::EventTypes eventType)
{
    Notify(eventType);

}

void TopLevelSession::InitiateMessage(IObserver::EventTypes eventType, void* data)
{
    Notify(eventType, data);

}



void TopLevelSession::InitiateMessage(std::string message) {
    this->m_message = message;
    AlertEveryone();
}



