// Assignment_GC.cpp: A program using the TL-Engine

#include <TL-Engine.h>	// TL-Engine include file and namespace
#include <iostream>
#include <ostream>
#include <sstream>
#include <math.h>
#include <fstream>
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
	myEngine->AddMediaFolder("C:\\ProgramData\\TL-Engine\\Media\\MEDIAEXTRA");
	myEngine->AddMediaFolder("C:\\ProgramData\\TL-Engine\\Media\\MEDIAASSIGNMENT");


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
	IModel* isle [5];

	const int MAP1_Walls_Num = 5;

	int MAP1_Walls_Coord[MAP1_Walls_Num][3] = { {-90, 0, 40} ,{-100, 0, 40},{10, 0, 40},{10, 0, 53},{-10, 0, 53} };


	for (int i = 0; i < MAP1_Walls_Num; i++) {
		int cache_arr[3];
		for (int j = 0; j < 3; j++) {
			cache_arr[j] = MAP1_Walls_Coord[i][j];
		}
		IModel* isle = isleMesh->CreateModel(cache_arr[0], cache_arr[1], cache_arr[2]);
	}

	
	float myMatrix[4][4];

	IMesh* race2Mesh = myEngine->LoadMesh("race2.x");
	IModel* race2 = race2Mesh->CreateModel();
	race2->SetSkin("sp02-01.jpg");
	
	IMesh* garageMesh = myEngine->LoadMesh("GarageLarge.x");
	IModel* garage = garageMesh->CreateModel(100,0,0);

	IMesh* garage2Mesh = myEngine->LoadMesh("GarageSmall.x");
	IModel* garage2 = garage2Mesh->CreateModel(120, 0, 0);

	/*IMesh* race2Mesh = myEngine->LoadMesh("race2.x");
	IModel* race2 = race2Mesh->CreateModel();

	IMesh* race2Mesh = myEngine->LoadMesh("race2.x");
	IModel* race2 = race2Mesh->CreateModel();*/




	bool CONSTRUCT_MODE = 0;

	
	ICamera* myCamera = myEngine->CreateCamera(kFPS);
	


	

		/*checkpoint 1: (0, 0, 0)
		isle : (-10, 0, 40)
		isle : (10, 0, 40)
		wall : (-10.5, 0, 46)
		wall : (9.5, 0, 46)
		isle : (10, 0, 53)
		isle : (-10, 0, 53)
		checkpoint 2 : (0, 0, 150)*/





	float MAP1_WALLS_COORDS[5][4][4];


	





	ofstream fw("C:\\TLOUTPUT\\C_PLUSPLUS.txt", std::ofstream::out);






	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		float kTimer = myEngine->Timer();
		/**** Update your scene each frame here ****/
		sphere->SetX(myCamera->GetX());
		/*myCamera->LookAt(race2);*/
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
		sphere->GetMatrix(&myMatrix[0][0]);


		if (myEngine->KeyHeld(Mouse_LButton)) {
			IModel* model1 = isleMesh->CreateModel(myCamera->GetX(), 0, myCamera->GetZ());
			model1->SetMatrix(&myMatrix[0][0]);
			
			if (fw.is_open())
			{
				fw << "Model:";
				//store array contents to text file
				for (int i = 0; i < 4; i++) {
					fw << "\n";
				
				for (int j = 0; j < 4; j++) {
					fw << myMatrix[i][j] << " ";
				}
				}

				fw << "\n\n";
				
			}
			else cout << "Problem with opening file";
			
		}
		stringstream outdText;
		stringstream outdText2;
		stringstream currentOBJMatrix;
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

		
		currentOBJMatrix << myMatrix[0][0] << " " << myMatrix[0][1] << " " << myMatrix[0][2] << " " << myMatrix[0][3];
		myFont->Draw(currentOBJMatrix.str(), 20, 70);
			
		
		
		if (myEngine->KeyHit(Key_M)) {
			fw.close();
		}
		
		
		
	

	}
	
	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}
