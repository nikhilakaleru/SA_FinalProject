

#pragma once
#include "../Core/CoreExports.h"
#include "../Core/Observer.h"
#include "TopLevelSession.h"

class CORE_API DrawingObservser : public Observer
{

public:

    DrawingObservser(TopLevelSession& topLevelSession, EventTypes eventType);
    ~DrawingObservser() override;
    void Update(const std::string& message_from_subject) override;
    void Update(const std::string& message_from_subject, void* data) override;
    void RemoveMeFromTheList();
    void PrintInfo();
    void PrintInfo(void* data);
    bool UpdateOnEventType(EventTypes eventType);

    

private:
    std::string message_from_subject_;
    TopLevelSession& topLevelSession_;
    static int static_number_;
    int number_;
    EventTypes m_eventType;

};

