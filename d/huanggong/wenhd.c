// Room: /d/huanggong/wenhd.c

inherit ROOM;

void create()
{
        set("short", "文华殿");
        set("long", @LONG
这里就是皇上每日饱读诗书的地方，一张御案摆放在大厅的
中央，御案上面雕着九条栩栩如生的金龙，御案上摆着一部古书
<<孙子兵法>>这可是历代帝王必读之书，呵呵你要不要读一下。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"daolu5",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}