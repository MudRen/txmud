// Room: /wiz/louth/c/jguanlu3.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
���ǳɶ��Ľ���·���������������̡���������һ�ҹײ�
�̡������������ͨ����������·��
LONG
);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guancaipu",
  "west" : __DIR__"jguanlu4",
  "east" : __DIR__"jguanlu2",
  "north" : __DIR__"roupu",
]));
        set("objects",([
        __DIR__"npc/sengren" : 1,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
