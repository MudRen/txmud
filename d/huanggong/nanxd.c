// Room: /d/huanggong/nanxd.c

inherit ROOM;

void create()
{
        set("short", "南薰殿");
        set("long", @LONG
这里就是皇上的浆洗房，听说韦小宝在此当差是曾经偷了皇
上的龙内裤，退休后开了一家诊所，专治不孕症，结果发了大财
，嘿嘿，你要不要也来这里打工，听说现在的待遇比以前好多了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"daolu3",
  ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


