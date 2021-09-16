// Room: /d/huanggong/nanm.c

inherit ROOM;

void create()
{
        set("short", "皇宫南门");
        set("long", @LONG
这里就是皇城的正门。每天早上文武百官由此进入皇宫等待
皇上早朝。城门的两侧是高十多米的城墙，红墙碧瓦，金碧辉煌
，体现了皇家的气派。一对威武的雄狮坐落在城门的两边，象征
着帝王的威严与权利。

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/changan/jingsq1",
  "north" : __DIR__"daolu1",
]));
        set(SAFE_ENV, 1);
        set("outdoors", "huanggong");
	set("objects",([
	__DIR__"npc/yulin" : 2,
]));

	setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "north" || dir == "n")
		return notify_fail("御林军校挺身一拦说道：“皇宫禁地，平民百姓不得进入！”\n\n");
	else
		return ::valid_leave(me,dir);
}