// Room: /d/fengtian/guanlu2.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
����·��ͨ��������ŵĹٵ�������û����������ô������
���ӣ��ٵ����в��ٽ��Ǻͳ��ǵ��ˣ�������ԶԶ���Կ�������
�ǵ������ˡ�
LONG
	);

	set("outdoors", "fengtian");

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"guanlu3",
  "north" : __DIR__"lukou",
]));

	set("objects",([
		NPC_DIR"xunpu" : 2,
]));

	setup();
	replace_program(ROOM);
}
