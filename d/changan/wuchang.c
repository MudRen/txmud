// Room: /d/changan/wuchang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ݵ��������Ŀճ������ĵ�������ϸϸ��ɳ�ӣ�
���ٵ��Ӷ�������еľ�ʯ�����еĴ�ľ�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wuguan",
]));
	set("objects", ([
	__DIR__"npc/muren" : 3,
]));

	setup();
	replace_program(ROOM);
}
