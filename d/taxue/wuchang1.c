// wuchang1.c
// by dicky

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���䳡");
        set("long", @LONG
�����Ǹ�¶�����䳡���ſ�д��һ�����ӣ�paizi�����ö��������������
���ţ������ڳ��У�����û���˻�ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ�
���䳡������һ��������(tree)���Ե�ʮ�ֵĴ�׳�����ϵ���Ҷ�ǳ�ï�ܣ�
�м�ֻ��֪����С�������д�����ȥ��
LONG
        );

	set("outdoors","taxue");

        set("exits", ([              
               "east" : __DIR__"wuchang2",
               "north" : __DIR__"shilu5",
               "south" : __DIR__"liangong",
        ]));

        set("item_desc", ([
          "tree" : "һ�ô�������֦Ҷï�ܣ�����������������\n",
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
	add_action("do_shake", "yao");
	add_action("do_shake", "huang");
}

int do_shake(string arg)
{
	object me = this_player();
	int level, keecost;

	if (arg != "tree" && arg != "shu" && arg != "dashu")
		return notify_fail("��Ҫҡʲô��\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");

	level = me->query_skill("parry", 1);
	keecost = level / 4 + random(level / 4);
        if (me->query("kee") <= keecost) {
		write("��̫���ˣ���ЪЪ�ɣ�\n");
		return 1;
	}
	if (level < 30) {
		write("��ʹ����ҡ���Ŵ���������ȴ��˿�������㲻���뵽�Ǿ䡰��ݺ������ĳ�������\n");
		return 1;
	}
	if (level > 100) {
		write("��ʹ����ҡ���Ŵ����������ϵ�Ҷ�Ӷ�ҡ���䵽���ɿ���ȥ�ˡ�\n");
		return 1;
	}
	me->receive_damage("kee", keecost);
	if (!random(5))
		message_vision("$Nʹ����ҡ�Ŵ����������ϵ��¼���������������$N��ͷ����$N��æ��ۼܿ���\n", me);
	else
		write("��ʹ����ҡ�Ŵ����������ϵ��¼������������������ͷ�������æ��ۼܿ���\n");
	me->improve_skill("parry", me->query("int"));
	return 1;
}
