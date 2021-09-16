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
	set("short", BWHT HIR"�ϻ�¥"NOR);
	set("long", @LONG
����һ���������Ĵ�����������������˴��ĵ�������
������������������Ŵ���ĺ�ϲ�֡�����������һ�����ķ�
�裬���湩���š��Ϻ͡����ɡ�
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
	create_door("eastup", "��ľ��", "westdown", DOOR_CLOSED);
}

int valid_leave(object who,string dir)
{
	if( present("mei po") && member_array(who,hold) != -1)
		return notify_fail("ý��Ц��������ס��˵�������ɱ���ѽ���ٵȻ���ɡ�\n");
	return ::valid_leave(who,dir);
}
