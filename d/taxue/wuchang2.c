// wuchang2.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����Ǹ�¶�����䳡���ſ�д��һ�����ӣ�paizi�����ö��������������
���ţ������ڳ��У�����û���˻�ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ�
���䳡�м���һ����ˣ�qigan�������Ϸǳ��Ĺ⻬���춥��һ����ӣ�����
д�š�̤ѩ���������������Ĵ��֡�
LONG
        );

	set("outdoors","taxue");

        set("exits", ([
               "west" : __DIR__"wuchang1",
               "south" : __DIR__"liangong2",
        ]));

        set("item_desc", ([
           "qigan"  :  "����һ�˷ǳ��⻬����ˣ�����������ӭ����չ��\n",
	   "paizi" :
		HIY"
������������������������������������
������������������������������������
����������                  ��������
��������     ��  ��  ��     ��������
����������                  ��������     
������������������������������������
������������������������������������\n\n"NOR,
	]));
		
        setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me = this_player();
	int level, keecost;

	if (arg != "qigan" && arg != "qi")
		return notify_fail("��Ҫ��ʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	level = me->query_skill("dodge", 1);
	keecost = level / 4 + random(level / 4);
        if (me->query("kee") <= keecost) {
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30) {
		write("�㱧ס��ˣ�ƴ�������������������˰���Ҳ�²���ȥ\n");
		return 1;
	}
	if (level > 100) {
		write("�㱧ס��ˣ�һ���̵�������ˣ������Աߵ����󲩲�֮����\n");
		return 1;
	}
	me->receive_damage("kee", keecost);
	write("�㱧����ˣ�ʹ���������������˺ô�ľ�������ˣ�������������\n");
	me->improve_skill("dodge", me->query("int"));
	return 1;
}
