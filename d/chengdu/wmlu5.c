// Room: /wiz/louth/c/wmlu5.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ�������·�����������Ͼ���������ջ��������һ
��ˮ���ꡣ������������Թᴩ��������·��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yuelaikezhan",
  "west" : __DIR__"wmlu6",
  "east" : __DIR__"shizi1",
  "north" : __DIR__"shuiguodian",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
