// Room: guodaoe2.c

inherit ROOM;

void create()
{
	set("short", "曲径回廊");
	set("long",@LONG
这是一条雕梁画柱的回廊，梁柱上画的都是道教里的人物，
可能是本派的什么典故吧。回廊环抱着整个前院。前院其实就是
一个不小的花园。走到这里，心神渐静，空气也开始潮湿起来。
LONG
);
	set("exits", ([ /* sizeof() == 2 */
	"west" : __DIR__"guodaoe",
	"northeast" : __DIR__"guodaoe3",
	"south":__DIR__"sleephome",
]));
	set("outdoors", "huashan_zx");
	setup();
}

int valid_leave(object ob,string dir)
{
        if(!ob || !stringp(dir))
                return 1;

        if( (dir == "south")
        && ob->query("class") != "huashan"
        && !wizardp(ob) )
                return notify_fail("非华山弟子不得入内！！\n");

        else
                return ::valid_leave(ob,dir);
}
