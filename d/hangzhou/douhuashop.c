// /d/hangzhou/douhuashop.c

inherit ROOM;

void create()
{
        set("short", "豆花庄");
        set("long", @LONG
这是一间不太大的店铺，倒还算得上干净，可顾客不是很多
看来吃惯了清淡口味的杭州人还是不太喜欢四川的麻辣味道，柜
台后面的掌柜也显得无精打采。倒是小二殷勤的上来招呼：你老
要个啥子？
LONG
        );
        set("exits", ([ 
            "north"  : __DIR__"changane1",
]));
        setup();
        replace_program(ROOM);
}

