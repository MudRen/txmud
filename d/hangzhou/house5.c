// Room: /d/hangzhou/house5.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
����һ�������Ժ�䣬Ժ������ļ������������������м�
����ʯ��ʯ�Σ����ϵ�Сˮ���ﻹ�����㣬�ǳ����¡�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"house2",
  "west" : __DIR__"house6",
]));

	set("cannot_build_home",1);
	set("outdoors","hangzhou");

	setup();
	replace_program(ROOM);
}
