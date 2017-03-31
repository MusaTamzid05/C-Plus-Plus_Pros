#include "game.h"
#include <iostream>
#include <stdlib.h>
#include <string>


namespace GameEngine{

    Game::Game(const std::string& window_name , int width_ , int height_){

        initialize_font();
        initialize_states();

        m_window = new sf::RenderWindow(sf::VideoMode(width_ , height_), window_name);

    }

    Game::~Game(){
        delete m_window;
    }

    void Game::run(int minimum_framerate){

        sf::Clock clock;
        sf::Time time_since_last_update = sf::Time::Zero;
        sf::Time  time_per_frame = sf::seconds(1.0 / minimum_framerate);

        while(m_window->isOpen()){

            process_event();

            time_since_last_update += clock.restart();

            // if the time since the last update is better than the time per frame
            // then we need to do some extra updates

            if(time_since_last_update > time_per_frame){

                time_since_last_update -= time_per_frame;
                process_event();
                update(time_per_frame);
            }

            render();
        }
    }

    void Game::process_event(){

        sf::Event event;

        while(m_window->pollEvent(event)){

            if(event.type == sf::Event::Closed)
                m_window->close();
        }

    }

    void Game::update(sf::Time& delta_time){

    }

    void Game::render(){

        m_window->clear();
        show_framerate();
        m_window->display();
    }

    void Game::initialize_font(){

        if(!m_font.loadFromFile("font/default.ttf")){
            std::cerr << "Could not load the font.\n";
            exit(1);
        }

        initialize_text();

    }


    void Game::initialize_text(){
        
        m_text.setFont(m_font);
        m_text.setCharacterSize(24);
        m_text.setFillColor(sf::Color::Red);
        m_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    }

    void Game::initialize_states(){

        statistics_time = sf::Time::Zero;
        num_frames = 0;

    }

    void Game::update_states(sf::Time& elasped_time){

        statistics_time += elasped_time;
        num_frames += 1;
        calculate_framerate();


        
    }


    void Game::calculate_framerate(){

        if(statistics_time >= sf::seconds(1.0f)){


            m_text.setString("Frame / Second = " + std::to_string(num_frames) + "\n" +
                    "Time / Update = " + std::to_string(statistics_time.asMicroseconds() / num_frames) + " us");

        statistics_time -= sf::seconds(1.0f);
        num_frames = 0;

        }
    }

    void Game::show_framerate(){
        m_window->draw(m_text);
    }


};
