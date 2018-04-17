// Include the OculusVR SDK
#include "include\OVR_CAPI.h"
#include <iostream>
#include <thread>

using namespace std;

#define PORT "3710"
#define BACKLOG 10


// Sample code from the Oculus SDK, outlines the necessary steps to enable headset initialization and data access

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

// Oculus made this method of accessing the tracking data outdated for some reason.

void Application2()
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


// Method from charlesodale.com, hello world for oculus rift cv1 dk2 sdk1.3.0
int main()
{
	std::cout << "Initializing bullshit... \nIf I fail you'll know because it'll ask you to press any key to continue to continue or some shit: \n \n";

	if (ovr_Initialize(nullptr) == ovrSuccess)
	{
		ovrSession session = nullptr;
		ovrGraphicsLuid luid;
		ovrResult result = ovr_Create(&session, &luid);

		std::cout << "well its doing something lmao";

		if (result == ovrSuccess)
		{
			ovrTrackingState ts;

			while (true)
			{
				//ts is the tracking state and enables us to retrieve the necessary data

				ts = ovr_GetTrackingState(session, 0, true);

				ovrPoseStatef tempHeadPose = ts.HeadPose;
				ovrPosef tempPose = tempHeadPose.ThePose;
				ovrVector3f tempPos = tempPose.Position;
				ovrQuatf tempOrient = tempPose.Orientation;

				float yaw, pitch, roll;
				float xpos, ypos, zpos;

				pitch = tempOrient.x;
				roll = tempOrient.z;
				yaw = tempOrient.y;

				xpos = tempPos.x;
				ypos = tempPos.y;
				zpos = tempPos.z;

				std::cout << "Pitch: " << pitch << " Roll: " << roll + "  Yaw: " << yaw;
				std::cout << "X: " + xpos + " Y: " + ypos + " Z: " + zpos;

				//std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}

			ovr_Destroy(session);
		}

		ovr_Shutdown();
	}

	return 0;
}

void SendData(float pitch,float roll, float yaw, float xpos, float ypos, float zpos)
{ // Code to send the data on the second thread to matlab/simulink
	
}

void NetIni()
{ // Code to initialize all of the networking on a second thread

}