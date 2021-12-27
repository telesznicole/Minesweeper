#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <random>

//variables created
struct block{
    bool isRevealed = false;
    bool tagged = false;
    bool hasMine = false;
    int neighborNum = 0;
    bool isOnEnd = false;
    bool flagUp = false;
};
block gameBoard[25][16];
bool debugOn = false;
std::vector<std::vector<char> > boards;
std::vector<int> minePositions;
std::vector<int>flagPositions;
std::vector<int>revealedTilePositions;
bool winning = true;
bool gameWon = false;
int currentBoard = 0;

int findElementNum(int j, int k){
    return ((k * 25) + j);
}

void loadBoard(const std::string& boardName){
    std::ifstream file(boardName);
    //read info from file if open
    if (file.is_open()){
        winning = true;
        gameWon = false;
        std::vector<char> loadedBoard;

        while (!file.eof()){
            std::string line;

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }

            getline(file, line);
            for (unsigned int j = 0; j < 25; j++){
                //read each char of line and push it into array
                loadedBoard.push_back(line[j]);
            }
        }

        //clear vectors
        minePositions.clear();
        flagPositions.clear();
        revealedTilePositions.clear();

        //find mine positions
        for (unsigned int i = 0; i < loadedBoard.size(); i++){
            if (loadedBoard[i] == '1')
                minePositions.push_back(i);
        }

        //push loadedBoard into boards vector
        boards.push_back(loadedBoard);
    }
    file.close();
}

void setNeighborNumbers(){
    for (unsigned int i = 0; i < 16; i++){
        for (unsigned int j = 0; j < 25; j++){
            int numOfNeighbors = 0;
            if (!gameBoard[j][i].isOnEnd){
                //check all to left
                if (gameBoard[j - 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i + 1].hasMine)
                    numOfNeighbors++;

                //check all to right
                if (gameBoard[j + 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j+1][i + 1].hasMine)
                    numOfNeighbors++;

                //check above, below
                if (gameBoard[j][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i + 1].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            //do special cases for corners
            else if ((j == 0) && (i == 0)){
                //check top left corner
                if (gameBoard[j + 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i + 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i + 1].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            else if ((j == 0) && (i == 15)){
                //check bottom left corner
                if (gameBoard[j][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            else if ((j == 24) && (i == 0)){
                //check top right corner
                if (gameBoard[j - 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i + 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i + 1].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            else if ((j == 24) && (i == 15)){
                //check bottom right corner
                if (gameBoard[j - 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i - 1].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            else if (j == 0){
                //check for left down
                if (gameBoard[j][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i + 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i + 1].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            else if (j == 24){
                //check for right down
                if (gameBoard[j][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i + 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i + 1].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            else if (i == 0){
                //check for top row
                if (gameBoard[j - 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i + 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i + 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i + 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }
            else if (i == 15){
                //check for bottom row
                if (gameBoard[j - 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j - 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j + 1][i - 1].hasMine)
                    numOfNeighbors++;
                if (gameBoard[j][i - 1].hasMine)
                    numOfNeighbors++;

                gameBoard[j][i].neighborNum = numOfNeighbors;
            }

            if (gameBoard[j][i].hasMine)
                gameBoard[j][i].neighborNum = 0;
        }
    }
}

int rand(int min, int max){
    static std::mt19937 random;

    std::uniform_int_distribution<int> dist(min, max);
    return dist(random);
}

void createRandomBoard(){
    winning = true;
    gameWon = false;
    std::vector<char> randBoard;

    int mineCount = 0;

    for (unsigned int i = 0; i < 400; i++){
        if (mineCount >= 50)
            randBoard.push_back('0');
        else{
            int num = rand(0, 1);
            if (num == 0)
                randBoard.push_back('0');
            else{
                for (unsigned int k = 0; k < (rand() % 20); k++){
                    randBoard.push_back('0');
                }
                randBoard.push_back('1');
                mineCount++;
            }
        }

    }

    //clear vectors
    minePositions.clear();
    flagPositions.clear();
    revealedTilePositions.clear();

    //find mine positions
    for (unsigned int i = 0; i < randBoard.size(); i++){
        if (randBoard[i] == '1')
            minePositions.push_back(i);
    }

    boards.push_back(randBoard);

    int blockCountCreation = 0;
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < 25; j++){
            //create object
            block blokko;

            //if block is on end
            if ((i == 0) || (i == 15) || (j == 0) || (j == 24))
                blokko.isOnEnd = true;

            //if block has mine
            if (boards.at(currentBoard).at(blockCountCreation) == '1')
                blokko.hasMine = true;

            //put it in array[i][j]
            gameBoard[j][i] = blokko;

            blockCountCreation++;
        }
    }
    setNeighborNumbers();
    currentBoard++;
}

void leftClickToReveal(int i){
    int hiddenIter = 0;

    //add where it finds nearby ones
    for (int h = 0; h < 16; h++){
        for (int t = 0; t < 25; t++){
            //if i != a position in flagPositions
            if (i == hiddenIter){
                gameBoard[t][h].isRevealed = true;

                //if clicked where flag is then dont make it reveal
                for (int p = 0; p < flagPositions.size(); p++){
                    if (flagPositions[p] == i){
                        gameBoard[t][h].isRevealed = false;
                        continue;
                    }
                }

                //recursive search part
                if ((gameBoard[t][h].neighborNum == 0) && (!gameBoard[t][h].hasMine) && (!gameBoard[t][h].tagged)){
                    //put once or put in each???
                    //reset at end or nah???

                    gameBoard[t][h].tagged = true;

                    //change to only check cardinal directions

                    //top left corner
                    if ((t == 0) && (h == 0)){
                        leftClickToReveal(findElementNum(1,0));
                        leftClickToReveal(findElementNum(1,1));
                        leftClickToReveal(findElementNum(0,1));
                    }
                        //top right corner
                    else if ((t == 24) && (h == 0)){
                        leftClickToReveal(findElementNum(23,0));
                        leftClickToReveal(findElementNum(24,1));
                        leftClickToReveal(findElementNum(23,1));
                    }
                        //bottom right corner
                    else if ((t == 24) && (h == 15)){
                        leftClickToReveal(findElementNum(23, 15));
                        leftClickToReveal(findElementNum(23, 14));
                        leftClickToReveal(findElementNum(24, 14));
                    }
                        //bottom left corner
                    else if ((t == 0) && (h == 15)){
                        leftClickToReveal(findElementNum(0, 14));
                        leftClickToReveal(findElementNum(1,14));
                        leftClickToReveal(findElementNum(1,15));
                    }
                        //top row
                    else if (h == 0){
                        leftClickToReveal(findElementNum(t - 1, h));
                        leftClickToReveal(findElementNum(t + 1, h));
                        leftClickToReveal(findElementNum(t + 1, h + 1));
                        leftClickToReveal(findElementNum(t, h + 1));
                        leftClickToReveal(findElementNum(t - 1, h + 1));
                    }
                        //bottom row
                    else if (h == 15){
                        leftClickToReveal(findElementNum(t - 1, h));
                        leftClickToReveal(findElementNum(t - 1, h - 1));
                        leftClickToReveal(findElementNum(t, h - 1));
                        leftClickToReveal(findElementNum(t + 1, h - 1));
                        leftClickToReveal(findElementNum(t + 1, h));
                    }
                        //right
                    else if (t == 0){
                        leftClickToReveal(findElementNum(t, h - 1));
                        leftClickToReveal(findElementNum(t + 1, h - 1));
                        leftClickToReveal(findElementNum(t + 1, h));
                        leftClickToReveal(findElementNum(t + 1, h + 1));
                        leftClickToReveal(findElementNum(t, h + 1));
                    }
                        //left
                    else if (t == 24){
                        leftClickToReveal(findElementNum(t - 1, h));
                        leftClickToReveal(findElementNum(t - 1, h - 1));
                        leftClickToReveal(findElementNum(t, h - 1));
                        leftClickToReveal(findElementNum(t, h + 1));
                        leftClickToReveal(findElementNum(t - 1, h + 1));
                    }
                        //middle
                    else{
                        leftClickToReveal(findElementNum(t - 1, h));
                        leftClickToReveal(findElementNum(t - 1, h - 1));
                        leftClickToReveal(findElementNum(t, h - 1));
                        leftClickToReveal(findElementNum(t + 1, h - 1));
                        leftClickToReveal(findElementNum(t + 1, h));
                        leftClickToReveal(findElementNum(t + 1, h + 1));
                        leftClickToReveal(findElementNum(t, h + 1));
                        leftClickToReveal(findElementNum(t - 1, h + 1));
                    }
                }

                //pushback location to revealedPositions vector
                if (gameBoard[t][h].isRevealed){
                    revealedTilePositions.push_back(hiddenIter);
                }
            }
            hiddenIter++;
        }
    }
}

int main()
{
    createRandomBoard();

    int fillCount = 0;
    for (unsigned int i = 0; i < 16; i++){
        for (unsigned int j = 0; j < 25; j++){
            if (gameBoard[j][i].isRevealed)
                revealedTilePositions.push_back(fillCount);
            fillCount++;
        }
    }

    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");

    //load textures
    sf::Texture tile_hidden, tile_revealed, face_happy, face_lose, face_win, debug, test_1, test_2, test_3, flag, mine,
        number_1, number_2, number_3, number_4, number_5, number_6, number_7, number_8, digits;
    tile_hidden.loadFromFile("images/tile_hidden.png");
    tile_revealed.loadFromFile("images/tile_revealed.png");
    face_happy.loadFromFile("images/face_happy.png");
    face_lose.loadFromFile("images/face_lose.png");
    face_win.loadFromFile("images/face_win.png");
    debug.loadFromFile("images/debug.png");
    test_1.loadFromFile("images/test_1.png");
    test_2.loadFromFile("images/test_2.png");
    test_3.loadFromFile("images/test_3.png");
    flag.loadFromFile("images/flag.png");
    mine.loadFromFile("images/mine.png");
    number_1.loadFromFile("images/number_1.png");
    number_2.loadFromFile("images/number_2.png");
    number_3.loadFromFile("images/number_3.png");
    number_4.loadFromFile("images/number_4.png");
    number_5.loadFromFile("images/number_5.png");
    number_6.loadFromFile("images/number_6.png");
    number_7.loadFromFile("images/number_7.png");
    number_8.loadFromFile("images/number_8.png");
    digits.loadFromFile("images/digits.png");

    //create needed sprites
    std::vector<sf::Sprite> hiddenTiles;
    sf::Sprite tile_hiddenSprite(tile_hidden);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            tile_hiddenSprite.setPosition(sf::Vector2f(j * tile_hiddenSprite.getGlobalBounds().width,
                    i * tile_hiddenSprite.getGlobalBounds().height));
            hiddenTiles.push_back(tile_hiddenSprite);
        }
    }
    std::vector<sf::Sprite> revealedTiles;
    sf::Sprite tile_revealedSprite(tile_revealed);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            tile_revealedSprite.setPosition(sf::Vector2f(j * tile_revealedSprite.getGlobalBounds().width,
                                                         i * tile_revealedSprite.getGlobalBounds().height));
            revealedTiles.push_back(tile_revealedSprite);
        }
    }
    sf::Sprite face_happySprite(face_happy);
    sf::Sprite face_loseSprite(face_lose);
    sf::Sprite face_winSprite(face_win);
    sf::Sprite debugSprite(debug);
    sf::Sprite test_1Sprite(test_1);
    sf::Sprite test_2Sprite(test_2);
    sf::Sprite test_3Sprite(test_3);
    std::vector<sf::Sprite> flags;
    sf::Sprite flagSprite(flag);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            flagSprite.setPosition(sf::Vector2f(j * flagSprite.getGlobalBounds().width,
                                                i * flagSprite.getGlobalBounds().height));
            flags.push_back(flagSprite);
        }
    }
    std::vector<sf::Sprite> mines;
    sf::Sprite mineSprite(mine);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            mineSprite.setPosition(sf::Vector2f(j * mineSprite.getGlobalBounds().width,
                    i * mineSprite.getGlobalBounds().height));
            mines.push_back(mineSprite);
        }
    }
    std::vector<sf::Sprite> ones;
    sf::Sprite number_1Sprite(number_1);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_1Sprite.setPosition(sf::Vector2f(j * number_1Sprite.getGlobalBounds().width,
                                                i * number_1Sprite.getGlobalBounds().height));
            ones.push_back(number_1Sprite);
        }
    }
    std::vector<sf::Sprite> twos;
    sf::Sprite number_2Sprite(number_2);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_2Sprite.setPosition(sf::Vector2f(j * number_2Sprite.getGlobalBounds().width,
                                                    i * number_2Sprite.getGlobalBounds().height));
            twos.push_back(number_2Sprite);
        }
    }
    std::vector<sf::Sprite> threes;
    sf::Sprite number_3Sprite(number_3);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_3Sprite.setPosition(sf::Vector2f(j * number_3Sprite.getGlobalBounds().width,
                                                    i * number_3Sprite.getGlobalBounds().height));
            threes.push_back(number_3Sprite);
        }
    }
    std::vector<sf::Sprite> fours;
    sf::Sprite number_4Sprite(number_4);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_4Sprite.setPosition(sf::Vector2f(j * number_4Sprite.getGlobalBounds().width,
                                                    i * number_4Sprite.getGlobalBounds().height));
            fours.push_back(number_4Sprite);
        }
    }
    std::vector<sf::Sprite> fives;
    sf::Sprite number_5Sprite(number_5);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_5Sprite.setPosition(sf::Vector2f(j * number_5Sprite.getGlobalBounds().width,
                                                    i * number_5Sprite.getGlobalBounds().height));
            fives.push_back(number_5Sprite);
        }
    }
    std::vector<sf::Sprite> sixs;
    sf::Sprite number_6Sprite(number_6);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_6Sprite.setPosition(sf::Vector2f(j * number_6Sprite.getGlobalBounds().width,
                                                    i * number_6Sprite.getGlobalBounds().height));
            sixs.push_back(number_6Sprite);
        }
    }
    std::vector<sf::Sprite> sevens;
    sf::Sprite number_7Sprite(number_7);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_7Sprite.setPosition(sf::Vector2f(j * number_7Sprite.getGlobalBounds().width,
                                                    i * number_7Sprite.getGlobalBounds().height));
            sevens.push_back(number_7Sprite);
        }
    }
    std::vector<sf::Sprite> eights;
    sf::Sprite number_8Sprite(number_8);
    for (auto i = 0; i < 16; i++){
        for (auto j = 0; j < 25; j++){
            number_8Sprite.setPosition(sf::Vector2f(j * number_8Sprite.getGlobalBounds().width,
                                                    i * number_8Sprite.getGlobalBounds().height));
            eights.push_back(number_8Sprite);
        }
    }
    std::vector<sf::Sprite> digitsToSmash;
    std::vector<sf::Sprite> digitsToSmashNegative;
    sf::Sprite digitsSprite(digits);
    for (auto i = 0; i < 11; i++){
        if (i == 0){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 1){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 2){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 3){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 4){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 5){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 6){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 7){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 8){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 9){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 10){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
        if (i == 11){
            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect((21 * i), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmash.push_back(digitsSprite);
        }
    }
    for (auto i = 0; i < 11; i++){
        if (i == 0){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 1){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 2){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 3){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 4){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 5){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 6){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 7){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 8){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 9){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 10){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
        if (i == 11){
            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(0, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(21, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);

            digitsSprite.setTextureRect(sf::IntRect(((21 * i) + 21), 0, 21, 32));
            digitsSprite.setPosition(sf::Vector2f(42, (16 * 32)));
            digitsToSmashNegative.push_back(digitsSprite);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            //if button is pressed
            if (event.type == sf::Event::MouseButtonPressed){
                //if left button
                if (event.mouseButton.button == sf::Mouse::Left){
                    //get position
                    auto mousePosition = sf::Mouse::getPosition(window);

                    //click debug mode
                    if (debugSprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                        if (!debugOn)
                            debugOn = true;
                        else if (debugOn)
                            debugOn = false;
                    }

                    if (winning){
                        //click on tile (reveal it)
                        for (int i = 0; i < hiddenTiles.size(); i++){
                            if (hiddenTiles[i].getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                                leftClickToReveal(i);
                            }
                        }
                    }

                    //hit a mine
                    for (unsigned int i = 0; i < revealedTiles.size(); i++){
                        if (revealedTiles[i].getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                            for (int j = 0; j < minePositions.size(); j++){
                                if (minePositions[j] == i){
                                    winning = false;
                                }
                            }
                        }
                    }

                    //click to load board
                    if (test_1Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                        loadBoard("boards/testboard1.brd");

                        int blockCountCreation = 0;
                        for (int i = 0; i < 16; i++){
                            for (int j = 0; j < 25; j++){
                                //create object
                                block blokko;

                                //if block is on end
                                if ((i == 0) || (i == 15) || (j == 0) || (j == 24))
                                    blokko.isOnEnd = true;

                                //if block has mine
                                if (boards.at(currentBoard).at(blockCountCreation) == '1')
                                    blokko.hasMine = true;

                                //put it in array[i][j]
                                gameBoard[j][i] = blokko;

                                blockCountCreation++;
                            }
                        }
                        setNeighborNumbers();
                        currentBoard++;
                    }
                    if (test_2Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                        loadBoard("boards/testboard2.brd");

                        int blockCountCreation = 0;
                        for (int i = 0; i < 16; i++){
                            for (int j = 0; j < 25; j++){
                                //create object
                                block blokko;

                                //if block is on end
                                if ((i == 0) || (i == 15) || (j == 0) || (j == 24))
                                    blokko.isOnEnd = true;

                                //if block has mine
                                if (boards.at(currentBoard).at(blockCountCreation) == '1')
                                    blokko.hasMine = true;

                                //put it in array[i][j]
                                gameBoard[j][i] = blokko;

                                blockCountCreation++;
                            }
                        }
                        setNeighborNumbers();
                        currentBoard++;
                    }
                    if (test_3Sprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                        loadBoard("boards/testboard3.brd");

                        int blockCountCreation = 0;
                        for (int i = 0; i < 16; i++){
                            for (int j = 0; j < 25; j++){
                                //create object
                                block blokko;

                                //if block is on end
                                if ((i == 0) || (i == 15) || (j == 0) || (j == 24))
                                    blokko.isOnEnd = true;

                                //if block has mine
                                if (boards.at(currentBoard).at(blockCountCreation) == '1')
                                    blokko.hasMine = true;

                                //put it in array[i][j]
                                gameBoard[j][i] = blokko;

                                blockCountCreation++;
                            }
                        }
                        setNeighborNumbers();
                        currentBoard++;
                    }
                    if (face_happySprite.getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                        createRandomBoard();
                    }
                }
                //if right button
                else if (event.mouseButton.button == sf::Mouse::Right){
                    //get position
                    auto mousePosition = sf::Mouse::getPosition(window);

                    if (winning){
                        //flag stuff
                        int sir = 0;
                        for (unsigned int i = 0; i < hiddenTiles.size(); i++){
                            if (hiddenTiles[i].getGlobalBounds().contains(sf::Vector2f(mousePosition.x, mousePosition.y))){
                                for (unsigned int o = 0; o < 16; o++){
                                    for (unsigned int j = 0; j < 25; j++){
                                        if (gameBoard[j][o].flagUp && sir == i){
                                            int addThis = 0;
                                            int addToIter = 0;
                                            for (unsigned int u = 0; u < flagPositions.size(); u++){
                                                if (flagPositions[u] == i){
                                                    addThis = addToIter;
                                                }
                                                addToIter++;
                                            }
                                            flagPositions.erase(flagPositions.begin() + addThis);
                                            gameBoard[j][o].flagUp = false;
                                        }
                                        else if (!gameBoard[j][o].flagUp && sir == i){
                                            int countF = 0;
                                            for (unsigned int k = 0; k < 16; k++){
                                                for (unsigned int j = 0; j < 25; j++){
                                                    if ((countF == i) && (!gameBoard[j][k].isRevealed)){
                                                        flagPositions.push_back(i);
                                                        gameBoard[j][k].flagUp = true;
                                                    }
                                                    countF++;
                                                }
                                            }
                                        }
                                        sir++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        //determines if gameWon
        int finalCounter = 0;
        for (unsigned int i = 0; i < 16; i++){
            for (unsigned int j = 0; j < 25; j++){
                if (gameBoard[j][i].hasMine || gameBoard[j][i].isRevealed)
                    finalCounter++;
            }
        }
        if (finalCounter == 400){
            gameWon = true;
        }

        //only do once
        window.clear();

        //draw revealed tiles
        for (unsigned int i = 0; i < revealedTiles.size(); i++){
            window.draw(revealedTiles[i]);
        }

        //draw mines
        int mineCountDrawing = 0;
        for (unsigned int i = 0; i < 16; i++){
            for (unsigned int j = 0; j < 25; j++){
                if (gameBoard[j][i].hasMine){
                    window.draw(mines[mineCountDrawing]);
                }
                mineCountDrawing++;
            }
        }

        //draw neighbor numbers
        int numCountDrawing = 0;
        for (unsigned int i = 0; i < 16; i++){
            for (unsigned int j = 0; j < 25; j++){
                if (gameBoard[j][i].neighborNum == 1){
                    window.draw(ones[numCountDrawing]);
                }
                else if (gameBoard[j][i].neighborNum == 2){
                    window.draw(twos[numCountDrawing]);
                }
                else if (gameBoard[j][i].neighborNum == 3){
                    window.draw(threes[numCountDrawing]);
                }
                else if (gameBoard[j][i].neighborNum == 4){
                    window.draw(fours[numCountDrawing]);
                }
                else if (gameBoard[j][i].neighborNum == 5){
                    window.draw(fives[numCountDrawing]);
                }
                else if (gameBoard[j][i].neighborNum == 6){
                    window.draw(sixs[numCountDrawing]);
                }
                else if (gameBoard[j][i].neighborNum == 7){
                    window.draw(sevens[numCountDrawing]);
                }
                else if (gameBoard[j][i].neighborNum == 8){
                    window.draw(eights[numCountDrawing]);
                }
                numCountDrawing++;
            }
        }

        //draw hidden tiles
        int tileIter = 0;
        for (unsigned int i = 0; i < 16; i++){
            for (unsigned int j = 0; j < 25; j++){
                if (!gameBoard[j][i].isRevealed)
                    window.draw(hiddenTiles[tileIter]);
                tileIter++;
            }
        }

        //draw mines on top of everything if debugOn
        if (debugOn || !winning){
            int mineCountDrawingInner = 0;
            for (unsigned int i = 0; i < 16; i++){
                for (unsigned int j = 0; j < 25; j++){
                    if (gameBoard[j][i].hasMine){
                        window.draw(mines[mineCountDrawingInner]);
                    }
                    mineCountDrawingInner++;
                }
            }
        }

        //draw flags
        int flagCountDrawing = 0;
        for (unsigned int i = 0; i < 16; i++){
            for (unsigned int j = 0; j < 25; j++){
                for (unsigned int k = 0; k < flagPositions.size(); k++){
                    if (flagPositions[k] == flagCountDrawing){
                        window.draw(flags[flagCountDrawing]);
                    }
                }
                flagCountDrawing++;
            }
        }

        //draw counter
        //count mines
        int mineCount = 0;
        for (int i = 0; i < 16; i++){
            for (int j = 0; j < 25; j++){
                if (gameBoard[j][i].hasMine){
                    mineCount++;
                }
            }
        }
        //positive number
        if ((int)(mineCount - flagPositions.size()) >= 0){
            //determine each digit
            int num = (int)(mineCount - flagPositions.size());
            int onesDigit = (num % 10);
            int tensDigit = ((num / 10) % 10);

            window.draw(digitsToSmash[0]);
            if (tensDigit == 9){
                window.draw(digitsToSmash[28]);
            }
            if (tensDigit == 8){
                window.draw(digitsToSmash[25]);
            }
            if (tensDigit == 7){
                window.draw(digitsToSmash[22]);
            }
            if (tensDigit == 6){
                window.draw(digitsToSmash[19]);
            }
            if (tensDigit == 5){
                window.draw(digitsToSmash[16]);
            }
            if (tensDigit == 4){
                window.draw(digitsToSmash[13]);
            }
            if (tensDigit == 3){
                window.draw(digitsToSmash[10]);
            }
            if (tensDigit == 2){
                window.draw(digitsToSmash[7]);
            }
            if (tensDigit == 1){
                window.draw(digitsToSmash[4]);
            }
            if (tensDigit == 0){
                window.draw(digitsToSmash[1]);
            }
            if (onesDigit == 9){
                window.draw(digitsToSmash[29]);
            }
            if (onesDigit == 8){
                window.draw(digitsToSmash[26]);
            }
            if (onesDigit == 7){
                window.draw(digitsToSmash[23]);
            }
            if (onesDigit == 6){
                window.draw(digitsToSmash[20]);
            }
            if (onesDigit == 5){
                window.draw(digitsToSmash[17]);
            }
            if (onesDigit == 4){
                window.draw(digitsToSmash[14]);
            }
            if (onesDigit == 3){
                window.draw(digitsToSmash[11]);
            }
            if (onesDigit == 2){
                window.draw(digitsToSmash[8]);
            }
            if (onesDigit == 1){
                window.draw(digitsToSmash[5]);
            }
            if (onesDigit == 0){
                window.draw(digitsToSmash[2]);
            }
        }
        //negative number
        else{
            //determine each digit
            int num = ((int)(mineCount - flagPositions.size()) * (-1));
            int onesDigit = (num % 10);
            int tensDigit = ((num / 10) % 10);
            int hundredsDigit = ((num / 100) % 10);

            window.draw(digitsToSmash[30]);
            if (hundredsDigit == 9){
                digitsToSmash[27].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[27]);
            }
            if (hundredsDigit == 8){
                digitsToSmash[24].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[24]);
            }
            if (hundredsDigit == 7){
                digitsToSmash[21].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[21]);
            }
            if (hundredsDigit == 6){
                digitsToSmash[18].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[18]);
            }
            if (hundredsDigit == 5){
                digitsToSmash[15].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[15]);
            }
            if (hundredsDigit == 4){
                digitsToSmash[12].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[12]);
            }
            if (hundredsDigit == 3){
                digitsToSmash[9].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[9]);
            }
            if (hundredsDigit == 2){
                digitsToSmash[6].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[6]);
            }
            if (hundredsDigit == 1){
                digitsToSmash[3].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[3]);
            }
            if (hundredsDigit == 0){
                digitsToSmash[0].setPosition(sf::Vector2f(21, (16 *32)));
                window.draw(digitsToSmash[0]);
            }
            if (tensDigit == 9){
                digitsToSmash[28].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[28]);
            }
            if (tensDigit == 8){
                digitsToSmash[25].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[25]);
            }
            if (tensDigit == 7){
                digitsToSmash[22].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[22]);
            }
            if (tensDigit == 6){
                digitsToSmash[19].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[19]);
            }
            if (tensDigit == 5){
                digitsToSmash[16].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[16]);
            }
            if (tensDigit == 4){
                digitsToSmash[13].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[13]);
            }
            if (tensDigit == 3){
                digitsToSmash[10].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[10]);
            }
            if (tensDigit == 2){
                digitsToSmash[7].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[7]);
            }
            if (tensDigit == 1){
                digitsToSmash[4].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[4]);
            }
            if (tensDigit == 0){
                digitsToSmash[1].setPosition(sf::Vector2f(42, (16 *32)));
                window.draw(digitsToSmash[1]);
            }
            if (onesDigit == 9){
                digitsToSmash[29].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[29]);
            }
            if (onesDigit == 8){
                digitsToSmash[26].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[26]);
            }
            if (onesDigit == 7){
                digitsToSmash[23].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[23]);
            }
            if (onesDigit == 6){
                digitsToSmash[20].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[20]);
            }
            if (onesDigit == 5){
                digitsToSmash[17].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[17]);
            }
            if (onesDigit == 4){
                digitsToSmash[14].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[14]);
            }
            if (onesDigit == 3){
                digitsToSmash[11].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[11]);
            }
            if (onesDigit == 2){
                digitsToSmash[8].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[8]);
            }
            if (onesDigit == 1){
                digitsToSmash[5].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[5]);
            }
            if (onesDigit == 0){
                digitsToSmash[2].setPosition(sf::Vector2f(63, (16 *32)));
                window.draw(digitsToSmash[2]);
            }
        }

        //hard code losing
        if (!winning){
            //draw mines
            int mineCountDrawingLost = 0;
            for (unsigned int i = 0; i < 16; i++){
                for (unsigned int j = 0; j < 25; j++){
                    if (gameBoard[j][i].hasMine){
                        window.draw(mines[mineCountDrawingLost]);
                    }
                    mineCountDrawingLost++;
                }
            }
        }

        //hard code winning
        int winningCounter = 0;
        for (unsigned int i = 0; i < 16; i++){
            for (unsigned int j = 0; j < 25; j++){
                if (gameBoard[j][i].hasMine){
                    if (gameWon){
                        //make all tiles revealed
                        for (unsigned int t = 0; t < 16; t++){
                            for (unsigned int p = 0; p < 25; p++){
                                if (!gameBoard[p][t].isRevealed)
                                    gameBoard[p][t].isRevealed = true;
                            }
                        }
                        window.draw(flags[winningCounter]);
                    }
                }
                winningCounter++;
            }
        }
        //winning counter
        if (gameWon){
            window.draw(digitsToSmash[0]);
            window.draw(digitsToSmash[1]);
            window.draw(digitsToSmash[2]);
        }

        //draw smiley face
        face_happySprite.setPosition(sf::Vector2f(400.0f - (face_happySprite.getGlobalBounds().width / 2.0f),
                                                  hiddenTiles[0].getGlobalBounds().height * 16.0f));
        window.draw(face_happySprite);

        //draw lose face (if game lost)
        if (!winning){
            face_loseSprite.setPosition(sf::Vector2f(400.0f - (face_loseSprite.getGlobalBounds().width / 2.0f),
                                                     hiddenTiles[0].getGlobalBounds().height * 16.0f));
            window.draw(face_loseSprite);
        }

        //draw victory face (if game won)
        if (gameWon){
            face_winSprite.setPosition(sf::Vector2f(400.0f - (face_winSprite.getGlobalBounds().width / 2.0f),
                                                     hiddenTiles[0].getGlobalBounds().height * 16.0f));
            window.draw(face_winSprite);
        }

        //draw debug button
        debugSprite.setPosition(sf::Vector2f(400.0f - (debugSprite.getGlobalBounds().width / 2.0f) + (2 * debugSprite.getGlobalBounds().width),
                                             hiddenTiles[0].getGlobalBounds().height * 16.0f));
        window.draw(debugSprite);

        //draw test buttons
        test_1Sprite.setPosition(sf::Vector2f(400.0f - (test_1Sprite.getGlobalBounds().width / 2.0f) + (3 * test_1Sprite.getGlobalBounds().width),
                                              hiddenTiles[0].getGlobalBounds().height * 16.0f));
        window.draw(test_1Sprite);
        test_2Sprite.setPosition(sf::Vector2f(400.0f - (test_2Sprite.getGlobalBounds().width / 2.0f) + (4 * test_2Sprite.getGlobalBounds().width),
                                              hiddenTiles[0].getGlobalBounds().height * 16.0f));
        window.draw(test_2Sprite);
        test_3Sprite.setPosition(sf::Vector2f(400.0f - (test_3Sprite.getGlobalBounds().width / 2.0f) + (5 * test_3Sprite.getGlobalBounds().width),
                                              hiddenTiles[0].getGlobalBounds().height * 16.0f));
        window.draw(test_3Sprite);

        //only do once
        window.display();
    }
    return 0;
}