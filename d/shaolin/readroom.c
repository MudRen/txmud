// Room: /d/shaolin/readroom.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�о���");
	set("long", @LONG
����һ�������ʯ�ݣ�û��һ�ȴ���������������һ��ľ����
������һյС�͵Ʒ��Ż谵�Ĺ⡣
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
		tell_object(ob,HIC"���߽�������о��ң����ɵ��ľ��񶨣�����һƬ������\n"NOR);
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
