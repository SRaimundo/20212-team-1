/* Player.cpp */

#include "Player.hpp"

#include <iostream>

Player::Player(std::string name, ALLEGRO_BITMAP *image,int x, int y, int tam_x, int tam_y):
    Character(name, image, x, y), _tam_x(tam_x), _tam_y(tam_y),_direcao_anterior(0), _numPasso(0) {};


Player::~Player(){}

bool Player::walk(int direcao, Map &mapa){
    bool andou = false;
    if(direcao == -1){
        al_draw_bitmap_region(this->_image, 0, 0, this->_tam_x, this->_tam_y,_position.get_x() * _tamPixels,_position.get_y() * _tamPixels, 0);
        _numPasso = 0;
        this->_direcao_anterior = 0;

    }
    else {
        if(direcao == 0 && mapa.get_val_walkable(this->_position.get_x(), this->_position.get_y() + 1) == '1') {
            this->_position.add_y();
            andou = true;
        } else if(direcao == 1 && mapa.get_val_walkable(this->_position.get_x(), this->_position.get_y() - 1) == '1') {
            this->_position.sub_y();
            andou = true;
        } else if(direcao == 2 && mapa.get_val_walkable(this->_position.get_x() - 1, this->_position.get_y() ) == '1') {
            this->_position.sub_x();
            andou = true;;
        } else if(direcao == 3 && mapa.get_val_walkable(this->_position.get_x() + 1, this->_position.get_y() ) == '1') {
            this->_position.add_x();
            andou = true;
        }
        
        if(this->_direcao_anterior == direcao){
            this->_numPasso++;
            if(this->_numPasso >= this->_numSprites )
                this->_numPasso = 0;

        }else{
            this->_numPasso = 0;
        }
        this->_direcao_anterior = direcao;

        al_draw_bitmap_region(this->_image, this->_numPasso * this->_tam_x, direcao * this->_tam_y,this->_tam_x, this->_tam_y,_position.get_x() * this->_tamPixels,_position.get_y() * this->_tamPixels, 0);
    }

    return andou;
}

// TODO: Correct interact()
void Player::interact(Npc *npc) {
	al_install_keyboard();	// TODO: Verify if it's not duplicate
	// TODO: Add excepction if keyboard wasn't installed
	
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();	// TODO: Verify if it's not duplicate
	al_register_event_source(event_queue, al_get_keyboard_event_source());	// TODO: Verify if it's not duplicate
	
	ALLEGRO_EVENT event;
	al_wait_for_event(event_queue, &event);
	
	// TODO: Include time to press the key
	if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (event.keyboard.keycode) {
			case ALLEGRO_KEY_I:
				if (npc->can_interact(this->_position)) {
					npc->show_interaction();
					std::cout << "Successful interaction.\n";	// TODO: Add exception
				}
				else {
					std::cerr << "Error in interaction.\n";	// TODO: Add exception
					return ;
				}
				break;
			default:
				std::cerr << "Interaction wasn't called.\n";	// TODO: Add exception
				break;
		}
	}
}

Position Player::get_CAPIMON_DRAW_POSITION() const {
    return this->CAPIMON_DRAW_POSITION;
}

Position Player::get_CAPIMON_STATUS_POSITION() const {
    return this->CAPIMON_STATUS_POSITION;
}
