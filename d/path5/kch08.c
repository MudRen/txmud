// Room: /d/path5/kch08.c

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
  "southup" : __DIR__"kch09",
  "northdown" : __DIR__"kch07",
]));
        set("outdoors", "path5");
        set("cannot_build_home", 1);
        set("NORIDE", "��ǰ��ĵ��Σ���ͽ�����ܹ�ȥ��������ûϷ�ˡ�");
	setup();
	replace_program(ROOM);
}
