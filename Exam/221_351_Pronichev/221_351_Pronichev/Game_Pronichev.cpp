#include "Game_Pronichev.h"
#include <iostream>

unsigned int cube()
{
	return 1 + rand() % 6;
}

Game_Pronichev::Game_Pronichev()
{
	Player Pl;
	this->Year = 1;
	this->Phase = 0;
	for (int i = 0; i < 2; i++)
	{
		Pl.Name = i;
		Pl.Cube_F = Pl.Cube_S = Pl.Cube_T = Pl.Bounus_Cube = 0;
		Pl.Plus_Token = Pl.Win_point = Pl.Token_build = 0;
		Pl.Gold = Pl.Wood = Pl.Stone = 0;
		Pl.Army = 0;
		this->Igrok.push_back(Pl);
	}

}

Game_Pronichev::Game_Pronichev(const int num)
{
	Player Pl;
	this->Year = 1;
	this->Phase = 0;
	this->kolichestvo = num;
	for (int i = 0; i < kolichestvo; i++)
	{
		std::cin>>Pl.Name;
		Pl.Cube_F = Pl.Cube_S = Pl.Cube_T = Pl.Bounus_Cube = 0;
		Pl.Plus_Token = Pl.Win_point = Pl.Token_build = 0;
		Pl.Gold = Pl.Wood = Pl.Stone = 0;	
		Pl.Army = 0;
		this->Igrok.push_back(Pl);
	}
	this->Phase++;
}


Game_Pronichev::Game_Pronichev(const Game_Pronichev& Game)
{
	Player Pl;
	this->Year = Game.Year;
	this->Phase = Game.Phase;
	this->kolichestvo = Game.kolichestvo;
	for (int i = 0; i < kolichestvo; i++)
	{	
		this->Igrok.at(i)=Game.Igrok.at(i);
	}
}
Game_Pronichev::~Game_Pronichev()
{
	//nothing, because static
}

bool Game_Pronichev::comp(Player const& lhs, Player const& rhs) 
{ 
	return lhs.Win_point < rhs.Win_point; 
}


void Game_Pronichev::phase1()
{
	if (this->Year == 1 && this->Phase == 1) 
	{
		int chose = 0;
		for (int i = 0; i < kolichestvo; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				std::cin >> chose;
				if (chose == 1)
				{
					Igrok.at(i).Gold++;
				}
				else if (chose == 2)
				{
					Igrok.at(i).Wood++;
				}
				else if (chose == 3)
				{
					Igrok.at(i).Stone++;
				}
			}
		}
	}
	else 
	{
		std::vector<Player*> chosen;
		int max_build = 0;
		int max_resours = 0;

		for (Player Playr : this->Igrok) 
		{
			if (Playr.Build.size() == max_build)
			{
				if (Playr.Wood + Playr.Gold + Playr.Stone == max_resours)
				{
					chosen.push_back(&Playr);
				}
				else if (Playr.Wood + Playr.Gold +  Playr.Stone> max_resours) 
				{
					max_resours = Playr.Wood + Playr.Gold + Playr.Stone;
					
					chosen.empty();
					chosen.push_back(&Playr);
				}
			}
			else if (Playr.Build.size() > max_build) 
			{
				chosen.empty();
				chosen.push_back(&Playr);
				max_build = Playr.Build.size();
				max_resours = Playr.Wood + Playr.Gold + Playr.Stone;
			}
		}
		if (chosen.size() == 1) 
		{
			chosen.front()->Cube_F = cube();
			chosen.front()->Cube_S = cube();
			chosen.front()->Cube_T = cube();
		}
		else if (chosen.size() > 1) 
		{
			int chose = 0;
			for (int i = 0; i < kolichestvo; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					std::cin >> chose;
					if (chose == 1)
					{
						Igrok.at(i).Gold++;
					}
					else if (chose == 2)
					{
						Igrok.at(i).Wood++;
					}
					else if (chose == 3)
					{
						Igrok.at(i).Stone++;
					}
				}
			}
		}
	}
	this->Phase++;
}

void Game_Pronichev::phase2()
{
	this->Phase++;
}

void Game_Pronichev::phase3()
{
	std::vector<Player> candidates;
	int max_buildings = this->Igrok.at(0).Build.size();

	for (auto g : this->Igrok)
	{
		if (g.Build.size() > max_buildings)
		{
			max_buildings = g.Build.size();
			candidates.clear();
			candidates.push_back(g);
		}
		else if (g.Build.size() == max_buildings) candidates.push_back(g);
	}
	for (int i = 0; i < this->Igrok.size(); i++)
	{
		for (auto c : candidates)
		{
			if (this->Igrok.at(i).Name == c.Name)
			{
				this->Igrok.at(i).Win_point++;
			}
		}
	}
	this->Phase++;
}

int Game_Pronichev::throw_dice(Player& player) 
{
	return 0;
}
void Game_Pronichev::phase4()
{
	this->Phase++;
}

void Game_Pronichev::phase5()
{
	std::vector<Player> candidates;
	int min_buildings = this->Igrok.at(0).Build.size();
	for (auto g : this->Igrok)
	{
		if (g.Build.size() < min_buildings)
		{
			min_buildings = g.Build.size();
			candidates.clear();
			candidates.push_back(g);
		}
		else if (g.Build.size() == min_buildings)
		{
			candidates.push_back(g);
		}
	}
	if (candidates.size() == 1)
	{

	}
	else 
	{
		std::vector<Player> new_candidates;
		int count = 0;
		int sum_min = candidates[0].Gold + candidates[0].Wood + candidates[0].Stone;
		for (auto c : candidates)
		{
			int sum_p = c.Gold + c.Wood + c.Stone;
			if (sum_p < sum_min)
			{
				sum_min = c.Gold + c.Wood + c.Stone;
				new_candidates.clear();
				new_candidates.push_back(c);
			}
			else if (sum_min == sum_p) new_candidates.push_back(c);
		}
		if (count == 1)
		{
		
		}
	}

}

void Game_Pronichev::phase6()
{
	this->Phase++;
}

void Game_Pronichev::phase7()
{
	int* Max_First;
	int* Max_Second;
	for (auto player : this->Igrok) 
	{
		while (player.Gold + player.Wood + player.Stone > 2) 
		{
			if (player.Army == 9)
			{
				break;
			}

			player.Army++;
			
			if (player.Gold > player.Wood) 
			{
				player.Gold--;
				if (player.Wood > player.Stone) 
				{
					player.Wood--;
				}
				else 
				{
					player.Stone--;
				}
			}
			else 
			{
				player.Wood--;
				
				if (player.Gold > player.Stone) 
				{
					player.Gold;
				}
				else
				{
					player.Stone--;
				} 
			}
		}
	}
	this->Phase++;
}

void Game_Pronichev::phase8()
{

	int i = 1;
	char goblins[] = "zombi";
	char varvar[] = "ork";
	int help = throw_dice(Igrok.front());
	for (auto player : this->Igrok) {
		if (i % 2 == 1) 
		{
			defense_level(goblins, help, player);
		}
		else
		{
			defense_level(varvar, help, player);
		}
	}
}

void Game_Pronichev::defense_level(const char* enemy_name, int king_help, Player& player)
{

}

bool Game_Pronichev::load(const char* filename)
{
	int k = 0;
	std::ifstream file;
	std::string line;
	std::string buf = "";
	file.open(filename);
	while (std::getline(file, line))
	{
		k++;
	}
	file.close();

	file.open(filename);
	int b = 0;
	for (int i = 0; i < k; i++)
	{
		while (std::getline(file, line))
		{
			
			for (int i = 0; i < line.size(); i++)
			{

			}
		}
		for (auto i : Igrok)
		{
			std::cout << i.Name;
		}
		file.close();
		return 1;
	}
}
bool Game_Pronichev::save_game(const char* filename)
{
	std::ofstream f;
	int k=0;
	int* info = new int(kolichestvo);
	f.open(filename);
	for (int i = 0; i < kolichestvo; i++)
	{
		k = 0;
		f << i << "["
			<< Igrok.at(i).Name << "]["
			<< Igrok.at(i).Cube_F << "]["
			<< Igrok.at(i).Cube_S << "]["
			<< Igrok.at(i).Cube_T << "]["
			<< Igrok.at(i).Bounus_Cube << "]["
			<< Igrok.at(i).Gold << "]["
			<< Igrok.at(i).Wood << "]["
			<< Igrok.at(i).Stone << "]["
			<< Igrok.at(i).Win_point << "]["
			<< Igrok.at(i).Plus_Token << "]["
			<< Igrok.at(i).Token_build << "]["
			<< Igrok.at(i).Army << "]";
		for (int j = 0; j < Igrok.at(i).Build.size(); j++)
		{
			f <<"[" << Igrok.at(i).Build[j] << "]";
			k++;
			
		}
		f << "{" << k << "}";
		f << '\n';
	}
	f.close();
	return 1;
	
}


void Game_Pronichev::phase246()
{

}


void Game_Pronichev::phase246_bones()
{
	
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < Igrok.size(); i++)
		{
			if (advisers[Igrok.at(i).Cube_F].gamer_name == "0" && Igrok.at(i).Cube_F != 0)
			{
				advisers[Igrok.at(i).Cube_F].gamer_name == Igrok.at(i).Name;
				Igrok.at(i).Cube_F = 0;
			}
			else if (advisers[Igrok.at(i).Cube_S].gamer_name == "0" && Igrok.at(i).Cube_S != 0)
			{
				advisers[Igrok.at(i).Cube_S].gamer_name == Igrok.at(i).Name;
				Igrok.at(i).Cube_S = 0;
			}
			else if (advisers[Igrok.at(i).Cube_T].gamer_name == "0" && Igrok.at(i).Cube_T != 0)
			{
				advisers[Igrok.at(i).Cube_T].gamer_name == Igrok.at(i).Name;
				Igrok.at(i).Cube_T = 0;
			}
			else if (advisers[Igrok.at(i).Cube_S + Igrok.at(i).Cube_F].gamer_name == "0" && (Igrok.at(i).Cube_S + Igrok.at(i).Cube_F) != 0)
			{
				advisers[Igrok.at(i).Cube_F + Igrok.at(i).Cube_S].gamer_name == Igrok.at(i).Name;
				Igrok.at(i).Cube_F = 0;
				Igrok.at(i).Cube_S = 0;
			}
			else if (advisers[Igrok.at(i).Cube_T + Igrok.at(i).Cube_F].gamer_name == "0" && (Igrok.at(i).Cube_S + Igrok.at(i).Cube_F) != 0)
			{
				advisers[Igrok.at(i).Cube_T + Igrok.at(i).Cube_F].gamer_name == Igrok.at(i).Name;
				Igrok.at(i).Cube_F = 0;
				Igrok.at(i).Cube_T = 0;
			}
			else if (advisers[Igrok.at(i).Cube_S + Igrok.at(i).Cube_T].gamer_name == "0" && (Igrok.at(i).Cube_S + Igrok.at(i).Cube_F) != 0)
			{
				advisers[Igrok.at(i).Cube_S + Igrok.at(i).Cube_T].gamer_name == Igrok.at(i).Name;
				Igrok.at(i).Cube_S = 0;
				Igrok.at(i).Cube_T = 0;
			}
			else if (advisers[Igrok.at(i).Cube_S + Igrok.at(i).Cube_F + Igrok.at(i).Cube_T].gamer_name == "0" && (Igrok.at(i).Cube_S + Igrok.at(i).Cube_F + Igrok.at(i).Cube_T) != 0)
			{
				advisers[Igrok.at(i).Cube_F + Igrok.at(i).Cube_S + Igrok.at(i).Cube_T].gamer_name == Igrok.at(i).Name;
				Igrok.at(i).Cube_F = 0;
				Igrok.at(i).Cube_S = 0;
				Igrok.at(i).Cube_T = 0;
			}
		}
	}

	//advisor()_help;

	for (int i = 0; i < advisers.size(); i++)
	{
		std::cout << advisers[i].adviser_name << " " << advisers[i].gamer_name << std::endl;
	}
}

void Game_Pronichev::building(const char* advisor_name, Player& player)
{

}