// Room: /wiz/louth/c/jguanlu1.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ��Ľ���·���ϱ��ǳɶ��Ķ���Ь�ꡣ����������
�ᴩ�ɶ������Ľ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiemaodian",
  "west" : __DIR__"jguanlu2",
  "east" : __DIR__"shizi",
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
