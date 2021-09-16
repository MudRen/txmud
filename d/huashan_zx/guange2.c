// Room: guange.c by pian
#include <ansi.h>
inherit ROOM;
string look_sign(object me);
void create()
{
	set("short","枫林小驻");
	set("long",@LONG
走着走着，你眼见豁然开阔。一小片空地中间有一个小小的
草亭，草亭上有几个已经看不出颜色的字－－枫林小驻。下面好
像还有一行诗(shi)。琴声从亭子里传出来。
LONG
);
	set("item_desc",([
	//"sign": (: look_sign :),
	"shi":HIG"
		浓芳依翠萼    焕阑一亭中\n
		零露粘如醉    残霞照似融\n
		丹青难下笔    造化独留功\n
		舞蝶迷香径    翩翩逐晚风\n"NOR,
]));
	set("exits", ([
	"east" : __DIR__"guange3",
	"west":__DIR__"guange1",
	"enter":__DIR__"ting",
]));
	set("outdoors", "huashan_p");

	
	setup();
	replace_program(ROOM);
}