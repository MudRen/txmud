// Room: cufang2.c by pian

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���￿ǽ�������״��������Ѭ���ǣ������ȳ�ȥ�Ȱɡ�
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"chufang1",
]));
	setup();
	replace_program(ROOM);
}