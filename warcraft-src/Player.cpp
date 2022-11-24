#include "Player.hpp"
#include <QDebug>
#include <QGraphicsScene>

#define MAX_SELECTED_UNITS 8
#define MAX_FOOD           100
#define MAX_GOLD           100000
#define MAX_LUMBER         20000

Player::Player(Race race) {
    this->race = race;
    selectedUnits.reserve(MAX_SELECTED_UNITS);
}

void Player::selectUnit(Unit *unit){
    if(units.contains(unit)){
        deselect();
        selectedUnits.append(unit);
        unit->setHighlighted(true);
    }
}

void Player::selectUnits(QList<Unit *> &selected){
    if(selected.empty()) return;

    if(selected.size() > MAX_SELECTED_UNITS){
        selected = selected.mid(0, MAX_SELECTED_UNITS);
    }

    deselect();
    for(Unit *u : selected){
        if(units.contains(u)){
            selectedUnits.append(u);
            u->setHighlighted(true);
        }
    }
}

void Player::selectBuilding(Building *building){
    if(buildings.contains(building)){
        deselect();
        selectedBuilding = building;
        selectedBuilding->setHighlighted(true);
    }
}

void Player::deselect() {
    for(Unit * u : selectedUnits){
        u->setHighlighted(false);
    }
    selectedUnits.clear();

    if(selectedBuilding){
        selectedBuilding->setHighlighted(false);
        selectedBuilding = nullptr;
    }
}

QLinkedList<Building *> Player::buildingsOfType(Building::Type type) const {
    QLinkedList<Building *> list;
    for(Building *b : buildings) {
        if(b->getType() == type) {
            list.append(b);
        }
    }
    return list;
}

QLinkedList<Unit *> Player::unitsOfType(Unit::Type type) const {
    QLinkedList<Unit *> list;
    for(Unit *u : units) {
        if(u->getType() == type) {
            list.append(u);
        }
    }
    return list;
}

QLinkedList<Entity *> Player::allEntities() const {
    QLinkedList<Entity *> list;
    for(Unit *u : units) {
        list.append(u);
    }
    for(Building *b : buildings) {
        list.append(b);
    }
    return list;
}
