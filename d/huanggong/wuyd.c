// Room: /d/huanggong/wuyd.c

inherit ROOM;

void create()
{
        set("short", "武英殿");
        set("long", @LONG
这里就是皇上闲时，和护卫们切磋武艺的地方，西面摆放着
一个兵器架，上面十八般武器样样齐全．大殿的南面放着一张龙
椅，从那作工，就能看出皇家的气派．你看了以后不禁也有座座
的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"daolu3",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}