// shroad4  南环路

inherit ROOM;

void create()
{
        set("short", "南环路");
        set("long", @LONG
这里是长安城的南环路，是长安四条主街道之一，由于是紧
邻皇城的内环路，所以戒备森严，巡捕、御林军来往不断，街道
两边干净整洁，大青石砖铺的官道很是宽阔。隐隐从这里可以看
到皇宫的角楼，甚至还可以看到上面的侍卫，当然当地人对这一
切早已司空见惯了。南环路由这里向西延伸，北面是东环路。
LONG
        );

	set("exits", ([
                "west"             : __DIR__"shroad3",
                "north"            : __DIR__"ehroad1", ]) );

	set("outdoors","changan");
        setup();
	replace_program(ROOM);
}
