// Room: /d/path3/k_s3.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�������Ĵ�·��·�������ǹ�ͺͺ��ɽ�¡�һֱ��
��Զ���ǿ�����ˣ��ɴ������Ͼ͵���פ��ꡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"k_s4",
  "north" : __DIR__"k_s2",
]));

	set("outdoors", "path3");
	setup();
	replace_program(ROOM);
}
