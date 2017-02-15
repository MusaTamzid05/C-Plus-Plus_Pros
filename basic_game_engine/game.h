#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>

namespace GameEngine{


    class Game{

        public:

            Game(const std::string& window_name  , int width_ , int height_);
            virtual ~Game();


            void run(int minimum_framerate);

        private:

            sf::RenderWindow* m_window;
            sf::Font  m_font;
            sf::Text m_text;

            void update(sf::Time& delta_time);
            void render();
            void process_event();

            void show_framerate();

            
            void update_states(sf::Time& elasped_time);
            void calculate_framerate();

            void initialize_states();
            void initialize_font();
            void initialize_text();

            sf::Time statistics_time;
            int num_frames;



    };

};
#endif
