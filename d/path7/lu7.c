// Room: /d/path7/lu7.c

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
����һ���徲��С·����˵���·��Զ��ȴ���ټ��˼�����
�����ǵĳ���һЩС�ݣ������Ӻ��������߹����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"lu8",
  "northwest" : __DIR__"lu6",
]));

	set("outdoors", "path7");

	setup();
	replace_program(ROOM);
}
