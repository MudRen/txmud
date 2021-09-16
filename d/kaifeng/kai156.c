// Room: /u/w/wangs/b/kai156.c

inherit ROOM;

void create()
{
	set("short", "前松街");
	set("long", @LONG
这里是开封城的住宅区。一条碎石子铺成的街坊，东边可见
一些民居住宅，街头有炊烟袅袅飘来青柴的香味。不远处传来家
家户户舂米的声音，还有大户人家榨香油的醇香味。路边三五个
小孩正在拍手唱歌玩耍着。往北不远就是开封东门了。　　
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"kai157",
  "north" : __DIR__"kai147",
  "east" : __DIR__"kai180",
]));

	set("outdoors","kaifeng");
	setup();
	replace_program(ROOM);
}
