// Room: /d/huashan/shibi.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��һ�������Ϳ�������ǽ���Ͽ�������������ַ������֣�
��֪����ʲô���������Ϸ���һ���޵档
LONG
);

	set("exits", ([ /* sizeof() == 1 */
	"east" : __DIR__"dongtian",
]));

	set("objects", ([
		__DIR__"npc/master-yue":1,
]));

	setup();
	replace_program(ROOM);
}
