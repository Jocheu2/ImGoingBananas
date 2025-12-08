#pragma once
#include <utils.h>
using namespace utils;

#pragma region gameInformation
// TODO: Set your name and group in the title here
std::string g_WindowTitle{ "Im goin bananas! - Name, firstname - 1DAE14" };

// Change the window dimensions here
float g_WindowWidth{ 800 };
float g_WindowHeight{ 600 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
// Constants
const float g_Rad2Deg{ 180.f / g_Pi };
const float g_Deg2Rad{ g_Pi / 180.f };

//Grid
int const g_Cols{ 5 }, g_Rows{ 4 };
int g_BoardGrid[g_Cols * g_Rows]{
    0,1,1,1,0 ,
    0,1,0,1,0,
    -1,1,0,1,0,
    0,0,0,1,2 };

const Point2f g_CellSize{
    g_WindowWidth / g_Cols,
    g_WindowHeight / g_Rows
};

//Variables needed to create a path for Bloons to follow
int g_PathWaypointAmount{ 0 };
Point2f* g_Path{ new Point2f{} };
Point2f g_SpawnPoint{};

//Enums
enum class ProjectileBehaviour
{
    Dart,
    Boomerang,
    HomingBoomerang,
    Tack,
    Crossbow,
    Ring,
    None
};
enum class Direction {
    up,
    down,
    right,
    left
};

Direction g_CurrentPathDirection{ Direction::right };

//Structs
#pragma region structs
struct Bloon {
    int hp{};
    int currentNavigationPointId{};
    int moneyDropped{};
    int bloonTextureId{};
    float speed{};
    Point2f location{};
};
struct Projectile
{
    int spriteId{};
    int damage{};
    float radius{};
    float speed{};
    float timer{}; // in ms
    float lifetime{}; // in ms
    int maxPierce{};
    ProjectileBehaviour behaviour{};
    float homingRadius{}; // for homing projectiles
    int homingBloonId{ -1 };
    int bloonsPierced{};
    int* piercedBloonIds{ nullptr };
    Point2f origin{};
    Point2f position{};
    Point2f direction{};
};
struct Monkey 
{
    int monkeyId{};
    int monkeyUpgradeTier{};
    Projectile projectile{};
    float detectRadius{};
    float colliderRadius{};
    float fireRate{}; // Projectiles per second
    float cooldownTimer{};
    Point2f position{};
    Point2f targetPosition{};
};
struct UIButton {
    Texture texture{};
    Rectf rect{};
    bool isHoveringOver{};
};
struct MonkeyUpgrade
{
    int cost{}; // how much does this upgrade cost
    int damage{}; // increases damage
    int pierce{}; // increases pierce
    float radius{}; // increases radius
    float detectRadius{}; // increases detect radius of monkey
    float homeRadius{}; // increases home radius (and makes projectile home duh)
    float fireRate{}; // increases fire rate of monkey
    float speed{}; // increases speed of projectile
    float lifetime{}; // increases lifetime
    int swapSpriteId{ -1 }; // Swaps current projectile sprite. Will ignore if set to -1
    ProjectileBehaviour swapBehaviour{ ProjectileBehaviour::None }; // Swaps current behaviour. Will ignore ProjectileBehaviour::None
};
#pragma endregion structs

// Prefabs
//Bloons
const int g_MinBloonHealth{ 1 };
const int g_MaxBloonHealth{ 4 };

#pragma region BloonTypes
const Bloon redBloon{
    1,
    0,
    1,
    0,
    50.f,
    Point2f{}
};
const Bloon blueBloon{
    2,
    0,
    1,
    1,
    100.f,
    Point2f{}
};
const Bloon greenBloon{
    3,
    0,
    1,
    2,
    20.f,
    Point2f{}
};
const Bloon yellowBloon{
    4,
    0,
    1,
    3,
    20.f,
    Point2f{}
};
const Bloon nullBloon{
    0,
    -1,
    0,
    -1,
    0,
    Point2f{}
};
#pragma endregion BloonTypes

//Projectiles
const Projectile Dart{
    0,
    1,
    20,
    200.f,
    0,
    800.f,
    1,
    ProjectileBehaviour::Dart
};
const float g_BoomerangSwingRadius{ 80.f };
const float g_BoomerangSpeed{ 100.f }; //pixels per second
const Projectile Boomerang{
    1,
    1,
    20,
    g_BoomerangSpeed / g_BoomerangSwingRadius, //radiants per second
    0,
    g_BoomerangSwingRadius * 2 * g_BoomerangSwingRadius / g_BoomerangSpeed * 2 * g_Pi,
    1,
    ProjectileBehaviour::Boomerang
};
const int g_TackCount{ 8 };
const Projectile Tack{
    2,
    1,
    20,
    200.f, //pixels per second
    0,
    800.f,
    1,
    ProjectileBehaviour::Tack
};
const int crossbowPierce{ 5 }; //Amount of bloons that can be pierced by crossbow
const Projectile Crossbow{
    0,
    1,
    20.f,
    200.f,
    0.f,
    1000.f,
    crossbowPierce,
    ProjectileBehaviour::Crossbow
};
const int ringMaxPierce{ 10 }; //necessary to make ring not instantly kill everything. It needs to be high enough so
//the ring doesn't dissapear prematurely
const Projectile Ring{
    0,
    1,
    20.f,
    200.f,
    0.f,
    1000.f,
    ringMaxPierce,
    ProjectileBehaviour::Ring
};
const Projectile nullProjectile{
    -1,
    1,
    0,
    0.f,
    0,
    0.f,
    0,
    ProjectileBehaviour::None,
    0,
    0,
    0,
    nullptr,
    Point2f{},
    Point2f{},
    Point2f{}
};

//Monkeys
const Monkey dartMonkey{
    0,
    0,
    Dart,
    100.f,
    50.f,
    0.5f
};
const Monkey boomerangMonkey{
    1,
    0,
    Boomerang,
    100.f,
    50.f,
    0.5f
};
const Monkey tackShooter{
    2,
    0,
    Tack,
    100.f,
    50.f,
    0.5f
};

//Wave
int g_BloonsHpToSpawn{ 50 };
int g_TotalAmountOfBloons{};
int g_AmountActiveBloons{};
int g_CurrentWave{ 0 };
Bloon* g_ArrBloons{ nullptr };

//Textures
const int g_AmountOfBloonsTextures{ 9 };
Texture g_ArrBloonsTextures[g_AmountOfBloonsTextures]{};
const int g_AmountOfMonkeyTextures{ 3 };
const int g_AmountOfUpgradesPerMonkey{ 3 };
Texture g_ArrMonkeyTextures[g_AmountOfMonkeyTextures * g_AmountOfUpgradesPerMonkey]{};
const int g_AmountOfProjectiles{ 3 };
Texture g_ArrProjectileTextures[g_AmountOfProjectiles]{};

//UI
int g_Money{ 20 };
Point2f g_MousePosition{};
bool g_IsUIActive{};
float g_UIShopShiftTransition{};
float g_UIShopHorizontalOffset{};
const int g_AmountOfMonkeyBuyButtons{ 3 };
const int g_FontSize{ 18 };
Texture g_TextUIBackground{};
Texture g_ArrUIMonkeyTextButtons[g_AmountOfMonkeyBuyButtons]{};
UIButton g_ArrUIMonkeyBuyButtons[g_AmountOfMonkeyBuyButtons]{};
UIButton g_TextUICloseBtn{};
UIButton g_TextUIOpenBtn{};
int g_ArrUIMonkeyPrices[g_AmountOfMonkeyBuyButtons]{5, 15, 20}; //temporary fixed values
const Color4f g_GrayOutColor{ 0.f, 0.f, 0.f, 0.8f };

Texture g_MoneyIcon{};
Texture g_ArrNumbers[10]{};
float g_AverageNumbersHeight{};
//subection: upgrades
bool g_IsMonkeySelected{};
int g_SelectedMonkeyId{};
Texture g_TextUIUpgradesBackground{};
UIButton g_ArrBuyUpgradeBtn[2]{};

//Preview Monkey
bool g_IsPreviewOn{};
bool g_CanPlaceMonkey{};
int g_PreviewMonkeyId{};
float g_UIUpgradeShiftTransition{};
float g_UIUpgradeHorizontalOffset{};
Texture g_ArrPreviewMonkeyTextures[g_AmountOfMonkeyTextures * 2]{};
Texture g_ArrUIUpgradeText[g_AmountOfUpgradesPerMonkey]{};

//Next wave button
UIButton g_NextWaveBtn{};
float g_NextWaveVerticallOffset{};
float g_UINextWaveShiftTransition{};

// Upgrades
//Dart
// Upgrades
//Dart
MonkeyUpgrade g_ArrDartUpgrades[g_AmountOfUpgradesPerMonkey - 1]{
    MonkeyUpgrade{
        10,     //cost
        1,      //damage
        0,      //pierce
        2,      //radius
        0,      //detect radius
        0,      //home radius
        0.5f,   //firerate
        0,      //speed
        2       //lifetime
    },
    MonkeyUpgrade{
        20,     //cost
        2,      //damage
        0,      //pierce
        1,      //radius
        0,      //detect radius
        0,      //home radius
        0,      //firerate
        2,      //speed
        0       //lifetime
    }
};
//Boomerang
MonkeyUpgrade g_ArrBoomerangUpgrades[g_AmountOfUpgradesPerMonkey - 1]{
    MonkeyUpgrade{
        10,     //cost
        2,      //damage
        5,      //pierce
        5,      //radius
        50,     //detect radius
        200,    //home radius
        0.1f,      //firerate
        300,      //speed
        1000,       //lifetime
        -1,
        ProjectileBehaviour::HomingBoomerang
    },
    MonkeyUpgrade{
        20,     //cost
        3,      //damage
        7,      //pierce
        1,      //radius
        0,      //detect radius
        100,      //home radius
        1.f,      //firerate
        200,      //speed
        2000,       //lifetime
    }
};
//Tack
MonkeyUpgrade g_ArrTackUpgrades[g_AmountOfUpgradesPerMonkey - 1]{
    MonkeyUpgrade{
        10,     //cost
        1,      //damage
        10,      //pierce
        2,      //radius
        0,      //detect radius
        0,      //home radius
        1.f,    //firerate
        2,      //speed
        0,       //lifetime
        -1,
        ProjectileBehaviour::Ring
    },
    MonkeyUpgrade{
        20,     //cost
        2,      //damage
        0,      //pierce
        1,      //radius
        0,      //detect radius
        0,      //home radius
        2.f,    //firerate
        2,      //speed
        0       //lifetime
    }
};

//Monkey placing
int g_MonkeysOnBoard{ 0 };
Monkey* g_ArrMonkeys{ nullptr };

//Projectile
int g_MaxProjectilesOnBoard{};
int g_ProjectilesOnBoardAmount{};
Projectile* g_ArrProjectiles{nullptr};

// Declare your own functions here
void DrawBoard();
void DrawBloons();
void DrawMonkeys();

void StartWave();

void DrawUI();
void UpdateUIShopMenu(float elapsedSec);
void UpdateUIUpgradeMenu(float elapsedSec);
void UpdateUINextWave(float elapsedSec);
void UpdateUIButtonCollisions();
void DrawPreviewMonkey();
float DrawNumberSequenceTopCenter(int number, const Point2f& topCenter); //returns width
float DrawNumberSequenceTopLeft(int number, Point2f topLeft); //returns width

void SpawnBloon(const Point2f& spawnPoint, Bloon& bloon, int index);
void DestroyBloon(Bloon& bloon);
void DamageBloon(Bloon& bloon);
void UpdateBloons(float elapsedSec);

int GetRand(int min, int max);
float GetRand(float start, float end);

Bloon GetBloonFromIndex(int index);
Monkey GetMonkeyFromIndex(int index);
MonkeyUpgrade* GetMonkeyUpgradesFromIndex(int index);
void NormalizeVector(Point2f& vector);

void InitPath();

bool IsRectCollidingWithPath(const Rectf& rectangle);
bool IsCircleCollidingWithPath(const Circlef& circle);
bool IsValueInArray(const int* array, int arrayLength, int searchedValue);

void PlaceMonkey(const Point2f& position, const Monkey& monkey);

void UpdateMonkey(float elapsedSec);

void SwapProjectilesInArray(Projectile& proj1, Projectile& proj2);
void InitProjectiles(const Point2f& source, const Point2f& destination, const Projectile& projectile);
void UpdateProjectiles(float elapsedSec);
void DrawProjectiles();
void DeleteProjectile(Projectile& projectile);
void DeletePiercedBloonIds(Projectile& projectile);
void ResizeProjectileArray();
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
