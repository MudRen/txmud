#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����������ң�ǽ�ϵ��͵Ʒ����谵�Ļƹ⡣����
�����з���һ��ʯ�Ƶ����Σ�ʯ��������һ������Ů����¶
����֮ɫ��������һ��С��(door)���ص�����ʵʵ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yu102",
]));
        set("item_desc",([
        "door" : "һ�ȹص�����ʵʵ��С�ţ����������ȥ��(knock)һ�¡�\n",
        "С��" : "һ�ȹص�����ʵʵ��С�ţ����������ȥ��(knock)һ�¡�\n",
]));
        set("objects", ([
        __DIR__"npc/master" : 1,
        __DIR__"npc/shibi2" : 1,
        __DIR__"npc/shibi1" : 1,
]) );


	setup();
	create_door("south", "ľ��", "north", DOOR_CLOSED);
}

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{
	object me = this_player();

	if(arg != "С��" && arg != "door")
		return notify_fail("��Ҫ��ʲô��\n");

	if(!me->query_temp("louth_qupai"))
		return notify_fail("û�о�������ܲ�������㲻���������˼ҡ�\n");

	if((int)me->query_temp("louth_buxing") >= 1)
		return notify_fail("�����Ǹ����Ѿ���������ˣ��㻹���߰ɡ�\n");

	message_vision(HIM"$N��������˼���ľ�š�����\n\n"NOR,me);
	call_out("greeting",8,me);
	return 1;
}

void greeting(object me)
{
	if(!objectp(me) || (environment(me) != this_object()))
		return;

	if(random(25) < me->query("kar"))
	{
		tell_object(me,"��ʱľ�ſ��ˣ�������˵Ŀ���ȥ��������ˡ�\n");
		set("exits/east",__DIR__"zhangroom");
	}
	else
		tell_object(me,"��ʱ�������и��˵������߰ɣ���������Щ�������\n");
		me->set_temp("louth_buxing",1);
}
