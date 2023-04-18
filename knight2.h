#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
enum ItemType {PHOENIXDOWN=0,ANTIDOTE};
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
    };
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
    };
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
    };
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
    };
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
public:
    virtual bool insertFirst(BaseItem * item)=0;
    virtual BaseItem * get(ItemType itemType)=0;
    virtual string toString() const=0;
    virtual ListNode * iterator()=0;
    virtual void Drop3items()=0;
    virtual BaseItem * getItem(BaseKnight* knight)=0;
};
class PaladinBag:public BaseBag
{
    private:
    ListNode* firstNode;
    int CountItems;
    public:
    PaladinBag(int phoenixdownI,int antidote)
    {
        firstNode=NULL;
        CountItems=0;
        for(int i=1;i<=phoenixdownI;i++)
        {            
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new PhoenixdownI(PHOENIXDOWN);
            firstNode = newNode;
            this->CountItems++;
        }
        for(int i=1;i<=antidote;i++)
        {
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new Antidote(ANTIDOTE);
            firstNode = newNode;
            this->CountItems++;
        }
        cout<<firstNode;
    }
    bool insertFirst(BaseItem*);
    BaseItem * get(ItemType );
    string toString() const;
    ListNode * iterator()
    {
        return firstNode;
    }
    BaseItem * getItem(BaseKnight* knight);
    void Drop3items()
    {
        int i=1;
        while(i<=3)
        {
            firstNode=firstNode->nextNode;
            if (firstNode==NULL) break;
            i++;
        }
    }
};
class LancelotBag:public BaseBag
{
    private:
    ListNode* firstNode;
    int CountItems;
    public:
    LancelotBag(int phoenixdownI,int antidote)
    {
        firstNode=NULL;
        CountItems=0;
        for(int i=1;i<=phoenixdownI;i++)
        {            
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new PhoenixdownI(PHOENIXDOWN);
            firstNode = newNode;
            this->CountItems++;
        }
        for(int i=1;i<=antidote;i++)
        {
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new Antidote(ANTIDOTE);
            firstNode = newNode;
            this->CountItems++;
        }
    }
    bool insertFirst(BaseItem *);
    BaseItem * get(ItemType);
    string toString() const;
    BaseItem * getItem(BaseKnight* knight);
    ListNode * iterator()
    {
        return firstNode;
    }
    void Drop3items()
    {
        int i=1;
        while(i<=3)
        {
            firstNode=firstNode->nextNode;
            if (firstNode==NULL) break;
            i++;
        }
    }
};
class DragonBag:public BaseBag
{
    private:
    ListNode* firstNode;
    int CountItems;
    public:
    DragonBag(int phoenixdownI,int antidote)
    {
        CountItems=0;
        firstNode=NULL;
        for(int i=1;i<=phoenixdownI;i++)
        {            
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new PhoenixdownI(PHOENIXDOWN);
            firstNode = newNode;
            this->CountItems++;
        }
        for(int i=1;i<=antidote;i++)
        {
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new Antidote(ANTIDOTE);
            firstNode = newNode;
            this->CountItems++;
        }
    }
    bool insertFirst(BaseItem * );
    BaseItem * get(ItemType );
    string toString() const;
    BaseItem * getItem(BaseKnight* knight);
    ListNode * iterator()
    {
        return firstNode;
    }
    void Drop3items()
    {
        int i=1;
        while(i<=3)
        {
            firstNode=firstNode->nextNode;
            if (firstNode==NULL) break;
            i++;
        }
    }
};
class NormalBag:public BaseBag
{
    private:
    ListNode* firstNode;
    int CountItems;
    public:
    NormalBag(int phoenixdownI,int antidote)
    {
        CountItems=0;
        firstNode=NULL;
        for(int i=1;i<=phoenixdownI;i++)
        {            
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new PhoenixdownI(PHOENIXDOWN);
            firstNode = newNode;
            this->CountItems++;
        }
        for(int i=1;i<=antidote;i++)
        {
            ListNode* newNode = new ListNode();
            newNode->nextNode = firstNode;
            newNode->item=new Antidote(ANTIDOTE);
            firstNode = newNode;
            this->CountItems++;
        }
    }
    bool insertFirst(BaseItem * );
    BaseItem * get(ItemType );
    string toString() const;
    BaseItem * getItem(BaseKnight* knight);
    ListNode * iterator()
    {
        return firstNode;
    }
    void Drop3items()
    {
        int i=1;
        while(i<=3)
        {
            if (firstNode==NULL) break;
            firstNode=firstNode->nextNode;
            i++;
        }
    }
};
// End Define Base Bag

// Begin implementation of class BaseOpponent
class BaseOpponent
{
    public:
    virtual int getLevel()=0;
    virtual int getGil()=0;
    virtual int getBaseDamage()=0;
    virtual void fight(BaseKnight * knight)=0;
};
class MadBear:public BaseOpponent
{
    private:
    int levelO,baseDamage,gil;
    public:
    MadBear(int i,int IdEnemy)
    {
        baseDamage=10;
        gil=100;
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return gil;
    }
    int getBaseDamage()
    {
        return baseDamage;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class Bandit:public BaseOpponent
{
    private:
    int levelO,baseDamage,gil;
    public:
    Bandit(int i,int IdEnemy)
    {
        baseDamage=15;
        gil=150;
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return gil;
    }
    int getBaseDamage()
    {
        return baseDamage;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class LordLupin:public BaseOpponent
{
    private:
    int levelO,baseDamage,gil;
    public:
    LordLupin(int i,int IdEnemy)
    {
        baseDamage=45;
        gil=450;
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return gil;
    }
    int getBaseDamage()
    {
        return baseDamage;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class Elf:public BaseOpponent
{
    private:
    int levelO,baseDamage,gil;
    public:
    Elf(int i,int IdEnemy)
    {
        baseDamage=75;
        gil=750;
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return gil;
    }
    int getBaseDamage()
    {
        return baseDamage;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class Troll:public BaseOpponent
{
    private:
    int levelO,baseDamage,gil;
    public:
    Troll(int i,int IdEnemy)
    {
        baseDamage=95;
        gil=800;
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return gil;
    }
    int getBaseDamage()
    {
        return baseDamage;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class Tornbery:public BaseOpponent
{
    private:
    int levelO;
    public:
    Tornbery(int i,int IdEnemy)
    {
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return 0;
    }
    int getBaseDamage()
    {
        return 0;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class QueenOfCards:public BaseOpponent
{
    private:
    int levelO;
    public:
    QueenOfCards(int i,int IdEnemy)
    {
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return 0;
    }
    int getBaseDamage()
    {
        return 0;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class NinadeRings:public BaseOpponent
{
    private:
    int levelO;
    public:
    NinadeRings(int i,int IdEnemy)
    {
        levelO=0;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return 0;
    }
    int getBaseDamage()
    {
        return 0;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class DurianGarden:public BaseOpponent
{
    private:
    int levelO;
    public:
    DurianGarden(int i,int IdEnemy)
    {
        levelO=0;
    }
    int getLevel()
    {
        return 0;
    }
    int getGil()
    {
        return 0;
    }
    int getBaseDamage()
    {
        return 0;
    } 
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};
class OmegaWeapon:public BaseOpponent
{
    private:
    int levelO;
    public:
    OmegaWeapon(int i,int IdEnemy)
    {
        levelO=(i+IdEnemy)%10+1;
    }
    int getLevel()
    {
        return levelO;
    }
    int getGil()
    {
        return 0;
    }
    int getBaseDamage()
    {
        return 0;
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
    int getGil()
    {
        return 0;
    }
    int getBaseDamage()
    {
        return 0;
    }
    int getLevel()
    {
        return 0;
    }
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
    int getGil()
    {
        return 0;
    }
    int getBaseDamage()
    {
        return 0;
    }
    int getLevel()
    {
        return 0;
    }
    void fight(BaseKnight *);
    void lose(BaseKnight *);
    void win(BaseKnight *);
};

// End Define Base Opponent
class BaseKnight {
    protected:
    int id;
    int hp; 
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag * bag;
    KnightType knightType;
    public:
    bool lose;
    bool army_paladinShied;
    bool army_guinevererHair;
    bool army_excalibur;
    bool army_lancelotSpear;
    int army_loseUltimecia;
    bool meetHades;
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
        gil=Gil;
        if (Gil>999) gil=999;
    }
    void setHP(int HP)
    {
        hp=HP;
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
};
class ArmyKnights {
private:
BaseKnight ** armyKnight;
int N;
bool PaladinShied,Excalibur,LancelotSpear,GuinevereHair;
bool meetHades;
public:
    ArmyKnights (const string & file_armyknights);
    ~ArmyKnights()
    {
        delete armyKnight;
    }
    bool fight(BaseOpponent * opponent);
    bool adventure (Events * events);
    int count() const
    {
        return N;
    }
    BaseKnight * lastKnight() const;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo() const;
    void printResult(bool win) const;
    void recoveryLastKnight(BaseKnight *);
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
        delete arr;
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