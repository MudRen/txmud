// Room: /d/path5/kch41.c

inherit ROOM;

void create()
{
	set("short", "����ɽ·");
	set("long", @LONG
����һ�����ѵ�С·�����Թ�ľ��������ʱ������������졣
�㾯��������ܿ��˿�����û�з�����ʲôΣ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"kch42",
  "northup" : __DIR__"kch40",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
