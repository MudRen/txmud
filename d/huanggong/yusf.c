// Room: /d/huanggong/yusf.c

inherit ROOM;

void create()
{
        set("short", "御膳房");
        set("long", @LONG
这里就是闻名江湖的御膳房，在这里当厨子的都是来自各大
著名酒楼的名厨。每天把大江南北的名菜做好，等着皇亲国戚们
品尝，但许多还是被浪费掉了。即使是满汉全席也是如此。但厨
子们得手艺还是像原来那么好。眼前的饭菜正冒着香气，馋得你
直流口水:).....禁不住你想要大吃一通。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"daolu2",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}