// Room: /d/huanggong/taihd.c

inherit ROOM;

void create()
{
        set("short", "太和殿");
        set("long", @LONG
这里就是人间的天堂．金銮殿．国家的权利中心．每当新皇
帝登基都要在这里举行大典．正中摆放着皇帝的宝座，驾前东，
西摆放着一对仙鹤，象征着吉祥，香炉里飘出淡淡的檀香，领人
心旷神怡．大店两侧文武百官，各个身着锦衣，英气勃发．大殿
门前一队锦衣卫随时保护着皇上的安全这里可不是你长呆的地方。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taihm",
  "north" : __DIR__"zhonghd",
]));
        set("no_clean_up", 0);
        set("to", "rset long
");

        setup();
        replace_program(ROOM);
}