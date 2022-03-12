#include "PlayerAttack.hpp"

PlayerAttack::PlayerAttack()
	: Object(al_load_bitmap("img/PlayerAttackBox.bmp"), 0, 320),
	_nAtks(2),
	_selected()
{
	_attacks = { { {"a", 13}, {"b", 1}, { }, { } } }; // inicializa com dois ataques
}

PlayerAttack::~PlayerAttack()
{

}

void PlayerAttack::addAttack(const Attack& atk)
{
	_attacks[_nAtks - 1] = atk;
}

void PlayerAttack::draw()
{
	if (_nAtks = 1)
	{
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 14.f, this->_position.get_y() + 14.f, 0, _attacks[0].nome);
	}
	
	if (_nAtks = 2)
	{
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 14.f, this->_position.get_y() + 30.f, 0, _attacks[1].nome);
	}
	
	if (_nAtks = 3)
	{
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 70.f, this->_position.get_y() + 14.f, 0, _attacks[2].nome);
	}
	
	if (_nAtks = 4)
	{
		al_draw_text(
			Object::gblFont,
			al_map_rgb(255, 2555, 255),
			this->_position.get_x() + 70.f, this->_position.get_y() + 30.f, 0, _attacks[3].nome);
	}

	// Desenha seleção na posição correta
	switch (_selected)
	{
	case 0:
		/* code */
		break;
	case 1:
		/* code */
		break;
	case 2:
		/* code */
		break;
	case 3:
		/* code */
		break;
	}
}

void PlayerAttack::selectAttack(int n)
{
	this->_selected = n;
}

int PlayerAttack::do_attack(int n)
{
	Attack atk = _attacks[n - 1];
	return atk.dano; // Retorna o dano
}
