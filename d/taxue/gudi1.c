// gudi.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","山谷底");
        set("long",@LONG
这里是峭壁下面的谷底，这里阳光稀少。四周看上去高不可攀，怪石
嶙峋。借着微弱的光线，你看到对面石壁上有着几百幅各样图形，每个人
形状均不相同，举手踢足似在练武。图形尽处，石壁上出现了几行字(zi)
，也是以利器所刻制。靠石壁不远有一座土坟，坟前有一块墓碑(mubei)。
LONG);

	set("outdoors","taxue");

        set("tiehe_count",1);
        set("sword_count", 1);
       
        set("item_desc", ([
        "zi": HIB"残剑飞雪，且等有缘，福兮祸兮，瞬息之间。\n\n"NOR,
	"mubei" : HIR"
                        
                       ┌─┐
                       │一│
                       │代│
                       │武│
                       │学│
                       │宗│
                       │师│
                       │独│
                       │孤│
                       │求│
                     ※│败│※
                   ※  │之│  ※
                 ※    │墓│    ※
               ※      └─┘      ※
          ※※※※※※※※※※※※※※※※\n\n"NOR
        ]));

	set("exits",([
                "east" : __DIR__"gudi",
	]));

        set("objects", ([
                __DIR__"npc/master1" : 1,
        ]));

	setup();
}

void init()
{
        add_action("do_ketou", "ketou");
}

int do_ketou(string arg)
{
        object me = this_player();

        if (arg != "mubei")
                return notify_fail("你要拜什么？\n");
        
        message_vision("$N在坟前跪倒，恭恭敬敬地拜了四拜。\n", me);
//        me->set_temp("taxue/gudi_bai", 1);
        return 1;
}