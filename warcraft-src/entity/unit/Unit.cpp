#include "Unit.hpp"
#include <QtMath>
#include <QDebug>

Unit::Unit(QPointF pos, Unit::Type type, float speed, float damage, int armor, int range, int attackSpeed) : Entity(pos) {
    this->speed = speed;
    this->damage = damage;
    this->range = range;
    this->armor = armor;
    this->attackSpeed = attackSpeed;
    this->type = type;

    scaleX = 2;
    scaleY = 2;

    attackAnims.reserve(8);
    movementAnims.reserve(8);
    deathAnims.reserve(1);

    currentAnimationSet = &movementAnims;
}

Unit::Unit() : Unit(QPointF(0, 0), Unit::NONE, 0.5f, 0, 0, 0, 0) { }

Unit::~Unit() {
    setCurrentAnimation(nullptr);

    qDeleteAll(movementAnims);
    qDeleteAll(deathAnims);
    qDeleteAll(attackAnims);
}

void Unit::updateAnimation(){
    float angle = QLineF(center(), targetPoint).angle();

    int index = 0;
    if(currentAnimationSet->size() == 8){
        if(angle >= 30 && angle <= 60){
            index = 1;
        } else if (angle > 60 && angle < 120){
            index = 2;
        } else if (angle >= 120 && angle <= 150){
            index = 3;
        } else if (angle > 150 && angle < 210){
            index = 4;
        } else if (angle >= 210 && angle <= 240){
            index = 5;
        } else if (angle > 240 && angle < 300){
            index = 6;
        } else if (angle >= 300 && angle <= 330){
            index = 7;
        }
    }

    Animation *anim = currentAnimationSet->at(index);
    Animation *currentAnim = getCurrentAnimation();
    if(anim != currentAnim){
        setCurrentAnimation(anim);
    }
    anim->start();
}

void Unit::update(){
    Entity::update();
    if(targetEntity) {
        if(targetEntity->isVisible() && targetEntity->isAlive()){
            if(isWithinRange(targetEntity)){
                if(currentAnimationSet != &attackAnims){
                    moving = false;
                    path.clear();
                    currentAnimationSet = &attackAnims;
                    setTarget(targetEntity->center());
                    if(attackCooldown-- <= 0){
                        targetEntity->damaged(damage, this);
                        attackCooldown = attackSpeed;
                    }
                } else {
                    currentAnimationSet = &movementAnims;
                }

            } else if (path.isEmpty()){
                setPath(graph->shortestPath(center(), targetEntity->center()));
                currentAnimationSet = &movementAnims;
            }
        } else {
            cancel();
            updateAnimation();
            stopMoving();
        }
    }

    if(moving){
        // Přibliž se k cíli
        QVector2D dir = direction();
        moveBy(speed * dir.x(), speed * dir.y());
    }

    if(distanceFrom(targetPoint) < 0.5f){
        moving = false;
        if(!path.isEmpty()) {

            Node **node = path.dequeue();
            if(*node) {
                setTarget((*node)->pos);
                move();
            } else {
                // Přepočítej cestu
                Node **goal = path.takeLast();
                if(goal && *goal){
                    setPath(graph->shortestPath(center(), (*goal)->pos));
                }
            }
        } else {
            stopMoving();
        }
    }
}

void Unit::setPath(const PATH &list){
    if(list.isEmpty() || (!path.isEmpty() && path.last() == list.last() && path.first() == list.first())) return;
    path = list;
    setTarget((*(path.dequeue()))->pos);
    move();
}

void Unit::goTo(QPointF goal) {
    if(!graph) return;
    setPath(graph->shortestPath(center(), goal));
}

void Unit::attack(Entity *victim) {
    if(victim == nullptr || targetEntity == victim || !victim->isAlive()) return;
    setPath(graph->shortestPath(center(), victim->center()));
    //path.removeLast();
    targetEntity = victim;
}

void Unit::die() {
    moving = false;
    if(!deathAnims.contains(getCurrentAnimation())){
        setCurrentAnimation(deathAnims.at(0));
        getCurrentAnimation()->start();
    }
    cancel();
    Entity::die();
}

void Unit::damaged(float amount, Entity *source) {
    Entity::damaged(amount, source);
    hp += amount;
    hp -= amount*(1-armor/10);
    if(!moving && !targetEntity) attack(source);
}

void Unit::stopMoving(){
    moving = false;
    getCurrentAnimation()->setCurrentFrameIndex(0);
    getCurrentAnimation()->stop();
    path.clear();
    //currentAnimationSet = &movementAnims;
}

void Unit::setTarget(QPointF target){
    targetPoint = target;
    updateAnimation();
}

QVector2D Unit::direction() const {
    return QVector2D(targetPoint - center()).normalized();
}

bool Unit::isWithinRange(Entity *entity) const {
    return distanceFrom(entity) <= (range + 1) * entity->boundingRect().width();
}

void Unit::cancel(){
    targetEntity = nullptr;
    currentAnimationSet = &movementAnims;
}

void Unit::move() {
    moving = true;
}


