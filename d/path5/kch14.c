// Room: /d/path5/kch14.c

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
  "southdown" : __DIR__"kch15",
  "northup" : __DIR__"kch13",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
