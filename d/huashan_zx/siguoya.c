// Room: siguoya.c by pian

inherit ROOM;

void create()
{
        set("short", "思过崖");
        set("long", @LONG
思过崖是华山派弟子犯了严重的过错，就会罚在这里面壁静
思已过。这里向北有一个小小的山洞，是供思过弟子晚间遮避风
雨用的。
　　从东面不时有阵阵狂风吹来。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
		"enter" : __DIR__"sg_dong",
		"southdown" : __DIR__"guange5",
		"east" : __DIR__"siguoya2",
]));
        set("outdoors", "huashan_p");
        setup();
        replace_program(ROOM);
}
