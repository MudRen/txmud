// Room: /wiz/louth/c/fdjie5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ��ĸ����֡��������򱱾�������·��������������
�ĳ������ǲ÷��̡�������һֱ�ߵ������ֵľ�ͷ��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie4",
  "west" : __DIR__"duchang",
  "east" : __DIR__"caifengpu",
  "north" : __DIR__"wmlu1",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
