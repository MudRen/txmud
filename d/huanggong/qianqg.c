// Room: /d/huanggong/qianqg.c

inherit ROOM;

void create()
{
        set("short", "乾清宫");
        set("long", @LONG
这里就是皇上每天早朝过后处理国事的地方。一张巨大的龙
案放大殿的中央。龙案上，一叠厚厚的奏折等待皇上前来批阅。
墙上挂着一幅唐伯虎的真迹。处处体现出帝王家的气派，一张龙
椅上面刻着九条即欲腾空的金龙，使人不禁产生，座一座的念头。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"daolu6",
  "south" : __DIR__"baohd",
  "north" : __DIR__"jiaotd",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

