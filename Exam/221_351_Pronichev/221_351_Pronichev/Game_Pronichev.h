#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>


class Game_Pronichev
{
private:
	enum Building 
	{
		Statue, Church, Cathedral, Inn, Market, Farm, TradeGuild,
		Barrack, Palisade, Stable, StoneWall, Fortress, Stockade, TownHall, Embassy
	};
	typedef struct Adviser 
	{
		std::string adviser_name;
		std::string gamer_name;
		Adviser(std::string a_name, std::string g_name)
		{
			adviser_name = a_name;
			gamer_name = g_name;
		}
	} Adviser;

	struct Player
	{
		std::string Name;

		unsigned int Cube_F, Cube_S, Cube_T, Bounus_Cube;
		unsigned int Gold, Wood, Stone;
		unsigned int Win_point, Plus_Token, Token_build;
		unsigned int Army;
		std::vector<Building> Build;
	};

	unsigned int Phase;
	unsigned int Year;
	int Enemy[5] = { 1,2,3,4,5};
	int kolichestvo;
	std::vector<Adviser> advisers;

	std::vector<Player> Igrok;

public:
	Game_Pronichev();
	Game_Pronichev(const int);
	Game_Pronichev(const Game_Pronichev&);
	~Game_Pronichev();
	bool comp(Player const& lhs, Player const& rhs);
	void phase1();
	void phase2();
	void phase3();
	void phase4();
	void phase5();
	void phase6();
	void phase7();
	void phase8();
	bool save_game(const char*);
	bool load(const char*);
	void phase246();
	void phase246_bones();
	void building(const char*, Player&);
	int throw_dice(Player&);
	void defense_level(const char* enemy_name, int king_help, Player& player);
};

