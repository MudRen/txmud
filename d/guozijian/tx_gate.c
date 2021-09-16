// Room: /d/guozijian/tx_gate.c 

inherit ROOM;

void create() 
{ 
	set("short", "太学门");
	set("long", @LONG
这里是国子监的第二道门，是一个拱门，墙体都是皇室专用
的血红色，门的上方用蓝底金字写者“太学门”，旁边刻有精美
的图案。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"yongdao2",
		"south" : __DIR__"yongdao1",
]));
	setup();
	replace_program(ROOM);
}
