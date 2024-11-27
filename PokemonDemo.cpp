// PokemonDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;

#include <iostream>
#include <string>

#include <creature.h>
#include <CreatureTypes.h>
#include <BattleMove.h>

#include <StatModifiers.h>

#include <BattleManager.h>
#include <BattleInfo.h>

void testCreature()
{
    cout << endl;

    Creature* testCreature = new Cloyster();

    testCreature->creatureInfo();

    BattleMove* testMove = new MoveBlizzard();

    testMove->Attack(testCreature);

    testCreature->creatureInfo();

    Creature* testCreature2 = new Forretress();
    testCreature2->creatureInfo();

    delete testMove;
    testMove = new MoveEmber();

    testMove->Attack(testCreature2);

    testCreature2->creatureInfo();

}

void testTypes()
{
    cout << endl;
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
    cout << endl;
    BattleMove* testMove = new MoveBlizzard();

    testMove->ListParts();

    delete testMove;

    testMove = new MoveEmber();
    testMove->ListParts();
}

void testStatBuffs()
{
    cout << endl;
    StatModifiers stat;
    stat.increaseByOneLevel(ATTACK);

    stat.debugDisplayBuffs();
    stat.increaseByTwoLevels(ATTACK);
    stat.debugDisplayBuffs();
    stat.increaseByTwoLevels(ATTACK);
    stat.debugDisplayBuffs();
    stat.increaseByTwoLevels(ATTACK);
    stat.debugDisplayBuffs();
    stat.minimumBuff(ATTACK);
    stat.debugDisplayBuffs();
    stat.maximumBuff(ATTACK);
    stat.maximumBuff(DEFENSE);
    stat.decreaseByTwoLevels(SPATK);
    stat.maximumBuff(SPDEF);
    stat.debugDisplayBuffs();
}

void testBattle()
{

    cout << endl;
    BattleManager bMgr;

    Creature* poke1 = new Cloyster();
    BattleInfo* bInfo1 = new BattleInfo();
    Creature* poke2 = new Forretress();
    BattleInfo* bInfo2 = new BattleInfo();

    bInfo1->SetCurrentMove(new MoveBlizzard());
    bInfo2->SetCurrentMove(new MoveEmber());


    cout << "Testing BattleManager\n";

    bMgr.SetCreature1(poke1, bInfo1);
    bMgr.SetCreature2(poke2, bInfo2);

    bMgr.Turn();

}

int main()
{
    //testCreature();

    //testTypes();

    //testMoves();

    //testStatBuffs();

    testBattle();
}
