// Room: /d/shaolin/door.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "�����´���");
	set("long",@LONG
�����������µĴ��ſڣ�ǰ���Ǹߴ��ɽ�ţ�����������
�϶���һЩͭ����ǧ���ɲ����ש���ߡ���������һ��������ɽ
��������һ�������������顰�����¡��������֡���ǰ����֪
��ɮ��æµ�ŽӴ�����ɽ��������ǡ�������������ʯ��ͨ����
ɽ·����������ǰԺ�㳡��
LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"f_square",
  "southdown" : __DIR__"taijie1",
]));

	set("item_desc", ([
                "����":	HIC"      ���������ĺ���ɽΪ��һ\n      �Ĵ�����ʮ�������ǳ�Ԫ\n"NOR,
        ]) );

	set("NORIDE","����ɮ����ǰ��ס˵�������������˷����徲֮�أ�������������롣��\n");

        set("outdoors","shaolin");
        setup();
        replace_program(ROOM);
}
