// Room: /d/tangmen/gd2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��С·");
	set("long", @LONG
����һ��ʯ��С·������������̲ݵ��У������Ǿ�������
�߶���·�ϵ�ʯ�ӱ�ĥ�÷ǳ�������ǰ�治Զ����һ��ƬԺ�䣬
������Ŷ���������ӰӰ�����ĺ����в����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"fyuan",
  "south" : __DIR__"dmq",
  "west" : __DIR__"chalu",
]));

	set("outdoors", "tangmen");
	setup();
	replace_program(ROOM);
}
