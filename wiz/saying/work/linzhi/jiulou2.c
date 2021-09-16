//jiulou2.c 香格里拉二层。

inherit ROOM;

void create()
{
        set("short", "谪仙楼二层");
        set("long", @LONG
这里是香格里拉酒楼的二楼，一般是有身份有地位的人才能上
来就餐的地方。这里的雅座清净整洁，服侍的小姐也很可人，不过
最吸引人的还是这里的美餐。
LONG
        );

        set("night_long",@LONG
这里是香格里拉酒楼的二楼。现在已经是晚上，酒楼已经打
烊了，掌柜的正在柜台后面打盹儿。
LONG
);
        set("no_clean_up", 0);
        set("no_sleep_room",1);
        set("exits", ([ /* sizeof() == 1 */
	"down" : __DIR__"jiulou",
]));
        set("objects",([
        __DIR__"npc/jiulou_boss" : 1,
]));
        set("NORIDE","小店楼梯太窄，您老骑着坐骑可是上不去。");
        setup();
        replace_program(ROOM);
}
