// Room: /d/changan/baoxiang.c
// by Find.

#include <ansi.h>
#include <room.h>

inherit ROOM;

private object *hold = ({});

void no_out(object ob)
{
	hold -= ({0});
	if(objectp(ob) && (member_array(ob,hold)==-1))
		hold += ({ob});
}

void can_out(object ob) { if(objectp(ob) && (member_array(ob,hold)!=-1)) hold -= ({ob}); }

void create()
{
	set("short", BWHT HIR"合欢楼"NOR);
	set("long", @LONG
这是一处宽敞明亮的大厅，大厅四面挂满了大红的灯笼，中
央的两根大柱子上贴着大幅的红喜字。正对面设着一个镶金的佛
龛，上面供奉着“合和”二仙。
LONG
	);

	set("NONPC",1);
	set(SAFE_ENV,1);

	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"shroad1",
	"eastup" : __DIR__"sxg",
]));

	set("objects",([
	NPC_DIR"meipo" : 1,
]));

	setup();
	create_door("eastup", "红木门", "westdown", DOOR_CLOSED);
}

int valid_leave(object who,string dir)
{
	if( present("mei po") && member_array(who,hold) != -1)
		return notify_fail("媒婆笑嘻嘻的拦住你说道：您可别走呀，再等会儿吧。\n");
	return ::valid_leave(who,dir);
}
