// PokemonDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>
#include <string>

#include <creature.h>
#include <CreatureTypes.h>
#include <BattleMove.h>

void testCreature()
{

    Creature* testCreature = new Cloyster();

    testCreature->creatureInfo();

    BattleMove* testMove = new MoveBlizzard();

    testMove->Attack(testCreature);

    testCreature->creatureInfo();
}

void testTypes()
{
    CreatureTypes typeUtil;

    cout << endl;
    cout << "Normal vs Normal: " << typeUtil.checkEffective(NORMAL, NORMAL) << endl;
    cout << "Normal vs Rock: " << typeUtil.checkEffective(NORMAL, ROCK) << endl;
    cout << "Normal vs Ghost: " << typeUtil.checkEffective(NORMAL, GHOST) << endl;
    cout << "Normal vs Steel: " << typeUtil.checkEffective(NORMAL, STEEL) << endl;
    cout << "Water vs Fire: " << typeUtil.checkEffective(WATER, FIRE) << endl;
    cout << "Fighting vs Poison: " << typeUtil.checkEffective(FIGHTING, POISON) << endl;
    cout << "Fighting vs Flying: " << typeUtil.checkEffective(FIGHTING, FLYING) << endl;
    cout << "Fighting vs Dark: " << typeUtil.checkEffective(FIGHTING, DARK) << endl;
    cout << "Bug vs Fairy: " << typeUtil.checkEffective(BUG, FAIRY) << endl;
}

void testMoves()
{
    BattleMove* testMove = new MoveBlizzard();

    testMove->ListParts();
}

int main()
{
    testCreature();

    testTypes();

    testMoves();
}
