// /d/tianshui/duchang.c

inherit DUCHANG;

void create()
{
        set("short", "天水赌馆");
        set("long", @LONG
这里就是远近闻名的天水赌馆。里面此起彼伏的叫喊声，银
子、元宝叮叮当当的碰撞声使你也不禁血液沸腾起来，真想也赌
(bet)他几把试试运气。门边的牌子(paizi)写着这里的赌规。旁
边有楼梯通向二楼。
LONG
        );
        set("item_desc", ([
                "paizi" : 
"\n本赌场目前开放押「大小」,规则如下:\n"
"三粒骰子点数总和：\n"
"       四   至 十   为「小」(small)，\n"
"       十一 至 十八 为「大」(big)，\n"
"您也可以押全色 (all) 即三粒骰子点数相同。\n"
"如您押的结果和骰子摇出的结果相同，赌一赔一。\n"
"如您押全色押中了则一赔八，押100两赢800两！\n\n"
"本赌场只接受银子为赌注,多少不限。\n",
        ]));
        set("exits", ([
                "west" : __DIR__"nroad2",
		  "up" : __DIR__"duchang2"
                     ]));
	set("objects",([
	__DIR__"npc/judge" : 1,
]));
        set(SAFE_ENV,1);
        setup();
}

int valid_leave(object me,string dir)
{
	if(dir == "up")
		return notify_fail("通往楼上的门紧锁着，不时传出几声隐约的叫喊声，楼上好象也在赌钱。\n");
	return ::valid_leave(me,dir);
}
