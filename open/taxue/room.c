// Room: /d/changan/wroad5.c

inherit ROOM;

void create()
{
    set("short", "С����");
	set("long", @LONG
һ���շ�����ѡ�
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
]));

	set("objects",([
     "/open/taxue/boy.c":1,
    "/open/taxue/boss.c":1,
]));

	setup();
	replace_program(ROOM);
}
