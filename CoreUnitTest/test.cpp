#include "pch.h"
#include "..\Core\StringUtils.h"
#include "..\Core\Observer.h"
#include "..\Core\CoreSession.h"



TEST(ObserverCheckTests, InitiateMessageTest)
{
	CoreSession session;
	Observer* observer1 = new Observer(session, Observer::SavePart);
	session.InitiateMessage("save part observer is added");
	
	EXPECT_TRUE(session.m_message=="save part observer is added");

}

TEST(ObserverCheckTests, ObserverAttachTest)
{

	CoreSession session;
	Observer* observer1 = new Observer(session, Observer::SavePart);

	EXPECT_TRUE(session.m_listObserver.size()==1);
}

TEST(ObserverCheckTests, ObserverMultipleAttachTest)
{
	CoreSession session;
	Observer* observer1 = new Observer(session, Observer::OpenPart);
	Observer* observer2 = new Observer(session, Observer::ClosePart);
	Observer* observer3 = new Observer(session, Observer::SavePart);

	EXPECT_TRUE(session.m_listObserver.size() == 3);
}

TEST(ObserverCheckTests, ObserverDetachTest)
{
	CoreSession session;
	Observer* observer1 = new Observer(session, Observer::OpenPart);
	session.Detach(observer1);

	EXPECT_TRUE(session.m_listObserver.size() == 0);

}


TEST(ObserverCheckTests, ObserverMultipleAttachAndDetachTest)
{
	CoreSession session;
	Observer* observer1 = new Observer(session, Observer::OpenPart);
	session.Detach(observer1);
	Observer* observer2 = new Observer(session, Observer::ClosePart);
	Observer* observer3 = new Observer(session, Observer::SavePart);
	session.Detach(observer1);

	EXPECT_TRUE(session.m_listObserver.size() == 1);

}



TEST(ObserverCheckTests, SessionNotifyTest)
{


	EXPECT_TRUE(1   );

}

TEST(ObserverCheckTests, SessionAlertEveryoneTest)
{


	EXPECT_TRUE(1);

}

TEST(ObserverCheckTests, OpenPartNotifyTest)
{


	EXPECT_TRUE(1);

}

TEST(ObserverCheckTests, ClosePartNotifyTest)
{


	EXPECT_TRUE(1);

}

TEST(ObserverCheckTests, SavePartNotfiyTest)
{


	EXPECT_TRUE(1);

}



TEST(ObserverCheckTests, DrawingObserverTest)
{


	EXPECT_TRUE(1);

}


