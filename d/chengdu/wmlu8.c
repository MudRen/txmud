// Room: /wiz/louth/c/wmlu8.c

inherit ROOM;

void create()
{
	set("short", "����·");
	set("long", @LONG
�����ǳɶ�������·����������������һ�������ҵĺ�լ��
�������Ժ����������·���ϱ�����������
LONG
);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"wwdao1",
  "west" : __DIR__"haozhai",
  "east" : __DIR__"wmlu7",
]));

	set("objects",([
	NPC_DIR"xunpu" : 2,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
