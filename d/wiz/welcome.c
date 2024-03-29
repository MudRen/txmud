// Room: /d/wiz/welcome.c

#define BLOCK_CMDS	({"chat","rumor","menpai","tx","save"})
inherit ROOM;

void create()
{
	set("short", "松竹小院");
	set("long", @LONG
这里是一个幽静的小院落，院中奇花异石，举目望去四周云雾缭
绕，不时传来声声百鸟的鸣叫，扑鼻而来的是阵阵的花香，仿佛置身
于使人忘忧的世外仙境，前方竹林掩映中有几间茅屋。
LONG
	);

	set(SAFE_ENV,1);
	set("room_lable","welcome");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"welcome5",
]));

	set("objects",([
		__DIR__"npc/tongzi1" : 1,
]));
	setup();
}

void init()
{
	add_action("block_cmds","",1);
}

int block_cmds(string arg)
{
	if(!wizardp(this_player()) && member_array(query_verb(),BLOCK_CMDS) != -1)
		return 1;
	else
		return 0;
}

int valid_leave(object me,string arg)
{
	if(!present("book",me) && !wizardp(me))
		return notify_fail("小书童对你说道：请等一下。\n");
	else
		return 1;
}