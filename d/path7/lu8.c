// Room: /d/path7/lu8.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ���徲��С·����˵���·��Զ��ȴ���ټ��˼�����
�����ǵĳ���һЩС�ݣ������Ӻ��������߹����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"lu7",
]));

	set("outdoors", "path7");

	setup();
	replace_program(ROOM);
}
