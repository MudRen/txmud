// Room: /wiz/louth/c/fdjie4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǹ����֡��������򱱿���ͨ��Ѽ������Ѽ�ꡣһֱ��
�����ǽ���·���������ܼǵ��̡�
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"fdjie3",
  "east" : __DIR__"dangpu",
  "north" : __DIR__"fdjie5",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
