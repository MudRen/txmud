// grocery  杂货铺

#include <room.h>

inherit ROOM;
void create()
{
        set("short", "杂货铺");
        set("long", @LONG
这里是长安城的朱雀大街，是长安四条主街道之一，街道两
这是一家很普通的杂货铺，一进门就能感觉到它的古老，高
大的柜台，柜台后的货架上摆放各种货物，从农人用的锄头到妇
人用的针线，一应俱全，如果问问这里的老板，说不定他还有什
么隐密的货卖给你呢。从这里向西出门就是朱雀大街。
LONG
        );
       set("exits", ([
                "west"            : __DIR__"zqroad4", ]) );
        setup();
}

