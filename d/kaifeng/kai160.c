// Room: /u/w/wangs/b/kai160.c

inherit ROOM;

void create()
{
	set("short", "后松街");
	set("long", @LONG
这里是开封城的住宅区。一条青石板铺成的街坊，两边可见
一些民居住宅，街头有炊烟袅袅飘来青柴的香味。不远处传来家
家户户舂米的声音，还有大户人家榨香油的醇香味。路边三五个
小孩正在拍手唱歌玩耍着。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai161",
  "north" : __DIR__"kai159",
  "east" : __DIR__"kai183",
]));
        set("objects",([
	NPC_DIR"stdnpc/stdnpc_1" : 2,
]));

	set("outdoors","kaifeng");

	setup();
	replace_program(ROOM);
}
