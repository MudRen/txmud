// Room: /wiz/louth/a/dxmishi.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"midao7",
]));
        set("objects", ([ /* sizeof() == 4 */
  __DIR__"obj/jiebook" : 1,
]));
	setup();
	replace_program(ROOM);
}
