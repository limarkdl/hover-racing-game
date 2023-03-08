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
	I3DEngine* myEngine = New3DEngine(kTLX);
	myEngine->StartWindowed();
	IFont* myFont = myEngine->LoadFont("Font1.bmp");
	// Add default folder for meshes and other media
	/*myEngine->AddMediaFolder( "C:\\ProgramData\\TL-Engine\\Media" );
	myEngine->AddMediaFolder("C:\\ProgramData\\TL-Engine\\Media\\MEDIAEXTRA");*/
	myEngine->AddMediaFolder("C:\\Users\\IKostin\\source\\repos\\ASSIGNMENT_GC\\MEDIA");

	bool isCameraM = 'true';

	/**** Set up your scene here ****/
	/*IMesh* skyMesh = myEngine->LoadMesh("Skybox2.x");
	IModel* sky = skyMesh->CreateModel(0, -960, 0);*/

	/*IMesh* floorMesh = myEngine->LoadMesh("ground.x");
	IModel* floor = floorMesh->CreateModel(0, -2, 0);*/

	IMesh* checkpointMesh = myEngine->LoadMesh("Checkpoint.x");
	/*IModel* checkpoint1 = checkpointMesh->CreateModel(0, 0, 0);*/
	IModel* checkpoint2 = checkpointMesh->CreateModel(0, 0, 150);


	IMesh* isleMesh = myEngine->LoadMesh("IsleStraight.x");
	IModel* isle[5];

	const int MAP1_Walls_Num = 5;

	int MAP1_Walls_Coord[MAP1_Walls_Num][3] = { {-90, 0, 40} ,{-100, 0, 40},{10, 0, 40},{10, 0, 53},{-10, 0, 53} };


	for (int i = 0; i < MAP1_Walls_Num; i++) {
		int cache_arr[3];
		for (int j = 0; j < 3; j++) {
			cache_arr[j] = MAP1_Walls_Coord[i][j];
		}
		IModel* isle = isleMesh->CreateModel(cache_arr[0], cache_arr[1], cache_arr[2]);
	}

	string MODELS[] = { "", "GarageLarge.x","GarageSmall.x", "IsleCorner.x", "IsleCross.x", "IsleTee.x", "Lamp.x", "TankLarge1.x", "TankLarge2.x", "Tribune2.x",
		"Tribune3.x", "Walkway.x", "Checkpoint.x","Cross.x","Flare.x","Interstellar.x",
		"IsleStraight.x","race2.x","TankSmall1.x","TankSmall2.x","Tribune1.x","Wall.x","Arrow.x","Box.x","Bullet.x","Cross.x","Cube.x","Cue.x","Dummy.x","Flare.x","Grid.x",
		"island.x","Match.x","Matchbox.x","minicube.x","Planet.x","PoolBall.x","PoolTable.x","Stars.x","Teapot.x","Torus.x","Tribune3.x","Turret.x","TwoPence.x","water.x","skull.x" };

	// CONSTRUCTOR STATE // 
	bool isConstructorMode = true;

	// Stores current chosen model from a MODELS[] for CONSTRUCTOR
	int counterMODELS = 1;

	float myMatrix[4][4];

	IMesh* race2Mesh = myEngine->LoadMesh("race2.x");
	IModel* race2 = race2Mesh->CreateModel();
	race2->SetSkin("sp02-01.jpg");

	/*IMesh* lampMesh = myEngine->LoadMesh("lamp.x");
	IModel* lampa = lampMesh->CreateModel(0,7,-5);
	lampa->RotateLocalY(180);*/

	IMesh* poolTableMesh = myEngine->LoadMesh("PoolTable.x");
	IModel* poolTable = poolTableMesh->CreateModel(100, 0, 0);

	IMesh* garage2Mesh = myEngine->LoadMesh("GarageSmall.x");
	IModel* garage2 = garage2Mesh->CreateModel(120, 0, 0);

	IMesh* IsleCornerMesh = myEngine->LoadMesh("IsleCorner.x");
	IModel* IsleCorner = IsleCornerMesh->CreateModel(140, 0, 0);

	IMesh* IsleCrossMesh = myEngine->LoadMesh("IsleCross.x");
	IModel* IsleCross = IsleCrossMesh->CreateModel(160, 0, 0);

	IMesh* IsleTeeMesh = myEngine->LoadMesh("IsleTee.x");
	IModel* IsleTee = IsleTeeMesh->CreateModel(180, 0, 0);

	IMesh* LampMesh = myEngine->LoadMesh("Lamp.x");
	IModel* Lamp = LampMesh->CreateModel(200, 0, 0);

	IMesh* TankLarge1Mesh = myEngine->LoadMesh("Skybox.x");
	IModel* TankLarge1 = TankLarge1Mesh->CreateModel(0, -960, 0);



	/*IMesh* TankLarge2Mesh = myEngine->LoadMesh("SkyBox 07.x");
	IModel* TankLarge2 = TankLarge2Mesh->CreateModel();*/



	IMesh* CueMesh = myEngine->LoadMesh("Cue.x");
	IModel* Cue = CueMesh->CreateModel(1, 10, -8);
	Cue->SetSkin("antenna.jpg");
	Cue->Scale(0.015);
	Cue->ScaleX(0.5);
	Cue->RotateLocalX(-130);
	/*Cue->RotateLocalY(45);*/
	
	IModel* Cue2 = CueMesh->CreateModel(-1, 10, -8);
	Cue2->Scale(0.015);
	Cue2->ScaleX(0.5);
	Cue2->RotateLocalX(-130);
	

	IMesh* Tribune3Mesh = myEngine->LoadMesh("Tribune3.x");
	IModel* Tribune3 = Tribune3Mesh->CreateModel(350, 0, 0);

	IMesh* WalkwayMesh = myEngine->LoadMesh("Walkway.x");
	IModel* Walkway = WalkwayMesh->CreateModel(500, 0, 0);


	int changedWheel = 0;

	bool CONSTRUCT_MODE = 0;


	ICamera* myCamera = myEngine->CreateCamera(kManual);
	myCamera->RotateLocalX(90);

	float MAP1_WALLS_COORDS[5][4][4];

	IMesh* wallMesh = myEngine->LoadMesh("Wall.x");

	/*float SECTION1[16][3] = { {-20, 0, 0},{-20, 0, 10},{-20, 0, 20},{-20, 0, 30},{-20, 0, 40},{-20, 0, 50},
		{-20, 0, 60},{-20, 0, 70},{20, 0, 0},{20, 0, 10},{20, 0, 20},{20, 0, 30},{20, 0, 40},{20, 0, 50},{20, 0, 60},{20, 0, 70} };*/

	
	int z = 0;
	for (int i = 0; i < 20; i++) {
		IModel* wall = wallMesh->CreateModel(-20, 0, z);
		wall->ScaleZ(1.2);
		z += 8;

	}

	z = 0;
	for (int i = 0; i < 20; i++) {
		IModel* wall = wallMesh->CreateModel(20, 0, z);
		wall->ScaleZ(1.2);
		z += 8;
	}

	/*for (int i = 0; i < 20; i++) {


	}*/


	/*for (int i = 0; i < 16; i++) {
		int cache_arr[3];
		for (int j = 0; j < 3; j++) {
			cache_arr[j] = SECTION1[i][j];
		}
		IModel* wall = wallMesh->CreateModel(cache_arr[0], cache_arr[1], cache_arr[2]);
		wall->ScaleZ(1.2);
	}*/
	

	IMesh* newMesh = myEngine->LoadMesh(MODELS[counterMODELS]);
	IModel* sphere = newMesh->CreateModel(myCamera->GetX(), 0, myCamera->GetZ());



	ofstream fw("C:\\TLOUTPUT\\C_PLUSPLUS.txt", std::ofstream::out);

	
	IMesh* testMesh = myEngine->LoadMesh("Walkway.x");
	IModel* test = testMesh->CreateModel(30, 0, 100);

	test->ScaleX(10);


	// The main game loop, repeat until engine is stopped
	while (myEngine->IsRunning())
	{
		// Draw the scene
		myEngine->DrawScene();
		float kTimer = myEngine->Timer();
		/**** Update your scene each frame here ****/


		if (isConstructorMode) {


			if (isCameraM) {
				myEngine->StartMouseCapture();
				int mouseMoveX = myEngine->GetMouseMovementX();

				sphere->RotateY(mouseMoveX);
				sphere->GetMatrix(&myMatrix[0][0]);
			}

			if (myEngine->KeyHit(Key_Escape)) {
				myEngine->Stop();
			}

			if (myEngine->KeyHit(Mouse_LButton)) {

				IModel* model1 = newMesh->CreateModel(myCamera->GetX(), 50, myCamera->GetZ());

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
			outdText << "Current model:  " << MODELS[counterMODELS] << "  Counter:  " << counterMODELS << "MOUSEWHEEL: " << myEngine->GetMouseWheel();
			myFont->Draw(outdText.str(), 20, 20);
		}
		sphere->SetX(myCamera->GetX());
		sphere->SetZ(myCamera->GetZ());
		if (myEngine->GetMouseWheel() != changedWheel) {
				counterMODELS += myEngine->GetMouseWheelMovement();
				if (counterMODELS == 0) {
					counterMODELS = 1;
				}
				else if (counterMODELS == 45) {
					counterMODELS = 44;
				}
				newMesh->RemoveModel(sphere);
    				newMesh = myEngine->LoadMesh(MODELS[counterMODELS]);
				sphere = newMesh->CreateModel();
				changedWheel = myEngine->GetMouseWheel();	
		}
	

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
		
		
		

		if (myEngine->KeyHit(Key_C)) {
			if (isCameraM) {
				myCamera = myEngine->CreateCamera(kFPS);
				isCameraM = false;
			}
			else {
				myCamera = myEngine->CreateCamera(kManual);
				myCamera->RotateLocalX(90);
				isCameraM = true;

			}
		} 
	
		//ISprite* menu =  myEngine->CreateSprite("floorMetal1.tga",0,0,0);
		
		
		stringstream outdText2;
		stringstream currentOBJMatrix;
		float sphereX = sphere->GetX();
		float sphereY = sphere->GetY();
		float sphereZ = sphere->GetZ();

		float sphereLX = sphere->GetLocalX();
		float sphereLY = sphere->GetLocalY();
		float sphereLZ = sphere->GetLocalZ();

		
		outdText2 << "Local_X:  " << round(sphereLX) << "  Local_Y  " << round(sphereLY) << "  Local_Z  " << round(sphereLZ);
		myFont->Draw(outdText2.str(), 20, 50);

		
		currentOBJMatrix << myMatrix[0][0] << " " << myMatrix[0][1] << " " << myMatrix[0][2] << " " << myMatrix[0][3];
		myFont->Draw(currentOBJMatrix.str(), 20, 70);
			
		
		
		if (myEngine->KeyHit(Key_L)) {
			fw.close();
		}
		
		
		if (myEngine->KeyHit(Key_M)) {
			isConstructorMode = !isConstructorMode;
		}
	

	}
	
	// Delete the 3D engine now we are finished with it
	myEngine->Delete();
}

