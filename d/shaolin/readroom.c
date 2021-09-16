// Room: /d/shaolin/readroom.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "诵经室");
	set("long", @LONG
这是一间清冷的石屋，没有一扇窗户。屋子正中有一张木桌，
桌上有一盏小油灯发着昏暗的光。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"cangjing2",
]));

	setup();
}

void init()
{
	object ob = previous_object();
	if(ob && userp(ob) && (ob->query("class") == "shaolin"))
		call_out("up_int",1,ob);
}

void up_int(object ob)
{
	if(ob && (environment(ob) == this_object()) && !(ob->query_temp("readingroom_add")))
	{
		ob->set_temp("readingroom_add",1);
		ob->add_temp("apply/intelligence",6);
		tell_object(ob,HIC"你走进清冷的诵经室，不由得心静神定，胸中一片空明。\n"NOR);
	}
}

int valid_leave(object ob,string dir)
{
	if(objectp(ob) && ob->query_temp("readingroom_add"))
	{
		ob->add_temp("apply/intelligence",-6);
		ob->delete_temp("readingroom_add");
	}
	return ::valid_leave(ob,dir);
}
