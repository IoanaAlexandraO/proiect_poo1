#ifndef ABSTRACT_ENTITY_H
#define ABSTRACT_ENTITY_H

class AbstractEntity {
protected:
    AbstractEntity() {}
public:
    virtual ~AbstractEntity() {}
    virtual void speak() const = 0;
};

#endif
