#pragma once

#include "UILIbraryExports.h"
#include "..\AppPartOps\PartObserver.h"


class UILIBRARY_API UI
{
public:

	UI();

	void Init();

	void StartGUILoop();

	void ShutDownGUILoop();

private:
	void PerformSampleJournalingPartsOps();
	void PerformPartsOpsThatNeedsToLoadDemandLoadedLibrary();
	void PerformJavaAutomationWorkflow();
	void PerformDotnetAutomationWorkflow();
	void PerformSampleUsingBuilder();

	PartObserver* observer4;
	PartObserver* observer5;

};