// Room: /wiz/louth/c/jguanlu7.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���ǳɶ��Ľ���·��������������ջ��������һ����ܡ�
�����������ͨ����������·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"jguanlu6",
  "east" : __DIR__"jguanlu8",
  "north" : __DIR__"business",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
