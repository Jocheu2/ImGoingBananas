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

	//Grass, paths
	for (int i = 0; i < g_AmountOfGrassTextures; ++i)
	{
		if (!TextureFromFile("Resources/Tiles/G" + std::to_string(i) + ".png", g_ArrGrassTextures[i]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}
	}

	for (int i = 0; i < g_AmountOfPathTextures; ++i)
	{
		if (!TextureFromFile("Resources/Tiles/P" + std::to_string(i) + ".png", g_ArrPathTextures[i]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}
	}

	if (!TextureFromFile("Resources/Tiles/PS0.png", g_StonePathTexture))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
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

	for (int i = 0; i < g_AmountOfUpgradesPerMonkey; ++i)
	{
		if (!TextureFromString("Upgrade: " + std::to_string(i + 1) + " / " + std::to_string(g_AmountOfUpgradesPerMonkey), "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{1, 1, 1, 1}, g_ArrUIUpgradeText[i]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}
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
	}if (!TextureFromFile("Resources/UI/nextWave.png", g_NextWaveBtn.texture)) {
		std::cout << "ERROR! Failed to load the texture!\n";
	}if (!TextureFromFile("Resources/UI/nextWave02.png", g_NextWaveBtn2)) {
		std::cout << "ERROR! Failed to load the texture!\n";
	}if (!TextureFromFile("Resources/UI/startWave.png", g_StartWaveBtn)) {
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	g_NextWaveBtn.rect.width = g_NextWaveBtn.texture.width;
	g_NextWaveBtn.rect.height = g_NextWaveBtn.texture.height;

	if (!TextureFromFile("Resources/UI/buyUpgradeBtn.png", g_ArrBuyUpgradeBtn[0].texture))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	g_ArrBuyUpgradeBtn[0].rect.width = g_ArrBuyUpgradeBtn[0].texture.width;
	g_ArrBuyUpgradeBtn[0].rect.height = g_ArrBuyUpgradeBtn[0].texture.height;

	if (!TextureFromFile("Resources/UI/maxUpgradeBtn.png", g_ArrBuyUpgradeBtn[1].texture))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	g_ArrBuyUpgradeBtn[1].rect.width = g_ArrBuyUpgradeBtn[1].texture.width;
	g_ArrBuyUpgradeBtn[1].rect.height = g_ArrBuyUpgradeBtn[1].texture.height;

	if (!TextureFromFile("Resources/UI/sellMonkeyBtn.png", g_SellMonkeyBtn.texture))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	g_SellMonkeyBtn.rect.width = g_SellMonkeyBtn.texture.width;
	g_SellMonkeyBtn.rect.height = g_SellMonkeyBtn.texture.height;

	if (!TextureFromFile("Resources/UI/buttonUIClose.png", g_TextUICloseBtn.texture))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	g_TextUICloseBtn.rect.width = g_TextUICloseBtn.texture.width;
	g_TextUICloseBtn.rect.height = g_TextUICloseBtn.texture.height;

	if (!TextureFromFile("Resources/UI/buttonUIOpen.png", g_TextUIOpenBtn.texture))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	g_TextUIOpenBtn.rect.width = g_TextUIOpenBtn.texture.width;
	g_TextUIOpenBtn.rect.height = g_TextUIOpenBtn.texture.height;

	//Main Menu
	if (!TextureFromFile("Resources/UI/mainMenuBG.png", g_MainMenuBG))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	if (!TextureFromFile("Resources/UI/banana.png", g_MainMenuBanana))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	if (!TextureFromFile("Resources/UI/bananaGlow.png", g_MainMenuBananaGlow))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	if (!TextureFromFile("Resources/UI/startGameBtn.png", g_StartGameButton.texture))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	g_StartGameButton.rect.width = g_StartGameButton.texture.width;
	g_StartGameButton.rect.height = g_StartGameButton.texture.height;

	if (!TextureFromString("Select Map", "Resources/Fonts/Calistoga-Regular.ttf", g_TitleFontSize, Color4f{ 1, 1, 1, 1 }, g_SelectMapTitle))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	//Map previews
	for (int i = 0; i < g_AmountOfMaps; ++i)
	{
		if (!TextureFromFile("Resources/MapPreviews/" + std::to_string(i) + ".png", g_ArrMapsButtons[i].texture))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}
	}

	if (!TextureFromString("Monkey Meadows", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_ArrMapsNames[0]))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	if (!TextureFromString("Banana Patch", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_ArrMapsNames[1]))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}
	if (!TextureFromString("West-Vlaanderen", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_ArrMapsNames[2]))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	//Current wave and hp
	if (!TextureFromString("Current wave: ", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_CurrentWaveText))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	if (!TextureFromString("HP ", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{ 1, 1, 1, 1 }, g_CurrentHpText))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	//Font numbers
	for (int i = 0; i < 10; ++i)
	{
		if (!TextureFromString(std::to_string(i), "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{1, 1, 1, 1}, g_ArrNumbers[i]))
		{
			std::cout << "ERROR! Failed to load the texture!\n";
		}

		g_AverageNumbersHeight += g_ArrNumbers[i].height;
	}

	g_AverageNumbersHeight /= 10.f;

	if (!TextureFromString("$", "Resources/Fonts/Calistoga-Regular.ttf", g_FontSize, Color4f{1, 1, 1, 1}, g_MoneyIcon))
	{
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	
	if (!TextureFromFile("Resources/UI/lose.png", g_TextureLosing)) {
		std::cout << "ERROR! Failed to load the texture!\n";
	}

	
  
  //Turn off 'g_IsMainMenuActive' for debugging purposes
	//StartGame();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	if (!g_IsMainMenuActive)
	{
		DrawBoard();
    if (g_PlayerHp > 0) {
		DrawBloons();
		DrawMonkeys();
		DrawProjectiles();
		DrawUI();

		if (g_IsPreviewOn)
		{
			DrawPreviewMonkey();
		}
	  }
    else {
        DrawLosingScreen();
    }
  }
	else
	{
		DrawMainMenu();
	}
}

void Update(float elapsedSec)
{
	if (!g_IsMainMenuActive)
	{
		if (g_PlayerHp > 0) {
			UpdateUIShopMenu(elapsedSec);
			UpdateUIUpgradeMenu(elapsedSec);
			UpdateUINextWave(elapsedSec);
			UpdateMonkey(elapsedSec);
			UpdateProjectiles(elapsedSec);
			UpdateBloons(elapsedSec);
		}
    else {
        g_LosingAnimationProgress += 0.2 * elapsedSec;
    }
  }
	else 
    {
		UpdateMainMenu(elapsedSec);
	}
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

	for (int i = 0; i < g_AmountOfGrassTextures; ++i)
	{
		DeleteTexture(g_ArrGrassTextures[i]);
	}

	for (int i = 0; i < g_AmountOfPathTextures; ++i)
	{
		DeleteTexture(g_ArrPathTextures[i]);
	}

	//Delete information on pierced bloons from existing projectiles
	for (int i{}; i < g_ProjectilesOnBoardAmount; ++i) { 
		DeletePiercedBloonIds(g_ArrProjectiles[i]);
	}
	for (int i = 0; i < g_AmountOfUpgradesPerMonkey; ++i)
	{
		DeleteTexture(g_ArrUIUpgradeText[i]);
	}

	for (int i = 0; i < 10; ++i)
	{
		DeleteTexture(g_ArrNumbers[i]);
	}

	for (int i = 0; i < g_AmountOfMaps; ++i)
	{
		DeleteTexture(g_ArrMapsButtons[i].texture);
		DeleteTexture(g_ArrMapsNames[i]);
	}

	DeleteTexture(g_StonePathTexture);
	DeleteTexture(g_TextUICloseBtn.texture);
	DeleteTexture(g_TextUIOpenBtn.texture);
	DeleteTexture(g_ArrBuyUpgradeBtn[0].texture);
	DeleteTexture(g_ArrBuyUpgradeBtn[1].texture);
	DeleteTexture(g_SellMonkeyBtn.texture);
	DeleteTexture(g_MoneyIcon);
	DeleteTexture(g_NextWaveBtn.texture);
	DeleteTexture(g_NextWaveBtn2);
	DeleteTexture(g_MainMenuBG);
	DeleteTexture(g_MainMenuBanana);
	DeleteTexture(g_MainMenuBananaGlow);
	DeleteTexture(g_StartGameButton.texture);
	DeleteTexture(g_SelectMapTitle);
	DeleteTexture(g_TextureLosing);
	DeleteTexture(g_StartWaveBtn);
	DeleteTexture(g_CurrentWaveText);
	DeleteTexture(g_CurrentHpText);

	
	delete[] g_ArrMonkeys;
	if (g_ArrBloons != nullptr) {
		delete[] g_ArrBloons;
	}
	delete[] g_Path;
	delete[] g_ArrProjectiles;

	if (g_BoardTextures != nullptr)
	{
		delete[] g_BoardTextures;
	}
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	if (key == SDLK_r) {
		RestartGame();
	}

	if (key == SDLK_i) {
		std::cout << "\033[33m Welcome to 'I'm going Bananas! Your goal is to not let any of bloons on board reach your base\n";
		std::cout << "You can open menu to buy monkeys by pressing the 'TAB' key. Don't forget to keep enough money for it!\n";
		std::cout << "To exit preview mode, press 'esc' key\n";
		std::cout << "You may upgrade by selecting a monkey already on field and pressing UPGRAGE button!\n";
		std::cout << "To close upgrade menu, click the game window anywhere else than the upgrade screen\n";
		std::cout << "You may also sell the monkey to refund a part of the cost and free up the space on board!\n";
		std::cout << "To return to main menu use the 'm' key or retry the stage from beginning by pressing the 'r' key\n";
		std::cout << "Good luck \n\n This Project was Developed by The Them (Joachim Psuty-Lipski and Egor Tatarli) from group GD14 \033[0m\n";
	}
}

void OnKeyUpEvent(SDL_Keycode key)
{
	//UI
	if (key == SDLK_TAB)
	{
		g_IsUIActive = !g_IsUIActive;
	}

	//Preview and Selecting maps
	if (key == SDLK_ESCAPE)
	{
		g_IsPreviewOn = false;
		g_IsSelectingMap = false;
	}

	if (key == SDLK_m) {
		RestartGame();
		g_IsMainMenuActive = true;
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

	const Circlef previewMonkeyCirclef{
		mousePos.x,
		mousePos.y,
		g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId].height * 0.25f
	};

	//Check for collisions with path and other monkeys
	g_CanPlaceMonkey = false;
	if (!IsCircleCollidingWithPath(previewMonkeyCirclef))
	{
		g_CanPlaceMonkey = true;
		for (int i = 0; i < g_MonkeysOnBoard; ++i)
		{
			const Circlef monkeyCollider{
				g_ArrMonkeys[i].position,
				g_ArrMonkeys[i].colliderRadius
			};

			if (IsOverlapping(previewMonkeyCirclef, monkeyCollider))
			{
				g_CanPlaceMonkey = false;
				break;
			}
		}
	}
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	if (e.button != SDL_BUTTON_LEFT || g_IsMainMenuActive)
		return;

	Point2f mousePosition{
	static_cast<float>(e.x),
	static_cast<float>(e.y)
	};

	if(g_CanPlaceMonkey && g_IsPreviewOn) PlaceMonkey(mousePosition, GetMonkeyFromIndex(g_PreviewMonkeyId));
	
	if (g_CanPlaceMonkey && g_IsPreviewOn) 
	{
		PlaceMonkey(mousePosition, GetMonkeyFromIndex(g_PreviewMonkeyId));
		g_IsUIActive = true;
		return;
	}

	if (!g_IsPreviewOn)
	{
		const Rectf upgradesUIBG{ 0, g_WindowHeight - g_UpgradesBGHeight, g_UIBackgroundWidth, g_UpgradesBGHeight };

		if(g_IsMonkeySelected && !IsPointInRect(upgradesUIBG, g_MousePosition))
			g_IsMonkeySelected = false;

		//Check for clicks on monkeys
		for (int i = 0; i < g_MonkeysOnBoard; ++i)
		{
			if (g_IsMonkeySelected && IsPointInRect(upgradesUIBG, g_MousePosition))
				break;

			const Circlef monkeyCollider{
				g_ArrMonkeys[i].position,
				g_ArrMonkeys[i].colliderRadius
			};

			if (IsPointInCircle(monkeyCollider, g_MousePosition))
			{
				if (g_IsUIActive && g_MousePosition.x > g_WindowWidth - g_UIBackgroundWidth)
					break;

				g_IsMonkeySelected = true;
				g_SelectedMonkeyId = i;
				break;
			}
		}
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	if (e.button == SDL_BUTTON_LEFT)
	{
		if (!g_IsMainMenuActive)
		{
			UpdateUIButtonCollisions();

			if (g_IsUIActive)
			{
				//Check if user clicked on buy buttons
				for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
				{
					if (!g_ArrUIMonkeyBuyButtons[i].isHoveringOver)
						continue;

					g_PreviewMonkeyId = i;
					g_IsPreviewOn = true;
					g_IsUIActive = false;
					return;
				}

				//Check if user clicked on close UI button
				if (g_TextUICloseBtn.isHoveringOver) 
				{
					g_IsUIActive = false;
				}
			}
			else if(g_TextUIOpenBtn.isHoveringOver)
			{
				//Check if user clicked on open UI button
				g_IsUIActive = true;
			}

			//TODO: add upgrade button collision detection alongside upgrading the actual monkey
			if (g_IsMonkeySelected && g_ArrBuyUpgradeBtn[0].isHoveringOver)
			{
				Monkey* monkey{ &g_ArrMonkeys[g_SelectedMonkeyId] };

				if ((*monkey).monkeyUpgradeTier > g_AmountOfUpgradesPerMonkey - 2)
				{
					std::cout << "Error! Trying to read some memory! Cannot upgrade monkey.";
					return;
				}

				MonkeyUpgrade upgrade{ GetMonkeyUpgradesFromIndex((*monkey).monkeyId)[(*monkey).monkeyUpgradeTier] };

				if (g_Money >= upgrade.cost)
				{
					//upgrade
					Projectile* projectile{ &(*monkey).projectile };

					(*monkey).fireRate += upgrade.fireRate;
					(*monkey).detectRadius += upgrade.detectRadius;
					(*monkey).monkeyUpgradeTier++;
					(*monkey).moneySpent += upgrade.cost;
					(*projectile).damage += upgrade.damage;
					(*projectile).radius += upgrade.radius;
					(*projectile).homingRadius += upgrade.homeRadius;
					(*projectile).maxPierce += upgrade.pierce;
					(*projectile).speed += upgrade.speed;
					(*projectile).lifetime += upgrade.lifetime;

					if(upgrade.swapSpriteId != -1) (*projectile).spriteId = upgrade.swapSpriteId;
					if(upgrade.swapBehaviour != ProjectileBehaviour::None) (*projectile).behaviour = upgrade.swapBehaviour;

					ResizeProjectileArray();

					g_Money -= upgrade.cost;
				}
				else
				{
					std::cout << "Not enough funds to upgrade monkey! (" + std::to_string(g_Money) + "$ out of " + std::to_string(upgrade.cost) + "$ needed)\n";
				}
			}

			if (g_IsMonkeySelected && g_SellMonkeyBtn.isHoveringOver)
			{
				// sell monkey heh
				g_Money += g_ArrMonkeys[g_SelectedMonkeyId].moneySpent * g_ReturnCostCoefficient;
				DestroyMonkey(g_SelectedMonkeyId);
				g_IsMonkeySelected = false;
				g_SelectedMonkeyId = 0;
			}
    
			if (g_NextWaveBtn.isHoveringOver) {
				StartWave();
				g_IsSecretRolled = false;
			}
		}
		else
		{
			UpdateMainMenuButtonsCollision();
			if (!g_IsSelectingMap)
			{
				if (g_StartGameButton.isHoveringOver)
				{
					g_IsSelectingMap = true;
				}
			}
			else
			{
				for (int i = 0; i < g_AmountOfMaps; ++i)
				{
					if (g_ArrMapsButtons[i].isHoveringOver)
					{
						g_CurrentMapIndex = i;
						g_ArrMapsButtons[i].isHoveringOver = false;
						g_IsSelectingMap = false;
						g_IsMainMenuActive = false;
						StartGame();
					}
				}
			}
		}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawMainMenu()
{
	// Main Menu
	DrawTexture(g_MainMenuBG, Point2f{});

	const Point2f bananaGlowTopLeft{ g_WindowWidth * 0.5f - g_MainMenuBananaGlow.width * 0.5f,
		g_WindowHeight * 0.52f - g_MainMenuBananaGlow.height * 0.45f + g_MainMenuBananaVerticalOffset };
	DrawTexture(g_MainMenuBananaGlow, bananaGlowTopLeft, g_MainMenuBananaGlowRotation);

	const Point2f bananaTopLeft{ g_WindowWidth * 0.5f - g_MainMenuBanana.width * 0.5f,
		g_WindowHeight * 0.52f - g_MainMenuBanana.height * 0.5f + g_MainMenuBananaVerticalOffset };
	DrawTexture(g_MainMenuBanana, bananaTopLeft);

	const Point2f startGameBtnTopLeft{ g_WindowWidth * 0.5f - g_StartGameButton.rect.width * 0.5f,
		g_WindowHeight - g_StartGameButton.rect.height * 2 };
	DrawTexture(g_StartGameButton.texture, startGameBtnTopLeft);
	g_StartGameButton.rect.left = startGameBtnTopLeft.x;
	g_StartGameButton.rect.top = startGameBtnTopLeft.y;

	// Map selection screen
	if (!g_IsSelectingMap)
		return;

	const float selectingMapBGWidth{ 800 };
	const float selectingMapBGHeight{ 400 };
	const Rectf selectingMapBGRect{ g_WindowWidth * 0.5f - selectingMapBGWidth * 0.5f, g_WindowHeight * 0.5f - selectingMapBGHeight * 0.5f,
		selectingMapBGWidth, selectingMapBGHeight };
	const Color4f selectingMapBGColor{ 0, 0, 0, 0.8f };

	utils::SetColor(selectingMapBGColor);
	utils::FillRect(selectingMapBGRect);

	const Point2f selectMapTitleTopLeft{ g_WindowWidth * 0.5f - g_SelectMapTitle.width * 0.5f, selectingMapBGRect.top + g_SelectMapTitle.height * 0.1f };
	DrawTexture(g_SelectMapTitle, selectMapTitleTopLeft);

	const float mapButtonsOffset{ selectingMapBGWidth / g_AmountOfMaps };
	const float mapButtonsScale{ 0.3f };
	Point2f mapButtonsStartPos{ selectingMapBGRect.left + mapButtonsOffset * 0.5f, g_WindowHeight * 0.5f };

	for (int i = 0; i < g_AmountOfMaps; ++i)
	{
		// Map button
		const UIButton mapButton{ g_ArrMapsButtons[i] };
		const Rectf mapRect{ mapButtonsStartPos.x - mapButton.texture.width * 0.5f * mapButtonsScale + mapButtonsOffset * i,
			mapButtonsStartPos.y - mapButton.texture.height * 0.5f * mapButtonsScale,
			mapButton.texture.width * mapButtonsScale,
			mapButton.texture.height * mapButtonsScale };
		g_ArrMapsButtons[i].rect = mapRect;

		DrawTexture(mapButton.texture, mapRect);

		// Map name
		const Texture mapName{ g_ArrMapsNames[i] };
		const Point2f mapNameTopLeft{ mapButtonsStartPos.x - mapName.width * 0.5f + mapButtonsOffset * i, mapRect.top + mapRect.height + mapName.height * 0.1f };

		DrawTexture(mapName, mapNameTopLeft);
	}
}
void UpdateMainMenu(float elapsedSec)
{
	// banana go up and down
	const float frequency{ 1.5f };
	const float amplitude{ 15 };

	g_MainMenuTime += elapsedSec;
	g_MainMenuBananaVerticalOffset = sinf(g_MainMenuTime * frequency) * amplitude;

	// glow rotate weeee
	const float rotationSpeed{ 10.f }; // in degrees per second
	g_MainMenuBananaGlowRotation += rotationSpeed * elapsedSec;
}
void UpdateMainMenuButtonsCollision()
{
	if (!g_IsSelectingMap)
	{
		g_StartGameButton.isHoveringOver = false;
		if (IsPointInRect(g_StartGameButton.rect, g_MousePosition))
		{
			g_StartGameButton.isHoveringOver = true;
		}
	}
	else
	{
		for (int i = 0; i < g_AmountOfMaps; ++i)
		{
			g_ArrMapsButtons[i].isHoveringOver = false;
			if (IsPointInRect(g_ArrMapsButtons[i].rect, g_MousePosition))
			{
				g_ArrMapsButtons[i].isHoveringOver = true;
				break;
			}
		}
	}
}
void StartGame()
{
	g_Cols = GetCurrentGridCols();
	g_Rows = GetCurrentGridRows();
	g_MoneyReductionScalar = 1;
	g_BloonSpeedScalar = 1;
	g_CurrentWave = 0;
	g_BoardTextures = new Texture*[g_Cols * g_Rows] {};
	g_BoardGrid = GetCurrentBoardGrid();
	g_CellSize = Point2f{ g_WindowWidth / g_Cols, g_WindowHeight / g_Rows };
	InitPath();
	InitPathTextures();
	ForceUIOffTheScreen();
}

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
				tempPath[currentPointIndex] = Point2f{ (currentColumn) * (g_CellSize.x) + g_CellSize.x*0.75f ,
				currentRow * (g_CellSize.y) - g_CellSize.y * 0.25f };

				// set bloons spawn point
				g_SpawnPoint = Point2f{ 0, tempPath[currentPointIndex].y };

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
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) - g_CellSize.x*0.25f ,
				currentRow * (g_CellSize.y) - g_CellSize.y*0.25f };
			++currentPointIndex;
			++g_PathWaypointAmount;
			g_CurrentPathDirection = Direction::right;
		}
		else if (currentColumn > 0 &&
			g_BoardGrid[currentRow * g_Cols + (currentColumn - 1)] != 0 &&
			g_CurrentPathDirection != Direction::right)
		{
			--currentColumn;
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) - g_CellSize.x * 0.25f ,
				currentRow * (g_CellSize.y) - g_CellSize.y * 0.25f };
			++currentPointIndex;
			++g_PathWaypointAmount;
			g_CurrentPathDirection = Direction::left;
		}
		else if (currentRow > 0 &&
			g_BoardGrid[(currentRow - 1) * g_Cols + currentColumn] != 0 &&
			g_CurrentPathDirection != Direction::down) {
			--currentRow;
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) - g_CellSize.x * 0.25f ,
				currentRow * (g_CellSize.y) - g_CellSize.y * 0.25f };
			++currentPointIndex;
			++g_PathWaypointAmount;
			g_CurrentPathDirection = Direction::up;
		}
		else if (currentRow < g_Rows &&
			g_BoardGrid[(currentRow + 1) * g_Cols + currentColumn] != 0 &&
			g_CurrentPathDirection != Direction::up) {
			++currentRow;
			tempPath[currentPointIndex] = Point2f{ currentColumn * (g_CellSize.x) - g_CellSize.x * 0.25f ,
				currentRow * (g_CellSize.y) - g_CellSize.y * 0.25f };
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
		g_Path[index].y -= 15.f;
	}
	g_Path[g_PathWaypointAmount - 1].x += g_CellSize.x;

	delete[] tempPath;
}
void InitPathTextures()
{
	for (int x = 0; x < g_Cols; ++x)
	{
		for (int y = 0; y < g_Rows; ++y)
		{
			Texture* curTexture{ nullptr };

			if (g_BoardGrid[y * g_Cols + x] == 0)
			{
				curTexture = &g_ArrGrassTextures[GetRand(0, g_AmountOfGrassTextures - 1)];
			}
			else if (!g_IsPathMadeOutOfStone)
			{
				curTexture = &g_ArrPathTextures[GetRand(0, g_AmountOfPathTextures - 1)];
			}
			else
			{
				curTexture = &g_StonePathTexture;
			}

			g_BoardTextures[y * g_Cols + x] = curTexture;
		}
	}
}
void DrawBoard()
{
	Color4f const cPath{ 0.7f, 0.47f, 0.27f, 1.f }, cGround{ 0.52f, 0.82f, 0.48f, 1.f },
		cEndPoint{ 1.f, 0.f, 0.f, 1.f }, cStartPoint{0.46f, 0.96f, 0.26f, 1.f};

	for (int row = 0; row < g_Rows; ++row) {
		for (int col = 0; col < g_Cols; ++col) {
			Rectf currentCellRect{ col * g_CellSize.x, row * g_CellSize.y, g_CellSize.x, g_CellSize.y };
			const Texture texture{ *g_BoardTextures[row * g_Cols + col] };
			DrawTexture(texture, currentCellRect);
		}
	}
}

void StartWave()
{
	++g_CurrentWave;
	UpdateDifficultyScaling();
	
	int bloonsHpToSpawn{static_cast<int>( ceil(20 + pow(2 * g_CurrentWave,1.5f))) };
	int* arrBloonsToSpawn{ new int[g_AmountOfBloonsTextures] {} };
	g_TotalAmountOfBloons = 0;

	//std::cout << "Wave " << g_CurrentWave << std::endl;

	//Randomness
	int bloonRandomOffsetFactor{};
	int maxTierOfBloon{};
	if (bloonsHpToSpawn < 30) {
		bloonRandomOffsetFactor = 0;
		maxTierOfBloon = 1;
	}
	else if (bloonsHpToSpawn < 40)
	{
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 2;
	}
	else if (bloonsHpToSpawn < 65) {
		bloonRandomOffsetFactor = 2;
		maxTierOfBloon = 3;
	}
	else if (bloonsHpToSpawn < 80) {
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 3;
	}
	else if (bloonsHpToSpawn < 105) {
		bloonRandomOffsetFactor = 2;
		maxTierOfBloon = 4;
	}
	else if (bloonsHpToSpawn < 125) {
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 4;
	}
	else if (bloonsHpToSpawn < 150) {
		bloonRandomOffsetFactor = 2;
		maxTierOfBloon = 5;
	}
	else if (bloonsHpToSpawn < 175) {
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 5;
	}
	else if (bloonsHpToSpawn < 205) {
		bloonRandomOffsetFactor = 2;
		maxTierOfBloon = 6;
	}
	else if (bloonsHpToSpawn < 235) {
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 6;
	}
	else if (bloonsHpToSpawn < 260) {
		bloonRandomOffsetFactor = 3;
		maxTierOfBloon = 7;
	}
	else if (bloonsHpToSpawn < 300) {
		bloonRandomOffsetFactor = 2;
		maxTierOfBloon = 7;
	}
	else if (bloonsHpToSpawn < 340) {
		bloonRandomOffsetFactor = 2;
		maxTierOfBloon = 8;
	}
	else if (bloonsHpToSpawn < 375) {
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 8;
	}
	else if(bloonsHpToSpawn < 420) {
		bloonRandomOffsetFactor = 1;
		maxTierOfBloon = 9;
	}
	else {
		bloonRandomOffsetFactor = 0;
		maxTierOfBloon = 9;
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
		else if (randomBloon > maxTierOfBloon)
			randomBloon = maxTierOfBloon;

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
	
	g_AmountActiveBloons = g_TotalAmountOfBloons;
	delete[] arrBloonsToSpawn;

	
}
void UpdateDifficultyScaling()
{
	if (g_CurrentWave < 10)
		return;

	if (g_CurrentWave < 20)
	{
		g_BloonSpeedScalar += 0.05f;
		g_MoneyReductionScalar = 0.6f;
	}
	else if (g_CurrentWave < 30)
	{
		g_BloonSpeedScalar += 0.1f;
		g_MoneyReductionScalar = 0.3f;
	}
	else if (g_CurrentWave < 40)
	{
		g_BloonSpeedScalar += 0.2f;
		g_MoneyReductionScalar = 0.1f;
	}
	else
	{
		g_BloonSpeedScalar += 0.5f;
		g_MoneyReductionScalar = 0.05f;
	}
}

void RestartGame()
{
	g_Money = 50;
	g_CurrentWave = 0;
	g_PlayerHp = 10;
	g_LosingAnimationProgress = 0.f;
	g_MonkeysOnBoard = 0;
	g_ProjectilesOnBoardAmount = 0;
	g_MaxProjectilesOnBoard = 0;
	g_AmountActiveBloons = 0;
	g_PreviewMonkeyId = 0;
	g_IsUIActive = 0;
	g_IsMonkeySelected = 0;
	g_SelectedMonkeyId = 0;
	g_TotalAmountOfBloons = 0;

	for (int i{}; i < g_ProjectilesOnBoardAmount; ++i) {
		if (g_ArrProjectiles[i].maxPierce > 0 &&
			g_ArrProjectiles[i].piercedBloonIds != nullptr) {
			DeletePiercedBloonIds(g_ArrProjectiles[i]);
		}
	}
	delete[] g_ArrMonkeys;
	delete[] g_ArrProjectiles;
	delete[] g_ArrBloons;

	g_ArrBloons = nullptr;

	g_ArrMonkeys = nullptr;
	g_ArrProjectiles = nullptr;

	//StartWave();

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
	}
}
void UpdateBloons(float elapsedSec)
{
	for (int index = 0; index < g_TotalAmountOfBloons; ++index) 
	{
		
		if (g_ArrBloons[index].bloonTextureId == -1) {
			continue;
		}

		if (g_ArrBloons[index].hp <= 0) {
			--g_AmountActiveBloons;
			DestroyBloon(g_ArrBloons[index]);
			continue;
		}
		DamageBloon(g_ArrBloons[index]);

		float distance{ GetDistance(g_ArrBloons[index].location, g_Path[g_ArrBloons[index].currentNavigationPointId])  };

		if (GetDistance(g_ArrBloons[index].location, g_Path[g_PathWaypointAmount - 1]) < g_ArrBloons[index].speed * g_BloonSpeedScalar * elapsedSec) {
			g_PlayerHp -= floor(pow(g_ArrBloons[index].hp, 0.66f));
			DestroyBloon(g_ArrBloons[index]);
			--g_AmountActiveBloons;
		}

		Point2f normalVector{
			(g_Path[g_ArrBloons[index].currentNavigationPointId].x - g_ArrBloons[index].location.x) / distance,
			(g_Path[g_ArrBloons[index].currentNavigationPointId].y - g_ArrBloons[index].location.y) / distance
		};

		g_ArrBloons[index].location.x += normalVector.x * g_ArrBloons[index].speed * g_BloonSpeedScalar * elapsedSec;
		g_ArrBloons[index].location.y += normalVector.y * g_ArrBloons[index].speed * g_BloonSpeedScalar * elapsedSec;

		if (distance < g_ArrBloons[index].speed * g_BloonSpeedScalar * elapsedSec)
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
	Monkey* tempArrayMonkey{ new Monkey[g_MonkeysOnBoard + 1]{} };

	//copies projectiles and monkeys on board to a new array so we can raise the max amount of them on board
	for (int index = 0; index < g_MonkeysOnBoard; ++index) {
		tempArrayMonkey[index] = g_ArrMonkeys[index];
	}

	//setup the new monkey
	tempArrayMonkey[g_MonkeysOnBoard] = monkey;
	tempArrayMonkey[g_MonkeysOnBoard].position = position;
	tempArrayMonkey[g_MonkeysOnBoard].targetPosition = Point2f{ position.x, position.y + 1 };
	tempArrayMonkey[g_MonkeysOnBoard].moneySpent = g_ArrUIMonkeyPrices[monkey.monkeyId];

	//transfer the arrays
	++g_MonkeysOnBoard;
	if (g_ArrMonkeys != nullptr) {
		delete[] g_ArrMonkeys;
	}
	
	g_ArrMonkeys = tempArrayMonkey;
	g_IsPreviewOn = false;

	//determines how many projectiles can be on board based on projectile lifetime and amount of monkeys
	ResizeProjectileArray();
	//removes appropriate amount of money from players wallet
	g_Money -= g_ArrUIMonkeyPrices[monkey.monkeyId];
}
void DrawMonkeys()
{
	for (int index = 0; index < g_MonkeysOnBoard; ++index) {
		const Texture monkeyTexture = g_ArrMonkeyTextures[g_ArrMonkeys[index].monkeyId * g_AmountOfUpgradesPerMonkey + g_ArrMonkeys[index].monkeyUpgradeTier];
		const Rectf placementRect{
			g_ArrMonkeys[index].position.x - monkeyTexture.width / g_CurrentTextPixelSize * g_RescaledTextPixelSize * 0.5f,
			g_ArrMonkeys[index].position.y - monkeyTexture.height / g_CurrentTextPixelSize * g_RescaledTextPixelSize * 0.5f,
			monkeyTexture.width / g_CurrentTextPixelSize * g_RescaledTextPixelSize,
			monkeyTexture.height / g_CurrentTextPixelSize * g_RescaledTextPixelSize
		};

		// Draw detection range only if monkey is selected
		if (g_IsMonkeySelected && g_SelectedMonkeyId == index)
		{
			utils::SetColor(1.f, 1.f, 1.f, 0.5f);
			utils::FillEllipse(g_ArrMonkeys[index].position, g_ArrMonkeys[index].detectRadius, g_ArrMonkeys[index].detectRadius);
			utils::SetColor(1.f, 1.f, 1.f, 1.f);
			utils::DrawEllipse(g_ArrMonkeys[index].position, g_ArrMonkeys[index].detectRadius, g_ArrMonkeys[index].detectRadius);
		}

		// Draw monkey
		const float angle{ atan2f(g_ArrMonkeys[index].targetPosition.y - g_ArrMonkeys[index].position.y, g_ArrMonkeys[index].targetPosition.x - g_ArrMonkeys[index].position.x) * g_Rad2Deg - 90 };
		DrawTexture(monkeyTexture, placementRect, angle);
	}
}
void DrawPreviewMonkey()
{
	const Rectf previewRect{ 
		g_MousePosition.x - g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2].width / g_CurrentTextPixelSize * g_RescaledTextPixelSize * 0.5f,
		g_MousePosition.y - g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2].height / g_CurrentTextPixelSize * g_RescaledTextPixelSize * 0.5f,
		g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2].width / g_CurrentTextPixelSize * g_RescaledTextPixelSize,
		g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2].height / g_CurrentTextPixelSize * g_RescaledTextPixelSize
	};

	// Draw detection radius preview
	utils::SetColor(1.f, 1.f, 1.f, 0.5f);
	utils::FillEllipse(g_MousePosition, GetMonkeyFromIndex(g_PreviewMonkeyId).detectRadius, GetMonkeyFromIndex(g_PreviewMonkeyId).detectRadius);
	utils::SetColor(1.f, 1.f, 1.f, 1.f);
	utils::DrawEllipse(g_MousePosition, GetMonkeyFromIndex(g_PreviewMonkeyId).detectRadius, GetMonkeyFromIndex(g_PreviewMonkeyId).detectRadius);

	// Draw texture
	if (g_CanPlaceMonkey) 
	{
		DrawTexture(g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2], previewRect);
	}
	else 
	{
		DrawTexture(g_ArrPreviewMonkeyTextures[g_PreviewMonkeyId * 2 + 1], previewRect);
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
				if (g_ArrMonkeys[index].projectile.behaviour != ProjectileBehaviour::Tack && 
					g_ArrMonkeys[index].projectile.behaviour != ProjectileBehaviour::Ring)
					g_ArrMonkeys[index].targetPosition = bloonCollider.center;

				break;
			}

		}
	}
}
void DestroyMonkey(int monkeyId)
{
	// Swap the monkey to delete to the end of the array
	SwapMonkeysInArray(g_ArrMonkeys[monkeyId], g_ArrMonkeys[g_MonkeysOnBoard - 1]);

	// Make a temporary array
	Monkey* tempArray{ new Monkey[g_MonkeysOnBoard - 1]{} };
	
	for (int i = 0; i < g_MonkeysOnBoard - 1; ++i)
	{
		tempArray[i] = g_ArrMonkeys[i];
	}

	delete[] g_ArrMonkeys;
	g_ArrMonkeys = tempArray;
	--g_MonkeysOnBoard;
	ResizeProjectileArray();
}
void SwapMonkeysInArray(Monkey& monkey1, Monkey& monkey2)
{
	Monkey temp = monkey1;
	monkey1 = monkey2;
	monkey2 = temp;
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

		//In case projectile is of crossbow type, loads in guardian values that never will occur as bloon id's
		//to prevent a case where bloon with id 0 can't be damaged by a crossbow
		if (newProjectile.maxPierce > 0) {
			newProjectile.piercedBloonIds = new int[newProjectile.maxPierce] {};
			for (int index = 0; index < newProjectile.maxPierce; ++index) {
				newProjectile.piercedBloonIds[index] = -1;
			}
		}

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

			if (newProjectile.maxPierce > 0) {
				newProjectile.piercedBloonIds = new int[newProjectile.maxPierce] {};
				for (int index = 0; index < newProjectile.maxPierce; ++index) {
					newProjectile.piercedBloonIds[index] = -1;
				}
			}

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
		const Rectf projectileTextureRect{
			centerOfProjectile.x - projectileTexture.width / g_CurrentTextPixelSize * g_RescaledTextPixelSize * 0.5f,
			centerOfProjectile.y - projectileTexture.height / g_CurrentTextPixelSize * g_RescaledTextPixelSize * 0.5f,
			projectileTexture.width / g_CurrentTextPixelSize * g_RescaledTextPixelSize,
			projectileTexture.height / g_CurrentTextPixelSize * g_RescaledTextPixelSize
		};

		float angle{};
		if(g_ArrProjectiles[index].behaviour != ProjectileBehaviour::Boomerang && 
			g_ArrProjectiles[index].behaviour != ProjectileBehaviour::HomingBoomerang &&
			g_ArrProjectiles[index].behaviour != ProjectileBehaviour::Ring)
		{
			angle =  atan2f(g_ArrProjectiles[index].direction.y, g_ArrProjectiles[index].direction.x) * g_Rad2Deg ;
		}
		else if(g_ArrProjectiles[index].behaviour != ProjectileBehaviour::Ring)
		{
			const float amountOfBoomerangSpins{ 2 + (g_ArrProjectiles[index].maxPierce - g_ArrProjectiles[index].bloonsPierced) * 0.1f };
			angle = atan2f(g_ArrProjectiles[index].direction.y, g_ArrProjectiles[index].direction.x) * g_Rad2Deg 
				+ g_ArrProjectiles[index].timer / g_ArrProjectiles[index].lifetime * 360.f * amountOfBoomerangSpins;
		}
		else
		{
			const float opacity{ 1 - powf(g_ArrProjectiles[index].timer / g_ArrProjectiles[index].lifetime, 2) };
			const Color4f ringInsideColor{ 1.f, 0.5f, 0.f, opacity };
			const Color4f ringRimColor{ 1.f, 0.5f, 0.f, 1.f };
			const float ringRimThicness{ 5.f };

			utils::SetColor(ringInsideColor);
			utils::FillEllipse(g_ArrProjectiles[index].origin, g_ArrProjectiles[index].radius, g_ArrProjectiles[index].radius);

			utils::SetColor(ringRimColor);
			utils::DrawEllipse(g_ArrProjectiles[index].origin, g_ArrProjectiles[index].radius, g_ArrProjectiles[index].radius, ringRimThicness * opacity);
			continue;
		}

		//const float colliderRadius{ g_ArrProjectiles[index].radius };

		//utils::SetColor(1.f, 1.f, 1.f, 1.f);
		//utils::DrawEllipse(centerOfProjectile, colliderRadius, colliderRadius);
		utils::DrawTexture(projectileTexture, projectileTextureRect, angle);
	}
}
void DeleteProjectile(Projectile& projectile) {
	projectile = nullProjectile;
	--g_ProjectilesOnBoardAmount;
}
void DeletePiercedBloonIds(Projectile& projectile)
{
	if (projectile.piercedBloonIds == nullptr)
		return;

	delete[] projectile.piercedBloonIds;
	projectile.piercedBloonIds = nullptr;
}
void ResizeProjectileArray()
{
	g_MaxProjectilesOnBoard = 0;
	for (int index = 0; index < g_MonkeysOnBoard; ++index) {
		int scalar{};
		const float projectilesCooldown{ 1 / g_ArrMonkeys[index].fireRate };
		g_ArrMonkeys[index].projectile.behaviour == ProjectileBehaviour::Tack ? scalar = g_TackCount : scalar = 1;

		g_MaxProjectilesOnBoard += ceilf(g_ArrMonkeys[index].projectile.lifetime / projectilesCooldown * 0.001f) * scalar;
	}

	//projecttiles
	Projectile* tempProjectileArray = new Projectile[g_MaxProjectilesOnBoard]{};

	for (int index = 0; index < g_ProjectilesOnBoardAmount; ++index)
	{
		if (index >= g_MaxProjectilesOnBoard)
		{
			std::cout << "Cannot write more projectiles to the array! Skipping...\n";
			break;
		}

		tempProjectileArray[index] = g_ArrProjectiles[index];
	}

	if (g_ProjectilesOnBoardAmount > g_MaxProjectilesOnBoard)
	{
		//Clean up all the projectiles
		for (int index = g_MaxProjectilesOnBoard; index < g_ProjectilesOnBoardAmount; ++index)
		{
			DeletePiercedBloonIds(g_ArrProjectiles[index]);
		}

		g_ProjectilesOnBoardAmount = g_MaxProjectilesOnBoard;
	}

	if (g_ArrProjectiles != nullptr) {
		delete[] g_ArrProjectiles;
	}
	g_ArrProjectiles = tempProjectileArray;
}
void UpdateProjectiles(float elapsedSec)
{
	for (int projectileIdx = 0; projectileIdx < g_ProjectilesOnBoardAmount; ++projectileIdx) {
		g_ArrProjectiles[projectileIdx].timer += elapsedSec * 1000;

		if (g_ArrProjectiles[projectileIdx].timer >= g_ArrProjectiles[projectileIdx].lifetime) {
			DeletePiercedBloonIds(g_ArrProjectiles[projectileIdx]);
			SwapProjectilesInArray(g_ArrProjectiles[projectileIdx], g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			DeleteProjectile(g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			
			continue;
		}

		//Check if projectile is out of the map
		if (g_ArrProjectiles[projectileIdx].position.x <= -g_ProjectileOutOfTheMapGraceDistance || 
			g_ArrProjectiles[projectileIdx].position.x >= g_WindowWidth + g_ProjectileOutOfTheMapGraceDistance)
		{
			//Delete the projectile
			DeletePiercedBloonIds(g_ArrProjectiles[projectileIdx]);
			SwapProjectilesInArray(g_ArrProjectiles[projectileIdx], g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			DeleteProjectile(g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			continue;
		}
		else if (g_ArrProjectiles[projectileIdx].position.y <= -g_ProjectileOutOfTheMapGraceDistance ||
			g_ArrProjectiles[projectileIdx].position.y >= g_WindowHeight + g_ProjectileOutOfTheMapGraceDistance)
		{
			//Delete the projectile
			DeletePiercedBloonIds(g_ArrProjectiles[projectileIdx]);
			SwapProjectilesInArray(g_ArrProjectiles[projectileIdx], g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			DeleteProjectile(g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
			continue;
		}

		if (g_ArrProjectiles[projectileIdx].spriteId == -1) {
			continue;
		}

		//Get a bloon to home to
		if (g_ArrProjectiles[projectileIdx].homingBloonId == -1 && g_ArrProjectiles[projectileIdx].homingRadius > 0)
		{
			const Circlef projectileCollider{
				g_ArrProjectiles[projectileIdx].position.x + g_ArrProjectiles[projectileIdx].radius * 0.5f,
				g_ArrProjectiles[projectileIdx].position.y + g_ArrProjectiles[projectileIdx].radius * 0.5f,
				g_ArrProjectiles[projectileIdx].homingRadius
			};

			float closestDist{ INFINITY };
			for (int i = 0; i < g_TotalAmountOfBloons; ++i)
			{
				if (g_ArrBloons[i].bloonTextureId == -1)
					continue;

				//Check if bloon have gotten pierced alredy
				if (IsValueInArray(g_ArrProjectiles[projectileIdx].piercedBloonIds, g_ArrProjectiles[projectileIdx].maxPierce, i))
					continue;

				if (GetDistance(g_ArrProjectiles[projectileIdx].position, g_ArrBloons[i].location) < closestDist)
				{
					const Circlef bloonCollider{
						g_ArrBloons[i].location.x + g_ArrBloonsTextures[g_ArrBloons[i].bloonTextureId].width,
						g_ArrBloons[i].location.y + g_ArrBloonsTextures[g_ArrBloons[i].bloonTextureId].width,
						g_ArrBloonsTextures[g_ArrBloons[i].bloonTextureId].width * 0.5f
					};

					// Check if bloon is close enough
					if (IsOverlapping(projectileCollider, bloonCollider))
					{
						closestDist = GetDistance(g_ArrProjectiles[projectileIdx].position, g_ArrBloons[i].location);
						g_ArrProjectiles[projectileIdx].homingBloonId = i;
					}
				}
			}
		}

		//Projectile behviour logic
		switch (g_ArrProjectiles[projectileIdx].behaviour)
		{
			case ProjectileBehaviour::Tack:
			case ProjectileBehaviour::Dart:
			case ProjectileBehaviour::Crossbow:
				g_ArrProjectiles[projectileIdx].position = Point2f{
					g_ArrProjectiles[projectileIdx].position.x + g_ArrProjectiles[projectileIdx].speed * elapsedSec * g_ArrProjectiles[projectileIdx].direction.x,
					g_ArrProjectiles[projectileIdx].position.y + g_ArrProjectiles[projectileIdx].speed * elapsedSec * g_ArrProjectiles[projectileIdx].direction.y
				};
				break;

			case ProjectileBehaviour::Ring:
				g_ArrProjectiles[projectileIdx].radius += g_ArrProjectiles[projectileIdx].speed * elapsedSec;
				break;

			case ProjectileBehaviour::HomingBoomerang:
				if (g_ArrProjectiles[projectileIdx].homingBloonId != -1)
				{
					g_ArrProjectiles[projectileIdx].direction = Point2f{
						g_ArrBloons[g_ArrProjectiles[projectileIdx].homingBloonId].location.x + g_ArrBloonsTextures[g_ArrBloons[g_ArrProjectiles[projectileIdx].homingBloonId].bloonTextureId].width - g_ArrProjectiles[projectileIdx].position.x,
						g_ArrBloons[g_ArrProjectiles[projectileIdx].homingBloonId].location.y + g_ArrBloonsTextures[g_ArrBloons[g_ArrProjectiles[projectileIdx].homingBloonId].bloonTextureId].width - g_ArrProjectiles[projectileIdx].position.y
					};

					NormalizeVector(g_ArrProjectiles[projectileIdx].direction);
				}

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

		bool hitBloon{};
		for (int bloonIdx = 0; bloonIdx < g_TotalAmountOfBloons; ++bloonIdx) {

			//case for if a bloon is a nullBloon
			if (g_ArrBloons[bloonIdx].bloonTextureId == -1) {
				continue;
			}

			Circlef projectileCollider{};
			if (g_ArrProjectiles[projectileIdx].behaviour == ProjectileBehaviour::Ring) {
				//Necessary to keep the ring type projectile in it's origin place, it's position can't be tied
				//to it's radius, otherwise it keeps shifting
				projectileCollider = Circlef{
					g_ArrProjectiles[projectileIdx].origin.x,
					g_ArrProjectiles[projectileIdx].origin.y,
					g_ArrProjectiles[projectileIdx].radius
				};
			}
			else {
				projectileCollider = Circlef{
					g_ArrProjectiles[projectileIdx].position.x + g_ArrProjectiles[projectileIdx].radius * 0.5f,
					g_ArrProjectiles[projectileIdx].position.y + g_ArrProjectiles[projectileIdx].radius * 0.5f,
					g_ArrProjectiles[projectileIdx].radius
				};
			}

			const Circlef bloonCollider{
				g_ArrBloons[bloonIdx].location.x + g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width,
				g_ArrBloons[bloonIdx].location.y + g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width,
				g_ArrBloonsTextures[g_ArrBloons[bloonIdx].bloonTextureId].width * 0.5f
			};

			if (IsOverlapping(projectileCollider, bloonCollider)) {
				hitBloon = true;

				if (g_ArrProjectiles[projectileIdx].maxPierce > 0 &&
					g_ArrProjectiles[projectileIdx].bloonsPierced < g_ArrProjectiles[projectileIdx].maxPierce &&
					!IsValueInArray(g_ArrProjectiles[projectileIdx].piercedBloonIds, g_ArrProjectiles[projectileIdx].maxPierce, bloonIdx))
				{
					//Behaviour handling on overlap if projectile can pierce multiple bloons AND hasn't pierced
					//given bloon before
					g_Money += ceilf(g_ArrBloons[bloonIdx].moneyDropped * g_MoneyReductionScalar);
					g_ArrBloons[bloonIdx].hp -= g_ArrProjectiles[projectileIdx].damage;
					g_ArrProjectiles[projectileIdx].piercedBloonIds[g_ArrProjectiles[projectileIdx].bloonsPierced] = bloonIdx;
					++g_ArrProjectiles[projectileIdx].bloonsPierced;
					continue;
				}
				else if (g_ArrProjectiles[projectileIdx].maxPierce > 0 &&
					IsValueInArray(g_ArrProjectiles[projectileIdx].piercedBloonIds, g_ArrProjectiles[projectileIdx].maxPierce, bloonIdx)) 
				{
					//Behaviour handling on overlap if projectile can pierce multiple bloons AND hasn't pierced
					//given bloon before
					continue;
				}
				else 
				{
					//Default projectile behaviour on hit or once crossbow projectile pierces it's max amount of bloons
					g_Money += ceilf(g_ArrBloons[bloonIdx].moneyDropped * g_MoneyReductionScalar);
					g_ArrBloons[bloonIdx].hp -= g_ArrProjectiles[projectileIdx].damage;
					DeletePiercedBloonIds(g_ArrProjectiles[projectileIdx]);
					SwapProjectilesInArray(g_ArrProjectiles[projectileIdx], g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
					DeleteProjectile(g_ArrProjectiles[g_ProjectilesOnBoardAmount - 1]);
					break;
				}

				break;
			}
		}

		if (g_ArrProjectiles[projectileIdx].homingBloonId == -1)
			continue;

		//Reset bloon to home if collided with bloon
		if ((hitBloon || g_ArrBloons[g_ArrProjectiles[projectileIdx].homingBloonId].bloonTextureId == -1) && g_ArrProjectiles[projectileIdx].homingRadius > 0)
		{
			g_ArrProjectiles[projectileIdx].homingBloonId = -1;
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

int GetCurrentGridCols()
{
	switch (g_CurrentMapIndex)
	{
		case 0:
			return g_ColsMap0;
		case 1:
			return g_ColsMap1;
		case 2:
			return g_ColsMap2;
		default:
			std::cout << "This error is sus\n";
			return g_ColsMap0;
	}
}
int GetCurrentGridRows()
{
	switch (g_CurrentMapIndex)
	{
		case 0:
			return g_RowsMap0;
		case 1:
			return g_RowsMap1;
		case 2:
			return g_RowsMap2;
		default:
			std::cout << "This error is sus\n";
			return g_ColsMap0;
	}
}
int* GetCurrentBoardGrid()
{
	switch (g_CurrentMapIndex)
	{
	case 0:
		return g_BoardGridMap0;
	case 1:
		return g_BoardGridMap1;
	case 2:
		return g_BoardGridMap2;
	default:
		std::cout << "This error is sus\n";
		return g_BoardGridMap0;
	}
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
		case 4:
			return pinkBloon;
			break;
		case 5:
			return whiteBloon;
			break;
		case 6:
			return blackBloon;
			break;
		case 7:
			return zebraBloon;
			break;
		case 8:
			return gayBloon;
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
MonkeyUpgrade* GetMonkeyUpgradesFromIndex(int index)
{
	switch (index)
	{
		case 0:
			return g_ArrDartUpgrades;
			break;
		case 1:
			return g_ArrBoomerangUpgrades;
			break;
		case 2:
			return g_ArrTackUpgrades;
			break;
		default:
			std::cout << "Incorrent Monkey Index\n";
			return g_ArrDartUpgrades;
			break;

		//add cases as more monkeys are added
	}
}

void DrawUI()
{
	// Shop menu

	const float UIButtonsInitialOffset{ g_MoneyIcon.height * 3.f / 2.f };
	const float UIButtonsVerticalOffset{ g_WindowHeight / g_AmountOfMonkeyBuyButtons };
	const Point2f UIShopTopLeft{ g_UIShopHorizontalOffset + g_WindowWidth - g_UIBackgroundWidth, 0 };
	const Point2f UIShopTopCenter{ g_UIShopHorizontalOffset + g_WindowWidth - g_UIBackgroundWidth / 2.f, 0 };

	const Rectf shopBGRect{ UIShopTopLeft.x, UIShopTopLeft.y, g_WindowWidth - UIShopTopLeft.x, g_WindowHeight };
	const Color4f shopBGColor{ 72.f / 255.f, 42.f / 255.f, 21.f / 255.f, 1.f };
	const Rectf shopBGOutlineRect{ UIShopTopLeft.x, UIShopTopLeft.y + g_TextUIOpenBtn.rect.height, g_RescaledTextPixelSize, g_WindowHeight - UIShopTopLeft.y - g_TextUIOpenBtn.rect.height };
	const Color4f shopBGOutlineColor{ 12.f / 255.f, 12.f / 255.f, 12.f / 255.f, 1.f };
	utils::SetColor(shopBGColor);
	utils::FillRect(shopBGRect);

	utils::SetColor(shopBGOutlineColor);
	utils::FillRect(shopBGOutlineRect);

	// Draw open / close buttons
	const Point2f UIOpenCloseBtnPos{ UIShopTopLeft.x - g_TextUICloseBtn.rect.width, UIShopTopLeft.y };
	g_TextUIOpenBtn.rect.left = UIOpenCloseBtnPos.x;
	g_TextUICloseBtn.rect.left = UIOpenCloseBtnPos.x;
	g_TextUIOpenBtn.rect.top = UIOpenCloseBtnPos.y;
	g_TextUICloseBtn.rect.top = UIOpenCloseBtnPos.y;

	if (!g_IsUIActive)
		DrawTexture(g_TextUIOpenBtn.texture, UIOpenCloseBtnPos);
	else
		DrawTexture(g_TextUICloseBtn.texture, UIOpenCloseBtnPos);

	//Draw Shop Buttons
	for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
	{
		const Point2f costTopCenter{ UIShopTopCenter.x + g_MoneyIcon.width / 2.f, UIButtonsInitialOffset + UIButtonsVerticalOffset * i - g_AverageNumbersHeight };
		const Point2f buttonTopLeft{ UIShopTopCenter.x - g_ArrUIMonkeyBuyButtons[i].rect.width / 2, UIButtonsInitialOffset + UIButtonsVerticalOffset * i };
		const Point2f textTopLeft{ UIShopTopCenter.x - g_ArrUIMonkeyTextButtons[i].width / 2,
			UIButtonsInitialOffset + UIButtonsVerticalOffset * i + g_ArrUIMonkeyBuyButtons[i].rect.height };
		const int cost{ g_ArrUIMonkeyPrices[i] };
		const float costWidth{ DrawNumberSequenceTopCenter(cost, costTopCenter) };
		const Point2f moneyIconTopLeft{ costTopCenter.x - costWidth - g_MoneyIcon.width, costTopCenter.y };

		g_ArrUIMonkeyBuyButtons[i].rect.left = buttonTopLeft.x;
		g_ArrUIMonkeyBuyButtons[i].rect.top = buttonTopLeft.y;

		DrawTexture(g_ArrUIMonkeyBuyButtons[i].texture, buttonTopLeft);
		//Gray out the button if you don't have enough cash
		if (g_Money < cost)
		{
			utils::SetColor(g_GrayOutColor);
			utils::FillRect(buttonTopLeft, g_ArrUIMonkeyBuyButtons[i].rect.width, g_ArrUIMonkeyBuyButtons[i].rect.height);
		}

		DrawTexture(g_MoneyIcon, moneyIconTopLeft);
		DrawTexture(g_ArrUIMonkeyTextButtons[i], textTopLeft);
	}

	// Upgrades menu
	const Point2f UIUpgradeTopLeft{ -g_UIUpgradeHorizontalOffset, g_WindowHeight - g_UpgradesBGHeight };
	const Point2f UIUpgradeTopCenter{ -g_UIUpgradeHorizontalOffset + g_UIBackgroundWidth / 2.f, g_WindowHeight - g_UpgradesBGHeight };
	const Rectf upgradesBGRect{ UIUpgradeTopLeft.x, UIUpgradeTopLeft.y, g_UIBackgroundWidth, g_WindowHeight - UIUpgradeTopLeft.y };
	const Rectf upgradesBGOutlineRect{ UIUpgradeTopLeft.x + upgradesBGRect.width - g_RescaledTextPixelSize, UIUpgradeTopLeft.y, g_RescaledTextPixelSize, upgradesBGRect.height };
	utils::SetColor(shopBGColor);
	utils::FillRect(upgradesBGRect);

	utils::SetColor(shopBGOutlineColor);
	utils::FillRect(upgradesBGOutlineRect);

	if (g_MonkeysOnBoard > 0)
	{
		const Texture currentMonkeyName{ g_ArrUIMonkeyTextButtons[g_ArrMonkeys[g_SelectedMonkeyId].monkeyId] };
		const Point2f currentMonkeyNameTopLeft{ UIUpgradeTopCenter.x - currentMonkeyName.width / 2.f, UIUpgradeTopCenter.y };
		DrawTexture(currentMonkeyName, currentMonkeyNameTopLeft);

		const UIButton monkeyPreview{ g_ArrUIMonkeyBuyButtons[g_ArrMonkeys[g_SelectedMonkeyId].monkeyId] };
		const Point2f previewMonkeyTopLeft = Point2f{ UIUpgradeTopCenter.x - monkeyPreview.rect.width / 2.f, currentMonkeyNameTopLeft.y + monkeyPreview.rect.height / 4.f };
		DrawTexture(monkeyPreview.texture, previewMonkeyTopLeft);

		const Texture currentUpgradeTexture{ g_ArrUIUpgradeText[g_ArrMonkeys[g_SelectedMonkeyId].monkeyUpgradeTier] };
		const Point2f currentUpgradeTextTopLeft{ UIUpgradeTopCenter.x - currentUpgradeTexture.width / 2.f,
			previewMonkeyTopLeft.y + monkeyPreview.rect.height };
		DrawTexture(currentUpgradeTexture, currentUpgradeTextTopLeft);

		UIButton* buyButton{ &g_ArrBuyUpgradeBtn[0] };
		if (g_ArrMonkeys[g_SelectedMonkeyId].monkeyUpgradeTier == g_AmountOfUpgradesPerMonkey - 1)
		{
			buyButton = &g_ArrBuyUpgradeBtn[1];
			g_ArrBuyUpgradeBtn[0].rect.left = -1000; // get button far away so we can't click it when upgrades are maxed
			const Point2f buyButtonTopLeft{ UIUpgradeTopCenter.x - (*buyButton).rect.width / 2.f,
			currentUpgradeTextTopLeft.y + (*buyButton).rect.height };
			(*buyButton).rect.left = buyButtonTopLeft.x;
			(*buyButton).rect.top = buyButtonTopLeft.y;

			DrawTexture((*buyButton).texture, buyButtonTopLeft);
		}
		else
		{
			const Point2f buyButtonTopLeft{ UIUpgradeTopCenter.x - (*buyButton).rect.width / 2.f,
			currentUpgradeTextTopLeft.y + (*buyButton).rect.height };
			(*buyButton).rect.left = buyButtonTopLeft.x;
			(*buyButton).rect.top = buyButtonTopLeft.y;

			DrawTexture((*buyButton).texture, buyButtonTopLeft);

			int cost{ GetMonkeyUpgradesFromIndex(g_ArrMonkeys[g_SelectedMonkeyId].monkeyId)[g_ArrMonkeys[g_SelectedMonkeyId].monkeyUpgradeTier].cost };
			const Point2f costTextTopCenter{ UIUpgradeTopCenter.x + g_MoneyIcon.width / 2.f,
				currentUpgradeTextTopLeft.y + (*buyButton).rect.height * 2 };
			const float costTextWidth{ DrawNumberSequenceTopCenter(cost, costTextTopCenter) };

			const Point2f moneyIconTopLeft{ costTextTopCenter.x - g_MoneyIcon.width - costTextWidth, costTextTopCenter.y };
			DrawTexture(g_MoneyIcon, moneyIconTopLeft);
		}

		

		const Point2f sellBtnTopLeft{ UIUpgradeTopCenter.x - g_SellMonkeyBtn.rect.width / 2.f,
			currentUpgradeTextTopLeft.y + (*buyButton).rect.height * 2 + g_MoneyIcon.height + g_SellMonkeyBtn.rect.height / 2.f };
		DrawTexture(g_SellMonkeyBtn.texture, sellBtnTopLeft);
		g_SellMonkeyBtn.rect.left = sellBtnTopLeft.x;
		g_SellMonkeyBtn.rect.top = sellBtnTopLeft.y;
	}

	//Next wave button
	
	const Point2f nextWaveTopLeft{
	g_WindowWidth/2.f - g_NextWaveBtn.rect.width*0.5f,
	-g_NextWaveVerticallOffset + g_WindowHeight };
	g_NextWaveBtn.rect.top = nextWaveTopLeft.y;
	g_NextWaveBtn.rect.left = nextWaveTopLeft.x;
	if (g_AlternateBuyButtonOn == true && g_CurrentWave!=0) {
		DrawTexture(g_NextWaveBtn2, g_NextWaveBtn.rect);		
	}
	else if(g_CurrentWave==0 || (g_CurrentWave == 1 && g_AmountActiveBloons!=0)){
		DrawTexture(g_StartWaveBtn, g_NextWaveBtn.rect);
	}
	else {
		DrawTexture(g_NextWaveBtn.texture, g_NextWaveBtn.rect);
	}
	
	

	//Main UI BG
	const Point2f displayOffset{
		10.f,
		10.f
	};

	const Rectf mainUIBGRect{ 0.f, 0.f, g_CurrentWaveText.width + displayOffset.x * 6, displayOffset.y * 4 + g_CurrentWaveText.height + g_CurrentHpText.height + g_MoneyIcon.height };
	const Color4f mainUIBGColor{ 0, 0, 0, 0.5f };
	utils::SetColor(mainUIBGColor);
	utils::FillRect(mainUIBGRect);

	//Current wave display
	Point2f currentWaveTopLeft{ displayOffset.x, displayOffset.y };
	DrawTexture(g_CurrentWaveText, currentWaveTopLeft);
	currentWaveTopLeft.x += g_CurrentWaveText.width;
	DrawNumberSequenceTopLeft(g_CurrentWave, currentWaveTopLeft);

	//Current HP display
	Point2f currentHpTopLeft{ displayOffset.x, displayOffset.y + currentWaveTopLeft.y + g_CurrentWaveText.height };
	DrawTexture(g_CurrentHpText, currentHpTopLeft);
	currentHpTopLeft.x += g_CurrentHpText.width;
	DrawNumberSequenceTopLeft(g_PlayerHp, currentHpTopLeft);

	//Money display
	Point2f currentMoneyTopLeft{ displayOffset.x, displayOffset.y + currentHpTopLeft.y + g_CurrentHpText.height };
	DrawTexture(g_MoneyIcon, currentMoneyTopLeft);
	currentMoneyTopLeft.x += g_MoneyIcon.width;
	if (DrawNumberSequenceTopLeft(g_Money, currentMoneyTopLeft) == 0)
		DrawTexture(g_ArrNumbers[0], currentMoneyTopLeft);
}
void ForceUIOffTheScreen()
{
	g_UIShopShiftTransition = g_UIBackgroundWidth;
	g_UIShopHorizontalOffset = g_UIBackgroundWidth;
	g_UIUpgradeShiftTransition = g_UIBackgroundWidth;
	g_UIUpgradeHorizontalOffset = g_UIBackgroundWidth;
}
void UpdateUIShopMenu(float elapsedSec)
{
	const float transitionSpeedScalar{ 1.5f };

	if (!g_IsUIActive)
	{
		if (g_UIShopShiftTransition == g_UIBackgroundWidth)
			return;

		g_UIShopShiftTransition += g_UIBackgroundWidth * transitionSpeedScalar * elapsedSec;

		if (g_UIShopShiftTransition > g_UIBackgroundWidth)
			g_UIShopShiftTransition = g_UIBackgroundWidth;

		const float t{ g_UIShopShiftTransition / g_UIBackgroundWidth };
		g_UIShopHorizontalOffset = g_UIBackgroundWidth * t;
	}
	else
	{
		if (g_UIShopShiftTransition == 0)
			return;
		
		g_UIShopShiftTransition -= g_UIBackgroundWidth * transitionSpeedScalar * elapsedSec;

		if (g_UIShopShiftTransition < 0)
			g_UIShopShiftTransition = 0;
		
		const float t{ g_UIShopShiftTransition / g_UIBackgroundWidth };
		g_UIShopHorizontalOffset = g_UIBackgroundWidth * powf(t, 2);
	}
}
void UpdateUIUpgradeMenu(float elapsedSec)
{
	const float transitionSpeedScalar{ 1.5f };

	if (!g_IsMonkeySelected)
	{
		if (g_UIUpgradeShiftTransition == g_UIBackgroundWidth)
			return;

		g_UIUpgradeShiftTransition += g_UIBackgroundWidth * transitionSpeedScalar * elapsedSec;

		if (g_UIUpgradeShiftTransition > g_UIBackgroundWidth)
			g_UIUpgradeShiftTransition = g_UIBackgroundWidth;

		const float t{ g_UIUpgradeShiftTransition / g_UIBackgroundWidth };
		g_UIUpgradeHorizontalOffset = g_UIBackgroundWidth * t;
	}
	else
	{
		if (g_UIUpgradeShiftTransition == 0)
			return;

		g_UIUpgradeShiftTransition -= g_UIBackgroundWidth * transitionSpeedScalar * elapsedSec;

		if (g_UIUpgradeShiftTransition < 0)
			g_UIUpgradeShiftTransition = 0;

		const float t{ g_UIUpgradeShiftTransition / g_UIBackgroundWidth };
		g_UIUpgradeHorizontalOffset = g_UIBackgroundWidth * powf(t, 2);
	}
}
void UpdateUINextWave(float elapsedSec)
{
	const float transitionSpeedScalar{ 1.5f };
	if (g_AmountActiveBloons <= 0) {
		if (abs(g_UINextWaveShiftTransition - (g_NextWaveBtn.rect.height))<0.1f) {
			return;
		}

		g_UINextWaveShiftTransition += g_NextWaveBtn.rect.height * transitionSpeedScalar * elapsedSec;
		if (g_UINextWaveShiftTransition > g_NextWaveBtn.rect.height) {
			g_UINextWaveShiftTransition = g_NextWaveBtn.rect.height;
		}

		
		const float t{ g_UINextWaveShiftTransition / g_NextWaveBtn.rect.height };
		g_NextWaveVerticallOffset = g_NextWaveBtn.rect.height * powf(t,2);
	}
	else {
		
		if (g_UINextWaveShiftTransition <= 0) {
			g_UINextWaveShiftTransition = 0;
			if (g_IsSecretRolled == false) {
				//Determines if a secret new wave button appears this wave
				g_AlternateBuyButtonOn = false;
				if (rand() % 20 == 0 && g_CurrentWave != 0 && g_CurrentWave != 1) {
					//std::cout << "Secret, shhh" << std::endl;
					g_AlternateBuyButtonOn = true;
				}
				g_IsSecretRolled = true;
			}
			return;
		}
		g_UINextWaveShiftTransition -= g_NextWaveBtn.rect.height * transitionSpeedScalar * elapsedSec;
		const float t{ g_UINextWaveShiftTransition / g_NextWaveBtn.rect.height };
		g_NextWaveVerticallOffset = g_NextWaveBtn.rect.height * powf(t, 2);
		
	}
}
//Add more UI collisions as you add more buttons
void UpdateUIButtonCollisions()
{
	// UI buy buttons
	for (int i = 0; i < g_AmountOfMonkeyBuyButtons; ++i)
	{
		g_ArrUIMonkeyBuyButtons[i].isHoveringOver = false;

		if (IsPointInRect(g_ArrUIMonkeyBuyButtons[i].rect, g_MousePosition) && g_Money >= g_ArrUIMonkeyPrices[i])
		{
			g_ArrUIMonkeyBuyButtons[i].isHoveringOver = true;
			break;
		}
	}

	// UI open / close buttons
	if (IsPointInRect(g_TextUICloseBtn.rect, g_MousePosition) && g_IsUIActive)
	{
		g_TextUICloseBtn.isHoveringOver = true;
		g_TextUIOpenBtn.isHoveringOver = false;
	}
	else if (IsPointInRect(g_TextUIOpenBtn.rect, g_MousePosition) && !g_IsUIActive)
	{
		g_TextUIOpenBtn.isHoveringOver = true;
		g_TextUICloseBtn.isHoveringOver = false;
	}

	// Upgrades UI
	g_ArrBuyUpgradeBtn[0].isHoveringOver = false;

	if (IsPointInRect(g_ArrBuyUpgradeBtn[0].rect, g_MousePosition) && g_IsMonkeySelected)
	{
		g_ArrBuyUpgradeBtn[0].isHoveringOver = true;
	}

	// Sell button
	g_SellMonkeyBtn.isHoveringOver = false;

	if (IsPointInRect(g_SellMonkeyBtn.rect, g_MousePosition) && g_IsMonkeySelected)
	{
		g_SellMonkeyBtn.isHoveringOver = true;
  }
  
  // Next Wave Button
	g_NextWaveBtn.isHoveringOver = false;
	if (IsPointInRect(g_NextWaveBtn.rect, g_MousePosition) && g_AmountActiveBloons <= 0) {
		g_NextWaveBtn.isHoveringOver = true;
	}
}
float DrawNumberSequenceTopCenter(int number, const Point2f& topCenter)
{
	int numberOfDigits{ static_cast<int>(log10f(number) + 1) };
	float width{};

	for (int i = numberOfDigits; i >= 1; --i)
	{
		int digit{ static_cast<int>(number % static_cast<int>(powf(10, i)) / powf(10, i - 1)) };
		width += g_ArrNumbers[digit].width;
	}

	Point2f nextDigitTopLeft{ topCenter.x - width / 2.f, topCenter.y };

	for (int i = numberOfDigits; i >= 1; --i)
	{
		int digit{ static_cast<int>(number % static_cast<int>(powf(10, i)) / powf(10, i - 1)) };
		DrawTexture(g_ArrNumbers[digit], nextDigitTopLeft);
		nextDigitTopLeft.x += g_ArrNumbers[digit].width;
	}

	return width;
}
float DrawNumberSequenceTopLeft(int number, Point2f topLeft)
{
	int numberOfDigits{ static_cast<int>(log10f(number) + 1) };
	float width{};

	for (int i = numberOfDigits; i >= 1; --i)
	{
		int digit{ static_cast<int>(number % static_cast<int>(powf(10, i)) / powf(10, i - 1)) };
		DrawTexture(g_ArrNumbers[digit], topLeft);
		topLeft.x += g_ArrNumbers[digit].width;
		width += g_ArrNumbers[digit].width;
	}

	return width;
}

void DrawLosingScreen()
{
	const Color4f background{ 0.f, 0.f, 0.f, g_LosingAnimationProgress};
	Rectf target{ 0,0, g_WindowWidth, g_WindowHeight };
	utils::SetColor(background);
	FillRect(target);
	if (g_LosingAnimationProgress > 0.9f) {
		Rectf TextureTarget{
			g_WindowWidth * 0.5f - g_TextureLosing.width,
			g_WindowHeight * 0.5f - g_TextureLosing.height,
			g_TextureLosing.width*2,
			g_TextureLosing.height*2
		};
		utils::DrawTexture(g_TextureLosing, TextureTarget);
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
bool IsValueInArray(const int* array, int arrayLength, int searchedValue)
{
	for (int index = 0; index < arrayLength; ++index) {
		if (array[index] == searchedValue) return true;
	}
	return false;
}
#pragma endregion ownDefinitions