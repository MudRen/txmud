// Room: /d/path3/cross6.c

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
  "west" : __DIR__"cross5",
  "east" : __DIR__"cross7",
  "northeast" : "/d/mafeng/up1",
]));
	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
