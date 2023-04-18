#include "knight2.h"

/* * * BEGIN implementation of class BaseBag * * */
// Class PaladinBag
bool PaladinBag::insertFirst(BaseItem * item)
{
    ListNode* newNode = new ListNode();
    newNode->nextNode = firstNode;
    newNode->item=item;
    firstNode = newNode;
    this->CountItems++;
    return true;
}
PaladinBag::PaladinBag(int phoenixdownI,int antidote)
{
        this->Limit=99999;
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
BaseItem * PaladinBag::get(ItemType type)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if (curNode->item->getItem()==type)
        {
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;
}
string PaladinBag::toString() const
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
}
BaseItem * PaladinBag::getItem(BaseKnight*knight)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if ((curNode->item->getItem()==PHOENIXDOWN)&&(curNode->item->canUse(knight)))
        {
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;
}

// End of class PaladinBag

// Class LancelotBag
bool LancelotBag::insertFirst(BaseItem * item)
{
    ListNode* newNode = new ListNode();
    newNode->nextNode = firstNode;
    newNode->item=item;
    firstNode = newNode;
    this->CountItems++;
    return true;
}
BaseItem * LancelotBag::get(ItemType type)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if (curNode->item->getItem()==type)
        {
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;   
}
string LancelotBag::toString() const
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
}
BaseItem * LancelotBag::getItem(BaseKnight*knight)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if ((curNode->item->getItem()==PHOENIXDOWN)&&(curNode->item->canUse(knight)))
        {
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;
}
// End of class LancelotBag

// Class DragonBag
bool DragonBag::insertFirst(BaseItem * item)
{
    ListNode* newNode = new ListNode();
    newNode->nextNode = firstNode;
    newNode->item=item;
    firstNode = newNode;
    this->CountItems++;
    return true;
}
BaseItem * DragonBag::get(ItemType type)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if (curNode->item->getItem()==type)
        {
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;
}
string DragonBag::toString() const
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
}
BaseItem * DragonBag::getItem(BaseKnight*knight)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if ((curNode->item->getItem()==PHOENIXDOWN)&&(curNode->item->canUse(knight)))
        {
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;
}
// End of class DragonBag

// Class NormalBag
bool NormalBag::insertFirst(BaseItem * item)
{
    ListNode* newNode = new ListNode();
    newNode->nextNode = firstNode;
    newNode->item=item;
    firstNode = newNode;
    this->CountItems++;
    return true;
}
BaseItem * NormalBag::get(ItemType type)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if (curNode->item->getItem()==type)
        {
            
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;
}
string NormalBag::toString() const
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
}
BaseItem * NormalBag::getItem(BaseKnight*knight)
{
    ListNode* curNode = firstNode;
    while (curNode != NULL) 
    {
        if ((curNode->item->getItem()==PHOENIXDOWN)&&(curNode->item->canUse(knight)))
        {
            BaseItem *item= curNode->item; 
            curNode->item=firstNode->item;
            firstNode=firstNode->nextNode;
            CountItems--;
            return item;
        }
        curNode = curNode->nextNode;
    }
    return NULL;
}
// End of class NormalBag

/* * * END implementation of class BaseBag * * */

/*** Begin implementation of class BaseOpponent ***/
// Class MadBear;
void MadBear::fight(BaseKnight * knight)
{
    if (knight->getKnightType()==0||(knight->getKnightType()==1))
    {
        this->lose(knight); 
        return;
    }
    if(knight->getLevel()>=levelO) this->lose(knight); 
    else this->win(knight);
} 
void MadBear::lose(BaseKnight *knight)
{
   knight->setGil(knight->getGil()+gil);
}
void MadBear::win(BaseKnight *knight)
{
    knight->setHP(knight->getHP()-baseDamage*(levelO-knight->getLevel()));
}
// End of class MadBear
void Bandit::fight(BaseKnight * knight)
{
    if (knight->getKnightType()==0||(knight->getKnightType()==1))
    {
        this->lose(knight); 
        return;
    }
    if(knight->getLevel()>=levelO) this->lose(knight); 
    else this->win(knight);
} 
void Bandit::lose(BaseKnight *knight)
{
   knight->setGil(knight->getGil()+gil);
}
void Bandit::win(BaseKnight *knight)
{
    int HP=knight->getHP()-baseDamage*(levelO-knight->getLevel());
    if (HP<=0)
    {
        BaseItem *item=knight->getBag()->get(PHOENIXDOWN);
        if (item!=NULL)
        {
            item->use(knight);
            knight->setGil(knight->getGil()+gil);
        }
        else
        {
            if(knight->getGil()>=100)
            {
                knight->setGil(knight->getGil()-100);
                knight->setHP(knight->getmaxHP()/2);
            }
            else 
            {
                knight->setHP(HP);
            }
        }
    }
    else knight->setHP(HP);
}
// End of class Bandit
void LordLupin::fight(BaseKnight * knight)
{
    if (knight->getKnightType()==0||(knight->getKnightType()==1))
    {
        this->lose(knight); 
        return;
    }
    if(knight->getLevel()>=levelO) this->lose(knight); 
    else this->win(knight);
} 
void LordLupin::lose(BaseKnight *knight)
{
   knight->setGil(knight->getGil()+gil);
}
void LordLupin::win(BaseKnight *knight)
{
    int HP=knight->getHP()-baseDamage*(levelO-knight->getLevel());
    if (HP<=0)
    {
        BaseItem *item=knight->getBag()->get(PHOENIXDOWN);
        if (item!=NULL)
        {
            item->use(knight);
            knight->setGil(knight->getGil()+gil);
        }
        else
        {
            if(knight->getGil()>=100)
            {
                knight->setGil(knight->getGil()-100);
                knight->setHP(knight->getmaxHP()/2);
            }
            else 
            {
                knight->setHP(HP);
            }
        }
    }
    else knight->setHP(HP);
}
// End of class LordLupin
void Elf::fight(BaseKnight * knight)
{
    if (knight->getKnightType()==0||(knight->getKnightType()==1))
    {
        this->lose(knight); 
        return;
    }
    if(knight->getLevel()>=levelO) this->lose(knight); 
    else this->win(knight);
} 
void Elf::lose(BaseKnight *knight)
{
   knight->setGil(knight->getGil()+gil);
}
void Elf::win(BaseKnight *knight)
{
    int HP=knight->getHP()-baseDamage*(levelO-knight->getLevel());
    if (HP<=0)
    {
        BaseItem *item=knight->getBag()->get(PHOENIXDOWN);
        if (item!=NULL)
        {
            item->use(knight);
            knight->setGil(knight->getGil()+gil);
        }
        else
        {
            if(knight->getGil()>=100)
            {
                knight->setGil(knight->getGil()-100);
                knight->setHP(knight->getmaxHP()/2);
            }
            else 
            {
                knight->setHP(HP);
            }
        }
    }
    else knight->setHP(HP);
}
// End of class Elf
void Troll::fight(BaseKnight * knight)
{
    if (knight->getKnightType()==0||(knight->getKnightType()==1))
    {
        this->lose(knight); 
        return;
    }
    if(knight->getLevel()>=levelO) this->lose(knight); 
    else this->win(knight);
} 
void Troll::lose(BaseKnight *knight)
{
   knight->setGil(knight->getGil()+gil);
}
void Troll::win(BaseKnight *knight)
{
    int HP=knight->getHP()-baseDamage*(levelO-knight->getLevel());
    if (HP<=0)
    {
        BaseItem *item=knight->getBag()->get(PHOENIXDOWN);
        if (item!=NULL)
        {
            item->use(knight);
            knight->setGil(knight->getGil()+gil);
        }
        else
        {
            if(knight->getGil()>=100)
            {
                knight->setGil(knight->getGil()-100);
                knight->setHP(knight->getmaxHP()/2);
            }
            else 
            {
                knight->setHP(HP);
            }
        }
    }
    else knight->setHP(HP);
}
// End of class Troll
void Tornbery::fight(BaseKnight * knight)
{
    if(knight->getLevel()>=levelO) this->lose(knight); 
    else this->win(knight);
} 
void Tornbery::lose(BaseKnight *knight)
{
   knight->setLevel(knight->getLevel()+1);
}
void Tornbery::win(BaseKnight *knight)
{
    if (knight->getKnightType()==2) return;
    BaseItem*item=knight->getBag()->get(ANTIDOTE);
    if (item==NULL)
    {
        knight->getBag()->Drop3items();
        knight->setHP(knight->getHP()-10);
    }
}
// End of class Tornbery
void QueenOfCards::fight(BaseKnight * knight)
{
    if(knight->getLevel()>=levelO) this->lose(knight); 
    else this->win(knight);
} 
void QueenOfCards::lose(BaseKnight *knight)
{
    knight->setGil(knight->getGil()*2);
}
void QueenOfCards::win(BaseKnight *knight)
{
    if (knight->getKnightType()==0) return;
    knight->setGil(knight->getGil()/2);
}
// End of class QueenOfCards
void NinadeRings::fight(BaseKnight * knight)
{
    if(knight->getGil()>=50||(knight->getKnightType()==0)) this->lose(knight); 
} 
void NinadeRings::lose(BaseKnight *knight)
{
    if (knight->getHP()<knight->getmaxHP()/3)
    {
        knight->setGil(knight->getGil()-50);
        knight->setHP(knight->getHP()+knight->getmaxHP()/5);
    }
}
// End of class NinadeRings
void DurianGarden::fight(BaseKnight * knight)
{
    knight->setHP(knight->getmaxHP());
} 
// End of class DurianGarden
void OmegaWeapon::fight(BaseKnight * knight)
{
    if((knight->getHP()==knight->getmaxHP()&&(knight->getLevel()==10))||(knight->getKnightType()==2)) this->lose(knight); 
    else this->win(knight);
} 
void OmegaWeapon::lose(BaseKnight *knight)
{
    knight->setLevel(10);
    knight->setGil(999);
}
void OmegaWeapon::win(BaseKnight *knight)
{
    knight->setHP(0);
}
// End of class OmegaWeapon
void Hades::fight(BaseKnight * knight)
{
    if((knight->getLevel()==10)||((knight->getKnightType()==0)&&(knight->getLevel()>=8))) this->lose(knight); 
    else this->win(knight);
} 
void Hades::lose(BaseKnight *knight)
{
   knight->army_paladinShied=true;
   knight->meetHades=true;
}
void Hades::win(BaseKnight *knight)
{
    knight->setHP(0);
}
// End of class Hades
void Ultimecia::fight(BaseKnight * knight)
{
    if (knight->army_excalibur) return this->lose(knight);
    if (knight->army_guinevererHair&&knight->army_lancelotSpear&&knight->army_paladinShied)
    {
        if(knight->getKnightType()==0||knight->getKnightType()==1||knight->getKnightType()==2)
        {
            if(knight->getKnightType()==0)
            {
                int dam=(int)0.06*knight->getHP()*knight->getLevel()/1;
                HP-=dam;
            }
            if(knight->getKnightType()==1)
            {
                int dam=(int)0.05*knight->getHP()*knight->getLevel()/1;
                HP-=dam;
            }
            if(knight->getKnightType()==2)
            {
                int dam=(int)0.075*knight->getHP()*knight->getLevel()/1;
                HP-=dam;
            }
            if (HP<=0) this->win(knight); else knight->lose=true;
        }
        else knight->lose=true;
    }
    else this->win(knight);
} 
void Ultimecia::lose(BaseKnight *knight)
{
    knight->army_loseUltimecia=0;
}
void Ultimecia::win(BaseKnight *knight)
{
    knight->lose=true;
    knight->army_loseUltimecia=true;
}
// End of class Ultimecia

/* * * BEGIN implementation of class BaseKnight * * */
bool isPytago(int);
bool isPrime(int);
KnightType checkingtype(int HP)
{
    if (isPrime(HP)) return PALADIN;
    if (HP==888) return LANCELOT;
    if (isPytago(HP)) return DRAGON;
    return NORMAL;
}
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
   KnightType type=checkingtype(maxhp);
   BaseKnight *knight=new BaseKnight(id,maxhp,level,gil,antidote,phoenixdownI,type);
   return knight;   
}
string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}
// /* * * END implementation of class BaseKnight * * */

// /* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights(const string & file_armyknights)
{
    PaladinShied=false;
    GuinevereHair=false;
    LancelotSpear=false;
    Excalibur=false;
    meetHades=false;
    int maxhp,level,gil,antidote,phoenixdownI;
    ifstream File(file_armyknights);
    File>>N;
    armyKnight=new BaseKnight*[N+1];    
    for(int i=1;i<=N;i++)
    {
        File>>maxhp>>level>>phoenixdownI>>gil>>antidote;
        armyKnight[i]=BaseKnight::create(i,maxhp,level,gil,antidote,phoenixdownI);
    }    
}
BaseKnight* ArmyKnights::lastKnight() const
{
    return armyKnight[N];
}
void CheckingBag(BaseKnight **arr,int N,BaseItem *items)
{
    while(N>=1)
    {
        if (arr[N]->getBag()->getNumberofItems()<arr[N]->getBag()->getLimit()) 
        {
            arr[N]->getBag()->insertFirst(items);
            return;
        }
        else N--;
    }
}
bool ArmyKnights::adventure (Events * events)
{
    int i=0;
    while(i<events->count())
    {  
        BaseOpponent *opponent=NULL;
        int IdEnemy=events->get(i);
        switch (IdEnemy)
        {
        case 1:
        {
            opponent=new MadBear(i,IdEnemy);
            break;
        }
        case 2:
        {
            opponent=new Bandit(i,IdEnemy);
            break;
        }
        case 3:
        {
            opponent=new LordLupin(i,IdEnemy);
            break;
        }
        case 4:
        {
            opponent=new Elf(i,IdEnemy);
            break;
        }
        case 5:
        {
            opponent=new Troll(i,IdEnemy);
            break;
        }
        case 6:
        {
            opponent=new Tornbery(i,IdEnemy);
            break;
        }
        case 7:
        {
            opponent=new QueenOfCards(i,IdEnemy);
            break;
        }
        case 8:
        {
            opponent=new NinadeRings(i,IdEnemy);
            break;
        }
        case 9:
        {
            opponent=new DurianGarden(i,IdEnemy);
            break;
        }
        case 10:
        {
            opponent=new OmegaWeapon(i,IdEnemy);
            break;
        }
        case 11:
        {
            opponent=new Hades;
            break;
        }
        case 95:
        {
            this->PaladinShied=true;
            break;
        }
        case 96:
        {
            this->LancelotSpear=true;
            break;
        }
        case 97:
        {
            this->GuinevereHair=true;
            break;
        }
        case 98:
        {
            this->Excalibur=true;
            break;
        }
        case 99:
        {
            opponent=new Ultimecia;
            break;
        }
        case 112:
        {
            BaseItem *item=new PhoenixdownII(PHOENIXDOWN);
            CheckingBag(armyKnight,N,item);
            break;
        }
        case 113:
        {
            BaseItem *item=new PhoenixdownIII(PHOENIXDOWN);
            CheckingBag(armyKnight,N,item);
            break;
        }
        case 114:
        {
            BaseItem *item=new PhoenixdownIV(PHOENIXDOWN);
            this->lastKnight()->getBag()->insertFirst(item);
            CheckingBag(armyKnight,N,item);
            break;
        }
        default:
            break;
        }
        if (N==0)
        {
            printResult(false);
            return false;
        }
        if (opponent!=NULL)
        {
            bool check=this->fight(opponent);
            if (check==true)   
            {
                if(this->lastKnight()->army_loseUltimecia==1) 
                {
                    N=0;
                    printResult(false);
                }
                if (IdEnemy==99)
                {
                    
                    while(this->lastKnight()->getKnightType()==3)
                    {
                        N--;
                        if (N==0) break;
                    }
                } else N--;
            }  
            else 
            {
                printInfo();
                i++;
                if (this->lastKnight()->army_loseUltimecia==0)
                {
                    printResult(true);
                }
            }
        }
        else 
        {  
            printInfo();
            i++;
        }
    }
    return false;
}
void passing(BaseKnight **arr,int N)
{
    int remainGil=arr[N]->getGil()-999;
    arr[N]->setGil(999);
    int k=N;
    while(remainGil>0&&k>=1)
    {
        k--;
        arr[k]->setGil(arr[k]->getGil()+remainGil);
        remainGil=arr[k]->getGil()-999;
        if(k==1&&arr[1]->getGil()>999) arr[1]->setGil(999);
    }
}
bool ArmyKnights::fight(BaseOpponent* opponent)
{
    this->lastKnight()->army_excalibur=this->Excalibur;
    this->lastKnight()->army_guinevererHair=this->GuinevereHair;
    this->lastKnight()->army_lancelotSpear=this->LancelotSpear;
    this->lastKnight()->army_paladinShied=this->PaladinShied;
    this->lastKnight()->meetHades=this->meetHades;
    opponent->fight(this->lastKnight());
    this->recoveryLastKnight(this->lastKnight());
    if (this->lastKnight()->getHP()<=0||this->lastKnight()->lose==true) return true; else
    {
        if(this->lastKnight()->getGil()>=999) passing(armyKnight,N);
        this->Excalibur=this->lastKnight()->army_excalibur;
        this->GuinevereHair=this->lastKnight()->army_guinevererHair;
        this->LancelotSpear=this->lastKnight()->army_lancelotSpear;
        this->PaladinShied=this->lastKnight()->army_paladinShied;
        this->meetHades=this->lastKnight()->meetHades;
        return false;
    }
}
void ArmyKnights::recoveryLastKnight(BaseKnight* knight)
{
        BaseItem *item=knight->getBag()->getItem(knight);
        if (item!=NULL)
        {
            item->use(knight);
        }
        else if((knight->getGil()>=100)&&(knight->getHP()<=0))
        {
                knight->setGil(knight->getGil()-100);
                knight->setHP(knight->getmaxHP()/2);
        }
}
void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
          cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}
bool ArmyKnights::hasPaladinShield() const
{
    return PaladinShied;
}
bool ArmyKnights::hasLancelotSpear() const
{
    return LancelotSpear;
}
bool ArmyKnights::hasGuinevereHair() const
{
    return GuinevereHair;
}
bool ArmyKnights::hasExcaliburSword() const
{
    return Excalibur;
}
void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::~KnightAdventure()
{
    delete armyKnights;
    delete events;
}
void KnightAdventure::loadArmyKnights(const string & file)
{
    armyKnights=new ArmyKnights(file);
}
void KnightAdventure::loadEvents(const string & file)
{
    events=new Events(file);
}
void KnightAdventure::run()
{
    bool z=armyKnights->adventure(events);
}
/* * * END implementation of class KnightAdventure * * */

/* * * BEGIN implementation of class Events * * */
Events::Events(const string &file_events)
{
    ifstream File(file_events);
    File>>N;
    int k;
    arr=new int[N+1];
    for(int i=0;i<N;i++)
    {
       File>>arr[i];
    }
}
int Events::count() const
{
    return N;
}
int Events::get(int i) const
{
    return arr[i];
}
/* * * END implementation of class Events * * */

/*** Begin implementation of class BaseItem***/ 
bool PhoenixdownI::canUse(BaseKnight *knight)
{
    int HP=knight->getHP();
    if (HP<=0)  return true; else return false;
}
void PhoenixdownI::use(BaseKnight *knight)
{
    knight->setHP(knight->getmaxHP());
}
string PhoenixdownI::getName()
{
    return "PhoenixI";
}


bool PhoenixdownII::canUse(BaseKnight *knight)
{
    int HP=knight->getHP();
    if (HP<(knight->getmaxHP())/4)  return true; else return false;
}
void PhoenixdownII::use(BaseKnight *knight)
{
    knight->setHP(knight->getmaxHP());
}
string PhoenixdownII::getName()
{
    return "PhoenixII";
}

bool PhoenixdownIII::canUse(BaseKnight *knight)
{
    int HP=knight->getHP();
    if (HP<(knight->getmaxHP())/3) return true; else return false;
}
void PhoenixdownIII::use(BaseKnight *knight)
{
    int HP=knight->getHP();
    if (HP<=0) knight->setHP((knight->getmaxHP())/3); else knight->setHP(HP+(knight->getmaxHP())/3);
}
string PhoenixdownIII::getName()
{
    return "PhoenixIII";
}

bool PhoenixdownIV::canUse(BaseKnight *knight)
{
    int HP=knight->getHP();
    if (HP<(knight->getmaxHP())/2) return true; else return false;
}
void PhoenixdownIV::use(BaseKnight *knight)
{
    int HP=knight->getHP();
    if (HP<=0) knight->setHP((knight->getmaxHP())/2); else knight->setHP(HP+(knight->getmaxHP())/5);
}
string PhoenixdownIV::getName()
{
    return "PhoenixIV";
}

// More function declare
bool isPytago(int HP)
{
    if (HP>=100&&HP<=999) 
    {
        int a=HP%10;
        HP=HP/10;
        int b=HP%10;
        HP=HP/10;
        int c=HP;
        if ((a*a==b*c+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b)) return true;
    }
    return false;
}
bool isPrime(int n)
{
    for(int i=2;i<n/2+1;i++)
    if (n%i==0) return false;
    return true;
}
