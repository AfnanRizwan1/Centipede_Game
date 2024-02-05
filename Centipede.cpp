#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Initializing Dimensions.
// resolutionX and resolutionY determine the rendering resolution.
// Don't edit unless required. Use functions on lines 43, 44, 45 for resizing the game window.
const int resolutionX = 960;
const int resolutionY = 960;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionX / boxPixelsX; // Total rows on grid
const int gameColumns = resolutionY / boxPixelsY; // Total columns on grid

// Initializing GameGrid.
int gameGrid[gameRows][gameColumns] = {};

// The following exist purely for readability.
const int x = 0;
const int y = 1;
const int exists = 2;

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Write your functions declarations here. Some have been written for you. //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

// LEVEL 1
void drawPlayer(sf::RenderWindow& window, float player[], sf::Sprite& playerSprite, float bullet[]);  // This Function is used to draw the main player
void moveBullet(float bullet[], sf::Clock& bulletClock,	int& randMush,float mushroom1[][3],float mushroom2[][3], int& score,float centi[][3],sf::RenderWindow& window,sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite,bool revCheck[][2],float centihead[][3],sf::Sound& killSound,float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite, float flea[][3], float scorpian[][3],float mushroomScorpian[][3],float mushroomScorpian2[][3]);  // This Function is used to move the bullet
void drawBullet(sf::RenderWindow& window, float bullet[], sf::Sprite& bulletSprite, float player[]);   // This Function is used to draw the bullet sprite
void spawnMushrooms(sf::RenderWindow& window,sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite,bool& check, float bullet[], int& score,float mushroom1[][3],float mushroom2[][3],int& randMush, float player[],float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite,float mushroomScorpian[][3], sf::Sprite& mushroomScorpianSprite,float mushroomScorpian2[][3], sf::Sprite& mushroomScorpian2Sprite,int& lives,float mushroomExtra[][3],sf::Sprite& mushroomExtraSprite,float mushroomExtra2[][3],sf::Sprite& mushroomExtra2Sprite, int& mushCheck);   // I have made a complete sperate function for spawning mushrooms because it makes easier to spawn any kind of mushroom whether it be original, broken or poisonous mushroom
void drawCenti(sf::RenderWindow& window, float centi[][3], sf::Sprite& centiSprite, float bullet[]) ;   // This function is used to draw the centipede segments sprite
void moveCenti(float centi[][3], sf::Clock& centiClock, bool& move, int gameGrid[][gameColumns], float bullet[],float centihead[][3],bool revCheck[][2],float mushroom1[][3],float mushroom2[][3],int randMush,sf::RenderWindow& window,sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite, float player[], bool& lastCheck,float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite,int& lives,float mushroomScorpian[][3],float mushroomScorpian2[][3]);   // The purpose of making this function is to move centipede. Also it helps us to figure out the collision of centipede with various other things
void drawSpider(sf::RenderWindow& window, float spider[], sf::Sprite& spiderSprite);   //This function is used to draw the spider sprite
void moveSpider( float spider[], sf::Clock& spiderClock, int gameGrid[][gameColumns], float player[], float bullet[],sf::RenderWindow& window, sf::Sprite& scoreSprite3,float mushroom1[][3],float mushroom2[][3],int& randMush,sf::Clock& scoreTimer, int& score,sf::Sound& killSound, int& playerPosition,int& spiderPosition, int& lives);   //This function is used to move the spider sprite. Also it helps to figure out collision of spider with other things like muhsrooms and player
void drawScore(sf::RenderWindow& window, sf::Sprite& scoreSprite3,float spider[],sf::Clock& scoreTimer, sf::Time scoreDisplayDuration, int& score,int& playerPosition,int& spiderPosition, sf::Sprite& scoreSprite6, sf::Sprite& scoreSprite9);   //The purpose of this function is to navigate the distance between spider and player when the spider is killed by player and then display the score according to it
void drawHead(sf::RenderWindow& window, float centi[][3], sf::Sprite& centiheadSprite, float bullet[],float centihead[][3]);   //The putpose of this function is to draw the head sprite of centipede
void checkCollision(float bullet[], float centi[][3],bool revCheck[][2],sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite,int randMush,float mushroom1[][3],float mushroom2[][3],float centihead[][3],sf::RenderWindow& window, int& score,float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite,sf::Sound& killSound);   // This is a function made for checking purposes majorly the collision of bullet with centipede
void drawFlea(int gameGrid[][gameColumns],sf::RenderWindow& window, float bullet[], float mushroom1[][3], float mushroom2[][3],float flea[][3], sf::Sprite& fleaSprite, bool& checkFlag,int randMush);   //The purpose ofthis function is to draw the flea sprite
void moveFlea(float flea[][3], sf::Clock& fleaClock, bool& checkFlag,int& lives,float player[],float mushroomExtra[][3],int& mushCheck );   //The purpose of this function is to move the flea and also the detection of collision of player with flea
void drawScorpian(int gameGrid[][gameColumns],sf::RenderWindow& window, float bullet[], float mushroom1[][3], float mushroom2[][3],float scorpian[][3], sf::Sprite& scorpianSprite, bool& checkFlag,int randMush);   //This function is used to draw the scorpian sprite
void moveScorpian(float scorpian[][3], sf::Clock& scorpianClock, bool& checkFlag,float mushroomScorpian[][3],float mushroom1[][3],float mushroom2[][3],	int& randMush,int& lives, float player[]);   //The purpose of using this function is to move the scorpian and also for detection purposes
void drawExtra(float extrahead[][3],sf::Clock extraheadClock,sf::Sprite extraheadSprite, sf::RenderWindow& window, float centi[][3], float centihead[][3]);   //The purpose of this function is to draw the heads that come out of screen once the centipede enters player area
void moveExtra(float extrahead[][3], float centi[][3], float centihead[][3],sf::Clock extraheadClock, bool revHead[][2]);   //This function is used to move the extra heads

// LEVEL 2
void drawPlayerL2(sf::RenderWindow& window, float playerL2[], sf::Sprite& playerL2Sprite, float bulletL2[]);
void moveBulletL2(float bulletL2[], sf::Clock& bulletL2Clock,	int& randMush,float mushroom1L2[][3],float mushroom2L2[][3], int& score,float centiL2[][3],sf::RenderWindow& window,sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite,bool revCheckL2[][2],float centiheadL2[][3],sf::Sound& killSoundL2,float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite, float fleaL2[][3], float scorpianL2[][3],float mushroomScorpianL2[][3],float mushroomScorpian2L2[][3]);
void drawBulletL2(sf::RenderWindow& window, float bulletL2[], sf::Sprite& bulletL2Sprite, float playerL2[]);
void spawnMushroomsL2(sf::RenderWindow& window,sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite,bool& checkL2, float bulletL2[], int& scoreL2,float mushroom1L2[][3],float mushroom2L2[][3],int& randMush, float playerL2[],float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite,float mushroomScorpianL2[][3], sf::Sprite& mushroomScorpianL2Sprite,float mushroomScorpian2L2[][3], sf::Sprite& mushroomScorpian2L2Sprite,int& lives);
void drawCentiL2(sf::RenderWindow& window, float centiL2[][3], sf::Sprite& centiL2Sprite, float bulletL2[]) ;
void moveCentiL2(float centiL2[][3], sf::Clock& centiL2Clock, bool& moveL2, int gameGrid[][gameColumns], float bulletL2[],float centiheadL2[][3],bool revCheckL2[][2],float mushroom1L2[][3],float mushroom2L2[][3],int randMush,sf::RenderWindow& window,sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite, float playerL2[], bool& lastCheckL2,float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite,int& lives,float mushroomScorpianL2[][3],float mushroomScorpian2L2[][3], int& hitCheck);
void drawSpiderL2(sf::RenderWindow& window, float spiderL2[], sf::Sprite& spiderL2Sprite);
void moveSpiderL2( float spiderL2[], sf::Clock& spiderL2Clock, int gameGrid[][gameColumns], float playerL2[], float bulletL2[],sf::RenderWindow& window, sf::Sprite& scoreL2Sprite3,float mushroom1L2[][3],float mushroom2L2[][3],int& randMush,sf::Clock& scoreTimer, int& scoreL2,sf::Sound& killSoundL2, int& playerPosition2, int& spiderPosition2, int& lives);
void drawScoreL2(sf::RenderWindow& window, sf::Sprite& scoreL2Sprite3,float spiderL2[],sf::Clock& scoreTimer, sf::Time scoreDisplayDuration, int& score, int& playerPosition2, int& spiderPosition2,sf::Sprite& scoreL2Sprite6, sf::Sprite& scoreL2Sprite9);
void drawHeadL2(sf::RenderWindow& window, float centiL2[][3], sf::Sprite& centiheadL2Sprite, float bulletL2[],float centiheadL2[][3]);
void checkCollisionL2(float bulletL2[], float centiL2[][3],bool revCheckL2[][2],sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite,int randMush,float mushroom1L2[][3],float mushroom2L2[][3],float centiheadL2[][3],sf::RenderWindow& window, int& scoreL2,float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite,sf::Sound& killSoundL2);
void drawFleaL2(int gameGrid[][gameColumns],sf::RenderWindow& window, float bulletL2[], float mushroom1L2[][3], float mushroom2L2[][3],float fleaL2[][3], sf::Sprite& fleaL2Sprite, bool& checkFlagL2,int randMush);
void moveFleaL2(float fleaL2[][3], sf::Clock& fleaL2Clock, bool& checkFlagL2,int& lives,float playerL2[]);
void drawScorpianL2(int gameGrid[][gameColumns],sf::RenderWindow& window, float bulletL2[], float mushroom1L2[][3], float mushroom2L2[][3],float scorpianL2[][3], sf::Sprite& scorpianL2Sprite, bool& checkFlagL2,int randMush);
void moveScorpianL2(float scorpianL2[][3], sf::Clock& scorpianL2Clock, bool& checkFlagL2,float mushroomScorpianL2[][3],float mushroom1L2[][3],float mushroom2L2[][3],int& randMush, int& lives, float playerL2[]);


int main()
{
	srand(time(0));

	// Declaring RenderWindow.
	sf::RenderWindow window(sf::VideoMode(resolutionX, resolutionY), "Centipede", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

	// Used to resize your window if it's too big or too small. Use according to your needs.
	window.setSize(sf::Vector2u(640, 640)); // Recommended for 1366x768 (768p) displays.
	// window.setSize(sf::Vector2u(1280, 1280)); // Recommended for 2560x1440 (1440p) displays.
	// window.setSize(sf::Vector2u(1920, 1920)); // Recommended for 3840x2160 (4k) displays.
	
	// Used to position your window on every launch. Use according to your needs.
	window.setPosition(sf::Vector2i(100, 100));

	int level = 1;
	int lives = 6;
	int score = 0;
	int randMush = rand() % (11) + 20;	
	if(level==1)
{
	// Initializing Background Music.
	sf::Music bgMusic;
	bgMusic.openFromFile("Music/field_of_hopes.ogg");
	bgMusic.play();
	bgMusic.setVolume(50);

	// Initializing Background.
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;
	backgroundTexture.loadFromFile("Textures/backgroundn.png");
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setColor(sf::Color(255, 255, 255, 255 * 0.50)); // Reduces Opacity to 25%

	// Initializing Player and Player Sprites.
	float player[3] = {};
	player[x] = (gameColumns / 2) * boxPixelsX;
	player[y] = (gameColumns * 3 / 4) * boxPixelsY;
	player[exists] = true;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	playerTexture.loadFromFile("Textures/gun.png");
	playerSprite.setTexture(playerTexture);
	playerSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));

	// Initializing Bullet and Bullet Sprites.
	float bullet[3] = {};
	bullet[x] = player[x];
	bullet[y] = player[y] - boxPixelsY;
	bullet[exists] = false;
	sf::Clock bulletClock;
	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;
	bulletTexture.loadFromFile("Textures/bullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	
	int randomStart =  rand() % 21 + 10;
	randomStart *= 32;   //making a random start location for centipede

	// Centipede
	float centi[12][3] = {};   //centipede array
	for(int l=0; l<12; ++l)   //loops runs through 12 segments assigning the values to segments in such a way that the next segment is placed before the previous one
	{
    centi[l][x] = (randomStart+ (l*32));
    centi[l][y] = 0;
    centi[l][exists] = true;
	}
	sf::Clock centiClock;
	sf::Texture centiTexture;
	sf::Sprite centiSprite;
	centiTexture.loadFromFile("Textures/12_segments_32x.png");
	centiSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	centiSprite.setTexture(centiTexture);


	// Centipede Head
	float centihead[12][3] = {};   //centipede head array
	for(int k=0; k<12; k++)   
	{
	centihead[k][x] = centi[k][x];   //assigning each centipedesegment a head
	centihead[k][y] = centi[k][y];
	if(k>0)
	{
	centihead[k][exists] = false;   //making all other head's existance to false because initially we only need first one
	}
	if(k==0)
	{
	centihead[0][exists] = true;   //making the first head true and the first head is basically placed on first segment so in total 12 segments
	}
	}
	sf::Clock centiheadClock;
	sf::Texture centiheadTexture;
	sf::Sprite centiheadSprite;
	centiheadTexture.loadFromFile("Textures/12_headsegments_32x.png");
	centiheadSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	centiheadSprite.setTexture(centiheadTexture);


	// Spider
	float spider[3] = {};   //spider array
	spider[x] = rand() % resolutionX;   //assigned the spider a random x position
	spider[y] = resolutionY-boxPixelsY;   //spider rises from ground
	spider[exists] = true;
	sf::Clock spiderClock;
	sf::Texture spiderTexture;
	sf::Sprite spiderSprite;
	spiderTexture.loadFromFile("Textures/spider_and_score.png");
	spiderSprite.setTexture(spiderTexture);
	spiderSprite.setTextureRect(sf::IntRect(0, 0, 2*boxPixelsX,boxPixelsY));	
	spiderSprite.setColor(sf::Color(255, 255, 255));


	int randRow;
	int randCol;

	// Initializing the original Mushrooms
	float mushroom1[randMush][3] = {};  //original mushroom array

	for(int i=0; i<randMush; i++)
	{
		randRow = ((rand() % (gameRows - 2)) + 1) * 32;   //assigning random row
		randCol = ((rand() % (gameColumns - 2)) + 1) * 32;   //assigning random column

		mushroom1[i][x] = randRow;   //assiging mushrrom the random value 
		mushroom1[i][y] = randCol;
		mushroom1[i][exists] = true;
	}

	sf::Texture mushroom1Textures;
	sf::Sprite mushroom1Sprite;
	mushroom1Textures.loadFromFile("Textures/mushorg(1).png");
	mushroom1Sprite.setTexture(mushroom1Textures);
	mushroom1Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroom1Sprite.setColor(sf::Color(255, 255, 255,255));

	// Initializing the updated mushroom
	float mushroom2[randMush][3] = {};
	for(int i=0; i<randMush; i++)
	{
		mushroom2[i][x] = -64;
		mushroom2[i][y] = -64;
		mushroom2[i][exists] = false;
	}
	sf::Texture mushroom2Textures;
	sf::Sprite mushroom2Sprite;
	mushroom2Textures.loadFromFile("Textures/mushdef(1).png");
	mushroom2Sprite.setTexture(mushroom2Textures);
	mushroom2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroom2Sprite.setColor(sf::Color(255, 255, 255, 255));

	// initializing the Mushrooms created when centipede breaks
	float mushroomNew[12][3] = {};
	for(int i=0; i<12; i++)
	{
		mushroomNew[i][x] = -70;
		mushroomNew[i][y] = -70;
		mushroomNew[i][exists] = false;
	}	
	sf::Texture mushroomNewTextures;
	sf::Sprite mushroomNewSprite;
	mushroomNewTextures.loadFromFile("Textures/mushorg(1).png");
	mushroomNewSprite.setTexture(mushroomNewTextures);
	mushroomNewSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroomNewSprite.setColor(sf::Color(255, 255, 255, 255));


	// initializing the updated centipede mushroom
	float mushroomNew2[12][3] = {};
	for(int i=0; i<12; i++)
	{

		mushroomNew2[i][x] = -90;
		mushroomNew2[i][y] = -90;
		mushroomNew2[i][exists] = false;
	}	
	sf::Texture mushroomNew2Textures;
	sf::Sprite mushroomNew2Sprite;
	mushroomNew2Textures.loadFromFile("Textures/mushdef(1).png");
	mushroomNew2Sprite.setTexture(mushroomNew2Textures);
	mushroomNew2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroomNew2Sprite.setColor(sf::Color(255, 255, 255, 255));

	// initializing the poisonous mushroom created by centipede in player area
	float mushroomPoison[12][3] = {};
	for(int i=0; i<12; i++)
	{

		mushroomPoison[i][x] = -70;
		mushroomPoison[i][y] = -70;
		mushroomPoison[i][exists] = false;
	}	
	sf::Texture mushroomPoisonTextures;
	sf::Sprite mushroomPoisonSprite;
	mushroomPoisonTextures.loadFromFile("Textures/mushroom.png");
	mushroomPoisonSprite.setTexture(mushroomPoisonTextures);
	mushroomPoisonSprite.setTextureRect(sf::IntRect(0, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomPoisonSprite.setColor(sf::Color(255, 255, 255, 255));

	// initializing the broken poisonous mushroom created by centipede in player area
	float mushroomPoisonN[12][3] = {};
	for(int i=0; i<12; i++)
	{
		mushroomPoisonN[i][x] = -85;
		mushroomPoisonN[i][y] = -85;
		mushroomPoisonN[i][exists] = false;
	}	
	sf::Texture mushroomPoisonNTextures;
	sf::Sprite mushroomPoisonNSprite;
	mushroomPoisonNTextures.loadFromFile("Textures/mushroom.png");
	mushroomPoisonNSprite.setTexture(mushroomPoisonNTextures);
	mushroomPoisonNSprite.setTextureRect(sf::IntRect(boxPixelsX, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomPoisonNSprite.setColor(sf::Color(255, 255, 255, 255));


	sf::SoundBuffer buffer;   //sound used when bullet shoots
	if(!buffer.loadFromFile("Sound Effects/laser_sound.wav"))
	{
		return -1;
	}

	sf::Sound bulletSound;
	bulletSound.setBuffer(buffer);

	sf::SoundBuffer killbuffer;   //sound when someone is killed
	if(!killbuffer.loadFromFile("Sound Effects/kill.wav"))
	{
		return -1;
	}

	sf::Sound killSound;
	killSound.setBuffer(killbuffer);
	// killSound.setLoop(true);

	// spider 300 score
	sf::Texture scoreTexture3;
	sf::Sprite scoreSprite3;
	scoreTexture3.loadFromFile("Textures/spider_and_score.png");
	scoreSprite3.setTexture(scoreTexture3);
	scoreSprite3.setTextureRect(sf::IntRect(0, boxPixelsY, 2*boxPixelsX, boxPixelsY));
	scoreSprite3.setColor(sf::Color(255, 255, 255, 255));

	// spider 600 score
	sf::Texture scoreTexture6;
	sf::Sprite scoreSprite6;
	scoreTexture6.loadFromFile("Textures/spider_and_score.png");
	scoreSprite6.setTexture(scoreTexture6);
	scoreSprite6.setTextureRect(sf::IntRect(2*boxPixelsX, boxPixelsY, 2*boxPixelsX, boxPixelsY));
	scoreSprite6.setColor(sf::Color(255, 255, 255, 255));

	// spider 900 score
	sf::Texture scoreTexture9;
	sf::Sprite scoreSprite9;
	scoreTexture9.loadFromFile("Textures/spider_and_score.png");
	scoreSprite9.setTexture(scoreTexture9);
	scoreSprite9.setTextureRect(sf::IntRect(4*boxPixelsX, boxPixelsY, 2*boxPixelsX, boxPixelsY));
	scoreSprite9.setColor(sf::Color(255, 255, 255, 255));

	// Initializing Flea and Flea Sprites.
	const int maxFleas = 50;   //flea array
	float flea[maxFleas][3] = {};

	for(int i=0; i<maxFleas; i++)
	{
	int randomFlea =  rand() % 21 + 10;   //giving fleas a random initial position each time
	randomFlea *= 32;

	flea[i][x]= randomFlea;
	flea[i][y]= 0;
	flea[i][exists]=false;
	}
	flea[0][exists]=true;
	sf::Clock fleaClock;
	sf::Texture fleaTexture;
	sf::Sprite fleaSprite;
	fleaTexture.loadFromFile("Textures/flea.png");
	fleaSprite.setTexture(fleaTexture);
	fleaSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));

	// Initializing scorpian and scorpian Sprites.
	const int maxScorpian = 50;
	float scorpian[maxScorpian][3] = {};   //scorpian array

	for(int i=0; i<maxScorpian; i++)
	{
	int randomScorpian =  rand() % 11 + 10;   //giving scorpians a random initial position each time
	randomScorpian *= 32;

	scorpian[i][y]= randomScorpian;
	scorpian[i][x]= 0;
	scorpian[i][exists]=false;
	}
	scorpian[0][exists]=true;
	sf::Clock scorpianClock;
	sf::Texture scorpianTexture;
	sf::Sprite scorpianSprite;
	scorpianTexture.loadFromFile("Textures/scorpion.png");
	scorpianSprite.setTexture(scorpianTexture);
	scorpianSprite.setTextureRect(sf::IntRect(0, 0, 2*boxPixelsX, boxPixelsY));

	// initializing the poisonous mushroom created by scorpian
	float mushroomScorpian[randMush][3] = {};
	for(int i=0; i<randMush; i++)
	{
		mushroomScorpian[i][x] = -95;
		mushroomScorpian[i][y] = -95;
		mushroomScorpian[i][exists] = false;
	}	
	sf::Texture mushroomScorpianTextures;
	sf::Sprite mushroomScorpianSprite;
	mushroomScorpianTextures.loadFromFile("Textures/mushroom.png");
	mushroomScorpianSprite.setTexture(mushroomScorpianTextures);
	mushroomScorpianSprite.setTextureRect(sf::IntRect(0, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomScorpianSprite.setColor(sf::Color(255, 255, 255, 255));

	// initializing the broken poisonous mushroom created by scorpian
	float mushroomScorpian2[randMush][3] = {};
	for(int i=0; i<randMush; i++)
	{
		mushroomScorpian2[i][x] = -105;
		mushroomScorpian2[i][y] = -105;
		mushroomScorpian2[i][exists] = false;
	}	
	sf::Texture mushroomScorpian2Textures;
	sf::Sprite mushroomScorpian2Sprite;
	mushroomScorpian2Textures.loadFromFile("Textures/mushroom.png");
	mushroomScorpian2Sprite.setTexture(mushroomScorpian2Textures);
	mushroomScorpian2Sprite.setTextureRect(sf::IntRect(boxPixelsX, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomScorpian2Sprite.setColor(sf::Color(255, 255, 255, 255));


	int size = 50*30;
	float mushroomExtra[size][3] = {};
	for(int i=0; i<size; i++)
	{
		mushroomExtra[i][x] = -987;
		mushroomExtra[i][y] = -987;
		mushroomExtra[i][exists] = false;
	}
	sf::Texture mushroomExtraTextures;
	sf::Sprite mushroomExtraSprite;
	mushroomExtraTextures.loadFromFile("Textures/mushorg(1).png");
	mushroomExtraSprite.setTexture(mushroomExtraTextures);
	mushroomExtraSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroomExtraSprite.setColor(sf::Color(255, 255, 255,255));	


	// Muhsroom Flea broken
	float mushroomExtra2[size][3] = {};
	for(int i=0; i<size; i++)
	{
		mushroomExtra2[i][x] = -987;
		mushroomExtra2[i][y] = -987;
		mushroomExtra2[i][exists] = false;
	}
	sf::Texture mushroomExtra2Textures;
	sf::Sprite mushroomExtra2Sprite;
	mushroomExtra2Textures.loadFromFile("Textures/mushdef(1).png");
	mushroomExtra2Sprite.setTexture(mushroomExtra2Textures);
	mushroomExtra2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroomExtra2Sprite.setColor(sf::Color(255, 255, 255,255));

	// initaializing Extra Heads
	float extrahead[20][3] = {};   //extra heads array
	for(int k=0; k<20; k++)
	{

		int randomHead =  (rand() % 8 + 23);   //random initial position
		randomHead *= 32;

		extrahead[k][x] = resolutionX+32 ;
		extrahead[k][y] = randomHead;
		extrahead[k][exists] = true;
	}
	sf::Clock extraheadClock;
	sf::Texture extraheadTexture;
	sf::Sprite extraheadSprite;
	extraheadTexture.loadFromFile("Textures/12_headsegments_32x.png");
	extraheadSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	extraheadSprite.setTexture(extraheadTexture);	 

	bool check=false;
	bool move = false;
	bool checkFlag = false;
	int playerPosition;
	int spiderPosition;
	int mushCheck = 0;
	bool headCheck = false;
	bool levelCheck=false;
	int strikeCount = 0;
	bool lastCheck=true;
	bool moveLeft = false;
	bool moveFront = false;
	bool revCheck[12][2];
	bool revHead[20][2];	
	bool scoreCheck=false;
    sf::Clock scoreTimer;
    sf::Time scoreDisplayDuration = sf::seconds(1.0f);

	for(int i=0; i<12; i++)
	{
		revCheck[i][1] = false;   //bool array used to check the direction of centipede
	}

	for(int i=0; i<20; i++)
	{
		revHead[i][1] = false;   //used to check the direction of extra heads
	}
	
	sf::Font font;
	font.loadFromFile("GA1.ttf");
	sf::Text scoreText;   //score text
	scoreText.setFont(font);
	scoreText.setCharacterSize(36);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setStyle(sf::Text::Underlined); 
	scoreText.setStyle(sf::Text::Italic); 
	scoreText.setPosition(0,0);

	sf::Font levelfont;
	levelfont.loadFromFile("GA1.ttf");
	sf::Text levelText;   //level text
	levelText.setFont(levelfont);
	levelText.setCharacterSize(36);
	levelText.setFillColor(sf::Color::White);
	levelText.setStyle(sf::Text::Bold);
	levelText.setStyle(sf::Text::Underlined); 
	levelText.setStyle(sf::Text::Italic); 
	levelText.setPosition(0,resolutionX-64);

	sf::Font livesfont;
	livesfont.loadFromFile("GA1.ttf");
	sf::Text livesText;   //lives text
	livesText.setFont(livesfont);
	livesText.setCharacterSize(36);
	livesText.setFillColor(sf::Color::White);
	livesText.setStyle(sf::Text::Bold);
	livesText.setStyle(sf::Text::Underlined); 
	livesText.setStyle(sf::Text::Italic); 
	livesText.setPosition(resolutionX-128,resolutionY-64);

	
	while(window.isOpen()) {

		///////////////////////////////////////////////////////////////
		//                                                           //
		// Call Your Functions Here. Some have been written for you. //
		// Be vary of the order you call them, SFML draws in order.  //
		//                                                           //
		///////////////////////////////////////////////////////////////
		
		spawnMushrooms(window,mushroom1Sprite,mushroom2Sprite,check,bullet,score,mushroom1,mushroom2,randMush,player,mushroomNew,mushroomNewSprite,mushroomNew2,mushroomNew2Sprite,mushroomPoison,mushroomPoisonSprite,mushroomPoisonN,mushroomPoisonNSprite,mushroomScorpian,mushroomScorpianSprite,mushroomScorpian2,mushroomScorpian2Sprite,lives,mushroomExtra,mushroomExtraSprite,mushroomExtra2,mushroomExtra2Sprite,mushCheck);   //function called to spawn mushrooms
		window.draw(backgroundSprite);   //called to print background
		if(player[exists] == true)
		{
		drawPlayer(window, player, playerSprite,bullet);   //to draw the player
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))   //to shoot the bullet
		{
    	bullet[exists] = true;
		bullet[x] = player[x];
		bullet[y] = player[y] - boxPixelsY;
		bulletSound.play();   //bullet shoot sound
		
		}
		
		if(bullet[exists] == true)
		{ 
        drawBullet(window, bullet, bulletSprite, player);   //to draw bullet
        moveBullet(bullet,bulletClock,randMush,mushroom1,mushroom2,score,centi,window,mushroom1Sprite,mushroom2Sprite,revCheck,centihead,killSound,mushroomNew,mushroomNewSprite,mushroomNew2,mushroomNew2Sprite,mushroomPoison,mushroomPoisonSprite,mushroomPoisonN,mushroomPoisonNSprite,flea,scorpian,mushroomScorpian,mushroomScorpian2);   //to move bullet
		}


		for(int k=0; k<12; k++)
		{
		if(centi[k][exists]==true)
		{
		drawCenti(window, centi, centiSprite, bullet);   //to draw centipede
		moveCenti(centi, centiClock, move, gameGrid,bullet,centihead,revCheck,mushroom1,mushroom2,randMush,window,mushroom1Sprite,mushroom2Sprite,player,lastCheck,mushroomNew,mushroomNewSprite,mushroomNew2,mushroomNew2Sprite,mushroomPoison,mushroomPoisonSprite,mushroomPoisonN,mushroomPoisonNSprite,lives,mushroomScorpian,mushroomScorpian2);   //to move centipede
		}
		else
		{
			if(centi[k][exists]==false)
			{
				continue;
			}
		}
		}


		for(int i=0; i<12; i++)
		{
		if (centihead[i][exists]==true) 
		{
			drawHead(window,centi,centiheadSprite,bullet,centihead);   //to draw centipede's heads
		}
		else
		{
			if(centihead[i][exists]==false)
			{
				continue;
			}
		}
		}


		if (spider[exists] == true) 
		{
			drawSpider(window, spider, spiderSprite);   //to draw spider
			moveSpider(spider, spiderClock, gameGrid,player,bullet,window,scoreSprite3,mushroom1,mushroom2,randMush,scoreTimer,score,killSound,playerPosition,spiderPosition,lives);   //to move spider
			// spiderSound.play();
		}


		if(spider[exists]==false)
		{
			drawScore(window,scoreSprite3,spider,scoreTimer,scoreDisplayDuration,score,playerPosition,spiderPosition,scoreSprite6,scoreSprite9);   //to draw the score produced when spider is killed
		}


		for(int i=0; i<maxFleas; i++)
		{
			if(flea[i][exists]==true)
			{
		drawFlea(gameGrid,window,bullet,mushroom1,mushroom2,flea,fleaSprite,checkFlag,randMush);   //to draw flea
		moveFlea(flea,fleaClock,checkFlag,lives,player,mushroomExtra,mushCheck);   //to move flea
			}
		}

		for(int i=0; i<maxScorpian; i++)
		{
			if(scorpian[i][exists]==true)
			{
		drawScorpian(gameGrid,window,bullet,mushroom1,mushroom2,scorpian,scorpianSprite,checkFlag,randMush);   //to draw scorpian
		moveScorpian(scorpian,scorpianClock,checkFlag,mushroomScorpian,mushroom1,mushroom2,randMush,lives,player);   //to move scorpian
			}
		}

		drawExtra(extrahead,extraheadClock,extraheadSprite,window,centi,centihead);   //to draw extra heads
		moveExtra(extrahead,centi,centihead,extraheadClock,revHead);   //to move extra heads

		if(lives==0)
		{break;}

		if(score == 10000 || score == 12000 || score == 15000 || score == 20000)   //increase lives at these scores
		{
			lives++;
		}


		for(int i=0; i<12; i++)
		{
			if(centi[i][exists]==false && centihead[i][exists]==false)
			{
				levelCheck=true;
			}
			else
			{
				levelCheck=false;
				break;
			}

		}

		for(int i=0; i<12; i++)
		{
			if(centi[i][exists]==false)
			{
				headCheck = true;
			}
			else
			{
				headCheck=false;
				break;
			}
		}

		if(headCheck==true)
		{
			for(int k=0; k<12; k++)
			{
				centihead[k][exists] = false;
			}
		}



		if(levelCheck==true)
		{
			level++;
			levelCheck=false;
			break;
		}




		scoreText.setString("Score: " + std::to_string(score));
    	window.draw(scoreText);

		levelText.setString("Level: " + std::to_string(level));
    	window.draw(levelText);

		livesText.setString("Lives: " + std::to_string(lives));
    	window.draw(livesText);

		sf::Event e;
		while (window.pollEvent(e)) 
		{
			if (e.type == sf::Event::Closed) 
			{
				return 0;
			}
		}		
		window.display();
		window.clear();
	}
}

//Level 2

if(level==2)
{

	// Initializing Background Music.
	sf::Music bgMusic;
	bgMusic.openFromFile("Music/field_of_hopes.ogg");
	bgMusic.play();
	bgMusic.setVolume(50);

	// Initializing Background.
	sf::Texture backgroundL2Texture;
	sf::Sprite backgroundL2Sprite;
	backgroundL2Texture.loadFromFile("Textures/bgn.png");
	backgroundL2Sprite.setTexture(backgroundL2Texture);
	backgroundL2Sprite.setColor(sf::Color(255, 255, 255, 255 * 0.50)); // Reduces Opacity to 25%
			std::cout<<true;
	// Initializing Player and Player Sprites.
	float playerL2[3] = {};
	playerL2[x] = (gameColumns / 2) * boxPixelsX;
	playerL2[y] = (gameColumns * 3 / 4) * boxPixelsY;
	playerL2[exists] = true;
	sf::Texture playerL2Texture;
	sf::Sprite playerL2Sprite;
	playerL2Texture.loadFromFile("Textures/shipnew.png");
	playerL2Sprite.setTexture(playerL2Texture);
	playerL2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));

	// Initializing Bullet and Bullet Sprites.
	float bulletL2[3] = {};
	bulletL2[x] = playerL2[x];
	bulletL2[y] = playerL2[y] - boxPixelsY;
	bulletL2[exists] = false;
	sf::Clock bulletL2Clock;
	sf::Texture bulletL2Texture;
	sf::Sprite bulletL2Sprite;
	bulletL2Texture.loadFromFile("Textures/bullet.png");
	bulletL2Sprite.setTexture(bulletL2Texture);
	bulletL2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	
	int randomStart =  rand() % 21 + 10;
	randomStart *= 32;

	// Centipede
	float centiL2[12][3] = {};
	for(int l=0; l<12; ++l)
	{
    centiL2[l][x] = (randomStart+ (l*32));
    centiL2[l][y] = 0;
    centiL2[l][exists] = true;
	}
	sf::Clock centiL2Clock;
	sf::Texture centiL2Texture;
	sf::Sprite centiL2Sprite;
	centiL2Texture.loadFromFile("Textures/body1.png");
	centiL2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	centiL2Sprite.setTexture(centiL2Texture);


	// Centipede Head
	float centiheadL2[12][3] = {};
	for(int k=0; k<12; k++)
	{
	centiheadL2[k][x] = centiL2[k][x]; 
	centiheadL2[k][y] = centiL2[k][y];
	if(k>0)
	{
	centiheadL2[k][exists] = false;
	}
	if(k==0)
	{
	centiheadL2[0][exists] = true;	
	}
	}
	sf::Clock centiheadL2Clock;
	sf::Texture centiheadL2Texture;
	sf::Sprite centiheadL2Sprite;
	centiheadL2Texture.loadFromFile("Textures/head8.png");
	centiheadL2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	centiheadL2Sprite.setTexture(centiheadL2Texture);


	// Spider
	float spiderL2[3] = {};
	spiderL2[x] = rand() % resolutionX;
	spiderL2[y] = resolutionY-boxPixelsY;
	spiderL2[exists] = true;
	sf::Clock spiderL2Clock;
	sf::Texture spiderL2Texture;
	sf::Sprite spiderL2Sprite;
	spiderL2Texture.loadFromFile("Textures/spider_and_score.png");
	spiderL2Sprite.setTexture(spiderL2Texture);
	spiderL2Sprite.setTextureRect(sf::IntRect(0, 0, 2*boxPixelsX,boxPixelsY));	
	spiderL2Sprite.setColor(sf::Color(255, 0, 255));


	randMush += (0.2 * randMush);
	int randRow;
	int randCol;

	// Setting Mushrooms
	float mushroom1L2[randMush][3] = {};

	for(int i=0; i<randMush; i++)
	{
		randRow = ((rand() % (gameRows - 2)) + 1) * 32;
		randCol = ((rand() % (gameColumns - 2)) + 1) * 32;

		mushroom1L2[i][x] = randRow;
		mushroom1L2[i][y] = randCol;
		mushroom1L2[i][exists] = true;
	}

	sf::Texture mushroom1L2Textures;
	sf::Sprite mushroom1L2Sprite;
	mushroom1L2Textures.loadFromFile("Textures/shroom(1).png");
	mushroom1L2Sprite.setTexture(mushroom1L2Textures);
	mushroom1L2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroom1L2Sprite.setColor(sf::Color(255, 255, 255));

	// Initializing the updated mushroom
	float mushroom2L2[randMush][3] = {};
	for(int i=0; i<randMush; i++)
	{
		mushroom2L2[i][x] = -64;
		mushroom2L2[i][y] = -64;
		mushroom2L2[i][exists] = false;
	}
	sf::Texture mushroom2L2Textures;
	sf::Sprite mushroom2L2Sprite;
	mushroom2L2Textures.loadFromFile("Textures/shroom2(1)(1).png");
	mushroom2L2Sprite.setTexture(mushroom2L2Textures);
	mushroom2L2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroom2L2Sprite.setColor(sf::Color(255, 255, 255, 255));

	// Centi Mushroom
	float mushroomNewL2[12][3] = {};
	for(int i=0; i<12; i++)
	{

		mushroomNewL2[i][x] = -70;
		mushroomNewL2[i][y] = -70;
		mushroomNewL2[i][exists] = false;
	}	
	sf::Texture mushroomNewL2Textures;
	sf::Sprite mushroomNewL2Sprite;
	mushroomNewL2Textures.loadFromFile("Textures/shroom(1).png");
	mushroomNewL2Sprite.setTexture(mushroomNewL2Textures);
	mushroomNewL2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroomNewL2Sprite.setColor(sf::Color(255, 255, 255, 255));


	// Centi Mushroom broke
	float mushroomNew2L2[12][3] = {};
	for(int i=0; i<12; i++)
	{

		mushroomNew2L2[i][x] = -90;
		mushroomNew2L2[i][y] = -90;
		mushroomNew2L2[i][exists] = false;
	}	
	sf::Texture mushroomNew2L2Textures;
	sf::Sprite mushroomNew2L2Sprite;
	mushroomNew2L2Textures.loadFromFile("Textures/shroom2(1)(1).png");
	mushroomNew2L2Sprite.setTexture(mushroomNew2L2Textures);
	mushroomNew2L2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));
	mushroomNew2L2Sprite.setColor(sf::Color(255, 255, 255, 255));

	// Mushrom poison
	float mushroomPoisonL2[12][3] = {};
	for(int i=0; i<12; i++)
	{

		mushroomPoisonL2[i][x] = -70;
		mushroomPoisonL2[i][y] = -70;
		mushroomPoisonL2[i][exists] = false;
	}	
	sf::Texture mushroomPoisonL2Textures;
	sf::Sprite mushroomPoisonL2Sprite;
	mushroomPoisonL2Textures.loadFromFile("Textures/mushroom.png");
	mushroomPoisonL2Sprite.setTexture(mushroomPoisonL2Textures);
	mushroomPoisonL2Sprite.setTextureRect(sf::IntRect(0, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomPoisonL2Sprite.setColor(sf::Color(255, 255, 255, 255));

	// Mushrom poison broke
	float mushroomPoisonNL2[12][3] = {};
	for(int i=0; i<12; i++)
	{
		mushroomPoisonNL2[i][x] = -85;
		mushroomPoisonNL2[i][y] = -85;
		mushroomPoisonNL2[i][exists] = false;
	}	
	sf::Texture mushroomPoisonNL2Textures;
	sf::Sprite mushroomPoisonNL2Sprite;
	mushroomPoisonNL2Textures.loadFromFile("Textures/mushroom.png");
	mushroomPoisonNL2Sprite.setTexture(mushroomPoisonNL2Textures);
	mushroomPoisonNL2Sprite.setTextureRect(sf::IntRect(boxPixelsX, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomPoisonNL2Sprite.setColor(sf::Color(255, 255, 255, 255));


	sf::SoundBuffer bufferL2;
	if(!bufferL2.loadFromFile("Sound Effects/laser_sound.wav"))
	{
		return -1;
	}

	sf::Sound bulletSoundL2;
	bulletSoundL2.setBuffer(bufferL2);

	sf::SoundBuffer killbufferL2;
	if(!killbufferL2.loadFromFile("Sound Effects/kill.wav"))
	{
		return -1;
	}

	sf::Sound killSoundL2;
	killSoundL2.setBuffer(killbufferL2);
	// killSound.setLoop(true);

	// spider 300
	sf::Texture scoreL2Texture6;
	sf::Sprite scoreL2Sprite6;
	scoreL2Texture6.loadFromFile("Textures/spider_and_score.png");
	scoreL2Sprite6.setTexture(scoreL2Texture6);
	scoreL2Sprite6.setTextureRect(sf::IntRect(0, boxPixelsY, 2*boxPixelsX, boxPixelsY));
	scoreL2Sprite6.setColor(sf::Color(255, 255, 255, 255));

	// spider 600
	sf::Texture scoreL2Texture9;
	sf::Sprite scoreL2Sprite9;
	scoreL2Texture9.loadFromFile("Textures/spider_and_score.png");
	scoreL2Sprite9.setTexture(scoreL2Texture9);
	scoreL2Sprite9.setTextureRect(sf::IntRect(2*boxPixelsX, boxPixelsY, 2*boxPixelsX, boxPixelsY));
	scoreL2Sprite9.setColor(sf::Color(255, 255, 255, 255));

	// spider 900
	sf::Texture scoreL2Texture3;
	sf::Sprite scoreL2Sprite3;
	scoreL2Texture3.loadFromFile("Textures/spider_and_score.png");
	scoreL2Sprite3.setTexture(scoreL2Texture3);
	scoreL2Sprite3.setTextureRect(sf::IntRect(4*boxPixelsX, boxPixelsY, 2*boxPixelsX, boxPixelsY));
	scoreL2Sprite3.setColor(sf::Color(255, 255, 255, 255));

	// Initializing Flea and Flea Sprites.
	const int maxFleas = 50;
	float fleaL2[maxFleas][3] = {};

	for(int i=0; i<maxFleas; i++)
	{
	int randomFlea =  rand() % 21 + 10;
	randomFlea *= 32;

	fleaL2[i][x]= randomFlea;
	fleaL2[i][y]= 0;
	fleaL2[i][exists]=false;
	}
	fleaL2[0][exists]=true;
	sf::Clock fleaL2Clock;
	sf::Texture fleaL2Texture;
	sf::Sprite fleaL2Sprite;
	fleaL2Texture.loadFromFile("Textures/flea.png");
	fleaL2Sprite.setTexture(fleaL2Texture);
	fleaL2Sprite.setColor(sf::Color(255, 0, 255));
	fleaL2Sprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));

	// Initializing scorpian and scorpian Sprites.
	const int maxScorpian = 50;
	float scorpianL2[maxScorpian][3] = {};

	for(int i=0; i<maxScorpian; i++)
	{
	int randomScorpian =  rand() % 11 + 10;
	randomScorpian *= 32;

	scorpianL2[i][y]= randomScorpian;
	scorpianL2[i][x]= 0;
	scorpianL2[i][exists]=false;
	}
	scorpianL2[0][exists]=true;
	sf::Clock scorpianL2Clock;
	sf::Texture scorpianL2Texture;
	sf::Sprite scorpianL2Sprite;
	scorpianL2Texture.loadFromFile("Textures/scorpion.png");
	scorpianL2Sprite.setTexture(scorpianL2Texture);
	scorpianL2Sprite.setColor(sf::Color(255, 0, 255));	
	scorpianL2Sprite.setTextureRect(sf::IntRect(0, 0, 2*boxPixelsX, boxPixelsY));

	// Mushrom scorpian
	float mushroomScorpianL2[randMush][3] = {};
	for(int i=0; i<randMush; i++)
	{
		mushroomScorpianL2[i][x] = -95;
		mushroomScorpianL2[i][y] = -95;
		mushroomScorpianL2[i][exists] = false;
	}	
	sf::Texture mushroomScorpianL2Textures;
	sf::Sprite mushroomScorpianL2Sprite;
	mushroomScorpianL2Textures.loadFromFile("Textures/mushroom.png");
	mushroomScorpianL2Sprite.setTexture(mushroomScorpianL2Textures);
	mushroomScorpianL2Sprite.setTextureRect(sf::IntRect(0, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomScorpianL2Sprite.setColor(sf::Color(255, 255, 255, 255));

		// Mushrom scorpian broken
	float mushroomScorpian2L2[randMush][3] = {};
	for(int i=0; i<randMush; i++)
	{
		mushroomScorpian2L2[i][x] = -105;
		mushroomScorpian2L2[i][y] = -105;
		mushroomScorpian2L2[i][exists] = false;
	}	
	sf::Texture mushroomScorpian2L2Textures;
	sf::Sprite mushroomScorpian2L2Sprite;
	mushroomScorpian2L2Textures.loadFromFile("Textures/mushroom.png");
	mushroomScorpian2L2Sprite.setTexture(mushroomScorpian2L2Textures);
	mushroomScorpian2L2Sprite.setTextureRect(sf::IntRect(boxPixelsX, boxPixelsY, boxPixelsX, boxPixelsY));
	mushroomScorpian2L2Sprite.setColor(sf::Color(255, 255, 255, 255));

	bool checkL2=false;
	bool moveL2 = false;
	bool checkFlagL2 = false;
	bool levelCheckL2=false;
	bool headCheckL2=false;
	int playerPosition2;
	int spiderPosition2;
	int strikeCountL2 = 0;
	bool lastCheckL2=true;
	bool moveLeftL2 = false;
	bool moveFrontL2 = false;
	bool revCheckL2[12][2];
	bool scoreCheckL2=false;
	int hitCheck = 0;
    sf::Clock scoreTimer; // Declare a clock to measure time
    sf::Time scoreDisplayDuration = sf::seconds(1.0f);

	for(int i=0; i<12; i++)
	{
		revCheckL2[i][1] = false;
	}
	
	sf::Font font;
	font.loadFromFile("GA1.ttf"); // Replace with your font file
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setCharacterSize(36);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setStyle(sf::Text::Bold);
	scoreText.setStyle(sf::Text::Underlined); 
	scoreText.setStyle(sf::Text::Italic); 
	scoreText.setPosition(0,0);

	sf::Font levelfont;
	levelfont.loadFromFile("GA1.ttf"); // Replace with your font file
	sf::Text levelText;
	levelText.setFont(levelfont);
	levelText.setCharacterSize(36);
	levelText.setFillColor(sf::Color::White);
	levelText.setStyle(sf::Text::Bold);
	levelText.setStyle(sf::Text::Underlined); 
	levelText.setStyle(sf::Text::Italic); 
	levelText.setPosition(0,resolutionX-64);

	sf::Font livesfont;
	livesfont.loadFromFile("GA1.ttf");
	sf::Text livesText;
	livesText.setFont(livesfont);
	livesText.setCharacterSize(36);
	livesText.setFillColor(sf::Color::White);
	livesText.setStyle(sf::Text::Bold);
	livesText.setStyle(sf::Text::Underlined); 
	livesText.setStyle(sf::Text::Italic); 
	livesText.setPosition(resolutionX-128,resolutionY-64);	

	
	while(window.isOpen()) {

		///////////////////////////////////////////////////////////////
		//                                                           //
		// Call Your Functions Here. Some have been written for you. //
		// Be vary of the order you call them, SFML draws in order.  //
		//                                                           //
		///////////////////////////////////////////////////////////////
		
		spawnMushroomsL2(window,mushroom1L2Sprite,mushroom2L2Sprite,checkL2,bulletL2,score,mushroom1L2,mushroom2L2,randMush,playerL2,mushroomNewL2,mushroomNewL2Sprite,mushroomNew2L2,mushroomNew2L2Sprite,mushroomPoisonL2,mushroomPoisonL2Sprite,mushroomPoisonNL2,mushroomPoisonNL2Sprite,mushroomScorpianL2,mushroomScorpianL2Sprite,mushroomScorpian2L2,mushroomScorpian2L2Sprite,lives);
		window.draw(backgroundL2Sprite);
		if(playerL2[exists] == true)
		{
		drawPlayerL2(window, playerL2, playerL2Sprite,bulletL2);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
    	bulletL2[exists] = true;
		bulletL2[x] = playerL2[x];
		bulletL2[y] = playerL2[y] - boxPixelsY;
		bulletSoundL2.play();
		
		}
		
		if(bulletL2[exists] == true)
		{ 
        drawBulletL2(window, bulletL2, bulletL2Sprite, playerL2);
        moveBulletL2(bulletL2,bulletL2Clock,randMush,mushroom1L2,mushroom2L2,score,centiL2,window,mushroom1L2Sprite,mushroom2L2Sprite,revCheckL2,centiheadL2,killSoundL2,mushroomNewL2,mushroomNewL2Sprite,mushroomNew2L2,mushroomNew2L2Sprite,mushroomPoisonL2,mushroomPoisonL2Sprite,mushroomPoisonNL2,mushroomPoisonNL2Sprite,fleaL2,scorpianL2,mushroomScorpianL2,mushroomScorpian2L2);
		}


		for(int k=0; k<12; k++)
		{
		if(centiL2[k][exists]==true)
		{
		drawCentiL2(window, centiL2, centiL2Sprite, bulletL2);
		moveCentiL2(centiL2, centiL2Clock, moveL2, gameGrid,bulletL2,centiheadL2,revCheckL2,mushroom1L2,mushroom2L2,randMush,window,mushroom1L2Sprite,mushroom2L2Sprite,playerL2,lastCheckL2,mushroomNewL2,mushroomNewL2Sprite,mushroomNew2L2,mushroomNew2L2Sprite,mushroomPoisonL2,mushroomPoisonL2Sprite,mushroomPoisonNL2,mushroomPoisonNL2Sprite,lives,mushroomScorpianL2,mushroomScorpian2L2,hitCheck);
		}
		else
		{
			if(centiL2[k][exists]==false)
			{
				continue;
			}
		}
		}


		for(int i=0; i<12; i++)
		{
		if (centiheadL2[i][exists]==true) 
		{
			drawHeadL2(window,centiL2,centiheadL2Sprite,bulletL2,centiheadL2);
		}
		else
		{
			if(centiheadL2[i][exists]==false)
			{
				continue;
			}
		}
		}


		if (spiderL2[exists] == true) 
		{
			drawSpiderL2(window, spiderL2, spiderL2Sprite);
			moveSpiderL2(spiderL2, spiderL2Clock, gameGrid,playerL2,bulletL2,window,scoreL2Sprite3,mushroom1L2,mushroom2L2,randMush,scoreTimer,score,killSoundL2,playerPosition2,spiderPosition2,lives);
			// spiderSound.play();
		}


		if(spiderL2[exists]==false)
		{
			drawScoreL2(window,scoreL2Sprite3,spiderL2,scoreTimer,scoreDisplayDuration,score,playerPosition2,spiderPosition2,scoreL2Sprite6,scoreL2Sprite9);
		}


		for(int i=0; i<maxFleas; i++)
		{
			if(fleaL2[i][exists]==true)
			{
		drawFleaL2(gameGrid,window,bulletL2,mushroom1L2,mushroom2L2,fleaL2,fleaL2Sprite,checkFlagL2,randMush);
		moveFleaL2(fleaL2,fleaL2Clock,checkFlagL2,lives,playerL2);
			}
		}

		for(int i=0; i<maxScorpian; i++)
		{
			if(scorpianL2[i][exists]==true)
			{
		drawScorpianL2(gameGrid,window,bulletL2,mushroom1L2,mushroom2L2,scorpianL2,scorpianL2Sprite,checkFlagL2,randMush);
		moveScorpianL2(scorpianL2,scorpianL2Clock,checkFlagL2,mushroomScorpianL2,mushroom1L2,mushroom2L2,randMush,lives,playerL2);
			}
		}

		if(lives==0)
		{break;}
		

		if(score == 10000 || score == 12000 || score == 15000 || score == 20000)   //increase lives at these scores
		{
			lives++;
		}		
				

		for(int i=0; i<12; i++)
		{
			if(centiL2[i][exists]==false && centiheadL2[i][exists]==false)
			{
				levelCheckL2=true;
			}
			else
			{
				levelCheckL2=false;
				break;
			}

		}

		for(int i=0; i<12; i++)
		{
			if(centiL2[i][exists]==false)
			{
				headCheckL2 = true;
			}
			else
			{
				headCheckL2=false;
				break;
			}
		}

		if(headCheckL2==true)
		{
			for(int k=0; k<12; k++)
			{
				centiheadL2[k][exists] = false;
			}
		}		
		

		if(levelCheckL2==true)
		{
			level++;
			levelCheckL2=false;
			break;
		}




		scoreText.setString("Score: " + std::to_string(score));
    	window.draw(scoreText);

		levelText.setString("Level: " + std::to_string(level));
    	window.draw(levelText);

		livesText.setString("Lives: " + std::to_string(lives));
    	window.draw(livesText);		

		sf::Event e;
		while (window.pollEvent(e)) 
		{
			if (e.type == sf::Event::Closed) 
			{
				return 0;
			}
		}		
		window.display();
		window.clear();
	}

}
}

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Write your functions definitions here. Some have been written for you. //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

void drawPlayer(sf::RenderWindow& window, float player[], sf::Sprite& playerSprite, float bullet[]) 
{
	// Movement with arrow keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player[y] > (3*resolutionY)/4)
	{
        player[y] = player[y] -  1;   // Move up
	} 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player[y] < resolutionY - boxPixelsY)
	{
        player[y] = player[y] +  1;   // Move down
	} 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player[x] > 0)
	{
        player[x] = player[x] -  1;   // Move left
	} // Move left
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player[x] < resolutionX-boxPixelsX)
	{
        player[x] = player[x] +  1;   // Move right
	} 

	playerSprite.setPosition(player[x], player[y]);
	window.draw(playerSprite);
}

void moveBullet(float bullet[], sf::Clock& bulletClock,	int& randMush,float mushroom1[][3],float mushroom2[][3], int& score,float centi[][3],sf::RenderWindow& window,sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite,bool revCheck[][2],float centihead[][3],sf::Sound& killSound,float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite, float flea[][3], float scorpian[][3],float mushroomScorpian[][3],float mushroomScorpian2[][3]) 
{

	if (bulletClock.getElapsedTime().asMilliseconds() < 1)
		return;
	bulletClock.restart();
	bullet[y] -= 10;

	int bulletSize = 32;   //max bullet size
	int mushroomSize = 32;   //max mushroom size



	// Simple Mushrooms
	for(int k=0; k<randMush; k++)
	{

	if(bullet[x] + bulletSize > mushroom1[k][x] && bullet[x] < mushroom1[k][x] + mushroomSize && bullet[y] + bulletSize > mushroom1[k][y] && bullet[y] < mushroom1[k][y] + mushroomSize)   //collision of bullet and original mushroom
	{
		killSound.play();
		mushroom2[k][y] = mushroom1[k][y];          // Assigning the position of original mushroom to destroyed one
		mushroom2[k][x] = mushroom1[k][x];

		mushroom1[k][y] = -100;
		mushroom1[k][x] = -100;		

		mushroom1[k][y] = false;
		mushroom1[k][x] = false;

		bullet[exists] = false;

		break;
	}

	if(bullet[x] + bulletSize > mushroom2[k][x] && bullet[x] < mushroom2[k][x] + mushroomSize && bullet[y] + bulletSize > mushroom2[k][y] && bullet[y] < mushroom2[k][y] + mushroomSize)   //collision of bullet and broken mushroom
	{

		killSound.play();

		mushroom2[k][y] = -120;
		mushroom2[k][x] = -120;

		mushroom2[k][y] = false;
		mushroom2[k][x] = false;
		score+=1;

		bullet[exists] = false;

		break;

	}
	}

	for(int i=0; i<12; i++)
	{

	if(bullet[x] + bulletSize > mushroomNew[i][x] && bullet[x] < mushroomNew[i][x] + mushroomSize && bullet[y] + bulletSize > mushroomNew[i][y] && bullet[y] < mushroomNew[i][y] + mushroomSize)   //collision of bullet and centipede mushroom
	{
		killSound.play();
		mushroomNew2[i][y] = mushroomNew[i][y];          // Assigning the position of original mushroom to destroyed one
		mushroomNew2[i][x] = mushroomNew[i][x];

		mushroomNew[i][y] = -100;
		mushroomNew[i][x] = -100;		

		mushroomNew[i][y] = false;
		mushroomNew[i][x] = false;

		bullet[exists] = false;

		break;
	}

	if(bullet[x] + bulletSize > mushroomNew2[i][x] && bullet[x] < mushroomNew2[i][x] + mushroomSize && bullet[y] + bulletSize > mushroomNew2[i][y] && bullet[y] < mushroomNew2[i][y] + mushroomSize)   //collision of bullet and centipede broken mushroom
	{

		killSound.play();

		mushroomNew2[i][y] = -120;
		mushroomNew2[i][x] = -120;

		mushroomNew2[i][y] = false;
		mushroomNew2[i][x] = false;
		score+=1;
		

		bullet[exists] = false;

		break;

	}			

	}


	for(int i=0; i<12; i++)
	{

	if(bullet[x] + bulletSize > mushroomPoison[i][x] && bullet[x] < mushroomPoison[i][x] + mushroomSize && bullet[y] + bulletSize > mushroomPoison[i][y] && bullet[y] < mushroomPoison[i][y] + mushroomSize)   //collision of bullet and poison mushroom
	{
		killSound.play();

		mushroomPoisonN[i][y] = mushroomPoison[i][y];          // Assigning the position of original mushroom to destroyed one
		mushroomPoisonN[i][x] = mushroomPoison[i][x];

		mushroomPoison[i][y] = -100;
		mushroomPoison[i][x] = -100;		

		mushroomPoison[i][y] = false;
		mushroomPoison[i][x] = false;

		bullet[exists] = false;

		break;
	}

	if(bullet[x] + bulletSize > mushroomPoisonN[i][x] && bullet[x] < mushroomPoisonN[i][x] + mushroomSize && bullet[y] + bulletSize > mushroomPoisonN[i][y] && bullet[y] < mushroomPoisonN[i][y] + mushroomSize)   //collision of bullet and broken poisonous mushroom
	{

		killSound.play();

		mushroomPoisonN[i][y] = -120;
		mushroomPoisonN[i][x] = -120;

		mushroomPoisonN[i][y] = false;
		mushroomPoisonN[i][x] = false;
		score+=1;
		

		bullet[exists] = false;

		break;

	}			
	}

	for(int i=0; i<50; i++)
	{
		if(bullet[x] + bulletSize > flea[i][x] && bullet[x] < flea[i][x] + mushroomSize && bullet[y] + bulletSize > flea[i][y] && bullet[y] < flea[i][y] + mushroomSize && flea[i][exists] && bullet[exists])   //collision of bullet and flea
		{
			killSound.play();

			bullet[exists]=false;
			flea[i][x] = -1098;
			flea[i][y] = -1098;
			flea[i][exists] = false;
			flea[i+1][exists] = true;
			score+=1000;
		}
	}

	for(int i=0; i<50; i++)
	{
		if(bullet[x] + bulletSize > scorpian[i][x] && bullet[x] < scorpian[i][x] + mushroomSize && bullet[y] + bulletSize > scorpian[i][y] && bullet[y] < scorpian[i][y] + mushroomSize && scorpian[i][exists] && bullet[exists])    //collision of bullet and scorpian
		{
			killSound.play();

			bullet[exists]=false;
			scorpian[i][x] = -1098;
			scorpian[i][y] = -1098;
			scorpian[i][exists] = false;
			scorpian[i+1][exists] = true;
		}
	}

	for(int k=0; k<randMush; k++)
	{

	if(bullet[x] + bulletSize > mushroomScorpian[k][x] && bullet[x] < mushroomScorpian[k][x] + mushroomSize && bullet[y] + bulletSize > mushroomScorpian[k][y] && bullet[y] < mushroomScorpian[k][y] + mushroomSize)   //collision of bullet an scorpian produced muhsroom
	{
		killSound.play();
		mushroomScorpian2[k][y] = mushroomScorpian[k][y];        // Assigning the position of original mushroom to destroyed one
		mushroomScorpian2[k][x] = mushroomScorpian[k][x];

		mushroomScorpian[k][y] = -321;
		mushroomScorpian[k][x] = -321;		

		mushroomScorpian[k][y] = false;
		mushroomScorpian[k][x] = false;

		bullet[exists] = false;

		break;
	}

	if(bullet[x] + bulletSize > mushroomScorpian2[k][x] && bullet[x] < mushroomScorpian2[k][x] + mushroomSize && bullet[y] + bulletSize > mushroomScorpian2[k][y] && bullet[y] < mushroomScorpian2[k][y] + mushroomSize)   // Assigning the position of broken poisonous mushroom to destroyed one
	{

		killSound.play();

		mushroomScorpian2[k][y] = -320;
		mushroomScorpian2[k][x] = -320;

		mushroomScorpian2[k][y] = false;
		mushroomScorpian2[k][x] = false;
		score+=1;

		bullet[exists] = false;

		break;

	}
	}	
	
			

	checkCollision(bullet,centi,revCheck,mushroom1Sprite,mushroom2Sprite,randMush,mushroom1,mushroom2,centihead,window,score,mushroomNew,mushroomNewSprite,mushroomNew2,mushroomNew2Sprite,mushroomPoison,mushroomPoisonSprite,mushroomPoisonN,mushroomPoisonNSprite,killSound);   //calling check collision dunction

	if (bullet[y] < -32)
		bullet[exists] = false;
}

void drawBullet(sf::RenderWindow& window, float bullet[], sf::Sprite& bulletSprite, float player[]) 
{

	if(bullet[exists]==true)
	{
	bulletSprite.setPosition(bullet[x], bullet[y]);
	window.draw(bulletSprite);
	}
}

void spawnMushrooms(sf::RenderWindow& window,sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite,bool& check, float bullet[], int& score,float mushroom1[][3],float mushroom2[][3],int& randMush, float player[],float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite,float mushroomScorpian[][3], sf::Sprite& mushroomScorpianSprite,float mushroomScorpian2[][3], sf::Sprite& mushroomScorpian2Sprite,int& lives,float mushroomExtra[][3],sf::Sprite& mushroomExtraSprite,float mushroomExtra2[][3],sf::Sprite& mushroomExtra2Sprite, int& mushCheck)
{

for(int a=0; a<randMush; a++)   //to choose between original and nomral
{
	if(mushroom1[a][x] != false && mushroom1[a][x] >0 && mushroom1[a][y] != false && mushroom1[a][y]>0)
	{
		mushroom1Sprite.setPosition(mushroom1[a][x], mushroom1[a][y]);
		window.draw(mushroom1Sprite);
	}

	else
	{
	if(mushroom2[a][x] != false && mushroom2[a][x]>0 && mushroom2[a][y] != false && mushroom2[a][y]>0)
	{
		mushroom2Sprite.setPosition(mushroom2[a][x], mushroom2[a][y]);
		window.draw(mushroom2Sprite);
	}
	}
}

for(int i=0; i<12; i++)   //to choose between simple and broken mushroom
{
	if(mushroomNew[i][x] != false && mushroomNew[i][x]>0 && mushroomNew[i][y] != false && mushroomNew[i][y]>0)
	{
	mushroomNewSprite.setPosition(mushroomNew[i][x], mushroomNew[i][y]);
	window.draw(mushroomNewSprite);
	}

	else
	{
	if(mushroomNew2[i][x] != false && mushroomNew2[i][x]>0 && mushroomNew2[i][y] != false && mushroomNew2[i][y]>0)
	{
	mushroomNew2Sprite.setPosition(mushroomNew2[i][x], mushroomNew2[i][y]);
	window.draw(mushroomNew2Sprite);
	}
	}	

}

for(int i=0; i<12; i++)   //to choose between original and poison mushroom
{
	if(mushroomPoison[i][x] != false && mushroomPoison[i][x]>0 && mushroomPoison[i][y] != false && mushroomPoison[i][y]>0)   //orignal and broke poison mushroom  
	{
	mushroomPoisonSprite.setPosition(mushroomPoison[i][x], mushroomPoison[i][y]);
	window.draw(mushroomPoisonSprite);
	}

	else
	{
	if(mushroomPoisonN[i][x] != false && mushroomPoisonN[i][x]>0 && mushroomPoisonN[i][y] != false && mushroomPoisonN[i][y]>0)
	{
	mushroomPoisonNSprite.setPosition(mushroomPoisonN[i][x], mushroomPoisonN[i][y]);
	window.draw(mushroomPoisonNSprite);
	}
	}

	if((player[x] == mushroomPoison[i][x] && player[y] == mushroomPoison[i][y] && player[exists] && mushroomPoison[i][exists]) || (player[x] == mushroomPoisonN[i][x] && player[y] == mushroomPoisonN[i][y] && player[exists] && mushroomPoisonN[i][exists]))   // destruction of player
	{
		lives--;
		player[exists] = false;
		mushroomExtra[mushCheck][x] = mushroomPoison[i][x];
		mushroomExtra[mushCheck][y] = mushroomPoison[i][y];
		mushroomExtra[mushCheck][exists] = true;
		mushCheck++;


		if(lives>0)
		{
			player[x] = (gameColumns / 2) * boxPixelsX;   //player set to intitally
			player[y] = (gameColumns * 3 / 4) * boxPixelsY;
			player[exists] = true;
		}
	}	
}

for(int a=0; a<randMush; a++)   //to choose between normal and broken
{
	if(mushroomScorpian[a][x] != false && mushroomScorpian[a][x] >0 && mushroomScorpian[a][y] != false && mushroomScorpian[a][y]>0)   //scorpian mushroom
	{
		mushroomScorpianSprite.setPosition(mushroomScorpian[a][x], mushroomScorpian[a][y]);
		window.draw(mushroomScorpianSprite);
	}

	else
	{
	if(mushroomScorpian2[a][x] != false && mushroomScorpian2[a][x]>0 && mushroomScorpian2[a][y] != false && mushroomScorpian2[a][y]>0)
	{
		mushroomScorpian2Sprite.setPosition(mushroomScorpian2[a][x], mushroomScorpian2[a][y]);
		window.draw(mushroomScorpian2Sprite);
	}
	}
}

}

void moveCenti(float centi[][3], sf::Clock& centiClock, bool& move, int gameGrid[][gameColumns], float bullet[],float centihead[][3],bool revCheck[][2],float mushroom1[][3],float mushroom2[][3],int randMush,sf::RenderWindow& window,sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite, float player[], bool& lastCheck,float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite, int& lives,float mushroomScorpian[][3],float mushroomScorpian2[][3])
{
    if (centiClock.getElapsedTime().asMilliseconds() < 130)
    return;

    centiClock.restart();

	int bulletSize = 32;
	int spiderSize = 32;
	int mushroomSize = 32;

    for (int p=0; p<12; p++) 
	{

		if(revCheck[p][1]==false)    //Flase means the centiipede segments are moving towards
		{
			centi[p][x] = centi[p][x] - 32;   //moves one grid towards left
		}

		for(int j=0; j<randMush; j++)
		{
		if(centi[p][x] == mushroom1[j][x] && centi[p][y] == mushroom1[j][y] && mushroom1[j][exists] && mushroom1[j][y] != 0)   //collision of centipede and mushroom
		{

			centi[p][y] = centi[p][y] + 32;

			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}

		for(int j=0; j<randMush; j++)
		{
		if(centi[p][x] + bulletSize > mushroom2[j][x] && centi[p][x] < mushroom2[j][x] + mushroomSize && centi[p][y] + bulletSize > mushroom2[j][y] && centi[p][y] < mushroom2[j][y] + mushroomSize)
		{
			centi[p][y] = centi[p][y] + 32;

			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}

		for(int j=0; j<12; j++)
		{
		if(centi[p][x] == mushroomNew[j][x] && centi[p][y] == mushroomNew[j][y] && mushroomNew[j][exists]==true)
		{

			centi[p][y] = centi[p][y] + 32;

			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}
		
		for(int j=0; j<12; j++)
		{
		if(centi[p][x] == mushroomNew2[j][x] && centi[p][y] == mushroomNew2[j][y] && mushroomNew2[j][exists]==true)
		{

			centi[p][y] = centi[p][y] + 32;

			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}

		for(int j=0; j<12; j++)
		{
		if(centi[p][x] == mushroomPoison[j][x] && centi[p][y] == mushroomPoison[j][y] && mushroomPoison[j][exists]==true)
		{

			centi[p][y] = centi[p][y] + 32;

			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}

		for(int j=0; j<12; j++)
		{
		if(centi[p][x] == mushroomPoisonN[j][x] && centi[p][y] == mushroomPoisonN[j][y] && mushroomPoisonN[j][exists]==true)
		{

			centi[p][y] = centi[p][y] + 32;
			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}
		
		for(int j=0; j<randMush; j++)
		{
		if(centi[p][x] + bulletSize > mushroomScorpian[j][x] && centi[p][x] < mushroomScorpian[j][x] + mushroomSize && centi[p][y] + bulletSize > mushroomScorpian[j][y] && centi[p][y] < mushroomScorpian[j][y] + mushroomSize)
		{

			centi[p][y] = centi[p][y] + 32;
			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}

		for(int j=0; j<randMush; j++)
		{
		if(centi[p][x] + bulletSize > mushroomScorpian2[j][x] && centi[p][x] < mushroomScorpian2[j][x] + mushroomSize && centi[p][y] + bulletSize > mushroomScorpian2[j][y] && centi[p][y] < mushroomScorpian2[j][y] + mushroomSize)
		{

			centi[p][y] = centi[p][y] + 32;
			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}
		}												


		if(centi[p][x]==-32)     //ONCE THE CENTIPEDE REACHES THE LEFT MAX OF THE SCREEN
		{
			centi[p][y] = centi[p][y] + 32;

			if(revCheck[p][1]!=false)      // turns the centipede in opposite direction
			{
				revCheck[p][1]=false;
			}
			else
			{
				revCheck[p][1]=true;
			}
		}

		if(revCheck[p][1]!=false)   //moving right
		{
			centi[p][x] = centi[p][x] + 32;             //CENTIPEDE STARTS MOVING TOWARDS RIGHT
		}

		if(centi[p][x]==960 && centi[p][y] !=0)       //ONCE THE CENTIPEDE REACHES THE MAX RIGHT OF SCREEN
		{
			centi[p][y] = centi[p][y] + 32;

			if(revCheck[p][1]!=false)         // turns the centipede in opposite direction
			{
				revCheck[p][1] =false;
			}
			else
			{
				revCheck[p][1] = true;
			}
		}
		centihead[p][x] = centi[p][x];   //assign centi positions to heads
		centihead[p][y] = centi[p][y];

		if((centi[p][x]==0 && centi[p][y]==960) || centi[p][x]==960 && centi[p][y]==960)   //condition when centipede segment reaches last row so it moves back and forth
		{
			centi[p][y] = centi[p][y] - 32;
			centihead[p][y] = centi[p][y];
		}
	}

	for(int l=0; l<12; l++)
	{
		if(player[x] < centi[l][x] + 32 && player[x] + 32 > centi[l][x] && player[y] < centi[l][y] + 32 && player[y] + 32 > centi[l][y] && player[exists] && centi[l][exists])
		{
			lives--;
			player[exists] = false;		

			if(lives>0)
			{
				player[x] = (gameColumns / 2) * boxPixelsX;
				player[y] = (gameColumns * 3 / 4) * boxPixelsY;
				player[exists] = true;
			}
		}
	}


}

void drawCenti(sf::RenderWindow& window, float centi[][3], sf::Sprite& centiSprite, float bullet[]) 
{

	for(int k=0; k<12; k++)
	{
		centiSprite.setPosition(centi[k][x], centi[k][y]);
		window.draw(centiSprite);
	}
}


void drawHead(sf::RenderWindow& window, float centi[][3], sf::Sprite& centiheadSprite, float bullet[],float centihead[][3])
{
	for(int i=0; i<12; i++)
	{
		if(centihead[i][exists] ==true)
		{
		centiheadSprite.setPosition(centihead[i][x], centihead[i][y]);
		window.draw(centiheadSprite);
		}
	}
}

void moveSpider(float spider[], sf::Clock& spiderClock, int gameGrid[][gameColumns], float player[], float bullet[], sf::RenderWindow& window, sf::Sprite& scoreSprite3,float mushroom1[][3],float mushroom2[][3],int& randMush,sf::Clock& scoreTimer, int& score,sf::Sound& killSound,int& playerPosition,int& spiderPosition, int& lives) 
{
    static bool directionUp = true;   //used for vertical positioning
    static bool directionRight = true;   //used for horizontal positioning
	int bulletSize = 32;
	int spiderSize = 32;
	int mushroomSize = 32;
	int totalArea = ((3*resolutionY)/4);   //spider remains in this area


    if (spider[y] >= totalArea && spider[y] <= resolutionY-boxPixelsY)   //spider remains bound in the area
    {
        if (spiderClock.getElapsedTime().asMilliseconds() > 10) 
        {

            if (directionUp) 
            {
				// spiderSound.play();
                spider[y] = spider[y] - 2;   //spider moves up


                if (spider[y] <= totalArea)      // THIS CONDITION WORKS TILL THE SPIDER REACHES AT A MAX GIVEN HEIGHT
                {
                    directionUp = false;   //time it to move it down
                }
            } 
            else 
            {
				// spiderSound.play();
                spider[y] = spider[y] + 2;

                if (spider[y] >= (resolutionY-boxPixelsY))     // THIS CONDITION WORKS TILL THE SPIDER REACHES AT A MAX GIVEN DEPTH
                {
                    directionUp = true;   //time to move it up
                }
            }

            if (directionRight) 
            {
				// spiderSound.play();
                spider[x] = spider[x] + 2;   

                if (spider[x] >= resolutionX-boxPixelsX-32)       // THIS CONDITION WORKS TILL THE SPIDER REACHES MAX RIGHT OF SCREEN
                {
                    directionRight = false;   //time to move it towards left
                }
            } 
            else 
            {
				// spiderSound.play();
                spider[x] = spider[x] - 2;            // THIS CONDITION WORKS TILL THE SPIDER REACHES AT A MAX LEFT OF SCREEN

                if (spider[x] <= 0) 
                {
                    directionRight = true;   //time to move it towards right
                }
            }

			// Bullet detection
			if(bullet[x] + bulletSize >= spider[x] && bullet[x] <= spider[x] + spiderSize && bullet[y] + bulletSize >= spider[y] && bullet[y] <= spider[y] + spiderSize && bullet[exists] && spider[exists])   //bullet and spider collision
			{

				// spiderSound.stop();
				killSound.play();
				spider[exists] = false;
				bullet[exists] = false;

				playerPosition = player[y]/boxPixelsY;
				spiderPosition = spider[y]/boxPixelsY;

				//assigning scores
				if(playerPosition-spiderPosition == 1)
				{
					score+=900;
					scoreTimer.restart();
				}
				else if(playerPosition-spiderPosition == 2)
				{
					score+=600;
					scoreTimer.restart();					
				}
				else
				{
					if(playerPosition-spiderPosition >=3)
					{
					score+=300;
					scoreTimer.restart();
					}
				}
			}

			// Mushrooms collision detection with spider and it eats them
			for(int k=0; k<randMush; k++)
			{
			if(spider[x] + spiderSize >= mushroom1[k][x] && spider[x] <= mushroom1[k][x] + mushroomSize && spider[y] + spiderSize >= mushroom1[k][y] && spider[y] <= mushroom1[k][y] + mushroomSize)
			{
				mushroom1[k][x] = false;
				mushroom1[k][y] = false;
			}
			}

			for(int k=0; k<randMush; k++)
			{
			if(spider[x] + spiderSize >= mushroom2[k][x] && spider[x] <= mushroom2[k][x] + mushroomSize && spider[y] + spiderSize >= mushroom2[k][y] && spider[y] <= mushroom2[k][y] + mushroomSize)
			{
				mushroom2[k][x] = false;
				mushroom2[k][y] = false;
			}
			}

			// Player Detection

            // spiderSound.play();
            spiderClock.restart();
        }
    }

			if(player[x] < spider[x] + 32 && player[x] + 32 > spider[x] && player[y] < spider[y] + 32 && player[y] + 32 > spider[y] && player[exists] && spider[exists])
			{
				lives--;
				player[exists]=false;

				if(lives>0)
				{
					player[x] = (gameColumns / 2) * boxPixelsX;
					player[y] = (gameColumns * 3 / 4) * boxPixelsY;
					player[exists] = true;
				}

			}
	 
}

void drawScore(sf::RenderWindow& window, sf::Sprite& scoreSprite3, float spider[],sf::Clock& scoreTimer, sf::Time scoreDisplayDuration, int& score,int& playerPosition,int& spiderPosition, sf::Sprite& scoreSprite6, sf::Sprite& scoreSprite9)
{
	if(spider[exists] == false && playerPosition-spiderPosition == 1)
	{
	scoreSprite9.setPosition(spider[x], spider[y]);
	if(scoreTimer.getElapsedTime() < scoreDisplayDuration)
	{
    window.draw(scoreSprite9);
	}
	}

	else if(spider[exists] == false && playerPosition-spiderPosition == 2)
	{
	scoreSprite6.setPosition(spider[x], spider[y]);
	if(scoreTimer.getElapsedTime() < scoreDisplayDuration)
	{
    window.draw(scoreSprite6);
	}
	}

	else
	{
	if(spider[exists] == false && playerPosition-spiderPosition >= 3)
	{
	scoreSprite3.setPosition(spider[x], spider[y]);
	if(scoreTimer.getElapsedTime() < scoreDisplayDuration)
	{
    window.draw(scoreSprite3);
	}
	}
	}
}

void drawSpider(sf::RenderWindow& window, float spider[], sf::Sprite& spiderSprite) 
{
	if(spider[exists]==true)
	{
	spiderSprite.setPosition(spider[x], spider[y]);
	window.draw(spiderSprite);
	}
}

void checkCollision(float bullet[], float centi[][3],bool revCheck[][2],sf::Sprite mushroom1Sprite,sf::Sprite& mushroom2Sprite,int randMush,float mushroom1[][3],float mushroom2[][3],float centihead[][3],sf::RenderWindow& window, int& score,float mushroomNew[][3], sf::Sprite& mushroomNewSprite,float mushroomNew2[][3], sf::Sprite& mushroomNew2Sprite,float mushroomPoison[][3], sf::Sprite& mushroomPoisonSprite,float mushroomPoisonN[][3], sf::Sprite& mushroomPoisonNSprite,sf::Sound& killSound)
{
	int CheckSeg;

for(int i=0; i<12; i++)
{
	if(bullet[x] + 32 > centi[i][x] && bullet[x] < centi[i][x] + boxPixelsX && bullet[y] + 32 > centi[i][y] && bullet[y] < centi[i][y] + boxPixelsY && bullet[exists]==true && centihead[i][exists]==true && centi[i][exists]==true)   //bullet and centipede collision mainly head
	{
		score+=20;
		CheckSeg=i;
		while(centi[CheckSeg][exists]!=false)
		{
			if(centi[CheckSeg][exists]!=false)
			{
			centi[CheckSeg][x] = -1000;
			centi[CheckSeg][y] = -1000;			
			centi[CheckSeg][exists]=false;
			centihead[CheckSeg][x] = -1000;
			centihead[CheckSeg][y] = -1000;	
			centihead[CheckSeg][exists]=false;
			}
			CheckSeg++;
		}

	} 
}

	for (int i = 0; i < 12; ++i) 
	{
        // Check collision between bullet and centipede segment
        if (bullet[x] + 32 > centi[i][x] && bullet[x] < centi[i][x] + boxPixelsX && bullet[y] + 32 > centi[i][y] && bullet[y] < centi[i][y] + boxPixelsY && centi[i][exists]==true) 
		{
			killSound.play();
			score+=10;
			bullet[exists] = false;
			centi[i][exists]=false;
			centihead[i+1][exists] = true;
			centihead[i][exists] = false; 

			if(centi[i][y] < (3*resolutionY)/4)
			{
			for(int k=i; k<12; k++)
			{
				mushroomNew[k][x] = centi[i][x];
				mushroomNew[k][y] = centi[i][y];
				mushroomNew[k][exists] = true;
				break;
			}
			}

			if(centi[i][y] > (3*resolutionY)/4)
			{
			for(int k=i; k<12; k++)
			{
				mushroomPoison[k][x] = centi[i][x];
				mushroomPoison[k][y] = centi[i][y];
				mushroomPoison[k][exists] = true;
				break;
			}
			}

			break;
        }
    }
}

void drawFlea(int gameGrid[][gameColumns], sf::RenderWindow& window, float bullet[], float mushroom1[][3], float mushroom2[][3], float flea[][3], sf::Sprite& fleaSprite, bool& checkFlag,int randMush)
{

	for(int k=0; k<50; k++)
	{
		if(flea[k][exists]==true )
		{	
		if(k>0 && flea[k-1][exists]==false && flea[k+1][exists]==false)
			{
        	fleaSprite.setPosition(flea[k][x], flea[k][y]);
        	window.draw(fleaSprite);
			}
		if(k==0 && flea[k+1][exists]==false)
			{
        fleaSprite.setPosition(flea[k][x], flea[k][y]);
        window.draw(fleaSprite);
			}
		}
	}
	
}

void moveFlea(float flea[][3], sf::Clock& fleaClock, bool& checkFlag,int& lives,float player[],float mushroomExtra[][3],int& mushCheck )
{
	for(int i=0; i<50; i++)
	{
    if (flea[i][exists]==true && fleaClock.getElapsedTime().asMilliseconds() >= 20)
    {
        fleaClock.restart();
        flea[i][y] += 10;
    }

	if(flea[i][y]==resolutionY && flea[i][exists]==true)
	{
		flea[i][x] = -1098;
		flea[i][y] = -1098;		
		flea[i][exists]=false;
		flea[i+1][exists]=true;
	}

	if(player[x] < flea[i][x] + 32 && player[x] + 32 > flea[i][x] && player[y] < flea[i][y] + 32 && flea[i][y] + 32 > flea[i][y] && player[exists] && flea[i][exists])   //flea and player collision
	{
		lives--;
		player[exists] = false;		
		if(lives>0)
		{
		player[x] = (gameColumns / 2) * boxPixelsX;
		player[y] = (gameColumns * 3 / 4) * boxPixelsY;
		player[exists] = true;
		}
		
	}



	}
	
}

void drawScorpian(int gameGrid[][gameColumns], sf::RenderWindow& window, float bullet[], float mushroom1[][3], float mushroom2[][3], float scorpian[][3], sf::Sprite& scorpianSprite, bool& checkFlag,int randMush)
{
 
	for(int k=0; k<50; k++)
	{
		if(scorpian[k][exists]==true )
		{	
		if(k>0 && scorpian[k-1][exists]==false && scorpian[k+1][exists]==false)
			{
        	scorpianSprite.setPosition(scorpian[k][x], scorpian[k][y]);
        	window.draw(scorpianSprite);
			}
		if(k==0 && scorpian[k+1][exists]==false)
			{
        scorpianSprite.setPosition(scorpian[k][x], scorpian[k][y]);
        window.draw(scorpianSprite);
			}
		}

	
	}

	

	
}

void moveScorpian(float scorpian[][3], sf::Clock& scorpianClock, bool& checkFlag,float mushroomScorpian[][3],float mushroom1[][3],float mushroom2[][3],	int& randMush, int& lives, float player[])
{
	for(int i=0; i<50; i++)
	{
    if (scorpian[i][exists]==true && scorpianClock.getElapsedTime().asMilliseconds() > 20)
    {
        scorpianClock.restart();
        scorpian[i][x] += 4;
    }

	if(scorpian[i][x]==resolutionX+20*32 && scorpian[i][exists]==true)
	{
		scorpian[i][exists]=false;
		scorpian[i+1][exists]=true;
	}

	//scorpian and muhsroom detection
	for(int k=0; k<randMush; k++)
	{
		if((scorpian[i][x] == mushroom1[k][x] && scorpian[i][y] == mushroom1[k][y] && scorpian[i][exists] && mushroom1[k][exists]))
		{
			mushroomScorpian[k][x] = mushroom1[k][x];
			mushroomScorpian[k][y] = mushroom1[k][y];

			mushroom1[k][x] = -1023;
			mushroom1[k][y] = -1023;

			mushroom1[k][exists] = false;
		}

		if((scorpian[i][x] == mushroom2[k][x] && scorpian[i][y] == mushroom2[k][y] && scorpian[i][exists] && mushroom2[k][exists]))
		{
			mushroomScorpian[k][x] = mushroom2[k][x];
			mushroomScorpian[k][y] = mushroom2[k][y];

			mushroom2[k][x] = -1023;
			mushroom2[k][y] = -1023;

			mushroom2[k][exists] = false;
		}
	}

			if(player[x] < scorpian[i][x] + 32 && player[x] + 32 > scorpian[i][x] && player[y] < scorpian[i][y] + 32 && scorpian[i][y] + 32 > scorpian[i][y] && player[exists] && scorpian[i][exists])   //player and scorpian collision
		{
			lives--;
			player[exists] = false;

			if(lives>0)
			{
				player[x] = (gameColumns / 2) * boxPixelsX;
				player[y] = (gameColumns * 3 / 4) * boxPixelsY;
				player[exists]= true;
			}
			
		}	

}
}

void drawExtra(float extrahead[][3],sf::Clock extraheadClock,sf::Sprite extraheadSprite, sf::RenderWindow& window, float centi[][3], float centihead[][3])
{
	bool Ch = false;
	for(int i=0; i<12; i++)
	{
		if(centi[i][y] > (3*resolutionY)/4)
		{
			Ch = true;
			break;
		}

	}

if(Ch == true)
{
	for(int i=0; i<20; i++)
	{
		extraheadSprite.setPosition(extrahead[i][x], extrahead[i][y]);
		window.draw(extraheadSprite);
	}
}
}

void moveExtra(float extrahead[][3], float centi[][3], float centihead[][3],sf::Clock extraheadClock, bool revHead[][2])
{
    if (extraheadClock.getElapsedTime().asMilliseconds() < 600)
    return;

    extraheadClock.restart();


    for (int p=0; p<20; p++) 
	{

		if(revHead[p][1]==false)    //moving left
		{
			extrahead[p][x] = extrahead[p][x] - 32;
		}											

		if(extrahead[p][x]==-32)     //ONCE THE CENTIPEDE REACHES THE LEFT MAX OF THE SCREEN
		{
			extrahead[p][y] = extrahead[p][y] + 32;

			if(revHead[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revHead[p][1]=false;
			}
			else
			{
				revHead[p][1]=true;
			}
		}

		if(revHead[p][1]!=false)
		{
			extrahead[p][x] = extrahead[p][x] +  32;             //CENTIPEDE STARTS MOVING TOWARDS RIGHT
		}

		if(extrahead[p][x]==960+32)       //ONCE THE CENTIPEDE REACHES THE MAX RIGHT OF SCREEN
		{
			extrahead[p][y] = extrahead[p][y] +  32;

			if(revHead[p][1]!=false)         //AGAIN REVERSES THE DIRECTION ONCE IT COMES DOWN
			{
				revHead[p][1] =false;
			}
			else
			{
				revHead[p][1] = true;
			}
		}

		if((extrahead[p][x]==0-32 && extrahead[p][y]==960) || extrahead[p][x]==960 && extrahead[p][y]==960)
		{
			extrahead[p][y] = extrahead[p][y] - 32;
		}
	}

}
// LEVEL 2

void drawPlayerL2(sf::RenderWindow& window, float playerL2[], sf::Sprite& playerL2Sprite, float bulletL2[]) 
{
	// Movement with arrow keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerL2[y] > (3*resolutionY)/4)
	{
        playerL2[y] = playerL2[y] - 1;
	} // Move up
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerL2[y] < resolutionY - boxPixelsY)
	{
        playerL2[y] = playerL2[y] + 1;
	} // Move down
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerL2[x] > 0)
	{
        playerL2[x] = playerL2[x] - 1;
	} // Move left
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerL2[x] < resolutionX-boxPixelsX)
	{
        playerL2[x] = playerL2[x] + 1;
	} // Move right

	playerL2Sprite.setPosition(playerL2[x], playerL2[y]);
	window.draw(playerL2Sprite);
}

void moveBulletL2(float bulletL2[], sf::Clock& bulletL2Clock,	int& randMush,float mushroom1L2[][3],float mushroom2L2[][3], int& score,float centiL2[][3],sf::RenderWindow& window,sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite,bool revCheckL2[][2],float centiheadL2[][3],sf::Sound& killSoundL2,float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite, float fleaL2[][3], float scorpianL2[][3],float mushroomScorpianL2[][3],float mushroomScorpian2L2[][3])
{

	if (bulletL2Clock.getElapsedTime().asMilliseconds() < 1)
		return;
	bulletL2Clock.restart();
	bulletL2[y] -= 10;

	int bulletSize = 32;
	int mushroomSize = 32;



	// Simple Mushrooms
	for(int k=0; k<randMush; k++)
	{

	if(bulletL2[x] + bulletSize > mushroom1L2[k][x] && bulletL2[x] < mushroom1L2[k][x] + mushroomSize && bulletL2[y] + bulletSize > mushroom1L2[k][y] && bulletL2[y] < mushroom1L2[k][y] + mushroomSize)
	{
		killSoundL2.play();
		mushroom2L2[k][y] = mushroom1L2[k][y];          // Assigning the position of Original mushroom to destroyed one
		mushroom2L2[k][x] = mushroom1L2[k][x];

		mushroom1L2[k][y] = -100;
		mushroom1L2[k][x] = -100;		

		mushroom1L2[k][y] = false;
		mushroom1L2[k][x] = false;

		bulletL2[exists] = false;

		break;
	}

	if(bulletL2[x] + bulletSize > mushroom2L2[k][x] && bulletL2[x] < mushroom2L2[k][x] + mushroomSize && bulletL2[y] + bulletSize > mushroom2L2[k][y] && bulletL2[y] < mushroom2L2[k][y] + mushroomSize)
	{

		killSoundL2.play();

		mushroom2L2[k][y] = -120;
		mushroom2L2[k][x] = -120;

		mushroom2L2[k][y] = false;
		mushroom2L2[k][x] = false;
		score+=1;

		bulletL2[exists] = false;

		break;

	}
	}

	for(int i=0; i<12; i++)
	{

	if(bulletL2[x] + bulletSize > mushroomNewL2[i][x] && bulletL2[x] < mushroomNewL2[i][x] + mushroomSize && bulletL2[y] + bulletSize > mushroomNewL2[i][y] && bulletL2[y] < mushroomNewL2[i][y] + mushroomSize)
	{
		killSoundL2.play();
		mushroomNew2L2[i][y] = mushroomNewL2[i][y];          // Assigning the position of Original mushroom to destroyed one
		mushroomNew2L2[i][x] = mushroomNewL2[i][x];

		mushroomNewL2[i][y] = -100;
		mushroomNewL2[i][x] = -100;		

		mushroomNewL2[i][y] = false;
		mushroomNewL2[i][x] = false;

		bulletL2[exists] = false;

		break;
	}

	if(bulletL2[x] + bulletSize > mushroomNew2L2[i][x] && bulletL2[x] < mushroomNew2L2[i][x] + mushroomSize && bulletL2[y] + bulletSize > mushroomNew2L2[i][y] && bulletL2[y] < mushroomNew2L2[i][y] + mushroomSize)
	{

		killSoundL2.play();

		mushroomNew2L2[i][y] = -120;
		mushroomNew2L2[i][x] = -120;

		mushroomNew2L2[i][y] = false;
		mushroomNew2L2[i][x] = false;
		score+=1;
		

		bulletL2[exists] = false;

		break;

	}			

	}


	for(int i=0; i<12; i++)
	{

	if(bulletL2[x] + bulletSize > mushroomPoisonL2[i][x] && bulletL2[x] < mushroomPoisonL2[i][x] + mushroomSize && bulletL2[y] + bulletSize > mushroomPoisonL2[i][y] && bulletL2[y] < mushroomPoisonL2[i][y] + mushroomSize)
	{
		killSoundL2.play();
		mushroomPoisonNL2[i][y] = mushroomPoisonL2[i][y];          // Assigning the position of Original mushroom to destroyed one
		mushroomPoisonNL2[i][x] = mushroomPoisonL2[i][x];

		mushroomPoisonL2[i][y] = -100;
		mushroomPoisonL2[i][x] = -100;		

		mushroomPoisonL2[i][y] = false;
		mushroomPoisonL2[i][x] = false;

		bulletL2[exists] = false;

		break;
	}

	if(bulletL2[x] + bulletSize > mushroomPoisonNL2[i][x] && bulletL2[x] < mushroomPoisonNL2[i][x] + mushroomSize && bulletL2[y] + bulletSize > mushroomPoisonNL2[i][y] && bulletL2[y] < mushroomPoisonNL2[i][y] + mushroomSize)
	{

		killSoundL2.play();

		mushroomPoisonNL2[i][y] = -120;
		mushroomPoisonNL2[i][x] = -120;

		mushroomPoisonNL2[i][y] = false;
		mushroomPoisonNL2[i][x] = false;
		score+=1;
		

		bulletL2[exists] = false;

		break;

	}			
	}

	for(int i=0; i<50; i++)
	{
		if(bulletL2[x] + bulletSize > fleaL2[i][x] && bulletL2[x] < fleaL2[i][x] + mushroomSize && bulletL2[y] + bulletSize > fleaL2[i][y] && bulletL2[y] < fleaL2[i][y] + mushroomSize && fleaL2[i][exists] && bulletL2[exists])
		{
			killSoundL2.play();

			bulletL2[exists]=false;
			fleaL2[i][x] = -1098;
			fleaL2[i][y] = -1098;
			fleaL2[i][exists] = false;
			fleaL2[i+1][exists] = true;
			score+=1000;
		}
	}

	for(int i=0; i<50; i++)
	{
		if(bulletL2[x] + bulletSize > scorpianL2[i][x] && bulletL2[x] < scorpianL2[i][x] + mushroomSize && bulletL2[y] + bulletSize > scorpianL2[i][y] && bulletL2[y] < scorpianL2[i][y] + mushroomSize && scorpianL2[i][exists] && bulletL2[exists])
		{
			killSoundL2.play();

			bulletL2[exists]=false;
			scorpianL2[i][x] = -1098;
			scorpianL2[i][y] = -1098;
			scorpianL2[i][exists] = false;
			scorpianL2[i+1][exists] = true;
		}
	}

	for(int k=0; k<randMush; k++)
	{

	if(bulletL2[x] + bulletSize > mushroomScorpianL2[k][x] && bulletL2[x] < mushroomScorpianL2[k][x] + mushroomSize && bulletL2[y] + bulletSize > mushroomScorpianL2[k][y] && bulletL2[y] < mushroomScorpianL2[k][y] + mushroomSize)
	{
		killSoundL2.play();
		mushroomScorpian2L2[k][y] = mushroomScorpianL2[k][y];          // Assigning the position of Original mushroom to destroyed one
		mushroomScorpian2L2[k][x] = mushroomScorpianL2[k][x];

		mushroomScorpianL2[k][y] = -321;
		mushroomScorpianL2[k][x] = -321;		

		mushroomScorpianL2[k][y] = false;
		mushroomScorpianL2[k][x] = false;

		bulletL2[exists] = false;

		break;
	}

	if(bulletL2[x] + bulletSize > mushroomScorpian2L2[k][x] && bulletL2[x] < mushroomScorpian2L2[k][x] + mushroomSize && bulletL2[y] + bulletSize > mushroomScorpian2L2[k][y] && bulletL2[y] < mushroomScorpian2L2[k][y] + mushroomSize)
	{

		killSoundL2.play();

		mushroomScorpian2L2[k][y] = -320;
		mushroomScorpian2L2[k][x] = -320;

		mushroomScorpian2L2[k][y] = false;
		mushroomScorpian2L2[k][x] = false;
		score+=1;

		bulletL2[exists] = false;

		break;

	}
	}	
	
			

	checkCollision(bulletL2,centiL2,revCheckL2,mushroom1L2Sprite,mushroom2L2Sprite,randMush,mushroom1L2,mushroom2L2,centiheadL2,window,score,mushroomNewL2,mushroomNewL2Sprite,mushroomNew2L2,mushroomNew2L2Sprite,mushroomPoisonL2,mushroomPoisonL2Sprite,mushroomPoisonNL2,mushroomPoisonNL2Sprite,killSoundL2);

	if (bulletL2[y] < -32)
		bulletL2[exists] = false;
}
void drawBulletL2(sf::RenderWindow& window, float bulletL2[], sf::Sprite& bulletL2Sprite, float playerL2[])
{

	if(bulletL2[exists]==true)
	{
	bulletL2Sprite.setPosition(bulletL2[x], bulletL2[y]);
	window.draw(bulletL2Sprite);
	}
}

void spawnMushroomsL2(sf::RenderWindow& window,sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite,bool& checkL2, float bulletL2[], int& scoreL2,float mushroom1L2[][3],float mushroom2L2[][3],int& randMush, float playerL2[],float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite,float mushroomScorpianL2[][3], sf::Sprite& mushroomScorpianL2Sprite,float mushroomScorpian2L2[][3], sf::Sprite& mushroomScorpian2L2Sprite,int& lives)
{

for(int a=0; a<randMush; a++)
{
	if(mushroom1L2[a][x] != false && mushroom1L2[a][x] >0 && mushroom1L2[a][y] != false && mushroom1L2[a][y]>0)
	{
		mushroom1L2Sprite.setPosition(mushroom1L2[a][x], mushroom1L2[a][y]);
		window.draw(mushroom1L2Sprite);
	}

	else
	{
	if(mushroom2L2[a][x] != false && mushroom2L2[a][x]>0 && mushroom2L2[a][y] != false && mushroom2L2[a][y]>0)
	{
		mushroom2L2Sprite.setPosition(mushroom2L2[a][x], mushroom2L2[a][y]);
		window.draw(mushroom2L2Sprite);
	}
	}
}

for(int i=0; i<12; i++)
{
	if(mushroomNewL2[i][x] != false && mushroomNewL2[i][x]>0 && mushroomNewL2[i][y] != false && mushroomNewL2[i][y]>0)
	{
	mushroomNewL2Sprite.setPosition(mushroomNewL2[i][x], mushroomNewL2[i][y]);
	window.draw(mushroomNewL2Sprite);
	}

	else
	{
	if(mushroomNew2L2[i][x] != false && mushroomNew2L2[i][x]>0 && mushroomNew2L2[i][y] != false && mushroomNew2L2[i][y]>0)
	{
	mushroomNew2L2Sprite.setPosition(mushroomNew2L2[i][x], mushroomNew2L2[i][y]);
	window.draw(mushroomNew2L2Sprite);
	}
	}	

}

for(int i=0; i<12; i++)
{
	if(mushroomPoisonL2[i][x] != false && mushroomPoisonL2[i][x]>0 && mushroomPoisonL2[i][y] != false && mushroomPoisonL2[i][y]>0)
	{
	mushroomPoisonL2Sprite.setPosition(mushroomPoisonL2[i][x], mushroomPoisonL2[i][y]);
	window.draw(mushroomPoisonL2Sprite);
	}

	else
	{
	if(mushroomPoisonNL2[i][x] != false && mushroomPoisonNL2[i][x]>0 && mushroomPoisonNL2[i][y] != false && mushroomPoisonNL2[i][y]>0)
	{
	mushroomPoisonNL2Sprite.setPosition(mushroomPoisonNL2[i][x], mushroomPoisonNL2[i][y]);
	window.draw(mushroomPoisonNL2Sprite);
	}
	}
	
	if((playerL2[x] == mushroomPoisonL2[i][x] && playerL2[y] == mushroomPoisonL2[i][y] && playerL2[exists] && mushroomPoisonL2[i][exists]) || (playerL2[x] == mushroomPoisonNL2[i][x] && playerL2[y] == mushroomPoisonNL2[i][y] && playerL2[exists] && mushroomPoisonNL2[i][exists]))
	{
		lives--;
		playerL2[exists] = false;

		if(lives>0)
		{
			playerL2[x] = (gameColumns / 2) * boxPixelsX;
			playerL2[y] = (gameColumns * 3 / 4) * boxPixelsY;
			playerL2[exists] = true;
		}
	}		
}

for(int a=0; a<randMush; a++)
{
	if(mushroomScorpianL2[a][x] != false && mushroomScorpianL2[a][x] >0 && mushroomScorpianL2[a][y] != false && mushroomScorpianL2[a][y]>0)
	{
		mushroomScorpianL2Sprite.setPosition(mushroomScorpianL2[a][x], mushroomScorpianL2[a][y]);
		window.draw(mushroomScorpianL2Sprite);
	}

	else
	{
	if(mushroomScorpian2L2[a][x] != false && mushroomScorpian2L2[a][x]>0 && mushroomScorpian2L2[a][y] != false && mushroomScorpian2L2[a][y]>0)
	{
		mushroomScorpian2L2Sprite.setPosition(mushroomScorpian2L2[a][x], mushroomScorpian2L2[a][y]);
		window.draw(mushroomScorpian2L2Sprite);
	}
	}
}

}

void moveCentiL2(float centiL2[][3], sf::Clock& centiL2Clock, bool& moveL2, int gameGrid[][gameColumns], float bulletL2[],float centiheadL2[][3],bool revCheckL2[][2],float mushroom1L2[][3],float mushroom2L2[][3],int randMush,sf::RenderWindow& window,sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite, float playerL2[], bool& lastCheckL2,float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite,int& lives,float mushroomScorpianL2[][3],float mushroomScorpian2L2[][3], int& hitCheck)
{
    if (centiL2Clock.getElapsedTime().asMilliseconds() < 130)
    return;

    centiL2Clock.restart();

	int bulletSize = 32;
	int spiderSize = 32;
	int mushroomSize = 32;

    for (int p=0; p<12; p++) 
	{

		if(revCheckL2[p][1]==false)    //moving left
		{
			centiL2[p][x] = centiL2[p][x] - 32;
		}

		for(int j=0; j<randMush; j++)
		{
		if(centiL2[p][x] == mushroom1L2[j][x] && centiL2[p][y] == mushroom1L2[j][y] && mushroom1L2[j][y] != 0)
		{

			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}

		for(int j=0; j<randMush; j++)
		{
		if(centiL2[p][x] == mushroom2L2[j][x] && centiL2[p][y] == mushroom2L2[j][y] && centiL2[p][y] != 0)
		{
			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}

		for(int j=0; j<12; j++)
		{
		if(centiL2[p][x] == mushroomNewL2[j][x] && centiL2[p][y] == mushroomNewL2[j][y] && mushroomNewL2[j][exists]==true)
		{

			centiL2[p][y] = centiL2[p][y] + 32;
;
			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}
		
		for(int j=0; j<12; j++)
		{
		if(centiL2[p][x] == mushroomNew2L2[j][x] && centiL2[p][y] == mushroomNew2L2[j][y] && mushroomNew2L2[j][exists]==true)
		{

			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}

		for(int j=0; j<12; j++)
		{
		if(centiL2[p][x] == mushroomPoisonL2[j][x] && centiL2[p][y] == mushroomPoisonL2[j][y] && mushroomPoisonL2[j][exists]==true)
		{

			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}

		for(int j=0; j<12; j++)
		{
		if(centiL2[p][x] == mushroomPoisonNL2[j][x] && centiL2[p][y] == mushroomPoisonNL2[j][y] && mushroomPoisonNL2[j][exists]==true)
		{

			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}

		for(int j=0; j<randMush; j++)
		{
		if(centiL2[p][x] + bulletSize > mushroomScorpianL2[j][x] && centiL2[p][x] < mushroomScorpianL2[j][x] + mushroomSize && centiL2[p][y] + bulletSize > mushroomScorpianL2[j][y] && centiL2[p][y] < mushroomScorpianL2[j][y] + mushroomSize)
		{

			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}

		for(int j=0; j<randMush; j++)
		{
		if(centiL2[p][x] + bulletSize > mushroomScorpian2L2[j][x] && centiL2[p][x] < mushroomScorpian2L2[j][x] + mushroomSize && centiL2[p][y] + bulletSize > mushroomScorpian2L2[j][y] && centiL2[p][y] < mushroomScorpian2L2[j][y] + mushroomSize)
		{

			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}
		}												


		if(centiL2[p][x]==-32)     //ONCE THE CENTIPEDE REACHES THE LEFT MAX OF THE SCREEN
		{
			centiL2[p][y] = centiL2[p][y] + 32;


			if(revCheckL2[p][1]!=false)      // TURNING THE CENTIPEDE TO OPPOSITE DIRECTION
			{
				revCheckL2[p][1]=false;
			}
			else
			{
				revCheckL2[p][1]=true;
			}
		}

		if(revCheckL2[p][1]!=false)
		{
			centiL2[p][x] = centiL2[p][x] + 32;             //CENTIPEDE STARTS MOVING TOWARDS RIGHT
		}

		if(centiL2[p][x]==960 && centiL2[p][y] !=0)       //ONCE THE CENTIPEDE REACHES THE MAX RIGHT OF SCREEN
		{
			centiL2[p][y] = centiL2[p][y] + 32;

			if(revCheckL2[p][1]!=false)         //AGAIN REVERSES THE DIRECTION ONCE IT COMES DOWN
			{
				revCheckL2[p][1] =false;
			}
			else
			{
				revCheckL2[p][1] = true;
			}
		}
		centiheadL2[p][x] = centiL2[p][x];
		centiheadL2[p][y] = centiL2[p][y];

		if((centiL2[p][x]==0 && centiL2[p][y]==960) || centiL2[p][x]==960 && centiL2[p][y]==960)
		{
			centiL2[p][y] = centiL2[p][y] - 32;
			centiheadL2[p][y] = centiL2[p][y];
		}

	}

	for(int l=0; l<12; l++)
	{
		if(playerL2[x] < centiL2[l][x] + 32 && playerL2[x] + 32 > centiL2[l][x] && playerL2[y] < centiL2[l][y] + 32 && playerL2[y] + 32 > centiL2[l][y] && playerL2[exists] && centiL2[l][exists])
		{
			lives--;
			playerL2[exists] = false;

			if(lives>0)
			{
				playerL2[x] = (gameColumns / 2) * boxPixelsX;
				playerL2[y] = (gameColumns * 3 / 4) * boxPixelsY;
				playerL2[exists] = true;
			}
		}
	}	


}

void drawCentiL2(sf::RenderWindow& window, float centiL2[][3], sf::Sprite& centiL2Sprite, float bulletL2[])
{

	for(int k=0; k<12; k++)
	{
		centiL2Sprite.setPosition(centiL2[k][x], centiL2[k][y]);
		window.draw(centiL2Sprite);
	}
}


void drawHeadL2(sf::RenderWindow& window, float centiL2[][3], sf::Sprite& centiheadL2Sprite, float bulletL2[],float centiheadL2[][3])
{
	for(int i=0; i<12; i++)
	{
		if(centiheadL2[i][exists] ==true)
		{
		centiheadL2Sprite.setPosition(centiheadL2[i][x], centiheadL2[i][y]);
		window.draw(centiheadL2Sprite);
		}
	}
}

void moveSpiderL2( float spiderL2[], sf::Clock& spiderL2Clock, int gameGrid[][gameColumns], float playerL2[], float bulletL2[],sf::RenderWindow& window, sf::Sprite& scoreL2Sprite3,float mushroom1L2[][3],float mushroom2L2[][3],int& randMush,sf::Clock& scoreTimer, int& score,sf::Sound& killSoundL2, int& playerPosition2, int& spiderPosition2, int& lives)
{
    static bool directionUp = true;
    static bool directionRight = true;
	int bulletSize = 32;
	int spiderSize = 32;
	int mushroomSize = 32;
	int totalArea = ((3*resolutionY)/4);


    if (spiderL2[y] >= totalArea && spiderL2[y] <= resolutionY-boxPixelsY) 
    {
        if (spiderL2Clock.getElapsedTime().asMilliseconds() > 10) 
        {

            if (directionUp) 
            {
				// spiderSound.play();
                spiderL2[y] = spiderL2[y] - 2;


                if (spiderL2[y] <= totalArea)      // THIS CONDITION WORKS TILL THE SPIDER REACHES AT A MAX GIVEN HEIGHT
                {
                    directionUp = false;
                }
            } 
            else 
            {
				// spiderSound.play();
                spiderL2[y] = spiderL2[y] + 2;

                if (spiderL2[y] >= (resolutionY-boxPixelsY))     // THIS CONDITION WORKS TILL THE SPIDER REACHES AT A MAX GIVEN DEPTH
                {
                    directionUp = true;
                }
            }

            if (directionRight) 
            {
				// spiderSound.play();
                spiderL2[x] = spiderL2[x] + 2;

                if (spiderL2[x] >= resolutionX-boxPixelsX-32)       // THIS CONDITION WORKS TILL THE SPIDER REACHES MAX RIGHT OF SCREEN
                {
                    directionRight = false;
                }
            } 
            else 
            {
				// spiderSound.play();
                spiderL2[x] = spiderL2[x] - 2;            // THIS CONDITION WORKS TILL THE SPIDER REACHES AT A MAX LEFT OF SCREEN

                if (spiderL2[x] <= 0) 
                {
                    directionRight = true;
                }
            }

			// Bullet detection
			if(bulletL2[x] + bulletSize >= spiderL2[x] && bulletL2[x] <= spiderL2[x] + spiderSize && bulletL2[y] + bulletSize >= spiderL2[y] && bulletL2[y] <= spiderL2[y] + spiderSize && spiderL2[exists] && bulletL2[exists])
			{
				// spiderSound.stop();
				killSoundL2.play();
				spiderL2[exists] = false;
				bulletL2[exists] = false;

				if(playerPosition2-spiderPosition2 == 1)
				{
					score+=900;
					scoreTimer.restart();
				}
				else if(playerPosition2-spiderPosition2 == 2)
				{
					score+=600;
					scoreTimer.restart();					
				}
				else
				{
					if(playerPosition2-spiderPosition2 >=3)
					{
					score+=300;
					scoreTimer.restart();
					}
				}
			}

			// Mushroom detection
			for(int k=0; k<randMush; k++)
			{
			if(spiderL2[x] + spiderSize >= mushroom1L2[k][x] && spiderL2[x] <= mushroom1L2[k][x] + mushroomSize && spiderL2[y] + spiderSize >= mushroom1L2[k][y] && spiderL2[y] <= mushroom1L2[k][y] + mushroomSize)
			{
				mushroom1L2[k][x] = false;
				mushroom1L2[k][y] = false;
			}
			}

			for(int k=0; k<randMush; k++)
			{
			if(spiderL2[x] + spiderSize >= mushroom2L2[k][x] && spiderL2[x] <= mushroom2L2[k][x] + mushroomSize && spiderL2[y] + spiderSize >= mushroom2L2[k][y] && spiderL2[y] <= mushroom2L2[k][y] + mushroomSize)
			{
				mushroom2L2[k][x] = false;
				mushroom2L2[k][y] = false;
			}
			}

			// Player Detection
			if(playerL2[x] < spiderL2[x] + 32 && playerL2[x] + 32 > spiderL2[x] && playerL2[y] < spiderL2[y] + 32 && playerL2[y] + 32 > spiderL2[y] && playerL2[exists] && spiderL2[exists])
			{
				lives--;
				playerL2[exists] = false;

				if(lives>0)
				{
					playerL2[x] = (gameColumns / 2) * boxPixelsX;
					playerL2[y] = (gameColumns * 3 / 4) * boxPixelsY;
					playerL2[exists] = true;
				}
			}
            // spiderSound.play();
            spiderL2Clock.restart();
        }
    }
	 
}

void drawScoreL2(sf::RenderWindow& window, sf::Sprite& scoreL2Sprite3,float spiderL2[],sf::Clock& scoreTimer, sf::Time scoreDisplayDuration, int& scoreL2, int& playerPosition2, int& spiderPosition2,sf::Sprite& scoreL2Sprite6, sf::Sprite& scoreL2Sprite9)
{

	if(spiderL2[exists] == false && playerPosition2-spiderPosition2 == 1)
	{
	scoreL2Sprite9.setPosition(spiderL2[x], spiderL2[y]);
	if(scoreTimer.getElapsedTime() < scoreDisplayDuration)
	{
    window.draw(scoreL2Sprite9);
	}
	}

	else if(spiderL2[exists] == false && playerPosition2-spiderPosition2 == 2)
	{
	scoreL2Sprite6.setPosition(spiderL2[x], spiderL2[y]);
	if(scoreTimer.getElapsedTime() < scoreDisplayDuration)
	{
    window.draw(scoreL2Sprite6);
	}
	}

	else
	{
	if(spiderL2[exists] == false && playerPosition2-spiderPosition2 >= 3)
	{
	scoreL2Sprite3.setPosition(spiderL2[x], spiderL2[y]);
	if(scoreTimer.getElapsedTime() < scoreDisplayDuration)
	{
    window.draw(scoreL2Sprite3);
	}
	}
	}

}

void drawSpiderL2(sf::RenderWindow& window, float spiderL2[], sf::Sprite& spiderL2Sprite)
{
	if(spiderL2[exists]==true)
	{
	spiderL2Sprite.setPosition(spiderL2[x], spiderL2[y]);
	window.draw(spiderL2Sprite);
	}
}

void checkCollisionL2(float bulletL2[], float centiL2[][3],bool revCheckL2[][2],sf::Sprite mushroom1L2Sprite,sf::Sprite& mushroom2L2Sprite,int randMush,float mushroom1L2[][3],float mushroom2L2[][3],float centiheadL2[][3],sf::RenderWindow& window, int& score,float mushroomNewL2[][3], sf::Sprite& mushroomNewL2Sprite,float mushroomNew2L2[][3], sf::Sprite& mushroomNew2L2Sprite,float mushroomPoisonL2[][3], sf::Sprite& mushroomPoisonL2Sprite,float mushroomPoisonNL2[][3], sf::Sprite& mushroomPoisonNL2Sprite,sf::Sound& killSoundL2)
{
	int CheckSeg;

for(int i=0; i<12; i++)
{
	if(bulletL2[x] + 32 > centiL2[i][x] && bulletL2[x] < centiL2[i][x] + boxPixelsX && bulletL2[y] + 32 > centiL2[i][y] && bulletL2[y] < centiL2[i][y] + boxPixelsY && bulletL2[exists]==true && centiheadL2[i][exists]==true && centiL2[i][exists]==true)
	{

		score+=20;
		CheckSeg=i;
		while(centiL2[CheckSeg][exists]!=false)
		{
			if(centiL2[CheckSeg][exists]!=false)
			{
			centiL2[CheckSeg][x] = -1000;
			centiL2[CheckSeg][y] = -1000;			
			centiL2[CheckSeg][exists]=false;
			centiheadL2[CheckSeg][x] = -1000;
			centiheadL2[CheckSeg][y] = -1000;	
			centiheadL2[CheckSeg][exists]=false;
			}
			CheckSeg++;
		}

		// bulletL2[exists]=false;
		// centiL2[i][x] = -1000;
		// centiL2[i][y] = -1000;
		// centiL2[i][exists] = false;
		// centiheadL2[i][x] = -1000;
		// centiheadL2[i][y] = -1000;			
		// centiheadL2[i][exists] = false;
		// centiL2[i+1][x] = centiheadL2[i+1][x];
		// centiL2[i+1][y] = centiheadL2[i+1][y];		
		// centiheadL2[i+1][exists] = true;
		// break;

	} 
}

	for (int i = 0; i < 12; ++i) 
	{
        // Check collision between bullet and centipede segment
        if (bulletL2[x] + 32 > centiL2[i][x] && bulletL2[x] < centiL2[i][x] + boxPixelsX && bulletL2[y] + 32 > centiL2[i][y] && bulletL2[y] < centiL2[i][y] + boxPixelsY && centiL2[i][exists]==true && centiheadL2[i][exists]==false) 
		{
			killSoundL2.play();
			score+=10;
			bulletL2[exists] = false;
			centiL2[i][exists]=false;
			centiheadL2[i+1][exists] = true;
			centiheadL2[i][exists] = false; 

			if(centiL2[i][y] < (3*resolutionY)/4)
			{
			for(int k=i; k<12; k++)
			{
				mushroomNewL2[k][x] = centiL2[i][x];
				mushroomNewL2[k][y] = centiL2[i][y];
				mushroomNewL2[k][exists] = true;
				break;
			}
			}

			if(centiL2[i][y] > (3*resolutionY)/4)
			{
			for(int k=i; k<12; k++)
			{
				mushroomPoisonL2[k][x] = centiL2[i][x];
				mushroomPoisonL2[k][y] = centiL2[i][y];
				mushroomPoisonL2[k][exists] = true;
				break;
			}
			}

			break;
        }
    }
}

void drawFleaL2(int gameGrid[][gameColumns],sf::RenderWindow& window, float bulletL2[], float mushroom1L2[][3], float mushroom2L2[][3],float fleaL2[][3], sf::Sprite& fleaL2Sprite, bool& checkFlagL2,int randMush)
{

	for(int k=0; k<50; k++)
	{
		if(fleaL2[k][exists]==true )
		{	
		if(k>0 && fleaL2[k-1][exists]==false && fleaL2[k+1][exists]==false)
			{
        	fleaL2Sprite.setPosition(fleaL2[k][x], fleaL2[k][y]);
        	window.draw(fleaL2Sprite);
			}
		if(k==0 && fleaL2[k+1][exists]==false)
			{
        fleaL2Sprite.setPosition(fleaL2[k][x], fleaL2[k][y]);
        window.draw(fleaL2Sprite);
			}
		}
	}

}

void moveFleaL2(float fleaL2[][3], sf::Clock& fleaL2Clock, bool& checkFlagL2,int& lives, float playerL2[])
{
	for(int i=0; i<50; i++)
	{
    if (fleaL2[i][exists]==true && fleaL2Clock.getElapsedTime().asMilliseconds() >= 20)
    {
        fleaL2Clock.restart();
        fleaL2[i][y] += 10;
    }

	if(fleaL2[i][y]==resolutionY && fleaL2[i][exists]==true)
	{
		fleaL2[i][exists]=false;
		fleaL2[i+1][exists]=true;
	}
	}

	for(int i=0; i<50; i++)
	{
			if(playerL2[x] < fleaL2[i][x] + 32 && playerL2[x] + 32 > fleaL2[i][x] && playerL2[y] < fleaL2[i][y] + 32 && fleaL2[i][y] + 32 > fleaL2[i][y] && playerL2[exists] && fleaL2[i][exists])
		{
			lives--;
			playerL2[exists] = false;

			if(lives>0)
			{
				playerL2[x] = (gameColumns / 2) * boxPixelsX;
				playerL2[y] = (gameColumns * 3 / 4) * boxPixelsY;
				playerL2[exists]= true;
			}
			
		}
	}	
}

void drawScorpianL2(int gameGrid[][gameColumns],sf::RenderWindow& window, float bulletL2[], float mushroom1L2[][3], float mushroom2L2[][3],float scorpianL2[][3], sf::Sprite& scorpianL2Sprite, bool& checkFlagL2,int randMush)
{
 
	for(int k=0; k<50; k++)
	{
		if(scorpianL2[k][exists]==true )
		{	
		if(k>0 && scorpianL2[k-1][exists]==false && scorpianL2[k+1][exists]==false)
			{
        	scorpianL2Sprite.setPosition(scorpianL2[k][x], scorpianL2[k][y]);
        	window.draw(scorpianL2Sprite);
			}
		if(k==0 && scorpianL2[k+1][exists]==false)
			{
        scorpianL2Sprite.setPosition(scorpianL2[k][x], scorpianL2[k][y]);
        window.draw(scorpianL2Sprite);
			}
		}
	}

	
}

void moveScorpianL2(float scorpianL2[][3], sf::Clock& scorpianL2Clock, bool& checkFlagL2,float mushroomScorpianL2[][3],float mushroom1L2[][3],float mushroom2L2[][3],int& randMush, int& lives, float playerL2[])
{
	for(int i=0; i<50; i++)
	{

    if (scorpianL2[i][exists]==true && scorpianL2Clock.getElapsedTime().asMilliseconds() > 20)
    {
        scorpianL2Clock.restart();
        scorpianL2[i][x] += 4;
    }

	if(scorpianL2[i][x]==resolutionX+20*32 && scorpianL2[i][exists]==true)
	{
		scorpianL2[i][exists]=false;
		scorpianL2[i+1][exists]=true;
	}

	for(int k=0; k<randMush; k++)
	{
		if((scorpianL2[i][x] == mushroom1L2[k][x] && scorpianL2[i][y] == mushroom1L2[k][y] && scorpianL2[i][exists] && mushroom1L2[k][exists]))
		{
			mushroomScorpianL2[k][x] = mushroom1L2[k][x];
			mushroomScorpianL2[k][y] = mushroom1L2[k][y];

			mushroom1L2[k][x] = -1023;
			mushroom1L2[k][y] = -1023;

			mushroom1L2[k][exists] = false;
		}

		if((scorpianL2[i][x] == mushroom2L2[k][x] && scorpianL2[i][y] == mushroom2L2[k][y] && scorpianL2[i][exists] && mushroom2L2[k][exists]))
		{
			mushroomScorpianL2[k][x] = mushroom2L2[k][x];
			mushroomScorpianL2[k][y] = mushroom2L2[k][y];

			mushroom2L2[k][x] = -1023;
			mushroom2L2[k][y] = -1023;

			mushroom2L2[k][exists] = false;
		}
	}

		if(playerL2[x] < scorpianL2[i][x] + 32 && playerL2[x] + 32 > scorpianL2[i][x] && playerL2[y] < scorpianL2[i][y] + 32 && scorpianL2[i][y] + 32 > scorpianL2[i][y] && playerL2[exists] && scorpianL2[i][exists])
		{
			lives--;
			playerL2[exists] = false;

			if(lives>0)
			{
				playerL2[x] = (gameColumns / 2) * boxPixelsX;
				playerL2[y] = (gameColumns * 3 / 4) * boxPixelsY;
				playerL2[exists]= true;
			}
			
		}		

	}

}




