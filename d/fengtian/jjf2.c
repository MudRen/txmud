// Room: /d/fengtian/jjf2.c

inherit ROOM;

void create()
{
	set("short", "ͥԺ");
	set("long", @LONG
���뽫������һ�����ķ����Ĵ�ͥԺ��ͥԺ�����кܶ��ֱ
�İ�������һ����ʯ�·��ɨ�ĸɸɾ�����������ֱͨ��������
��������ͥԺ�ﻹ���˺ܶ໨���Եú���������
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"jjf1",
  "east" : __DIR__"jjf3",
]));
        set("outdoors", "fengtian");
	set("cannot_build_home",1);

	setup();
	replace_program(ROOM);
}
