// Room: /d/shaolin/cangjing2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ؾ������");
	set("long", @LONG
������ǲؾ����¥�ˣ����ڴ˵��ղص��Ƿ��ŵľ��估��
���书���ؼ������������������µĽ��ء����������µĳ��ҵ�
�Ӿ����ܽ���˵���ϰ�𷨼��书����ǽһ�ž޴�����(shujia)
�����˾���(jing shu)��
LONG
	);

 
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"cangjing1",
  "east" : __DIR__"cangjing3",
  "west" : __DIR__"readroom",
]));

	set("NORIDE", 1);
	set(SAFE_ENV,1);
	set("objects", ([
	__DIR__"npc/huichi" : 1,
]));

	setup();
	create_door("east", "ľ��", "west", DOOR_CLOSED,LOCKED,__DIR__"npc/obj/cangjing_key");
}

void init()
{
	add_action("do_get","get");
}

int do_get(string arg)
{
	string what,where;
	object shu;

	if(!arg || sscanf(arg,"%s from %s",what,where) != 2)
		return 0;

	if((what == "jing shu" || what == "js") && where != "shujia")
	{
		write("��Ҫ��ʲô�����þ��飿\n");
		return 1;
	}
	if( where == "shujia" && (what != "jing shu" && what != "js"))
	{
		write("��Ҫ���������ʲô��\n");
		return 1;
	}
	if( where != "shujia" || (what != "jing shu" && what != "js"))
		return 0;
	
	shu = new(__DIR__"npc/obj/jingshu");

	if(!shu->move(this_player()))
		shu->move(this_object());

	message_vision(sprintf("$N�����������һ��%s��\n",shu->name()),this_player());
	return 1;
}

int valid_leave(object me,string dir)
{
	object *obs;

	if(!me)
		return 0;

	if(dir == "down")
	{
		if(sizeof(filter_array(deep_inventory(me),(: $1->is_shaolin_book() :))))
			return notify_fail("�޳�������ס��˵��������ɷ��ͣ���ѧ�伮����Я���ؾ��󡣡�\n");
	}

	if( (dir == "east")
	&& ( me->query("class") != "shaolin"
	|| !me->query("family/can_study_yijin")) )
		return notify_fail("�޳�������ס��˵������δ�÷�����ɲ��ɽ�����ݣ���\n");

	if(dir == "west")
	{
		obs = filter_array(all_inventory(me),(: $1->is_character() :));
		if(sizeof(obs))
			return notify_fail("�޳�������ס��˵���������Ÿ������ȥ�о�����ʲô����\n");
	}
	return ::valid_leave(me,dir);
}
