// Room: /d/huanggong/yujt.c

inherit ROOM;

void create()
{
        set("short", "御景亭");
        set("long", @LONG
这里是御花园的最高处，整个御花园的美景尽收眼底。你不
禁被眼前的鬼斧神工所打动，广阔的湖面上波光鳞鳞，几只鸭子
正在戏水打闹 。远处宫殿的檐角隐没在一片苍翠的绿林中...你
仿佛置身与红尘之外，与这湖光山色溶为了一体。
LONG        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"taihjs",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}