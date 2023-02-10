// Assignment_GC.cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <iostream>
#include <ostream>
#include <sstream>
#include <math.h>
using namespace std;

using namespace tle;

const float kGameSpeed = 100.0f;

void main()
{
	// Create a 3D engine (using TLX engine here) and open a window for it
	I3DEngine* myEngine = New3DEngine( kTLX );
	myEngine->StartWindowed();
	IFont* myFont = myEngine->LoadFont("Font1.bmp");
	// Add default folder for meshes and other media
	myEngine->AddMediaFolder( "C:\\ProgramData\\TL-Engine\\Media" );
	
	/**** Set up your scene here ****/
	IMesh* skyMesh = myEngine->LoadMesh("Skybox2.x");
	IModel* sky = skyMesh->CreateModel(0, -960, 0);

	IMesh* floorMesh = myEngine->LoadMesh("ground.x");
	IModel* floor = floorMesh->CreateModel();

	IMesh* checkpointMesh = myEngine->LoadMesh("Checkpoint.x");
	IModel* checkpoint1 = checkpointMesh->CreateModel(0,0,0);
	IModel* checkpoint2 = checkpointMesh->CreateModel(0,0,150);

	IMesh* sphereMesh = myEngine->LoadMesh("IsleStraight.x");
	IModel* sphere = sphereMesh->CreateModel(0,0,0);
	

	IMesh* isleMesh = myEngine->LoadMesh("IsleStraight.x");
	IModel* isle1 = isleMesh->CreateModel(-10,0,40);
	IModel* isle2 = isleMesh->CreateModel(10,0,40);
	IModel* isle3 = isleMesh->CreateModel(10, 0, 53);
	IModel* isle4 = isleMesh->CreateModel(-10, 0, 53);


	IMesh* race2Mesh = myEngine->LoadMesh("race2.x");
	IModel* race2 = race2Mesh->CreateModel();
	race2->SetSkin("sp02-01.jpg");
	
	
	ICamera* myCamera = myEngine->CreateCamera(kManual, 0, 40, 0);
	myCamera->RotateLocalX(90);


		/*checkpoint 1: (0, 0, 0)
		isle : (-10, 0, 40)
		isle : (10, 0, 40)
		wall : (-10.5, 0, 46)
		wall : (9.5, 0, 46)
		isle : (10, 0, 53)
		isle : (-10, 0, 53)
		checkpoint 2 : (0, 0, 150)*/


	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		float kTimer = myEngine->Timer();
		/**** Update your scene each frame here ****/
		sphere->SetX(myCamera->GetX());
		
		sphere->SetZ(myCamera->GetZ());
		if (myEngine->KeyHeld(Key_W)) {
			myCamera->MoveZ(kGameSpeed * kTimer);

		}
		if (myEngine->KeyHeld(Key_A)) {
			myCamera->MoveLocalX(-kGameSpeed * kTimer);

		}
		if (myEngine->KeyHeld(Key_S)) {

			myCamera->MoveZ(-kGameSpeed * kTimer);
		}
		if (myEngine->KeyHeld(Key_D)) {
			myCamera->MoveLocalX(kGameSpeed * kTimer);

		}

		if (myEngine->KeyHeld(Key_Space)) {
			myCamera->MoveLocalZ(-kGameSpeed * kTimer * 2);
		}
		if (myEngine->KeyHeld(Key_Z)) {
			myCamera->MoveLocalZ(kGameSpeed * kTimer * 2);
		}
		int mouseMoveX = myEngine->GetMouseMovementX();

		sphere->RotateY(mouseMoveX);

		if (myEngine->KeyHeld(Mouse_LButton)) {
			IModel* model1 = isleMesh->CreateModel(myCamera->GetX(), 0, myCamera->GetZ());
			model1->RotateLocalY(sphere->GetLocalY());
		}
		stringstream outdText;
		stringstream outdText2;
		float sphereX = sphere->GetX();
		float sphereY = sphere->GetY();
		float sphereZ = sphere->GetZ();

		float sphereLX = sphere->GetLocalX();
		float sphereLY = sphere->GetLocalY();
		float sphereLZ = sphere->GetLocalZ();

		outdText << "Global_X:  " << round(sphereX) << "  Global_Y  " << round(sphereY) << "  Global_Z  "  << round(sphereZ);
		myFont->Draw(outdText.str(), 20, 20);
		outdText2 << "Local_X:  " << round(sphereLX) << "  Local_Y  " << round(sphereLY) << "  Local_Z  " << round(sphereLZ);
		myFont->Draw(outdText2.str(), 20, 50);
	}
	
	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}
