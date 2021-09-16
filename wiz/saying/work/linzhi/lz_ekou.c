//lz_ekou.c 林芝村东口跟成都西相连接的地方

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","村东山路");
        set("long", @LONG
走过横断山脉，地势忽然一降。你眼前出现了大片的原始森
林，远处有雅鲁藏布江奔流而下，南北各有一条山脉。雪峰，森
林与河谷，与之前单调的高原景色大不相同，你的心情也不禁变
得愉悦起来。路边有一个牌子。
LONG
        );
        set("item_desc",([
        "牌子":HIR"注意！前方森林无路可通，且有蛮夷猛兽伤人！\n"NOR,
]));

	set("exits", ([
        "east":"/d/chengdu_w/ccg37",
        "west":__DIR__"forest0"
]));
        if (random(6)>4)
        {
	set("objects",([
        __DIR__"npc/eagle":1,
]));
        }
        setup();
}
