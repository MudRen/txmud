//lz_ekou.c ��֥�嶫�ڸ��ɶ��������ӵĵط�

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","�嶫ɽ·");
        set("long", @LONG
�߹����ɽ�������ƺ�Ȼһ��������ǰ�����˴�Ƭ��ԭʼɭ
�֣�Զ������³�ز����������£��ϱ�����һ��ɽ����ѩ�壬ɭ
����ӹȣ���֮ǰ�����ĸ�ԭ��ɫ����ͬ���������Ҳ������
������������·����һ�����ӡ�
LONG
        );
        set("item_desc",([
        "����":HIR"ע�⣡ǰ��ɭ����·��ͨ�����������������ˣ�\n"NOR,
]));

	set("exits", ([
        "east":"/d/chengdu_w/ccg37",
        "west":__DIR__"forest0"
]));
        if (random(6)>4)
        {
	set("objects",([
        __DIR__"npc/eagle":1,
]));
        }
        setup();
}
