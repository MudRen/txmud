// Room: /wiz/louth/c/wwdao4.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���ǳɶ������������������������Ǳ����̡��ϱ��������
��ͨ������������
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"bingqipu",
  "south" : __DIR__"wwdao5",
  "north" : __DIR__"wwdao3",
]));
        set("objects",([
        __DIR__"npc/laoren" : 1,
        __DIR__"npc/dama" : 1,
]));

	set("outdoors","chengdu");

	setup();
	replace_program(ROOM);
}
