#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	//Bloons
	for (int i = 0; i < g_AmountOfBloonsTextures; ++i)
	{
		if (!TextureFromFile("Resources/Bloons/" + std::to_string(i) + ".png", g_ArrBloonsTextures[i]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}
	}

	//Monkeys
	for (int i = 0; i < g_AmountOfMonkeyTextures; ++i)
	{
		for (int j = 0; j < g_AmountOfUpgradesPerMonkey; ++j)
		{
			if (!TextureFromFile("Resources/Monkeys/" + std::to_string(i) + std::to_string(j) + ".png", g_ArrMonkeyTextures[i * g_AmountOfUpgradesPerMonkey + j]))
			{
				std::cout << "ERROR! Failed to load the texture!\n";
			}
		}

		//Previews
		if (!TextureFromFile("Resources/Monkeys/Previews/" + std::to_string(i * 2) + ".png", g_ArrPreviewMonkeyTextures[i * 2]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}

		if (!TextureFromFile("Resources/Monkeys/Previews/" + std::to_string(i * 2 + 1) + ".png", g_ArrPreviewMonkeyTextures[i * 2 + 1]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}
	}

	//Projectiles
	for (int i = 0; i < g_AmountOfProjectiles; ++i)
	{
		if (!TextureFromFile("Resources/Projectiles/" + std::to_string(i) + ".png", g_ArrProjectileTextures[i]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}
	}

	//UI
	for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
	{
		if (!TextureFromFile("Resources/UI/" + std::to_string(i) + ".png", g_ArrUIMonkeyBuyButtons[i].texture))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}

		g_ArrUIMonkeyBuyButtons[i].rect.width = g_ArrUIMonkeyBuyButtons[i].texture.width;
		g_ArrUIMonkeyBuyButtons[i].rect.height = g_ArrUIMonkeyBuyButtons[i].texture.height;
	}

	if (!TextureFromString("Dart Monkey", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_ArrUIMonkeyTextButtons[0]))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	if (!TextureFromString("Boomerang Monkey", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_ArrUIMonkeyTextButtons[1]))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	if (!TextureFromString("Tack Shooter", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_ArrUIMonkeyTextButtons[2]))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	if (!TextureFromFile("Resources/UI/BG.png", g_TextUIBackground))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	InitPath();
	StartWave();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawBoard();
	DrawBloons();
	DrawMonkeys();

	DrawUI();

	DrawProjectiles();

	if (g_IsPreviewOn)
	{
		DrawPreviewMonkey();
	}

}

void Update(float elapsedSec)
{
	
	UpdateUI(elapsedSec);
	UpdateMonkey(elapsedSec);
	UpdateProjectiles(elapsedSec);
	UpdateBloons(elapsedSec);
}

void End()
{
	// free game resources here
	for (int i = 0; i < g_AmountOfBloonsTextures; ++i)
	{
		DeleteTexture(g_ArrBloonsTextures[i]);
	}

	for (int i = 0; i < g_AmountOfMonkeyTextures * g_AmountOfUpgradesPerMonkey; ++i)
	{
		DeleteTexture(g_ArrMonkeyTextures[i]);
	}

	for (int i = 0; i < g_AmountOfMonkeyTextures * 2; ++i)
	{
		DeleteTexture(g_ArrPreviewMonkeyTextures[i]);
	}

	for (int i = 0; i < g_AmountOfProjectiles; ++i)
	{
		DeleteTexture(g_ArrProjectileTextures[i]);
	}

	for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
	{
		DeleteTexture(g_ArrUIMonkeyBuyButtons[i].texture);
		DeleteTexture(g_ArrUIMonkeyTextButtons[i]);
	}

	DeleteTexture(g_TextUIBackground);

	delete[] g_ArrMonkeys;
	delete[] g_ArrBloons;
	delete[] g_Path;
	delete[] g_ArrProjectiles;
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//UI
	if (key == SDLK_TAB)
	{
		g_IsUIActive = !g_IsUIActive;
	}

	//Preview
	if (key == SDLK_ESCAPE)
	{
		g_IsPreviewOn = false;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePosition.x = static_cast<float>(e.x);
	g_MousePosition.y = static_cast<float>(e.y);

	//TODO: Collision detection for preview monkey
	//I think it is to Done now
	const Point2f mousePos{
		static_cast<float>(e.x),
		static_cast<float>(e.y)
	};

	/*const Rectf previewMonkeyRect{
		mousePos.x - g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId].width * 0.25f,
		mousePos.y - g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId].height * 0.25f,
		g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId].width * 0.5f,
		g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId].height * 0.5f
	};*/
	const Circlef previewMonkeyCirclef{
		mousePos.x,
		mousePos.y,
		g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId].height * 0.25f
	};
	g_CanPlaceMonkey = !IsCircleCollidingWithPath(previewMonkeyCirclef);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePosition{
	static_cast<float>(e.x),
	static_cast<float>(e.y)
	};
	std::cout << g_PreviewMonkeyId << std::endl;
	if(g_CanPlaceMonkey && g_IsPreviewOn) PlaceMonkey(mousePosition, GetMonkeyFromIndex(g_PreviewMonkeyId));
	
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	if (e.button == SDL_BUTTON_LEFT && g_IsUIActive)
	{
		UpdateUIButtonCollisions();
		for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
		{
			if (!g_ArrUIMonkeyBuyButtons[i].isHoveringOver)
				continue;

			g_PreviewMonkeyId = i;
			g_IsPreviewOn = true;
			g_IsUIActive = false;
			break;
		}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void InitPath()
{
	int currentRow{ 0 }, currentColumn{ 0 };
	Point2f* tempPath{ new Point2f[g_Rows * g_Cols] };
	int currentPointIndex{ 0 };


	//looks for the starting position, signified as -1 on board grid
	for (int row = 0; row < g_Rows; ++row) {
		for (int col = 0; col < g_Cols; ++col) {
			if (g_BoardGrid[row * g_Cols + col] == -1) {
				currentRow = row;
				currentColumn = col;
				tempPath[currentPointIndex] = Point2f{ (currentColumn) * (g_CellSize.x) + g_CellSize.x ,
				currentRow * (g_CellSize.y) };

				++currentPointIndex;
				++g_PathWaypointAmount;
				break;
			}
		}
	}


	//Looks for next path tile, until reaches the end tile signifies as 2 on board grid
	while (g_BoardGrid[currentRow * g_Cols + currentColumn] != 2) {
		if (currentColumn < g_Cols &&
			g_BoardGrid[currentRow * g_Cols + (currentColumn + 1)] != 0 &&
			g_CurrentPathDirection != Direction::left)
		{
			++currentColumn;
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) ,
				currentRow * (g_CellSize.y) };
			++currentPointIndex;
			++g_PathWaypointAmount;
			g_CurrentPathDirection = Direction::right;
		}
		else if (currentColumn > 0 &&
			g_BoardGrid[currentRow * g_Cols + (currentColumn - 1)] != 0 &&
			g_CurrentPathDirection != Direction::right)
		{
			--currentColumn;
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) ,
				currentRow * (g_CellSize.y) };
			++currentPointIndex;
			++g_PathWaypointAmount;
			g_CurrentPathDirection = Direction::left;
		}
		else if (currentRow > 0 &&
			g_BoardGrid[(currentRow - 1) * g_Cols + currentColumn] != 0 &&
			g_CurrentPathDirection != Direction::down) {
			--currentRow;
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) ,
				currentRow * (g_CellSize.y) };
			++currentPointIndex;
			++g_PathWaypointAmount;
			g_CurrentPathDirection = Direction::up;
		}
		else if (currentRow < g_Rows &&
			g_BoardGrid[(currentRow + 1) * g_Cols + currentColumn] != 0 &&
			g_CurrentPathDirection != Direction::up) {
			++currentRow;
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) ,
				currentRow * (g_CellSize.y) };
			++currentPointIndex;
			++g_PathWaypointAmount;
			g_CurrentPathDirection = Direction::down;
		}

	}

	delete[] g_Path;
	g_Path = nullptr;

	g_Path = new Point2f[g_PathWaypointAmount]{};

	for (int index = 0; index < g_PathWaypointAmount; ++index) {
		g_Path[index] = tempPath[index];
	}

	delete[] tempPath;
}
void DrawBoard()
{
	Color4f const cPath{ 0.7f, 0.47f, 0.27f, 1.f }, cGround{ 0.52f, 0.82f, 0.48f, 1.f },
		cEndPoint{ 1.f, 0.f, 0.f, 1.f }, cStartPoint{0.46f, 0.96f, 0.26f, 1.f};

	for (int row = 0; row < g_Rows; ++row) {
		for (int col = 0; col < g_Cols; ++col) {
			Rectf currentCell{ col * g_CellSize.x, row * g_CellSize.y, g_CellSize.x, g_CellSize.y };
			if (g_BoardGrid[row * g_Cols + col] == 1) {
				utils::SetColor(cPath);
			}
			else if (g_BoardGrid[row * g_Cols + col] == 2) {
				utils::SetColor(cEndPoint);
			}
			else if (g_BoardGrid[row * g_Cols + col] == -1) {
				utils::SetColor(cStartPoint);
			}
			else {
				utils::SetColor(cGround);
			}
			utils::FillRect(currentCell);
		}
	}
}

void StartWave()
{
	++g_CurrentWave;
	delete[] g_ArrBloons;
	int bloonsHpToSpawn{ g_BloonsHpToSpawn };
	int* arrBloonsToSpawn{ new int[g_AmountOfBloonsTextures] {} };
	g_TotalAmountOfBloons = 0;

	//Randomness
	int bloonRandomOffsetFactor{};
	int maxTierOfBloon{};

	if (g_CurrentWave < 6)
	{
		bloonRandomOffsetFactor = 0;
		maxTierOfBloon = 2;
	}
	else if (g_CurrentWave < 11)
	{
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 4;
	}

	while (bloonsHpToSpawn > 0)
	{
		int randomBloon{};

		//Randimize bloon to spawn
		if (bloonsHpToSpawn + bloonRandomOffsetFactor >= maxTierOfBloon)
		{
			randomBloon = maxTierOfBloon + GetRand(-bloonRandomOffsetFactor, bloonRandomOffsetFactor);
		}
		else if (bloonsHpToSpawn >= maxTierOfBloon)
		{
			randomBloon = maxTierOfBloon + GetRand(-bloonRandomOffsetFactor, 0);
		}
		else if (bloonsHpToSpawn > bloonRandomOffsetFactor)
		{
			randomBloon = bloonsHpToSpawn + GetRand(-bloonRandomOffsetFactor, bloonRandomOffsetFactor);
		}
		else
		{
			randomBloon = bloonsHpToSpawn;
		}

		//Check if bloon went overboard just in case
		if (randomBloon < g_MinBloonHealth)
			randomBloon = g_MinBloonHealth;
		else if (randomBloon > g_MaxBloonHealth)
			randomBloon = g_MaxBloonHealth;

		bloonsHpToSpawn -= GetBloonFromIndex(randomBloon - 1).hp;

		//Add random bloon to buffer array
		++arrBloonsToSpawn[randomBloon - 1];
		++g_TotalAmountOfBloons;
	}

	//Insert random bloons into spawn queue
	g_ArrBloons = new Bloon[g_TotalAmountOfBloons]{};
	int bloonIndex{};
	for (int textureIndex = 0; textureIndex < g_AmountOfBloonsTextures; textureIndex++)
	{
		while (arrBloonsToSpawn[textureIndex] > 0)
		{
			if (bloonIndex >= g_TotalAmountOfBloons)
			{
				std::cout << "ERROR! Reading non-accessable memory!\n";
				break;
			}

			g_ArrBloons[bloonIndex] = GetBloonFromIndex(textureIndex);

			//Spawn Bloon
			SpawnBloon(g_SpawnPoint, g_ArrBloons[bloonIndex], bloonIndex);
			++bloonIndex;
			--arrBloonsToSpawn[textureIndex];
		}
	}

	delete[] arrBloonsToSpawn;
}

void SpawnBloon(const Point2f& spawnPoint, Bloon& bloon, int index)
{
	Point2f startDirection{ g_Path[0].x - spawnPoint.x,
		g_Path[0].y - spawnPoint.y };
	NormalizeVector(startDirection);

	const float randomDistance{ g_ArrBloonsTextures[bloon.bloonTextureId].width * 2 / g_CurrentWave };
	const float horizontalOffset{ startDirection.x * (g_ArrBloonsTextures[bloon.bloonTextureId].width + GetRand(0.f, randomDistance)) * (index + 1) };

	bloon.location = Point2f{ spawnPoint.x - horizontalOffset,
		spawnPoint.y };
}
void DrawBloons()
{
	for (int index = 0; index < g_TotalAmountOfBloons; ++index) {
		if (g_ArrBloons[index].bloonTextureId == -1) { continue; }

		const Point2f drawLocation{
			g_ArrBloons[index].location.x + g_ArrBloonsTextures[g_ArrBloons[index].bloonTextureId].width * 0.5f,
			g_ArrBloons[index].location.y + g_ArrBloonsTextures[g_ArrBloons[index].bloonTextureId].width * 0.5f
		};

		const Circlef bloonCollider{
			g_ArrBloons[index].location.x + g_ArrBloonsTextures[g_ArrBloons[index].bloonTextureId].width,
			g_ArrBloons[index].location.y + g_ArrBloonsTextures[g_ArrBloons[index].bloonTextureId].width,
			g_ArrBloonsTextures[g_ArrBloons[index].bloonTextureId].width * 0.5f
		};

		utils::DrawTexture(g_ArrBloonsTextures[g_ArrBloons[index].bloonTextureId], drawLocation);
		utils::DrawEllipse(bloonCollider.center, bloonCollider. radius, bloonCollider.radius);
		utils::FillEllipse(drawLocation, 5.f, 5.f);
		utils::FillEllipse(bloonCollider.center, 5.f, 5.f);
	}
}
void UpdateBloons(float elapsedSec)
{
	for (int index = 0; index < g_TotalAmountOfBloons; ++index) 
	{
		
		if (g_ArrBloons[index].hp <= 0) {
			DestroyBloon(g_ArrBloons[index]);
			continue;
		}
		DamageBloon(g_ArrBloons[index]);

		float distance{ GetDistance(g_ArrBloons[index].location, g_Path[g_ArrBloons[index].currentNavigationPointId])  };

		if (GetDistance(g_ArrBloons[index].location, g_Path[g_PathWaypointAmount - 1]) < g_ArrBloons[index].speed * elapsedSec) {
			DestroyBloon(g_ArrBloons[index]);
		}

		Point2f normalVector{
			(g_Path[g_ArrBloons[index].currentNavigationPointId].x - g_ArrBloons[index].location.x) / distance,
			(g_Path[g_ArrBloons[index].currentNavigationPointId].y - g_ArrBloons[index].location.y) / distance
		};

		g_ArrBloons[index].location.x += normalVector.x * g_ArrBloons[index].speed * elapsedSec;
		g_ArrBloons[index].location.y += normalVector.y * g_ArrBloons[index].speed * elapsedSec;

		if (distance < g_ArrBloons[index].speed * elapsedSec)
		{
			++g_ArrBloons[index].currentNavigationPointId;
		}
	}
}
void DestroyBloon(Bloon& bloon)
{
	bloon = nullBloon;
}
void DamageBloon(Bloon& bloon) {
	const Point2f BloonPosition = bloon.location;
	const int BloonNavigationPoint = bloon.currentNavigationPointId;
	bloon = GetBloonFromIndex(bloon.hp-1);
	bloon.currentNavigationPointId = BloonNavigationPoint;
	bloon.location = BloonPosition;
}

void PlaceMonkey(const Point2f& position, const Monkey& monkey)
{
	Monkey* tempArrayMonkey = new Monkey[g_MonkeysOnBoard + 1]{};



	//copies projectiles and monkeys on board to a new array so we can raise the max amount of them on board
	for (int index = 0; index < g_MonkeysOnBoard; ++index) {
		tempArrayMonkey[index] = g_ArrMonkeys[index];
	}

	//setup the new monkey
	tempArrayMonkey[g_MonkeysOnBoard] = monkey;
	tempArrayMonkey[g_MonkeysOnBoard].position = position;

	//transfer the arrays
	++g_MonkeysOnBoard;
	delete[] g_ArrMonkeys;
	g_ArrMonkeys = tempArrayMonkey;
	g_IsPreviewOn = false;

	//adds monkeys to the array, and determines how many projectiles can be on board based on projectile lifetime and amount of monkeys
	g_MaxProjectilesOnBoard = 0;
	for (int index = 0; index < g_MonkeysOnBoard; ++index) {
		int scalar{};
		const float projectilesCooldown{ 1 / g_ArrMonkeys[index].fireRate };
		g_ArrMonkeys[index].projectile.behaviour == ProjectileBehaviour::Tack ? scalar = g_TackCount : scalar = 1;

		g_MaxProjectilesOnBoard += ceilf(g_ArrMonkeys[index].projectile.lifetime / projectilesCooldown * 0.001f) * scalar;
	}

	//projecttiles
	Projectile* tempProjectileArray = new Projectile[g_MaxProjectilesOnBoard];

	for (int index = 0; index < g_ProjectilesOnBoardAmount; ++index)
	{
		tempProjectileArray[index] = g_ArrProjectiles[index];
	}

	//removes appropriate amount of money from players wallet
	g_Money -= g_ArrUIMonkeyPrices[monkey.monkeyId];

	delete[] g_ArrProjectiles;
	g_ArrProjectiles = tempProjectileArray;
}
void DrawMonkeys()
{
	for (int index = 0; index < g_MonkeysOnBoard; ++index) {
		const Texture monkeyTexture = g_ArrMonkeyTextures[g_ArrMonkeys[index].monkeyId * g_AmountOfUpgradesPerMonkey + g_ArrMonkeys[index].monkeyUpgradeTier];
		const Point2f placementPosition{
			g_ArrMonkeys[index].position.x - monkeyTexture.width * 0.5f,
			g_ArrMonkeys[index].position.y - monkeyTexture.height * 0.5f
		};
		const float angle{ atan2f(g_ArrMonkeys[index].targetPosition.y - (placementPosition.y + monkeyTexture.height * 0.5f),
			g_ArrMonkeys[index].targetPosition.x - (placementPosition.x + monkeyTexture.width * 0.5f)) * g_Rad2Deg - 90 };
		DrawTexture(monkeyTexture, placementPosition, angle);
		utils::SetColor(1.f, 1.f, 1.f, 1.f);
		utils::DrawEllipse(g_ArrMonkeys[index].position, g_ArrMonkeys[index].detectRadius, g_ArrMonkeys[index].detectRadius);
	}
}
void DrawPreviewMonkey()
{


	const Point2f previewTopLeft{ g_MousePosition.x - g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2].width / 2,
		g_MousePosition.y - g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2].height / 2 };

	if (g_CanPlaceMonkey) {
		DrawTexture(g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2], previewTopLeft);
	}
	else {
		DrawTexture(g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2 + 1], previewTopLeft);
	}

}
void UpdateMonkey(float elapsedSec)
{
	//Searches for any bloon within detection range
	//TODO: Check if it is possible to target Bloon which is the closest to the end point and within range
	for (int index = 0; index < g_MonkeysOnBoard; ++index)
	{
		if (g_ArrMonkeys[index].cooldownTimer > 0) {
			g_ArrMonkeys[index].cooldownTimer -= elapsedSec;
			continue;
		}
		else {
			g_ArrMonkeys[index].cooldownTimer = 0;
		}

		Circlef monkeyDetectCollider{
			g_ArrMonkeys[index].position.x,
			g_ArrMonkeys[index].position.y,
			g_ArrMonkeys[index].detectRadius
		};

		for (int bloonIdx = 0; bloonIdx < g_TotalAmountOfBloons; ++bloonIdx) {
			if (g_ArrBloons[bloonIdx].hp <= 0) continue;

			Circlef bloonCollider{
			g_ArrBloons[bloonIdx].location.x + g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width,
			g_ArrBloons[bloonIdx].location.y + g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width,
			g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width * 0.5f
			};
			if (IsOverlapping(monkeyDetectCollider, bloonCollider)) {
				InitProjectiles(g_ArrMonkeys[index].position, bloonCollider.center, g_ArrMonkeys[index].projectile);
				//TODO: Add actual shooting
				g_ArrMonkeys[index].cooldownTimer = 1.f / g_ArrMonkeys[index].fireRate;
				g_ArrMonkeys[index].targetPosition = bloonCollider.center;
				break;
			}

		}
	}
}

void InitProjectiles(const Point2f& source, const Point2f& destination, const Projectile& projectile)
{
	if (!(projectile.behaviour == ProjectileBehaviour::Tack))
	{
		//Creates a new projectile
		Projectile newProjectile = projectile;
		newProjectile.position = source;
		newProjectile.origin = source;

		Point2f directionVector{
		destination.x - source.x,
		destination.y - source.y
		};
		NormalizeVector(directionVector);

		newProjectile.direction = directionVector;

		g_ArrProjectiles[g_ProjectilesOnBoardAmount] = newProjectile;
		++g_ProjectilesOnBoardAmount;
	}
	else
	{
		float tackAngle{};
		for (int i = 0; i < g_TackCount; ++i)
		{
			//Creates a new projectile
			Projectile newProjectile = projectile;
			newProjectile.position = source;
			newProjectile.origin = source;

			Point2f directionVector{
			cosf(tackAngle),
			sinf(tackAngle)
			};

			newProjectile.direction = directionVector;
			g_ArrProjectiles[g_ProjectilesOnBoardAmount] = newProjectile;
			++g_ProjectilesOnBoardAmount;
			tackAngle += 2.f * g_Pi / g_TackCount;
		}
	}
}
void DrawProjectiles()
{
	for (int index = 0; index < g_ProjectilesOnBoardAmount; ++index) {
		const Point2f centerOfProjectile{
			g_ArrProjectiles[index].position
		};
		const Texture projectileTexture{
			g_ArrProjectileTextures[g_ArrProjectiles[index].spriteId]
		};
		const Rectf projectileTexturePosition{
			centerOfProjectile.x - projectileTexture.width * 0.5f,
			centerOfProjectile.y - projectileTexture.height * 0.5f,
			projectileTexture.width,
			projectileTexture.height
		};
		const float angle{ atan2f(g_ArrProjectiles[index].direction.y, g_ArrProjectiles[index].direction.x) * g_Rad2Deg };

		const float colliderRadius{ g_ArrProjectiles[index].radius };

		utils::SetColor(1.f, 1.f, 1.f, 1.f);
		utils::DrawEllipse(centerOfProjectile, colliderRadius, colliderRadius);
		utils::DrawTexture(projectileTexture, projectileTexturePosition, angle);
	}
}
void DeleteProjectile(Projectile& projectile) {
	projectile = nullProjectile;
	--g_ProjectilesOnBoardAmount;
}
void UpdateProjectiles(float elapsedSec)
{

	for (int projectileIdx = 0; projectileIdx < g_ProjectilesOnBoardAmount; ++projectileIdx) {

		g_ArrProjectiles[projectileIdx].timer += elapsedSec * 1000;

		if (g_ArrProjectiles[projectileIdx].timer >= g_ArrProjectiles[projectileIdx].lifetime) {
			SwapProjectilesInArray(g_ArrProjectiles[projectileIdx], g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			DeleteProjectile(g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			continue;
		}

		if (g_ArrProjectiles[projectileIdx].spriteId == -1) {
			continue;
		}

		switch (g_ArrProjectiles[projectileIdx].behaviour)
		{
		case ProjectileBehaviour::Tack:
		case ProjectileBehaviour::Dart:
			g_ArrProjectiles[projectileIdx].position = Point2f{
				g_ArrProjectiles[projectileIdx].position.x + g_ArrProjectiles[projectileIdx].speed * elapsedSec * g_ArrProjectiles[projectileIdx].direction.x,
				g_ArrProjectiles[projectileIdx].position.y + g_ArrProjectiles[projectileIdx].speed * elapsedSec * g_ArrProjectiles[projectileIdx].direction.y
			};
			break;
		case ProjectileBehaviour::Boomerang:
			const float angle{ g_Pi + atan2f(g_ArrProjectiles[projectileIdx].direction.y, g_ArrProjectiles[projectileIdx].direction.x) };
			g_ArrProjectiles[projectileIdx].position = Point2f{
				g_ArrProjectiles[projectileIdx].origin.x + g_ArrProjectiles[projectileIdx].direction.x * g_BoomerangSwingRadius + 
					g_BoomerangSwingRadius * cosf(angle + 2 * g_Pi * g_ArrProjectiles[projectileIdx].timer * 0.001f * g_ArrProjectiles[projectileIdx].speed),
				g_ArrProjectiles[projectileIdx].origin.y + g_ArrProjectiles[projectileIdx].direction.y * g_BoomerangSwingRadius + 
					g_BoomerangSwingRadius * sinf(angle + 2 * g_Pi * g_ArrProjectiles[projectileIdx].timer * 0.001f * g_ArrProjectiles[projectileIdx].speed)
			};
			break;
		}

		//TODO: Add detection collison for Bloons and damaging them

		for (int bloonIdx = 0; bloonIdx < g_TotalAmountOfBloons; ++bloonIdx) {

			if (g_ArrBloons[bloonIdx].bloonTextureId == -1) {
				continue;
			}

			const Circlef projectileCollider{
			g_ArrProjectiles[projectileIdx].position.x + g_ArrProjectiles[projectileIdx].radius * 0.5f,
			g_ArrProjectiles[projectileIdx].position.y + g_ArrProjectiles[projectileIdx].radius * 0.5f,
			g_ArrProjectiles[projectileIdx].radius
			};
			const Circlef bloonCollider{
			g_ArrBloons[bloonIdx].location.x + g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width,
			g_ArrBloons[bloonIdx].location.y + g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width,
			g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width * 0.5f
			};

			if (IsOverlapping(projectileCollider, bloonCollider)) {
				g_Money += g_ArrBloons[bloonIdx].hp;
				g_ArrBloons[bloonIdx].hp -= g_ArrProjectiles[projectileIdx].damage;
				SwapProjectilesInArray(g_ArrProjectiles[projectileIdx], g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
				DeleteProjectile(g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
				
				break;
			}
		}

	}
}
void SwapProjectilesInArray(Projectile& proj1, Projectile& proj2)
{
	const Projectile tempProj = proj1;
	proj1 = proj2;
	proj2 = tempProj;
}

int GetRand(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}
float GetRand(float start, float end)
{
	float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
	return round((start + random * (end - start)) * 100.f) / 100.f;
}

Bloon GetBloonFromIndex(int index)
{
	switch (index)
	{
		case 0:
			return redBloon;
			break;
		case 1:
			return blueBloon;
			break;
		case 2:
			return greenBloon;
			break;
		case 3:
			return yellowBloon;
			break;
		default:
			std::cout << "Incorrent Bloon Index\n";
			return redBloon;
			break;

		//add cases as more bloons are added
	}
}
Monkey GetMonkeyFromIndex(int index)
{
	switch (index)
	{
	case 0:
		return dartMonkey;
		break;
	case 1:
		return boomerangMonkey;
		break;
	case 2:
		return tackShooter;
		break;
	default:
		std::cout << "Incorrent Monkey Index\n";
		return dartMonkey;
		break;

		//add cases as more monkeys are added
	}
}

void DrawUI()
{
	const float UIButtonsVerticalOffset{ g_WindowHeight / g_AmountOfMonkeyBuyButtons };
	const Point2f UITopLeft{ g_UIHorizontalOffset + g_WindowWidth - g_TextUIBackground.width, 0 };
	const Point2f UITopCenter{ g_UIHorizontalOffset + g_WindowWidth - g_TextUIBackground.width / 2.f, 0};

	DrawTexture(g_TextUIBackground, UITopLeft);

	//Draw Buttons
	for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
	{
		const Point2f ButtonTopLeft{ UITopCenter.x - g_ArrUIMonkeyBuyButtons[i].rect.width / 2, UIButtonsVerticalOffset * i };
		const Point2f TextTopLeft{ UITopCenter.x - g_ArrUIMonkeyTextButtons[i].width / 2, 
			UIButtonsVerticalOffset* i + g_ArrUIMonkeyBuyButtons[i].rect.height };

		g_ArrUIMonkeyBuyButtons[i].rect.left = ButtonTopLeft.x;
		g_ArrUIMonkeyBuyButtons[i].rect.top = ButtonTopLeft.y;

		DrawTexture(g_ArrUIMonkeyBuyButtons[i].texture, ButtonTopLeft);
		DrawTexture(g_ArrUIMonkeyTextButtons[i], TextTopLeft);
	}
}
void UpdateUI(float elapsedSec)
{
	const float transitionSpeedScalar{ 1.5f };

	if (!g_IsUIActive)
	{
		if (g_UIConstantShiftTransition == g_TextUIBackground.width)
			return;

		g_UIConstantShiftTransition += g_TextUIBackground.width * transitionSpeedScalar * elapsedSec;

		if (g_UIConstantShiftTransition > g_TextUIBackground.width)
			g_UIConstantShiftTransition = g_TextUIBackground.width;

		const float t{ g_UIConstantShiftTransition / g_TextUIBackground.width };
		g_UIHorizontalOffset = g_TextUIBackground.width * powf(t, 0.65f);
	}
	else
	{
		if (g_UIConstantShiftTransition == 0)
			return;
		
		g_UIConstantShiftTransition -= g_TextUIBackground.width * transitionSpeedScalar * elapsedSec;

		if (g_UIConstantShiftTransition < 0)
			g_UIConstantShiftTransition = 0;
		
		const float t{ g_UIConstantShiftTransition / g_TextUIBackground.width };
		g_UIHorizontalOffset = g_TextUIBackground.width * powf(t, 2);
	}
}
void UpdateUIButtonCollisions()
{
	for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
	{
		g_ArrUIMonkeyBuyButtons[i].isHoveringOver = false;

		if (IsPointInRect(g_ArrUIMonkeyBuyButtons[i].rect, g_MousePosition) && g_Money>=g_ArrUIMonkeyPrices[i])
		{
			g_ArrUIMonkeyBuyButtons[i].isHoveringOver = true;
			return;
		}
	}
}

void NormalizeVector(Point2f& vector)
{
	const float length{ GetDistance(vector, Point2f{ 0, 0 }) };
	vector.x /= length;
	vector.y /= length;
	
}
bool IsRectCollidingWithPath(const Rectf& rectangle)
{
	for (int row = 0; row < g_Rows; ++row) {
		for (int col = 0; col < g_Cols; ++col) {
			const Rectf currentgridRect{
				col * g_CellSize.x,
				row * g_CellSize.y,
				g_CellSize.x,
				g_CellSize.y
			};
			
			if (g_BoardGrid[row * g_Cols + col] != 0 && IsOverlapping(rectangle, currentgridRect)) { 
				return true; 
			}
		}
	}

	return false;
}
bool IsCircleCollidingWithPath(const Circlef& circle) {
	for (int row = 0; row < g_Rows; ++row) {
		for (int col = 0; col < g_Cols; ++col) {
			const Rectf currentgridRect{
				col * g_CellSize.x,
				row * g_CellSize.y,
				g_CellSize.x,
				g_CellSize.y
			};

			if (g_BoardGrid[row * g_Cols + col] != 0 && IsOverlapping(currentgridRect, circle)) {
				return true;
			}
		}
	}
	return false;
}
#pragma endregion ownDefinitions