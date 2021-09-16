// Room: /wiz/louth/a/shandong5.c

inherit ROOM;

void create()
{
	set("short", "山洞口");
	set("long", @LONG
这里是宽敞干燥的大山洞，四周的石壁(wall)凿的十分平整，
上面插着几只点燃的火把，地上铺着细细的沙子，踩上去格外舒
适。前面隐约透过来一点亮光，大概就是洞口了。
LONG
	);
	set("item_desc", ([ /* sizeof() == 2 */
  "石壁" : "[1;37m
                花      嫣
                雨      然
                飘      一
                零      笑
                笑      戏
                红      九
                尘      天

[2;37;0m",
  "wall" : "[1;37m
                花      嫣
                雨      然
                飘      一
                零      笑
                笑      戏
                红      九
                尘      天

[2;37;0m",
]));
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong3",
  "north" : __DIR__"taoyuan1",
]));

	setup();
	replace_program(ROOM);
}
