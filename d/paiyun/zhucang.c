// Room: /d/paiyun/zhucang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������߰���ѷ���ľͷ��������֮��Ķ�������
������һ�䴢���ҡ�
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"lu10",
]));

	setup();
	replace_program(ROOM);
}
