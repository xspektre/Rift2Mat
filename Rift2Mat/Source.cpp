// Include the OculusVR SDK
#include "include\OVR_CAPI.h"
#include <iostream>

void Application()
{
	ovrResult result = ovr_Initialize(nullptr);
	if (OVR_FAILURE(result))
		return;

	ovrSession session;
	ovrGraphicsLuid luid;
	result = ovr_Create(&session, &luid);
	if (OVR_FAILURE(result))
	{
		ovr_Shutdown();
		return;
	}

	ovrHmdDesc desc = ovr_GetHmdDesc(session);
	ovrSizei resolution = desc.Resolution;

	ovr_Destroy(session);
	ovr_Shutdown();
}

void main()
{
	std::cout << "1";
	std::system("pause");

	ovrResult result = ovr_Initialize(0);
	if (OVR_FAILURE(result))
		return;

	std::cout << "2";
	std::system("pause");

	ovrSession session;
	ovrGraphicsLuid luid;
	result = ovr_Create(&session, &luid);
	if (OVR_FAILURE(result))
	{
		ovr_Shutdown();
		return;
	}

	std::cout << "3";
	std::system("pause");

	ovrHmdDesc desc = ovr_GetHmdDesc(session);
	ovrSizei resolution = desc.Resolution;

	std::cout << "4";
	std::system("pause");

	ovrTrackingState ts = ovr_GetTrackingState(session, ovr_GetTimeInSeconds(), ovrTrue);
	std::cout << ts.StatusFlags;

	if (ts.StatusFlags & (ovrStatus_OrientationTracked | ovrStatus_PositionTracked))
	{
		std::cout << "Tracking Functional.";
		std::system("pause");
	}

	while (true)
	{
		ovrPosef pose = ts.HeadPose.ThePose;
		long xOr = pose.Orientation.x;
		long yOr = pose.Orientation.y;
		long zOr = pose.Orientation.z;
		std::cout << "X: " << xOr << " Y: " << yOr << " Z: " << zOr << std::endl;
	}

	ovr_Destroy(session);
	ovr_Shutdown();

}