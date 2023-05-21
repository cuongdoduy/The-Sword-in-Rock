#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
enum ItemType {PHOENIXDOWN=0,ANTIDOTE=1};
enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
class BaseKnight;
// Begin implement of class BaseItem
class BaseItem {
protected:
ItemType item;
public:
    virtual bool canUse ( BaseKnight * knight ) = 0;
    virtual void use ( BaseKnight * knight ) = 0;
    virtual string getName()=0;
    virtual ItemType getItem()
    {
        return item;
    }
};
class PhoenixdownI:public BaseItem
{
    public:
    PhoenixdownI(ItemType item)
    {
        this->item=item;
    }
    bool canUse(BaseKnight *knight);
    void use ( BaseKnight * knight );
    string getName();
};
class PhoenixdownII:public BaseItem
{
    public:
    PhoenixdownII(ItemType item)
    {
        this->item=item;
    }
    bool canUse(BaseKnight *knight);
    void use ( BaseKnight * knight );
    string getName();
};
class PhoenixdownIII:public BaseItem
{
    public:
    PhoenixdownIII(ItemType item)
    {
        this->item=item;
    }
    bool canUse(BaseKnight *knight);
    void use ( BaseKnight * knight );
    string getName();
};
class PhoenixdownIV:public BaseItem
{
    public:
    PhoenixdownIV(ItemType item)
    {
        this->item=item;
    }
    bool canUse(BaseKnight *knight);
    void use ( BaseKnight * knight );
    string getName();
};
class Antidote:public BaseItem
{
    public:
    Antidote(ItemType item)
    {
        this->item=item;
    }
    bool canUse(BaseKnight *knight)
    {
        return true;
    }
    void use ( BaseKnight * knight )
    {
        return ;
    }
    string getName()
    {
        return "Antidote";
    }
};
// End implement of class BaseItem

struct ListNode {
    BaseItem *item;     // dữ liệu được lưu ở nút của linked list
    ListNode* nextNode; // the pointer points to next node of linked list
};
// Define struc Node;
class Events;
// Begin Define BaseBag;
class BaseBag {
protected:
    ListNode* firstNode;
    int Limit,CountItems;
public:
    void InitialBaseBag(int phoenixdownI,int antidote)
    {
        firstNode=NULL;
        CountItems=0;
        for(int i=1;i<=phoenixdownI;i++)
        {            
            ListNode* newNode=new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new PhoenixdownI(PHOENIXDOWN);
            firstNode = newNode;
            this->CountItems++;
        }
        for(int i=1;i<=antidote;i++)
        {
            ListNode* newNode=new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new Antidote(ANTIDOTE);
            firstNode = newNode;
            this->CountItems++;
        }
    };
    virtual bool insertFirst(BaseItem * item)
    {
        ListNode* newNode = new ListNode();
        newNode->nextNode = firstNode;
        newNode->item=item;
        firstNode = newNode;
        this->CountItems++;
        return true;
    };
    virtual string toString() const
    {
        string s="Bag[count="+to_string(CountItems)+";";
        ListNode* curNode = firstNode;
        while (curNode != NULL) 
        {
        s=s+ curNode->item->getName();
        curNode = curNode->nextNode;
        if (curNode!=NULL) s+=",";
        }
        s+="]";
        return s;
    };
    virtual ListNode * iterator()
    {
        return firstNode;
    }
    virtual void Drop3items()
    {
        int i=1;
        while(i<=3)
        {
            if(firstNode==NULL) break;
            ListNode* temp = firstNode;
            firstNode = firstNode->nextNode;
            delete temp->item;
            delete temp;
            this->CountItems--;
            i++;
        }
    };
    virtual BaseItem * getItem(BaseKnight* knight)
    { 
        ListNode* curNode = firstNode;
        while (curNode != NULL) 
        {
            if ((curNode->item->getItem()==PHOENIXDOWN)&&(curNode->item->canUse(knight)))
            {
                BaseItem *item= curNode->item; 
                curNode->item=firstNode->item;
                ListNode* temp = firstNode;
                firstNode=firstNode->nextNode;
                delete temp;
                CountItems--;
                return item;
            }
            curNode = curNode->nextNode;
        }
        return NULL;
    };
    virtual int getNumberofItems()
    {
        return CountItems;
    };
    virtual int getLimit()
    {
        return Limit;
    };
    BaseItem * get(ItemType type)
    {
        ListNode* curNode = firstNode;
        while (curNode != NULL) 
        {
            if (curNode->item->getItem()==type)
            {
                BaseItem *item= curNode->item; 
                curNode->item=firstNode->item;
                ListNode* temp = firstNode;
                firstNode=firstNode->nextNode;
                delete temp;
                CountItems--;
                return item;
            }
            curNode = curNode->nextNode;
        }
        return NULL;
    }
    ~BaseBag()
    {
        ListNode* curNode = firstNode;
        while (curNode != NULL) 
        {
            ListNode* temp = curNode;
            curNode = curNode->nextNode;
            delete temp->item;
            delete temp;
        }
    }
};
class PaladinBag:public BaseBag
{
    public:
    PaladinBag(int phoenixdownI,int antidote);
};
class LancelotBag:public BaseBag
{
    public:
    LancelotBag(int phoenixdownI,int antidote);
};
class DragonBag:public BaseBag
{
    public:
    DragonBag(int phoenixdownI,int antidote);
};
class NormalBag:public BaseBag
{
    public:
    NormalBag(int phoenixdownI,int antidote);
};
// End Define Base Bag

// Begin implementation of class BaseOpponent
class BaseOpponent
{
    protected:
    int levelO,baseDamage,gil;
    public:
    virtual int getLevel()
    {
        return levelO;
    }
    virtual int getGil()
    {
        return gil;
    }
    virtual int getBaseDamage()
    {
        return baseDamage;
    }
    virtual void lose(BaseKnight *);
    virtual void win(BaseKnight *);
    virtual void fight(BaseKnight * knight);
};
class MadBear:public BaseOpponent
{
    
    public:
    MadBear(int i,int IdEnemy)
    {
        baseDamage=10;
        gil=100;
        levelO=(i+IdEnemy)%10+1;
    }
};
class Bandit:public BaseOpponent
{
    public:
    Bandit(int i,int IdEnemy)
    {
        baseDamage=15;
        gil=150;
        levelO=(i+IdEnemy)%10+1;
    }
};
class LordLupin:public BaseOpponent
{
    public:
    LordLupin(int i,int IdEnemy)
    {
        baseDamage=45;
        gil=450;
        levelO=(i+IdEnemy)%10+1;
    }
};
class Elf:public BaseOpponent
{
    public:
    Elf(int i,int IdEnemy)
    {
        baseDamage=75;
        gil=750;
        levelO=(i+IdEnemy)%10+1;
    }
};
class Troll:public BaseOpponent
{
    public:
    Troll(int i,int IdEnemy)
    {
        baseDamage=95;
        gil=800;
        levelO=(i+IdEnemy)%10+1;
    }
};
class Tornbery:public BaseOpponent
{
    public:
    Tornbery(int i,int IdEnemy)
    {
        baseDamage=0;
        gil=0;
        levelO=(i+IdEnemy)%10+1;
    }
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class QueenOfCards:public BaseOpponent
{
    public:
    QueenOfCards(int i,int IdEnemy)
    {
        levelO=(i+IdEnemy)%10+1;
    }
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class NinadeRings:public BaseOpponent
{

    public:
    NinadeRings(int i,int IdEnemy)
    {
        levelO=0;
    }
    void fight(BaseKnight *);
    void lose(BaseKnight *);
};
class DurianGarden:public BaseOpponent
{
    public:
    DurianGarden(int i,int IdEnemy)
    {
        levelO=0;
    }
    void fight(BaseKnight *);
};
class OmegaWeapon:public BaseOpponent
{
    public:
    OmegaWeapon(int i,int IdEnemy)
    {
        levelO=(i+IdEnemy)%10+1;
    }
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class Hades:public BaseOpponent
{
    private:
    public:
    Hades()
    {}
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class Ultimecia:public BaseOpponent
{
    private:
    bool EnemyPaladinShied,GuinevereHair,LancelotSpear,Excalibur;
    int HP;
    public:
    Ultimecia()
    {
        HP=5000;
    };
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};

// End Define Base Opponent
class BaseKnight {
    protected:
    int id,hp,maxhp,level,gil,antidote;
    BaseBag * bag;
    KnightType knightType;
    public:
    bool lose,army_paladinShied,army_guinevererHair,army_excalibur,army_lancelotSpear,meetHades,meetOmegaWeapon;
    int army_loseUltimecia;
    BaseKnight()
    {
    }
    BaseKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI,KnightType type)
    {
        this->id=id;
        this->hp=maxhp;
        this->maxhp=maxhp;
        this->level=level;
        this->army_loseUltimecia=2;
        this->lose=false;
        this->gil=gil;
        this->antidote=antidote;
        this->knightType=type;  
        switch (type)
        {
            case 0:
            {
                this->bag=new PaladinBag(phoenixdownI,antidote);
                break;
            }
            case 1:
            {
                this->bag=new LancelotBag(phoenixdownI,antidote);
                break;
            }
            case 2:
            {
                this->bag=new DragonBag(phoenixdownI,antidote);
                break;
            }
            case 3:
            {
                this->bag=new NormalBag(phoenixdownI,antidote);
                break;
            }
        default:
            break;
        }
    }
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    int getId() const
    {
        return id;
    }
    int getGil() const
    {
        return gil;
    }
    int getLevel() const
    {
        return level;
    }
    int getHP() const
    {
        return hp;
    }
    int getmaxHP() const
    {
        return maxhp;
    }
    void setGil(int Gil)
    {
        this->gil=Gil;
    }
    void setHP(int HP)
    {
        this->hp=HP;
        if (HP>=999) hp=999;
    }
    void setLevel(int level)
    {
        this->level=level;
        if (level>=10) this->level=10;
    }
    KnightType getKnightType()
    {
        return this->knightType;
    }
    BaseBag* getBag()
    {
        return bag;
    } 
    ~BaseKnight()
    {
        delete bag;
    }
};
class ArmyKnights {
private:
BaseKnight ** armyKnight;
int N;
bool PaladinShied,Excalibur,LancelotSpear,GuinevereHair;
bool meetHades,meetOmegaWeapon;
bool sortArmy;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights()
    {
        delete[] armyKnight;
    }
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const
    {
        return N;
    }
    void setN(int N)
    {
        this->N=N;
    }
    BaseKnight * lastKnight() const;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo() const;
    void printResult(bool win) const;
    void recoveryLastKnight(BaseKnight *);
    void sortArmyKnight();
    BaseKnight** getarmyKnight()
    {
        return armyKnight;
    }
};
class Events {
private:
int N;
int * arr;
public:
    Events ( const string &);
    ~Events()
    {
        delete[] arr;
    }
    int count() const;
    int get(int i) const;
    int * getArr()
    {
        return arr;
    }
};
class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;
public:
    ~KnightAdventure();  // TODO:
    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__