// Room: /wiz/louth/c/jguanlu5.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���ǳɶ��Ľ���·�������������ӻ��̡������������ȡ�
�����������ͨ����������·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yangmalang",
  "west" : __DIR__"shizi",
  "east" : __DIR__"jguanlu6",
  "north" : __DIR__"zahuopu",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
