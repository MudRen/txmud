// Room: /d/shaolin/door.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "少林寺大门");
	set("long",@LONG
这里是少林寺的大门口，前方是高大的山门，大红朱漆的门
上钉着一些铜钉。千年古刹，金砖玉瓦。门两旁是一幅对联，山
门上面是一块镶金的蓝匾上书“少林寺”三个大字。门前两个知
客僧正忙碌着接待着上山进香的人们。从这里往南是石阶通往下
山路，进门向北是前院广场。
LONG
);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"f_square",
  "southdown" : __DIR__"taijie1",
]));

	set("item_desc", ([
                "对联":	HIC"      地在天中四海名山为第一\n      心传言外十方法教是初元\n"NOR,
        ]) );

	set("NORIDE","护寺僧人上前拦住说道：“少林寺乃佛门清静之地，不能骑坐骑进入。”\n");

        set("outdoors","shaolin");
        setup();
        replace_program(ROOM);
}
