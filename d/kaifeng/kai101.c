inherit HOCKSHOP;

void create()
{
	set("short", "杨记当铺");
	set("long", @LONG
杨记当铺的老板却是姓周。周老板长着一副笑眯眯的圆脸，
据说除了笑容外没有人看过周老板的脸上露出过别的表情。当有
人问起他这张笑脸时，他总是笑眯眯地说：哈哈，和气生财嘛，
哭丧着脸可怎么跟人做生意啊，哈哈。不过背地里，百姓们都叫
他“周扒皮”。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"kai100",
]));

        set("objects",([
        __DIR__"npc/zboss": 1,
]));

	setup();

}
