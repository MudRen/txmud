// xixiangfang.c ���᷿
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","���᷿");
        set("long",@LONG
������̤ѩɽׯ�����᷿������������黹���飬ֻ��ǽ�Ϲ�����һ
������������̤ѩɽׯׯ���������������ʾ����������Ǹ�����˫ȫ��
�������ǽ����һ��������һ�ȴ���(window)���š�
LONG);

	set("exits",([
		"south" : __DIR__"xiting",
	]));
	
	set("item_desc",([
		"window" : "��̨����һ��С�ɵĽ�ӡ(sign)��\n",
		"sign" : "��ֻ�ɰ���С��ӡ������ȥ��һ������Ĳ������㲻ס��̤��ȥ��\n",
	]));

        set("objects", ([
                __DIR__"npc/master3" : 1,
        ]));

	setup();
	replace_program(ROOM);
}

int init()
{
	add_action("do_ta","ta");
//	add_action("do_jump","jump");
}

int do_ta(string arg)
	{
	object me;
	me = this_player();
	if ( !living(this_player()) || arg != "sign" )
	return 0;
	if ((int)me->query_skill("dodge", 1) > 31)
	return notify_fail("��̤�Ͽɰ���С��ӡ�������Ѿ��޷������Ļ����Ṧ�ˡ�\n");
        if ( (int)me->query("gin")<20) 
	{
		me->receive_damage("gin", 10 ,"tire");
		write("��̫���ˣ��Ѿ�̧������ˣ�\n");              
        return 1;
	}

        me->receive_damage("gin", random(20),"tire");
        message_vision("$N����̤�Ŵ�̨�ϵ�С��ӡ��\n", me);  
        write("��̤��С��ӡ��ʹ��Ļ����Ṧ�ֽ���һ����\n");
		me->improve_skill("dodge", me->query("int"));       
	return 1;
} 
