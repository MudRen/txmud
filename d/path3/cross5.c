// Room: /d/path3/cross5.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С·");
	set("long", @LONG
������λ�����ɽ���µ�һ��С·����һ������ɽ����Ӱ��
�����ƺ�����������㻹��С�����µĺá�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"cross4",
  "east" : __DIR__"cross6",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
