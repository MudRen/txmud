// Room: /wiz/louth/c/wmlu1.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ�������·�����������Ͼ��Ǹ����֡�����Ѽ��
����Ѽ�ꡣ����һ��Ƨ�������ͨ����������·��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie5",
  "west" : __DIR__"wmlu2",
  "east" : __DIR__"pixiang",
  "north" : __DIR__"yaziwang",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
