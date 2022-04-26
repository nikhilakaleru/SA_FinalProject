

#pragma once
#include "../Core/CoreExports.h"
#include "../Core/CoreSession.h"
#include <list>
#include <iostream>

class PartObserver;
class DrawingObserver;

class CORE_API TopLevelSession : public CoreSession
{
public:

    // consturcutor to create observer objects
    TopLevelSession() ;


    // returns toplevelsession object.
    static TopLevelSession& GetInstance();


    // -
    TopLevelSession(TopLevelSession const&) = delete;
    void operator=(TopLevelSession const&) = delete;

    // print when object gets deleted
    ~TopLevelSession() override;

    // top level session specific notify methods based on event type
    void Notify(IObserver::EventTypes eventType) override;
    void Notify(IObserver::EventTypes eventType, void* data) override;


    // create message overloading functions
    void InitiateMessage(IObserver::EventTypes eventType);
    void InitiateMessage(IObserver::EventTypes eventType, void* data);
    void InitiateMessage(std::string message = "Empty");



    // initialize observers
    void SetupDefaultObservers();




private:


    // default observers
    PartObserver* m_observerForSavePart;
    PartObserver* m_observerForClosePart;
    PartObserver* m_observerForOpenPart;
    DrawingObserver* m_observerForDrawInk;
    DrawingObserver* m_observerForEraseInk;

};



