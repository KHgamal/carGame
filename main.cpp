#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1800, 1000), "Car game" );
    window.setFramerateLimit(60);

    //variables

  //Main car movement
  bool rpressed=false;
  bool lpressed=false;
  bool upressed=false;
  bool dpressed=false;
  int x=850 , y =700;

  //car 1 position
  int moveShapeyAxis=rand() % 100 + 0;
  int xAxis=rand() % 55 + 555;

  //car 2 position
  int moveShapeyAxis2=rand() % 100 + 0;
  int xAxis2=rand() % 180 + 750;

  //car 3 position
  int moveShapeyAxis3=rand() % 100 + 0;
  int xAxis3=rand() % 40 + 1060;

  //coin position
  int moveShapeyAxis4=rand() % y + 0;
  int xAxis4=rand() % 545 + 555;

  int score=0;

  //game music
  sf::Music music;
  music.openFromFile("Data/racing.ogg");

  //score messages
    sf::Text info1;
    sf::Font font;
    font.loadFromFile("Data/arial.ttf");
    info1.setFont(font);
    info1.setFillColor(sf::Color::White);
    info1.setPosition(1500,100);
    info1.setCharacterSize(50);


    //background image
    sf::Texture img ;
    img.loadFromFile("Data/bg.jpg");
    sf::RectangleShape image;
    image.setTexture(&img);
    image.setSize(sf::Vector2f(1800,1000));

    //car 1 image
    sf::Texture car1 ;
    car1.loadFromFile("Data/car 1.png");
    sf::RectangleShape carShape1;
    carShape1.setSize(sf::Vector2f(100,200));
    carShape1.setTexture(&car1);

    //car 2 image
    sf::Texture car2 ;
    car2.loadFromFile("Data/car 2.png");
    sf::RectangleShape carShape2;
    carShape2.setSize(sf::Vector2f(100,200));
    carShape2.setTexture(&car2);

    //car 3 image
    sf::Texture car3 ;
    car3.loadFromFile("Data/car 3.png");
    sf::RectangleShape carShape3;
    carShape3.setSize(sf::Vector2f(100,200));
    carShape3.setTexture(&car3);

    //coin image
    sf::Texture c ;
    c.loadFromFile("Data/coin.png");
    sf::RectangleShape coin;
    coin.setSize(sf::Vector2f(80,80));
    coin.setTexture(&c);

    //coin image
    sf::Texture endGame;
    endGame.loadFromFile("Data/lose.png");
    sf::RectangleShape lose;
    lose.setSize(sf::Vector2f(1800,1000));
    lose.setTexture(&endGame);

    //car image
    sf::Texture car;
    car.loadFromFile("Data/car.png");
    sf::RectangleShape carShape;
    carShape.setSize(sf::Vector2f(100,200));
    carShape.setTexture(&car);

    music.play();
 bool playing=true;
    while (window.isOpen())
    {
     //for the game show screen

        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                window.close();
            }
            if(event.type==sf::Event::KeyPressed&&(event.key.code==sf::Keyboard::Left)){
                lpressed=true;
            }
            if(event.type==sf::Event::KeyPressed&&(event.key.code==sf::Keyboard::Right)){
                rpressed=true;
            }
            if(event.type==sf::Event::KeyPressed&&(event.key.code==sf::Keyboard::Up)){
                upressed=true;
            }
            if(event.type==sf::Event::KeyPressed&&(event.key.code==sf::Keyboard::Down)){
                dpressed=true;
            }
        }

        //car movement
        if(rpressed==true&&x<1100){
             x+=10;
             rpressed = false;
        }
        if(lpressed==true&&x>545){
             x-=10;
             lpressed = false;
        }
        if(dpressed==true&&y<700){
             y+=10;
             dpressed = false;
        }
        if(upressed==true&&y>100){
             y-=10;
             upressed = false;
        }
        carShape.setPosition(x,y);


        //car 1 logic
        if(moveShapeyAxis>=0&&moveShapeyAxis<1100){
                            moveShapeyAxis+=5;
                        }
                        if(moveShapeyAxis>=1100){
                            moveShapeyAxis=rand() % 100 + 0;
                            xAxis=rand() % 55 + 555;
                        }
        carShape1.setPosition(xAxis,moveShapeyAxis);

        //car 2 logic
        if(moveShapeyAxis2>=0&&moveShapeyAxis2<1100){
                            moveShapeyAxis2+=5;
                        }
                        if(moveShapeyAxis2>=1100){
                            moveShapeyAxis2=rand() % 100 + 0;
                            xAxis2=rand() % 180 + 750;
                        }
       carShape2.setPosition(xAxis2,moveShapeyAxis2);

        //car 3 logic
        if(moveShapeyAxis3>=0&&moveShapeyAxis3<1100){
                            moveShapeyAxis3+=5;
                        }
                        if(moveShapeyAxis3>=1100){
                            moveShapeyAxis3=rand() % 100 + 0;
                            xAxis3=rand() % 40 + 1060;
                        }
        carShape3.setPosition(xAxis3,moveShapeyAxis3);

        //coin logic
        if(moveShapeyAxis4>=0&&moveShapeyAxis4<2000){
                            moveShapeyAxis4+=10;
                        }
                        if(moveShapeyAxis4>=2000||xAxis4<0||moveShapeyAxis4<0){
                            moveShapeyAxis4=rand() % y + 0;
                            xAxis4=rand() % 545 + 555;
                        }
      coin.setPosition(xAxis4,moveShapeyAxis4);

        //collision with other cars
        if(carShape.getGlobalBounds().intersects(carShape1.getGlobalBounds())==true||
           carShape.getGlobalBounds().intersects(carShape2.getGlobalBounds())==true||
           carShape.getGlobalBounds().intersects(carShape3.getGlobalBounds())==true){
                playing=false;
         }

          if(carShape.getGlobalBounds().intersects(coin.getGlobalBounds())==true) {
                score+=10;
                xAxis4=-100;
                moveShapeyAxis4=-100;
          }

    //give the string and int values to text
        std::stringstream ss1;
        ss1<<"  Score  \n"<<score<<" points";
        info1.setString(ss1.str());

          window.clear();

         if(playing==true){
        window.draw(image);
        window.draw(carShape1);
        window.draw(carShape2);
        window.draw(carShape3);
        window.draw(coin);
        window.draw(carShape);
        window.draw(info1);
        }
        else if(playing==false){
           window.draw(lose);
           music.stop();
        }

        // Update the window
        window.display();
    }


    return 0;
}
