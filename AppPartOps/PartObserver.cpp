#include "PartObserver.h"
#include "..\AppPartOps\DelMeBadPattern.h"
#include <iostream>

int static static_number_ = 0;

PartObserver::PartObserver(TopLevelSession& topLevelSession, EventTypes eventType) : topLevelSession_(topLevelSession), m_eventType(eventType) {
    this->topLevelSession_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++static_number_ << "\".\n";
    this->number_ = static_number_;
}
PartObserver::~PartObserver() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void PartObserver::Update(const std::string& message_from_subject) {
    message_from_subject_ = message_from_subject;
    PrintInfo();
}
void PartObserver::Update(const std::string& message_from_subject, void* data) {
    message_from_subject_ = message_from_subject;
    PrintInfo(data);
}


void PartObserver::RemoveMeFromTheList() {
    topLevelSession_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}
void PartObserver::PrintInfo()
{
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";

}

void PartObserver::PrintInfo(void* data)
{
    PartOpsNotifierData* partData = (PartOpsNotifierData*)data;

    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    std::cout << "Part Data \n" << "Part FilePath " << partData->partName << "\nPart GUID " << partData->guid << std::endl;

}

bool PartObserver::UpdateOnEventType(EventTypes eventType)
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
