// Room: /d/path5/kch40.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ�����ѵ�С·�����Թ�ľ��������ʱ������������졣
�㾯��������ܿ��˿�����û�з�����ʲôΣ�ա�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"kch41",
  "westup" : __DIR__"kch39",
]));
        set("outdoors", "path5");
	setup();
	replace_program(ROOM);
}
