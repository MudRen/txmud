// Room: /d/path5/kch13.c

inherit ROOM;

void create()
{
	set("short", "���ɽ·");
	set("long", @LONG
����һ����᫵�ɽ·�����ߵ������������Щ���ˡ���ʱ
��һЩ��ʯ��ɽ�ϻ��䣬�㲻�ò����С�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"kch14",
  "northwest" : __DIR__"kch12",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
