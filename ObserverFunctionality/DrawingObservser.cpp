#include "DrawingObservser.h"
#include "..\AppPartOps\DelMeBadPattern.h"
#include "TopLevelSession.h"
#include <iostream>

int static static_number_ = 0;

DrawingObservser::DrawingObservser(TopLevelSession& topLevelSession, EventTypes eventType) : topLevelSession_(topLevelSession), m_eventType(eventType) {
    this->topLevelSession_.Attach(this);
    std::cout << "Hi, I'm the Observer \"" << ++static_number_ << "\".\n";
    this->number_ = static_number_;
}
DrawingObservser::~DrawingObservser() {
    std::cout << "Goodbye, I was the Observer \"" << this->number_ << "\".\n";
}

void DrawingObservser::Update(const std::string& message_from_subject) {
    message_from_subject_ = message_from_subject;
    PrintInfo();
}
void DrawingObservser::Update(const std::string& message_from_subject, void* data) {
    message_from_subject_ = message_from_subject;
    PrintInfo(data);
}


void DrawingObservser::RemoveMeFromTheList() {
    topLevelSession_.Detach(this);
    std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}
void DrawingObservser::PrintInfo()
{
    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";

}

void DrawingObservser::PrintInfo(void* data)
{
    PartOpsNotifierData* partData = (PartOpsNotifierData*)data;

    std::cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
    std::cout << "Part Data \n" << "Part FilePath " << partData->partName << "\nPart GUID " << partData->guid << std::endl;

}

bool DrawingObservser::UpdateOnEventType(EventTypes eventType)
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
